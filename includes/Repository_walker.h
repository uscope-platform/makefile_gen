//
// Created by fils on 28/05/2021.
//

#ifndef MAKEFILEGEN_V2_REPOSITORY_WALKER_H
#define MAKEFILEGEN_V2_REPOSITORY_WALKER_H

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <set>

#include "json.hpp"

class Repository_walker {

public:
    Repository_walker();
    void analyze_dir();
private:
    std::string target_repository;
    bool is_excluded_directory(const std::filesystem::path& dir);
    bool contains_excluding_file(const std::filesystem::path& dir);
    // TODO: Make excluded directories dynamic with a mechanism similar to .gitignore
    std::set<std::string> excluded_directories = {".git"};
    std::set<std::string> excluding_extensions = {".xpr"};
};


#endif //MAKEFILEGEN_V2_REPOSITORY_WALKER_H
