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

#include "analysis/bus_analysis.hpp"

bus_analysis::bus_analysis(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &ds, const Depfile &df) {
    dfile = df;
    d_store = ds;
    s_store = s;
}

void bus_analysis::analyze_bus(std::shared_ptr<HDL_instance> &ast) {
    auto bus = dfile.get_bus_section()["control"];

    std::string bus_if = bus["bus_interface"];
    std::string starting_module  = bus["starting_module"];
    bus_type = bus["type"];

    analysis_context top = {ast, bus_if, 0};
    analize_node({top});
}


void bus_analysis::analize_node(const std::vector<analysis_context> &n) {
    for(auto &leaf:n){
        if(specs_manager.is_sink(leaf.node->get_type())){
            //manage_sink
            process_leaf_node(leaf);
        }else if(specs_manager.is_interconnect(leaf.node->get_type())){
            //manage interconnects
            analize_node(process_interconnect(leaf));
        }else {
            // manage_nested_modules
            analize_node(process_nested_module(leaf));
        }
    }
}



std::vector<analysis_context> bus_analysis::process_interconnect(const analysis_context &inst) {
    std::vector<analysis_context> ret_val;
    auto ic = inst.node;
    auto addresses = ic->get_parameters().get("SLAVE_ADDR").get_array_value().get_1d_slice({0,0});
    auto masters_ifs = ic->get_ports()[specs_manager.get_interconnect_source_port(bus_type, ic->get_type())];
    std::reverse(masters_ifs.begin(), masters_ifs.end());

    for(int i = 0; i<masters_ifs.size(); i++){

        for(auto &dep:inst.node->get_parent()->get_dependencies()){
            for(auto &port:dep->get_ports()){
                if(port.second.size()==1){
                    if(port.second.front() == masters_ifs[i]){
                        analysis_context ctx = {dep, port.first, addresses[i]};
                        ret_val.push_back(ctx);
                    }
                }

            }
        }
    }
    return ret_val;
}

std::vector<analysis_context> bus_analysis::process_nested_module(const analysis_context &inst) {

    std::vector<analysis_context> ret_stack;
    for(auto &dep:inst.node->get_dependencies()){
        for(auto &connection:dep->get_ports()){
            for(auto &item:connection.second){
                if(item == inst.interface){
                    analysis_context ctx = {dep, connection.first, inst.address};
                    ret_stack.push_back(ctx);
                    goto breakNested;
                }
            }
        }
        breakNested:;
    }

    return ret_stack;
}

void bus_analysis::process_leaf_node(const analysis_context &leaf) {

    auto leaf_parent = leaf.node->get_parent();
    std::cout<< "Found module : " + leaf_parent->get_name() + " of type: " + leaf_parent->get_type() + " at address: " << std::hex << leaf.address << "\n";
}

