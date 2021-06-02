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
#include <future>

#include "data_model/settings_store.h"
#include "data_model/data_store.h"
#include "analysis/sv_analyzer.h"
#include "analysis/vhdl_analyzer.h"
#include "third_party/thread_pool.hpp"

static std::vector<HDL_Resource> analyze_verilog(const std::filesystem::path &file);
static std::vector<HDL_Resource> analyze_vhdl(const std::filesystem::path &file);

const unsigned int max_threads = std::thread::hardware_concurrency()-1;

class Repository_walker {

public:
    explicit Repository_walker(std::shared_ptr<settings_store> s, std::shared_ptr<data_store> d);
    void analyze_dir();
private:

    bool is_excluded_directory(const std::filesystem::path& dir);
    bool contains_excluding_file(const std::filesystem::path& dir);
    void analyze_file(std::filesystem::path& dir);
    // File analysis functions


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
    std::shared_ptr<settings_store> s_store;
    std::shared_ptr<data_store> d_store;

    std::vector<std::future<std::vector<HDL_Resource>>> analyzer_futures;

    thread_pool pool;
    int working_threads = 0;

};


#endif //MAKEFILEGEN_V2_REPOSITORY_WALKER_H
