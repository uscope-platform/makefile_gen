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

#include "data_model/HDL/factories/HDL_parameters_factory.hpp"


void HDL_parameters_factory::new_parameter() {
      resources_factory_base<HDL_parameter>::new_basic_resource();
      current_resource.set_type(HDL_parameter::expression_parameter);
      for(auto &dim:packed_dimensions){
          init_list.add_dimension(dim, dim.packed);
      }
      packed_dimensions.clear();

}

std::shared_ptr<HDL_parameter> HDL_parameters_factory::get_parameter() {
    return std::make_shared<HDL_parameter>(get_resource());
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
    expression_level--; // This is needed because in the grammar there is an expression before the list initialization;
}


void HDL_parameters_factory::stop_initialization_list(bool default_assignment) {
    if (in_replication) {
        stop_replication();
    }
    in_initialization_list = false;
    if (default_assignment){
        init_list.set_default();
    }
    current_resource.add_initialization_list(init_list);
    init_list = Initialization_list();
    expression_level++;
}


void HDL_parameters_factory::start_bit_selection() {
    in_bit_selection = true;
    expression_stack.push(new_expression);
    new_expression.clear();
}

void HDL_parameters_factory::stop_bit_selection() {
    bit_selection = new_expression;
    new_expression = expression_stack.top();
    expression_stack.pop();
}

void HDL_parameters_factory::close_array_index() {
    if(in_bit_selection & (in_param_assignment || in_packed_assignment || in_replication_assignment|| in_param_override)){
        in_bit_selection = false;
        new_expression.components.back().add_array_index(bit_selection);
    }
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
        dimension_t dim = {first_expr, second_expr, false};
        init_list.add_dimension(dim, dim.packed);
    }
}

void HDL_parameters_factory::stop_replication() {
    if(in_replication){
        in_replication = false;
        init_list.add_item(new_replication);
    expression_level++;
    }
}

void HDL_parameters_factory::start_replication_assignment() {
    in_replication_assignment = true;
    in_replication_size = true;
}

void HDL_parameters_factory::stop_replication_assignment() {
    in_replication_assignment = false;
    init_list.set_scalar(new_replication);
}

void HDL_parameters_factory::stop_packed_assignment() {
    if(in_packed_assignment && !in_initialization_list){
        current_resource.add_initialization_list(init_list);
        init_list = Initialization_list();
        in_packed_assignment = false;
    }
}

void HDL_parameters_factory::close_replication_size() {
    in_replication_size = false;

}

void HDL_parameters_factory::start_expression_new() {
    in_expression_new = true;
    expression_level++;
}

void HDL_parameters_factory::stop_expression_new() {

    expression_level--;
    if(expression_level == 0){
        if(!new_expression.empty()){
            if(in_replication || in_replication_assignment) {
                if (in_replication_size)
                    new_replication.set_size(new_expression);
                else
                    new_replication.set_item(new_expression);
            } else if(in_unpacked_declaration || in_packed_dimension){
                expression_stack.push(new_expression);
            } else if(in_initialization_list) {
                init_list.add_item(new_expression);
            }  else if(in_concatenation) {
                new_concatenation.add_component(new_expression);
            } else {
                current_resource.set_expression(new_expression);
                if(in_function_assignment) {
                    in_function_assignment = false;
                    current_resource.set_type(HDL_parameter::function_parameter);
                }
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
    if(in_param_assignment || in_packed_assignment || in_initialization_list){
        expression_level_stack.push(expression_level);
        expression_level = 0;
        in_concatenation = true;
        new_concatenation = Concatenation();
    }

}

void HDL_parameters_factory::stop_concatenation() {
    if(in_concatenation){
        expression_level = expression_level_stack.top();
        expression_level_stack.pop();
        init_list.add_item(new_concatenation);
        in_concatenation = false;
    }
}

void HDL_parameters_factory::start_replication() {
    if(in_param_assignment || in_initialization_list || in_packed_assignment){
        in_replication = true;
        in_replication_size = true;
        expression_level--;
    }
}

void HDL_parameters_factory::start_unpacked_dimension_declaration() {
    if(in_param_assignment & !in_bus_array_quantifier){
        in_unpacked_declaration = true;
    }
}

void HDL_parameters_factory::start_packed_dimension() {
    in_packed_dimension = true;
}

void HDL_parameters_factory::stop_packed_dimension() {
    if( in_packed_dimension){
        in_packed_dimension = false;
        auto second_expr = expression_stack.top();
        expression_stack.pop();
        auto first_expr = expression_stack.top();
        expression_stack.pop();
        packed_dimensions.push_back({first_expr, second_expr, true});
    }
}


void HDL_parameters_factory::start_instance_parameter_assignment(const std::string& parameter_name) {
    resources_factory_base<HDL_parameter>::new_basic_resource();
    current_resource.set_type(HDL_parameter::expression_parameter);
    current_resource.set_name(parameter_name);
}

void HDL_parameters_factory::clear_expression() {
    expression_stack = std::stack<Expression>();
    expression_level = 0;
}

void HDL_parameters_factory::start_ternary_operator() {
    //in_ternary_operator = true;
}

void HDL_parameters_factory::start_array_quantifier() {
    in_bus_array_quantifier = true;
}

void HDL_parameters_factory::stop_array_quantifier() {
    in_bus_array_quantifier = false;
}
