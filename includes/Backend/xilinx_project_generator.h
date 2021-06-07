//
// Created by fils on 05/06/2021.
//

#ifndef MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H
#define MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H

#include <ios>
#include <set>
#include <iostream>
#include <fstream>
#include <regex>

#include "data_model/Depfile.h"

#include "third_party/inja.hpp"
#include "third_party/json.hpp"

using json = nlohmann::json;

class xilinx_project_generator {
public:
    xilinx_project_generator();
    void write_makefile(std::ofstream &output);
    void set_project_name(const std::string& name);
    void set_directories(const std::string& base,const std::vector<std::string>& commons);
    void set_synth_sources(const std::set<std::string>& paths);
    void set_sim_sources(const std::set<std::string>& paths);
    void set_synth_tl(const std::string& tl);
    void set_sim_tl(const std::string& tl);
    void set_constraint_sources(const std::set<std::string>& paths);
    void set_script_sources(const std::set<std::string>& paths);

private:
    std::vector<std::string> process_sources_set(const std::set<std::string>& paths);
    inja::Environment env;
    inja::Template tpl;
    std::string base_dir;
    std::string template_file = "/home/fils/git/makefilegen_v2/templates/make_project_xlnx.j2";
    json data;
};


#endif //MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H
