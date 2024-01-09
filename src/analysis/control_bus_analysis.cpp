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
    if(inst.node->get_parent()->get_parameters().contains("PRAGMA_MKFG_PARAMETRIZED_INTERCONNECT")){
        return process_parametric_interconnect(inst);
    } else{
        return process_simple_interconnect(inst);
    }
}

std::vector<analysis_context> control_bus_analysis::process_simple_interconnect(const analysis_context &inst) {
    std::vector<analysis_context> ret_val;
    auto ic = inst.node;
    auto addresses = ic->get_parameter_value("SLAVE_ADDR")->get_array_value().get_1d_slice({0,0});
    auto masters_ifs = ic->get_ports()[specs_manager.get_interconnect_source_port(ic->get_type())];
    std::reverse(masters_ifs.begin(), masters_ifs.end());

    for(int i = 0; i<masters_ifs.size(); i++){

        for(auto &dep:inst.node->get_parent()->get_dependencies()){
            bool check = dep->get_name() == "core_c_0";
            for(auto &port:dep->get_ports()){
                if(port.second.size()==1){
                    if(port.second.front() == masters_ifs[i]){
                        analysis_context ctx = {dep, port.first, addresses[i] , false,
                                                inst.current_module_top, inst.proxy};
                        ret_val.push_back(ctx);
                    }
                }

            }
        }
    }
    return ret_val;
}

std::vector<analysis_context> control_bus_analysis::process_parametric_interconnect(const analysis_context &inst) {
    nlohmann::ordered_json bus_layout;

    auto node = inst.node->get_parent();

    auto instance_name = node->get_parameter_value("PRAGMA_MKFG_PARAMETRIZED_INTERCONNECT");
    auto layout = node->get_parameter_value("PRAGMA_MKFG_BUS_LAYOUT")->get_string_value();
    std::string repl = R"(")";
    layout = std::regex_replace(layout, std::regex("\\\\"), repl);

    nlohmann::json interconnect_specs = nlohmann::ordered_json::parse(layout);


    std::vector<int64_t> addresses;
    std::vector<std::string> modules;
    std::vector<std::string> interfaces;

    int64_t base_address = node->get_parameter_value(interconnect_specs["base"])->get_numeric_value();
    int64_t offset = std::stoll((std::string) interconnect_specs["offset"], nullptr, 0);
    int64_t segment_base = 0;
    for(auto &item:interconnect_specs["map"]){
        int64_t len;
        if(node->get_parameters().contains(item["len"])){
            len = node->get_parameter_value(item["len"])->get_numeric_value();
        } else {
           len = std::stoll((std::string) item["len"], nullptr, 0);
        }
        for(int i = 0; i<len; i++){
            addresses.push_back(base_address + (segment_base+i)*offset);
            interfaces.push_back(item["if"]);
            modules.push_back(item["mod"]);
        }
        segment_base = len;
    }


    std::vector<analysis_context> res;
    for(int i = 0; i<modules.size(); i++){
        for(auto &d:node->get_dependencies()){
            if(d->get_name() == modules[i]){
                analysis_context a = {d, interfaces[i], addresses[i], true,
                                      inst.current_module_top, inst.proxy};
                res.push_back(a);
            }
        }
    }
    return res;
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

    if(inst.parametric){
        for(auto &dep:inst.node->get_dependencies()){
            for(auto &connection:dep->get_ports()){
                for(auto &item:connection.second){
                    if(item == inst.interface){
                        analysis_context ctx = {dep, connection.first, inst.address,
                                                inst.parametric, inst.current_module_top, tgt};
                        ret_stack.push_back(ctx);
                        goto breakNested2;
                    }
                }
            }
            breakNested2:;
        }
    } else{
        for(auto &dep:inst.node->get_dependencies()){
            for(auto &connection:dep->get_ports()){
                for(auto &item:connection.second){
                    auto pn = item.substr(0, item.find('[')); // TODO: This is a bodge to support array of instances, proper suppoty should be implemented
                    if(pn == inst.interface){
                        analysis_context ctx = {dep, connection.first,
                                                inst.address, inst.parametric, inst.current_module_top, tgt};
                        ret_stack.push_back(ctx);
                        goto breakNested;
                    }
                }
            }
            breakNested:;
        }
    }

    for(auto &item:inst.node->get_parameters()){
        if(item->get_name() == "PRAGMA_MKFG_MODULE_TOP"){
            for(auto &node:ret_stack){
                node.current_module_top = inst.node->get_parameter_value("PRAGMA_MKFG_MODULE_TOP")->get_string_value();
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
    leaf.node->set_proxy_specs(leaf.proxy);
    std::cout<< "Found module : " + leaf_parent->get_name() + " of type: " + leaf_parent->get_type() + " at address: " << std::hex << leaf.address << "\n";
}

