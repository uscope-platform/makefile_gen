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


std::map<std::string, HDL_parameter> run_test(std::string & t_p){

    sv_analyzer analyzer(std::make_shared<std::istringstream>(t_p));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor p({},std::make_shared<data_store>(true, "/tmp/test_data_store"));
    resource =  p.process_resource(resource);


    return resource.get_parameters();

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

    std::map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"simple_numeric_p", {"32"}, numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"}, numeric_parameter, 8},
            {"dimensionless_sv_numeric_p", {"'h3F"}, numeric_parameter, 63},
            {"string_p", {R"("423")"}, expression_parameter, 9999},
            {"nested_p", {"string_p"}, expression_parameter, 9999},
            {"local_p", {"74"}, numeric_parameter, 74},
    };



    for(auto & vt : vect_params){
        HDL_parameter par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }


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

    std::map<std::string, HDL_parameter> check_params;


    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;


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


    for(auto & vt : vect_params){
        HDL_parameter par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }

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

    std::map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"array_parameter_0", {"32"}, numeric_parameter, 32},
            {"array_parameter_1", {"5"}, numeric_parameter, 5},
            {"sv_numeric_p", {"5'o10"}, numeric_parameter, 8},
    };

    HDL_parameter par = HDL_parameter();
    for(auto & vt : vect_params){
        par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }



    par = HDL_parameter();
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

    std::map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"multidim_array_parameter_0", {"32"}, numeric_parameter, 32},
            {"multidim_array_parameter_1", {"32"}, numeric_parameter, 32},
            {"multidim_array_parameter_2", {"5"}, numeric_parameter, 5},
            {"multidim_array_parameter_3", {"6"}, numeric_parameter, 6},
            {"repetition_size", {"2"}, numeric_parameter, 2}
    };

    HDL_parameter par = HDL_parameter();
    for(auto & vt : vect_params){
        par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }


    par = HDL_parameter();
    par.set_type(numeric_parameter);
    par.set_value(5);
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

    std::map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"repetition_size", {"2"}, numeric_parameter, 2},
            {"repetition_parameter_a_0", {"1"}, numeric_parameter, 1},
            {"repetition_parameter_a_1", {"1"}, numeric_parameter, 1},
            {"repetition_parameter_b_0", {"4"}, numeric_parameter, 4},
            {"repetition_parameter_b_1", {"4"}, numeric_parameter, 4},
            {"multi_repetition_parameter_0", {"1"}, numeric_parameter, 1},
            {"multi_repetition_parameter_1", {"1"}, numeric_parameter, 1},
            {"multi_repetition_parameter_2", {"4"}, numeric_parameter, 4},
            {"multi_repetition_parameter_3", {"4"}, numeric_parameter, 4},
            {"mixed_repetition_parameter_0", {"1"}, numeric_parameter, 1},
            {"mixed_repetition_parameter_1", {"2"}, numeric_parameter, 2},
            {"mixed_repetition_parameter_2", {"4"}, numeric_parameter, 4},
            {"mixed_repetition_parameter_3", {"4"}, numeric_parameter, 4},
    };

    HDL_parameter par = HDL_parameter();
    for(auto & vt : vect_params){
        par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }

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


    std::map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"packed_param", {"169"}, numeric_parameter, 169}
    };

    HDL_parameter par = HDL_parameter();
    for(auto & vt : vect_params){
        par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }

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

    std::map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"negative_param", {"16'sd32767","-"}, numeric_parameter, -32767}
    };

    HDL_parameter par = HDL_parameter();
    for(auto & vt : vect_params){
        par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_processing, negative_number_array_init) {
    std::string test_pattern = R"(
        module test_mod #(
             //parameter negative_array_param [1:0] = '{-16'sd32767, 16'sd32767}
        )();
        endmodule
    )";

    auto parameters = run_test(test_pattern);

    std::map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"negative_array_param_0", {"16'sd32767","-"}, numeric_parameter, -32767},
            {"negative_array_param_1", {"16'sd32767"}, numeric_parameter, 32767},
    };

    HDL_parameter par = HDL_parameter();
    for(auto & vt : vect_params){
        par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}


TEST(parameter_processing, expression_array_init) {
    std::string test_pattern = R"(
        module test_mod #(
             //parameter expression_array_param [1:0] = '{5+4, 7*6}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    std::map<std::string, HDL_parameter> check_params;


    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("negative_param");
    for(auto &op:{"16'sd32767","-"}){
        p.add_component(Expression_component(op));
    }
    check_params["negative_param"] = p;

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

/*
TEST(parameter_processing, verilog_parameter_processing_override){

    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");

    sv_analyzer analyzer("check_files/test_package.sv");
    analyzer.cleanup_content("`(.*)");

    d_store->store_hdl_entity(analyzer.analyze()[0]);

    analyzer = sv_analyzer("check_files/test_sv_parameter_extraction.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    std::map<std::string, HDL_parameter> parent_params;

    HDL_parameter par = HDL_parameter();
    par.set_name("simple_numeric_p");
    par.set_value(15);
    parent_params["simple_numeric_p"] = par;


    par.set_name("sv_numeric_p");
    par.set_value(12);
    parent_params["sv_numeric_p"] = par;

    Parameter_processor p(parent_params, d_store);
    resource =  p.process_resource(resource);

    auto parameters = resource.get_parameters();

    std::map<std::string, HDL_parameter> check_params;

    typedef struct {
        std::string name;
        std::vector<std::string> components;
        parameter_type type;
        int64_t value;
    }param_check_t;

    std::vector<param_check_t> vect_params = {
            {"simple_numeric_p", {"32"},  numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"},  numeric_parameter, 8},
            {"dimensionless_sv_numeric_p", {"'h3F"},numeric_parameter, 63},
            {"string_p", {R"("423")"}, expression_parameter, 9999},
            {"nested_p", {"string_p"}, expression_parameter, 9999},
            {"local_p", {"74"}, numeric_parameter, 74},
            {"repetition_size", {"2"}, numeric_parameter, 2},
            {"simple_log_expr_p", {"add_expr_p", "$clog2"}, numeric_parameter, 5},
            {"add_expr_p", {"simple_numeric_p", "sv_numeric_p", "+"}, numeric_parameter,27},
            {"sub_expr_p", {"simple_numeric_p", "sv_numeric_p","-"}, numeric_parameter,3},
            {"mul_expr_p", {"simple_numeric_p", "sv_numeric_p","*"}, numeric_parameter, 180},
            {"div_expr_p", {"simple_numeric_p", "sv_numeric_p","/"}, numeric_parameter, 1},
            {"modulo_expr_p", {"simple_numeric_p", "sv_numeric_p","%"}, numeric_parameter, 3},
            {"chained_expression", {"add_expr_p", "mul_expr_p", "5", "*","+"}, numeric_parameter, 927},
            {"complex_log_expr_p", { "add_expr_p", "2","+", "$clog2"}, numeric_parameter, 5},
            {"parenthesised_expr_p", { "add_expr_p", "mul_expr_p", "+", "5", "*"}, numeric_parameter, 1035},
            {"array_parameter_0", {"32"}, numeric_parameter, 32},
            {"array_parameter_1", {"5"}, numeric_parameter, 5},
            {"multidim_array_parameter_0", {"32"}, numeric_parameter, 32},
            {"multidim_array_parameter_1", {"32"}, numeric_parameter, 32},
            {"multidim_array_parameter_2", {"5"}, numeric_parameter, 5},
            {"multidim_array_parameter_3", {"6"}, numeric_parameter, 6},
            {"repetition_parameter_0", {"1"}, numeric_parameter, 1},
            {"repetition_parameter_1", {"1"}, numeric_parameter, 1},
            {"multi_repetition_parameter_0", {"1"}, numeric_parameter, 1},
            {"multi_repetition_parameter_1", {"1"}, numeric_parameter, 1},
            {"multi_repetition_parameter_2", {"4"}, numeric_parameter, 4},
            {"multi_repetition_parameter_3", {"4"}, numeric_parameter, 4},
            {"mixed_repetition_parameter_0", {"1"}, numeric_parameter, 1},
            {"mixed_repetition_parameter_1", {"2"}, numeric_parameter, 2},
            {"mixed_repetition_parameter_2", {"4"}, numeric_parameter, 4},
            {"mixed_repetition_parameter_3", {"4"}, numeric_parameter, 4},
            {"negative_param", {"16'sd32767","-"}, numeric_parameter, -32767}
    };


    for(auto & vt : vect_params){
        HDL_parameter par = HDL_parameter();
        par.set_name(vt.name);
        for(auto &cpt:vt.components){
            par.add_component(Expression_component(cpt));
        }
        par.set_type(vt.type);
        if(vt.type == numeric_parameter){
            par.set_value(vt.value);
        }

        check_params[vt.name] = par;
    }

    HDL_parameter param = HDL_parameter();
    param.set_type(expression_parameter);
    param.set_name("package_param");
    param.set_value(0x43c00000);
    Expression_component ec("bus_base");
    ec.set_package_prefix("test_package");
    param.add_component(ec);
    check_params["package_param"] = param;


    param = HDL_parameter();
    param.set_type(numeric_parameter);
    param.set_value(37);
    param.set_name("array_parameter_expr_p");
    Expression_component e("array_parameter");
    std::vector<std::vector<Expression_component>> ai = {{Expression_component("sv_numeric_p"), {Expression_component("*")}, {Expression_component("0")}}};
    e.set_array_index(ai);
    param.add_component(e);
    e = Expression_component("array_parameter");
    ai = {{Expression_component("1")}};
    e.set_array_index(ai);
    param.add_component(e);
    param.add_component(Expression_component("+"));
    check_params["array_parameter_expr_p"] = param;


    param = HDL_parameter();
    param.set_type(numeric_parameter);
    param.set_value(169);
    param.set_name("packed_param");
    param.add_component(Expression_component("169"));
    check_params["packed_param"] = param;

    param = HDL_parameter();
    param.set_type(numeric_parameter);
    param.set_value(5);
    param.set_name("multidim_array_access");
    e = Expression_component("multidim_array_parameter");
    ai = {{Expression_component("1")},{Expression_component("0")}};
    e.set_array_index(ai);
    param.add_component(e);
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
*/