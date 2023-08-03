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
    if(in_replication){
        replication_components.push_back({c});
    }else if(in_initialization_list){
        initialization_list.push_back({c});
    } else if (in_expression || in_unpacked_declaration){
        current_expression.push_back(c);
    } else {
        current_resource.add_component(c);
    }
}

void HDL_parameters_factory::start_initialization_list() {
    in_initialization_list = true;
    repeated_initialization = false;
    initialization_list.clear();
}


void HDL_parameters_factory::stop_initializaiton_list() {
    in_initialization_list = false;
    if(repeated_initialization){
        initialization_list.insert(initialization_list.begin(),{Expression_component("$repeat_init")});
        repeated_initialization = false;
    }
    current_resource.add_initialization_list(initialization_list);
}

void HDL_parameters_factory::set_repeated_initialization() {
    repeated_initialization = true;
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
    if(in_param_assignment){
        current_expression.back().add_array_index(bit_selection);
    }
}

void HDL_parameters_factory::close_first_range() {
    if(in_unpacked_declaration){
        expression_stack.push(current_expression);
        current_expression.clear();
    }
}

void HDL_parameters_factory::stop_unpacked_dimension_declaration() {
    in_unpacked_declaration = false;
    auto first_expr = expression_stack.top();
    expression_stack.pop();
    auto second_expr= current_expression;
    current_expression.clear();
    current_resource.add_dimension({first_expr, second_expr});
}

void HDL_parameters_factory::init_list_concatenation() {
    if(in_initialization_list){
        initialization_list.insert(initialization_list.end(),{Expression_component("$repeat_init")});
    }
}

void HDL_parameters_factory::stop_replication() {
    in_replication = false;
    replication_components.insert(replication_components.begin(), {Expression_component("$repeat_init")});
    initialization_list.insert(initialization_list.end(), replication_components.begin(), replication_components.end());
    replication_components.clear();
}






