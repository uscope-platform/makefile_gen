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


TEST(preprocessor, nested_ifdefs) {
    auto test_pattern = std::istringstream(R"(
module test;
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