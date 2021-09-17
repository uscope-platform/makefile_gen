// Copyright 2021 University of Nottingham Ningbo China
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <gtest/gtest.h>

#include "data_model/Constraints.h"



TEST( Constraints_test , get_name) {
    Constraints cnstr("test");
    ASSERT_EQ(cnstr.get_name(), "test");
}

TEST( Constraints_test , path) {
    Constraints cnstr("test");
    cnstr.set_path("test_path");
    ASSERT_EQ(cnstr.get_path(), "test_path");
}

TEST( Constraints_test , serialization) {
    Constraints cnstr("test");
    cnstr.set_path("test_path");
    std::string result = cnstr;
    ASSERT_EQ(result, "test,test_path");
}

TEST( Constraints_test , deserialization) {
    Constraints cnstr("test,test_path", true);
    Constraints result("test");
    result.set_path("test_path");
    ASSERT_EQ(cnstr, result);
}