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

#include "analysis/control_bus_analysis.hpp"

control_bus_analysis::control_bus_analysis(const Depfile &df) : specs_manager("axi_lite"){
    dfile = df;
}

void control_bus_analysis::analyze_bus(std::shared_ptr<HDL_instance_AST> &ast) {
    if(!dfile.has_mappable_bus()){
        return;
    }

    auto bus = dfile.get_bus_section()["control"];
    std::string bus_if = bus["bus_interface"];

    analysis_context top = {ast, bus_if, 0, false, "", {}};
    analize_node({top});
}

void control_bus_analysis::analyze_bus(std::shared_ptr<HDL_instance_AST> &ast,const std::string &intf) {

    std::string bus_if = intf;

    analysis_context top = {ast, bus_if, 0, false, "", {}};
    analize_node({top});
}


void control_bus_analysis::analize_node(const std::vector<analysis_context> &n) {
    for(auto &leaf:n){
        auto type = leaf.node->get_type();
        if(specs_manager.is_sink(type)){
            //manage_sink
            process_leaf_node(leaf);
        }else if(specs_manager.is_interconnect(type)){
            //manage interconnects
            analize_node(process_interconnect(leaf));
        }else {
            // manage_nested_modules
            analize_node(process_nested_module(leaf));
        }
    }
}



std::vector<analysis_context> control_bus_analysis::process_interconnect(const analysis_context &inst) {
    std::vector<analysis_context> ret_val;
    auto ic = inst.node;
    auto addresses = ic->get_parameter_value("SLAVE_ADDR")->get_array_value().get_1d_slice({0,0});
    auto masters_ifs = ic->get_ports()[specs_manager.get_interconnect_source_port(ic->get_type())];

    std::reverse(masters_ifs.begin(), masters_ifs.end());

    auto masters = expand_bus_array(masters_ifs, ic->get_parent(), addresses);

    for(auto & master : masters){
        auto dependencies=  inst.node->get_parent()->get_dependencies();
        for(auto &dep:dependencies){
            for(auto &[port_name, nets]:dep->get_ports()){
                bool stop = dep->get_name() == "pwm_cu";
                bool stop2 = master.idx == 2;
                if(nets.size()==1){
                    auto net_name = nets.front().get_base_name();

                    auto idx = dep->get_repetition_idx();

                    if(net_name == master.name){
                        if(specs_manager.is_interconnect(dep->get_type())) {
                            if(specs_manager.get_interconnect_source_port(dep->get_type()) == port_name) {
                                continue;
                            }
                        }
                        if(idx==-1) {
                            analysis_context ctx = {dep, port_name, master.address, false,
                                inst.current_module_top, inst.current_module_prefix, inst.proxy};
                            int i = 0;
                        }else if(idx == master.idx) {

                            analysis_context ctx = {dep, port_name, master.address, false,
                                                    inst.current_module_top, inst.current_module_prefix, inst.proxy};
                            ret_val.push_back(ctx);
                            if(master.in_array) goto break2;
                        }

                    }
                }

            }
        }
        break2:
        continue;
    }
    return ret_val;
}


std::vector<analysis_context> control_bus_analysis::process_nested_module(const analysis_context &inst) {
    std::vector<analysis_context> ret_stack;

    proxy_target tgt;
    if(inst.node->has_parameter("PRAGMA_MKFG_PROXY")){
        if(inst.node->get_parameter_value("PRAGMA_MKFG_PROXY")->get_string_value()=="TRUE") {
            tgt.module = inst.node->get_parameter_value("PRAGMA_MKFG_PROXY_TL")->get_string_value();
            tgt.interface = inst.node->get_parameter_value("PRAGMA_MKFG_PROXY_IF")->get_string_value();

        }
    }

    for(auto &dep:inst.node->get_dependencies()){
        for(auto &[port_name, nets]:dep->get_ports()){
            for(auto &item:nets){
                if(item.get_base_name() == inst.interface){
                    analysis_context ctx = {dep, port_name, inst.address,
                                            inst.parametric, inst.current_module_top, inst.current_module_prefix, tgt};
                    ret_stack.push_back(ctx);
                    goto breakNested;
                }
            }
        }
        breakNested:;
    }

    for(auto &item:inst.node->get_parameters()){
        if(item->get_name() == "PRAGMA_MKFG_MODULE_TOP"){
            auto top = inst.node->get_parameter_value("PRAGMA_MKFG_MODULE_TOP")->get_string_value();
            for(auto &node:ret_stack){
                node.current_module_top = top;
            }
        }
        if(item->get_name() == "PRAGMA_MKFG_CHILD_PREFIX"){
            auto prefix = inst.node->get_parameter_value("PRAGMA_MKFG_CHILD_PREFIX")->get_string_value();
            for(auto &node:ret_stack){
                node.current_module_prefix = prefix;
            }
        }
    }

    return ret_stack;
}

void control_bus_analysis::process_leaf_node(const analysis_context &leaf) {

    auto leaf_parent = leaf.node->get_parent();
    leaf.node->get_parent()->add_address(leaf.address);
    if(!leaf.current_module_top.empty()){
        leaf.node->get_parent()->set_leaf_module_top(leaf.current_module_top);
    }
    if(!leaf.current_module_prefix.empty()){
        leaf.node->get_parent()->set_leaf_module_prefix(leaf.current_module_prefix);
    }
    leaf.node->set_proxy_specs(leaf.proxy);
    std::cout<< "Found module : " + leaf_parent->get_name() + " of type: " + leaf_parent->get_type() + " at address: " << std::hex << leaf.address << "\n";
}

std::vector<bus_context>
control_bus_analysis::expand_bus_array( const std::vector<HDL_net> &s, const std::shared_ptr<HDL_instance_AST> &parent,
                                        const std::vector<int64_t> &a ) {
    std::vector<bus_context> ret;
    int address_idx = 0;
    for(auto  &m: s){
        for(auto &dep:parent->get_dependencies()){
            if(m.get_full_name() == dep->get_name()){
                auto q = dep->get_array_quantifier();

                if(q != nullptr){
                    for(int i = 0; i<q->get_numeric_value(); i++){
                        bus_context b;
                        b.address = a[address_idx];
                        address_idx++;
                        b.name = m.get_full_name();
                        b.in_array = true;
                        b.idx = i;
                        ret.push_back(b);
                    }

                } else{
                    bus_context b;
                    b.address = a[address_idx];
                    address_idx++;
                    b.name = m.get_full_name();
                    b.in_array = false;
                    b.idx = 0;
                    ret.push_back(b);
                }
            }
        }
    }
    return ret;
}

