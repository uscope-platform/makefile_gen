//  Copyright 2025 Filippo Savi
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

#include "data_model/HDL/factories/HDL_instances_factory.hpp"


void HDL_instances_factory::new_dependency(const std::string &n, const std::string &p, dependency_class dc) {
    current_instance = HDL_instance(n, p, dc);
    valid_instance = true;
}

void HDL_instances_factory::add_parameter(const std::string &name, const std::shared_ptr<HDL_parameter> &p) {
    current_instance.add_parameter(name, p);
}

void HDL_instances_factory::add_port(const std::string &name) {
    auto nets = net_factory.get_nets();
    current_instance.add_port_connection(name, nets);
    disable_net_addition = false;
}

void HDL_instances_factory::add_scalar_net(const std::string &name) {
    if(disable_net_addition) {
        disable_net_addition = false;
        return;
    }
    net_factory.new_net(name);
}

HDL_instance HDL_instances_factory::get_dependency() {
    valid_instance = false;
    return current_instance;
}

void HDL_instances_factory::start_concat_port(const std::string &n) {
    in_concat = true;
    port_name = n;
}

void HDL_instances_factory::stop_concat_port() {
    in_concat = false;
    disable_net_addition = true;
}

void HDL_instances_factory::start_replication_port(const std::string &n) {
    in_replication = 1;
    port_name = n;
}


void HDL_instances_factory::add_connection_element(const std::string &s) {
    if(disable_net_addition) {
        disable_net_addition = false;
        return;
    }
    if(in_replication==1) {
        net_factory.add_replication_size(s);
    } else if(in_replication == 2) {
        net_factory.add_replication_target(s);
    } else if(in_bit_selection) {
        net_factory.add_accessor_component(s);
    } else if(in_concat && in_array_range == 0  && in_array == 0|| in_array == 1) {
        net_factory.new_net(s);
        if(in_array == 1) in_array++;
    } else if(in_array_range==1) {
        net_factory.new_net(s);
        in_array_range++;
    } else if(in_array_range==2) {
        net_factory.add_accessor_component(s);
    } else if(in_array_range==3) {
        net_factory.add_range_component(s);
    }
}

void HDL_instances_factory::start_bit_selection() {
    in_bit_selection =  true;
}

void HDL_instances_factory::stop_bit_selection() {
    in_bit_selection = false;
}

void HDL_instances_factory::start_replication() {
    net_factory.new_net("");
    in_replication = 1;
}

void HDL_instances_factory::stop_replication() {
    in_replication = 0;
}

void HDL_instances_factory::start_interface() {
    in_interface = true;
}

void HDL_instances_factory::stop_interface() {
    in_interface = false;
}

void HDL_instances_factory::start_array() {
    in_array = 1;
}

void HDL_instances_factory::stop_array() {
    in_array = 0;
    if(!in_concat) disable_net_addition = true;
}

void HDL_instances_factory::start_array_range() {
    in_array_range = 1;
}

void HDL_instances_factory::advance_array_range_phase(const std::string &op) {
    if(op == "+") net_factory.set_range_type(HDL_selection::increasing_range);
    else if(op == "-") net_factory.set_range_type(HDL_selection::decreasing_range);
    else net_factory.set_range_type(HDL_selection::explicit_range);
    in_array_range = 3;
}

void HDL_instances_factory::stop_array_range() {
    in_array_range = 0;
    disable_net_addition = true;
}


void HDL_instances_factory::add_array_quantifier(const std::shared_ptr<HDL_parameter> &p) {
    current_instance.add_array_quantifier(p);
}
