//
// Created by fils on 05/06/2021.
//

#include "Backend/xilinx_project_generator.h"

xilinx_project_generator::xilinx_project_generator() {
    std::string templates_dir = TEMPLATES_FOLDER;
    template_file = templates_dir + "/make_project_xlnx.j2";
    tpl = env.parse_template(template_file);
}



void xilinx_project_generator::write_makefile(std::ofstream &output) {
    std::string result = env.render(tpl, data);
    output<<result;
}

void xilinx_project_generator::set_project_name(const std::string& name) {
    data["name"] = name;
}

void xilinx_project_generator::set_synth_sources(const std::set<std::string>& paths) {
    data["synth_sources"] = this->process_sources_set(paths);
}

void xilinx_project_generator::set_sim_sources(const std::set<std::string>& paths) {
    std::vector<std::string> synth_sources = data["synth_sources"];
    std::vector<std::string> raw_sim_sources = this->process_sources_set(paths);
    std::vector<std::string> diff;

    std::set_difference(raw_sim_sources.begin(), raw_sim_sources.end(), synth_sources.begin(), synth_sources.end(),
                        std::inserter(diff, diff.begin()));

    data["sim_sources"] = diff;
}

void xilinx_project_generator::set_constraint_sources(const std::set<std::string>& paths) {
    data["constraints_sources"] = paths;
}

void xilinx_project_generator::set_script_sources(const std::set<std::string>& paths) {
    data["scripts"] = paths;
}

void xilinx_project_generator::set_synth_tl(const std::string& tl) {
    data["synth_tl"] = tl;
}

void xilinx_project_generator::set_sim_tl(const std::string &tl) {
    data["tb_tl"] = tl;
}

void xilinx_project_generator::set_directories(const std::string &base, const std::vector<std::string> &commons) {
    base_dir = base;
    std::vector<std::string> include_dirs;
    include_dirs.reserve(commons.size());

    for(const auto& item:commons){
        include_dirs.push_back(base + "/"+item);
    }

    data["base_dir"] = "set base_dir " + base;
    data["commons_dir"] = include_dirs;
}

std::vector<std::string> xilinx_project_generator::process_sources_set(const std::set<std::string>& paths) {
    std::vector<std::string> srcs;
    srcs.reserve(paths.size());
    for(const auto& source :paths){
        srcs.push_back(std::regex_replace(source, std::regex(base_dir), "$base_dir"));
    }
    return srcs;
}
