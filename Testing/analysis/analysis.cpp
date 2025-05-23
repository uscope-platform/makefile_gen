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
#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"

TEST( analysis_test , package) {

    sv_analyzer analyzer("check_files/test_package.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameters_map parameters = resource.get_parameters();

    Parameters_map check_map;

    auto p = std::make_shared<HDL_parameter>();
    p->set_name("bus_base");
    p->set_expression_components({Expression_component("32'h43c00000")});
    p->set_type(HDL_parameter::expression_parameter);
    check_map.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("timebase");
    p->set_expression_components({ Expression_component("bus_base")});
    p->set_type(HDL_parameter::expression_parameter);
    check_map.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("gpio");
    p->set_expression_components({
        Expression_component("timebase"), Expression_component("+"),
        Expression_component("32'h1000"), Expression_component("*"),
        Expression_component("2"), Expression_component("/"),
        Expression_component("2"), Expression_component("+"),
        Expression_component("1"),

    });
    p->set_type(HDL_parameter::expression_parameter);
    check_map.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("scope_mux");
    p->set_expression_components({ Expression_component("gpio")});
    p->set_type(HDL_parameter::expression_parameter);
    check_map.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("out_of_order");
    p->set_expression_components({ Expression_component("scope_mux")});
    p->set_type(HDL_parameter::expression_parameter);
    check_map.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("modulo_parameter");
    p->set_expression_components({
        Expression_component("3"),Expression_component("%"),Expression_component("2")
    });
    p->set_type(HDL_parameter::expression_parameter);
    check_map.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("subtraction_parameter");
    p->set_expression_components({
        Expression_component("'o4"),Expression_component("-"),Expression_component("'b10")
    });
    p->set_type(HDL_parameter::expression_parameter);
    check_map.insert(p);

    ASSERT_EQ(check_map, parameters);

}

TEST( analysis_test , sv_module) {

    sv_analyzer analyzer("check_files/test_sv_module.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    HDL_instance d3("SC", "SyndromeCalculator", module);
    d3.add_port_connection("clock", {HDL_net("clock")});
    d3.add_port_connection("reset", {HDL_net("reset")});
    d3.add_port_connection("data_in", {HDL_net("data_in")});
    d3.add_port_connection("syndrome", {HDL_net("data_out")});
    auto p = std::make_shared<HDL_parameter>();
    p->set_name("TEST_PARAM");
    Expression_component e("param");
    e.set_package_prefix("test_package");
    p->set_expression_components({e});
    p->set_type(HDL_parameter::expression_parameter);
    d3.add_parameter(p);

    HDL_instance d2("param", "test_package", package);
    HDL_instance d1("__init_file__", "file", memory_init);
    HDL_instance d0("if_array", "axi_lite", module);
    p = std::make_shared<HDL_parameter>();
    p->set_name("instance_array_qualifier");
    p->set_expression_components({Expression_component("module_parameter_2"),Expression_component("+"),Expression_component("1")});
    p->set_type(HDL_parameter::expression_parameter);
    d0.add_array_quantifier(p);
    std::vector<HDL_instance> deps = {d0, d1, d2, d3};


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


    p = std::make_shared<HDL_parameter>();
    p->set_name("module_parameter_1");
    p->add_component(Expression_component("56"));
    p->set_type(HDL_parameter::expression_parameter);
    check_res.add_parameter(p);


    p = std::make_shared<HDL_parameter>();
    p->set_name("module_parameter_2");
    p->add_component(Expression_component("74"));
    p->set_type(HDL_parameter::expression_parameter);
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
    HDL_instance dep("and_component", "ANDGATE", module);
    HDL_Resource check_res (module, "half_adder", "check_files/test_vhdl_module.vhd");
    check_res.add_dependency(dep);
    ASSERT_EQ(resource, check_res);
}


TEST(analysis_test, port_concat_assignment) {
    std::string test_pattern = R"(
    module test_mod ();


        axil_crossbar_interface  axi_xbar (
            .clock(clock),
            .slaves('{axi_in}),
            .masters('{timebase_axi, gpio_axi, fcore_axi})
        );


    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    auto dep = resource.get_dependencies()[0];

    HDL_instance check_dependency;
    check_dependency.set_type("axil_crossbar_interface");
    check_dependency.set_name("axi_xbar");
    check_dependency.set_dependency_class(module);
    check_dependency.add_port_connection("clock", {HDL_net("clock")});
    check_dependency.add_port_connection("slaves", {HDL_net("axi_in")});
    check_dependency.add_port_connection("masters", {HDL_net("timebase_axi"), HDL_net("gpio_axi"), HDL_net("fcore_axi")});

    ASSERT_EQ(dep, check_dependency);
}


TEST(analysis_test, interfaces_array) {
    std::string test_pattern = R"(
    module test_mod ();

        axi_lite  cores_control[3]();

    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    auto dep = resource.get_dependencies()[0];

    HDL_instance check_dependency;
    check_dependency.set_type("axi_lite");
    check_dependency.set_name("cores_control");
    check_dependency.set_dependency_class(module);
    auto array_qual = std::make_shared<HDL_parameter>();
    array_qual->set_name("instance_array_qualifier");
    array_qual->set_type(HDL_parameter::expression_parameter);
    array_qual->add_component(Expression_component("3"));
    check_dependency.add_array_quantifier(array_qual);
    ASSERT_EQ(dep, check_dependency);
}



TEST(analysis_test, parameter_array_assignment) {
    std::string test_pattern = R"(
    module test_mod ();
        integer i;

            SyndromeCalculator #(
                .TEST_PARAM(TEST_ARRAY[2])
            ) SC (
                .clock(clock)
            );

    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    auto param = resource.get_dependencies()[0].get_parameters().get("TEST_PARAM");

    HDL_parameter reference_param;
    reference_param.set_name("TEST_PARAM");
    Expression_component e("TEST_ARRAY");
    e.add_array_index({Expression_component("2")});
    reference_param.set_expression_components({e});
    reference_param.set_type(HDL_parameter::expression_parameter);

    ASSERT_EQ(reference_param, *param);
}
