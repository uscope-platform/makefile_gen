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

#include "data_model/HDL/HDL_Resource.hpp"


HDL_Resource::HDL_Resource() {
    hdl_type = module;
    name = "";
    path = "";
}


///  Resource object creator
/// \param t HDL entity feature
/// \param n Name of the feature
/// \param p Path of the file
/// \param r_type type of resource
HDL_Resource::HDL_Resource(dependency_class t, std::string n, std::string p) {
    hdl_type = t;
    name = std::move(n);
    path = std::move(p);
}

HDL_Resource::HDL_Resource(const HDL_Resource &c) {
    name = c.name;
    path = c.path;
    hdl_type = c.hdl_type;
    dependencies = c.dependencies;

    numeric_parameters = c.numeric_parameters;
    string_parameter = c.string_parameter;
    bus_roots = c.bus_roots;
    doc = c.doc;
    bus_submodules = c.bus_submodules;
    processor_docs = c.processor_docs;
    ports = c.ports;
    if_specs = c.if_specs;
}

bool HDL_Resource::is_interface() {
    return hdl_type == interface;
}



bool HDL_Resource::is_empty() {
    bool ret = true;

    ret &= name.empty();
    ret &= path.empty();
    ret &= hdl_type == module;
    ret &= numeric_parameters.empty();
    ret &= bus_submodules.empty();
    ret &= processor_docs.empty();
    ret &= dependencies.empty();
    ret &= ports.empty();
    ret &= if_specs.empty();
    ret &= bus_roots.empty();
    ret &= string_parameter.empty();

    return ret;
}

std::vector<HDL_dependency> HDL_Resource::get_dependencies() {

    return dependencies;
}

void HDL_Resource::add_dependency(const HDL_dependency &dep) {
    dependencies.push_back(dep);
}

void HDL_Resource::add_dependencies(std::vector<HDL_dependency> deps) {
    dependencies.insert(dependencies.begin(), deps.begin(), deps.end());
}



bool operator==(const HDL_Resource &lhs, const HDL_Resource &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.path == rhs.path;
    ret &= lhs.hdl_type == rhs.hdl_type;
    ret &= lhs.dependencies == rhs.dependencies;
    ret &= lhs.numeric_parameters == rhs.numeric_parameters;
    ret &= lhs.bus_submodules == rhs.bus_submodules;
    ret &= lhs.processor_docs == rhs.processor_docs;
    ret &= lhs.ports == rhs.ports;
    ret &= lhs.if_specs == rhs.if_specs;
    ret &= lhs.string_parameter == rhs.string_parameter;

    if(lhs.bus_roots.size() != rhs.bus_roots.size()){
        return false;
    } else {
        for(int i = 0; i<lhs.bus_roots.size(); ++i){
            if(lhs.bus_roots[i] == nullptr && rhs.bus_roots[i] == nullptr)
                ret &= true;

            if(lhs.bus_roots[i] != nullptr ^ rhs.bus_roots[i] != nullptr){
                ret &= false;
            }

            ret &= *lhs.bus_roots[i] == *rhs.bus_roots[i];
        }
    }

    return ret;
}

bool operator<(const HDL_Resource &lhs, const HDL_Resource &rhs) {
    return lhs.name<rhs.name;
}

void HDL_Resource::add_if_port_specs(const std::string &p_n, const std::string &if_name, const std::string &modport) {
    if_specs[p_n] = {if_name, modport};
}

std::pair<std::string, std::string> HDL_Resource::get_if_port_specs(const std::string &p_n) {
    return std::make_pair(if_specs[p_n][0],if_specs[p_n][1]);
}

