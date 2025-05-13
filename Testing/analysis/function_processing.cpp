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



TEST(function_processing, simple_function) {
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
    check_f.add_assignment({"CTRL_ADDR_CALC", {Expression_component("0")}, {Expression_component("100")}});
    check_f.add_assignment({"CTRL_ADDR_CALC", {Expression_component("1")}, {Expression_component("200")}});
    check_f.add_assignment({"CTRL_ADDR_CALC", {Expression_component("2")}, {Expression_component("300")}});
    EXPECT_EQ(check_f,result);

}



TEST(function_processing, simple_loop_function) {
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
    metadata.init.set_name("i");
    metadata.init.add_component(Expression_component("0"));
    metadata.init.set_type(expression_parameter);
    metadata.end_c.emplace_back("i");
    metadata.end_c.emplace_back("<");
    metadata.end_c.emplace_back("N_CORES");

    metadata.iter.emplace_back("i");
    metadata.iter.emplace_back("+");
    metadata.iter.emplace_back(1);
    assignment a = {
        "CTRL_ADDR_CALC",
        {Expression_component("i")},
        {Expression_component("100"), Expression_component("*"), Expression_component("i")}
    };

    metadata.assignments.push_back(a);
    check_f.add_loop_metadata(metadata);
    EXPECT_EQ(check_f,result);
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
    metadata.init.set_name("i");
    metadata.init.add_component(Expression_component("1"));
    metadata.init.set_type(expression_parameter);
    metadata.end_c.emplace_back("i");
    metadata.end_c.emplace_back("<");
    metadata.end_c.emplace_back("N_CORES");
    metadata.end_c.emplace_back("+");
    metadata.end_c.emplace_back("1");

    metadata.iter.emplace_back("i");
    metadata.iter.emplace_back("+");
    metadata.iter.emplace_back(1);
    assignment a = {
        "CTRL_ADDR_CALC",
        {Expression_component("i")},
        {Expression_component("100"), Expression_component("*"), Expression_component("i")}
    };

    metadata.assignments.push_back(a);
    check_f.add_loop_metadata(metadata);
    a = {
        "CTRL_ADDR_CALC",
        {Expression_component("0")},
        {Expression_component("44")}
    };
    check_f.add_assignment(a);
    a = {
        "CTRL_ADDR_CALC",
        {Expression_component("4")},
        {Expression_component("667")}
    };
    check_f.add_assignment(a);
    EXPECT_EQ(check_f,result);
}