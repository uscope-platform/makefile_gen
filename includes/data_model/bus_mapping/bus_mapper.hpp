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

#ifndef MAKEFILEGEN_V2_BUS_MAPPER_HPP
#define MAKEFILEGEN_V2_BUS_MAPPER_HPP

#include "data_model/data_store.hpp"
#include "data_model/settings_store.hpp"
#include "data_model/bus_mapping/bus_specs_manager.hpp"
#include "data_model/bus_mapping/address_resolver.hpp"
#include "data_model/expressions/expression_evaluator.hpp"

#include <nlohmann/json.hpp>
#include <regex>


typedef struct {
    std::string port_name;
    HDL_Resource module_spec;
    HDL_instance instance;
    uint32_t node_address;
    std::string module_name;
}bus_map_node;

class bus_mapper {
public:
    bus_mapper(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d, const HDL_Resource &bdp);

    void map_bus(const nlohmann::json &bus, const std::string &bus_selector, const std::string &top_level);
    std::vector<bus_map_node> get_leaves(){return leaf_nodes;};
private:

    void map_network(bus_map_node &res_v, uint32_t base_address, bool parametrised);
    bool process_node_type(bus_map_node &node, bus_map_node &parent, uint32_t base_address);
    void process_interconnects(HDL_Resource &parent_res, HDL_instance &parent_dep);


    bool port_contains_if(const std::string &port, const std::string &intf);
    bool is_array_parameter(const std::string &port);

    std::vector<uint32_t> get_parametrised_addrs(const nlohmann::json &spec, uint32_t n_ifs, HDL_Resource &parent_res, HDL_instance &parent_dep);
    std::unordered_map<uint32_t, std::string> decode_interconnect_map(const nlohmann::ordered_json &map, HDL_Resource &parent_res, HDL_instance &parent_dep);
    std::vector<std::string> get_interconnect_addr_vect(bus_map_node &item, HDL_Resource &parent);

    std::vector<std::string> split_if_array(const std::string &array);

    std::shared_ptr<settings_store> s_store;
    std::shared_ptr<data_store> d_store;
    std::string bus_type;

    bus_specs_manager specs_manager;

    std::vector<bus_map_node> leaf_nodes;
    std::vector<bus_map_node> interconnects;
    HDL_Resource bus_defining_package;
    address_resolver resolver;

};

#endif //MAKEFILEGEN_V2_BUS_MAPPER_HPP
