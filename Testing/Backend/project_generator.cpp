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
#include "Backend/Xilinx/xilinx_project_generator.hpp"


TEST(xilinx_project_gen, gen){
    xilinx_project_generator gen;

    gen.set_project_name("proj_name");

    gen.set_directories("/test/dir", {"include"});
    gen.set_synth_sources({"/test/synth/source.sv"});
    gen.set_sim_sources({"/test/sim/source.sv"});
    gen.set_script_sources({{"/test/script/source.sv", {}}});
    gen.set_constraint_sources({"/test/constr/source.sv"});
    gen.set_sim_tl("sim_tl");
    gen.set_synth_tl("synth_tl");
    std::stringstream test_stream;
    gen.write_makefile(test_stream);
    auto result = test_stream.str();

    std::string check = "set project_name \"proj_name\"\nset origin_dir \".\"\nset base_dir /test/dir\nset commons_dir [list \"/test/dir/include\" ]\nset synth_sources [list \"/test/synth/source.sv\" ]\nset sim_sources [list \"/test/sim/source.sv\" ]\nset constraints_sources [list \"/test/constr/source.sv\" ]\n# Create project\ncreate_project ${project_name} ./${project_name}\nset_property part xc7z020clg400-1 [current_project]\n# Set the directory path for the new project\nset proj_dir [get_property directory [current_project]]\nset obj [current_project]\nsource /test/script/source.sv\nadd_files -norecurse $synth_sources\nset_property top synth_tl [get_filesets sources_1]\nset_property include_dirs $commons_dir [get_filesets sources_1]\nset_property SOURCE_SET sources_1 [get_filesets sim_1]\nadd_files -fileset sim_1 -norecurse $sim_sources\nset_property top sim_tl [get_filesets sim_1]\nadd_files -fileset constrs_1 -norecurse  $constraints_sources\nupdate_compile_order\n";
    ASSERT_EQ(result, check);
}