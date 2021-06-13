//
// Created by fils on 28/05/2021.
//


#include "frontend/Repository_walker.h"


Repository_walker::Repository_walker(std::shared_ptr<settings_store> s, std::shared_ptr<data_store> d) : pool(max_threads),
                                                                                                         cache_mgr(s){
    s_store = std::move(s);
    d_store = std::move(d);
    target_repository = s_store->get_setting("hdl_store");
    if(target_repository.empty()){
        std::cout<< "Please enter the absolute path of the HDL repository"<<std::endl;
        std::cin >> target_repository;
        s_store->set_setting("hdl_store", target_repository);
    }
    analyze_dir();
}

/// This method analyses the Repository_walker target directory, mapping out useful things (like module dependencies, script location, etc.)
///
/// The implementation of this function iterates over the target directory recursively, calling the analyze_file method
/// on each file, to speed up the process directories can be skipped either based on their name (.git for example) or
/// on their content (exclude directories containing a .xpr file as they are vivado projecta and contain only auto-generated
/// stuff.
void Repository_walker::analyze_dir() {
    for(auto p_iter = std::filesystem::recursive_directory_iterator(target_repository);
        p_iter != std::filesystem::recursive_directory_iterator();
        ++p_iter ) {

        auto path = p_iter->path();
        std::string path_dbg = p_iter->path();
        if(std::filesystem::is_directory(path)){
            if(is_excluded_directory(path)){
                p_iter.disable_recursion_pending();
            } else{
                if(contains_excluding_file(path)){
                    p_iter.disable_recursion_pending();
                }
            }
        } else{
            if(working_threads == 2*max_threads){
               this->collect_analysis_results();
            }
            analyze_file(path);
        }
    }

    this->collect_analysis_results();
}

void Repository_walker::collect_analysis_results() {
    pool.wait_for_tasks();
    for(auto &f : hdl_futures){
        auto result = f.get();
        d_store->store_hdl_entity(result);
    }
    for(auto &f : scripts_futures){
        auto result = f.get();
        d_store->store_script(result);
    }
    for(auto &f : constraints_futures){
        auto result = f.get();
        d_store->store_constraint(result);
    }
    hdl_futures.erase(hdl_futures.begin(), hdl_futures.end());
    scripts_futures.erase(scripts_futures.begin(), scripts_futures.end());
    constraints_futures.erase(constraints_futures.begin(), constraints_futures.end());
    working_threads =0;
}


/// Check if the target directory needs to be skipped on the base of its name
/// \param dir Target directory
/// \return true if the directory needs to be skipped
bool Repository_walker::is_excluded_directory(const std::filesystem::path& dir) {
    return excluded_directories.find(dir.filename()) != excluded_directories.end();
}

/// Check if the target directory needs to be skipped on the base of its content
/// \param dir Target directory
/// \return true if the directory needs to be skipped
bool Repository_walker::contains_excluding_file(const std::filesystem::path &dir) {
    for(auto& p: std::filesystem::directory_iterator(dir)){
        if(!std::filesystem::is_directory(p.path())){
            bool is_excluded = excluding_extensions.find(p.path().extension()) != excluding_extensions.end();
            if(p.path().filename() == ignore_file_name){
                this->read_ignore_file(p.path());
            }
            if(is_excluded) return true;
        }
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
    if(!(file_is_verilog(file) || file_is_vhdl(file) || file_is_constraint(file)|| file_is_script(file))) return;

    bool updated_file = true;

    if(cache_mgr.is_cached(file)) updated_file = cache_mgr.is_changed(file);
    if(updated_file) {
        cache_mgr.add_file(file);
        if(file_is_verilog(file)){
            hdl_futures.push_back(pool.submit(analyze_verilog, file));
            working_threads++;
        } else if(file_is_script(file)){
            scripts_futures.push_back(pool.submit(analyze_script, file));
            working_threads++;
        } else if(file_is_vhdl(file)){
            hdl_futures.push_back(pool.submit(analyze_vhdl, file));
            working_threads++;
        } else if(file_is_constraint(file)){
            constraints_futures.push_back(pool.submit(analyze_constraint, file));
            working_threads++;
        }
    }

}

/// Check if the target file appertains to the verilog language family
/// \param file Target file
/// \return True if the file is verilog
bool Repository_walker::file_is_verilog(std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".svh" || extension == ".sv" || extension == ".v" || extension == ".v";
}

/// Check if the target file appertains to the vhdl language family
/// \param file Target file
/// \return
bool Repository_walker::file_is_vhdl(std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".vhd";
}

/// Check if the target file is a recognized script (TCL and python)
/// \param file Target file
/// \return true if the file is a recognized script
bool Repository_walker::file_is_script(std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".tcl" || extension == ".py";
}

/// Check if the target is a constrain file
/// \param file Target file
/// \return true if the file is a constrain file
bool Repository_walker::file_is_constraint(std::filesystem::path &file) {
    std::string extension = file.extension();
    return extension == ".xdc";
}

/// Analyze the target verilog-type file to extract declared and used instantiated design elements
/// \param file Target file
std::vector<std::shared_ptr<HDL_Resource>> analyze_verilog(const std::filesystem::path &file) {
    sv_analyzer file_processor(file);
    file_processor.cleanup_content("`(.*)");
    return file_processor.analyze();
}

/// Analyze the target vhdl-type file to extract declared and used instantiated design elements
/// \param file Target file
std::vector<std::shared_ptr<HDL_Resource>> analyze_vhdl(const std::filesystem::path &file) {
    vhdl_analyzer file_processor(file);
    file_processor.cleanup_content("");
    return file_processor.analyze();
}

/// Analyze the target Script extracting the necessary metadata
/// \param file Target file
std::vector<std::shared_ptr<Script>> analyze_script(const std::filesystem::path &file) {
    std::string ext = file.extension();
    ext = std::regex_replace(ext, std::regex("\\."), "");
    std::shared_ptr<Script> scr = std::make_shared<Script>(file.stem(), ext);
    scr->set_path(file);
    return {scr};
}

/// Analyze the target constraint file extracting the necessary metadata
/// \param file Target file
std::vector<std::shared_ptr<Constraints>> analyze_constraint(const std::filesystem::path &file) {
    std::shared_ptr<Constraints> constr = std::make_shared<Constraints>(file.stem());
    constr->set_path(file);
    return {constr};
}




