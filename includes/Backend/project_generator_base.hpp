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

#ifndef MAKEFILEGEN_V2_PROJECT_GENERATOR_BASE_HPP
#define MAKEFILEGEN_V2_PROJECT_GENERATOR_BASE_HPP


#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <utility>
#include <regex>
#include <nlohmann/json.hpp>

#include "Backend/backend_types.hpp"
#include "data_model/settings_store.hpp"

using json = nlohmann::json;


class project_generator_base {
public:
    explicit project_generator_base(const std::string& template_f, const std::shared_ptr<settings_store> &s_store);
    void write_makefile(std::ostream &output);
    void generate_sim_script(std::ostream &output);
    void write_sim_control_script(std::ostream &output);
    void set_project_name(const std::string& name);
    void set_directories(const std::string& repo_base, const std::string& project_base, const std::vector<std::string>& commons);
    void set_synth_sources(const std::set<std::string>& paths);
    void set_sim_sources(const std::set<std::string>& paths);
    void set_synth_packages(const std::set<std::string>& paths);
    void set_synth_data(const std::set<std::string>& paths);
    void set_sim_packages(const std::set<std::string>& paths);
    void set_sim_data(const std::set<std::string>& paths);
    void set_synth_tl(const std::string& tl);
    void set_sim_tl(const std::string& tl);
    void set_board_part(const std::string & bp);
    void set_constraint_sources(const std::unordered_set<std::string>& paths);
    void set_script_sources(const std::vector<script_source>& paths);
private:
    std::shared_ptr<settings_store> settings;
    std::string base_dir;
    std::string template_file;
    project_data data;

    std::string open_phase(const std::string &phase_name);
    std::string check_result(const std::string &error_message);
    std::pair<std::vector<std::string>, std::vector<std::string>> get_script_sim_sources(const std::span<std::string> &sources);
};


#endif //MAKEFILEGEN_V2_PROJECT_GENERATOR_BASE_HPP
