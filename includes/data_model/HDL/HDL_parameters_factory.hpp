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

class HDL_parameters_factory : protected resources_factory_base<HDL_parameter>{

public:
    void new_parameter();
    HDL_parameter get_parameter();
    void set_value(const std::string &s);
    void set_parmeter_name(const std::string &s) { set_name(s);};
    void add_component(const Expression_component &c);

    void start_initialization_list();
    void stop_initializaiton_list();
    void start_expression();
    void stop_expression();

    void start_bit_selection();
    void stop_bit_selection();

    void add_array_component();

    bool in_expression_context() {return in_expression;};
    bool is_component_relevant() const {return  in_initialization_list || in_expression;};
private:
    bool in_initialization_list = false;
    bool in_expression = false;
    bool in_bit_select = false;

    std::stack<std::vector<Expression_component>> expression_stack;
    std::vector<std::vector<Expression_component>> initialization_list;
    std::vector<Expression_component> current_expression;
    std::vector<Expression_component> bit_selection;
};


#endif //MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP
