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

#include "frontend/analysis/sv_preprocessor.hpp"


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

TEST(preprocessor, simple_define) {
    auto test_pattern = std::istringstream(R"(
        `define a 12
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

