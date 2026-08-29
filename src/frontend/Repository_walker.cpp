// Copyright 2021 University of Nottingham Ningbo China
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include "frontend/Repository_walker.hpp"
#include "data_model/mm_file.hpp"



Repository_walker::Repository_walker(const std::shared_ptr<settings_store>& s, const std::shared_ptr<data_store>& d, bool ephimeral) : pool(max_threads){
    construct_walker(s, d, {".git"});
}

Repository_walker::Repository_walker(const std::shared_ptr<settings_store>& s, const std::shared_ptr<data_store>& d, bool ephimeral,std::set<std::string> ex) : pool(max_threads){
    construct_walker(s, d, std::move(ex));
}

void Repository_walker::construct_walker(std::shared_ptr<settings_store> s, std::shared_ptr<data_store> d,
                                         std::set<std::string> ex) {

    s_store = std::move(s);
    d_store = std::move(d);
    excluded_directories = std::move(ex);
    target_repository = s_store->get_hdl_store();
    default_includes = s_store->get_default_includes();
    if (s_store->get_include_auto_discovery()) {
        repository_index_p = std::make_shared<repository_index>();
    }
    scan_repository();
    analyze_dir();
}




/// This method analyses the Repository_walker target directory, mapping out useful things (like module dependencies, script location, etc.)
///
/// The repository must have been scanned first (see scan_repository); the analysis
/// phase iterates the resulting file list instead of walking the directory tree.
void Repository_walker::analyze_dir() {
    // Snapshot the cached hashes before any file is re-parsed, so include-change
    // detection compares against the state the cache was in at the start of this
    // run (the main pass updates cache entries as it goes).
    for (auto &file: scanned_files) {
        previous_hashes[file.string()] = d_store->get_hash(file.string());
    }

    for (auto &file: scanned_files) {
        if(working_threads == 2*max_threads){
           this->collect_analysis_results();
        }
        analyze_file(file);
    }
    this->collect_analysis_results();

    // Re-parse cache-hit files whose (transitive) includes changed.
    invalidate_stale_includes();
}

/// Scan the repository once, building the repository index (basename -> paths) and the list of
/// files to be analyzed. The same exclusion rules used by the analysis phase are applied, so
/// the scan and the parse operate on the exact same file set.
void Repository_walker::scan_repository() {
    std::error_code ec;
    const std::filesystem::recursive_directory_iterator end;
    auto p_iter = std::filesystem::recursive_directory_iterator(target_repository, ec);
    while (p_iter != end && !ec) {

        auto path = p_iter->path();
        if(std::filesystem::is_directory(path, ec)){
            if(is_excluded_directory(path) || contains_excluding_file(path)){
                p_iter.disable_recursion_pending();
            }
        } else{
            if(file_is_verilog(path)){
                if (repository_index_p) repository_index_p->add_file(path);
                scanned_files.push_back(path);
            } else if(file_is_vhdl(path) || file_is_script(path) || file_is_constraint(path) || file_is_data(path)){
                scanned_files.push_back(path);
            }
        }
        p_iter.increment(ec);
    }
    if (ec) spdlog::warn("Error walking repository {}: {}", target_repository, ec.message());
}

void Repository_walker::collect_analysis_results() {
    pool.wait_for_tasks();
    auto store = [this](auto &futures) {
        for(auto &f : futures) {
            try {
                auto [path, file_hash, resource, includes] = f.get();
                if (!path.empty()) file_hashes[path] = file_hash;
                if (resource) d_store->store_file({path, file_hash, resource.value(), includes});
            } catch (const std::exception &e) {
                spdlog::error("Error analyzing a file: {}", e.what());
            } catch (...) {
                spdlog::error("Unknown error while analyzing a file");
            }
        }
        futures.clear();
    };
    store(hdl_futures);
    store(scripts_futures);
    store(constraints_futures);
    store(data_futures);

    working_threads =0;
}

/// After the main analysis pass, evict and re-parse any file that was served
/// from the cache (own hash unchanged) but whose transitive include files have
/// changed since it was cached. The include sets are transitive, so a single
/// hash comparison per include is sufficient.
void Repository_walker::invalidate_stale_includes() {
    std::vector<std::filesystem::path> stale;
    for (auto &file: scanned_files) {
        if (!file_is_verilog(file)) continue;
        auto path = file.string();
        // Own hash changed: the file was already re-parsed in the main pass.
        if (file_hashes[path] != previous_hashes[path]) continue;
        auto includes = d_store->get_includes(path);
        if (!includes.has_value()) continue;
        for (auto &inc: includes.value()) {
            auto current = file_hashes.find(inc.path);
            if (current == file_hashes.end()) continue;  // external/unscanned include: cannot track
            if (current->second != previous_hashes[inc.path]) {
                stale.push_back(file);
                break;
            }
        }
    }

    for (auto &file: stale) {
        spdlog::trace("Invalidating {}: an included file changed", file.string());
        d_store->evict_file(file.string());
        analyze_file(file);
    }
    if (!stale.empty()) this->collect_analysis_results();
}


/// Check if the target directory needs to be skipped on the base of its name
/// \param dir Target directory
/// \return true if the directory needs to be skipped
bool Repository_walker::is_excluded_directory(const std::filesystem::path& dir) {
    auto norm_dir = dir.lexically_normal();

    for (const auto& excl_dir : excluded_directories) {
        if(excl_dir.starts_with('*')) {
            auto excl_name = excl_dir.substr(1, excl_dir.size() -1);
            if(norm_dir.filename() == excl_name) return true;
        }  else {
            if(norm_dir == std::filesystem::path(excl_dir).lexically_normal()) return true;
        }

    }
    return false;

}


/// Check if the target directory needs to be skipped on the base of its content
/// \param dir Target directory
/// \return true if the directory needs to be skipped
bool Repository_walker::contains_excluding_file(const std::filesystem::path &dir) {
    try {
        for(auto& p: std::filesystem::directory_iterator(dir)){
            if(!std::filesystem::is_directory(p.path())){
                bool is_excluded = excluding_extensions.find(p.path().extension()) != excluding_extensions.end();
                if(p.path().filename() == ignore_file_name){
                    this->read_ignore_file(p.path());
                    return true;
                }
                if(is_excluded) return true;
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        spdlog::warn("Error iterating directory {}: {}", dir.string(), e.what());
        return false;
    }
    return false;
}

void Repository_walker::read_ignore_file(const std::filesystem::path &file) {
    std::ifstream content(file);
    std::string ignore_line;
    std::string ignore_path;
    while (std::getline(content, ignore_line)){
        ignore_path = file.parent_path().string() + "/" + ignore_line;
        if(std::filesystem::is_directory(ignore_path)) excluded_directories.insert(ignore_path);
    }

}



/// File analysis Dispatcher
/// \param file File to analyze
///
/// This method is a simple dispatcher that based on the file type calls the appropriate analysis method.
void Repository_walker::analyze_file(std::filesystem::path &file) {
    if(!(file_is_verilog(file) || file_is_vhdl(file) || file_is_constraint(file)|| file_is_script(file) || file_is_data(file))) return;

    spdlog::trace("Analizing file: {}", file.string());
    if(file_is_verilog(file)){
        auto old_hash = d_store->get_hash(file);
        hdl_futures.push_back(pool.submit(analyze_verilog, file, default_includes, old_hash, repository_index_p));
        working_threads++;
    } else if(file_is_script(file)){
        std::set<std::string> includes;
        auto old_hash = d_store->get_hash(file);
        scripts_futures.push_back(pool.submit(analyze_script, file, includes, old_hash));
        working_threads++;
    } else if(file_is_vhdl(file)){
        auto old_hash = d_store->get_hash(file);
        hdl_futures.push_back(pool.submit(analyze_vhdl, file, default_includes, old_hash));
        working_threads++;
    } else if(file_is_constraint(file)){
        std::set<std::string> includes;
        auto old_hash = d_store->get_hash(file);
        constraints_futures.push_back(pool.submit(analyze_constraint, file, includes, old_hash));
        working_threads++;
    } else if(file_is_data(file)){
        std::set<std::string> includes;
        auto old_hash = d_store->get_hash(file);
        data_futures.push_back(pool.submit(analyze_data, file, includes, old_hash));
        working_threads++;
    }

}

/// Check if the target file appertains to the verilog language family
/// \param file Target file
/// \return True if the file is verilog
bool Repository_walker::file_is_verilog(const std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".svh" || extension == ".sv" || extension == ".vh" || extension == ".v";
}

/// Check if the target file appertains to the vhdl language family
/// \param file Target file
/// \return
bool Repository_walker::file_is_vhdl(const std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".vhd" || extension == ".vhdl";
}

/// Check if the target file is a recognized script (TCL and python)
/// \param file Target file
/// \return true if the file is a recognized script
bool Repository_walker::file_is_script(const std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".tcl" || extension == ".py";
}

/// Check if the target is a constrain file
/// \param file Target file
/// \return true if the file is a constrain file
bool Repository_walker::file_is_constraint(const std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".xdc";
}

bool Repository_walker::file_is_data(const std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".dat" || extension == ".mem";
}


/// Analyze the target verilog-type file to extract declared and used instantiated design elements
/// \param file Target file
file_analysis_context<hdl_file> analyze_verilog(
    const std::filesystem::path &file,
    std::set<std::string> i_d, const std::string &old_hash,
    const std::shared_ptr<repository_index> &idx
) {
    spdlog::trace("PARSING: {}", file.c_str());
    try {

        auto f_opt = mm_file::try_open(file.string());
        if (!f_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not open file", file.string());
            return {};
        }
        auto hash_opt = hash_file(f_opt->view());
        if (!hash_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not calculate file hash", file.string());
            return {};
        }
        std::string hash = hash_opt.value();
        if (old_hash == hash) {
            return {file.string(), hash, std::nullopt};
        }
        sv_analyzer file_processor;
        file_processor.set_include_directories(i_d);
        file_processor.set_repository_index(idx);
        auto analysis = file_processor.analyze(file, f_opt->view());
        if (!analysis.has_value()) {
            spdlog::error("Error analyzing {}: {}", file.string(), file_processor.get_error());
            return {};
        }
        auto includes = file_processor.get_includes();
        return {file.string(), hash, analysis.value(), {includes.begin(), includes.end()}};
    } catch (const std::exception &err) {
        spdlog::error("Error analyzing {}: {}", file.string(), err.what());
        return {};
    } catch (...) {
        spdlog::error("Unknown error analyzing {}", file.string());
        return {};
    }
}
std::optional<std::string> hash_file(const std::string_view &file_content) {

    EVP_MD_CTX* context = EVP_MD_CTX_new();

    if(context != nullptr){
        if(EVP_DigestInit_ex(context, EVP_sha256(), nullptr)) {
            if(EVP_DigestUpdate(context, file_content.begin(), file_content.length())) {
                unsigned char hash[EVP_MAX_MD_SIZE];
                unsigned int lengthOfHash = 0;

                if(EVP_DigestFinal_ex(context, hash, &lengthOfHash)) {
                    std::stringstream ss;
                    for(unsigned int i = 0; i < lengthOfHash; ++i) {
                        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
                        if(i<lengthOfHash-1){
                            ss<<":";
                        }
                    }
                    EVP_MD_CTX_free(context);
                    return ss.str();
                }
            }
        }
    }
    EVP_MD_CTX_free(context);
    return std::nullopt;
};

/// Analyze the target vhdl-type file to extract declared and used instantiated design elements
/// \param file Target file
file_analysis_context<hdl_file> analyze_vhdl(
    const std::filesystem::path &file,
    std::set<std::string> i_d,
    const std::string &old_hash
) {
    try {
        auto f_opt = mm_file::try_open(file.string());
        if (!f_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not open file", file.string());
            return {};
        }
        auto hash_opt = hash_file(f_opt->view());
        if (!hash_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not calculate file hash", file.string());
            return {};
        }
        std::string hash = hash_opt.value();
        if (old_hash == hash) {
            return {file.string(), hash, std::nullopt};
        }
        vhdl_analyzer file_processor(file);
        file_processor.cleanup_content("");
        return {file.string(), hash, file_processor.analyze()};
    } catch (const std::exception &err) {
        spdlog::error("Error analyzing {}: {}", file.string(), err.what());
        return {};
    } catch (...) {
        spdlog::error("Unknown error analyzing {}", file.string());
        return {};
    }
}


/// Analyze the target Script extracting the necessary metadata
/// \param file Target file
file_analysis_context<DataFile> analyze_data(
    const std::filesystem::path &file,
    std::set<std::string> i_d,
    const std::string &old_hash
) {
    try {
        auto f_opt = mm_file::try_open(file.string());
        if (!f_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not open file", file.string());
            return {};
        }
        auto hash_opt = hash_file(f_opt->view());
        if (!hash_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not calculate file hash", file.string());
            return {};
        }
        std::string hash = hash_opt.value();
        if (old_hash == hash) {
            return {file.string(), hash, std::nullopt};
        }

        DataFile data(file.stem(), file.string());
        return {file.string(), hash, data};
    } catch (const std::exception &err) {
        spdlog::error("Error analyzing {}: {}", file.string(), err.what());
        return {};
    } catch (...) {
        spdlog::error("Unknown error analyzing {}", file.string());
        return {};
    }
}

/// Analyze the target Script extracting the necessary metadata
/// \param file Target file
file_analysis_context<Script> analyze_script(
    const std::filesystem::path &file,
    std::set<std::string> i_d,
    const std::string &old_hash
) {
    try {
        auto f_opt = mm_file::try_open(file.string());
        if (!f_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not open file", file.string());
            return {};
        }
        auto hash_opt = hash_file(f_opt->view());
        if (!hash_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not calculate file hash", file.string());
            return {};
        }
        std::string hash = hash_opt.value();
        if (old_hash == hash) {
            return {file.string(), hash, std::nullopt};
        }

        std::string ext = file.extension();
        if (!ext.empty() && ext[0] == '.') ext = ext.substr(1);
        script_specs s;
        s.name = file.stem();
        s.type = ext;
        Script scr(s);
        scr.set_path(file);
        return {file.string(), hash, scr};
    } catch (const std::exception &err) {
        spdlog::error("Error analyzing {}: {}", file.string(), err.what());
        return {};
    } catch (...) {
        spdlog::error("Unknown error analyzing {}", file.string());
        return {};
    }
}

/// Analyze the target constraint file extracting the necessary metadata
/// \param file Target file
file_analysis_context<Constraints> analyze_constraint(
    const std::filesystem::path &file,
    std::set<std::string> i_d,
    const std::string &old_hash
) {
    try {
        auto f_opt = mm_file::try_open(file.string());
        if (!f_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not open file", file.string());
            return {};
        }
        auto hash_opt = hash_file(f_opt->view());
        if (!hash_opt.has_value()) {
            spdlog::error("Error analyzing {}: could not calculate file hash", file.string());
            return {};
        }
        std::string hash = hash_opt.value();
        if (old_hash == hash) {
            return {file.string(), hash, std::nullopt};
        }
        Constraints constr(file.stem());
        constr.set_path(file);
        return {file.string(), hash, constr};
    } catch (const std::exception &err) {
        spdlog::error("Error analyzing {}: {}", file.string(), err.what());
        return {};
    } catch (...) {
        spdlog::error("Unknown error analyzing {}", file.string());
        return {};
    }
}




