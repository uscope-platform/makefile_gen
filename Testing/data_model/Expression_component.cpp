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


TEST(Expression_component, sized_binary_sv_constant_parsing){
    Expression_component ec("8'b10110");

    ASSERT_EQ(ec.get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(ec.get_numeric_value(), 22);
    ASSERT_EQ(ec.get_binary_size(), 8);
}


TEST(Expression_component, sized_octal_sv_constant_parsing){
    Expression_component ec("12'o547");

    ASSERT_EQ(ec.get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(ec.get_numeric_value(), 359);
    ASSERT_EQ(ec.get_binary_size(), 12);
}


TEST(Expression_component, sized_decimal_sv_constant_parsing){
    Expression_component ec("14'd1542");

    ASSERT_EQ(ec.get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(ec.get_numeric_value(), 1542);
    ASSERT_EQ(ec.get_binary_size(), 14);
}


TEST(Expression_component, sized_hexadecimal_sv_constant_parsing){
    Expression_component ec("20'hCA54");

    ASSERT_EQ(ec.get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(ec.get_numeric_value(), 51796);
    ASSERT_EQ(ec.get_binary_size(), 20);
}



TEST(Expression_component, unsized_binary_sv_constant_parsing){
    Expression_component ec("'b10110");

    ASSERT_EQ(ec.get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(ec.get_numeric_value(), 22);
    ASSERT_EQ(ec.get_binary_size(), 5);
}


TEST(Expression_component, unsized_octal_sv_constant_parsing){
    Expression_component ec("'o547");

    ASSERT_EQ(ec.get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(ec.get_numeric_value(), 359);
    ASSERT_EQ(ec.get_binary_size(), 9);
}


TEST(Expression_component, unsized_decimal_sv_constant_parsing){
    Expression_component ec("'d1542");

    ASSERT_EQ(ec.get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(ec.get_numeric_value(), 1542);
    ASSERT_EQ(ec.get_binary_size(), 11);
}


TEST(Expression_component, unsized_hexadecimal_sv_constant_parsing){
    Expression_component ec("'hCA54");

    ASSERT_EQ(ec.get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(ec.get_numeric_value(), 51796);
    ASSERT_EQ(ec.get_binary_size(), 16);
}

