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



application_definition_generator::application_definition_generator(const std::shared_ptr<HDL_instance> &l) {
    process_ast(l);
    deduplicate_peripheral_names();
    denormalize_addresses();
}

void application_definition_generator::process_ast(const std::shared_ptr<HDL_instance> &l) {
    std::stack<std::shared_ptr<HDL_instance>> working_stack;
    working_stack.push(l);

    while(!working_stack.empty()){
        auto current_node = working_stack.top();
        working_stack.pop();
        if(!current_node->get_address().empty()){

            nlohmann::json periph;
            std::string inst_name = current_node->get_name();

            periph["name"] =inst_name;
            periph["peripheral_id"] = inst_name;
            periph["spec_id"] =current_node->get_type();
            periph["base_address"] = std::vector<std::string>();
            for(auto a: current_node->get_address()){
                periph["base_address"].push_back("0x" + uint_to_hex(a));
            }
            periph["proxied"] = false;
            periph["proxy_address"] = std::to_string(0);
            peripherals.push_back(periph);
        }

        for(const auto& item:current_node->get_dependencies()) working_stack.push(item);
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

void application_definition_generator::deduplicate_peripheral_names() {

    std::map<std::string, int> duplicate_periph_count;

    for(auto &p : peripherals){
        if(duplicate_periph_count.contains(p["name"])){
            duplicate_periph_count[p["name"]]++;
        } else{
            duplicate_periph_count[p["name"]] = 1;
        }
    }
    std::map<std::string, int> deduplication_progressive;
    for(auto &p : peripherals){
        if(duplicate_periph_count[p["name"]] != 1){
            if(deduplication_progressive.contains(p["name"])){
                deduplication_progressive[p["name"]]++;
                p["name"] = (std::string) p["name"] + "_" +std::to_string(deduplication_progressive[p["name"]]);
                p["peripheral_id"] = p["name"];
            } else{
                deduplication_progressive[p["name"]] = 1;
                p["name"] = (std::string) p["name"] + "_0";
                p["peripheral_id"] = p["name"];
            }
        }
    }
}

void application_definition_generator::denormalize_addresses() {
    auto current_peripherals = std::move(peripherals);
    for(auto &p: current_peripherals){
        if(p["base_address"].size()>1){
            auto addr_vect = p["base_address"];
            for(int i = 0; i<addr_vect.size(); i++){
                p["base_address"] = addr_vect[i];
                p["name"] =( std::string) p["name"] + "_" + std::to_string(i);
                p["peripheral_id"] = p["name"];
                peripherals.push_back(p);
            }
        } else{
            p["base_address"] = p["base_address"][0];
            peripherals.push_back(p);
        }
    }

}

