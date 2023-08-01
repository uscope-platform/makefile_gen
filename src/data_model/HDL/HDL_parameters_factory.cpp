// Copyright 2021 Filippo Savi
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "data_model/HDL/HDL_parameters_factory.hpp"


void HDL_parameters_factory::new_parameter() {
      resources_factory_base<HDL_parameter>::new_basic_resource();
      current_resource.set_type(expression_parameter);
}

HDL_parameter HDL_parameters_factory::get_parameter() {
    return resources_factory_base<HDL_parameter>::get_resource();
}

void HDL_parameters_factory::set_value(const std::string &s) {
    current_resource.set_value(s);
}

void HDL_parameters_factory::add_component(const Expression_component &c) {
    if(in_initialization_list){
        initialization_list.push_back({c});
    } else if (in_expression){
        current_expression.push_back(c);
    } else {
        current_resource.add_component(c);
    }
}

void HDL_parameters_factory::start_initialization_list() {
    in_initialization_list = true;
    initialization_list.clear();
}


void HDL_parameters_factory::stop_initializaiton_list() {
    in_initialization_list = false;
    //TODO:implement initialization list support;
    current_resource.set_initialization_list(initialization_list);
    int i = 0;
}

void HDL_parameters_factory::start_expression() {
    in_expression = true;
    current_expression.clear();
}

void HDL_parameters_factory::stop_expression() {
    in_expression = false;
    current_resource.set_expression_components(current_expression);
    current_expression.clear();
}

void HDL_parameters_factory::start_bit_selection() {
    in_bit_select = true;
    expression_stack.push(current_expression);
    current_expression.clear();
}

void HDL_parameters_factory::stop_bit_selection() {
    bit_selection = current_expression;
    current_expression = expression_stack.top();
    expression_stack.pop();
}

void HDL_parameters_factory::add_array_component() {

    current_expression.back().add_array_index(bit_selection);
}



