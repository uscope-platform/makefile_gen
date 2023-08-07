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
    if(in_expression_new){
        new_expression.push_back(c);
    }
}

void HDL_parameters_factory::start_initialization_list() {
    in_initialization_list = true;
    expression_level--; // This is needed because in the grammar there is an expressionb before the list initialization;
}


void HDL_parameters_factory::stop_initializaiton_list() {
    if(in_replication){
        stop_replication();
    }
    in_initialization_list = false;
    current_resource.add_initialization_list(initialization_list);
    initialization_list.clear();
    expression_level++;
}


void HDL_parameters_factory::start_bit_selection() {
    expression_stack.push(new_expression);
    new_expression.clear();
}

void HDL_parameters_factory::stop_bit_selection() {
    bit_selection = new_expression;
    new_expression = expression_stack.top();
    expression_stack.pop();
}

void HDL_parameters_factory::close_array_index() {
    new_expression.back().add_array_index(bit_selection);
}

void HDL_parameters_factory::close_first_range() {
}

void HDL_parameters_factory::stop_unpacked_dimension_declaration() {
    if(in_unpacked_declaration){
        in_unpacked_declaration = false;
        auto second_expr = expression_stack.top();
        expression_stack.pop();
        auto first_expr = expression_stack.top();
        expression_stack.pop();
        current_resource.add_dimension({first_expr, second_expr, false});
    }
}

void HDL_parameters_factory::stop_replication() {
    in_replication = false;
    replication_components.insert(replication_components.begin(), {Expression_component("$repeat_init")});
    initialization_list.insert(initialization_list.end(), replication_components);
    replication_components.clear();

}

void HDL_parameters_factory::stop_packed_assignment() {
    if(in_packed_assignment && !in_initialization_list){
        current_resource.add_initialization_list(initialization_list);
        in_packed_assignment = false;
        initialization_list.clear();
    }
}

void HDL_parameters_factory::close_replication_size() {
    replication_components.emplace_back(",");
}

void HDL_parameters_factory::start_expression_new() {
    in_expression_new = true;
    expression_level++;
}

void HDL_parameters_factory::stop_expression_new() {

    expression_level--;
    if(expression_level == 0){
        if(!new_expression.empty()){
             if(in_unpacked_declaration || in_packed_dimension) {
                 expression_stack.push(new_expression);
             } else if(in_replication){
                 replication_components.insert(replication_components.end(), new_expression.begin(), new_expression.end());
            } else if(in_concatenation || in_packed_assignment || in_initialization_list){
                initialization_list.push_back(new_expression);
            } else {
                current_resource.set_expression_components(new_expression);
            }
        }
        new_expression.clear();
        in_expression_new = false;
    }
}

void HDL_parameters_factory::start_packed_assignment() {
    in_packed_assignment = true;
}

void HDL_parameters_factory::start_concatenation() {
    expression_level_stack.push(expression_level);
    expression_level = 0;
    in_concatenation = true;
}

void HDL_parameters_factory::stop_concatenation() {
    expression_level = expression_level_stack.top();
    expression_level_stack.pop();
    in_concatenation = false;
}

void HDL_parameters_factory::start_replication() {
    in_replication = true;
}

void HDL_parameters_factory::start_unpacked_dimension_declaration() {
    if(in_param_assignment){
        in_unpacked_declaration = true;
    }
}

void HDL_parameters_factory::start_packed_dimension() {
    in_packed_dimension = true;
}

void HDL_parameters_factory::stop_packed_dimension() {

    if(in_packed_dimension){
        in_packed_dimension = false;
        auto second_expr = expression_stack.top();
        expression_stack.pop();
        auto first_expr = expression_stack.top();
        expression_stack.pop();
        current_resource.add_dimension({first_expr, second_expr, true});
    }
}

