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

#ifndef EXPRESSION_EVALUATOR_HPP
#define EXPRESSION_EVALUATOR_HPP

#include "data_model/HDL/parameters/Expression_component.hpp"

class Expression_evaluator {
public:
    static std::vector<Expression_component> expr_vector_to_rpn(const std::vector<Expression_component>& v);
    static int64_t evaluate_binary_expression(int64_t op_a, int64_t op_b, const std::string& operation);
    static int64_t evaluate_unary_expression(int64_t operand, const std::string& operation);
};



#endif //EXPRESSION_EVALUATOR_HPP
