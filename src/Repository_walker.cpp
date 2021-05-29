//
// Created by fils on 28/05/2021.
//


#include "Repository_walker.h"

#include <utility>

using json = nlohmann::json;

Repository_walker::Repository_walker(std::shared_ptr<settings_store> s, std::shared_ptr<data_store> d) {
    std::string config_file = "test.json";
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
        if(std::filesystem::is_directory(path)){
            if(is_excluded_directory(path)){
                p_iter.disable_recursion_pending();
            } else{
                if(contains_excluding_file(path)){
                    p_iter.disable_recursion_pending();
                }
            }
        } else{
            analyze_file(path);
        }
    }
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
    bool is_excluded = false;
    for(auto& p: std::filesystem::directory_iterator(dir)){
        if(!std::filesystem::is_directory(p.path())){
            is_excluded = excluding_extensions.find(p.path().extension()) != excluding_extensions.end();
        }
    }
    return is_excluded;
}

/// File analysis Dispatcher
/// \param file File to analyze
///
/// This method is a simple dispatcher that based on the file type calls the appropriate analysis method.
void Repository_walker::analyze_file(std::filesystem::path &file) {
    if(file_is_verilog(file)){
        analyze_verilog(file);
    } else if(file_is_script(file)){
        analyze_script(file);
    } else if(file_is_vhdl(file)){
        analyze_vhdl(file);
    } else if(file_is_constraint(file)){
        analyze_constraint(file);
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
void Repository_walker::analyze_verilog(std::filesystem::path &file) {
    sv_analyzer file_processor(file);
    file_processor.cleanup_content("`(.*)");
    file_processor.parse();
    std::vector<HDL_entity> content = file_processor.get_entities();
    d_store->store_entity(content);
}

/// Analyze the target vhdl-type file to extract declared and used instantiated design elements
/// \param file Target file
void Repository_walker::analyze_vhdl(std::filesystem::path &file) {

}

/// Analyze the target Script extracting the necessary metadata
/// \param file Target file
void Repository_walker::analyze_script(std::filesystem::path &file) {

}

/// Analyze the target constraint file extracting the necessary metadata
/// \param file Target file
void Repository_walker::analyze_constraint(std::filesystem::path &file) {

}




