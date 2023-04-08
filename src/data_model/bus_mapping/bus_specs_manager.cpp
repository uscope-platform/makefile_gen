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

#include "data_model/bus_mapping/bus_specs_manager.hpp"

bus_specs_manager::bus_specs_manager(const bus_specs_manager &b) {
    bus_specs = b.bus_specs;
    port_dir_specs = b.port_dir_specs;
}

bus_specs_manager::bus_specs_manager() {
    std::string specs_dir = SPECS_FOLDER;

    for(auto &item:std::filesystem::directory_iterator(specs_dir)){
        std::ifstream ifs(item.path());
        nlohmann::json bus_spec_obj = nlohmann::json::parse(ifs);
        std::string name = bus_spec_obj["name"];

        std::vector<mapper_bus_component> components;
        for(auto &comp: bus_spec_obj["components"].items()){
            mapper_bus_component new_comp(comp.key(), comp.value());
            new_comp.set_defaults(bus_spec_obj["default_specs"]);
            components.push_back(new_comp);
        }
        std::unordered_map<if_port_dir, std::string> dir_map = {{if_port_input, bus_spec_obj["modports"]["in"]}, {if_port_output, bus_spec_obj["modports"]["out"]}};
        port_dir_specs[name] = dir_map;
        bus_specs[name] = components;
    }

}

bool bus_specs_manager::is_sink(const std::string &s) {
    return false;
}

bool bus_specs_manager::is_interconnect(const std::string &s) {
    return false;
}
