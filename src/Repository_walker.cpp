//
// Created by fils on 28/05/2021.
//


#include "Repository_walker.h"

using json = nlohmann::json;

Repository_walker::Repository_walker() {
    std::string config_file = "test.json";
    json j;
    if(std::filesystem::exists(config_file)){
        std::ifstream i(config_file);
        i >> j;
        target_repository = j["hdl_repo"];
    } else {
        std::cout << "Please input the base path of the HDL repository" << std::endl;
        std::string path_in;
        std::cin >> path_in;
        j["hdl_repo"] = path_in;
        std::ofstream i(config_file);
        i << j;
        target_repository = path_in;
    }
    analyze_dir();
}

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
            }
    }
}

bool Repository_walker::is_excluded_directory(const std::filesystem::path& dir) {
    return excluded_directories.find(dir.filename()) != excluded_directories.end();
}

bool Repository_walker::contains_excluding_file(const std::filesystem::path &dir) {
    bool is_excluded = false;
    for(auto& p: std::filesystem::directory_iterator(dir)){
        if(!std::filesystem::is_directory(p.path())){
            is_excluded = excluding_extensions.find(p.path().extension()) != excluding_extensions.end();
        }
    }
    return is_excluded;
}


