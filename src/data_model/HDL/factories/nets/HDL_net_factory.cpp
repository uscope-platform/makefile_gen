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

#include "../../../../../includes/data_model/HDL/factories/nets/HDL_net_factory.hpp"

void HDL_net_factory::new_net(const std::string &name) {
    if(!current_net.name.empty() && !is_in_concatenation()|| current_net.is_array() || current_net.is_replication()) {
        nets.push_back(current_net);
    }
     current_net = HDL_net(name);
}

std::vector<HDL_net> HDL_net_factory::get_nets() {
    auto ret = nets;
    if(!current_net.empty()) ret.push_back(current_net);
    nets.clear();
    current_net = HDL_net();
    return ret;
}

void HDL_net_factory::start_range() {
    range_factory.open_range(true);
}

void HDL_net_factory::close_range() {
    current_net.range = range_factory.get_range();
}

void HDL_net_factory::add_component(const std::string &c) {
    if(repetition_factory.is_in_repetition()) {
        repetition_factory.add_component(c);
    }
    if(in_array) {
        current_net.index.emplace_back(c);
    }
    if(range_factory.is_active()) {
        range_factory.add_component(c);
    }
    if(in_concatenation) {
        if(current_net.name.empty() && !repetition_factory.is_in_repetition()) {
            current_net.name = c;
        }
    }
}

void HDL_net_factory::set_range_type(HDL_range::range_type_t t) {
    range_factory.set_range_type(t);
}

void HDL_net_factory::start_concatenation() {
    in_concatenation = true;
}

void HDL_net_factory::stop_concatenation() {
    in_concatenation = false;
}

void HDL_net_factory::advance_concatenation() {
    if(!current_net.empty()) {
        nets.push_back(current_net);
    }
    current_net = HDL_net();
}

void HDL_net_factory::start_array() {
    in_array = true;
}

void HDL_net_factory::stop_array() {
    in_array = false;
}

void HDL_net_factory::set_name(const std::string &string) {
    current_net.name = string;
}

void HDL_net_factory::stop_repetition() {
    auto rep = repetition_factory.get_repetition();
    repetition_factory.stop_repetition();
    current_net.replication = rep;
}

void HDL_net_factory::add_replication_target(const std::string &c) {
    current_net.replication.target.emplace_back(c);
}

void HDL_net_factory::add_index_component(const std::string &c) {
    current_net.index.emplace_back(c);
}

void HDL_net_factory::add_replication_size(const std::string &c) {
    current_net.replication.size.emplace_back(c);
}
