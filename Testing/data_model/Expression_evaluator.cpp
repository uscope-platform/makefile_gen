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



#include <gtest/gtest.h>

#include "data_model/HDL/parameters/Expression.hpp"
#include "data_model/HDL/parameters/Expression_evaluator.hpp"



TEST(Expression_evaluator, pure_number){
    Expression e;
    e.emplace_back("8'b10110");
    auto val = e.evaluate();
    ASSERT_TRUE(val.has_value());
    ASSERT_EQ(val.value(), 22);
}



TEST(Expression_evaluator, string){
    Expression e;
    e.emplace_back("test");
    auto val = e.evaluate();
    ASSERT_FALSE(val.has_value());
}


TEST(Expression_evaluator, simple_expression){
    Expression e;
    e.emplace_back("5");
    e.emplace_back("+");
    e.emplace_back("4");

    auto val = e.evaluate();
    ASSERT_TRUE(val.has_value());
    ASSERT_EQ(val.value(), 9);
}


TEST(Expression_evaluator, parenthesis_expression){
    Expression e;
    e.emplace_back("(");
    e.emplace_back("5");
    e.emplace_back("+");
    e.emplace_back("4");
    e.emplace_back(")");
    e.emplace_back("*");
    e.emplace_back("2");

    auto val = e.evaluate();
    ASSERT_TRUE(val.has_value());
    ASSERT_EQ(val.value(), 18);
}


