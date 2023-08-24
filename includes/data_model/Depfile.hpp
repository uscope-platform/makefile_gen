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

#ifndef MAKEFILEGEN_V2_DEPFILE_HPP
#define MAKEFILEGEN_V2_DEPFILE_HPP

#include <string>
#include <fstream>
#include <iostream>

#include "data_model/Script.hpp"
#include "data_model/Constraints.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Depfile {
public:
    Depfile();
    explicit Depfile(const std::string& filename);
    explicit Depfile ( const Depfile & file);
    void set_content(const nlohmann::json &c){content = c;};
    std::string get_synth_tl();
    [[nodiscard]] json get_content() const {return content;};
    std::string get_sim_tl();
    std::string get_bus_defining_package();
    std::string get_project_name();
    json get_bus_section();
    std::vector<std::string> get_additional_synth_modules();
    std::vector<std::string> get_additional_sim_modules();
    std::vector<std::string> get_excluded_modules();
    std::vector<Constraints> get_constraints();
    std::vector<std::string> get_include_directories();
    std::vector<Script> get_scripts();
    bool is_module_excluded(const std::string &s);
    void add_excluded_module(const std::string &s);
private:
    json content;
};


#endif //MAKEFILEGEN_V2_DEPFILE_HPP
