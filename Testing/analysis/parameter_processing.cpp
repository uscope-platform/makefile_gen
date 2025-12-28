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
#include "analysis/HDL_ast_builder.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"

typedef struct {
    std::string name;
    std::vector<std::string> components;
    HDL_parameter::parameter_type type;
    int64_t value;
    bool is_rpn;
}param_check_t;

Parameters_map run_test(std::string & t_p){

    sv_analyzer analyzer(std::make_shared<std::istringstream>(t_p));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor p({},std::make_shared<data_store>(true, "/tmp/test_data_store"));

    return p.process_parameters_map(resource.get_parameters(), resource);

}

Parameters_map produce_check_components(std::vector<param_check_t> &in){
    Parameters_map ret;

    for(auto & vt : in){
        auto par = std::make_shared<HDL_parameter>();
        par->set_name(vt.name);
        if(vt.is_rpn){
            auto expr= par->get_expression_components();
            expr.rpn = true;
            par->set_expression_components(expr);
        }
        for(auto &cpt:vt.components){
            par->add_component(Expression_component(cpt));
        }
        par->set_type(vt.type);
        if(vt.type == HDL_parameter::HDL_parameter::numeric_parameter){
            par->set_value(vt.value);
        }

        ret.insert(par);
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
            {"simple_numeric_p", {"32"}, HDL_parameter::numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"}, HDL_parameter::numeric_parameter, 8},
            {"dimensionless_sv_numeric_p", {"'h3F"}, HDL_parameter::numeric_parameter, 63},
            {"local_p", {"74"}, HDL_parameter::numeric_parameter, 74},
    };


    Parameters_map check_params = produce_check_components(vect_params);

    auto p = std::make_shared<HDL_parameter>();
    p->set_value("423");
    p->set_name("string_p");
    p->add_component({Expression_component(R"("423")")});

    check_params.insert(p);

    p  = std::make_shared<HDL_parameter>();
    p->set_value("string_p");
    p->set_name("nested_p");
    p->add_component({Expression_component("string_p")});

    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
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
            {"simple_numeric_p", {"32"}, HDL_parameter::numeric_parameter, 32},
            {"sv_numeric_p", {"5'o10"}, HDL_parameter::numeric_parameter, 8},
            {"simple_log_expr_p", {"$clog2", "(", "add_expr_p", ")"}, HDL_parameter::numeric_parameter, 6},
            {"add_expr_p", {"simple_numeric_p", "+", "sv_numeric_p"}, HDL_parameter::numeric_parameter,40},
            {"sub_expr_p", {"simple_numeric_p","-", "sv_numeric_p"}, HDL_parameter::numeric_parameter,24},
            {"mul_expr_p", {"simple_numeric_p","*", "sv_numeric_p"}, HDL_parameter::numeric_parameter, 256},
            {"div_expr_p", {"simple_numeric_p","/", "sv_numeric_p"}, HDL_parameter::numeric_parameter, 4},
            {"modulo_expr_p", {"simple_numeric_p","%", "sv_numeric_p"}, HDL_parameter::numeric_parameter, 0},
            {"chained_expression", {"add_expr_p", "+", "mul_expr_p", "*", "5"}, HDL_parameter::numeric_parameter, 1320},
            {"complex_log_expr_p", { "$clog2", "(","add_expr_p", "+", "2", ")"}, HDL_parameter::numeric_parameter, 6},
            {"parenthesised_expr_p", { "(", "add_expr_p","+", "mul_expr_p",")", "*", "5" }, HDL_parameter::numeric_parameter, 1480}
    };

    Parameters_map check_params= produce_check_components(vect_params);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
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
        {"sv_numeric_p", {"5'o10"}, HDL_parameter::numeric_parameter, 8},
};

    Parameters_map check_params= produce_check_components(vect_params);


    auto par = std::make_shared<HDL_parameter>();
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(37);
    par->set_name("array_parameter_expr_p");
    Expression_component e("array_parameter");
    std::vector<Expression> ai;
    ai.push_back({{Expression_component("sv_numeric_p"), Expression_component("*"), Expression_component("0")}, false});
    e.set_array_index(ai);
    par->add_component(e);
    e = Expression_component("array_parameter");
    par->add_component(Expression_component("+"));
    ai.clear();
    ai.push_back({{Expression_component("1")}, false});
    e.set_array_index(ai);
    par->add_component(e);
    check_params.insert(par);


    par  = std::make_shared<HDL_parameter>();
    par->set_name("array_parameter");
    par->set_type(HDL_parameter::expression_parameter);
    Initialization_list i;
    dimension_t  d;
    d.first_bound ={{Expression_component("31")},false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = true;

    i.add_dimension(d,true);
    d.first_bound = {{Expression_component("1")}, false};
    d.second_bound = {{Expression_component("0")},false};
    d.packed = false;
    i.add_dimension(d, false);

    i.add_item({{Expression_component("32")}, false});
    i.add_item({{Expression_component("5")}, false});
    par->add_initialization_list(i);
    mdarray<int64_t> av;
    av.set_1d_slice({0,0}, {5,32});
    par->set_array_value(av);
    check_params.insert(par);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
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
            {"repetition_size", {"2"}, HDL_parameter::numeric_parameter, 2}
    };

    Parameters_map check_params= produce_check_components(vect_params);

    auto par = std::make_shared<HDL_parameter>();
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(32);
    par->set_name("multidim_array_access");
    Expression_component e = Expression_component("multidim_array_parameter");
    std::vector<Expression> ai;
    ai.push_back({{Expression_component("1")}, false});
    ai.push_back({{Expression_component("0")}, false});
    e.set_array_index(ai);
    par->add_component(e);
    check_params.insert(par);

    par  = std::make_shared<HDL_parameter>();
    par->set_name("multidim_array_parameter");
    par->set_type(HDL_parameter::expression_parameter);
    Initialization_list i;
    dimension_t  d = {{{Expression_component("31")}}, {{Expression_component("0")}}, true};
    i.add_dimension(d,true);
    d = {{{Expression_component("repetition_size"), Expression_component("-"), Expression_component("1")}},{ {Expression_component("0")}}, false};
    i.add_dimension(d, false);
    d = {{{Expression_component("1")}}, {{Expression_component("0")}}, false};
    i.add_dimension(d, false);

    i.open_level();
    i.add_item({{Expression_component("32")}, false});
    i.add_item({{Expression_component("32")}, false});
    i.close_level();
    i.open_level();
    i.add_item({{Expression_component("5")}, false});
    i.add_item({{Expression_component("6")}, false});
    i.close_level();
    par->add_initialization_list(i);

    mdarray<int64_t> av;
    av.set_2d_slice({0}, {{6,5}, {32,32}});
    par->set_array_value(av);
    check_params.insert(par);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
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

            parameter p1 = multi_repetition_parameter[2];
            parameter p2 = mixed_repetition_parameter[1];
            parameter p3 = mixed_repetition_parameter[2];

        endmodule
    )";

    auto parameters = run_test(test_pattern);



    Parameters_map check_params;


    auto par = std::make_shared<HDL_parameter>();
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(1);
    par->set_name("p1");
    Expression_component e = Expression_component("multi_repetition_parameter");
    std::vector<Expression> ai;
    ai.push_back({{Expression_component("2")}, false});
    e.set_array_index(ai);
    par->add_component(e);
    check_params.insert(par);


    par  = std::make_shared<HDL_parameter>();
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(4);
    par->set_name("p2");
    e = Expression_component("mixed_repetition_parameter");
    ai.clear();
    ai.push_back({{Expression_component("1")}, false});
    e.set_array_index(ai);
    par->add_component(e);
    check_params.insert(par);

    par  = std::make_shared<HDL_parameter>();
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(2);
    par->set_name("p3");
    e = Expression_component("mixed_repetition_parameter");
    ai.clear();
    ai.push_back({{Expression_component("2")}, false});
    e.set_array_index(ai);
    par->add_component(e);
    check_params.insert(par);


    ASSERT_TRUE(parameters.contains("p1"));
    ASSERT_EQ(*check_params.get("p1"), *parameters.get("p1"));
    ASSERT_TRUE(parameters.contains("p2"));
    ASSERT_EQ(*check_params.get("p2"), *parameters.get("p2"));
    ASSERT_TRUE(parameters.contains("p3"));
    ASSERT_EQ(*check_params.get("p3"), *parameters.get("p3"));


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
            {"packed_param", {}, HDL_parameter::numeric_parameter, 169}
    };

    Parameters_map check_params= produce_check_components(vect_params);
    auto p = parameters.get("packed_param");
    p->add_initialization_list({}); // clear Initialiation_list because it is not the aim of this test;
    parameters.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}



TEST(parameter_processing, package_processing) {

    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    sv_analyzer analyzer("check_files/test_package.sv");
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];


    Parameter_processor param_proc({},d_store);

    auto parameters = param_proc.process_parameters_map(resource.get_parameters(), resource);

    std::vector<param_check_t> vect_params = {
            {"bus_base", {"32'h43c00000"}, HDL_parameter::numeric_parameter, 0x43c00000},
            {"timebase", {"bus_base"}, HDL_parameter::numeric_parameter, 0x43c00000},
            {"gpio", {"timebase", "+","32'h1000", "*","2", "/","2", "+", "1"}, HDL_parameter::numeric_parameter, 0x43c01001},
            {"scope_mux", {"gpio"}, HDL_parameter::numeric_parameter, 0x43c01001},
            {"out_of_order", {"scope_mux"}, HDL_parameter::numeric_parameter, 0x43c01001},
            {"modulo_parameter", {"3", "%", "2"}, HDL_parameter::numeric_parameter, 1},
            {"subtraction_parameter", {"'o4", "-", "'b10"}, HDL_parameter::numeric_parameter, 2}
    };



    Parameters_map check_map = produce_check_components(vect_params);

    ASSERT_EQ(check_map.size(), parameters.size());

    for(const auto& item:check_map){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_processing, package_parameter_usage) {
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

    auto parameters = p.process_parameters_map(resource.get_parameters(), resource);

    Parameters_map check_params;

    auto param  = std::make_shared<HDL_parameter>();
    param->set_type(HDL_parameter::expression_parameter);
    param->set_name("package_param");
    param->set_value(0x43c00000);
    Expression_component ec("bus_base");
    ec.set_package_prefix("test_package");
    param->add_component(ec);
    check_params.insert(param);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
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
            {"negative_param", {"-", "16'sd32767"}, HDL_parameter::numeric_parameter, -32767}
    };


    Parameters_map check_params= produce_check_components(vect_params);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_processing, negative_number_array_init) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter negative_array_param [1:0] = '{-16'sd32767, 16'sd32767}
        )();

            parameter result_param = negative_array_param[1] - negative_array_param[0];
        endmodule
    )";

    auto parameters = run_test(test_pattern);


    Parameters_map check_params;

    auto par = std::make_shared<HDL_parameter>();
    par->set_name("result_param");
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(-65534);
    Expression_component ec("negative_array_param");
    Expression idx = {{Expression_component("1")}, false};
    ec.add_array_index(idx);
    par->add_component(ec);
    par->add_component(Expression_component("-"));
    ec = Expression_component("negative_array_param");
    idx = {{Expression_component("0")}, false};
    ec.add_array_index(idx);
    par->add_component(ec);

    check_params.insert(par);

    par=std::make_shared<HDL_parameter>();
    par->set_name("negative_array_param");
    par->set_type(HDL_parameter::expression_parameter);
    Initialization_list i;
    dimension_t  d;
    d.first_bound = {{Expression_component("1")}, false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = false;
    i.add_dimension(d, false);

    i.add_item({{Expression_component("-"), Expression_component("16'sd32767")}, false});
    i.add_item({{Expression_component("16'sd32767")}, false});

    par->add_initialization_list(i);
    mdarray<int64_t> av;
    av.set_1d_slice({0,0}, {32767,-32767});
    par->set_array_value(av);
    check_params.insert(par);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_processing, expression_array_init) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter integer expression_array_param [1:0] = '{5+4, 7*6}
        )();

            parameter p1 = expression_array_param[0];
            parameter p2 = expression_array_param[1];
        endmodule
    )";


    auto parameters = run_test(test_pattern);


    Parameters_map check_params;


    auto par = std::make_shared<HDL_parameter>();
    par->set_name("p1");
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(42);
    Expression_component ec("expression_array_param");
    Expression idx = {{Expression_component("0")}, false};
    ec.add_array_index(idx);
    par->add_component(ec);

    check_params.insert(par);

    par=std::make_shared<HDL_parameter>();
    par->set_name("p2");
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(9);
    ec = Expression_component("expression_array_param");
    idx = {{Expression_component("1")}, false};
    ec.add_array_index(idx);
    par->add_component(ec);

    check_params.insert(par);

    par=std::make_shared<HDL_parameter>();
    par->set_name("expression_array_param");
    par->set_type(HDL_parameter::expression_parameter);
    Initialization_list i;
    dimension_t  d;
    d.first_bound = {{Expression_component("1")}, false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = false;

    i.add_dimension(d, false);

    i.add_item({{Expression_component("5"), Expression_component("+"), Expression_component("4")}, false});
    i.add_item({{Expression_component("7"), Expression_component("*"), Expression_component("6")}, false});

    mdarray<int64_t> av;
    av.set_1d_slice({0,0}, {42,9});
    par->set_array_value(av);

    par->add_initialization_list(i);
    check_params.insert(par);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_processing, mixed_packed_unpacked_init) {
    std::string test_pattern = R"(
    module test_mod #(
      parameter reg [7:0] param_a [1:0] = '{{1'b1,1'b1,1'b1,1'b0,1'b0,1'b0,1'b1,1'b0}, {1'b0,1'b0,1'b0,1'b1,1'b1,1'b1,1'b0,1'b1}},
      parameter reg [7:0] param_b [1:0] = '{{8{1'b1}},{8{1'b0}}}
    )();


        parameter p1 = param_a[0];
        parameter p2 = param_a[1];
        parameter p3 = param_b[0];
        parameter p4 = param_b[1];

    endmodule
    )";


    auto parameters = run_test(test_pattern);

    std::vector<param_check_t> vect_params = {
            {"param_a_0", {"29"}, HDL_parameter::numeric_parameter, 29},
            {"param_a_1", {"226"}, HDL_parameter::numeric_parameter, 226},
            {"param_b_0", {"0"}, HDL_parameter::numeric_parameter, 0},
            {"param_b_1", {"255"}, HDL_parameter::numeric_parameter, 255}
    };
    Parameters_map check_params;

    auto par = std::make_shared<HDL_parameter>();
    par->set_name("p1");
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(29);
    Expression_component ec("param_a");
    Expression idx = {{Expression_component("0")}, false};
    ec.add_array_index(idx);
    par->add_component(ec);
    check_params.insert(par);

    par  = std::make_shared<HDL_parameter>();
    par->set_name("p2");
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(226);
    ec = Expression_component ("param_a");
    idx = {{Expression_component("1")}, false};
    ec.add_array_index(idx);
    par->add_component(ec);

    check_params.insert(par);

    par  = std::make_shared<HDL_parameter>();
    par->set_name("p3");
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(0);
    ec = Expression_component ("param_b");
    idx = {{Expression_component("0")}, false};
    ec.add_array_index(idx);
    par->add_component(ec);

    check_params.insert(par);

    par  = std::make_shared<HDL_parameter>();
    par->set_name("p4");
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(255);
    ec = Expression_component ("param_b");
    idx = {{Expression_component("1")}, false};
    ec.add_array_index(idx);
    par->add_component(ec);

    check_params.insert(par);


    ASSERT_TRUE(parameters.contains("p1"));
    ASSERT_EQ(*parameters.get("p1"), *check_params.get("p1"));


    ASSERT_TRUE(parameters.contains("p2"));
    ASSERT_EQ(*parameters.get("p2"), *check_params.get("p2"));


    ASSERT_TRUE(parameters.contains("p3"));
    ASSERT_EQ(*parameters.get("p3"), *check_params.get("p3"));


    ASSERT_TRUE(parameters.contains("p4"));
    ASSERT_EQ(*parameters.get("p4"), *check_params.get("p4"));

}



Parameters_map run_override_test(const std::string & t_p, const Parameters_map& parent){

    sv_analyzer analyzer(std::make_shared<std::istringstream>(t_p));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor p(parent, std::make_shared<data_store>(true, "/tmp/test_data_store"));

    auto params = p.process_parameters_map( resource.get_parameters(), resource);
    return params;

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
                parameter div_expr_p = simple_numeric_p  / sv_numeric_p;
                parameter modulo_expr_p = simple_numeric_p % sv_numeric_p;
                parameter chained_expression = add_expr_p + mul_expr_p  * 5;
                parameter complex_log_expr_p = $clog2(add_expr_p+2);
                parameter simple_log_expr_p = $clog2(add_expr_p);
                parameter parenthesised_expr_p = ( add_expr_p + mul_expr_p ) * 5;
            endmodule
        )";

    Parameters_map parent_param;

    auto par = std::make_shared<HDL_parameter>();
    par->set_name("simple_numeric_p");
    par->add_component(Expression_component("15"));
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(15);
    parent_param.insert(par);

    par  = std::make_shared<HDL_parameter>();
    par->set_name("sv_numeric_p");
    par->add_component(Expression_component("2"));
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(2);
    parent_param.insert(par);


    auto parameters = run_override_test(test_pattern, parent_param);

    std::vector<param_check_t> vect_params = {
            {"simple_numeric_p", {"15"}, HDL_parameter::numeric_parameter, 15},
            {"sv_numeric_p", {"2"}, HDL_parameter::numeric_parameter, 2},
            {"simple_log_expr_p", {"$clog2", "(", "add_expr_p", ")"}, HDL_parameter::numeric_parameter, 5},
            {"add_expr_p", {"simple_numeric_p", "+", "sv_numeric_p"}, HDL_parameter::numeric_parameter,17},
            {"sub_expr_p", {"simple_numeric_p","-", "sv_numeric_p"}, HDL_parameter::numeric_parameter,13},
            {"mul_expr_p", {"simple_numeric_p","*", "sv_numeric_p"}, HDL_parameter::numeric_parameter, 30},
            {"div_expr_p", {"simple_numeric_p","/", "sv_numeric_p"}, HDL_parameter::numeric_parameter, 7},
            {"modulo_expr_p", {"simple_numeric_p","%", "sv_numeric_p"}, HDL_parameter::numeric_parameter, 1},
            {"chained_expression", {"add_expr_p", "+", "mul_expr_p", "*", "5"}, HDL_parameter::numeric_parameter, 167},
            {"complex_log_expr_p", { "$clog2", "(","add_expr_p", "+", "2", ")"}, HDL_parameter::numeric_parameter, 5},
            {"parenthesised_expr_p", { "(", "add_expr_p","+", "mul_expr_p",")", "*", "5" }, HDL_parameter::numeric_parameter, 235}
    };

    Parameters_map check_params= produce_check_components(vect_params);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
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

    Parameters_map parent_param;

    auto par = std::make_shared<HDL_parameter>();
    par->set_name("array_parameter");
    par->add_component(Expression_component("22"));
    par->set_type(HDL_parameter::expression_parameter);
    Initialization_list il;
    dimension_t d;
    d.first_bound = {{Expression_component("31")}, false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = true;
    il.add_dimension(d, true);
    d.first_bound = {{Expression_component("1")}, false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = false;
    il.add_dimension(d, false);
    il.add_item({{Expression_component("2")}, false});
    il.add_item({{Expression_component("22")}, false});
    par->add_initialization_list(il);
    mdarray<int64_t> av;
    av.set_1d_slice({0,0}, {2,22});
    par->set_array_value(av);
    parent_param.insert(par);

    auto parameters = run_override_test(test_pattern, parent_param);


    std::vector<param_check_t> vect_params = {
            {"sv_numeric_p", {"5'o10"}, HDL_parameter::numeric_parameter, 8}
    };

    Parameters_map check_params= produce_check_components(vect_params);


    par  = std::make_shared<HDL_parameter>();
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(24);
    par->set_name("array_parameter_expr_p");
    Expression_component ec =Expression_component("array_parameter");
    Expression e;
    std::vector<Expression> ai;
    e.emplace_back("sv_numeric_p"); e.emplace_back("*"); e.emplace_back("0");
    ai.push_back(e);
    ec.set_array_index(ai);
    par->add_component(ec);
    par->add_component(Expression_component("+"));
    ec = Expression_component("array_parameter");
    ai.clear();
    e.components = {Expression_component("1")};
    ai.push_back(e);
    ec.set_array_index(ai);
    par->add_component(ec);
    check_params.insert(par);


    par  = std::make_shared<HDL_parameter>();
    par->set_name("array_parameter");
    par->set_type(HDL_parameter::expression_parameter);
    par->set_expression_components({{Expression_component("22")}, false});
    av = mdarray<int64_t>();
    av.set_1d_slice({0,0}, {2,22});
    par->set_array_value(av);
    par->add_initialization_list(il);
    check_params.insert(par);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_processing, repetition_array_override) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter repetition_size = 2,
            parameter bit repetition_parameter_a [repetition_size-1:0]  = '{repetition_size{1}}
        )();
            parameter p1 = repetition_parameter_a[2];
        endmodule
    )";

    Parameters_map parent_param;

    auto par = std::make_shared<HDL_parameter>();
    par->set_name("repetition_size");
    par->add_component(Expression_component("3"));
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(3);
    parent_param.insert(par);

    auto parameters = run_override_test(test_pattern, parent_param);

    std::vector<param_check_t> vect_params = {
            {"repetition_size", {"3"}, HDL_parameter::numeric_parameter, 3}
    };

    Parameters_map check_params;


    par  = std::make_shared<HDL_parameter>();
    par->set_type(HDL_parameter::numeric_parameter);
    par->set_value(1);
    par->set_name("p1");
    Expression_component e = Expression_component("repetition_parameter_a");
    std::vector<Expression> ai;
    ai.push_back({{Expression_component("2")}, false});
    e.set_array_index(ai);
    Initialization_list il;
    par->add_component(e);
    check_params.insert(par);

    ASSERT_TRUE(parameters.contains("p1"));
    ASSERT_EQ(*parameters.get("p1"), *check_params.get("p1"));

}


TEST(parameter_processing, array_instance_parameter_override) {
    std::string test_pattern = R"(
        module dependency #(
            parameter param_1 = 4,
            parameter param_2 [1:0]= '{0,0},
            param_3 = 6
        )();

            parameter p1_t = param_2[0];
            parameter p2_t = param_2[1];

        endmodule

        module test_mod #(
            parameter test_param = 4
        )();

            localparam override_array [1:0] = '{8,9};

            dependency #(
                .param_1(test_param),
                .param_2(override_array),
                .param_3((test_param + 7)*1)
            ) test_instance ();

        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));

    analyzer.cleanup_content("`(.*)");
    auto resources = analyzer.analyze();
    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    d_store->store_hdl_entity(resources[0]);
    d_store->store_hdl_entity(resources[1]);

    Parameter_processor p({}, d_store);
    auto top_res= d_store->get_HDL_resource("test_mod");
    auto parent_parameters = p.process_parameters_map(top_res.get_parameters(), top_res);

    auto instance_spec = d_store->get_HDL_resource("dependency");

    p = Parameter_processor(parent_parameters, d_store);

    auto parent_params = top_res.get_dependencies()[0].get_parameters();
    auto instance_parameters = p.process_parameters_map(parent_params, instance_spec);

    p = Parameter_processor(instance_parameters, d_store);

    auto dependency_params = p.process_parameters_map(instance_spec.get_parameters(), instance_spec);

    std::vector<param_check_t> vect_params = {
            {"param_1", {"test_param"}, HDL_parameter::numeric_parameter, 4},
            {"p1_t", {"param_2"}, HDL_parameter::numeric_parameter, 9},
            {"p2_t", {"param_2"}, HDL_parameter::numeric_parameter, 8},
            {"param_3", {"(", "test_param", "+", "7", ")", "*", "1"}, HDL_parameter::numeric_parameter, 11}
    };

    Parameters_map check_params= produce_check_components(vect_params);

    auto param = check_params.get("p1_t");
    auto ec = param->get_expression_components();
    std::vector<Expression> index;
    index.push_back({{Expression_component("0")}, false});
    ec.components[0].set_array_index(index);
    param->set_expression_components(ec);
    check_params.insert(param);

     param = check_params.get("p2_t");
    ec = param->get_expression_components();
    index.clear();
    index.push_back({{Expression_component("1")}});
    ec.components[0].set_array_index(index);
    param->set_expression_components(ec);
    check_params.insert(param);

    auto par = std::make_shared<HDL_parameter>();
    par->set_name("param_2");
    par->set_expression_components({{Expression_component("override_array")}, false});
    mdarray<int64_t> av;
    av.set_1d_slice({0,0}, {9,8});
    par->set_array_value(av);

    check_params.insert(par);
    ASSERT_EQ(check_params.size(), dependency_params.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(dependency_params.contains(item->get_name()));
        ASSERT_EQ(*item, *dependency_params.get(item->get_name()));
    }

}



TEST(parameter_processing, string_parameter) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter string_param = "TEST PARAM"
        )();

        endmodule
    )";

    Parameters_map parent_param;


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor p({}, std::make_shared<data_store>(true, "/tmp/test_data_store"));
    auto parameters = p.process_parameters_map(resource.get_parameters(), resource);

    auto check_param = std::make_shared<HDL_parameter>();
    check_param->set_value("TEST PARAM");
    check_param->set_name("string_param");
    check_param->add_component({Expression_component("\"TEST PARAM\"")});

    ASSERT_EQ(*check_param, *parameters.get("string_param"));

}

TEST(parameter_processing, string_parameter_map_processing) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter string_param = "TEST PARAM"
        )();

        endmodule
    )";

    Parameters_map parent_param;


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor p({}, std::make_shared<data_store>(true, "/tmp/test_data_store"));
    auto params = resource.get_parameters();

    auto parameters = p.process_parameters_map(params, resource);

    auto check_param = std::make_shared<HDL_parameter>();
    check_param->set_value("TEST PARAM");
    check_param->set_name("string_param");
    check_param->add_component({Expression_component("\"TEST PARAM\"")});

    ASSERT_EQ(*check_param, *parameters.get("string_param"));

}



TEST(parameter_processing, packed_replication_init) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter [4:0] test_parameter = {5{1'b1}}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor p({}, std::make_shared<data_store>(true, "/tmp/test_data_store"));
    auto parameters = p.process_parameters_map(resource.get_parameters(), resource);

    Parameters_map check_params;

    auto check_param = std::make_shared<HDL_parameter>();
    check_param->set_name("test_parameter");
    check_param->set_value(31);

    Initialization_list i;
    dimension_t d;
    d.first_bound = {{Expression_component("4")}, false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = true;
    i.add_dimension(d, true);
    i.add_item({{Expression_component("$repeat_init"),Expression_component("5"),Expression_component(","),Expression_component("1'b1")}, false});

    check_param->add_initialization_list(i);


    ASSERT_EQ(*check_param, *parameters.get("test_parameter"));
}

TEST(parameter_processing, array_initialization_default) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter p_1 = 5,
            parameter p_2 = 4,
            parameter [4:0] test_parameter [2:0][1:0] = '{default:p_1+p_2}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor proc({}, std::make_shared<data_store>(true, "/tmp/test_data_store"));

    auto parameters = proc.process_parameters_map(resource.get_parameters(), resource);

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_name("test_parameter");
    p->set_type(HDL_parameter::expression_parameter);
    Initialization_list i;
    dimension_t d;
    d.first_bound = {{Expression_component("4")}, false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = true;
    i.add_dimension(d, true);
    d.first_bound = {{Expression_component("2")}, false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = false;
    i.add_dimension(d, false);
    d.first_bound = {{Expression_component("1")}, false};
    d.second_bound = {{Expression_component("0")}, false};
    d.packed = false;
    i.add_dimension(d, false);
    i.add_item({{Expression_component("p_1"), Expression_component("+"), Expression_component("p_2")}});
    i.set_default();
    p->add_initialization_list(i);
    mdarray<int64_t> array;
    array.set_data({{{9,9},{9,9},{9,9}}});

    p->set_array_value(array);
    check_params.insert(p);


    p  = std::make_shared<HDL_parameter>();
    p->set_name("p_1");
    p->set_value(5);
    p->add_component({Expression_component("5")});
    check_params.insert(p);

    p  = std::make_shared<HDL_parameter>();
    p->set_name("p_2");
    p->set_value(4);
    p->add_component({Expression_component("4")});
    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_processing, packed_array_initialization_expression_override) {
    std::string test_pattern = R"(

        module dependency #(
            N_TRIGGER_REGISTERS = 1,
            parameter [31:0] TRIGGER_REGISTERS_IDX [N_TRIGGER_REGISTERS-1:0] = '{N_TRIGGER_REGISTERS{0}}
        )();
            parameter p1_t = TRIGGER_REGISTERS_IDX[0];
        endmodule

        module test_mod #(
        )();

            parameter TAP_ADDR_REG = 5;
            dependency #(
                .TRIGGER_REGISTERS_IDX('{TAP_ADDR_REG})
            ) d ();
        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));

    analyzer.cleanup_content("`(.*)");
    auto resources = analyzer.analyze();
    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    d_store->store_hdl_entity(resources[0]);
    d_store->store_hdl_entity(resources[1]);

    Parameter_processor p({}, d_store);
    auto top_res= d_store->get_HDL_resource("test_mod");
    auto parent_parameters = p.process_parameters_map(top_res.get_parameters(), top_res);

    p = Parameter_processor(parent_parameters, d_store);

    auto instance_spec = d_store->get_HDL_resource("dependency");

    auto parent_params = top_res.get_dependencies()[0].get_parameters();
    auto instance_parameters = p.process_parameters_map(parent_params, instance_spec);

    p = Parameter_processor(instance_parameters, d_store);

    auto res = d_store->get_HDL_resource("dependency");
    auto dependency_params = p.process_parameters_map(res.get_parameters(), res);



    auto array_val = dependency_params.get("TRIGGER_REGISTERS_IDX")->get_array_value();
    ASSERT_EQ(array_val.get_value({0,0,0}), 5);

}


TEST(parameter_processing, simple_for_array_parameter) {
    std::string test_pattern = R"(

        module dependency #(
            N_TRIGGER_REGISTERS = 1
        )();
        endmodule

        module test_mod #(
        )();

            parameter  [31:0] TAP_ADDR_REG [2:0] = '{6,2,4};
            generate
                for(n = 0; n<3; n=n+1)begin
                    dependency #(
                        .N_TRIGGER_REGISTERS(TAP_ADDR_REG[n])
                    ) d ();
                end
            endgenerate
        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));

    analyzer.cleanup_content("`(.*)");
    auto resources = analyzer.analyze();
    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    d_store->store_hdl_entity(resources[0]);
    d_store->store_hdl_entity(resources[1]);


    Depfile df;
    HDL_ast_builder b(s_store, d_store, df);
    auto ast = b.build_ast(std::vector<std::string>({"test_mod"}), {})[0];
    auto deps = ast->get_dependencies();
    ASSERT_EQ(deps[0]->get_parameters().get("N_TRIGGER_REGISTERS")->get_numeric_value(), 4);
    ASSERT_EQ(deps[1]->get_parameters().get("N_TRIGGER_REGISTERS")->get_numeric_value(), 2);
    ASSERT_EQ(deps[2]->get_parameters().get("N_TRIGGER_REGISTERS")->get_numeric_value(), 6);

}


TEST(parameter_processing, complex_for_array_parameter) {
    std::string test_pattern = R"(

        module dependency #(
            N_TRIGGER_REGISTERS = 1
        )();
        endmodule

        module test_mod #(
        )();

            parameter  [31:0] TAP_ADDR_REG [2:0] = '{6,2,4};

            parameter  TEST_PARAM = 1;

            generate
                for(n = 0; n<3; n=n+1)begin
                    dependency #(
                        .N_TRIGGER_REGISTERS(TAP_ADDR_REG[(TEST_PARAM+1)-n])
                    ) d ();
                end
            endgenerate
        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));

    analyzer.cleanup_content("`(.*)");
    auto resources = analyzer.analyze();
    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    d_store->store_hdl_entity(resources[0]);
    d_store->store_hdl_entity(resources[1]);


    Depfile df;
    HDL_ast_builder b(s_store, d_store, df);
    auto ast = b.build_ast(std::vector<std::string>({"test_mod"}), {})[0];
    auto deps = ast->get_dependencies();
    ASSERT_EQ(deps[0]->get_parameters().get("N_TRIGGER_REGISTERS")->get_numeric_value(), 6);
    ASSERT_EQ(deps[1]->get_parameters().get("N_TRIGGER_REGISTERS")->get_numeric_value(), 2);
    ASSERT_EQ(deps[2]->get_parameters().get("N_TRIGGER_REGISTERS")->get_numeric_value(), 4);

}

TEST(parameter_processing, scalar_function_parameter) {
    std::string test_pattern = R"(


        module test_mod #(
        )();

            parameter ADDR_WIDTH = 32;
            parameter N_AXI_LITE = 3;


            function logic [ADDR_WIDTH-1:0] CTRL_ADDR_CALC();
                CTRL_ADDR_CALC = 100;
            endfunction

            parameter [ADDR_WIDTH-1:0] AXI_ADDRESSES [N_AXI_LITE-1:0] = CTRL_ADDR_CALC();

        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor proc({}, std::make_shared<data_store>(true, "/tmp/test_data_store"));

    auto parameters = proc.process_parameters_map(resource.get_parameters(), resource);

    auto param = parameters.get("AXI_ADDRESSES");
    ASSERT_EQ(param->get_type(), HDL_parameter::numeric_parameter);
    ASSERT_EQ(param->get_numeric_value(), 100);

}

TEST(parameter_processing, simple_vector_function_parameter) {
    std::string test_pattern = R"(


        module test_mod #(
        )();

            parameter ADDR_WIDTH = 32;
            parameter N_AXI_LITE = 3;


            typedef logic [ADDR_WIDTH-1:0] ctrl_addr_init_t [N_AXI_LITE];
            function ctrl_addr_init_t CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = 100;
                CTRL_ADDR_CALC[1] = 200;
                CTRL_ADDR_CALC[2] = 300;
            endfunction

            parameter [ADDR_WIDTH-1:0] AXI_ADDRESSES [N_AXI_LITE-1:0] = CTRL_ADDR_CALC();

        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];


    Parameter_processor proc({}, std::make_shared<data_store>(true, "/tmp/test_data_store"));

    auto parameters = proc.process_parameters_map(resource.get_parameters(), resource);

    auto param = parameters.get("AXI_ADDRESSES");
    auto param_value = param->get_array_value().get_1d_slice({0, 0});
    mdarray<int64_t>::md_1d_array reference = {300, 200, 100};
    ASSERT_EQ(param_value, reference);
}


TEST(parameter_processing, loop_vector_function_parameter) {
    std::string test_pattern = R"(


        module test_mod #(
            N_CORES = 3
        )();

            parameter ADDR_WIDTH = 32;
            parameter N_AXI_LITE = 3;


            typedef logic [ADDR_WIDTH-1:0] ctrl_addr_init_t [N_AXI_LITE];
            function ctrl_addr_init_t CTRL_ADDR_CALC();
                for(int i = 0; i<N_CORES; i++)begin
                    CTRL_ADDR_CALC[N_CORES-1-i] = 100*i;
                end
            endfunction

            parameter [ADDR_WIDTH-1:0] AXI_ADDRESSES [N_AXI_LITE-1:0] = CTRL_ADDR_CALC();

        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor proc({}, std::make_shared<data_store>(true, "/tmp/test_data_store"));

    auto parameters = proc.process_parameters_map(resource.get_parameters(), resource);

    auto param = parameters.get("AXI_ADDRESSES");
    auto param_value = param->get_array_value().get_1d_slice({0, 0});
    mdarray<int64_t>::md_1d_array reference = {0, 100, 200};
    ASSERT_EQ(param_value, reference);
}


TEST(parameter_processing, complex_vector_function_parameter) {
    std::string test_pattern = R"(
        module test_mod #(
            N_CORES = 3
        )();

            parameter ADDR_WIDTH = 32;
            parameter N_AXI_LITE = 3;


            typedef logic [ADDR_WIDTH-1:0] ctrl_addr_init_t [N_AXI_LITE];
            function ctrl_addr_init_t CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = 44;
                for(int i = 1; i<N_CORES+1; i++)begin
                    CTRL_ADDR_CALC[i] = 100*i;
                end
                CTRL_ADDR_CALC[4] = 667;
            endfunction

            parameter [ADDR_WIDTH-1:0] AXI_ADDRESSES [N_AXI_LITE-1:0] = CTRL_ADDR_CALC();

        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    Parameter_processor proc({}, std::make_shared<data_store>(true, "/tmp/test_data_store"));

    auto parameters = proc.process_parameters_map(resource.get_parameters(), resource);

    auto param = parameters.get("AXI_ADDRESSES");
    auto param_value = param->get_array_value().get_1d_slice({0, 0});
    mdarray<int64_t>::md_1d_array reference = {667, 300, 200, 100, 44};
    ASSERT_EQ(param_value, reference);

}


TEST(parameter_processing, simple_package_in_function_initialization) {
    std::string test_pattern = R"(



        package hil_address_space;

            parameter bus_base = 32'h43c00000;

        endpackage


        module test_mod #(
            parameter ADDR_WIDTH = 32,
            parameter N_CORES = 3
        )();

            localparam N_AXI_LITE = N_CORES+3;
            localparam BASE_ADDR = 32'h43c00000 + 'h30000;

            typedef logic [ADDR_WIDTH-1:0] ctrl_addr_init_t [N_AXI_LITE];
            function ctrl_addr_init_t CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = hil_address_space::bus_base;
                CTRL_ADDR_CALC[1] = BASE_ADDR + 4;
            endfunction

            localparam [ADDR_WIDTH-1:0] AXI_ADDRESSES [N_AXI_LITE-1:0] = CTRL_ADDR_CALC();

        endmodule


    )";



    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");

    auto ds = std::make_shared<data_store>(true, "/tmp/test_data_store");
    auto resources = analyzer.analyze();
    ds->store_hdl_entity(resources[0]);
    ds->store_hdl_entity(resources[1]);
    Parameter_processor proc({}, ds);

    auto parameters = proc.process_parameters_map(resources[1].get_parameters(), resources[1]);

    auto param = parameters.get("AXI_ADDRESSES");
    auto param_value = param->get_array_value().get_1d_slice({0, 0});
    mdarray<int64_t>::md_1d_array reference = {0x43c30004,0x43c00000};
    ASSERT_EQ(param_value, reference);
}


TEST(parameter_processing, nested_package_in_function_initialization) {
    std::string test_pattern = R"(

        package hil_address_space;
            parameter bus_base = 32'h43c00000;
        endpackage


        module test_mod #(
            parameter ADDR_WIDTH = 32,
            parameter N_CORES = 3
        )();

            localparam N_AXI_LITE = N_CORES+3;
            localparam BASE_ADDR = hil_address_space::bus_base + 'h30000;

            typedef logic [ADDR_WIDTH-1:0] ctrl_addr_init_t [N_AXI_LITE];
            function ctrl_addr_init_t CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = hil_address_space::bus_base;
                CTRL_ADDR_CALC[1] = BASE_ADDR + 4;
            endfunction

            localparam [ADDR_WIDTH-1:0] AXI_ADDRESSES [N_AXI_LITE-1:0] = CTRL_ADDR_CALC();

        endmodule


    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");

    auto ds = std::make_shared<data_store>(true, "/tmp/test_data_store");
    auto resources = analyzer.analyze();
    ds->store_hdl_entity(resources[0]);
    ds->store_hdl_entity(resources[1]);
    Parameter_processor proc({}, ds);

    auto parameters = proc.process_parameters_map(resources[1].get_parameters(), resources[1]);

    auto param = parameters.get("AXI_ADDRESSES");
    auto param_value = param->get_array_value().get_1d_slice({0, 0});
    mdarray<int64_t>::md_1d_array reference = {0x43c30004,0x43c00000};
    ASSERT_EQ(param_value, reference);
}

TEST(parameter_processing, override_with_function_parameter) {
    std::string test_pattern = R"(

        module dependency #(
            parameter param_1 = 4
        )();

            parameter p1_t = param_1+2;

        endmodule

        module test_mod #(
        )();

            parameter ADDR_WIDTH = 32;
            parameter N_AXI_LITE = 3;


            function logic [ADDR_WIDTH-1:0] CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = 100;
                CTRL_ADDR_CALC[1] = 130;
                CTRL_ADDR_CALC[2] = 356;
            endfunction

            parameter FUNCTION_PARAM = CTRL_ADDR_CALC();


            dependency #(
                .param_1(FUNCTION_PARAM[2])
            ) dep ();

        endmodule
    )";



    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resources = analyzer.analyze();

    d_store->store_hdl_entity(resources[0]);
    d_store->store_hdl_entity(resources[1]);

    nlohmann::json df_content;

    Depfile df;
    df.set_content(df_content);

    HDL_ast_builder b(s_store, d_store, df);
    auto synth_ast = b.build_ast(std::vector<std::string>({"test_mod"}), {})[0];


    auto params = synth_ast->get_dependencies()[0]->get_parameters();
    auto param_1 = params.get("param_1");
    EXPECT_EQ(param_1->get_numeric_value(), 100);
    auto p1_t = params.get("p1_t");
    EXPECT_EQ(p1_t->get_numeric_value(), 102);
}



TEST(parameter_processing, parameter_with_for_loop) {
    std::string test_pattern = R"(

        module dependency #(
            parameter DMA_BASE_ADDRESS = 4
        )();

            parameter p1_t = DMA_BASE_ADDRESS+2;

        endmodule

        module test_mod #(
            parameter N_CORES = 2
        )();

            function logic [ADDR_WIDTH-1:0] CTRL_ADDR_CALC();
                CTRL_ADDR_CALC[0] = 100;
                CTRL_ADDR_CALC[1] = 130;
                CTRL_ADDR_CALC[2] = 356;
                CTRL_ADDR_CALC[3] = 62;
            endfunction

            parameter AXI_ADDRESSES = CTRL_ADDR_CALC();

            for(n = 0; n<N_CORES; n=n+1)begin
                dependency #(
                    .DMA_BASE_ADDRESS(AXI_ADDRESSES[(N_CORES+1)-n])
                ) dep ();
            end
        endmodule
    )";



    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resources = analyzer.analyze();

    d_store->store_hdl_entity(resources[0]);
    d_store->store_hdl_entity(resources[1]);

    nlohmann::json df_content;

    Depfile df;
    df.set_content(df_content);

    HDL_ast_builder b(s_store, d_store, df);
    auto synth_ast = b.build_ast(std::vector<std::string>({"test_mod"}), {})[0];

    auto deps = synth_ast->get_dependencies();

    std::vector<uint32_t> param_1;
    std::vector<uint32_t> p1_t;

    for(auto dep : deps) {
        auto p = dep->get_parameters();
        param_1.push_back(p.get("DMA_BASE_ADDRESS")->get_numeric_value());
        p1_t.push_back(p.get("p1_t")->get_numeric_value());
    }

    std::vector<uint32_t> expected_param_1 = {100, 130};
    EXPECT_EQ(param_1, expected_param_1);
    std::vector<uint32_t> expected_p1_t = {102, 132};
    EXPECT_EQ(p1_t, expected_p1_t);

}



TEST(parameter_processing, parent_parameter_collision) {
    std::string test_pattern = R"(

        module inner_dep();

        endmodule

        module dependency #(
            INNER_PARAMETER = 1
        )();
            for(n = 0; n<INNER_PARAMETER; n=n+1)begin
                inner_dep #() dep ();
            end
        endmodule

        module test_mod #(
        )();

            parameter  [31:0] INNER_PARAMETER [2:0] = '{6,2,4};
            dependency #(
                .INNER_PARAMETER(2)
            ) d ();
        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));

    analyzer.cleanup_content("`(.*)");
    auto resources = analyzer.analyze();
    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    d_store->store_hdl_entity(resources[0]);
    d_store->store_hdl_entity(resources[1]);
    d_store->store_hdl_entity(resources[2]);



    Depfile df;
    HDL_ast_builder b(s_store, d_store, df);
    auto ast = b.build_ast(std::vector<std::string>({"test_mod"}), {})[0];
    auto deps = ast->get_dependencies();
    ASSERT_EQ(deps[0]->get_parameters().get("INNER_PARAMETER")->get_numeric_value(), 5);

}