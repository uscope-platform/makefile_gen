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

    bool is_excluded_directory(const std::filesystem::path& dir);
    bool contains_excluding_file(const std::filesystem::path& dir);
    void analyze_file(std::filesystem::path& dir);
    // File analysis functions
    void analyze_verilog(std::filesystem::path &file);
    void analyze_vhdl(std::filesystem::path &file);
    void analyze_script(std::filesystem::path &file);
    void analyze_constraint(std::filesystem::path &file);
    // File type discrimination methods
    // TODO: use these to make file associations dynamic a la vscode
    static bool file_is_verilog(std::filesystem::path &file);
    static bool file_is_vhdl(std::filesystem::path &file);
    static bool file_is_script(std::filesystem::path &file);
    static bool file_is_constraint(std::filesystem::path &file);
    // TODO: Make excluded directories dynamic with a mechanism similar to .gitignore
    std::set<std::string> excluded_directories = {".git"};
    std::set<std::string> excluding_extensions = {".xpr"};
    std::string target_repository;

};


#endif //MAKEFILEGEN_V2_REPOSITORY_WALKER_H
