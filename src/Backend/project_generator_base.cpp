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
    data.board_part = "";
}

void project_generator_base::write_makefile(std::ostream &output) {


    output << "set project_name " <<  data.name <<std::endl;
    output << "set origin_dir \".\""<<std::endl;
    std::string bd = data.base_dir;
    output << bd << std::endl;

    output << "set commons_dir [list ";
    for(const auto& str:data.commons_dir){
        output << "\""<< str << "\" ";
    }
    output << "]"<< std::endl;

    output << "set synth_sources [list ";
    for(const auto& str:data.synth_sources){
        output << "\""<< str << "\" ";
    }
    output << "]"<< std::endl;

    output << "set sim_sources [list ";
    for(const auto& str:data.sim_sources){
        output << "\""<< str << "\" ";
    }
    output << "]"<< std::endl;

    output << "set constraints_sources [list ";
    for(const auto& str:data.constraints_sources){
        output << "\""<< str << "\" ";
    }
    output << "]"<< std::endl;

    std::string board_part = data.board_part;

    if(!board_part.empty()){

        output << "set board_part " << board_part << std::endl;
        output << "# Create project\ncreate_project ${project_name} ./${project_name}\n";
        output << "set_property board_part $board_part [current_project]\n";
    } else {
        output << "# Create project\ncreate_project ${project_name} ./${project_name}\n";
        output << "set_property part xc7z020clg400-1 [current_project]\n";
    }

    output<<"# Set the directory path for the new project\nset proj_dir [get_property directory [current_project]]\n";
    output << "set obj [current_project]\n";
    for(const auto& scr:data.scripts){
        output << "source " << scr << std::endl;
    }

    output << "add_files -norecurse $synth_sources\n";

    std::string tl = data.synth_tl;
    if(!tl.empty()){
        output<< "set_property top " <<tl<<" [get_filesets sources_1]"<< std::endl;
    }

    output << "set_property include_dirs $commons_dir [get_filesets sources_1]\n";
    output << "set_property SOURCE_SET sources_1 [get_filesets sim_1]\n";

    std::unordered_set<std::string> constr = data.constraints_sources;
    if(!constr.empty()){
        output << "add_files -fileset constrs_1 -norecurse  $constraints_sources\n";
    }

    output << "add_files -fileset sim_1 -norecurse $sim_sources\n";
    tl = data.tb_tl;
    if(!tl.empty()){
        output<< "set_property top " <<tl<<" [get_filesets sim_1]"<< std::endl;
    }

    output << "update_compile_order\n";
}



void project_generator_base::set_project_name(const std::string &name) {
    data.name = name;
}

void project_generator_base::set_directories(const std::string &base, const std::vector<std::string> &commons) {
    base_dir = base;
    std::vector<std::string> include_dirs;
    include_dirs.reserve(commons.size());

    for(const auto& item:commons){
        include_dirs.push_back(base +item);
    }

    data.base_dir = "set base_dir " + base;
    data.commons_dir = include_dirs;
}

void project_generator_base::set_synth_sources(const std::set<std::string> &paths) {
    data.synth_sources = this->process_sources_set(paths);
}

void project_generator_base::set_sim_sources(const std::set<std::string> &paths) {
    std::vector<std::string> synth_sources = data.synth_sources;
    std::vector<std::string> raw_sim_sources = this->process_sources_set(paths);
    std::vector<std::string> diff;

    std::set_difference(raw_sim_sources.begin(), raw_sim_sources.end(), synth_sources.begin(), synth_sources.end(),
                        std::inserter(diff, diff.begin()));

    data.sim_sources = diff;
}

void project_generator_base::set_synth_tl(const std::string &tl) {
    data.synth_tl= tl;
}
void project_generator_base::set_board_part(const std::string &bp) {
    data.board_part = bp;
}

void project_generator_base::set_sim_tl(const std::string &tl) {
    data.tb_tl = tl;
}


void project_generator_base::set_constraint_sources(const std::unordered_set<std::string> &paths) {
    data.constraints_sources = paths;
}

void project_generator_base::set_script_sources(const std::unordered_set<std::string> &paths) {
    data.scripts = paths;
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
