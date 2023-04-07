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
    gen.set_script_sources({"/test/script/source.sv"});
    gen.set_constraint_sources({"/test/constr/source.sv"});
    gen.set_sim_tl("sim_tl");
    gen.set_synth_tl("synth_tl");
    std::stringstream test_stream;
    gen.write_makefile(test_stream);
    auto result = test_stream.str();

    std::string check = "# Copyright 2021 University of Nottingham Ningbo China\n# Author: Filippo Savi <filssavi@gmail.com>\n# \n# Licensed under the Apache License, Version 2.0 (the \"License\");\n# you may not use this file except in compliance with the License.\n# You may obtain a copy of the License at\n#\n#      http://www.apache.org/licenses/LICENSE-2.0\n# \n# Unless required by applicable law or agreed to in writing, software\n# distributed under the License is distributed on an \"AS IS\" BASIS,\n# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n# See the License for the specific language governing permissions and\n# limitations under the License.\n\nset project_name \"proj_name\"\nset origin_dir \".\"\n\nset base_dir /test/dir\nset commons_dir  [list  /test/dir/include ]\n\n\n\nset synth_sources [list /test/synth/source.sv ]\n\nset sim_sources [list /test/sim/source.sv ]\n\nset constraints_sources [list /test/constr/source.sv ]\n\n# Create project\ncreate_project ${project_name} ./${project_name} -part xc7z020clg400-1\n\n# Set the directory path for the new project\nset proj_dir [get_property directory [current_project]]\n\nset obj [current_project]\n\n\nsource /test/script/source.sv\n\n\nadd_files -norecurse $synth_sources\n\nset_property top synth_tl [get_filesets sources_1]\n\nset_property include_dirs {$commons_dir} [get_filesets sources_1]\n\nset_property SOURCE_SET sources_1 [get_filesets sim_1]\nadd_files -fileset sim_1 -norecurse $sim_sources\n\nset_property top sim_tl [get_filesets sim_1]\n\n\n\nadd_files -fileset constrs_1 -norecurse  $constraints_sources\n\n\nupdate_compile_order";
    ASSERT_EQ(result, check);
}