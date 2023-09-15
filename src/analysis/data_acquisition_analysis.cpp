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
                    auto spec = dep->get_if_specs()[p.first];
                    if(specs_manager.is_output_port("axi_stream", spec[1])){
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
        if(auto follow_on_ifs = process_node(if_source, if_port)){
            for(std::string &ifs:*follow_on_ifs){
                backtrace_scope_inputs(node, ifs);
            }
        } else{
            if(!explored_nodes.contains({if_source->get_name(), if_port})){
                backtrace_scope_inputs(if_source, if_port);
                explored_nodes.insert({if_source->get_name(), if_port});
            }
        }
    } else {
        for(auto &item:node->get_ports()) {
            if(item.first == intf){
                if(!explored_nodes.contains({node->get_parent()->get_name(), item.second[0]})){
                    explored_nodes.insert({node->get_parent()->get_name(), item.second[0]});
                    backtrace_scope_inputs(node->get_parent(), item.second[0]);
                }

            }
        }
    }

}

std::optional<std::vector<std::string>> data_acquisition_analysis::process_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port) {
    auto node_type = specs_manager.get_component_spec("axi_stream", node->get_type(), "type");

    if(specs_manager.is_interconnect("axi_stream", node->get_type())){
        if(node_type == "passthrough"){
            return process_1_to_1_node(node,port);
        } else if (node_type == "1To2"){
            return process_1_to_n_node(node, port);
        } else if (node_type == "nTo1"){
            return process_n_to_1_node(node, port);
        } else{
            throw std::runtime_error("Error: unknown axi stream insterconnect type found");
        }
    } else if(specs_manager.is_source("axi_stream", node->get_type())){
        process_source(node, port);
        return std::vector<std::string>();
    } else{
        return std::nullopt;
    }
}

void data_acquisition_analysis::process_source(const std::shared_ptr<HDL_instance_AST> &node, std::string port) {
    if(log) {
        std::cout << "FOUND DATA SOURCE AT NODE: " + node->get_name() + "\n";
    }
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
    if(log){
        std::cout<< "ANALYZING N-TO-1 DATA NODE: "+ port + " of Instance " + node->get_name() + " found sources : [";
        for(int i =0 ; i<ret.size(); i++ ){
            std::cout<< ret[i];
            if(i<ret.size()-1) std::cout << ", ";
        }
        std::cout << "]\n";
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
    if(log) std::cout<< "ANALYZING 1-TO-N DATA NODE: "+ port + " of Instance " + node->get_name() + " found sources : "+ ret + "\n";
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
    if(log) std::cout<< "ANALYZING 1-TO-1 DATA NODE: "+ port + " of Instance " + node->get_name() + " found sources : "+ ret + "\n";
    return {ret};
}
