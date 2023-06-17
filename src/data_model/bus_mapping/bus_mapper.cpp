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

bus_mapper::bus_mapper(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d, const HDL_Resource &bdp) : resolver(bdp){
    d_store = d;
    s_store =  s;
    bus_defining_package = bdp;
}

void bus_mapper::map_bus(const nlohmann::json &bus, const std::string &bus_selector, const std::string &top_level) {
    std::string bus_if = bus[bus_selector]["bus_interface"];
    std::string starting_module  = bus[bus_selector]["starting_module"];
    bus_type = bus[bus_selector]["type"];

    auto tl = d_store->get_HDL_resource(top_level);

    bus_map_node top = {bus_if, tl, HDL_dependency()};

    map_network(top, bus_defining_package.get_bus_roots()[0]->get_base_address(), false);
    for(auto &item:leaf_nodes){
        std::cout<<"Found " << item.module_spec.getName() << " at address " <<std::hex << item.node_address << std::endl;
    }
}


void bus_mapper::map_network( bus_map_node &res, uint32_t base_address, bool parametrised) {
    std::vector<bus_map_node> bus_network;
    resolver.push_parameters_map(res.instance);
    for(auto &dep: res.module_spec.get_dependencies()){
        std::vector<bus_map_node> sub_network;
        if(parametrised) {
            if (dep.get_type() == res.module_name) {
                for (auto &port: dep.get_ports()) {
                    if (port.second.substr(0, port.second.find("[")) == res.port_name) {
                        auto module_spec = d_store->get_HDL_resource(dep.get_type());
                        bus_map_node cur_node(port.first, module_spec, dep);
                        process_node_type(cur_node, res, base_address);
                        sub_network.push_back(cur_node);
                    }
                }
            }
        } else{
            std::string if_name;
            if(res.port_name.find('[')!=std::string::npos){
                if_name = res.port_name.substr(0, res.port_name.find('['));
            } else{
                if_name = res.port_name;
            }
            for(auto &port:dep.get_ports()){
                std::string port_name;
                if(port.second.find('[')!=std::string::npos) {
                    port_name = port.second.substr(0, port.second.find('['));
                } else{
                    port_name = port.second;
                }
                if(port_contains_if(port_name, if_name)){
                    auto module_spec = d_store->get_HDL_resource(dep.get_type());
                    if(specs_manager.get_port_dir_specs(bus_type, if_port_input) == module_spec.get_if_port_specs(port.first).second){
                        bus_map_node cur_node(port.first, module_spec, dep);
                        process_node_type(cur_node, res, base_address);
                        sub_network.push_back(cur_node);
                    }
                }
            }
        }
        if(!sub_network.empty()){
            process_interconnects(res.module_spec, res.instance);
            if(!sub_network.empty()){
                for(auto &item:sub_network){
                    map_network(item, base_address, false);
                }
            }
        }
    }
    resolver.pop_parameters_map();
}

bool bus_mapper::process_node_type(bus_map_node &node, bus_map_node &parent, uint32_t base_address) {
    if(specs_manager.is_sink(node.module_spec.getName())){
        parent.node_address = base_address;
        leaf_nodes.push_back(parent);
        return false;
    }else if(specs_manager.is_interconnect(node.module_spec.getName())){
        interconnects.push_back(node);
        return false;
    }else {
        return true;
    }
}

void bus_mapper::process_interconnects(HDL_Resource &parent_res, HDL_dependency &parent_dep) {
    auto working_set = interconnects;
    interconnects.clear();
    std::string parametrized_bus_instance;
    if(parent_res.is_string_parameter("PRAGMA_MKFG_DEBUG")){
        int j = 0;
    }
    if(parent_res.is_string_parameter("PRAGMA_MKFG_PARAMETRIZED_INTERCONNECT")){
        parametrized_bus_instance = parent_res.get_parameter("PRAGMA_MKFG_PARAMETRIZED_INTERCONNECT");
    }
    for(auto &item:working_set) {
        if(item.instance.get_name()==parametrized_bus_instance){

            auto masters_str = item.instance.get_ports()[specs_manager.get_interconnect_source_port(bus_type, item.module_spec.getName())];//use spec manager instead of hardcoded name;
            HDL_dependency master_if_decl;
            for(auto &dep:parent_res.get_dependencies()){
                if(dep.get_name()==masters_str){
                    master_if_decl = dep;
                }
            }
            if(master_if_decl.is_module_array()){

                nlohmann::ordered_json bus_layout;
                for(auto if_spec:nlohmann::ordered_json::parse(parent_res.get_parameter("PRAGMA_MKFG_BUS_LAYOUT"))) {
                    if (if_spec["name"] == parametrized_bus_instance) {
                        bus_layout = if_spec;
                    }
                }

                auto n_ifs = expression_evaluator::calculate_expression(master_if_decl.get_quantifier(), parent_res, parent_dep, resolver);
                auto addresses_vect = get_parametrised_addrs(bus_layout, n_ifs, parent_res, parent_dep);

                auto map = decode_interconnect_map(bus_layout["map"], parent_res, parent_dep);

                for(int i = 0; i<map.size(); i++){
                    bus_map_node node = {masters_str, parent_res, parent_dep, 0, map[i]};
                    map_network(node, addresses_vect[i], true);
                }
            }

        } else{
            auto masters_str = item.instance.get_ports()[specs_manager.get_interconnect_source_port(bus_type, item.module_spec.getName())];
            auto masters_ifs = split_if_array(masters_str);

            auto addresses_vect = get_interconnect_addr_vect(item, parent_res);

            for(int i = 0; i<masters_ifs.size(); ++i){
                bus_map_node node = {masters_ifs[i], parent_res, parent_dep};
                map_network(node, resolver.get_address(addresses_vect[i], parent_res, parent_dep), false);
            }
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

bool bus_mapper::is_array_parameter(const std::string &port) {
    const std::regex regex(R"(\{([^\}]+)\})");
    std::smatch base_match;
    if(std::regex_search(port, base_match, regex)){
        return true;
    } else{
        return false;
    }
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

std::vector<std::string> bus_mapper::get_interconnect_addr_vect(bus_map_node &item, HDL_Resource &parent) {


    auto address_param = item.instance.get_parameters()["SLAVE_ADDR"];
    std::vector<std::string> addresses_vect;
    if(is_array_parameter(address_param)){
        addresses_vect = split_if_array(address_param);
    } else{
        auto addresses_str = parent.get_parameter(address_param);
        addresses_vect = split_if_array(addresses_str);
    }

    return addresses_vect;
}

std::vector<uint32_t> bus_mapper::get_parametrised_addrs( const nlohmann::json &spec,
                                                         uint32_t n_ifs, HDL_Resource &parent_res,
                                                         HDL_dependency &parent_dep) {
    std::vector<uint32_t> ret_val;

    uint32_t base_addr = resolver.get_address(spec["base"], parent_res, parent_dep);
    uint32_t offset = std::stoul((std::string )spec["offset"], nullptr, 0);
    for(int i = 0; i<n_ifs; i++){
        ret_val.push_back(base_addr+i*offset);
    }
    return ret_val;
}

std::unordered_map<uint32_t, std::string> bus_mapper::decode_interconnect_map(const nlohmann::ordered_json &map, HDL_Resource &parent_res, HDL_dependency &parent_dep) {
    int current_if = 0;
    std::unordered_map<uint32_t, std::string> ret_val;
    for(auto &item:map){
        expression e = expression(item["len"]);
        auto quantifier = expression_evaluator::calculate_expression(e, parent_res, parent_dep, resolver);
        for(int i = 0; i<quantifier; i++){
           ret_val[current_if] = item["mod"];
           current_if++;
        }
    }
    return ret_val;
}




