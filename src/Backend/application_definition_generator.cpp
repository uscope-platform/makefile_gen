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

#include "Backend/application_definition_generator.h"

#include <utility>


application_definition_generator::application_definition_generator(const Depfile &file,
                                                                   std::shared_ptr<bus_crossbar> xbar, std::shared_ptr<data_store> &d) : dep(file){
    bus_root = std::move(xbar);
    d_store = d;
    walk_bus_structure(bus_root);
    construct_application();
}

void application_definition_generator::walk_bus_structure(const std::shared_ptr<bus_crossbar>& node) {

    for(auto &item: node->get_children()){
        auto&  ptr = *item;
        std::string ret;
        if (typeid(ptr) == typeid(bus_crossbar)) {
            walk_bus_structure(std::static_pointer_cast<bus_crossbar>(item));
        } else if(typeid(ptr) == typeid(bus_module)) {
            auto module = std::static_pointer_cast<bus_module>(item);
            peripherals.push_back(generate_peripheral(module));

            auto test = d_store->get_HDL_resource(module->get_module_type());
            auto submodules = d_store->get_HDL_resource(module->get_module_type()).get_submodules();

            auto submodules_def = generate_submodules(submodules, module->get_name(),
                                                    module->get_base_address());
            if(!submodules_def.empty()){
                peripherals.insert(peripherals.end(), submodules_def.begin(), submodules_def.end());
            }

        }
    }
}

std::vector<nlohmann::json>
application_definition_generator::generate_submodules(std::vector<bus_submodule> &sm, const std::string &spec_prefix,
                                                      uint32_t base_address) {
    std::vector<nlohmann::json> ret;

    for (auto &item:sm) {
        auto def = generate_peripheral(item, spec_prefix, base_address);
        ret.push_back(def);
        auto children = item.get_children();
        auto child_defs = generate_submodules(children, spec_prefix + "." + item.get_name(), base_address + item.get_offset());
        if(!child_defs.empty()){
            ret.insert(ret.end(), child_defs.begin(), child_defs.end());
        }
    }

    return ret;
}

nlohmann::json application_definition_generator::generate_peripheral(std::shared_ptr<bus_module> m) {
    nlohmann::json periph;
    periph["name"] = m->get_name();
    periph["peripheral_id"] = m->get_name();
    periph["spec_id"] = m->get_module_type();
    periph["base_address"] = "0x" + uint_to_hex(m->get_base_address());
    periph["proxied"] = false;
    periph["proxy_address"] = std::to_string(0);
    periph["type"] = "Registers";
    periph["user_accessible"] = false;
    return periph;
}

nlohmann::json application_definition_generator::generate_peripheral(bus_submodule m, const std::string& spec_prefix, uint32_t base_address) {
    nlohmann::json periph;
    periph["name"] = spec_prefix + "." + m.get_name();
    periph["peripheral_id"] = spec_prefix + "." + m.get_name();
    periph["spec_id"] =  m.get_module_type();
    periph["base_address"] = "0x" + uint_to_hex(base_address + m.get_offset());
    periph["proxied"] = false;
    periph["proxy_address"] = std::to_string(0);
    periph["type"] = "Registers";
    periph["user_accessible"] = false;
    return periph;
}


void application_definition_generator::write_definition_file(const std::string &path) {
    std::string str = application.dump();
    std::ofstream ss(path);
    ss<<str;
    ss.close();
}

void application_definition_generator::construct_application() {
    application["application_name"] = dep.get_project_name();
    application["bitstream"] = "";
    application["channels"] = std::vector<nlohmann::json>();
    application["channel_groups"] = std::vector<nlohmann::json>();
    application["clock_frequency"] = 100000000;
    application["initial_registers_values"] = std::vector<nlohmann::json>();
    application["macro"] = std::vector<nlohmann::json>();
    application["n_enables"] = 0;
    application["parameters"] = std::vector<nlohmann::json>();
    application["peripherals"] = peripherals;
    application["timebase_address"] = "";
}

std::string application_definition_generator::uint_to_hex(uint32_t i) {
    std::ostringstream out;
    out << std::hex << i;
    return out.str();
}


