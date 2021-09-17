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

#ifndef MAKEFILEGEN_V2_PROJECT_GENERATOR_BASE_H
#define MAKEFILEGEN_V2_PROJECT_GENERATOR_BASE_H


#include <string>
#include <vector>
#include <set>
#include <utility>
#include <regex>

#include "third_party/inja.hpp"
#include "third_party/json.hpp"

using json = nlohmann::json;


class project_generator_base {
public:
    explicit project_generator_base(const std::string& template_f);
    void write_makefile(std::ofstream &output);
    void set_project_name(const std::string& name);
    void set_directories(const std::string& base,const std::vector<std::string>& commons);
    void set_synth_sources(const std::set<std::string>& paths);
    void set_sim_sources(const std::set<std::string>& paths);
    void set_synth_tl(const std::string& tl);
    void set_sim_tl(const std::string& tl);
    void set_constraint_sources(const std::set<std::string>& paths);
    void set_script_sources(const std::set<std::string>& paths);

protected:
    std::vector<std::string> process_sources_set(const std::set<std::string>& paths);
private:
    inja::Environment env;
    inja::Template tpl;
    std::string base_dir;
    std::string template_file;
    json data;
};


#endif //MAKEFILEGEN_V2_PROJECT_GENERATOR_BASE_H
