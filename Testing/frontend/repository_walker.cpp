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

#include "frontend/Repository_walker.h"
#include <gtest/gtest.h>




class repository_walker : public ::testing::Test {
protected:
    void SetUp() {
        d_store = std::make_shared<data_store>(true);
        s_store = std::make_shared<settings_store>(true);
    }

    virtual void TearDown() {
    }
    std::shared_ptr<data_store> d_store;
    std::shared_ptr<settings_store> s_store;
};




TEST_F(repository_walker , directory_analysis) {
    s_store->set_setting("hdl_store", "repository_walker");
    Repository_walker walker(s_store,d_store, {"ignored_dir"});
    auto hdl_results = d_store->get_hdl_cache();
    auto script_results = d_store->get_scripts_cache();
    auto constraints_results = d_store->get_constraints_cache();
    auto data_results = d_store->get_data_cache();

    ASSERT_TRUE(hdl_results.size() == 2);
    ASSERT_TRUE(script_results.size() == 2);
    ASSERT_TRUE(data_results.size() == 1);
    ASSERT_TRUE(constraints_results.size() == 1);

    DataFile d("data", "repository_walker/data.dat");
    std::unordered_map<std::string,DataFile> data_check;
    data_check["data"] = d;
    ASSERT_EQ(data_results, data_check);

    Script s1("script_1", "tcl");
    s1.set_path("repository_walker/script_1.tcl");
    std::unordered_map<std::string,Script> script_check;
    script_check["script_1"] = s1;

    Script s2("script_2", "py");
    s2.set_path("repository_walker/script_2.py");
    script_check["script_2"] = s2;

    ASSERT_EQ(script_results, script_check);

    Constraints c("constraints");
    c.set_path("repository_walker/constraints.xdc");
    std::unordered_map<std::string,Constraints> constraints_check;
    constraints_check["constraints"] = c;
    ASSERT_EQ(constraints_results, constraints_check);


    std::unordered_map<std::string, port_direction_t> test_ports;

    test_ports["clock"] = input_port;
    test_ports["reset"] = input_port;
    test_ports["data_in"] = modport;
    test_ports["data_out"] = modport;


    HDL_Resource sv_res(module, "Decoder", "repository_walker/test_sv_module.sv", hdl_deps_t());
    sv_res.set_ports(test_ports);

    HDL_Resource vh_res(null_feature, "half_adder", "repository_walker/test_vhdl_module.vhd", hdl_deps_t());
    std::unordered_map<std::string,HDL_Resource> hdl_check;
    hdl_check["Decoder"] = sv_res;
    hdl_check["half_adder"] = vh_res;

    ASSERT_EQ(hdl_results, hdl_check);

}


TEST_F(repository_walker , file_type_handling) {

    //VERILOG
    ASSERT_TRUE(Repository_walker::file_is_verilog("test.sv"));
    ASSERT_TRUE(Repository_walker::file_is_verilog("test.svh"));
    ASSERT_TRUE(Repository_walker::file_is_verilog("test.v"));
    ASSERT_TRUE(Repository_walker::file_is_verilog("test.vh"));
    ASSERT_FALSE(Repository_walker::file_is_verilog("test.xx"));
    //VHDL
    ASSERT_TRUE(Repository_walker::file_is_vhdl("test.vhd"));
    ASSERT_FALSE(Repository_walker::file_is_vhdl("test.xx"));
    //SCRIPT
    ASSERT_TRUE(Repository_walker::file_is_script("test.tcl"));
    ASSERT_TRUE(Repository_walker::file_is_script("test.py"));
    ASSERT_FALSE(Repository_walker::file_is_script("test.xx"));
    //CONSTRAINT
    ASSERT_TRUE(Repository_walker::file_is_constraint("test.xdc"));
    ASSERT_FALSE(Repository_walker::file_is_constraint("test.xx"));
    //DATA
    ASSERT_TRUE(Repository_walker::file_is_data("test.dat"));
    ASSERT_TRUE(Repository_walker::file_is_data("test.mem"));
    ASSERT_FALSE(Repository_walker::file_is_data("test.xx"));
}
