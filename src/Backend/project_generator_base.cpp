 // Copyright 2021 University of Nottingham Ningbo China
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "../includes/Backend/project_generator_base.hpp"

project_generator_base::project_generator_base(const std::string& template_f) {
    std::string templates_dir = TEMPLATES_FOLDER;
    template_file = templates_dir + "/" + template_f;
    tpl = env.parse_template(template_file);
    data["board_part"] = "";
}

void project_generator_base::write_makefile(std::ostream &output) {
    std::string result = env.render(tpl, data);
    output<<result;
    output.flush();
}

void project_generator_base::set_project_name(const std::string &name) {
    data["name"] = name;
}

void project_generator_base::set_directories(const std::string &base, const std::vector<std::string> &commons) {
    base_dir = base;
    std::vector<std::string> include_dirs;
    include_dirs.reserve(commons.size());

    for(const auto& item:commons){
        include_dirs.push_back(base + "/"+item);
    }

    data["base_dir"] = "set base_dir " + base;
    data["commons_dir"] = include_dirs;
}

void project_generator_base::set_synth_sources(const std::set<std::string> &paths) {
    data["synth_sources"] = this->process_sources_set(paths);
}

void project_generator_base::set_sim_sources(const std::set<std::string> &paths) {
    std::vector<std::string> synth_sources = data["synth_sources"];
    std::vector<std::string> raw_sim_sources = this->process_sources_set(paths);
    std::vector<std::string> diff;

    std::set_difference(raw_sim_sources.begin(), raw_sim_sources.end(), synth_sources.begin(), synth_sources.end(),
                        std::inserter(diff, diff.begin()));

    data["sim_sources"] = diff;
}

void project_generator_base::set_synth_tl(const std::string &tl) {
    data["synth_tl"] = tl;
}
void project_generator_base::set_board_part(const std::string &bp) {
    data["board_part"] = bp;
}

void project_generator_base::set_sim_tl(const std::string &tl) {
    data["tb_tl"] = tl;
}


void project_generator_base::set_constraint_sources(const std::unordered_set<std::string> &paths) {
    data["constraints_sources"] = paths;
}

void project_generator_base::set_script_sources(const std::unordered_set<std::string> &paths) {
    data["scripts"] = paths;
}

std::vector<std::string> project_generator_base::process_sources_set(const std::set<std::string> &paths) {
    std::vector<std::string> srcs;
    srcs.reserve(paths.size());

    for(const auto& source :paths){
        std::string replaced = base_dir;
        if(replaced.ends_with("/")){
            replaced.pop_back();
        }
        srcs.push_back(std::regex_replace(source, std::regex(replaced), "${base_dir}"));

    }
    return srcs;
}
