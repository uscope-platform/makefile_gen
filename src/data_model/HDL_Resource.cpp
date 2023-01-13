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

#include "data_model/HDL_Resource.h"

///  Resource object creator
/// \param t HDL entity feature
/// \param n Name of the feature
/// \param p Path of the file
/// \param deps Dependencies of the file
/// \param r_type type of resource
HDL_Resource::HDL_Resource(sv_feature t, std::string n, std::string p, hdl_deps_t deps, resource_type_t r_type) {
    hdl_type = t;
    name = std::move(n);
    path = std::move(p);
    dependencies = std::move(deps);
    resource_type = r_type;
}

HDL_Resource::HDL_Resource(const HDL_Resource &c) {
    name = c.name;
    path = c.path;
    resource_type = c.resource_type;
    hdl_type = c.hdl_type;
    dependencies = c.dependencies;

    parameters = c.parameters;
    bus_roots = c.bus_roots;
    doc = c.doc;
    bus_submodules = c.bus_submodules;
    processor_docs = c.processor_docs;
}


const std::string &HDL_Resource::getName() const {
    return name;
}


hdl_deps_t HDL_Resource::get_dependencies() {
    return dependencies;
}

bool HDL_Resource::is_interface() {
    return hdl_type == interface;
}

std::string HDL_Resource::get_path() {
    return path;
}

bool operator==(const HDL_Resource &lhs, const HDL_Resource &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.path == rhs.path;
    ret &= lhs.resource_type == rhs.resource_type;
    ret &= lhs.hdl_type == rhs.hdl_type;
    ret &= lhs.dependencies == rhs.dependencies;
    ret &= lhs.parameters == rhs.parameters;
    ret &= lhs.bus_submodules == rhs.bus_submodules;
    ret &= lhs.processor_docs == rhs.processor_docs;

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

void HDL_Resource::add_dependencies(hdl_deps_t deps) {
    dependencies.insert( deps.begin(), deps.end());
}

