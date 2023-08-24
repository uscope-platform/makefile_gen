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

#include "Backend/uplatform/peripheral_definition_generator.hpp"

peripheral_definition_generator::peripheral_definition_generator(std::shared_ptr<data_store> &d, const std::shared_ptr<HDL_instance> &l) {

    ver = "1.0";
    d_store = d;

    std::set<std::string> processed_peripherals;
    std::stack<std::shared_ptr<HDL_instance>> working_stack;
    working_stack.push(l);

    while(!working_stack.empty()){
        auto current_node = working_stack.top();
        working_stack.pop();
        if(!current_node->get_address().empty()){
            processed_peripherals.insert(current_node->get_type());
            generate_peripheral(d_store->get_HDL_resource(current_node->get_type()));
        }

        for(const auto& item:current_node->get_dependencies()) working_stack.push(item);
    }

}

void peripheral_definition_generator::generate_peripheral(const HDL_Resource &res) {

    nlohmann::json specs;

    if(peripheral_defs.contains(res.getName())) return;
    std::string periph_name = res.getName();

    if(res.get_documentation().is_aliased()){
        periph_name= res.get_documentation().get_alias();
    }
    specs["peripheral_name"] = periph_name;
    specs["version"] = ver;


    std::vector<nlohmann::json> regs;

    for(auto &item:res.get_documentation().get_registers()){
        regs.push_back(generate_register(item));
    }

    specs["registers"] = regs;
    peripheral_defs[periph_name] = specs;

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
