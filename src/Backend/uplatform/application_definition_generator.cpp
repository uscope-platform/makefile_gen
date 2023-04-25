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

#include "Backend/uplatform/application_definition_generator.hpp"



application_definition_generator::application_definition_generator(const std::vector<bus_map_node> &l) {
    leaves = l;

    std::unordered_map<std::string, uint32_t> app_instance_counters;
    std::unordered_set<std::string> repeated_app_instances;
    std::unordered_set<std::string> defined_app_instances;

    for(auto &item:leaves){

        if(defined_app_instances.contains(item.instance.get_name())){
            app_instance_counters[item.instance.get_name()] = 1;
        } else{
            defined_app_instances.insert(item.instance.get_name());
        }
    }

    for(auto &item:leaves){
        nlohmann::json periph;
        std::string inst_name = item.instance.get_name();
        if(app_instance_counters.contains(inst_name)){
            auto inst_count = app_instance_counters[inst_name];
            app_instance_counters[inst_name]++;
            inst_name += "_" + std::to_string(inst_count);
        }
        periph["name"] =inst_name;
        periph["peripheral_id"] = inst_name;
        periph["spec_id"] =item.instance.get_type();
        periph["base_address"] = "0x" + uint_to_hex(item.node_address);
        periph["proxied"] = false;
        periph["proxy_address"] = std::to_string(0);
        peripherals.push_back(periph);
    }
}

void application_definition_generator::write_definition_file(const std::string &path) {
    std::string str = application.dump();
    std::ofstream ss(path);
    ss<<str;
    ss.close();
}

void application_definition_generator::construct_application(const std::string &name) {
    application["application_name"] = name;
    application["bitstream"] = "";
    application["channels"] = std::vector<nlohmann::json>();
    application["channel_groups"] = std::vector<nlohmann::json>();
    application["clock_frequency"] = 100000000;
    application["initial_registers_values"] = std::vector<nlohmann::json>();
    application["macro"] = std::vector<nlohmann::json>();
    application["n_enables"] = 0;
    application["parameters"] = std::vector<nlohmann::json>();
    application["peripherals"] = peripherals;
    application["soft_cores"] = cores;
    application["timebase_address"] = "";
}



std::string application_definition_generator::uint_to_hex(uint32_t i) {
    std::ostringstream out;
    out << std::hex << i;
    return out.str();
}

void application_definition_generator::add_cores(std::vector<processor_instance> cs) {
    for(auto &core:cs){
        nlohmann::json c;
        c["id"] = core.get_name();
        c["default_program"] = "";
        std::vector<nlohmann::json> io_array;
        for(auto &i:core.get_dma_io()){
            nlohmann::json io;
            io["name"] = i.name;
            io["address"] = i.address;
            io["type"] = i.get_type();
            io_array.push_back(io);
        }
        c["io"] = io_array;
        c["address"] = core.get_address();
        cores.push_back(c);
    }
}


