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

#include "../../includes/frontend/analysis/preprocessor/sv_preprocessor.hpp"


TEST(preprocessor, file_directive) {
    auto test_pattern = std::istringstream(R"(
        module test_module ();
            parameter string FILENAME = `__FILE__;
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    std::ostringstream oss;
    auto result = preproc.preprocess(test_pattern);
    auto check_string =R"(
        module test_module ();
            parameter string FILENAME = "/tmp/file.sv";
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}

TEST(preprocessor, line_directive) {
    auto test_pattern = std::istringstream(
    R"(module test_module ();

            parameter LINE_NUMBER = `__LINE__;
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    std::ostringstream oss;
    auto result = preproc.preprocess(test_pattern);
    auto check_string =
        R"(module test_module ();

            parameter LINE_NUMBER = 3;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}


TEST(preprocessor, empty_define) {
    auto test_pattern = std::istringstream(R"(
        `define  a
        module test_module ();
            parameter TEST_PARAM = `a;
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
        module test_module ();
            parameter TEST_PARAM = ;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}


TEST(preprocessor, simple_define) {
    auto test_pattern = std::istringstream(R"(
        `define  a  12
        module test_module ();
            parameter TEST_PARAM = `a;
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
        module test_module ();
            parameter TEST_PARAM = 12;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}

TEST(preprocessor, simple_define_with_tabs) {
    auto test_pattern = std::istringstream(R"(
        `define  a	 	 12
        module test_module ();
            parameter TEST_PARAM = `a;
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
        module test_module ();
            parameter TEST_PARAM = 12;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}


TEST(preprocessor, multiple_defines) {
    auto test_pattern = std::istringstream(R"(
        `define a 12
        `define b 15
        module test_module ();
            parameter TEST_PARAM = `a + `b;
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
        module test_module ();
            parameter TEST_PARAM = 12 + 15;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}



TEST(preprocessor, undef) {
    auto test_pattern = std::istringstream(R"(
        `define  a  12
        `undef   a
        module test_module ();
            parameter TEST_PARAM = `a;
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    EXPECT_THROW(preproc.preprocess(test_pattern), std::runtime_error);
}


TEST(preprocessor, invalid_continuation) {
    auto test_pattern = R"(
        // This is a comment \
           that should stay a comment!
        wire a;
    )";

    sv_preprocessor preproc("/tmp/file.sv");
    auto res = preproc.flatten_source(test_pattern);
    auto check_string = R"(
        // This is a comment \
           that should stay a comment!
        wire a;
    )";
    EXPECT_EQ(check_string, res);
}


TEST(preprocessor, string_continuation) {
    auto test_pattern = R"(
module test;
parameter string ML_STRING = "TEST \
  parameter";
endmodule
    )";

    sv_preprocessor preproc("/tmp/file.sv");
    auto res = preproc.flatten_source(test_pattern);
    auto check_string = R"(
module test;
parameter string ML_STRING = "TEST   parameter";
endmodule
    )";
    EXPECT_EQ(check_string, res);
}


TEST(preprocessor, macro_continuation) {
    auto test_pattern = R"(
module test;
`define SUM(a,b) a + \
b
endmodule
    )";

    sv_preprocessor preproc("/tmp/file.sv");
    auto res = preproc.flatten_source(test_pattern);
    auto check_string = R"(
module test;
`define SUM(a,b) a + b
endmodule
    )";
    EXPECT_EQ(check_string, res);
}


TEST(preprocessor, multiline_macro_continuation) {
    auto test_pattern = R"(
module test;
`define SUM(a,b) a \
+ \
b
endmodule
    )";

    sv_preprocessor preproc("/tmp/file.sv");
    auto res = preproc.flatten_source(test_pattern);
    auto check_string = R"(
module test;
`define SUM(a,b) a + b
endmodule
    )";
    EXPECT_EQ(check_string, res);
}

TEST(preprocessor, ifdef_false) {
    auto test_pattern = std::istringstream(R"(
module test;
`ifdef A
    parameter TEST_PARAM = 3;
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, ifdef_true) {
    auto test_pattern = std::istringstream(R"(
`define A
module test;
`ifdef A
    parameter TEST_PARAM = 3;
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
    parameter TEST_PARAM = 3;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}



TEST(preprocessor, ifndef_true) {
    auto test_pattern = std::istringstream(R"(
module test;
`ifndef A
    parameter TEST_PARAM = 3;
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
    parameter TEST_PARAM = 3;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, ifndef_false) {
    auto test_pattern = std::istringstream(R"(
`define A
module test;
`ifndef A
    parameter TEST_PARAM = 3;
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, ifdef_else) {
    auto test_pattern = std::istringstream(R"(
module test;
`ifdef A
    parameter TEST_PARAM = 3;
`else
    parameter TEST_PARAM = 5;
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
    parameter TEST_PARAM = 5;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}



TEST(preprocessor, ifdef_elseif_taken) {
    auto test_pattern = std::istringstream(R"(
`define B
module test;
`ifdef A
    parameter TEST_PARAM = 3;
`elsif B
    parameter TEST_PARAM = 5;
`else
    parameter TEST_PARAM = 7;
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
    parameter TEST_PARAM = 5;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, ifdef_elseif_shadowed) {
    auto test_pattern = std::istringstream(R"(
`define A
`define B
module test;
`ifdef A
    parameter TEST_PARAM = 3;
`elsif B
    parameter TEST_PARAM = 5;
`else
    parameter TEST_PARAM = 7;
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
    parameter TEST_PARAM = 3;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, nested_ifdefs_skipped) {
    auto test_pattern = std::istringstream(R"(
module test;
`define B
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, nested_ifdef_else_skipped) {
    auto test_pattern = std::istringstream(R"(
module test;
`define B
`define C
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `elsif C
        parameter TEST_PARAM = 5;
    `else
        parameter TEST_PARAM = 7;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, nested_ifdefs_outer_taken) {
    auto test_pattern = std::istringstream(R"(
module test;
`define A
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, nested_ifdefs_fully_taken) {
    auto test_pattern = std::istringstream(R"(
module test;
`define A
`define B
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
        parameter TEST_PARAM = 3;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}



TEST(preprocessor, nested_ifdefs_fully_taken_repeat) {
    auto test_pattern = std::istringstream(R"(
module test;
`define A
`define B
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `endif
    `ifdef C
        parameter TEST_PARAM2 = 7;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
        parameter TEST_PARAM = 3;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, nested_elsif_taken) {
    auto test_pattern = std::istringstream(R"(
module test;
`define C
`define A
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `elsif C
        parameter TEST_PARAM = 5;
    `else
        parameter TEST_PARAM = 7;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
        parameter TEST_PARAM = 5;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, nested_else_taken) {
    auto test_pattern = std::istringstream(R"(
module test;
`define A
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `elsif C
        parameter TEST_PARAM = 5;
    `else
        parameter TEST_PARAM = 7;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
        parameter TEST_PARAM = 7;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, nested_else_taken_with_outer_elseif) {
    auto test_pattern = std::istringstream(R"(
module test;
`define A
`define D
`define E
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `elsif C
        parameter TEST_PARAM = 5;
    `else
        parameter TEST_PARAM = 7;
    `endif
`else
    `ifdef D
        parameter TEST_PARAM = 9;
    `elsif E
        parameter TEST_PARAM = 11;
    `else
        parameter TEST_PARAM = 15;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
        parameter TEST_PARAM = 7;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, nested_else_taken_with_outer_else) {
    auto test_pattern = std::istringstream(R"(
module test;
`define A
`define E
`ifdef A
    `ifdef B
        parameter TEST_PARAM = 3;
    `elsif C
        parameter TEST_PARAM = 5;
    `else
        parameter TEST_PARAM = 7;
    `endif
`else
    `ifdef D
        parameter TEST_PARAM = 9;
    `elsif E
        parameter TEST_PARAM = 11;
    `else
        parameter TEST_PARAM = 15;
    `endif
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
module test;
        parameter TEST_PARAM = 7;
endmodule
    )";
    EXPECT_EQ(check_string, result);
}


TEST(preprocessor, triple_nested_ifdef) {
    auto test_pattern = std::istringstream(R"(
`define LEVEL_1
`define LEVEL_3
module test;
`ifdef LEVEL_1
    parameter L1 = 1;
    `ifdef LEVEL_2
        parameter L2 = 1;
        `ifdef LEVEL_3
            parameter L3_FAIL = 1;
        `endif
    `else
        parameter L2_ELSE = 1;
        `ifdef LEVEL_3
            parameter L3_SUCCESS = 1;
        `endif
    `endif
`else
    parameter L1_FAIL = 1;
`endif
endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");
    auto result = preproc.preprocess(test_pattern);

    auto check_string = R"(
module test;
    parameter L1 = 1;
        parameter L2_ELSE = 1;
            parameter L3_SUCCESS = 1;
endmodule
    )";

    EXPECT_EQ(result, check_string);
}


TEST(preprocessor, simple_macro_with_args) {
    auto test_pattern = std::istringstream(R"(
        `define  ADD(a, b)  a+b
        module test_module ();
            parameter TEST_PARAM = `ADD(5,7);
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
        module test_module ();
            parameter TEST_PARAM = 5+7;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}





TEST(preprocessor, simple_macro_with_default_args) {
    auto test_pattern = std::istringstream(R"(
        `define  ADD(a=5, b=7)  a+b
        module test_module ();
            parameter TEST_PARAM = `ADD(,);
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
        module test_module ();
            parameter TEST_PARAM = 5+7;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}

TEST(preprocessor, simple_macro_with_default_args_overriden) {
    auto test_pattern = std::istringstream(R"(
        `define  ADD(a=5, b=7)  a+b
        module test_module ();
            parameter TEST_PARAM = `ADD(,3);
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
        module test_module ();
            parameter TEST_PARAM = 5+3;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}


TEST(preprocessor, multiple_macros) {
    auto test_pattern = std::istringstream(R"(
        `define  ADD(a=5, b=7)  a+b
        module test_module ();
            parameter TEST_PARAM = `ADD(,3) * `ADD(7,);
        endmodule
    )");

    sv_preprocessor preproc("/tmp/file.sv");

    auto result = preproc.preprocess(test_pattern);
    auto check_string = R"(
        module test_module ();
            parameter TEST_PARAM = 5+3 * 7+7;
        endmodule
    )";
    EXPECT_EQ(result, check_string);
}