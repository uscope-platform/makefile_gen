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
#include <filesystem>

#include "Backend/python_script_runner.h"

TEST(python_script_runner, run_script){

    Script s("python_test", "py");
    s.set_path("check_files/python_test.py");
    s.set_arguments({"test_file.tcl"});
    s.set_product(true, "tcl");
    std::vector<Script> script_vect = {s};

    python_script_runner runner;
    runner.run_python_scripts(script_vect);
    bool script_has_run = std::filesystem::exists("check_files/test_file.tcl");
    ASSERT_TRUE(script_has_run);
    std::filesystem::remove("check_files/test_file.tcl");
    auto tcl_dep = runner.get_script_dependencies();
    std::set<std::string> check_deps = {"check_files/test_file.tcl"};

    ASSERT_EQ(tcl_dep, check_deps);
}
