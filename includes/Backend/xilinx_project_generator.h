//
// Created by fils on 05/06/2021.
//

#ifndef MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H
#define MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H

#include <ios>
#include <set>
#include <iostream>
#include <fstream>

#include "third_party/inja.hpp"
#include "third_party/json.hpp"

using json = nlohmann::json;

class xilinx_project_generator {
public:
    xilinx_project_generator();
    void write_makefile(std::ofstream &output);
    void set_project_name(const std::string& name);
    void set_synth_sources(const std::set<std::string>& paths);
    void set_sim_sources(const std::set<std::string>& paths);
    void set_constraint_sources(const std::set<std::string>& paths);
private:
    inja::Environment env;
    inja::Template tpl;
    std::string template_file = "/home/fils/git/makefilegen_v2/templates/make_project_xlnx.j2";
    json data;
};


#endif //MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H
