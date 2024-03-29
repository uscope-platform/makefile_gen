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

#include "data_model/bus_mapping/bus_component.hpp"


mapper_bus_component::mapper_bus_component(const mapper_bus_component &bc) {
    name = bc.name;
    component_class = bc.component_class;
    component_specs = bc.component_specs;
}


mapper_bus_component::mapper_bus_component(const std::string &n, nlohmann::json &spec) {
    name = n;
    if(!spec.contains("class")){
        std::cerr << "ERROR: Could not find class when processing specs for bus component: "<< name<< std::endl;
        exit(-1);
    }
    std::string raw_class = spec["class"];
    if(raw_class=="source")
        component_class = source;
    else if(raw_class=="sink")
        component_class = sink;
    else if(raw_class=="interconnect")
        component_class = interconnect;
    else {
        std::cerr<< "ERROR: unknown component class: "<< raw_class<<" encountered while processing specs for bus component: "<< name<< std::endl;
        exit(-1);
    }

    for(auto &item:spec.items()){
        auto k = item.key();
        auto v = item.value();
        if(item.key() != "class"){
            component_specs[item.key()]= item.value();
        }
    }
}

bool operator==(const mapper_bus_component &lhs, const mapper_bus_component &rhs) {
    bool ret = true;
    ret &= lhs.name == rhs.name;
    ret &= lhs.component_class == rhs.component_class;
    ret &= lhs.component_specs == rhs.component_specs;
    return ret;
}

void mapper_bus_component::set_defaults(nlohmann::json &def_spec) {

    for(auto &spec:def_spec.items()){
        if(!component_specs.contains(spec.key())){
            component_specs[spec.key()]= spec.value();
        }
    }
}

