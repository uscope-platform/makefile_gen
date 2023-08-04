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

#ifndef MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP
#define MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP

#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/resource_factory_base.hpp"
#include "data_model/expressions/bus_mapping_expression.hpp"
#include "data_model/expressions/expression_evaluator.hpp"

typedef std::vector<Expression_component> Expression;

class HDL_parameters_factory : protected resources_factory_base<HDL_parameter> {

public:
    void new_parameter();

    HDL_parameter get_parameter();

    void set_value(const std::string &s);

    void set_parmeter_name(const std::string &s) { set_name(s); };

    void add_component(const Expression_component &c);

    void start_initialization_list();
    void stop_initializaiton_list();
    void start_expression();
    void stop_expression();

    void start_bit_selection();
    void stop_bit_selection();

    void start_unpacked_dimension_declaration() { in_unpacked_declaration = true; };
    void stop_unpacked_dimension_declaration();

    void close_first_range();
    void add_array_component();

    void start_param_assignment() { in_param_assignment = true; };
    void stop_param_assignment() { in_param_assignment = false; };

    void start_replication() {in_replication = true;};
    void stop_replication();

    void start_packed_assignment() {in_packed_assignment = true;};
    void stop_packed_assignment();

    bool in_expression_context() const { return in_expression; };
    bool in_packed_context() const {return in_packed_assignment; };
    bool is_component_relevant() const { return in_initialization_list || in_expression || in_unpacked_declaration || in_packed_assignment; };
private:
    bool in_param_assignment = false;
    bool in_initialization_list = false;
    bool in_expression = false;
    bool in_unpacked_declaration = false;
    bool in_replication = false;
    bool in_packed_assignment = false;

    std::stack<Expression> expression_stack;
    std::vector<Expression> initialization_list;
    std::vector<Expression> replication_components;
    Expression current_expression;
    Expression bit_selection;
    std::vector<Expression> concatenation_content;
};


#endif //MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP
