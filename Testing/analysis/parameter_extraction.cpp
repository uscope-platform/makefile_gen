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


#include <memory_resource>
#include <gtest/gtest.h>

#include "frontend/analysis/sv_analyzer.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"

typedef struct{
    std::vector<std::variant<std::vector<Expression>, std::vector<Concatenation>>> values;
    std::vector<dimension_t> dimensions;
}init_list_t;

Initialization_list produce_check_init_list_1d(const init_list_t &i){
    Initialization_list il;
    for(auto &item:i.dimensions){
        il.add_dimension(item, item.packed);
    }


    for(const auto &item:i.values){
        if (std::holds_alternative<std::vector<Expression>>(item)) {
            auto expressions = std::get<std::vector<Expression>>(item);
            for( auto &expr:expressions){
                il.add_item(expr);
            }
        } else {
            auto concatenations = std::get<std::vector<Concatenation>>(item);
            for( auto &expr:concatenations){
                il.add_item(expr);
            }
        }

    }

    return  il;
}


Initialization_list produce_check_init_list(const init_list_t &i){
    Initialization_list il;
    for(auto &item:i.dimensions){
        il.add_dimension(item, item.packed);
    }
    for(const auto &item:i.values){
        il.open_level();
        if (std::holds_alternative<std::vector<Expression>>(item)) {
            auto expressions = std::get<std::vector<Expression>>(item);
            for( auto &expr:expressions){
                il.add_item(expr);
            }
        } else {
            auto concatenations = std::get<std::vector<Concatenation>>(item);
            for( auto &expr:concatenations){
                il.add_item(expr);
            }
        }
        il.close_level();
    }

    return  il;
}


TEST(parameter_extraction, simple_parameters) {
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

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"simple_numeric_p", {"32"}},
            {"local_p", {"74"}},
            {"sv_numeric_p", {"5'o10"}},
            {"dimensionless_sv_numeric_p", {"'h3F"}},
            {"string_p", {R"("423")"}},
            {"nested_p", {"string_p"}}
    };


    for(auto &item:  vect_params){
        auto p = std::make_shared<HDL_parameter>();
        p->set_type(HDL_parameter::expression_parameter);
        p->set_name(item.first);
        for(auto &op:item.second){
            p->add_component(Expression_component(op));
        }
        check_params.insert(p);
    }

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();
    std::map<std::string, resolved_parameter> check_defaults = {
        {"simple_numeric_p", 32},
        {"local_p", 74},
        {"sv_numeric_p", 8},
        {"dimensionless_sv_numeric_p", 63},
        {"string_p", R"("423")"},
        {"nested_p", R"("423")"}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(parameter_extraction, simple_expressions) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter simple_numeric_p = 32,
            sv_numeric_p = 5'o10,
            dimensionless_sv_numeric_p  = 'h3F
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

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"simple_numeric_p", {"32"}},
            {"sv_numeric_p", {"5'o10"}},
            {"dimensionless_sv_numeric_p", {"'h3F"}},
            {"simple_log_expr_p", {"$clog2", "(", "add_expr_p",")"}},
            {"add_expr_p", {"simple_numeric_p", "+", "sv_numeric_p"}},
            {"sub_expr_p", {"simple_numeric_p", "-", "sv_numeric_p"}},
            {"mul_expr_p", {"simple_numeric_p", "*", "sv_numeric_p"}},
            {"div_expr_p", {"simple_numeric_p", "/", "sv_numeric_p"}},
            {"chained_expression", {"add_expr_p",  "+",  "mul_expr_p", "*", "5"}},
            {"modulo_expr_p", {"simple_numeric_p", "%", "sv_numeric_p"}},
            {"complex_log_expr_p", {"$clog2", "(", "add_expr_p", "+", "2",")"}},
            {"parenthesised_expr_p", { "(", "add_expr_p", "+", "mul_expr_p",")", "*", "5"}},
    };

    for(auto &item:  vect_params){
        auto p = std::make_shared<HDL_parameter>();
        p->set_type(HDL_parameter::expression_parameter);
        p->set_name(item.first);
        for(auto &op:item.second){
            p->add_component(Expression_component(op));
        }
        check_params.insert(p);
    }


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        EXPECT_TRUE(parameters.contains(item->get_name()));
        EXPECT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();
    std::map<std::string, resolved_parameter> check_defaults = {
        {"simple_numeric_p", 32},
        {"sv_numeric_p", 8},
        {"dimensionless_sv_numeric_p", 63},
        {"simple_log_expr_p",6},
        {"add_expr_p", 40},
        {"sub_expr_p", 24},
        {"mul_expr_p", 256},
        {"div_expr_p", 4},
        {"chained_expression", 1320},
        {"modulo_expr_p", 0},
        {"complex_log_expr_p", 6},
        {"parenthesised_expr_p", 1480}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}


TEST(parameter_extraction, assay_assignment) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter simple_numeric_p = 32,
            sv_numeric_p = 5'o10
        )();
            parameter logic [31:0] concatenation [1:0] = '{simple_numeric_p, sv_numeric_p};

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"simple_numeric_p", {"32"}},
            {"sv_numeric_p", {"5'o10"}}
    };


    for(auto &item:  vect_params){
        auto p = std::make_shared<HDL_parameter>();
        p->set_type(HDL_parameter::expression_parameter);
        p->set_name(item.first);
        for(auto &op:item.second){
            p->add_component(Expression_component(op));
        }
        check_params.insert(p);
    }

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("concatenation");

    Initialization_list il;
    il.add_dimension({{Expression_component("31")}, {Expression_component("0")}, true}, true);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}, false}, false);

    il.add_item(Expression({Expression_component("simple_numeric_p")}));
    il.add_item(Expression({Expression_component("sv_numeric_p")}));


    p->add_initialization_list(il);



    check_params.insert(p);


   ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        EXPECT_TRUE(parameters.contains(item->get_name()));
        EXPECT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();

    mdarray<int64_t> av;
    av.set_1d_slice({0, 0}, {8, 32});

    std::map<std::string, resolved_parameter> check_defaults = {
        {"simple_numeric_p", 32},
        {"sv_numeric_p", 8},
        {"concatenation", av}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}


TEST(parameter_extraction, default_assign) {
    std::string test_pattern = R"(
        module test_mod #(
        )();
            parameter logic [31:0] test_array [1:0] = '{default:5};

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("test_array");

    Initialization_list il;
    il.add_dimension({{Expression_component("31")}, {Expression_component("0")}, true}, true);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}, false}, false);

    il.add_item(Expression({Expression_component("5")}));
    il.set_default();

    p->add_initialization_list(il);



    check_params.insert(p);


   ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        EXPECT_TRUE(parameters.contains(item->get_name()));
        EXPECT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();

    mdarray<int64_t> av;
    av.set_1d_slice({0, 0}, {5, 5});

    std::map<std::string, resolved_parameter> check_defaults = {
        {"test_array", av}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(parameter_extraction, array_concatenation) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter simple_numeric_p = 32,
            sv_numeric_p = 5'o10
        )();
            parameter logic [31:0] concatenation [1:0] = {simple_numeric_p, sv_numeric_p};

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"simple_numeric_p", {"32"}},
            {"sv_numeric_p", {"5'o10"}}
    };


    for(auto &item:  vect_params){
        auto p = std::make_shared<HDL_parameter>();
        p->set_type(HDL_parameter::expression_parameter);
        p->set_name(item.first);
        for(auto &op:item.second){
            p->add_component(Expression_component(op));
        }
        check_params.insert(p);
    }

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("concatenation");

    Initialization_list il;
    il.add_dimension({{Expression_component("31")}, {Expression_component("0")}, true}, true);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}, false}, false);

    Concatenation c;
    c.add_component(Expression({Expression_component("simple_numeric_p")}));
    c.add_component(Expression({Expression_component("sv_numeric_p")}));
    il.set_scalar(c);

    p->add_initialization_list(il);



    check_params.insert(p);


   ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();

    mdarray<int64_t> av;
    av.set_1d_slice({0, 0}, {8,32});

    std::map<std::string, resolved_parameter> check_defaults = {
        {"simple_numeric_p", 32},
        {"sv_numeric_p", 8},
        {"concatenation", av}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(parameter_extraction, array_parameter) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter [31:0] array_parameter [1:0] = '{32, 5}
        )();

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("array_parameter");


    Initialization_list il;
    dimension_t d;
    d.first_bound = {Expression_component("31")};
    d.second_bound = {Expression_component("0")};
    d.packed = true;
    il.add_dimension(d,true);

    d.first_bound = {Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    il.add_dimension(d,false);
    il.add_item(Expression({Expression_component("32")}));
    il.add_item(Expression({Expression_component("5")}));

    p->add_initialization_list(il);

    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();
    mdarray<int64_t> array_value;
    array_value.set_1d_slice({0, 0}, {5, 32});
    std::map<std::string, resolved_parameter> check_defaults = {
        {"array_parameter", array_value}

    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}


TEST(parameter_extraction, simple_array_propagation) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter [31:0] array_parameter [1:0] = '{32, 5}
        )();
            parameter array_parameter_expr_p = array_parameter[0] + array_parameter[1];
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("array_parameter");


    Initialization_list il;
    dimension_t d;
    d.first_bound = {Expression_component("31")};
    d.second_bound = {Expression_component("0")};
    d.packed = true;
    il.add_dimension(d,true);

    d.first_bound = {Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    il.add_dimension(d,false);
    il.add_item(Expression({Expression_component("32")}));
    il.add_item(Expression({Expression_component("5")}));

    p->add_initialization_list(il);

    check_params.insert(p);


    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("array_parameter_expr_p");
    Expression_component e = Expression_component("array_parameter");
    std::vector<Expression> ai;
    ai.push_back(Expression({Expression_component("0")}));
    e.set_array_index(ai);
    p->add_component(e);
    p->add_component(Expression_component("+"));
    e = Expression_component("array_parameter");
    ai.clear();
    ai.push_back(Expression({Expression_component("1")}));
    e.set_array_index(ai);
    p->add_component(e);
    check_params.insert(p);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();
    mdarray<int64_t> array_value;
    array_value.set_1d_slice({0, 0}, {5, 32});
    std::map<std::string, resolved_parameter> check_defaults = {
        {"array_parameter", array_value},
        {"array_parameter_expr_p", 37},
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(parameter_extraction, array_expression) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter sv_numeric_p = 1,
            parameter [31:0] array_parameter [1:0] = '{32, 5}
        )();
            parameter array_parameter_expr_p = array_parameter[sv_numeric_p*0] + array_parameter[1];
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("array_parameter");


    Initialization_list il;
    dimension_t d;
    d.first_bound = {Expression_component("31")};
    d.second_bound = {Expression_component("0")};
    d.packed = true;
    il.add_dimension(d,true);

    d.first_bound = {Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    il.add_dimension(d,false);
    il.add_item(Expression({Expression_component("32")}));
    il.add_item(Expression({Expression_component("5")}));

    p->add_initialization_list(il);

    check_params.insert(p);


    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("array_parameter_expr_p");
    Expression_component e = Expression_component("array_parameter");
    std::vector<Expression> ai;
    ai.push_back({Expression_component("sv_numeric_p"), Expression_component("*"), Expression_component("0")});
    e.set_array_index(ai);
    p->add_component(e);
    p->add_component(Expression_component("+"));
    e = Expression_component("array_parameter");
    ai.clear();
    ai.push_back(Expression({Expression_component("1")}));
    e.set_array_index(ai);
    p->add_component(e);
    check_params.insert(p);
    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("sv_numeric_p");
    p->add_component(Expression_component("1"));
    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();
    mdarray<int64_t> array_value;
    array_value.set_1d_slice({0, 0}, {5, 32});
    std::map<std::string, resolved_parameter> check_defaults = {
        {"array_parameter", array_value},
        {"array_parameter_expr_p", 37},
        {"sv_numeric_p", 1},

    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(parameter_extraction, multidimensional_array_expression) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter repetition_size = 2,
            parameter [31:0] multidim_array_parameter [repetition_size-1:0][1:0] = '{{32,32}, {5,6}}
        )();
            parameter multidim_array_access = multidim_array_parameter[1][0];
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("repetition_size");
    p->add_component(Expression_component("2"));
    check_params.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("multidim_array_parameter");


    init_list_t init;
    std::vector<dimension_t> d;
    dimension_t dim;
    dim.first_bound = {Expression_component("31")};
    dim.second_bound= {Expression_component("0")};
    dim.packed = true;
    d.push_back(dim);
    dim.first_bound = {Expression_component("repetition_size"),Expression_component("-"), Expression_component("1")};
    dim.second_bound= {Expression_component("0")};
    dim.packed = false;
    d.push_back(dim);
    dim.first_bound = {Expression_component("1")};
    dim.second_bound= {Expression_component("0")};
    dim.packed = false;
    d.push_back(dim);
    init.dimensions = d;
    std::vector<Expression> e;
    e.push_back({Expression_component("32")});
    e.push_back({Expression_component("32")});
    init.values.push_back(e);
    e.clear();
    e.push_back({Expression_component("5")});
    e.push_back({Expression_component("6")});
    init.values.push_back(e);

    p->add_initialization_list(produce_check_init_list(init));


    check_params.insert(p);



    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("multidim_array_access");
    Expression_component ec = Expression_component("multidim_array_parameter");
    std::vector<Expression> ai;
    ai.push_back({Expression_component("1")});
    ai.push_back({Expression_component("0")});
    ec.set_array_index(ai);
    p->add_component(ec);
    check_params.insert(p);



    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }


    auto defaults = resource.get_default_parameters();

    mdarray<int64_t> av;
    av.set_2d_slice({0}, {{6,5}, {32,32}});

    std::map<std::string, resolved_parameter> check_defaults = {
        {"repetition_size", 2},
        {"multidim_array_parameter", av},
        {"multidim_array_access", 32}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }

}


TEST(parameter_extraction, simple_repetition_initialization) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter repetition_size = 2,
            parameter int repetition_parameter_1 [1:0]  = '{repetition_size{1}}
        )();

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("repetition_size");
    p->add_component(Expression_component("2"));
    check_params.insert(p);


    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("repetition_parameter_1");

    Initialization_list il;
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}, false}, false);
    Replication rep;
    rep.set_size({Expression_component("repetition_size")});
    rep.set_item(Expression({Expression_component("1")}));
    il.set_scalar(rep);


    p->add_initialization_list(il);

    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();

    mdarray<int64_t> av;
    av.set_2d_slice({0}, {{1,1}});

    std::map<std::string, resolved_parameter> check_defaults = {
        {"repetition_size", 2},
        {"repetition_parameter_1", av}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }

}

TEST(parameter_extraction, packed_repetition_initialization) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter repetition_size = 2,
            parameter int repetition_parameter_1  = {repetition_size{1}}
        )();

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("repetition_size");
    p->add_component(Expression_component("2"));
    check_params.insert(p);


    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("repetition_parameter_1");

    Initialization_list il;
    Replication rep;
    rep.set_size({Expression_component("repetition_size")});
    rep.set_item(Expression({Expression_component("1")}));
    il.set_scalar(rep);


    p->add_initialization_list(il);

    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();

    std::map<std::string, resolved_parameter> check_defaults = {
        {"repetition_size", 2},
        {"repetition_parameter_1", 3}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }

}

TEST(parameter_extraction, repetition_initialization) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter repetition_size = 2,
            parameter bit repetition_parameter_1 [1:0]  = '{repetition_size{1}},
            parameter bit repetition_parameter_2 [1:0]  = '{repetition_size{4}},
            parameter bit multi_repetition_parameter [3:0]  = {repetition_parameter_1,repetition_parameter_2},
            parameter bit mixed_repetition_parameter [3:0]  = {1,2,repetition_parameter_2}
        )();

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("repetition_size");
    p->add_component(Expression_component("2"));
    check_params.insert(p);


    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("repetition_parameter_1");

    Initialization_list il;
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}, false}, false);
    Replication r;
    r.set_size({Expression_component("repetition_size")});
    r.set_item(Expression({Expression_component("1")}));
    il.set_scalar(r);
    p->add_initialization_list(il);

    check_params.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("repetition_parameter_2");

    il = Initialization_list();
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}, false}, false);
    r.set_size({Expression_component("repetition_size")});
    r.set_item(Expression({Expression_component("4")}));
    il.set_scalar(r);
    p->add_initialization_list(il);

    check_params.insert(p);


    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("multi_repetition_parameter");

    il = Initialization_list();
    il.add_dimension({
    {Expression_component("3")},
    {Expression_component("0")},
    false
    }, false);
    Concatenation c;
    c.add_component(Expression({Expression_component("repetition_parameter_1")}));
    c.add_component( Expression({Expression_component("repetition_parameter_2")}));
    il.set_scalar(c);
    p->add_initialization_list(il);

    check_params.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("mixed_repetition_parameter");

    il = Initialization_list();
    il.add_dimension({
    {Expression_component("3")},
    {Expression_component("0")},
    false
    }, false);
    c = Concatenation();
    c.add_component(Expression({Expression_component("1")}));
    c.add_component( Expression({Expression_component("2")}));
    c.add_component( Expression({Expression_component("repetition_parameter_2")}));
    il.set_scalar(c);
    p->add_initialization_list(il);

    check_params.insert(p);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();

    mdarray<int64_t> av, av2, av3, av4;
    av.set_2d_slice({0}, {{1,1}});
    av2.set_2d_slice({0}, {{4,4}});
    av3.set_2d_slice({0}, {{4, 4, 1, 1}});
    av4.set_2d_slice({0}, {{4, 4, 2, 1}});

    std::map<std::string, resolved_parameter> check_defaults = {
        {"repetition_size", 2},
        {"repetition_parameter_1", av},
        {"repetition_parameter_2", av2},
        {"multi_repetition_parameter", av3},
        {"mixed_repetition_parameter", av4}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }

}

TEST(parameter_extraction, packed_array) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter logic [7:0] packed_param = {1'b1,1'b0,1'b1,1'b0,1'b1,1'b0,1'b0,1'b1}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("packed_param");

    dimension_t d;
    d.first_bound = {Expression_component("7")};
    d.second_bound = {Expression_component("0")};
    d.packed = true;
    Initialization_list il;
    il.add_dimension(d, true);
    il.set_scalar({Concatenation({
                {Expression_component("1'b1")},
                {Expression_component("1'b0")},
                {Expression_component("1'b1")},
                {Expression_component("1'b0")},
                {Expression_component("1'b1")},
                {Expression_component("1'b0")},
                {Expression_component("1'b0")},
                {Expression_component("1'b1")},
    })});

    p->add_initialization_list(il);

    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& check_item:check_params){
        ASSERT_TRUE(parameters.contains(check_item->get_name()));
        ASSERT_EQ(*check_item, *parameters.get(check_item->get_name()));
    }

    auto defaults = resource.get_default_parameters();


    std::map<std::string, resolved_parameter> check_defaults = {
        {"packed_param", 169}
    };

    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}


TEST(parameter_extraction, multpidim_packed_array) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter logic [7:0] packed_param [1:0] = '{{1'b1,1'b0,1'b1,1'b0,1'b1,1'b0,1'b0,1'b1},{1'b1,1'b1,1'b0,1'b0,1'b1,1'b0,1'b0,1'b1}}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("packed_param");

    init_list_t init;
    dimension_t d;

    d.first_bound = {Expression_component("7")};
    d.second_bound = {Expression_component("0")};
    d.packed = true;
    init.dimensions.push_back(d);

    d.first_bound = {Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    init.dimensions.push_back(d);
    auto c = {Concatenation({
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")}
    }),
    Concatenation({
            {Expression_component("1'b1")},
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")},
    })};
    init.values.emplace_back(c);

    p->add_initialization_list(produce_check_init_list(init));

    check_params.insert(p);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& check_item:check_params){
        ASSERT_TRUE(parameters.contains(check_item->get_name()));
        ASSERT_EQ(*check_item, *parameters.get(check_item->get_name()));
    }

    auto defaults = resource.get_default_parameters();


    mdarray<int64_t> av;
    av.set_1d_slice({0, 0}, {169, 201});
    std::map<std::string, resolved_parameter> check_defaults = {
        {"packed_param", av }
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }
}

TEST(parameter_extraction, package_parameters_use) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter package_param = test_package::bus_base
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("package_param");
    Expression_component ec("bus_base");
    ec.set_package_prefix("test_package");
    p->add_component(ec);
    check_params.insert(p);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_extraction, negative_number_parameters) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter negative_param = -16'sd32767
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("negative_param");
    for(auto &op:{"-", "16'sd32767"}){
        p->add_component(Expression_component(op));
    }
    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_extraction, negative_number_array_init) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter negative_array_param [1:0] = '{-16'sd32767, 16'sd32767}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("negative_array_param");

    init_list_t init;
    dimension_t d;
    d.first_bound = {Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    init.dimensions = {d};
    auto e = {Expression({Expression_component("-"),Expression_component("16'sd32767")}), Expression({Expression_component("16'sd32767")})};
    init.values.emplace_back(e);

    p->add_initialization_list(produce_check_init_list_1d(init));


    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_extraction, expression_array_init) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter expression_array_param [1:0] = '{5+4, 7*6}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("expression_array_param");

    init_list_t init;
    dimension_t d;
    d.first_bound = {Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    init.dimensions.push_back(d);
    auto e  = {Expression({Expression_component("5"),Expression_component("+"),Expression_component("4")}), Expression({Expression_component("7"),Expression_component("*"),Expression_component("6")})};
    init.values.emplace_back(e);
    p->add_initialization_list(produce_check_init_list_1d(init));


    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_extraction, combined_packed_unpacked_init) {
    std::string test_pattern = R"(
    module test_mod #(
      parameter reg [7:0] param_a [1:0] = '{{1'b1,1'b1,1'b1,1'b0,1'b0,1'b0,1'b1,1'b0}, {1'b0,1'b0,1'b0,1'b1,1'b1,1'b1,1'b0,1'b1}},
      parameter reg [7:0] param_b [1:0] = '{{8{1'b1}},{8{1'b0}}}
    )();
    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("param_a");

    init_list_t init;
    dimension_t d;
    d.first_bound  = {Expression_component("7")};
    d.second_bound = {Expression_component("0")};
    d.packed = true;
    init.dimensions.push_back(d);
    d.first_bound  = {Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    init.dimensions.push_back(d);
    auto c = {Concatenation({
            {Expression_component("1'b1")},
            {Expression_component("1'b1")},
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b0")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
    }),
    Concatenation({
        {Expression_component("1'b0")},
        {Expression_component("1'b0")},
        {Expression_component("1'b0")},
        {Expression_component("1'b1")},
        {Expression_component("1'b1")},
        {Expression_component("1'b1")},
        {Expression_component("1'b0")},
        {Expression_component("1'b1")}
    })};
    init.values.emplace_back(c);

    p->add_initialization_list(produce_check_init_list(init));



    check_params.insert(p);


    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("param_b");
    init.dimensions.clear();
    init.values.clear();
    d.first_bound  = {Expression_component("7")};
    d.second_bound = {Expression_component("0")};
    d.packed = true;
    init.dimensions.push_back(d);
    d.first_bound  ={Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    init.dimensions.push_back(d);
    auto e = {
        Expression({
            Expression_component("$repeat_init"),
            Expression_component("8"),
            Expression_component(","),
            Expression_component("1'b1")
        }),
        Expression({
            Expression_component("$repeat_init"),
            Expression_component("8"),
            Expression_component(","),
            Expression_component("1'b0")
        })};
    init.values.emplace_back(e);

    p->add_initialization_list(produce_check_init_list(init));



    check_params.insert(p);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_extraction, instance_parameter) {
    std::string test_pattern = R"(
    module test_mod #(
        parameter test_param = 4
    )();

    module_type #(
        .param_1(test_param),
        .param_2(test_param+5),
        .param_3((test_param + 7)*1)
    ) test_instance ();

    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto def_parameters = resource.get_parameters();

    auto inst_parameters = resource.get_dependencies()[0].get_parameters();

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"test_param", {"4"}}
    };

    Parameters_map check_params;
    for(auto &item:  vect_params){
        auto p = std::make_shared<HDL_parameter>();
        p->set_type(HDL_parameter::expression_parameter);
        p->set_name(item.first);
        for(auto &op:item.second){
            p->add_component(Expression_component(op));
        }
        check_params.insert(p);
    }


    ASSERT_EQ(check_params.size(), def_parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(def_parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *def_parameters.get(item->get_name()));
    }


    vect_params = {
            {"param_1", {"test_param"}},
            {"param_2", {"test_param", "+", "5"}},
            {"param_3", {"(", "test_param", "+", "7", ")", "*", "1"}},
    };

    check_params.clear();

    for(auto &item:  vect_params){
        auto p = std::make_shared<HDL_parameter>();
        p->set_type(HDL_parameter::expression_parameter);
        p->set_name(item.first);
        for(auto &op:item.second){
            p->add_component(Expression_component(op));
        }
        check_params.insert(p);
    }


    ASSERT_EQ(check_params.size(), inst_parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(inst_parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *inst_parameters.get(item->get_name()));
    }


}


TEST(parameter_extraction, mixed_packed_unpacked_init) {
    std::string test_pattern = R"(
    module test_mod #(
        SS_POLARITY_DEFAULT = 0
    )();


        localparam logic [31:0] FIXED_REGISTER_VALUES [4:0]= '{
            3,
            3,
            3,
            {SS_POLARITY_DEFAULT,3'b0,SS_POLARITY_DEFAULT,5'b0,4'hE,4'b0},
            {2'h2,2'b1,2'h3,4'hE,4'b0}
        };
    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"", {}}
    };

    check_params.clear();

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("SS_POLARITY_DEFAULT");
    p->add_component(Expression_component("0"));
    check_params.insert(p);


    p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("FIXED_REGISTER_VALUES");

    init_list_t init;
    dimension_t d;
    d.first_bound  = {Expression_component("31")};
    d.second_bound =  {Expression_component("0")};
    d.packed = true;
    init.dimensions.push_back(d);
    d.first_bound  = {Expression_component("4")};
    d.second_bound =  {Expression_component("0")};
    d.packed = false;
    init.dimensions.push_back(d);
    auto e = {
        Expression({Expression_component("3")}),
        Expression({Expression_component("3")}),
        Expression({Expression_component("3")}),
    };
    init.values.emplace_back(e);
    auto c = {Concatenation({
        {Expression_component("SS_POLARITY_DEFAULT")},
        {Expression_component("3'b0")},
        {Expression_component("SS_POLARITY_DEFAULT")},
        {Expression_component("5'b0")},
        {Expression_component("4'hE")},
        {Expression_component("4'b0")},
    }), Concatenation({
            {Expression_component("2'h2")},
            {Expression_component("2'b1")},
            {Expression_component("2'h3")},
            {Expression_component("4'hE")},
            {Expression_component("4'b0")},
    })};

    init.values.emplace_back(c);

    p->add_initialization_list(produce_check_init_list(init));



    check_params.insert(p);


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}


TEST(parameter_extraction, multidimensional_packed_array) {
    std::string test_pattern = R"(
    module test_mod #(
        parameter reg [7:0] param_a [1:0][1:0] = '{
            {
                {1'b1,1'b1,1'b1,1'b0,1'b0,1'b0,1'b1,1'b0},
                {1'b0,1'b0,1'b0,1'b1,1'b1,1'b1,1'b0,1'b1}
            },
            {
                {1'b0,1'b0,1'b0,1'b1,1'b1,1'b1,1'b0,1'b1},
                {1'b1,1'b1,1'b1,1'b0,1'b0,1'b0,1'b1,1'b0}
            }
        }
    )();
    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    check_params.clear();


    Expression v1 = {
        Expression_component("1'b1"),
        Expression_component("1'b1"),
        Expression_component("1'b1"),
        Expression_component("1'b0"),
        Expression_component("1'b0"),
        Expression_component("1'b0"),
        Expression_component("1'b1"),
        Expression_component("1'b0")
    };
    Expression v2 = {
                Expression_component("1'b0"),
                Expression_component("1'b0"),
                Expression_component("1'b0"),
                Expression_component("1'b1"),
                Expression_component("1'b1"),
                Expression_component("1'b1"),
                Expression_component("1'b0"),
                Expression_component("1'b1")
    };

    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("param_a");

    Initialization_list il;
    il.add_dimension({{Expression_component("7")}, {Expression_component("0")}, true}, true);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")},false},false);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")},false},false);

    il.open_level();
    il.open_level();
    for(const auto& item:v1.components){
        il.add_item(Expression({item}));
    }
    il.close_level();
    il.open_level();
    for(const auto& item:v2.components){
        il.add_item(Expression({item}));
    }
    il.close_level();
    il.close_level();
    il.open_level();
    il.open_level();
    for(const auto& item:v2.components){
        il.add_item(Expression({item}));
    }
    il.close_level();
    il.open_level();
    for(const auto& item:v1.components){
        il.add_item(Expression({item}));
    }
    il.close_level();
    il.close_level();

    p->add_initialization_list(il);

    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}


TEST(parameter_extraction, packed_replication_init) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter [4:0] test_parameter = {5{1'b1}}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;


    auto p = std::make_shared<HDL_parameter>();
    p->set_type(HDL_parameter::expression_parameter);
    p->set_name("test_parameter");

    Initialization_list il;
    il.add_dimension({{Expression_component("4")}, {Expression_component("0")}, true}, true);
    Replication r;
    r.set_size({Expression_component("5")});
    r.set_item(Expression({Expression_component("1'b1")}));
    il.set_scalar(r);

    p->add_initialization_list(il);


    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

    auto defaults = resource.get_default_parameters();

    std::map<std::string, resolved_parameter> check_defaults = {
        {"test_parameter", 31}
    };
    for(const auto& [name, value]:check_defaults){
        ASSERT_TRUE(defaults.contains(name));
        ASSERT_EQ(value, defaults.at(name));
    }

}


TEST(parameter_extraction, array_initialization_default) {
    std::string test_pattern = R"(
        module test_mod #(
             parameter [4:0] test_parameter [2:0][1:0] = '{default:0}
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_name("test_parameter");
    p->set_type(HDL_parameter::expression_parameter);
    Initialization_list i;
    dimension_t d;
    d.first_bound = {Expression_component("4")};
    d.second_bound = {Expression_component("0")};
    d.packed = true;
    i.add_dimension(d, true);
    d.first_bound = {Expression_component("2")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    i.add_dimension(d, false);
    d.first_bound = {Expression_component("1")};
    d.second_bound = {Expression_component("0")};
    d.packed = false;
    i.add_dimension(d, false);
    i.add_item(Expression({Expression_component("0")}));
    i.set_default();
    p->add_initialization_list(i);
    check_params.insert(p);

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }

}

TEST(parameter_extraction, unrelated_wire_dependency_conflict) {
    std::string test_pattern = R"(
    module test_mod #(
        DECIMATE = 1
    )();
    assign unrelated_wire = {5{1}};

        dependency #(
            .DECIMATED(DECIMATE)
        ) dep();
    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    HDL_instance i = resource.get_dependencies()[0];

    auto parameter = i.get_parameters().get("DECIMATED");

    auto check_param = std::make_shared<HDL_parameter>();
    check_param->set_name("DECIMATED");
    check_param->set_type(HDL_parameter::expression_parameter);
    check_param->add_component({Expression_component("DECIMATE")});

    ASSERT_EQ(*parameter, *check_param);
}


TEST(parameter_extraction, interface_parameters) {
    std::string test_pattern = R"(
        interface axi_stream #(DATA_WIDTH = 32, USER_WIDTH = 32, DEST_WIDTH = 32);
        endinterface
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;

    auto p = std::make_shared<HDL_parameter>();
    p->set_name("DATA_WIDTH");
    p->set_type(HDL_parameter::expression_parameter);
    p->add_component(Expression_component("32"));
    check_params.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("USER_WIDTH");
    p->set_type(HDL_parameter::expression_parameter);
    p->add_component(Expression_component("32"));
    check_params.insert(p);

    p = std::make_shared<HDL_parameter>();
    p->set_name("DEST_WIDTH");
    p->set_type(HDL_parameter::expression_parameter);
    p->add_component(Expression_component("32"));
    check_params.insert(p);

    ASSERT_EQ(check_params, parameters);
}


TEST(parameter_extraction, generate_for) {
    std::string test_pattern = R"(
    module test_mod #(
        N_REPETITION = 2
    )();

        parameter [31:0] ARRAY_PARAM [1:0] = '{10, 440};

        genvar n;

        generate
            for(n = 0; n<N_REPETITIONS; n=n+1)begin
                dependency #(
                    .DEP_PARAM(ARRAY_PARAM[n])
                ) dep();
            end
        endgenerate

    endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto dep = resource.get_dependencies()[0];

    ASSERT_EQ(dep.get_n_loops(), 1);

    auto loop = dep.get_inner_loop();

    HDL_loop_metadata check_loop;

    HDL_parameter p;
    p.set_name("n");
    p.set_type(HDL_parameter::expression_parameter);
    p.add_component(Expression_component("0"));

    check_loop.set_init(p);
    check_loop.set_end_c({Expression_component("n"), Expression_component("<"), Expression_component("N_REPETITIONS")});
    check_loop.set_iter({Expression_component("n"), Expression_component("+"), Expression_component("1")});

    ASSERT_EQ(loop, check_loop);
}


TEST(parameter_extraction, simple_function_parameter) {
    std::string test_pattern = R"(


        module test_mod #(
        )();

            parameter [ADDR_WIDTH-1:0] AXI_ADDRESSES [N_AXI_LITE-1:0] = CTRL_ADDR_CALC();

        endmodule
    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto param = resource.get_parameters().get("AXI_ADDRESSES");

    HDL_parameter p;
    p.set_name("AXI_ADDRESSES");
    p.set_type(HDL_parameter::function_parameter);
    p.add_component(Expression_component("CTRL_ADDR_CALC"));

    ASSERT_EQ(p, *param);
}

/**


TEST(parameter_extraction, param_ternary_conditional) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter condition = 2,
            parameter test_positive = condition > 1 ? 12 : 34,
            parameter test_positive = condition > 65 ? 12 : 34
        )();
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    Parameters_map check_params;



    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item->get_name()));
        ASSERT_EQ(*item, *parameters.get(item->get_name()));
    }
}
 **/