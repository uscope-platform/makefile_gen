//  Copyright 2026 Filippo Savi
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

#include "frontend/analysis/system_verilog/sv_analyzer.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/types/HDL_simple_type.hpp"
#include "frontend/analysis/system_verilog/type_engine.hpp"

TEST(type_parameter_extraction, with_default) {
    auto test_pattern = R"(
        module test_mod #(
            parameter type T = int
        )();
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto parameters = resource.get_parameters();

    Parameters_map check_params;
    auto p = std::make_shared<HDL_parameter>();
    p->set_name("T");
    p->is_type_param = true;
    p->set_type(Type_engine::create_primitive_type("int"));
    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());
    for (const auto& [name, item] : check_params) {
        ASSERT_TRUE(parameters.contains(name));
        ASSERT_EQ(*item, *parameters.get(name));
    }
}

TEST(type_parameter_extraction, no_default) {
    auto test_pattern = R"(
        module test_mod #(
            parameter type T
        )();
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto parameters = resource.get_parameters();

    Parameters_map check_params;
    auto p = std::make_shared<HDL_parameter>();
    p->set_name("T");
    p->is_type_param = true;
    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());
    for (const auto& [name, item] : check_params) {
        ASSERT_TRUE(parameters.contains(name));
        ASSERT_EQ(*item, *parameters.get(name));
    }
}

TEST(type_parameter_extraction, unsigned_type) {
    auto test_pattern = R"(
        module test_mod #(
            parameter type B = bit
        )();
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto parameters = resource.get_parameters();

    Parameters_map check_params;
    auto p = std::make_shared<HDL_parameter>();
    p->set_name("B");
    p->is_type_param = true;
    p->set_type(Type_engine::create_primitive_type("bit"));
    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());
    for (const auto& [name, item] : check_params) {
        ASSERT_TRUE(parameters.contains(name));
        ASSERT_EQ(*item, *parameters.get(name));
    }
}

TEST(type_parameter_extraction, localparam_type) {
    auto test_pattern = R"(
        module test_mod ();
            localparam type U = int;
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto parameters = resource.get_parameters();

    Parameters_map check_params;
    auto p = std::make_shared<HDL_parameter>();
    p->set_name("U");
    p->is_type_param = true;
    p->set_type(Type_engine::create_primitive_type("int"));
    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());
    for (const auto& [name, item] : check_params) {
        ASSERT_TRUE(parameters.contains(name));
        ASSERT_EQ(*item, *parameters.get(name));
    }
}
