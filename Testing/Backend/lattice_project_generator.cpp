// Copyright 2026 Filippo Savi
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
#include "Backend/Lattice/lattice_project_generator.hpp"

std::string lpg_settings_path = "/tmp/test_lattice_settings_store";
auto lpg_settings_file = lpg_settings_path + "/settings";

std::shared_ptr<settings_store> lpg_setup_settings() {
    std::filesystem::create_directories(lpg_settings_path);
    std::ofstream ofs(lpg_settings_file);
    ofs << R"({"lattice_radiant_path":"/dev/zero","profiles": {"test_profile": {"hdl_store":"/tmp/rb"}}})";
    ofs.flush();
    ofs.close();
    std::error_code ec;
    std::filesystem::resize_file(lpg_settings_file, std::filesystem::file_size(lpg_settings_file, ec), ec);
    return std::make_shared<settings_store>(false, lpg_settings_path, "test_profile");
}

void lpg_clean_settings() {
    std::filesystem::remove_all(lpg_settings_file);
    std::filesystem::remove_all(lpg_settings_path);
}

TEST(lattice_project_gen, write_makefile_with_target_part){
    std::shared_ptr<settings_store> s_store = lpg_setup_settings();
    lattice_project_generator gen(s_store);

    project_data d;
    d.name = "test_proj";
    d.target_part = "LIFCL-40-9BG400CES";
    d.synth_tl = "top_module";
    d.synth_sources = {"/test/synth/source.sv"};
    d.constraints_sources = {"/test/constr/constraints.lpf"};
    gen.set_data(d);

    std::ostringstream result_tcl;
    gen.write_makefile(result_tcl);
    auto output = result_tcl.str();

    EXPECT_NE(output.find(R"(prj_create -name "test_proj" -impl "impl1" -dev "LIFCL-40-9BG400CES" -dir "$build_dir")"), std::string::npos);
    EXPECT_NE(output.find(R"(prj_set_impl_opt -impl "impl1" {top} {top_module})"), std::string::npos);
    EXPECT_NE(output.find(R"(prj_set_impl_opt -impl "impl1" {VerilogStandard} {System Verilog})"), std::string::npos);
    EXPECT_NE(output.find(R"(prj_add_source /test/synth/source.sv)"), std::string::npos);
    EXPECT_NE(output.find(R"(prj_add_source /test/constr/constraints.lpf)"), std::string::npos);

    EXPECT_EQ(output.find(R"(-dir "./build_dir")"), std::string::npos);
    EXPECT_EQ(output.find("\ntest_proj\""), std::string::npos);

    lpg_clean_settings();
}

TEST(lattice_project_gen, write_makefile_with_board_part){
    std::shared_ptr<settings_store> s_store = lpg_setup_settings();
    lattice_project_generator gen(s_store);

    project_data d;
    d.name = "test_proj";
    d.board_part = "SOME_BOARD";
    d.synth_tl = "top_module";
    d.synth_sources = {"/test/synth/source.sv"};
    gen.set_data(d);

    std::ostringstream result_tcl;
    gen.write_makefile(result_tcl);
    auto output = result_tcl.str();

    EXPECT_NE(output.find(R"(-dev "SOME_BOARD")"), std::string::npos);

    lpg_clean_settings();
}

TEST(lattice_project_gen, write_makefile_vhdl){
    std::shared_ptr<settings_store> s_store = lpg_setup_settings();
    lattice_project_generator gen(s_store);

    project_data d;
    d.name = "test_proj";
    d.target_part = "LIFCL-40-9BG400CES";
    d.synth_tl = "top_module";
    d.synth_sources = {"/test/synth/top.vhd"};
    gen.set_data(d);

    std::ostringstream result_tcl;
    gen.write_makefile(result_tcl);
    auto output = result_tcl.str();

    EXPECT_NE(output.find(R"(prj_set_impl_opt -impl "impl1" {VhdlStandard} {VHDL-2008})"), std::string::npos);
    EXPECT_EQ(output.find(R"({VerilogStandard})"), std::string::npos);

    lpg_clean_settings();
}

TEST(lattice_project_gen, write_makefile_no_sources){
    std::shared_ptr<settings_store> s_store = lpg_setup_settings();
    lattice_project_generator gen(s_store);

    project_data d;
    d.name = "test_proj";
    d.target_part = "LIFCL-40-9BG400CES";
    d.synth_tl = "top_module";
    gen.set_data(d);

    std::ostringstream result_tcl;
    gen.write_makefile(result_tcl);
    auto output = result_tcl.str();

    EXPECT_NE(output.find(R"(prj_create -name "test_proj" -impl "impl1" -dev "LIFCL-40-9BG400CES" -dir "$build_dir")"), std::string::npos);
    EXPECT_NE(output.find(R"(prj_save)"), std::string::npos);
    EXPECT_NE(output.find(R"(prj_close)"), std::string::npos);

    lpg_clean_settings();
}
