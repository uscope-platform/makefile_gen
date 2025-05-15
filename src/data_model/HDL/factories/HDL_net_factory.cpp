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

#include "data_model/HDL/factories/HDL_net_factory.hpp"

void HDL_net_factory::new_net(const std::string &name) {
    if(!current_net.name.empty()) nets.push_back(current_net);
    current_net = HDL_net(name);
}

std::vector<HDL_net> HDL_net_factory::get_nets() {
    nets.push_back(current_net);
    return nets;
}

void HDL_net_factory::add_accessor_component(const std::string &c) {
    current_net.array_accessor.set_type(expression_parameter);
    current_net.array_accessor.add_component(Expression_component(c));
}

void HDL_net_factory::add_range_component(const std::string &c) {
    current_net.array_range.set_type(expression_parameter);
    current_net.array_range.add_component(Expression_component(c));
}

void HDL_net_factory::set_range_type(HDL_net::range_type_t t) {
    current_net.range_type = t;
}
