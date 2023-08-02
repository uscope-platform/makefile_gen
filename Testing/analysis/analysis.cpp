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
    bus_mapping_expression exp("if_array", {"module_parameter_2", "+", "1"});
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
    p.add_component(Expression_component("56"));
    p.set_type(expression_parameter);
    check_res.add_parameter(p);


    p = HDL_parameter();
    p.set_name("module_parameter_2");
    p.add_component(Expression_component("74"));
    p.set_type(expression_parameter);
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
            {"simple_log_expr_p", {"add_expr_p", "$clog2"}},
            {"add_expr_p", {"simple_numeric_p", "sv_numeric_p", "+"}},
            {"sub_expr_p", {"simple_numeric_p", "sv_numeric_p","-"}},
            {"mul_expr_p", {"simple_numeric_p", "sv_numeric_p","*"}},
            {"div_expr_p", {"simple_numeric_p", "sv_numeric_p","/"}},
            {"modulo_expr_p", {"simple_numeric_p", "sv_numeric_p","%"}},
            {"chained_expression", {"add_expr_p", "mul_expr_p", "5", "*","+"}},
            {"complex_log_expr_p", { "add_expr_p", "2","+", "$clog2"}},
            {"parenthesised_expr_p", { "add_expr_p", "mul_expr_p", "+", "5", "*"}}
    };


    for(auto &item:  vect_params){
        HDL_parameter p = HDL_parameter();
        p.set_type(expression_parameter);
        p.set_name(item.first);
        for(auto &op:item.second){
            p.add_component(Expression_component(op));
        }
        check_params[item.first] = p;
    }

    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("array_parameter");
    std::vector<std::vector<Expression_component>> il = {{Expression_component("32")}, {Expression_component("5")}};
    p.set_initialization_list(il);
    p.add_dimension({{Expression_component("1")},{Expression_component("0")}});
    check_params["array_parameter"] = p;

    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("array_parameter_expr_p");
    Expression_component e("array_parameter");
    std::vector<std::vector<Expression_component>> ai = {{Expression_component("sv_numeric_p")}, {Expression_component("*")}, {Expression_component(0)}};
    e.set_array_index(ai);
    p.add_component(e);
    e = Expression_component("array_parameter");
    ai = {{Expression_component(1)}};
    e.set_array_index(ai);
    p.add_component(e);
    p.add_component(Expression_component("+"));
    check_params["array_parameter_expr_p"] = p;


    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("multidim_array_parameter");
    il = {{Expression_component("32")},{Expression_component("32")}, {Expression_component("5")}, {Expression_component("6")}};
    p.set_initialization_list(il);
    p.add_dimension({{Expression_component("TEST_PARAM"),Expression_component("-"), Expression_component("1")},{Expression_component("0")}});
    p.add_dimension({{Expression_component("1")},{Expression_component("0")}});
    check_params["multidim_array_parameter"] = p;



    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("multidim_array_access");
    e = Expression_component("multidim_array_parameter");
    ai = {{Expression_component("1")},{Expression_component("0")}};
    e.set_array_index(ai);
    p.add_component(e);
    check_params["multidim_array_access"] = p;


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }


    ASSERT_EQ(check_params, parameters);
}



TEST(analysis_test, shunting_yard_priority){


    Parameter_processor p;
    std::vector<Expression_component> expr = {
            Expression_component("add_expr_p"),
            Expression_component("+"),
            Expression_component("mul_expr_p"),
            Expression_component("*"),
            Expression_component("5")
    };
    auto rpn_expr = p.expr_vector_to_rpn(expr);
    std::vector<Expression_component> expected_result = {
            Expression_component("add_expr_p"),
            Expression_component("mul_expr_p"),
            Expression_component("5"),
            Expression_component("*"),
            Expression_component("+")
    };

    ASSERT_EQ(rpn_expr, expected_result);

}

TEST(analysis_test, shunting_yard_parenthesis){

    Parameter_processor p;
    std::vector<Expression_component> expr_1 = {
            Expression_component("("),
            Expression_component("add_expr_p"),
            Expression_component("+"),
            Expression_component("mul_expr_p"),
            Expression_component(")"),
            Expression_component("*"),
            Expression_component("5")
    };
    auto rpn_expr_1 = p.expr_vector_to_rpn(expr_1);

    std::vector<Expression_component> expected_result_1 = {
            Expression_component("add_expr_p"),
            Expression_component("mul_expr_p"),
            Expression_component("+"),
            Expression_component("5"),
            Expression_component("*")
    };

    ASSERT_EQ(rpn_expr_1, expected_result_1);

    std::vector<Expression_component> expr_2 = {
            Expression_component("5"),
            Expression_component("*"),
            Expression_component("("),
            Expression_component("add_expr_p"),
            Expression_component("+"),
            Expression_component("mul_expr_p"),
            Expression_component(")")

    };

    auto rpn_expr_2 = p.expr_vector_to_rpn(expr_2);

    std::vector<Expression_component> expected_result_2 = {
            Expression_component("5"),
            Expression_component("add_expr_p"),
            Expression_component("mul_expr_p"),
            Expression_component("+"),
            Expression_component("*")
    };
    ASSERT_EQ(rpn_expr_2, expected_result_2);
}

TEST(analysis_test, shunting_yard_function){
    Parameter_processor p;
    std::vector<Expression_component> expr = {
            Expression_component("$clog2"),
            Expression_component("("),
            Expression_component("add_expr_p"),
            Expression_component("+"),
            Expression_component("2"),
            Expression_component(")")

    };

    auto rpn_expr = p.expr_vector_to_rpn(expr);
    std::vector<Expression_component> expected_result = {
            Expression_component("add_expr_p"),
            Expression_component("2"),
            Expression_component("+"),
            Expression_component("$clog2")
    };


    ASSERT_EQ(rpn_expr, expected_result);
}


TEST(analysis_test, verilog_parameter_processing){
    sv_analyzer analyzer("check_files/test_sv_parameter_extraction.sv");
    analyzer.cleanup_content("`(.*)");
    HDL_Resource resource = analyzer.analyze()[0];

    Parameter_processor p;
    resource =  p.process_resource(resource);

    auto parameters = resource.get_parameters();

    std::unordered_map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        std::vector<std::string> dependencies;
        parameter_type type;
        uint32_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"simple_numeric_p", {"32"}, {}, numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"}, {}, numeric_parameter, 8},
            {"dimensionless_sv_numeric_p", {"'h3F"}, {}, numeric_parameter, 63},
            {"string_p", {R"("423")"}, {}, expression_parameter, 9999},
            {"nested_p", {"string_parameter"}, {}, expression_parameter, 9999},
            {"local_p", {"74"}, {}, numeric_parameter, 74},
            {"simple_log_expr_p", {"add_expr_p", "$clog2"}, {"add_expr_p"}, numeric_parameter, 6},
            {"add_expr_p", {"simple_numeric_p", "sv_numeric_p", "+"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter,40},
            {"sub_expr_p", {"simple_numeric_p", "sv_numeric_p","-"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter,24},
            {"mul_expr_p", {"simple_numeric_p", "sv_numeric_p","*"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter, 256},
            {"div_expr_p", {"simple_numeric_p", "sv_numeric_p","/"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter, 4},
            {"modulo_expr_p", {"simple_numeric_p", "sv_numeric_p","%"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter, 0},
            {"chained_expression", {"add_expr_p", "mul_expr_p", "5", "*","+"}, {"add_expr_p", "mul_expr_p"}, numeric_parameter, 1320},
            {"complex_log_expr_p", { "add_expr_p", "2","+", "$clog2"}, {"add_expr_p"}, numeric_parameter, 6},
            {"parenthesised_expr_p", { "add_expr_p", "mul_expr_p", "+", "5", "*"}, {"add_expr_p", "mul_expr_p"}, numeric_parameter, 1480},
            {"array_parameter_0", {"32"}, {}, numeric_parameter, 32},
            {"array_parameter_1", {"5"}, {}, numeric_parameter, 5},
            {"multidim_array_parameter_0", {"32"}, {}, numeric_parameter, 32},
            {"multidim_array_parameter_1", {"32"}, {}, numeric_parameter, 32},
            {"multidim_array_parameter_2", {"5"}, {}, numeric_parameter, 5},
            {"multidim_array_parameter_3", {"6"}, {}, numeric_parameter, 6},
    };


    for(auto & vt : vect_params){
        HDL_parameter par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        for(auto &dep:vt.dependencies){
            par.add_dependency(dep);
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }


        HDL_parameter param;
        param.set_type(numeric_parameter);
        param.set_value(37);
        param.set_name("array_parameter_expr_p");
        Expression_component e("array_parameter");
        std::vector<std::vector<Expression_component>> ai = {{Expression_component("sv_numeric_p"), {Expression_component("*")}, {Expression_component(0)}}};
        e.set_array_index(ai);
        param.add_component(e);
        e = Expression_component("array_parameter");
        ai = {{Expression_component(1)}};
        e.set_array_index(ai);
        param.add_component(e);
        param.add_component(Expression_component("+"));
        param.add_dependency("array_parameter_1");
        param.add_dependency("array_parameter_0");
        param.add_dependency("sv_numeric_p");
        check_params["array_parameter_expr_p"] = param;



        param = HDL_parameter();
        param.set_type(numeric_parameter);
        param.set_value(5);
        param.set_name("multidim_array_access");
        e = Expression_component("multidim_array_parameter");
        ai = {{Expression_component("1")},{Expression_component("0")}};
        e.set_array_index(ai);
        param.add_component(e);
        param.add_dependency("multidim_array_parameter_2");
        check_params["multidim_array_access"] = param;



    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        auto result = parameters[item.first];
        auto reference = item.second;
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(reference, result);
    }


    ASSERT_EQ(check_params, parameters);

}


TEST(analysis_test, verilog_parameter_processing_override){
    sv_analyzer analyzer("check_files/test_sv_parameter_extraction.sv");
    analyzer.cleanup_content("`(.*)");
    HDL_Resource resource = analyzer.analyze()[0];

    std::unordered_map<std::string, HDL_parameter> parent_params;

    HDL_parameter par = HDL_parameter();
    par.set_name("simple_numeric_p");
    par.set_value(15);
    parent_params["simple_numeric_p"] = par;


    par.set_name("sv_numeric_p");
    par.set_value(12);
    parent_params["sv_numeric_p"] = par;

    Parameter_processor p;
    resource =  p.process_resource(resource, parent_params);

    auto parameters = resource.get_parameters();

    std::unordered_map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        std::vector<std::string> dependencies;
        parameter_type type;
        uint32_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"simple_numeric_p", {"32"}, {}, numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"}, {}, numeric_parameter, 8},
            {"dimensionless_sv_numeric_p", {"'h3F"}, {}, numeric_parameter, 63},
            {"string_p", {R"("423")"}, {}, expression_parameter, 9999},
            {"nested_p", {"string_parameter"}, {}, expression_parameter, 9999},
            {"local_p", {"74"}, {}, numeric_parameter, 74},
            {"simple_log_expr_p", {"add_expr_p", "$clog2"}, {"add_expr_p"}, numeric_parameter, 5},
            {"add_expr_p", {"simple_numeric_p", "sv_numeric_p", "+"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter,27},
            {"sub_expr_p", {"simple_numeric_p", "sv_numeric_p","-"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter,3},
            {"mul_expr_p", {"simple_numeric_p", "sv_numeric_p","*"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter, 180},
            {"div_expr_p", {"simple_numeric_p", "sv_numeric_p","/"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter, 1},
            {"modulo_expr_p", {"simple_numeric_p", "sv_numeric_p","%"}, {"simple_numeric_p","sv_numeric_p"}, numeric_parameter, 3},
            {"chained_expression", {"add_expr_p", "mul_expr_p", "5", "*","+"}, {"add_expr_p", "mul_expr_p"}, numeric_parameter, 927},
            {"complex_log_expr_p", { "add_expr_p", "2","+", "$clog2"}, {"add_expr_p"}, numeric_parameter, 5},
            {"parenthesised_expr_p", { "add_expr_p", "mul_expr_p", "+", "5", "*"}, {"add_expr_p", "mul_expr_p"}, numeric_parameter, 1035},
            {"array_parameter_0", {"32"}, {}, numeric_parameter, 32},
            {"array_parameter_1", {"5"}, {}, numeric_parameter, 5},
            {"multidim_array_parameter_0", {"32"}, {}, numeric_parameter, 32},
            {"multidim_array_parameter_1", {"32"}, {}, numeric_parameter, 32},
            {"multidim_array_parameter_2", {"5"}, {}, numeric_parameter, 5},
            {"multidim_array_parameter_3", {"6"}, {}, numeric_parameter, 6},
    };


    for(auto & vt : vect_params){
        HDL_parameter par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        for(auto &op:vt.dependencies){
            par.add_dependency(op);
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }



    HDL_parameter param;
    param.set_type(numeric_parameter);
    param.set_value(37);
    param.set_name("array_parameter_expr_p");
    Expression_component e("array_parameter");
    std::vector<std::vector<Expression_component>> ai = {{Expression_component("sv_numeric_p"), {Expression_component("*")}, {Expression_component(0)}}};
    e.set_array_index(ai);
    param.add_component(e);
    e = Expression_component("array_parameter");
    ai = {{Expression_component(1)}};
    e.set_array_index(ai);
    param.add_component(e);
    param.add_component(Expression_component("+"));
    param.add_dependency("array_parameter_1");
    param.add_dependency("array_parameter_0");
    param.add_dependency("sv_numeric_p");
    check_params["array_parameter_expr_p"] = param;



    param = HDL_parameter();
    param.set_type(numeric_parameter);
    param.set_value(5);
    param.set_name("multidim_array_access");
    e = Expression_component("multidim_array_parameter");
    ai = {{Expression_component("1")},{Expression_component("0")}};
    e.set_array_index(ai);
    param.add_component(e);
    param.add_dependency("multidim_array_parameter_2");
    check_params["multidim_array_access"] = param;




    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        auto result = parameters[item.first];
        auto reference = item.second;
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(reference, result);
    }


    ASSERT_EQ(check_params, parameters);
}