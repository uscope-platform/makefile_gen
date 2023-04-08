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

#include "data_model/bus_mapping/bus_mapper.hpp"

bus_mapper::bus_mapper(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d){
    d_store = d;
    s_store = s;
}

void bus_mapper::map_bus(const nlohmann::json &bus, const std::string &bus_selector, const std::string &top_level) {
    std::string bus_if = bus[bus_selector]["bus_interface"];
    std::string starting_module  = bus[bus_selector]["starting_module"];
    bus_type = bus[bus_selector]["type"];

    auto tl = d_store->get_HDL_resource(top_level);

    auto bus_network = map_network(tl, bus_if);
    auto clean_network = exclude_sources(bus_network);

}

std::vector<bus_map_node> bus_mapper::map_network(HDL_Resource &res, const std::string &network_name) {
    std::vector<bus_map_node> bus_network;
    for(auto &dep: res.get_dependencies()){
        for(auto &port:dep.get_ports()){
            if(port.second == network_name){
                bus_network.emplace_back(port.first, d_store->get_HDL_resource(dep.get_type()), dep);
            }
        }
    }

    return bus_network;
}

std::vector<bus_map_node>
bus_mapper::exclude_sources(std::vector<bus_map_node> network) {

    std::vector<bus_map_node> next_nodes;

    for(auto &item:network) {
        if(specs_manager.is_sink(item.module_spec.getName())){
            leaf_nodes.push_back(item);
        }
        if(specs_manager.is_interconnect(item.module_spec.getName())){
            interconnects.push_back(item);
        }

        if (item.module_spec.get_if_port_specs(item.port_name).second == specs_manager.get_port_dir_specs(bus_type, if_port_input)) {
            next_nodes.push_back(item);
        }
    }
    return next_nodes;
}