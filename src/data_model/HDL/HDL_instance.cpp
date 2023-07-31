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

#include <utility>


HDL_instance::HDL_instance(const HDL_instance &c) {
    parameters = c.parameters;
    ports_map = c.ports_map;
    dep_class = c.dep_class;
    type = c.type;
    name = c.name;
    quantifier = c.quantifier;
}


HDL_instance::HDL_instance(std::string dep_name, std::string dep_type, dependency_class d_c) {
    dep_class = d_c;
    name = std::move(dep_name);
    type = std::move(dep_type);
}

void HDL_instance::add_parameter(const std::string& parameter_name, const HDL_parameter &p) {
    parameters[parameter_name] = p;
}

void HDL_instance::add_port_connection(const std::string& port_name, std::string value) {
    ports_map[port_name] = std::move(value);
}

bool operator==(const HDL_instance &lhs, const HDL_instance &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.type == rhs.type;
    ret &= lhs.dep_class == rhs.dep_class;
    ret &= lhs.ports_map == rhs.ports_map;
    ret &= lhs.parameters == rhs.parameters;
    ret &= lhs.quantifier == rhs.quantifier;
    return ret;
}

void HDL_instance::add_array_quantifier(const expression &exp) {
    quantifier = exp;
}

void HDL_instance::add_parameters(std::unordered_map<std::string, HDL_parameter> p) {
    parameters = std::move(p);
}