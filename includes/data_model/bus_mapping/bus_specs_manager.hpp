//  Copyright 2023 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef MAKEFILEGEN_V2_BUS_SPECS_MANAGER_HPP
#define MAKEFILEGEN_V2_BUS_SPECS_MANAGER_HPP

#include <unordered_map>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <set>
#include <unordered_set>

#include "data_model/bus_mapping/bus_component.hpp"

 typedef enum {
    if_port_input = 0,
    if_port_output = 1
} if_port_dir;

class bus_specs_manager {
public:
    bus_specs_manager();
    bus_specs_manager(const bus_specs_manager &b);
    std::vector<mapper_bus_component> get_bus_specs(const std::string &s){return bus_specs[s];};
    std::string get_component_spec(const std::string &b, const std::string &c, const std::string &s);
    std::string get_port_dir_specs(const std::string &s, if_port_dir dir){return port_dir_specs[s][dir];};
    std::string get_interconnect_source_port(const std::string &bus_name, const std::string &module_n);
    bool is_output_port(const std::string &bt, const std::string  &type);

    bool is_sink(const std::string &type, const std::string &s);
    bool is_interconnect(const std::string &type, const std::string &s);
    bool is_source(const std::string &type, const std::string &s);

    std::pair<std::string, bool> get_input_port(const std::string &b, const std::string &c);
    std::pair<std::string, bool>  get_output_port(const std::string &b, const std::string &c);

private:
    std::unordered_map<std::string, std::vector<mapper_bus_component>> bus_specs;
    std::unordered_map<std::string, std::unordered_map<if_port_dir, std::string>> port_dir_specs;

    std::unordered_map<std::string, std::unordered_set<std::string>> interconnect_modules;
    std::unordered_map<std::string, std::unordered_set<std::string>> sink_modules;
    std::unordered_map<std::string, std::unordered_set<std::string>> source_modules;
};



#endif //MAKEFILEGEN_V2_BUS_SPECS_MANAGER_HPP
