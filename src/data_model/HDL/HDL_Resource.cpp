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

    parameters = c.parameters;
    doc = c.doc;
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
    ret &= processor_docs.empty();
    ret &= dependencies.empty();
    ret &= ports.empty();
    ret &= if_specs.empty();
    ret &= parameters.empty();

    return ret;
}

std::vector<HDL_instance> HDL_Resource::get_dependencies() {

    return dependencies;
}

void HDL_Resource::add_dependency(const HDL_instance &dep) {
    dependencies.push_back(dep);
}

void HDL_Resource::add_dependencies(std::vector<HDL_instance> deps) {
    dependencies.insert(dependencies.begin(), deps.begin(), deps.end());
}



bool operator==(const HDL_Resource &lhs, const HDL_Resource &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.path == rhs.path;
    ret &= lhs.hdl_type == rhs.hdl_type;
    ret &= lhs.dependencies == rhs.dependencies;
    ret &= lhs.processor_docs == rhs.processor_docs;
    ret &= lhs.ports == rhs.ports;
    ret &= lhs.if_specs == rhs.if_specs;
    ret &= lhs.parameters == rhs.parameters;

    return ret;
}

bool operator<(const HDL_Resource &lhs, const HDL_Resource &rhs) {
    return lhs.name<rhs.name;
}

void HDL_Resource::add_if_port_specs(const std::string &p_n, const std::string &if_name, const std::string &modport) {
    if_specs[p_n] = {if_name, modport};
}

std::unordered_map<std::string, std::array<std::string, 2>> HDL_Resource::get_if_port_specs() {
    return if_specs;
}

void HDL_Resource::set_parameters(Parameters_map p) {
    parameters = std::move(p);
}


void PrintTo(const HDL_Resource &res, std::ostream *os) {

    std::string result = "\n----------------------------------------------------";
    result += "\nHDL Resource:\n  NAME: " + res.name;
    result += "\n  PATH: " + res.path;
    result += "\n  PARAMETERS: \n";
    for(const auto& item:res.parameters){
        result += item->to_string();
    }
    result += "\n----------------------------------------------------";

    *os << result;


}


