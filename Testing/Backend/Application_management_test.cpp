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
#include <fstream>

#include "../includes/Backend/new_app_generator.hpp"

#ifndef TEMPLATES_FOLDER
    #define TEMPLATES_FOLDER "../templates"
#endif

bool check_file_eq(std::string a, std::string b){
    std::ifstream ss(a);
    std::string content_a((std::istreambuf_iterator<char>(ss)),std::istreambuf_iterator<char>());
    ss = std::ifstream(b);
    std::string content_b((std::istreambuf_iterator<char>(ss)), std::istreambuf_iterator<char>());
    return content_a == content_b;
}

TEST( application_management_test , create_new_application) {
    std::string app_name = "test_app";
    std::string lang = "sv";
    new_app_generator gen(app_name, lang);
    ASSERT_TRUE(std::filesystem::exists(app_name + "/tb") && std::filesystem::is_directory(app_name + "/tb"));
    ASSERT_TRUE(std::filesystem::exists(app_name + "/rtl") && std::filesystem::is_directory(app_name + "/rtl"));

    ASSERT_TRUE(check_file_eq("test_app/Depfile", "check_files/Depfile_gs"));
    ASSERT_TRUE(check_file_eq("test_app/rtl/test_app.sv", "check_files/top_synth_sv.sv"));
    ASSERT_TRUE(check_file_eq("test_app/tb/test_app_tb.sv", "check_files/top_tb_sv.sv"));
    std::string constraints_file_path = app_name +"/"+app_name+".xdc";
    ASSERT_TRUE(std::filesystem::exists(constraints_file_path) && std::filesystem::is_regular_file(constraints_file_path));

    // CLEAN UP FILES
    std::filesystem::remove_all(app_name);
}
