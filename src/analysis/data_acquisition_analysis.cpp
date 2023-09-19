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

data_acquisition_analysis::data_acquisition_analysis(bool logging) : specs_manager("axi_stream"){
    log = logging;
}


void data_acquisition_analysis::analyze(std::shared_ptr<HDL_instance_AST> &ast) {
    auto sinks = find_sinks(ast);
    if(sinks.size()>1){
        std::cout<<"ERROR: Multiple  sinks are not supported for data acquisition analysis";
        return;
    }

    auto scope_in_pn = specs_manager.get_component_spec(sinks[0]->get_type(), "in_port");
    std::string data_interface;

    for(auto &item:sinks[0]->get_ports()){
        if(item.first == scope_in_pn){
            data_interface = item.second[0];
        }
    }
    data_stream ds = {data_interface, 0};
    backtrace_scope_inputs(sinks[0]->get_parent(), ds);
    std::string dump = nlohmann::to_string(nlohmann::json(data_points));
    auto j = 24;
}

std::vector<std::shared_ptr<HDL_instance_AST>>
data_acquisition_analysis::find_sinks(std::shared_ptr<HDL_instance_AST> &ast) {
    std::vector<std::shared_ptr<HDL_instance_AST>> ret;

    for(auto &item:ast->get_dependencies()){
        if(specs_manager.is_sink(item->get_type())){
           ret.push_back(item);
           if(!item->get_channel_groups().empty()){
               auto tmp_g = item->get_channel_groups();
               groups.insert(groups.end(), tmp_g.begin(), tmp_g.end());
           }
        } else {
            auto ll_res = find_sinks(item);
            ret.insert(ret.end(), ll_res.begin(), ll_res.end());
        }
    }

    return ret;
}

void data_acquisition_analysis::backtrace_scope_inputs(const std::shared_ptr<HDL_instance_AST> &node,const data_stream &intf) {

    std::shared_ptr<HDL_instance_AST> if_source;
    std::string if_port;
    for(auto &dep:node->get_dependencies()){
        for(auto &p:dep->get_ports()){
            for(std::string &e:p.second){
                if(e == intf.if_name){
                    auto spec = dep->get_if_specs()[p.first];
                    if(specs_manager.is_output_port(spec[1])){
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
        data_stream ds = {if_port, intf.address_offset, intf.static_remap};
        if(auto follow_on_ifs = process_node(if_source, ds)){
            for(auto &ifs:*follow_on_ifs){
                backtrace_scope_inputs(node, ifs);
            }
        } else{
            if(!explored_nodes.contains({if_source->get_name(), if_port})){
                backtrace_scope_inputs(if_source, ds);
                explored_nodes.insert({if_source->get_name(), if_port});
            }
        }
    } else {
        for(auto &item:node->get_ports()) {
            if(item.first == intf.if_name){
                if(!explored_nodes.contains({node->get_parent()->get_name(), item.second[0]})){
                    explored_nodes.insert({node->get_parent()->get_name(), item.second[0]});
                    data_stream ds = {item.second[0], intf.address_offset, intf.static_remap};
                    backtrace_scope_inputs(node->get_parent(), ds);
                }

            }
        }
    }

}

std::optional<std::vector<data_stream>> data_acquisition_analysis::process_node(const std::shared_ptr<HDL_instance_AST> &node, const data_stream &in_stream) {
    auto node_type = specs_manager.get_component_spec(node->get_type(), "type");

    if(specs_manager.is_interconnect(node->get_type())){
        if(node_type == "passthrough"){
            return process_1_to_1_node(node,in_stream);
        } else if (node_type == "1To2"){
            return process_1_to_n_node(node, in_stream);
        } else if (node_type == "nTo1"){
            return process_n_to_1_node(node, in_stream);
        } else{
            throw std::runtime_error("Error: unknown axi stream insterconnect type found");
        }
    } else if(specs_manager.is_source(node->get_type())){
        process_source(node, in_stream);
        return std::vector<data_stream>();
    } else{
        return std::nullopt;
    }
}

void data_acquisition_analysis::process_source(const std::shared_ptr<HDL_instance_AST> &node, const data_stream &in_stream) {
    if(log) {
        std::cout << "FOUND DATA SOURCE AT NODE: " + node->get_name() + "\n";
    }

    std::string node_names = node->get_parameters().get("PRAGMA_MKFG_DATAPOINT_NAMES")->get_string_value();

    auto n_points_params = specs_manager.get_component_spec(node->get_type(), "n_points");
    auto n_params = node->get_parameters().get(n_points_params)->get_numeric_value();

    std::string port_suffix = specs_manager.get_component_spec(node->get_type(), in_stream.if_name);
    auto names = parse_datapoint_names(node_names);

    std::vector<int64_t> addresses;
    if(specs_manager.has_component_spec(node->get_type(), "initial_addresses")){
        auto addr_param_name = specs_manager.get_component_spec(node->get_type(), "initial_addresses");
        addresses = node->get_parameters().get(addr_param_name)->get_array_value().get_1d_slice({0,0});
    } else{
        for(int i =0; i<n_params; i++){
            addresses.push_back(i);
        }
    }

    auto port_name = node->get_ports()[in_stream.if_name];
    auto width = find_datapoint_width(node->get_parent(),  port_name[0]);

    for(int i = 0; i<n_params; i++){
        nlohmann::json dp;
        std::string channel_name;
        if(names.size() == 1 & n_params>1){
            channel_name = names[0] + "_" + std::to_string(i);
        } else{
            channel_name = names[i];
        }
        if (!port_suffix.empty()) {
            dp["name"] = channel_name + "_" +port_suffix;
            dp["id"] =   channel_name + "_" +port_suffix;
        }else{
            dp["name"] = channel_name;
            dp["id"] = channel_name;
        }
        dp["phys_width"] = width;
        dp["number"] = 0;
        if(in_stream.static_remap){
            dp["mux_setting"] = in_stream.address_offset;
        } else{
            dp["mux_setting"] = in_stream.address_offset + addresses[i];
        }
        dp["enabled"]= false;
        dp["max_value"] = 1000;
        dp["min_value"] = 0;
        dp["scaling_factor"] = 1;
        data_points.push_back(dp);
    }

}

std::vector<data_stream>
data_acquisition_analysis::process_n_to_1_node(const std::shared_ptr<HDL_instance_AST> &node, const data_stream &in_stream) {
    std::vector<data_stream> ret;
    auto in_port = specs_manager.get_input_port(node->get_type());
    for(auto &item:node->get_ports()){
        if(item.first == in_port.first){
            for(auto &port:item.second){
                data_stream ds = {port, in_stream.address_offset, in_stream.static_remap};
                ret.push_back(ds);
            }
        }
    }
    if(log){
        std::cout<< "ANALYZING N-TO-1 DATA NODE: "+ in_stream.if_name + " of Instance " + node->get_name() + " found sources : [";
        for(int i =0 ; i<ret.size(); i++ ){
            std::cout<< ret[i].if_name;
            if(i<ret.size()-1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    return ret;
}

std::vector<data_stream>
data_acquisition_analysis::process_1_to_n_node(const std::shared_ptr<HDL_instance_AST> &node, const data_stream &in_stream) {
    data_stream ret;
    auto in_port = specs_manager.get_input_port(node->get_type());
    for(auto &item:node->get_ports()){
        if(item.first == in_port.first){
            ret.if_name = item.second[0];
            ret.address_offset = in_stream.address_offset;
            ret.static_remap = in_stream.static_remap;
        }
    }
    if(log) std::cout<< "ANALYZING 1-TO-N DATA NODE: "+ in_stream.if_name + " of Instance " + node->get_name() + " found sources : "+ ret.if_name + "\n";
    return {ret};
}

std::vector<data_stream>
data_acquisition_analysis::process_1_to_1_node(const std::shared_ptr<HDL_instance_AST> &node, const data_stream &in_stream) {
    data_stream ret;

    auto in_port = specs_manager.get_input_port(node->get_type());
    int64_t remapping_addr = 0;
    std::string remapping_type;
    if(specs_manager.get_component_spec(node->get_type(), "remapping") == "true"){
        remapping_type = node->get_parameters().get("REMAP_TYPE")->get_string_value();
        remapping_addr = node->get_parameters().get("REMAP_OFFSET")->get_numeric_value();
    }

    for(auto &item:node->get_ports()){
        if(item.first == in_port.first){
            ret.if_name = item.second[0];
            if(remapping_type == "STATIC"){
                ret.address_offset = remapping_addr;
                ret.static_remap = true;
            } else if(remapping_type == "DYNAMIC"){
                ret.static_remap = false;
                ret.address_offset = in_stream.address_offset+remapping_addr;
            }

        }
    }



    if(log) std::cout<< "ANALYZING 1-TO-1 DATA NODE: "+ in_stream.if_name + " of Instance " + node->get_name() + " found sources : "+ ret.if_name + "\n";
    return {ret};
}

uint64_t
data_acquisition_analysis::find_datapoint_width(const std::shared_ptr<HDL_instance_AST> &node, std::string name) {
    for(auto &item:node->get_dependencies()){
        if(item->get_name() == name){
            return item->get_parameters().get("DATA_WIDTH")->get_numeric_value();
        }
    }
    return 32;
}
