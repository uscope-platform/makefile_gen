// Copyright 2021 Filippo Savi
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

#include "data_model/HDL/HDL_instance.hpp"

HDL_instance::HDL_instance(const HDL_instance &c) {
    parameters = c.parameters;
    ports_map = c.ports_map;
    dep_class = c.dep_class;
    type = c.type;
    name = c.name;
    groups = c.groups;
    loop_specs = c.loop_specs;
    array_quantifier = c.array_quantifier;
}


HDL_instance::HDL_instance(std::string dep_name, std::string dep_type, dependency_class d_c) {
    dep_class = d_c;
    name = std::move(dep_name);
    type = std::move(dep_type);
}

void HDL_instance::add_parameter(const std::string& parameter_name, const std::shared_ptr<HDL_parameter> &p) {
    parameters.insert(p);
}

void HDL_instance::add_port_connection(const std::string& port_name, std::vector<HDL_net> value) {
    ports_map[port_name] = std::move(value);
}

bool operator==(const HDL_instance &lhs, const HDL_instance &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.type == rhs.type;
    ret &= lhs.dep_class == rhs.dep_class;
    ret &= lhs.ports_map == rhs.ports_map;
    ret &= lhs.parameters == rhs.parameters;
    ret &= lhs.groups == rhs.groups;
    ret &= lhs.loop_specs == rhs.loop_specs;

    if(lhs.array_quantifier != nullptr && lhs.array_quantifier != nullptr){
        ret &= *lhs.array_quantifier == *rhs.array_quantifier;
    } else if(lhs.array_quantifier == nullptr && lhs.array_quantifier == nullptr){
        ret &= true;
    } else {
        ret = false;
    }


    return ret;
}

void HDL_instance::add_parameters(Parameters_map &p) {
    parameters.insert(p.begin(), p.end());
}

nlohmann::json HDL_instance::dump() {
    nlohmann::json ret;

    ret["instance_name"] = name;
    ret["instance_type"] = type;

    std::unordered_map<std::string, std::vector<std::string>> port_map_dump = {};
    for(auto &[name, nets] :ports_map) {
        for(auto &n:nets) {
            port_map_dump[name].push_back(n.get_full_name());
        }
    }
    ret["ports_map"] = port_map_dump;

    std::map<std::string, nlohmann::json> params_vect;
    for(auto &param:parameters){
        params_vect.insert({param->get_name(), param->dump()});
    }
    ret["parameters"] = params_vect;

    return ret;
}

Parameters_map HDL_instance::get_parameters() {
    return parameters;
}

Parameters_map HDL_instance::get_parameters_copy() {
    return Parameters_map::deep_copy(parameters);
}

