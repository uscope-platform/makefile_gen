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

#include "frontend/analysis/sv_analyzer.hpp"
#include "frontend/analysis/vhdl_analyzer.hpp"

TEST( analysis_test , package) {

    sv_analyzer analyzer("check_files/test_package.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    ASSERT_EQ(resource.getName(), "test_package");

    std::unordered_map<std::string, HDL_parameter> parameters = resource.get_parameters();

    std::unordered_map<std::string, HDL_parameter> check_map;
    HDL_parameter p;
    p.set_name("bus_base");
    p.set_value(0x43c00000);
    check_map[p.get_name()] = p;

    p.set_name("timebase");
    p.set_value(0x43c00000);
    check_map[p.get_name()] = p;

    p.set_name("gpio");
    p.set_value(0x43c01001);
    check_map[p.get_name()] = p;

    p.set_name("scope_mux");
    p.set_value(0x43c01001);
    check_map[p.get_name()] = p;

    p.set_name("modulo_parameter");
    p.set_value(1);
    check_map[p.get_name()] = p;

    p.set_name("subtraction_parameter");
    p.set_value(2);
    check_map[p.get_name()] = p;

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
    d3.add_port_connection("clock", "clock");
    d3.add_port_connection("reset", "reset");
    d3.add_port_connection("data_in", "data_in");
    d3.add_port_connection("syndrome", "data_out");
    HDL_parameter p;
    p.set_name("TEST_PARAM");
    p.set_value("test_package::param");
    d3.add_parameter("TEST_PARAM", p);

    HDL_dependency d2("param", "test_package", package);
    HDL_dependency d1("__init_file__", "file", memory_init);
    HDL_dependency d0("if_array", "axi_lite", module);
    expression exp("if_array", {"module_parameter_2","+","1"});
    d0.add_array_quantifier(exp);
    std::vector<HDL_dependency> deps = {d0, d1, d2, d3};


    std::unordered_map<std::string, port_direction_t> test_ports;

    test_ports["clock"] = input_port;
    test_ports["reset"] = input_port;
    test_ports["data_in"] = modport;
    test_ports["data_out"] = modport;

    HDL_Resource check_res(module, "Decoder", "check_files/test_sv_module.sv");
    check_res.add_dependencies(deps);
    check_res.set_ports(test_ports);

    check_res.add_if_port_specs("data_out", "axi_stream", "master");
    check_res.add_if_port_specs("data_in", "axi_stream", "slave");


    p = HDL_parameter();
    p.set_name("module_parameter_1");
    p.set_default_value("56");
    check_res.add_parameter(p);
    p = HDL_parameter();
    p.set_name("module_parameter_2");
    p.set_value("74");
    check_res.add_parameter(p);

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

