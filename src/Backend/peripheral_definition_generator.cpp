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

#include "Backend/peripheral_definition_generator.h"

peripheral_definition_generator::peripheral_definition_generator(const Depfile &file,
                                                                 std::shared_ptr<bus_crossbar> xbar, std::shared_ptr<data_store> &d) {
    bus_root = std::move(xbar);
    ver = "1.0";
    d_store = d;
    walk_bus_structure(bus_root);
}

void peripheral_definition_generator::walk_bus_structure(const std::shared_ptr<bus_crossbar> &node) {
    for(auto &item: node->get_children()){
        auto&  ptr = *item;
        std::string ret;
        if (typeid(ptr) == typeid(bus_crossbar)) {
            walk_bus_structure(std::static_pointer_cast<bus_crossbar>(item));
        } else if(typeid(ptr) == typeid(bus_module)) {
            auto mod = std::static_pointer_cast<bus_module>(item);
            HDL_Resource res = d_store->get_HDL_resource(mod->get_module_type());
            generate_peripheral(res);
        }
    }

    while(!submodules_to_generate.empty()){
        auto working_set = submodules_to_generate;
        submodules_to_generate.clear();
        for(auto &item:working_set){
           generate_peripheral(item);
        }
    }
}

void peripheral_definition_generator::generate_peripheral(HDL_Resource &res) {

    nlohmann::json specs;

    if(peripheral_defs.contains(res.getName())) return;

    specs["peripheral_name"] = res.getName();
    specs["version"] = ver;


    std::vector<nlohmann::json> regs;

    for(auto &item:res.get_documentation().get_registers()){
        regs.push_back(generate_register(item));
    }

    specs["registers"] = regs;
    peripheral_defs[res.getName()] = specs;


    for(auto &item:res.get_submodules()){
        std::string item_test = item.get_module_type();
        auto resource = d_store->get_HDL_resource(item.get_module_type());
        submodules_to_generate.push_back(resource);
    }

}



nlohmann::json peripheral_definition_generator::generate_register(register_documentation &doc) {

    nlohmann::json ret;

    ret["ID"] = doc.get_name();
    ret["register_name"] = doc.get_name();
    ret["description"] = doc.get_description();
    std::string dir;
    if(doc.get_read_allowed())
        dir += "R";
    if(doc.get_write_allowed())
        dir += "W";
    ret["direction"] = dir;
    std::ostringstream off;
    off<< "0x" << std::hex << doc.get_offset();
    ret["offset"] = off.str();
    std::vector<nlohmann::json> fields = {};
    for(auto &item:doc.get_fields()){
        fields.push_back(generate_field(item));
    }
    ret["fields"] = fields;
    return ret;
}

nlohmann::json peripheral_definition_generator::generate_field(field_documentation &doc) {
    nlohmann::json ret;
    ret["name"] = doc.get_name();
    ret["description"] = doc.get_description();
    ret["offset"] = doc.get_starting_position();
    ret["length"] = doc.get_length();
    return ret;
}

void peripheral_definition_generator::write_definition_file(const std::string &path) {
    std::string str = peripheral_defs.dump();
    std::ofstream ss(path);
    ss<<str;
    ss.close();
}
