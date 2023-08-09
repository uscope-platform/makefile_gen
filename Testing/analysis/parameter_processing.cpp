//  Copyright 2023 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.



#include <gtest/gtest.h>

#include "frontend/analysis/sv_analyzer.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"

typedef struct {
    std::string name;
    std::vector<std::string> components;
    parameter_type type;
    int64_t value;
}param_check_t;

std::map<std::string, HDL_parameter> run_test(std::string & t_p){

    sv_analyzer analyzer(std::make_shared<std::istringstream>(t_p));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor p({},std::make_shared<data_store>(true, "/tmp/test_data_store"));
    resource =  p.process_resource(resource);


    return resource.get_parameters();

}

std::map<std::string, HDL_parameter> produce_check_components(std::vector<param_check_t> &in){
    std::map<std::string, HDL_parameter> ret;

    for(auto & vt : in){
        HDL_parameter par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        ret[vt.name] = par;
    }
    return ret;
}

TEST(parameter_processing, simple_parameters) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter simple_numeric_p = 32,
            sv_numeric_p = 5'o10,
            dimensionless_sv_numeric_p  = 'h3F,
            string_p = "423",
            nested_p = string_p
        )();

        localparam local_p = 74;

        endmodule
    )";

    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"simple_numeric_p", {"32"}, numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"}, numeric_parameter, 8},
            {"dimensionless_sv_numeric_p", {"'h3F"}, numeric_parameter, 63},
            {"string_p", {R"("423")"}, expression_parameter, 9999},
            {"nested_p", {"string_p"}, expression_parameter, 9999},
            {"local_p", {"74"}, numeric_parameter, 74},
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, simple_expressions) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter simple_numeric_p = 32,
            sv_numeric_p = 5'o10
        )();
            parameter add_expr_p = simple_numeric_p + sv_numeric_p;
            parameter sub_expr_p = simple_numeric_p - sv_numeric_p;
            parameter mul_expr_p = simple_numeric_p * sv_numeric_p;
            parameter div_expr_p = simple_numeric_p / sv_numeric_p;
            parameter modulo_expr_p = simple_numeric_p % sv_numeric_p;
            parameter chained_expression = add_expr_p + mul_expr_p  * 5;
            parameter complex_log_expr_p = $clog2(add_expr_p+2);
            parameter simple_log_expr_p = $clog2(add_expr_p);
            parameter parenthesised_expr_p = ( add_expr_p + mul_expr_p ) * 5;
        endmodule
    )";


    auto parameters = run_test(test_pattern);


    std::vector<param_check_t> vect_params = {
            {"simple_numeric_p", {"32"}, numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"}, numeric_parameter, 8},
            {"simple_log_expr_p", {"add_expr_p", "$clog2"}, numeric_parameter, 6},
            {"add_expr_p", {"simple_numeric_p", "sv_numeric_p", "+"}, numeric_parameter,40},
            {"sub_expr_p", {"simple_numeric_p", "sv_numeric_p","-"}, numeric_parameter,24},
            {"mul_expr_p", {"simple_numeric_p", "sv_numeric_p","*"}, numeric_parameter, 256},
            {"div_expr_p", {"simple_numeric_p", "sv_numeric_p","/"}, numeric_parameter, 4},
            {"modulo_expr_p", {"simple_numeric_p", "sv_numeric_p","%"}, numeric_parameter, 0},
            {"chained_expression", {"add_expr_p", "mul_expr_p", "5", "*","+"}, numeric_parameter, 1320},
            {"complex_log_expr_p", { "add_expr_p", "2","+", "$clog2"}, numeric_parameter, 6},
            {"parenthesised_expr_p", { "add_expr_p", "mul_expr_p", "+", "5", "*"}, numeric_parameter, 1480}
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, array_expression) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter [31:0] array_parameter [1:0] = '{32, 5},
            sv_numeric_p = 5'o10
        )();
            parameter array_parameter_expr_p = array_parameter[sv_numeric_p*0] + array_parameter[1];
        endmodule
    )";

    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"array_parameter_0", {"5"}, numeric_parameter, 5},
            {"array_parameter_1", {"32"}, numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"}, numeric_parameter, 8},
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);


    HDL_parameter par = HDL_parameter();
    par.set_type(numeric_parameter);
    par.set_value(37);
    par.set_name("array_parameter_expr_p");
    Expression_component e("array_parameter");
    std::vector<std::vector<Expression_component>> ai = {{Expression_component("sv_numeric_p"), {Expression_component("*")}, {Expression_component("0")}}};
    e.set_array_index(ai);
    par.add_component(e);
    e = Expression_component("array_parameter");
    ai = {{Expression_component("1")}};
    e.set_array_index(ai);
    par.add_component(e);
    par.add_component(Expression_component("+"));
    check_params["array_parameter_expr_p"] = par;


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, multidimensional_array_expression) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter repetition_size = 2,
            parameter [31:0] multidim_array_parameter [repetition_size-1:0][1:0] = '{{32,32}, {5,6}}
        )();
            parameter multidim_array_access = multidim_array_parameter[1][0];
        endmodule
    )";

    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"multidim_array_parameter_0_0", {"6"}, numeric_parameter, 6},
            {"multidim_array_parameter_0_1", {"5"}, numeric_parameter, 5},
            {"multidim_array_parameter_1_0", {"32"}, numeric_parameter, 32},
            {"multidim_array_parameter_1_1", {"32"}, numeric_parameter, 32},
            {"repetition_size", {"2"}, numeric_parameter, 2}
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);

    HDL_parameter par = HDL_parameter();
    par.set_type(numeric_parameter);
    par.set_value(32);
    par.set_name("multidim_array_access");
    Expression_component e = Expression_component("multidim_array_parameter");
    std::vector<Expression> ai = {{Expression_component("1")},{Expression_component("0")}};
    e.set_array_index(ai);
    par.add_component(e);
    check_params["multidim_array_access"] = par;



    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, repetition_initialization) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter repetition_size = 2,
            parameter bit repetition_parameter_a [1:0]  = '{repetition_size{1}},
            parameter bit repetition_parameter_b [1:0]  = '{repetition_size{4}},
            parameter bit multi_repetition_parameter [3:0]  = {repetition_parameter_a,repetition_parameter_b},
            parameter bit mixed_repetition_parameter [3:0]  = {1,2,repetition_parameter_b}
        )();

        endmodule
    )";

    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"repetition_size", {"2"}, numeric_parameter, 2},
            {"repetition_parameter_a_0", {"1"}, numeric_parameter, 1},
            {"repetition_parameter_a_1", {"1"}, numeric_parameter, 1},
            {"repetition_parameter_b_0", {"4"}, numeric_parameter, 4},
            {"repetition_parameter_b_1", {"4"}, numeric_parameter, 4},
            {"multi_repetition_parameter_0", {"4"}, numeric_parameter, 4},
            {"multi_repetition_parameter_1", {"4"}, numeric_parameter, 4},
            {"multi_repetition_parameter_2", {"1"}, numeric_parameter, 1},
            {"multi_repetition_parameter_3", {"1"}, numeric_parameter, 1},
            {"mixed_repetition_parameter_0", {"4"}, numeric_parameter, 4},
            {"mixed_repetition_parameter_1", {"4"}, numeric_parameter, 4},
            {"mixed_repetition_parameter_2", {"2"}, numeric_parameter, 2},
            {"mixed_repetition_parameter_3", {"1"}, numeric_parameter, 1},
    };


    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, packed_array) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter logic [7:0] packed_param = {1'b1,1'b0,1'b1,1'b0,1'b1,1'b0,1'b0,1'b1}
        )();
        endmodule
    )";

    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"packed_param", {"169"}, numeric_parameter, 169}
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, package_parameters) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter package_param = test_package::bus_base
        )();
        endmodule
    )";

    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");

    sv_analyzer analyzer_pkg("check_files/test_package.sv");
    analyzer_pkg.cleanup_content("`(.*)");

    d_store->store_hdl_entity(analyzer_pkg.analyze()[0]);

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];



    Parameter_processor p({},d_store);

    resource =  p.process_resource(resource);

    auto parameters = resource.get_parameters();

    std::map<std::string, HDL_parameter> check_params;

    HDL_parameter param = HDL_parameter();
    param.set_type(expression_parameter);
    param.set_name("package_param");
    param.set_value(0x43c00000);
    Expression_component ec("bus_base");
    ec.set_package_prefix("test_package");
    param.add_component(ec);
    check_params["package_param"] = param;

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, negative_number_parameters) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter negative_param = -16'sd32767
        )();
        endmodule
    )";

    auto parameters = run_test(test_pattern);


    std::vector<param_check_t> vect_params = {
            {"negative_param", {"16'sd32767","-"}, numeric_parameter, -32767}
    };


    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, negative_number_array_init) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter negative_array_param [1:0] = '{-16'sd32767, 16'sd32767}
        )();
        endmodule
    )";

    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"negative_array_param_0", { "32767"}, numeric_parameter, 32767},
            {"negative_array_param_1", {"-32767"}, numeric_parameter, -32767},
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, expression_array_init) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter integer expression_array_param [1:0] = '{5+4, 7*6}
        )();
        endmodule
    )";


    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"expression_array_param_0", {"42"}, numeric_parameter, 42},
            {"expression_array_param_1", {"9"}, numeric_parameter, 9},
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, mixed_packed_unpacked_init) {
    std::string test_pattern = R"(
    module test_mod #(
      parameter reg [7:0] param_a [1:0] = '{{1'b1,1'b1,1'b1,1'b0,1'b0,1'b0,1'b1,1'b0}, {1'b0,1'b0,1'b0,1'b1,1'b1,1'b1,1'b0,1'b1}},
      parameter reg [7:0] param_b [1:0] = '{{8{1'b1}},{8{1'b0}}}
    )();
    endmodule
    )";


    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"param_a_0", {"29"}, numeric_parameter, 29},
            {"param_a_1", {"226"}, numeric_parameter, 226},
            {"param_b_0", {"0"}, numeric_parameter, 0},
            {"param_b_1", {"255"}, numeric_parameter, 255}
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}



std::map<std::string, HDL_parameter> run_override_test(const std::string & t_p, std::map<std::string, HDL_parameter> parent){

    sv_analyzer analyzer(std::make_shared<std::istringstream>(t_p));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor p(parent, std::make_shared<data_store>(true, "/tmp/test_data_store"));
    resource =  p.process_resource(resource);


    return resource.get_parameters();

}


TEST(parameter_processing, simple_expressions_override) {
    std::string test_pattern = R"(
      module test_mod #(
                parameter simple_numeric_p = 32,
                sv_numeric_p = 5'o10
            )();
                parameter add_expr_p = simple_numeric_p + sv_numeric_p;
                parameter sub_expr_p = simple_numeric_p - sv_numeric_p;
                parameter mul_expr_p = simple_numeric_p * sv_numeric_p;
                parameter div_expr_p = simple_numeric_p / sv_numeric_p;
                parameter modulo_expr_p = simple_numeric_p % sv_numeric_p;
                parameter chained_expression = add_expr_p + mul_expr_p  * 5;
                parameter complex_log_expr_p = $clog2(add_expr_p+2);
                parameter simple_log_expr_p = $clog2(add_expr_p);
                parameter parenthesised_expr_p = ( add_expr_p + mul_expr_p ) * 5;
            endmodule
        )";

    std::map<std::string, HDL_parameter> parent_param;

    HDL_parameter par = HDL_parameter();
    par.set_name("simple_numeric_p");
    par.add_component(Expression_component("15"));
    par.set_type(numeric_parameter);
    par.set_value(15);
    parent_param["simple_numeric_p"] = par;

    par = HDL_parameter();
    par.set_name("sv_numeric_p");
    par.add_component(Expression_component("2"));
    par.set_type(numeric_parameter);
    par.set_value(2);
    parent_param["sv_numeric_p"] = par;


    auto parameters = run_override_test(test_pattern, parent_param);

    std::vector<param_check_t> vect_params = {
            {"simple_numeric_p", {"15"}, numeric_parameter, 15},
            {"sv_numeric_p", {"2"}, numeric_parameter, 2},
            {"simple_log_expr_p", {"add_expr_p", "$clog2"}, numeric_parameter, 5},
            {"add_expr_p", {"simple_numeric_p", "sv_numeric_p", "+"}, numeric_parameter,17},
            {"sub_expr_p", {"simple_numeric_p", "sv_numeric_p","-"}, numeric_parameter,13},
            {"mul_expr_p", {"simple_numeric_p", "sv_numeric_p","*"}, numeric_parameter, 30},
            {"div_expr_p", {"simple_numeric_p", "sv_numeric_p","/"}, numeric_parameter, 7},
            {"modulo_expr_p", {"simple_numeric_p", "sv_numeric_p","%"}, numeric_parameter, 1},
            {"chained_expression", {"add_expr_p", "mul_expr_p", "5", "*","+"}, numeric_parameter, 167},
            {"complex_log_expr_p", { "add_expr_p", "2","+", "$clog2"}, numeric_parameter, 5},
            {"parenthesised_expr_p", { "add_expr_p", "mul_expr_p", "+", "5", "*"}, numeric_parameter, 235}
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);



    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, array_expression_override) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter [31:0] array_parameter [1:0] = '{32, 5},
            sv_numeric_p = 5'o10
        )();
            parameter array_parameter_expr_p = array_parameter[sv_numeric_p*0] + array_parameter[1];
        endmodule
    )";

    std::map<std::string, HDL_parameter> parent_param;

    HDL_parameter par = HDL_parameter();
    par.set_name("array_parameter_0");
    par.add_component(Expression_component("22"));
    par.set_type(numeric_parameter);
    par.set_value(22);
    parent_param["array_parameter_0"] = par;

    par = HDL_parameter();
    par.set_name("array_parameter_1");
    par.add_component(Expression_component("2"));
    par.set_type(numeric_parameter);
    par.set_value(2);
    parent_param["array_parameter_1"] = par;

    auto parameters = run_override_test(test_pattern, parent_param);


    std::vector<param_check_t> vect_params = {
            {"array_parameter_0", {"22"}, numeric_parameter, 22},
            {"array_parameter_1", {"2"}, numeric_parameter, 2},
            {"sv_numeric_p", {"5'o10"}, numeric_parameter, 8}
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);


    par = HDL_parameter();
    par.set_type(numeric_parameter);
    par.set_value(24);
    par.set_name("array_parameter_expr_p");
    Expression_component e("array_parameter");
    std::vector<std::vector<Expression_component>> ai = {{Expression_component("sv_numeric_p"), {Expression_component("*")}, {Expression_component("0")}}};
    e.set_array_index(ai);
    par.add_component(e);
    e = Expression_component("array_parameter");
    ai = {{Expression_component("1")}};
    e.set_array_index(ai);
    par.add_component(e);
    par.add_component(Expression_component("+"));
    check_params["array_parameter_expr_p"] = par;



    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, repetition_array_override) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter repetition_size = 2,
            parameter bit repetition_parameter_a [repetition_size-1:0]  = '{repetition_size{1}}
        )();

        endmodule
    )";

    std::map<std::string, HDL_parameter> parent_param;

    HDL_parameter par = HDL_parameter();
    par.set_name("repetition_size");
    par.add_component(Expression_component("3"));
    par.set_type(numeric_parameter);
    par.set_value(3);
    parent_param["repetition_size"] = par;


    auto parameters = run_override_test(test_pattern, parent_param);

    std::vector<param_check_t> vect_params = {
            {"repetition_parameter_a_0", {"1"}, numeric_parameter, 1},
            {"repetition_parameter_a_1", {"1"}, numeric_parameter, 1},
            {"repetition_parameter_a_2", {"1"}, numeric_parameter, 1},
            {"repetition_size", {"3"}, numeric_parameter, 3}
    };

    std::map<std::string, HDL_parameter> check_params = produce_check_components(vect_params);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}