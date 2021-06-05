//
// Created by fils on 05/06/2021.
//

#include "Backend/xilinx_project_generator.h"

xilinx_project_generator::xilinx_project_generator() {
    tpl = env.parse_template(template_file);
    data["base_dir"] = "";
    data["commons_dir"] = "";
    data["sim_sources"] = {"test", "test2"};
    data["synth_sources"] = {"test", "test2"};
    data["constraints_sources"] =  {"test", "test2"};
    data["scripts"] = {"test", "test2"};
    data["synth_tl"] = "test";
    data["tb_tl"] = "test";
}


void xilinx_project_generator::write_makefile(std::ofstream &output) {
    std::string result = env.render(tpl, data);
    output<<result;
}

void xilinx_project_generator::set_project_name(const std::string& name) {
    data["name"] = name;
}

void xilinx_project_generator::set_synth_sources(const std::set<std::string>& paths) {
    data["synth_sources"] = paths;
}

void xilinx_project_generator::set_sim_sources(const std::set<std::string>& paths) {
    data["sim_sources"] = paths;
}

void xilinx_project_generator::set_constraint_sources(const std::set<std::string>& paths) {
    data["constraints_sources"] = paths;
}
