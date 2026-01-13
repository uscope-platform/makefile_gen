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

#include "frontend/analysis/sv_analyzer.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"


TEST(function_processing, simple_function_scalar) {
    std::string test_pattern = R"(
        module test_mod #(
        )();

            function integer CTRL_ADDR_CALC();
                CTRL_ADDR_CALC = 67;
            endfunction
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto functions = resource.get_functions();

    EXPECT_EQ(functions.size(), 1);
    EXPECT_TRUE(functions.contains("CTRL_ADDR_CALC"));
    auto result = functions["CTRL_ADDR_CALC"];
    HDL_function check_f;
    check_f.set_name("CTRL_ADDR_CALC");
    assignment a;
    a.name = "CTRL_ADDR_CALC";
    a.index = {};
    a.value = {Expression_component("67", Expression_component::number)};
    check_f.add_assignment(a);
    EXPECT_EQ(check_f,result);

    auto values = result.evaluate(false);
    ASSERT_TRUE(values.has_value());
    EXPECT_TRUE(std::holds_alternative<int64_t>(values.value()));
    auto result_value = std::get<int64_t>(values.value());
    EXPECT_EQ(result_value, 67);
}


TEST(function_processing, simple_function_array) {
    std::string test_pattern = R"(
        module test_mod #(
        )();

            function integer CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = 100;
                CTRL_ADDR_CALC[1] = 200;
                CTRL_ADDR_CALC[2] = 300;
                IGNORED_ASSIGNMENT[2] = 1;
            endfunction
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto functions = resource.get_functions();

    EXPECT_EQ(functions.size(), 1);
    EXPECT_TRUE(functions.contains("CTRL_ADDR_CALC"));
    auto result = functions["CTRL_ADDR_CALC"];
    HDL_function check_f;
    check_f.set_name("CTRL_ADDR_CALC");
    assignment a;
    a.name = "CTRL_ADDR_CALC";
    a.index = {Expression_component("0", Expression_component::number)};
    a.value = {Expression_component("100", Expression_component::number)};
    check_f.add_assignment(a);
    a.index.value().components[0] = Expression_component("1", Expression_component::number);
    a.value.components[0] = Expression_component("200", Expression_component::number);
    check_f.add_assignment(a);
    a.index.value().components[0] = Expression_component("2", Expression_component::number);
    a.value.components[0] = Expression_component("300", Expression_component::number);
    check_f.add_assignment(a);
    EXPECT_EQ(check_f,result);

    mdarray<int64_t> check_val;
    check_val.set_1d_slice({0,0}, {100,200,300});
    auto values = result.evaluate(false);
    ASSERT_TRUE(values.has_value());
    EXPECT_TRUE(std::holds_alternative<mdarray<int64_t>>(values.value()));
    auto result_value = std::get<mdarray<int64_t>>(values.value());
    EXPECT_EQ(result_value, check_val);
}



TEST(function_processing, simple_loop_function) {
    std::string test_pattern = R"(
        module test_mod #(
            N_CORES = 3
        )();

            function logic [31:0] CTRL_ADDR_CALC();
                for(int i = 0; i<3; i++)begin
                    CTRL_ADDR_CALC[i] = 100*i;
                end
            endfunction
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto functions = resource.get_functions();

    EXPECT_EQ(functions.size(), 1);
    EXPECT_TRUE(functions.contains("CTRL_ADDR_CALC"));
    auto result = functions["CTRL_ADDR_CALC"];

    HDL_function check_f;
    check_f.set_name("CTRL_ADDR_CALC");
    auto metadata = HDL_loop_metadata();

    HDL_parameter p;
    p.set_name("i");
    p.add_component(Expression_component("0", Expression_component::number));
    p.set_type(HDL_parameter::expression_parameter);
    metadata.set_init(p);
    metadata.set_end_c({
        Expression_component("i", Expression_component::identifier),
        Expression_component("<", Expression_component::operation),
        Expression_component("3", Expression_component::number)
        });

    metadata.set_iter({
        Expression_component("i", Expression_component::identifier),
        Expression_component("+", Expression_component::operation),
        Expression_component("1", Expression_component::number)});

    assignment a = {
        "CTRL_ADDR_CALC",
        Expression({Expression_component("i", Expression_component::identifier)}),
        {Expression_component("100", Expression_component::number), Expression_component("*", Expression_component::operation), Expression_component("i", Expression_component::identifier)}
    };

    metadata.add_assignment(a);
    check_f.add_loop_metadata(metadata);
     EXPECT_EQ(check_f,result);

    mdarray<int64_t> check_val;
    check_val.set_1d_slice({0,0}, {0, 100,200});
    auto values = result.evaluate(false);
    ASSERT_TRUE(values.has_value());
    EXPECT_TRUE(std::holds_alternative<mdarray<int64_t>>(values.value()));
    auto result_value = std::get<mdarray<int64_t>>(values.value());
    EXPECT_EQ(result_value, check_val);
}


TEST(function_processing, parametric_loop_function) {
    std::string test_pattern = R"(
        module test_mod #(
            N_CORES = 3
        )();

            function logic [31:0] CTRL_ADDR_CALC();
                for(int i = 0; i<N_CORES; i++)begin
                    CTRL_ADDR_CALC[i] = 100*i;
                end
            endfunction
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto functions = resource.get_functions();

    EXPECT_EQ(functions.size(), 1);
    EXPECT_TRUE(functions.contains("CTRL_ADDR_CALC"));
    auto result = functions["CTRL_ADDR_CALC"];

    HDL_function check_f;
    check_f.set_name("CTRL_ADDR_CALC");
    auto metadata = HDL_loop_metadata();

    HDL_parameter p;
    p.set_name("i");
    p.add_component(Expression_component("0", Expression_component::number));
    p.set_type(HDL_parameter::expression_parameter);
    metadata.set_init(p);
    metadata.set_end_c({
        Expression_component("i", Expression_component::identifier),
        Expression_component("<", Expression_component::operation),
        Expression_component("N_CORES", Expression_component::identifier)
        });

    metadata.set_iter({
        Expression_component("i", Expression_component::identifier),
        Expression_component("+", Expression_component::operation),
        Expression_component("1", Expression_component::number)});

    assignment a = {
        "CTRL_ADDR_CALC",
        Expression({Expression_component("i", Expression_component::identifier)}),
        {Expression_component("100", Expression_component::number), Expression_component("*", Expression_component::operation), Expression_component("i", Expression_component::identifier)}
    };

    metadata.add_assignment(a);
    check_f.add_loop_metadata(metadata);
    EXPECT_EQ(check_f,result);

    mdarray<int64_t> check_val;
    check_val.set_1d_slice({0,0}, {0,100,200});
    auto res= result.propagate_constant("N_CORES", 3);
    auto values = result.evaluate(false);
    ASSERT_TRUE(values.has_value());
    EXPECT_TRUE(std::holds_alternative<mdarray<int64_t>>(values.value()));
    auto result_value = std::get<mdarray<int64_t>>(values.value());
    EXPECT_EQ(result_value, check_val);
}

TEST(function_processing, complex_loop_function) {
    std::string test_pattern = R"(
        module test_mod #(
            N_CORES = 3
        )();

            function logic [31:0] CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = 44;
                for(int i = 1; i<N_CORES+1; i++)begin
                    CTRL_ADDR_CALC[i] = 100*i;
                end
                CTRL_ADDR_CALC[4] = 667;
            endfunction
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto functions = resource.get_functions();

    EXPECT_EQ(functions.size(), 1);
    EXPECT_TRUE(functions.contains("CTRL_ADDR_CALC"));
    auto result = functions["CTRL_ADDR_CALC"];

    HDL_function check_f;
    check_f.set_name("CTRL_ADDR_CALC");
    auto metadata = HDL_loop_metadata();

    HDL_parameter p;
    p.set_name("i");
    p.add_component(Expression_component("1", Expression_component::number));
    p.set_type(HDL_parameter::expression_parameter);
    metadata.set_init(p);
    metadata.set_end_c({
                Expression_component("i", Expression_component::identifier),
               Expression_component("<", Expression_component::operation),
               Expression_component("N_CORES", Expression_component::identifier),
               Expression_component("+", Expression_component::operation),
               Expression_component("1", Expression_component::number)
    });

    metadata.set_iter({
            Expression_component("i", Expression_component::identifier),
            Expression_component("+", Expression_component::operation),
            Expression_component("1", Expression_component::number)
        });

    assignment a = {
        "CTRL_ADDR_CALC",
        Expression({Expression_component("i", Expression_component::identifier)}),
        {Expression_component("100", Expression_component::number), Expression_component("*", Expression_component::operation), Expression_component("i", Expression_component::identifier)}
    };

    metadata.add_assignment(a);
    check_f.add_loop_metadata(metadata);
    a = {
        "CTRL_ADDR_CALC",
        Expression({Expression_component("0", Expression_component::number)}),
        {Expression_component("44", Expression_component::number)}
    };
    check_f.add_assignment(a);
    a = {
        "CTRL_ADDR_CALC",
        Expression({Expression_component("4", Expression_component::number)}),
        {Expression_component("667", Expression_component::number)}
    };
    check_f.add_assignment(a);
    EXPECT_EQ(check_f,result);

    mdarray<int64_t> check_val;
    check_val.set_1d_slice({0,0}, {44, 100,200,300, 667});
    result.propagate_constant("N_CORES", 3);
    auto values = result.evaluate(false);
    ASSERT_TRUE(values.has_value());
    EXPECT_TRUE(std::holds_alternative<mdarray<int64_t>>(values.value()));
    auto result_value = std::get<mdarray<int64_t>>(values.value());
    EXPECT_EQ(result_value, check_val);
}


TEST(function_processing, parametrized_function) {
    std::string test_pattern = R"(
        module test_mod #(
            N_CORES = 1
        )();

            function logic [31:0] CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = 44;
                CTRL_ADDR_CALC[N_CORES] = 33;
            endfunction
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto functions = resource.get_functions();

    EXPECT_EQ(functions.size(), 1);
    EXPECT_TRUE(functions.contains("CTRL_ADDR_CALC"));
    auto result = functions["CTRL_ADDR_CALC"];

    HDL_function check_f;
    check_f.set_name("CTRL_ADDR_CALC");

    assignment a = {
        "CTRL_ADDR_CALC",
        Expression({Expression_component("0", Expression_component::number)}),
        {Expression_component("44", Expression_component::number)}
    };
    check_f.add_assignment(a);
    a = {
        "CTRL_ADDR_CALC",
        Expression({Expression_component("N_CORES", Expression_component::identifier)}),
        {Expression_component("33", Expression_component::number)}
    };
    check_f.add_assignment(a);
    EXPECT_EQ(check_f,result);

    mdarray<int64_t> check_val;
    check_val.set_1d_slice({0,0}, {44, 33});
    result.propagate_constant("N_CORES", 1);
    auto values = result.evaluate(false);
    ASSERT_TRUE(values.has_value());
    EXPECT_TRUE(std::holds_alternative<mdarray<int64_t>>(values.value()));
    auto result_value = std::get<mdarray<int64_t>>(values.value());
    EXPECT_EQ(result_value, check_val);
}


TEST(function_processing, package_assignment) {
    std::string test_pattern = R"(

        module test_mod ();


        function logic[31:0] CTRL_ADDR_CALC();
            CTRL_ADDR_CALC[0] = hil_address_space::bus_base;
        endfunction

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto functions = resource.get_functions();

    EXPECT_EQ(functions.size(), 1);
    EXPECT_TRUE(functions.contains("CTRL_ADDR_CALC"));
    auto result = functions["CTRL_ADDR_CALC"];


    HDL_function check_f;
    check_f.set_name("CTRL_ADDR_CALC");

    assignment a = {
        "CTRL_ADDR_CALC",
        Expression({Expression_component("0", Expression_component::number)}),
        {Expression_component("bus_base", Expression_component::identifier)}
    };
    a.value.components[0].set_package_prefix("hil_address_space");
    check_f.add_assignment(a);

    EXPECT_EQ(check_f,result);

    mdarray<int64_t> check_val;
    check_val.set_1d_slice({0,0}, {100,200,300});
    auto values = result.evaluate(false);
    ASSERT_TRUE(values.has_value());
    ASSERT_TRUE(std::holds_alternative<mdarray<int64_t>>(values.value()));
    auto result_value = std::get<mdarray<int64_t>>(values.value());
    EXPECT_EQ(result_value, check_val);
}



