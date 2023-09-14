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

#include "analysis/data_acquisition_analysis.hpp"

void data_acquisition_analysis::analyze(std::shared_ptr<HDL_instance_AST> &ast) {
    auto sinks = find_sinks(ast);
    if(sinks.size()>1){
        std::cout<<"ERROR: Multiple  sinks are not supported for data acquisition analysis";
        return;
    }

    auto scope_in_pn = specs_manager.get_component_spec("axi_stream", sinks[0]->get_type(), "in_port");
    std::string data_interface;

    for(auto &item:sinks[0]->get_ports()){
        if(item.first == scope_in_pn){
            data_interface = item.second[0];
        }
    }

    backtrace_scope_inputs(sinks[0]->get_parent(), data_interface);
}

std::vector<std::shared_ptr<HDL_instance_AST>>
data_acquisition_analysis::find_sinks(std::shared_ptr<HDL_instance_AST> &ast) {
    std::vector<std::shared_ptr<HDL_instance_AST>> ret;

    for(auto &item:ast->get_dependencies()){
        if(specs_manager.is_sink(bus_type, item->get_type())){
           ret.push_back(item);
        } else {
            auto ll_res = find_sinks(item);
            ret.insert(ret.end(), ll_res.begin(), ll_res.end());
        }
    }

    return ret;
}

void data_acquisition_analysis::backtrace_scope_inputs(const std::shared_ptr<HDL_instance_AST> &node, std::string intf) {

    std::shared_ptr<HDL_instance_AST> if_source;
    std::string if_port;
    for(auto &dep:node->get_dependencies()){
        for(auto &p:dep->get_ports()){
            for(std::string &e:p.second){
                if(e == intf){
                    if(specs_manager.is_output_port("axi_stream", dep->get_type(), p.first)){
                        if_source = dep;
                        if_port = p.first;
                        goto source_found;
                    }
                }
            }
        }
    }
    source_found:
    if(!if_port.empty()){
        auto follow_on_ifs = process_node(if_source, if_port);
        int i = 0;
        for(std::string &ifs:follow_on_ifs){
            backtrace_scope_inputs(node, ifs);
        }
    } else {
        for(auto &item:node->get_ports()) {
            if(item.first == intf){
                backtrace_scope_inputs(node->get_parent(), item.second[0]);
            }
        }
    }

}

std::vector<std::string> data_acquisition_analysis::process_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port) {
    std::vector<std::string> ret;
    auto node_type = specs_manager.get_component_spec("axi_stream", node->get_type(), "type");

    if(node_type == "passthrough"){
        return process_1_to_1_node(node,port);
    } else if (node_type == "1To2"){
        return process_1_to_n_node(node, port);
    } else if (node_type == "nTo1"){
        return process_n_to_1_node(node, port);
    }
    return ret;
}

std::vector<std::string>
data_acquisition_analysis::process_n_to_1_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port) {
    std::vector<std::string> ret;
    auto in_port = specs_manager.get_input_port("axi_stream", node->get_type());
    for(auto &item:node->get_ports()){
        if(item.first == in_port.first){
            ret.insert(ret.end(), item.second.begin(), item.second.end());
        }
    }
    return ret;
}

std::vector<std::string>
data_acquisition_analysis::process_1_to_n_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port) {
    std::string ret;
    auto in_port = specs_manager.get_input_port("axi_stream", node->get_type());
    for(auto &item:node->get_ports()){
        if(item.first == in_port.first){
            ret = item.second[0];
        }
    }
    return {ret};
}

std::vector<std::string>
data_acquisition_analysis::process_1_to_1_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port) {
    std::string ret;
    auto in_port = specs_manager.get_input_port("axi_stream", node->get_type());
    for(auto &item:node->get_ports()){
        if(item.first == in_port.first){
            ret = item.second[0];
        }
    }
    return {ret};
}
