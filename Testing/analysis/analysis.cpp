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

#include "analysis/sv_analyzer.h"
#include "analysis/vhdl_analyzer.h"

TEST( analysis_test , package) {

    sv_analyzer analyzer("check_files/test_package.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    ASSERT_EQ(resource.getName(), "test_package");

    std::unordered_map<std::string, uint32_t> parameters = resource.get_parameters();

    std::unordered_map<std::string, uint32_t> check_map;
    check_map["bus_base"] = 0x43c00000;
    check_map["timebase"] = 0x43c00000;
    check_map["gpio"] = 0x43c01001;
    check_map["scope_mux"] = 0x43c01001;
    check_map["modulo_parameter"] = 1;
    check_map["subtraction_parameter"] = 2;
    ASSERT_EQ(check_map, parameters);

    HDL_Resource check_res(package, "test_package", "check_files/test_package.sv", hdl_deps_t(), verilog_entity);
    check_res.set_parameters(check_map);


    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>(std::vector<std::string>(), "bus_base");
    xbar->set_base_address(0x43c00000);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("general_ctrls", "gpio", "gpio");
    mod->set_base_address(1136660481);
    xbar->add_child(mod);

    std::shared_ptr<bus_crossbar> xbar2 = std::make_shared<bus_crossbar>(std::vector<std::string>(), "timebase");
    xbar2->set_base_address(1136656384);
    xbar->add_child(xbar2);

    std::vector<std::shared_ptr<bus_crossbar>> bus_roots({xbar});
    check_res.add_bus_roots(bus_roots);
    ASSERT_EQ(resource, check_res);
}

TEST( analysis_test , sv_module) {

    sv_analyzer analyzer("check_files/test_sv_module.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    hdl_deps_t check_dep;
    check_dep["SyndromeCalculator"] = module;
    check_dep["test_package"] = package;
    check_dep["file"] = memory_init;
    HDL_Resource check_res(module, "Decoder", "check_files/test_sv_module.sv", check_dep, verilog_entity);
    ASSERT_EQ(resource, check_res);
    resource = analyzer.analyze()[1];
    hdl_deps_t dummy;
    check_res = HDL_Resource(interface, "test_if", "check_files/test_sv_module.sv", dummy, verilog_entity);
    ASSERT_EQ(resource, check_res);
}

TEST( analysis_test , vhdl_module) {

    vhdl_analyzer analyzer("check_files/test_vhdl_module.vhd");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    hdl_deps_t check_dep;
    check_dep["ANDGATE"] = module;
    HDL_Resource check_res (null_feature, "half_adder", "check_files/test_vhdl_module.vhd", check_dep, vhdl_entity);
    ASSERT_EQ(resource, check_res);
}

