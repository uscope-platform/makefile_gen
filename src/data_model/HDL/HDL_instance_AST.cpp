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

#include "data_model/HDL/HDL_instance_AST.hpp"
HDL_instance_AST::HDL_instance_AST(const HDL_instance &c) : HDL_instance(c) {

}

HDL_instance_AST::HDL_instance_AST(const HDL_instance_AST &c) {
    parameters = c.parameters;
    ports_map = c.ports_map;
    dep_class = c.dep_class;
    type = c.type;
    name = c.name;
    loop_specs = c.loop_specs;
    array_quantifier = c.array_quantifier;

    parent = c.parent;
    child_instances = c.child_instances;
    package_dependencies = c.package_dependencies;
    data_dependencies = c.data_dependencies;
    leaf_module_top = c.leaf_module_top;
    bus_address = c.bus_address;
    processors = c.processors;
    proxy_specs = c.proxy_specs;
    proxy_ast = c.proxy_ast;
    repeated_instance = c.repeated_instance;
    repetition_idx = c.repetition_idx;
}

bool operator==(const HDL_instance_AST &lhs, const HDL_instance_AST &rhs) {
    bool ret = true;
    // compare base class properties
    ret &= lhs.name == rhs.name;
    ret &= lhs.type == rhs.type;
    ret &= lhs.dep_class == rhs.dep_class;
    ret &= lhs.ports_map == rhs.ports_map;
    ret &= lhs.parameters == rhs.parameters;
    ret &= lhs.loop_specs == rhs.loop_specs;
    ret &= *lhs.array_quantifier == *rhs.array_quantifier;

    //compare child class properties
    ret &= lhs.child_instances == rhs.child_instances;
    ret &= lhs.bus_address == rhs.bus_address;
    ret &= lhs.data_dependencies == rhs.data_dependencies;
    ret &= lhs.package_dependencies == rhs.package_dependencies;
    ret &= lhs.leaf_module_top == rhs.leaf_module_top;
    ret &= lhs.bus_address == rhs.bus_address;
    ret &= lhs.processors == rhs.processors;
    ret &= lhs.proxy_specs == rhs.proxy_specs;
    ret &= lhs.repeated_instance == rhs.repeated_instance;
    ret &= lhs.repetition_idx == rhs.repetition_idx;

    return ret;
}

nlohmann::json HDL_instance_AST::dump() {
    auto ret = HDL_instance::dump();

    std::vector<nlohmann::json> children;
    children.reserve(child_instances.size());

    for(auto &child:child_instances){
        children.push_back(child->dump());
    }
    ret["children"] = children;

    if(!bus_address.empty()) ret["address"] = bus_address;

    return ret;
}


