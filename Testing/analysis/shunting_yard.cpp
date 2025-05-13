//  Copyright 2023 Filippo Savi
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



#include <gtest/gtest.h>

#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"

TEST(shunting_yard, shunting_yard_priority){


    std::vector<Expression_component> expr = {
            Expression_component("add_expr_p"),
            Expression_component("+"),
            Expression_component("mul_expr_p"),
            Expression_component("*"),
            Expression_component("5")
    };
    auto rpn_expr = Expression_evaluator::expr_vector_to_rpn(expr);

    Expression_component e("");
    e.set_rpn_marker();
    std::vector<Expression_component> expected_result = {
            e,
            Expression_component("add_expr_p"),
            Expression_component("mul_expr_p"),
            Expression_component("5"),
            Expression_component("*"),
            Expression_component("+")
    };

    ASSERT_EQ(rpn_expr, expected_result);

}

TEST(shunting_yard, shunting_yard_parenthesis){

    std::vector<Expression_component> expr_1 = {
            Expression_component("("),
            Expression_component("add_expr_p"),
            Expression_component("+"),
            Expression_component("mul_expr_p"),
            Expression_component(")"),
            Expression_component("*"),
            Expression_component("5")
    };
    auto rpn_expr_1 = Expression_evaluator::expr_vector_to_rpn(expr_1);

    Expression_component e("");
    e.set_rpn_marker();
    std::vector<Expression_component> expected_result_1 = {
            e,
            Expression_component("add_expr_p"),
            Expression_component("mul_expr_p"),
            Expression_component("+"),
            Expression_component("5"),
            Expression_component("*")
    };

    ASSERT_EQ(rpn_expr_1, expected_result_1);

    std::vector<Expression_component> expr_2 = {
            Expression_component("5"),
            Expression_component("*"),
            Expression_component("("),
            Expression_component("add_expr_p"),
            Expression_component("+"),
            Expression_component("mul_expr_p"),
            Expression_component(")")

    };

    auto rpn_expr_2 = Expression_evaluator::expr_vector_to_rpn(expr_2);

    std::vector<Expression_component> expected_result_2 = {
            e,
            Expression_component("5"),
            Expression_component("add_expr_p"),
            Expression_component("mul_expr_p"),
            Expression_component("+"),
            Expression_component("*")
    };
    ASSERT_EQ(rpn_expr_2, expected_result_2);
}

TEST(shunting_yard, shunting_yard_function){

    std::vector<Expression_component> expr = {
            Expression_component("$clog2"),
            Expression_component("("),
            Expression_component("add_expr_p"),
            Expression_component("+"),
            Expression_component("2"),
            Expression_component(")")

    };

    auto rpn_expr = Expression_evaluator::expr_vector_to_rpn(expr);


    Expression_component e("");
    e.set_rpn_marker();
    std::vector<Expression_component> expected_result = {
            e,
            Expression_component("add_expr_p"),
            Expression_component("2"),
            Expression_component("+"),
            Expression_component("$clog2")
    };


    ASSERT_EQ(rpn_expr, expected_result);
}

TEST(shunting_yard, shunting_yard_parenthesis_complex){

    std::vector<Expression_component> expr_1 = {
            Expression_component("("),
            Expression_component("4"),
            Expression_component("*"),
            Expression_component("3"),
            Expression_component("+"),
            Expression_component("5"),
            Expression_component(")"),
            Expression_component("+"),
            Expression_component("1")
    };
    auto rpn_expr_1 = Expression_evaluator::expr_vector_to_rpn(expr_1);

    Expression_component e("");
    e.set_rpn_marker();

    std::vector<Expression_component> expected_result_1 = {
            e,
            Expression_component("4"),
            Expression_component("3"),
            Expression_component("*"),
            Expression_component("5"),
            Expression_component("+"),
            Expression_component("1"),
            Expression_component("+")
    };

    ASSERT_EQ(rpn_expr_1, expected_result_1);
}

TEST(shunting_yard, shunting_yard_test_5){

    Expression_component e("");
    e.set_rpn_marker();
    std::vector<Expression_component> expr_1 = {
            e,
            Expression_component("N_CHANNELS"),
            Expression_component("8"),
            Expression_component("/"),
            Expression_component("1"),
            Expression_component("+")
    };
    auto rpn_expr_1 = Expression_evaluator::expr_vector_to_rpn(expr_1);

    ASSERT_EQ(rpn_expr_1, expr_1);
}
