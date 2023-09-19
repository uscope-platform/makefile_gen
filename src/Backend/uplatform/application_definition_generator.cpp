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


application_definition_generator::application_definition_generator(
        const std::shared_ptr<HDL_instance_AST> &l,
        const nlohmann::json &p,
        const std::map<std::string, std::string> &a) {
    periph_defs = p;
    alias_map = a;
    process_ast(l);
    deduplicate_peripheral_names();
    denormalize_addresses();
}

void application_definition_generator::process_ast(const std::shared_ptr<HDL_instance_AST> &l) {
    std::stack<std::shared_ptr<HDL_instance_AST>> working_stack;
    working_stack.push(l);

    while(!working_stack.empty()){
        auto current_node = working_stack.top();
        working_stack.pop();
        if(!current_node->get_address().empty()){

            nlohmann::json periph;
            if(!current_node->get_leaf_module_top().empty()){
                periph["name"] =current_node->get_leaf_module_top();
                periph["peripheral_id"] = current_node->get_leaf_module_top();;
            } else{
                periph["name"] =current_node->get_name();
                periph["peripheral_id"] = current_node->get_name();
            }
            std::string type = current_node->get_type();
            if(alias_map.contains(type)){
                type = alias_map[type];
            } else{
                type = current_node->get_type();
            }


            periph["spec_id"] = type;
            periph["base_address"] = std::vector<std::string>();
            for(auto a: current_node->get_address()){
                periph["base_address"].push_back("0x" + uint_to_hex(a));
            }
            periph["proxied"] = false;
            periph["proxy_address"] = std::to_string(0);

            auto spec = periph_defs[type];
            if(spec["parametric"]){
                    periph["hdl_parameters"] = get_parameters(spec, current_node);
            } else{
                periph["hdl_parameters"] =  std::vector<std::string>();
            }
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
    application["filters"] = std::vector<nlohmann::json>();
    application["programs"] = std::vector<std::string>();
    application["scripts"] = std::vector<std::string>();
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
            std::string base_name = p["name"];
            auto addr_vect = p["base_address"];
            for(int i = 0; i<addr_vect.size(); i++){
                p["base_address"] = addr_vect[i];
                p["name"] =( std::string) base_name + "_" + std::to_string(i);
                p["peripheral_id"] = p["name"];
                peripherals.push_back(p);
            }
        } else{
            p["base_address"] = p["base_address"][0];
            peripherals.push_back(p);
        }
    }

}

std::map<std::string, uint32_t>
application_definition_generator::get_parameters(const json &spec, std::shared_ptr<HDL_instance_AST> &node) {
    std::map<std::string, uint32_t> ret_map;

    for(auto &item:spec["registers"]){
        if(item.contains("n_registers")){
            std::vector<std::string> parameters = item["n_registers"];
            if(node->get_parameters().contains(parameters[0])){
                ret_map[parameters[0]] = node->get_parameters().get(parameters[0])->get_numeric_value();
            }
        }
        for(auto &f:item["fields"]){
            if(f.contains("n_fields")){
                std::vector<std::string> parameters = f["n_fields"];
                if(node->get_parameters().contains(parameters[0])){
                    ret_map[parameters[0]] = node->get_parameters().get(parameters[0])->get_numeric_value();
                }
            }
        }
    }
    return ret_map;
}

std::string application_definition_generator::get_definition_string() {
    return application.dump();
}

void application_definition_generator::add_datapoints(const std::vector<channel>& dp) {
    std::vector<nlohmann::json> channels_vect;
    for(auto &item:dp){
        nlohmann::json obj;
        obj["name"] = item.get_name();
        obj["id"] = item.get_name();
        obj["phys_width"] = item.get_phys_width();
        obj["number"] = item.get_channel_number();
        obj["mux_setting"] = item.get_mux_setting();
        obj["enabled"] = item.get_enabled();
        obj["max_value"] = item.get_max();
        obj["min_value"] = item.get_min();
        obj["scaling_factor"] = item.get_scaling_factor();
        channels_vect.push_back(obj);
    }
    application["channels"] = channels_vect;
}

void application_definition_generator::add_channel_groups(const std::vector<channel_group> &cgs) {
    std::vector<nlohmann::json> groups_obj;
    for(auto &g:cgs){
        nlohmann::json  group;
        group["group_name"] = g.get_name();
        group["group_id"] = g.get_name();
        group["default"] = g.get_default();
        std::vector<nlohmann::json> ch_v;
        for(auto &item:g.get_channels()){
            nlohmann::json i;
            i["label"] = item;
            i["value"] = item;
            ch_v.push_back(i);
        }
        group["channels"] = ch_v;

        groups_obj.push_back(group);
    }
    application["channel_groups"] = groups_obj;
}