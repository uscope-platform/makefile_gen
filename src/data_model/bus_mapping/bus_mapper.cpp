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

bus_mapper::bus_mapper(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d, const HDL_Resource &bdp){
    d_store = d;
    s_store = s;
    bus_defining_package = bdp;
}

void bus_mapper::map_bus(const nlohmann::json &bus, const std::string &bus_selector, const std::string &top_level) {
    std::string bus_if = bus[bus_selector]["bus_interface"];
    std::string starting_module  = bus[bus_selector]["starting_module"];
    bus_type = bus[bus_selector]["type"];

    auto tl = d_store->get_HDL_resource(top_level);

    bus_map_node n = {bus_if, tl, HDL_dependency()};
    std::vector<bus_map_node> top = {n};

    map_network(top);

}


void bus_mapper::map_network(std::vector<bus_map_node> &res_v) {
    std::vector<bus_map_node> bus_network;
    for(auto &res:res_v) {
        for(auto &dep: res.module_spec.get_dependencies()){
            std::vector<bus_map_node> sub_network;
            for(auto &port:dep.get_ports()){
                if(port_contains_if(port.second, res.port_name)){
                    auto module_spec = d_store->get_HDL_resource(dep.get_type());
                    if(specs_manager.get_port_dir_specs(bus_type, if_port_input) == module_spec.get_if_port_specs(port.first).second){
                        bus_map_node cur_node(port.first, module_spec, dep);
                        process_node_type(cur_node, res);
                        sub_network.push_back(cur_node);
                    } else{

                    }
                }
            }
            if(!sub_network.empty()){
                process_interconnects(res.module_spec);
                if(!sub_network.empty()){
                    map_network(sub_network);
                }
            }
        }
    }
}

bool bus_mapper::process_node_type(bus_map_node &node, bus_map_node &parent) {
    if(specs_manager.is_sink(node.module_spec.getName())){
        leaf_nodes.push_back(parent);
        return false;
    }else if(specs_manager.is_interconnect(node.module_spec.getName())){
        interconnects.push_back(node);
        return false;
    }else {
        return true;
    }
}

void bus_mapper::process_interconnects(HDL_Resource &parent) {
    auto working_set = interconnects;
    interconnects.clear();

    for(auto &item:working_set) {
        auto masters_str = item.instance.get_ports()[specs_manager.get_interconnect_source_port(bus_type, item.module_spec.getName())];//use spec manager instead of hardcoded name;
        auto masters_ifs = split_if_array(masters_str);
        auto addresses_str = item.instance.get_parameters()["SLAVE_ADDR"];
        auto address_param = parent.get_numeric_parameters()[addresses_str];
        for(auto &m:masters_ifs){
            bus_map_node n = {m, parent, HDL_dependency()};
            std::vector<bus_map_node> top = {n};

            map_network(top);
        }
    }

}

bool bus_mapper::port_contains_if(const std::string &port, const std::string &intf) {
    const std::regex regex(R"(\{([^\}]+)\})");
    std::smatch base_match;
    if(std::regex_search(port, base_match, regex)){
        std::stringstream ss(base_match[1].str());
        std::string item;
        while (std::getline(ss, item, ',')) {
            if(item==intf) return true;
        }
    }else{
        return  port==intf;
    }
    return false;
}

std::vector<std::string> bus_mapper::split_if_array(const std::string &array) {
    std::vector<std::string> retval;
    const std::regex regex(R"(\{([^\}]+)\})");
    std::smatch base_match;
    if(std::regex_search(array, base_match, regex)){
        std::stringstream ss(base_match[1].str());
        std::string item;

        while (std::getline(ss, item, ',')) {
           retval.push_back(item);
        }
    }else{
        retval.push_back(array);
    }
    return retval;
}



