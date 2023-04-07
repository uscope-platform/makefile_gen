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

#include "data_model/Constraints.hpp"

#include "third_party/cereal/archives/binary.hpp"

TEST( Constraints_test , get_name) {
    Constraints cnstr("test");
    ASSERT_EQ(cnstr.get_name(), "test");
}

TEST( Constraints_test , path) {
    Constraints cnstr("test");
    cnstr.set_path("test_path");
    ASSERT_EQ(cnstr.get_path(), "test_path");
}



TEST( Constraints_test , ser_des_constraints) {
    Constraints constr_out("test");
    constr_out.set_path("/test/path");

    std::stringstream os;
    {
        cereal::BinaryOutputArchive archive_out(os);
        archive_out(constr_out);
    }

    std::string json_str = os.str();
    std::stringstream is(json_str);
    Constraints constr_in;
    cereal::BinaryInputArchive archive_in(is);
    archive_in(constr_in);
    ASSERT_EQ(constr_out, constr_in);
}
