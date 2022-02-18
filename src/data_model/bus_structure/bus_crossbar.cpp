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


#include "data_model/bus_structure/bus_crossbar.h"




bus_crossbar::bus_crossbar(std::vector<std::string> c, std::string p) : bus_component(std::move(p), bus_crossbar_t){
     raw_children_list = std::move(c);
}

void bus_crossbar::add_child(const std::shared_ptr<bus_component>& c) {
    children.push_back(c);
}

std::string bus_crossbar::to_string(std::string prefix) {
    std::string ret;
    ret += prefix +  "CROSSBAR -- " + parameter_name + " -- " + std::to_string(base_address)  + "\n";
    for(auto &child:children){
        ret += bus_component::component_to_string(child, prefix + "  ");
        if(&child != &children.back()) ret += "\n";
    }
    return ret;
}
