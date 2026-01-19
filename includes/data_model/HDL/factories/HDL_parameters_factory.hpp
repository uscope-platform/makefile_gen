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

#ifndef MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP
#define MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP

#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/parameters/Initialization_list.hpp"
#include "data_model/HDL/parameters/HDL_function_call.hpp"
#include "resource_factory_base.hpp"


class HDL_parameters_factory : protected resources_factory_base<HDL_parameter> {

public:
    void new_parameter();

    std::shared_ptr<HDL_parameter> get_parameter();

    void set_value(const std::string &s);

    void set_parmeter_name(const std::string &s) { set_name(s); };

    void add_component(const Expression_component &c);

    void start_initialization_list();
    void stop_initialization_list(bool default_assignment);

    void start_bit_selection();
    void stop_bit_selection();

    void start_unpacked_dimension_declaration();
    void stop_unpacked_dimension_declaration();

    void close_first_range();
    void close_array_index();

    void start_param_assignment() { in_param_assignment = true; };
    void stop_param_assignment() { in_param_assignment = false; };

    void start_replication();
    void close_replication_size();
    void stop_replication();

    void start_replication_assignment();
    void stop_replication_assignment();
    void start_expression_new();
    void stop_expression_new();

    void start_packed_assignment();
    void stop_packed_assignment();

    void start_concatenation();
    void stop_concatenation();

    void start_packed_dimension();
    void stop_packed_dimension();

    void start_array_quantifier();
    void stop_array_quantifier();

    void start_function_assignment(const std::string &f_name);
    void stop_function_assignment();

    bool in_replication_assignment_context() const {return in_replication_assignment;};
    bool in_packed_context() const {return in_packed_assignment; };
    bool is_component_relevant() const { return in_initialization_list || in_expression_new || in_unpacked_declaration || in_packed_assignment ; };

    void start_instance_parameter_assignment(const std::string& parameter_name);

    void clear_expression();

    void start_ternary_operator();

    void start_param_override() { in_param_override = true;}
    void stop_param_override() { in_param_override = false;}

private:
    bool in_param_override = false;
    bool in_bit_selection = false;
    bool in_ternary_operator = false;
    bool in_param_assignment = false;
    bool in_initialization_list = false;
    bool in_expression_new = false;
    bool in_unpacked_declaration = false;
    bool in_replication = false;
    bool in_packed_assignment = false;
    bool in_concatenation = false;
    bool in_packed_dimension = false;
    bool in_replication_assignment = false;
    bool in_bus_array_quantifier = false;
    bool in_function_assignment = false;
    bool in_replication_size = false;
    bool skip_call_name = false;

    std::stack<Concatenation> concatenations_stack;
    std::stack<Expression> expression_stack;
    std::stack<Replication> replication_stack;
    std::stack<HDL_function_call> calls_stack;


    Expression bit_selection;
    std::vector<Expression> concat_components;

    Expression new_expression;
    Concatenation new_concatenation;
    Replication new_replication;
    HDL_function_call new_call;
    int expression_level=0;
    std::stack<int> expression_level_stack;

    Initialization_list init_list;

    std::vector<dimension_t> packed_dimensions{};
};


#endif //MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP
