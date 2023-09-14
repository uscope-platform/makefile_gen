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
            if(new_comp.get_class()==interconnect){
                interconnect_modules[name].insert(new_comp.get_name());
            } else if(new_comp.get_class()==sink){
                sink_modules[name].insert(new_comp.get_name());
            }
            components.push_back(new_comp);
        }
        std::unordered_map<if_port_dir, std::string> dir_map = {{if_port_input, bus_spec_obj["modports"]["in"]}, {if_port_output, bus_spec_obj["modports"]["out"]}};
        port_dir_specs[name] = dir_map;
        bus_specs[name] = components;
    }

}

bool bus_specs_manager::is_sink(const std::string &type, const std::string &s) {
    return sink_modules[type].contains(s);
}

bool bus_specs_manager::is_interconnect(const std::string &type, const std::string &s) {
    return interconnect_modules[type].contains(s);
}

std::string bus_specs_manager::get_interconnect_source_port(const std::string &bus_name, const std::string &module_n) {
    for(auto &item:bus_specs[bus_name]){
        if(item.get_name()==module_n){
            return item.get_spec("out_port");
        }
    }
    return "";
}

std::string
bus_specs_manager::get_component_spec(const std::string &b, const std::string &c, const std::string &s) {
    for(auto &item:bus_specs[b]){
        if(item.get_name() == c){
            return item.get_spec(s);
        }
    }
    return "";
}

bool bus_specs_manager::is_output_port(const std::string &bt, const std::string &cn, const std::string &pn) {
    auto out_name = get_output_port(bt, cn);

    if(out_name.second){
        std::string prefix = out_name.first.substr(0, out_name.first.find("*"));
        std::string suffix = out_name.first.substr(out_name.first.find("*")+1, out_name.first.size());
        std::string working_string = pn;
        auto remaing_s = working_string.erase(0, prefix.size());
        remaing_s = working_string.erase(working_string.size()-suffix.size(), working_string.size());
        if(remaing_s.empty()) return false;
        return std::all_of(remaing_s.begin(), remaing_s.end(), ::isdigit);
    } else {
        return pn == out_name.first;
    }
}

std::pair<std::string, bool> bus_specs_manager::get_input_port(const std::string &b, const std::string &c) {
    std::string in_name;
    for(auto &comp:bus_specs[b]){
        if(comp.get_name() == c){
            if(comp.has_spec("in_port")){
                in_name = comp.get_spec("in_port");
            } else {
                in_name = port_dir_specs[c][if_port_input];
            }
        }
    }
    return {in_name, false};
}

std::pair<std::string, bool> bus_specs_manager::get_output_port(const std::string &b, const std::string &c) {
    std::string out_name;
    bool templated =false;
    for(auto &comp:bus_specs[b]){
        if(comp.get_name() == c){
            if(comp.has_spec("out_port_template")){
                out_name = comp.get_spec("out_port_template");
                templated = true;
            } else if(comp.has_spec("out_port")){
                out_name = comp.get_spec("out_port");
            } else {
                out_name = port_dir_specs[b][if_port_input];
            }
        }
    }
    return {out_name, templated};
}
