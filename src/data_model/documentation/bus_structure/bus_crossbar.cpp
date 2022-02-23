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

bus_crossbar::bus_crossbar(const std::string &serialized_obj) {
    std::istringstream ss(serialized_obj);
    std::vector<std::string> tokens;
    std::string tmp;
    while(std::getline(ss, tmp, ',')) {
        tokens.push_back(tmp);
    }
    base_address = std::stoi(tokens[0]);
    parameter_name =std::string(tokens[1]);
    type = component_type(std::stoi(tokens[2]));
    std::string children_str;
    for(int i = 3;i<tokens.size(); ++i){
        children_str += tokens[i];
        if(i != tokens.size() - 1)
            children_str += ",";
    }
    tokens.clear();
    ss = std::istringstream(children_str);
    while(std::getline(ss, tmp, '/')) {
        tokens.push_back(tmp);
    }
    for(auto &item:tokens){
        children.push_back(bus_component::string_to_component(item));
    }
}

bool operator==(const bus_crossbar &lhs, const bus_crossbar &rhs) {
    bool ret = true;

    ret &= lhs.type == rhs.type;
    ret &= lhs.base_address == rhs.base_address;
    ret &= lhs.parameter_name == rhs.parameter_name;

    ret &= lhs.children.size() == rhs.children.size();

    if(ret){
        for(int i = 0; i< lhs.children.size(); ++i){
            ret &= *lhs.children[i] == *rhs.children[i];
        }
    }
    // THE RAW CHILDREN LIST IS NOT INCLUDED AS IT IS A VERY TEMPORARY HACK
    return ret;
}

bus_crossbar::operator std::string() {
    std::ostringstream tmp;
    tmp << base_address <<  "," << parameter_name << "," << component_type_to_integer(type)<< ",";

    for(int i = 0; i<children.size(); ++i){
        auto &item = children[i];
        std::string serialized_item = std::to_string(component_type_to_integer(item->get_type()));
        if(item->get_type()==bus_crossbar_t){
            serialized_item += *std::static_pointer_cast<bus_crossbar>(item);
        } else if(item->get_type() == bus_module_t){
            serialized_item += *std::static_pointer_cast<bus_module>(item);
        } else if(item->get_type() == bus_register_t) {
            serialized_item += *std::static_pointer_cast<bus_registers>(item);
        }

        tmp <<  serialized_item;
        if(i != children.size()-1) tmp << "/";
    }

    return tmp.str();
}
