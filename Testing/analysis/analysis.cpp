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

    HDL_Resource check_res(package, "test_package", "check_files/test_package.sv");
    check_res.set_parameters(check_map);

    std::shared_ptr<bus_crossbar> root = std::make_shared<bus_crossbar>();
    root->set_parameter("bus_base");
    root->set_target("test_package");
    root->set_base_address(0x43c00000);

    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>();
    xbar->set_parameter("timebase");
    xbar->set_base_address(1136656384);
    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("SicDriveMasterScope","SicDriveMasterScope");
    mod->set_base_address(0x43c01001);
    xbar->add_child(mod);
    root->add_child(xbar);



    std::shared_ptr<bus_module> mod2 = std::make_shared<bus_module>("general_ctrls", "gpio");
    mod2->set_base_address(0x43c01001);
    root->add_child(mod2);

    std::shared_ptr<bus_module> mod3 = std::make_shared<bus_module>("SicDriveMasterScope","SicDriveMasterScope");
    mod3->set_base_address(1);
    root->add_child(mod3);

    std::shared_ptr<bus_module> mod4 = std::make_shared<bus_module>("SicDriveMasterScope","SicDriveMasterScope");
    mod4->set_base_address(2);
    root->add_child(mod4);


    std::vector<std::shared_ptr<bus_crossbar>> bus_roots({root});
    check_res.add_bus_roots(bus_roots);
    ASSERT_EQ(resource, check_res);
}

TEST( analysis_test , sv_module) {

    sv_analyzer analyzer("check_files/test_sv_module.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    HDL_dependency d3("SC", "SyndromeCalculator", module);
    HDL_dependency d2("param", "test_package", package);
    HDL_dependency d1("__init_file__", "file", memory_init);
    std::vector<HDL_dependency> deps = {d1, d2, d3};


    std::unordered_map<std::string, port_direction_t> test_ports;

    test_ports["clock"] = input_port;
    test_ports["reset"] = input_port;
    test_ports["data_in"] = modport;
    test_ports["data_out"] = modport;

    HDL_Resource check_res(module, "Decoder", "check_files/test_sv_module.sv");
    check_res.add_dependencies(deps);
    check_res.set_ports(test_ports);
    ASSERT_EQ(resource, check_res);
    resource = analyzer.analyze()[1];
    check_res = HDL_Resource(interface, "test_if", "check_files/test_sv_module.sv");
    ASSERT_EQ(resource, check_res);
}

TEST( analysis_test , vhdl_module) {

    vhdl_analyzer analyzer("check_files/test_vhdl_module.vhd");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    HDL_dependency dep("and_component", "ANDGATE", module);
    HDL_Resource check_res (module, "half_adder", "check_files/test_vhdl_module.vhd");
    check_res.add_dependency(dep);
    ASSERT_EQ(resource, check_res);
}

