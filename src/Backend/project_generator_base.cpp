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

#include <fmt/format.h>

project_generator_base::project_generator_base(const std::string& template_f, const std::shared_ptr<settings_store> &s_store) {
    std::string templates_dir = TEMPLATES_FOLDER;
    template_file = templates_dir + "/" + template_f;
    data.board_part = "";
    settings = s_store;
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

        output << "\""<< std::regex_replace(str, std::regex(base_dir), "${base_dir}") << "\" ";
    }
    for(const auto& str:data.package_synth_sources){
        output << "\""<< std::regex_replace(str, std::regex(base_dir), "${base_dir}") << "\" ";
    }
    for(const auto& str:data.data_synth_sources){
        output << "\""<< std::regex_replace(str, std::regex(base_dir), "${base_dir}") << "\" ";
    }
    output << "]"<< std::endl;

    output << "set sim_sources [list ";
    for(const auto& str:data.sim_sources){
        output << "\""<< std::regex_replace(str, std::regex(base_dir), "${base_dir}") << "\" ";
    }
    for(const auto& str:data.package_sim_sources){
        output << "\""<< std::regex_replace(str, std::regex(base_dir), "${base_dir}") << "\" ";
    }
    for(const auto& str:data.data_sim_sources){
        output << "\""<< std::regex_replace(str, std::regex(base_dir), "${base_dir}") << "\" ";
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

    std::set<std::string> sourced_scripts;

    for(const auto& scr:data.scripts){
        if(scr.name.empty() || scr.path.empty()) {
            continue;
        }
        if(scr.function_mode) {
            if(!sourced_scripts.contains(scr.path)) output << "source " << scr.path << std::endl;

            if(!scr.name.empty()) {
                output << scr.name;
                for(const auto &val: scr.variables | std::views::values) {
                    output << " " << val ;
                }
                output << std::endl;
            }
        } else {
            if(!sourced_scripts.contains(scr.path)) output << "source " << scr.path << std::endl;
        }
        sourced_scripts.insert(scr.path);
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

void project_generator_base::generate_sim_script(std::ostream &output) {
    auto vivado_dir = settings->get_setting("vivado_path");
    auto sim_dir = data.repo_dir + "/sim";

    output << "FILES=( ";
    for (auto &f:data.package_synth_sources) {
        output << "\n    " << f;
    }
    for (auto &f:data.synth_sources) {
        output << "\n    " << f;
    }
    output << "\n    " << vivado_dir << "data/verilog/src/glbl.v";

    for (auto &f:data.package_sim_sources) {
        if (!data.package_synth_sources.contains(f)) output << "\n    "  << f;
    }

    for (auto &f:data.sim_sources) {
        if (!data.synth_sources.contains(f)) output << "\n    "  << f;
    }
    output << "\n)\n" << std::endl;

    output << "mkdir -p " << sim_dir << std::endl;
    output << "cp sim.tcl " << sim_dir + "/sim.tcl"<< std::endl;
    for (auto &f:data.data_synth_sources) {
        std::string abs_path = std::regex_replace(f, std::regex(R"(\$\{base_dir\})"), base_dir);
        output << "cp "<< abs_path << " "<< sim_dir + "/" + std::filesystem::path(f).filename().string() << std::endl;
    }
    output<< std::endl;

    for (auto &f:data.data_sim_sources) {
        std::string abs_path = std::regex_replace(f, std::regex(R"(\$\{base_dir\})"), base_dir);
        output << "cp "<< abs_path << " "<< sim_dir + "/" + std::filesystem::path(f).filename().string() << std::endl;
    }

    output<< std::endl;

    output << "(" << std::endl;
    output << "    cd "<< sim_dir<<"|| exit" << std::endl<< std::endl;

    output << open_phase("PHASE 1: XVLOG (Analysis)");

    output << "    xvlog -sv \"${FILES[@]}\" ";
    for (const auto& d: data.commons_dir) {
        output<< "-i " << d;
    }
    // add includes for xilinx interface definitions
    output << " -i " << settings->get_setting("vivado_path") + "data/rsb/busdef"<< std::endl;

    output << check_result("XVLOG FAILED");


    output << open_phase("PHASE 2: XELAB (Elaboration)");
    output << "    xelab -debug typical --relax -top "<<data.tb_tl<<" -top glbl -L xil_defaultlib -L unisims_ver -L unimacro_ver -L xpm  -snapshot sim_snapshot  -timescale 10ns/1ps" << std::endl;
    output << check_result("XELAB FAILED");


    output <<open_phase("PHASE 3: XSIM (Simulation)");
    output << "    xsim sim_snapshot -tclbatch sim.tcl"  << std::endl;
    output << check_result("XSIM FAILED");


    output << ")" << std::endl;
    auto res_file = sim_dir + "/dump.vcd";
    output << fmt::format("[[ -f {0} ]] && mv {0} .",res_file)<< std::endl;

    output << "rm -r " << sim_dir << std::endl;


    std::ofstream sim_tcl( "sim.tcl");
    sim_tcl<< R"(
    open_vcd dump.vcd

    log_vcd [get_objects -recursive /*]

    run 2ms

    flush_vcd
    close_vcd
    exit
)";
    sim_tcl.flush();
    sim_tcl.close();
}


 void project_generator_base::set_project_name(const std::string &name) {
    data.name = name;
}

void project_generator_base::set_directories(const std::string &base, const std::string& project_base, const std::vector<std::string> &commons) {
    base_dir = base;
    base_dir.replace(base_dir.size()-1, 1, "");
    std::vector<std::string> include_dirs;
    include_dirs.reserve(commons.size());

    for(const auto& item:commons){
        include_dirs.push_back(base_dir +item);
    }

    data.base_dir = "set base_dir " + base;
    data.commons_dir = include_dirs;
    data.repo_dir = project_base;
}

void project_generator_base::set_synth_sources(const std::set<std::string> &paths) {
    data.synth_sources = paths;
}

void project_generator_base::set_sim_sources(const std::set<std::string> &paths) {
    std::set<std::string> diff;
    std::set_difference(paths.begin(), paths.end(), data.synth_sources.begin(), data.synth_sources.end(),
                        std::inserter(diff, diff.begin()));

    data.sim_sources = diff;
}

 void project_generator_base::set_synth_packages(const std::set<std::string> &paths) {
    data.package_synth_sources = paths;
 }

 void project_generator_base::set_synth_data(const std::set<std::string> &paths) {
    data.data_synth_sources =paths;
 }

 void project_generator_base::set_sim_data(const std::set<std::string> &paths) {
    data.data_sim_sources = paths;
 }

 void project_generator_base::set_sim_packages(const std::set<std::string> &paths) {
    data.package_sim_sources = paths;
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

void project_generator_base::set_script_sources(const std::vector<script_source> &paths) {
    data.scripts = paths;
}


 std::string project_generator_base::open_phase(const std::string &phase_name) {
    return fmt::format(R"(    echo -e "\n\033[1;33m>>> {} <<<\033[0m")", phase_name)+ "\n";
 }

 std::string project_generator_base::check_result(const std::string &error_message) {
    std::ostringstream oss;
    oss << "    if [ $? -ne 0 ]; then"<< std::endl;
    oss << fmt::format(R"(        echo -e "\033[1;31m!!! {} !!!\033[0m")", error_message)<< std::endl;
    oss << "        exit 1"<< std::endl;
    oss << "    fi\n"<< std::endl;
    return oss.str();
 }

std::pair<std::vector<std::string>, std::vector<std::string>> project_generator_base::get_script_sim_sources(const std::span<std::string> &sources) {
    std::vector<std::string> code_sources, data_sources;
    for (auto &f:sources) {
        auto ext = std::filesystem::path(f).extension();
        if (ext != ".mem"&& ext != ".dat") code_sources.push_back(f);
        else data_sources.push_back(f);
    }
    return {code_sources, data_sources};
 }

