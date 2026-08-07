//  Copyright 2023 Filippo Savi
//  Author: Filippo Savi <filssavi@gmap->com>
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
#include "data_model/HDL/statement/hdl_statements.hpp"
#include "frontend/analysis/system_verilog/type_engine.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "analysis/parameter_solver.hpp"
#include "data_model/HDL/parameters/components/HDL_function_call.hpp"

using namespace std::string_literals;

TEST(system_task, simple) {
    auto test_pattern = R"(

    module test_mod #(
    )();

        localparam CAST = $rtoi(16.8);

    endmodule
    )";

    sv_analyzer analyzer;

    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_name("CAST");
    p->set_type(Type_engine::create_primitive_type("implicit"));
    HDL_function_call call("$rtoi");
    call.add_argument(std::make_shared<Numeric_token>("16.8"));

    p->set_raw_value(std::make_shared<HDL_function_call>(call));

    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& [name, item]:check_params){
        ASSERT_TRUE(parameters.contains(name));
        ASSERT_EQ(*item, *parameters.get(name));
    }

    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    std::map<qualified_identifier, resolved_parameter> check_defaults = {
        {qualified_identifier("CAST"), 17},
    };

    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(system_task, multiple) {
    auto test_pattern = R"(

    module test_mod #(
    )();

        localparam CAST = $rtoi(14.8+2);
        localparam CAST_2 = $rtoi(12.2);

    endmodule
    )";

    sv_analyzer analyzer;

    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_name("CAST");
    p->set_type(Type_engine::create_primitive_type("implicit"));
    HDL_function_call call("$rtoi");
    Expression_v2 e;
    e.set_lhs(std::make_shared<Numeric_token>("14.8"));
    e.set_rhs(std::make_shared<Numeric_token>("2"));
    e.set_operation(Expression_v2::add);
    call.add_argument(std::make_shared<Expression_v2>(e));

    p->set_raw_value(std::make_shared<HDL_function_call>(call));

    check_params.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("CAST_2");
    p->set_type(Type_engine::create_primitive_type("implicit"));
    call = HDL_function_call("$rtoi");
    call.add_argument(std::make_shared<Numeric_token>("12.2"));
    p->set_raw_value(std::make_shared<HDL_function_call>(call));

    check_params.insert(p);
    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& [name, item]:check_params){
        ASSERT_TRUE(parameters.contains(name));
        ASSERT_EQ(*item, *parameters.get(name));
    }

    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    std::map<qualified_identifier, resolved_parameter> check_defaults = {
        {qualified_identifier("CAST"), 17},
        {qualified_identifier("CAST_2"), 12},
    };

    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(system_task, propagation) {
    auto test_pattern = R"(

    module test_mod #(
        parameter PARAMETER_1 = 5
    )();

        localparam CAST = $rtoi(11.8 + PARAMETER_1);

    endmodule
    )";

    sv_analyzer analyzer;

    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_name("CAST");
    p->set_type(Type_engine::create_primitive_type("implicit"));
    HDL_function_call call("$rtoi");
    Expression_v2 e;
    e.set_lhs(std::make_shared<Numeric_token>("11.8"));
    e.set_rhs(std::make_shared<Identifier_token>(qualified_identifier("PARAMETER_1")));
    e.set_operation(Expression_v2::add);
    call.add_argument(std::make_shared<Expression_v2>(e));

    p->set_raw_value(std::make_shared<HDL_function_call>(call));

    check_params.insert(p);
    p = std::make_shared<HDL_parameter>();
    p->set_name("PARAMETER_1");
    p->set_type(Type_engine::create_primitive_type("implicit"));
    p->set_raw_value(std::make_shared<Numeric_token>("5"));
    check_params.insert(p);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& [name, item]:check_params){
        ASSERT_TRUE(parameters.contains(name));
        ASSERT_EQ(*item, *parameters.get(name));
    }

    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    std::map<qualified_identifier, resolved_parameter> check_defaults = {
        {qualified_identifier("CAST"), 17},
    };

    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(system_task, nested) {
    auto test_pattern = R"(

    module test_mod #(
        parameter PARAMETER_1 = 46
    )();

        localparam CAST = $rtoi($ceil(PARAMETER_1/16.0));

    endmodule
    )";

    sv_analyzer analyzer;

    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto parameters = resource.get_parameters();

    Parameters_map check_params;
    auto p = std::make_shared<HDL_parameter>();
    p->set_name("PARAMETER_1");
    p->set_type(Type_engine::create_primitive_type("implicit"));
    p->set_raw_value(std::make_shared<Numeric_token>("46"));
    check_params.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("CAST");
    p->set_type(Type_engine::create_primitive_type("implicit"));
    auto inner_call = std::make_shared<HDL_function_call>("$ceil");
    Expression_v2 e;
    e.set_lhs(std::make_shared<Identifier_token>(qualified_identifier("PARAMETER_1")));
    e.set_operation(Expression_v2::divide);
    e.set_rhs(std::make_shared<Numeric_token>("16.0"));
    inner_call->add_argument(std::make_shared<Expression_v2>(e));
    auto outer_call = std::make_shared<HDL_function_call>("$rtoi");
    outer_call->add_argument(inner_call);

    p->set_raw_value(outer_call);

    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& [name, item]:check_params){
        ASSERT_TRUE(parameters.contains(name));
        ASSERT_EQ(*item, *parameters.get(name));
    }

    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    std::map<qualified_identifier, resolved_parameter> check_defaults = {
        {qualified_identifier("PARAMETER_1"), 46},
        {qualified_identifier("CAST"), 3}
    };

    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(system_task, ln) {
    auto test_pattern = R"(
        module test_mod ();
            localparam V = $ln(1.0);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("V")).get_real(), 0.0);
}

TEST(system_task, log10) {
    auto test_pattern = R"(
        module test_mod ();
            localparam V = $log10(100);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("V")).get_real(), 2.0);
}

TEST(system_task, sqrt) {
    auto test_pattern = R"(
        module test_mod ();
            localparam V = $sqrt(16);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("V")).get_real(), 4.0);
}

TEST(system_task, pow) {
    auto test_pattern = R"(
        module test_mod ();
            localparam V = $pow(2, 3);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("V")).get_real(), 8.0);
}

TEST(system_task, min_int) {
    auto test_pattern = R"(
        module test_mod ();
            localparam V = $min(5, 3, 7, 1);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("V")).get_integer(), 1);
}

TEST(system_task, max_int) {
    auto test_pattern = R"(
        module test_mod ();
            localparam V = $max(5, 3, 7, 1);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("V")).get_integer(), 7);
}

TEST(system_task, countones) {
    auto test_pattern = R"(
        module test_mod ();
            localparam V = $countones(8'b10110011);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("V")).get_integer(), 5);
}

TEST(system_task, ln_int_arg) {
    auto test_pattern = R"(
        module test_mod ();
            localparam BASE = 7;
            localparam V = $ln(BASE);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("V")).get_real(), std::log(7.0));
}

TEST(system_task, sqrt_int_arg) {
    auto test_pattern = R"(
        module test_mod ();
            localparam N = 25;
            localparam V = $sqrt(N);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("V")).get_real(), 5.0);
}

TEST(system_task, bits_sized) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [31:0] W = 32;
            parameter B = $bits(W);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("B")).get_integer(), 32);
}

TEST(system_task, bits_packed_dim) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [7:0][3:0] V = 64;
            parameter B = $bits(V);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("B")).get_integer(), 32);
}

TEST(system_task, bits_dependency) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [15:0] X = 42;
            parameter B = $bits(X);
            parameter C = B + 1;
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("B")).get_integer(), 16);
    EXPECT_EQ(defaults.at(qualified_identifier("C")).get_integer(), 17);
}

TEST(system_task, size) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [7:0] arr [3:0] = '{4{8'hFF}};
            parameter S = $size(arr);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("S")).get_integer(), 4);
}

TEST(system_task, high_low) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [7:0] arr [3:0] = '{4{8'hFF}};
            parameter H = $high(arr);
            parameter L = $low(arr);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("H")).get_integer(), 3);
    EXPECT_EQ(defaults.at(qualified_identifier("L")).get_integer(), 0);
}

TEST(system_task, left_right) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [7:0] arr [5:2] = '{4{8'hFF}};
            parameter LFT = $left(arr);
            parameter RGT = $right(arr);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("LFT")).get_integer(), 5);
    EXPECT_EQ(defaults.at(qualified_identifier("RGT")).get_integer(), 2);
}

TEST(system_task, signed) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [7:0] RAW = 8'hFF;
            parameter S = $signed(RAW);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("S")).get_integer(), -1);
}

TEST(system_task, unsigned) {
    auto test_pattern = R"(
        module test_mod ();
            parameter signed [3:0] NEG = -1;
            parameter U = $unsigned(NEG);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("U")).get_integer(), 15);
}

TEST(system_task, trig) {
    auto test_pattern = R"(
        module test_mod ();
            localparam S = $sin(0.0);
            localparam C = $cos(0.0);
            localparam T = $tan(0.0);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("S")).get_real(), 0.0);
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("C")).get_real(), 1.0);
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("T")).get_real(), 0.0);
}

TEST(system_task, exp) {
    auto test_pattern = R"(
        module test_mod ();
            localparam E = $exp(0);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("E")).get_real(), 1.0);
}

TEST(system_task, hypot) {
    auto test_pattern = R"(
        module test_mod ();
            localparam H = $hypot(3, 4);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("H")).get_real(), 5.0);
}

TEST(system_task, onehot) {
    auto test_pattern = R"(
        module test_mod ();
            localparam O1 = $onehot(8'b00010000);
            localparam O0 = $onehot(8'b00000000);
            localparam N1 = $onehot0(8'b00000000);
            localparam N2 = $onehot0(8'b00010000);
            localparam N3 = $onehot0(8'b00110000);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("O1")).get_integer(), 1);
    EXPECT_EQ(defaults.at(qualified_identifier("O0")).get_integer(), 0);
    EXPECT_EQ(defaults.at(qualified_identifier("N1")).get_integer(), 1);
    EXPECT_EQ(defaults.at(qualified_identifier("N2")).get_integer(), 1);
    EXPECT_EQ(defaults.at(qualified_identifier("N3")).get_integer(), 0);
}

TEST(system_task, isunknown) {
    auto test_pattern = R"(
        module test_mod ();
            localparam U = $isunknown(42);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("U")).get_integer(), 0);
}

TEST(system_task, hyperbolic) {
    auto test_pattern = R"(
        module test_mod ();
            localparam SH = $sinh(0.0);
            localparam CH = $cosh(0.0);
            localparam TH = $tanh(0.0);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("SH")).get_real(), 0.0);
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("CH")).get_real(), 1.0);
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("TH")).get_real(), 0.0);
}

TEST(system_task, ahyperbolic) {
    auto test_pattern = R"(
        module test_mod ();
            localparam ASH = $asinh(0.0);
            localparam ACH = $acosh(1.0);
            localparam ATH = $atanh(0.0);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("ASH")).get_real(), 0.0);
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("ACH")).get_real(), 0.0);
    EXPECT_DOUBLE_EQ(defaults.at(qualified_identifier("ATH")).get_real(), 0.0);
}

TEST(system_task, dimensions) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [7:0] arr [3:0] = '{default:0};
            localparam D = $dimensions(arr);
            localparam UD = $unpacked_dimensions(arr);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("D")).get_integer(), 2);
    EXPECT_EQ(defaults.at(qualified_identifier("UD")).get_integer(), 1);
}

TEST(system_task, dimensions_scalar) {
    auto test_pattern = R"(
        module test_mod ();
            parameter [31:0] V = 0;
            localparam D = $dimensions(V);
            localparam UD = $unpacked_dimensions(V);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("D")).get_integer(), 1);
    EXPECT_EQ(defaults.at(qualified_identifier("UD")).get_integer(), 0);
}

TEST(system_task, typename) {
    auto test_pattern = R"(
        module test_mod ();
            parameter int V = 0;
            parameter TN = $typename(V);
        endmodule
    )";
    sv_analyzer analyzer;
    auto resource = analyzer.analyze("", test_pattern).get_content()[0]->as<hdl_resource_statement>();
    auto defaults = parameter_solver::process_parameters(resource.get_parameters(), {});
    EXPECT_EQ(defaults.at(qualified_identifier("TN")).get_string(), "int");
}
