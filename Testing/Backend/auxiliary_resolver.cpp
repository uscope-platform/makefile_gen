// Copyright 2021 Filippo Savi
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

#include "data_model/data_store.hpp"
#include "Backend/Auxiliary_resolver.hpp"

class aux_resolver : public ::testing::Test {
protected:
    void SetUp() {
        d_store = std::make_shared<data_store>(true,"/tmp/test_data_store");

        Script s1_spec("python_test", "py");
        s1_spec.set_path("/tests/script.py");
        d_store->store_script(s1_spec);

        Script s2_spec("tcl_test", "tcl");
        s2_spec.set_path("/tests/tcl_test.tcl");
        d_store->store_script(s2_spec);

        Constraints c("test_constr");
        c.set_path("/test/constraints.xdc");
        d_store->store_constraint(c);
    }

    virtual void TearDown() {
    }
    std::shared_ptr<data_store> d_store;
};




TEST_F(aux_resolver, get_py_obj){
    Auxiliary_resolver res(d_store);
    Script s1("python_test", "py");
    s1.set_arguments({"arg1", "arg2", "arg3"});
    s1.set_product(true, "test.tcl");
    auto result = res.get_python_objects({s1});

    Script s1_check("python_test", "py");
    s1_check.set_path("/tests/script.py");
    s1_check.set_arguments({"arg1", "arg2", "arg3"});
    s1_check.set_product(true, "test.tcl");
    ASSERT_EQ(result[0], s1_check);
}



TEST_F(aux_resolver, get_python_path){
    Auxiliary_resolver res(d_store);
    Script s1("python_test", "py");
    s1.set_arguments({"arg1", "arg2", "arg3"});
    s1.set_product(true, "test.tcl");
    auto result = res.get_python_script_paths({s1});
    std::unordered_set<std::string> check = {"/tests/script.py"};
    ASSERT_EQ(result, check);
}



TEST_F(aux_resolver, get_tcl_script){
    Auxiliary_resolver res(d_store);
    Script s1("tcl_test", "tcl");
    s1.set_arguments({"arg1", "arg2", "arg3"});
    auto result = res.get_tcl_objects({s1});

    Script s2_check("tcl_test", "tcl");
    s2_check.set_path("/tests/tcl_test.tcl");
    s2_check.set_arguments({"arg1", "arg2", "arg3"});
    ASSERT_EQ(result[0], s2_check);
}


TEST_F(aux_resolver, get_tcl_path){
    Auxiliary_resolver res(d_store);
    Script s1("tcl_test", "tcl");
    s1.set_arguments({"arg1", "arg2", "arg3"});
    auto result = res.get_tcl_script_paths({s1});
    std::unordered_set<std::string> check = {"/tests/tcl_test.tcl"};
    ASSERT_EQ(result, check);
}



TEST_F(aux_resolver, get_constraints){
    Auxiliary_resolver res(d_store);

    Constraints c("test_constr");
    auto result = res.get_constraints({c});

    std::unordered_set<std::string> check = {"/test/constraints.xdc"};
    ASSERT_EQ(result, check);
}