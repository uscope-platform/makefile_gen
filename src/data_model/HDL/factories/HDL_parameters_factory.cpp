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
      new_basic_resource();
      current_resource.set_type(HDL_parameter::expression_parameter);
      for(auto &dim:packed_dimensions){
          init_list.add_dimension(dim);
      }
      packed_dimensions.clear();

}

std::shared_ptr<HDL_parameter> HDL_parameters_factory::get_parameter() {
    auto resource = get_resource();
    return std::make_shared<HDL_parameter>(resource);
}

void HDL_parameters_factory::set_value(const std::string &s) {
    current_resource.set_value(s);
}

void HDL_parameters_factory::add_component(const Expression_component &c) {
    if (index_Factory.is_active() && !index_Factory.is_range()) {
        index_Factory.add_component(c);
    } else {
        if(in_expression_new && !skip_call_name){
            new_expression.push_back(c);
        }
        skip_call_name = false;
    }
}

void HDL_parameters_factory::start_initialization_list() {
    in_initialization_list = true;
    expression_level--; // This is needed because in the grammar there is an expression before the list initialization;
}


void HDL_parameters_factory::stop_initialization_list(bool default_assignment) {
    if (repl_factory.in_replication()) {
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
    index_Factory.start_index(false);
}

void HDL_parameters_factory::stop_bit_selection() {
    if(!new_expression.components.empty()) new_expression.components.back().add_array_index(index_Factory.get_index());
    index_Factory.stop_index();

}

void HDL_parameters_factory::close_array_index() {
    if(index_Factory.is_active() & (in_param_assignment || in_packed_assignment || repl_factory.is_assignment_context() || in_param_override)){
        index_Factory.stop_index();
        new_expression.components.back().add_array_index(index_Factory.get_index());
    }
}

void HDL_parameters_factory::stop_unpacked_dimension_declaration() {
    if(in_unpacked_declaration){
        in_unpacked_declaration = false;
        auto second_expr = expression_stack.top();
        expression_stack.pop();
        auto first_expr = expression_stack.top();
        expression_stack.pop();
        dimension_t dim = {first_expr, second_expr, false};
        init_list.add_dimension(dim);
    }
}

void HDL_parameters_factory::stop_replication() {
    if(repl_factory.in_replication()){
        init_list.add_item(repl_factory.finish());
    expression_level++;
    }
}

void HDL_parameters_factory::start_replication_assignment() {
    repl_factory.start_replication(false);
}

void HDL_parameters_factory::stop_replication_assignment() {
    init_list.set_scalar(repl_factory.finish());
}

void HDL_parameters_factory::stop_packed_assignment() {
    if(in_packed_assignment && !in_initialization_list){
        current_resource.add_initialization_list(init_list);
        init_list = Initialization_list();
        in_packed_assignment = false;
    }
}

void HDL_parameters_factory::start_expression_new() {
    in_expression_new = true;
    expression_level++;
}

void HDL_parameters_factory::stop_expression_new() {

    expression_level--;
    if(expression_level == 0){
        if(!new_expression.empty()){

            if(repl_factory.in_replication()) {
                repl_factory.add_expression(new_expression);
            } else if(in_unpacked_declaration){
                expression_stack.push(new_expression);
            } else if (index_Factory.is_range()){
                index_Factory.add_expression(new_expression);
            } else if(concat_factory.in_concatenation()) {
                concat_factory.add_component(std::make_shared<Expression>(new_expression));
            } else if(calls_factory.in_function_call()) {
                calls_factory.add_argument(std::make_shared<Expression>(new_expression));
            } else if(in_initialization_list) {
                init_list.add_item(std::make_shared<Expression>(new_expression));
            } else {
                current_resource.set_expression(std::make_shared<Expression>(new_expression));
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
        concat_factory.start_concatenation();
    }

}

void HDL_parameters_factory::stop_concatenation() {
    if(concat_factory.in_concatenation()){
        expression_level = expression_level_stack.top();
        expression_level_stack.pop();
        if (!concat_factory.in_nested()) {
            if(in_initialization_list)
                init_list.add_item(concat_factory.get_concatenation());
            else
                init_list.set_scalar(concat_factory.get_concatenation());
        }
        concat_factory.stop_concatenation();
    }
}

void HDL_parameters_factory::start_replication() {
    if(in_param_assignment || in_initialization_list || in_packed_assignment){
        repl_factory.start_replication(true);
        expression_level--;
    }
}

void HDL_parameters_factory::start_unpacked_dimension_declaration() {
    if(in_param_assignment & !in_bus_array_quantifier){
        in_unpacked_declaration = true;
    }
}

void HDL_parameters_factory::start_packed_dimension() {
    index_Factory.start_index(true);
}

void HDL_parameters_factory::stop_packed_dimension() {
    if (index_Factory.is_active()) {
        index_Factory.stop_index();
        packed_dimensions.push_back(index_Factory.get_dimension(true));
    }
}


void HDL_parameters_factory::start_instance_parameter_assignment(const std::string& parameter_name) {
    new_basic_resource();
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

void HDL_parameters_factory::start_function_assignment(const std::string &f_name) {
    calls_factory.start_function(f_name);
    skip_call_name= true;
    expression_level_stack.push(expression_level);
    expression_level = 0;
}

void HDL_parameters_factory::stop_function_assignment() {
    if (!calls_factory.is_nested()) {
        if (in_initialization_list) {
            init_list.add_item(calls_factory.get_function());
        } else {
            current_resource.set_expression(calls_factory.get_function());
        }
    }

    calls_factory.finish();
    expression_level = expression_level_stack.top();
    expression_level_stack.pop();
}
