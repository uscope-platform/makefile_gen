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

    HDL_instance d3("SC", "SyndromeCalculator", module);
    d3.add_port_connection("clock", "clock");
    d3.add_port_connection("reset", "reset");
    d3.add_port_connection("data_in", "data_in");
    d3.add_port_connection("syndrome", "data_out");
    HDL_parameter p;
    p.set_name("TEST_PARAM");
    p.set_value("test_package::param");
    d3.add_parameter("TEST_PARAM", p);

    HDL_instance d2("param", "test_package", package);
    HDL_instance d1("__init_file__", "file", memory_init);
    HDL_instance d0("if_array", "axi_lite", module);
    expression exp("if_array", {"module_parameter_2","+","1"});
    d0.add_array_quantifier(exp);
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


    p = HDL_parameter();
    p.set_name("module_parameter_1");
    p.set_value("56");
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
    HDL_instance dep("and_component", "ANDGATE", module);
    HDL_Resource check_res (module, "half_adder", "check_files/test_vhdl_module.vhd");
    check_res.add_dependency(dep);
    ASSERT_EQ(resource, check_res);
}

TEST(analysis_test, verilog_parameter_extraction){
    sv_analyzer analyzer("check_files/test_sv_parameter_extraction.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto parameters = resource.get_parameters();

    std::unordered_map<std::string, HDL_parameter> check_params;

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"simple_numeric_p", {"32"}},
            {"sv_numeric_p", {"5'o10"}},
            {"dimensionless_sv_numeric_p", {"'h3F"}},
            {"string_p", {R"("423")"}},
            {"nested_p", {"string_parameter"}},
            {"local_p", {"74"}},
            {"simple_log_expr_p", {"$clog2", "add_expr_p"}},
            {"add_expr_p", {"simple_numeric_p", "+", "sv_numeric_p"}},
            {"sub_expr_p", {"simple_numeric_p","-", "sv_numeric_p"}},
            {"mul_expr_p", {"simple_numeric_p","*", "sv_numeric_p"}},
            {"div_expr_p", {"simple_numeric_p","/", "sv_numeric_p"}},
            {"modulo_expr_p", {"simple_numeric_p","%", "sv_numeric_p"}},
            {"chained_expression", {"add_expr_p","+", "mul_expr_p", "*", "5"}},
            {"complex_log_expr_p", { "$clog2", "add_expr_p","+", "2"}},
            {"parenthesised_expr_p", {"(", "add_expr_p","+", "mul_expr_p", ")", "*", "5"}},
    };


    for(auto &item:  vect_params){
        HDL_parameter p = HDL_parameter();
        p.set_type(expression_parameter);
        p.set_name(item.first);
        for(auto &op:item.second){
            p.add_component(op);
        }
        check_params[item.first] = p;
    }

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }


    ASSERT_EQ(check_params, parameters);
}



TEST(analysis_test, verilog_parameter_processing){
    sv_analyzer analyzer("check_files/test_sv_parameter_extraction.sv");
    analyzer.cleanup_content("`(.*)");
    HDL_Resource resource = analyzer.analyze()[0];

    Parameter_processor p;
    resource =  p.process_resource(resource);

    auto parameters = resource.get_parameters();

    std::unordered_map<std::string, HDL_parameter> check_params;


    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"simple_numeric_p", {"32"}},
            {"sv_numeric_p", {"5'o10"}},
            {"dimensionless_sv_numeric_p", {"'h3F"}},
            {"string_p", {R"("423")"}},
            {"nested_p", {"string_parameter"}},
            {"local_p", {"74"}},
            {"simple_log_expr_p", {"$clog2", "add_expr_p"}},
            {"add_expr_p", {"simple_numeric_p", "+", "sv_numeric_p"}},
            {"sub_expr_p", {"simple_numeric_p","-", "sv_numeric_p"}},
            {"mul_expr_p", {"simple_numeric_p","*", "sv_numeric_p"}},
            {"div_expr_p", {"simple_numeric_p","/", "sv_numeric_p"}},
            {"modulo_expr_p", {"simple_numeric_p","%", "sv_numeric_p"}},
            {"chained_expression", {"add_expr_p","+", "mul_expr_p", "*", "5"}},
            {"complex_log_expr_p", { "$clog2", "add_expr_p","+", "2"}},
            {"parenthesised_expr_p", {"(", "add_expr_p","+", "mul_expr_p", ")", "*", "5"}},
    };

    std::vector<parameter_type> check_types = {
            numeric_parameter,
            numeric_parameter,
            numeric_parameter,
            expression_parameter,
            expression_parameter,
            numeric_parameter,
            numeric_parameter,
            numeric_parameter,
            numeric_parameter,
            numeric_parameter,
            numeric_parameter,
            numeric_parameter,
            numeric_parameter,
            numeric_parameter,
            numeric_parameter
    };

    std::vector<uint32_t> check_values = {
            32,  // simple_numeric_p
            8, // sv_numeric_p
            63, //dimensionless_sv_numeric_p
            9999, // DUMMY VALUE string_p
            9999, // DUMMY VALUE nested_p
            74, //local_p
            6, //simple_log_expr_p
            40, //add_expr_p
            24, //sub_expr_p
            256, //mul_expr_p
            4, //div_expr_p
            0, //modulo_expr_p
            1320, //chained_expression
            6, //complex_log_expr_p
            1480 //parenthesised_expr_p
    };

    for(int i = 0; i<vect_params.size(); i++){
        HDL_parameter par = HDL_parameter();
        par.set_name(vect_params[i].first);
        for(auto &op:vect_params[i].second){
            par.add_component(op);
        }
        par.set_type(check_types[i]);
        if(check_types[i] == numeric_parameter){
            par.set_value(check_values[i]);
        }

        check_params[vect_params[i].first] = par;
    }

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        auto result = parameters[item.first];
        auto reference = item.second;
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(reference, result);
    }


    ASSERT_EQ(check_params, parameters);

}