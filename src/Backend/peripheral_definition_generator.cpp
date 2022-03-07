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
            peripheral_defs.push_back(generate_peripheral(mod));
        }
    }
}

nlohmann::json peripheral_definition_generator::generate_peripheral(std::shared_ptr<bus_module> &node) {
    nlohmann::json ret;
    nlohmann::json periph;

    periph["name"] = node->get_module_type();
    periph["version"] = ver;
    ret[node->get_module_type()] = periph;

    std::vector<nlohmann::json> regs;
    auto def = d_store->get_HDL_resource(node->get_module_type());
    for(auto &item:def.get_documentation().get_registers()){
        regs.push_back(generate_register(item));
    }
    return ret;
}



nlohmann::json peripheral_definition_generator::generate_register(register_documentation &doc) {

    nlohmann::json ret;

    ret["ID"] = doc.get_name();
    ret["register_name"] = doc.get_name();
    ret["description"] = doc.get_description();
    if(doc.get_read_allowed())
        ret["direction"] += "R";
    if(doc.get_write_allowed())
        ret["direction"] += "W";

    std::ostringstream off;
    off<< "0x" << std::hex << doc.get_offset();
    ret["offset"] = off.str();
    ret["register_format"] = "single";
    return ret;
}
