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

typedef struct{
    std::vector<std::vector<Expression>> values;
    std::vector<dimension_t> dimensions;
}init_list_t;

Initialization_list produce_check_init_list_1d(const init_list_t &i){
    Initialization_list il;
    for(auto &item:i.dimensions){
        il.add_dimension(item, item.packed);
    }
    for(const auto &item:i.values){
        for(const auto &expr:item){
            il.add_item(expr);
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
        for(const auto &expr:item){
            il.add_item(expr);
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

    std::map<std::string, HDL_parameter> check_params;

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"simple_numeric_p", {"32"}},
            {"local_p", {"74"}},
            {"sv_numeric_p", {"5'o10"}},
            {"dimensionless_sv_numeric_p", {"'h3F"}},
            {"string_p", {R"("423")"}},
            {"nested_p", {"string_p"}}
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

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;

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
        HDL_parameter p = HDL_parameter();
        p.set_type(expression_parameter);
        p.set_name(item.first);
        for(auto &op:item.second){
            p.add_component(Expression_component(op));
        }
        check_params[item.first] = p;
    }

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }

}

TEST(parameter_extraction, array_expression) {
    std::string test_pattern = R"(
        module test_mod #(
            parameter [31:0] array_parameter [1:0] = '{32, 5}
        )();
            parameter array_parameter_expr_p = array_parameter[sv_numeric_p*0] + array_parameter[1];
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];
    auto parameters = resource.get_parameters();

    std::map<std::string, HDL_parameter> check_params;

    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("array_parameter");


    Initialization_list il;
    il.add_dimension({{Expression_component("31")}, {Expression_component("0")},true},true);
    il.add_dimension({{Expression_component("1")},{Expression_component("0")}},false);
    il.add_item({Expression_component("32")});
    il.add_item({Expression_component("5")});

    p.add_initialization_list(il);

    check_params["array_parameter"] = p;


    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("array_parameter_expr_p");
    Expression_component e = Expression_component("array_parameter");
    std::vector<std::vector<Expression_component>> ai = {{Expression_component("sv_numeric_p"), Expression_component("*"), Expression_component("0")}};
    e.set_array_index(ai);
    p.add_component(e);
    p.add_component(Expression_component("+"));
    e = Expression_component("array_parameter");
    ai = {{Expression_component("1")}};
    e.set_array_index(ai);
    p.add_component(e);
    check_params["array_parameter_expr_p"] = p;


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;


    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("repetition_size");
    p.add_component(Expression_component("2"));
    check_params["repetition_size"] = p;

    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("multidim_array_parameter");


    init_list_t init;
    init.dimensions = {
            {{Expression_component("31")}, {Expression_component("0")}, true},
            {{Expression_component("repetition_size"),Expression_component("-"), Expression_component("1")},{Expression_component("0")}},
            {{Expression_component("1")},{Expression_component("0")}}
                       };

    init.values = {
        {
            {Expression_component("32")},
            {Expression_component("32")}
        },{
            {Expression_component("5")},
            {Expression_component("6")}
        }
    };

    p.add_initialization_list(produce_check_init_list(init));


    check_params["multidim_array_parameter"] = p;



    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("multidim_array_access");
    Expression_component e = Expression_component("multidim_array_parameter");
    std::vector<Expression> ai = {{Expression_component("1")},{Expression_component("0")}};
    e.set_array_index(ai);
    p.add_component(e);
    check_params["multidim_array_access"] = p;



    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;


    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("repetition_size");
    p.add_component(Expression_component("2"));
    check_params["repetition_size"] = p;


    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("repetition_parameter_1");

    init_list_t init;
    init.dimensions = {{{Expression_component("1")},{Expression_component("0")}, false}};
    init.values = {{
                           {Expression_component("$repeat_init"), Expression_component("repetition_size"), Expression_component(","), Expression_component("1")}
                   }};

    p.add_initialization_list(produce_check_init_list_1d(init));

    check_params["repetition_parameter_1"] = p;

    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("repetition_parameter_2");

    init.dimensions = {{{Expression_component("1")},{Expression_component("0")}, false}};
    init.values = {{
                           {Expression_component("$repeat_init"), Expression_component("repetition_size"), Expression_component(","), Expression_component("4")}
                   }};

    p.add_initialization_list(produce_check_init_list_1d(init));

    check_params["repetition_parameter_2"] = p;


    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("multi_repetition_parameter");

    init.dimensions = {{{Expression_component("3")},{Expression_component("0")}}};
    init.values = {{
                           {Expression_component("repetition_parameter_1")},
                           {Expression_component("repetition_parameter_2")}
                   }};

    p.add_initialization_list(produce_check_init_list(init));

    check_params["multi_repetition_parameter"] = p;

    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("mixed_repetition_parameter");

    init.dimensions = {{{Expression_component("3")},{Expression_component("0")}}};
    init.values = {{
                           {Expression_component("1")},
                           {Expression_component("2")},
                           {Expression_component("repetition_parameter_2")}
                   }};

    
    p.add_initialization_list(produce_check_init_list(init));

    check_params["mixed_repetition_parameter"] = p;


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;

    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("packed_param");

    init_list_t init;
    init.dimensions = {{{Expression_component("7")}, {Expression_component("0")}, true}};
    init.values = {{
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")},
            {Expression_component("1'b0")},
            {Expression_component("1'b0")},
            {Expression_component("1'b1")}
    }};
    
    p.add_initialization_list(produce_check_init_list(init));

    check_params["packed_param"] = p;


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;

    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("package_param");
    Expression_component ec("bus_base");
    ec.set_package_prefix("test_package");
    p.add_component(ec);
    check_params["package_param"] = p;


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;


    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("negative_param");
    for(auto &op:{"-", "16'sd32767"}){
        p.add_component(Expression_component(op));
    }
    check_params["negative_param"] = p;

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;


    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("negative_array_param");

    init_list_t init;
    init.dimensions = {
            {{Expression_component("1")},{Expression_component("0")}, false}
    };
    init.values = {{
       {Expression_component("-"),Expression_component("16'sd32767")},
       {Expression_component("16'sd32767")}
    }};

    p.add_initialization_list(produce_check_init_list_1d(init));
    

    check_params["negative_array_param"] = p;

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;


    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("expression_array_param");

    init_list_t init;
    init.dimensions = {
            {{Expression_component("1")},{Expression_component("0")}, false}
    };
    init.values = {{
        {Expression_component("5"),Expression_component("+"),Expression_component("4")},
        {Expression_component("7"),Expression_component("*"),Expression_component("6")}
   }};

    p.add_initialization_list(produce_check_init_list_1d(init));
    

    check_params["expression_array_param"] = p;

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;


    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("param_a");

    init_list_t init;
    init.dimensions = {
            {{Expression_component("7")}, {Expression_component("0")}, true},
            {{Expression_component("1")}, {Expression_component("0")}, false}
    };
    init.values = {{
                           {Expression_component("1'b1")},
                           {Expression_component("1'b1")},
                           {Expression_component("1'b1")},
                           {Expression_component("1'b0")},
                           {Expression_component("1'b0")},
                           {Expression_component("1'b0")},
                           {Expression_component("1'b1")},
                           {Expression_component("1'b0")}
                   },
                   {
                           {Expression_component("1'b0")},
                           {Expression_component("1'b0")},
                           {Expression_component("1'b0")},
                           {Expression_component("1'b1")},
                           {Expression_component("1'b1")},
                           {Expression_component("1'b1")},
                           {Expression_component("1'b0")},
                           {Expression_component("1'b1")}
                   }};

    p.add_initialization_list(produce_check_init_list(init));
    
    

    check_params["param_a"] = p;


    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("param_b");

    init.dimensions = {
            {{Expression_component("7")}, {Expression_component("0")}, true},
            {{Expression_component("1")}, {Expression_component("0")}, false}
    };
    init.values = {{
                           {Expression_component("$repeat_init"),
                                   Expression_component("8"),
                                   Expression_component(","),
                                   Expression_component("1'b1")}
                   },
                   {{Expression_component("$repeat_init"),
                            Expression_component("8"),
                            Expression_component(","),
                            Expression_component("1'b0")}
                   }};

    p.add_initialization_list(produce_check_init_list(init));
    
    

    check_params["param_b"] = p;


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;
    for(auto &item:  vect_params){
        HDL_parameter p = HDL_parameter();
        p.set_type(expression_parameter);
        p.set_name(item.first);
        for(auto &op:item.second){
            p.add_component(Expression_component(op));
        }
        check_params[item.first] = p;
    }


    ASSERT_EQ(check_params.size(), def_parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(def_parameters.contains(item.first));
        ASSERT_EQ(item.second, def_parameters[item.first]);
    }

    vect_params = {
            {"param_1", {"test_param"}},
            {"param_2", {"test_param", "+", "5"}},
            {"param_3", {"(", "test_param", "+", "7", ")", "*", "1"}},
    };

    check_params.clear();

    for(auto &item:  vect_params){
        HDL_parameter p = HDL_parameter();
        p.set_type(expression_parameter);
        p.set_name(item.first);
        for(auto &op:item.second){
            p.add_component(Expression_component(op));
        }
        check_params[item.first] = p;
    }


    ASSERT_EQ(check_params.size(), inst_parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(inst_parameters.contains(item.first));
        ASSERT_EQ(item.second, inst_parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;

    std::vector<std::pair<std::string, std::vector<std::string>>> vect_params = {
            {"", {}}
    };

    check_params.clear();

    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("SS_POLARITY_DEFAULT");
    p.add_component(Expression_component("0"));
    check_params["SS_POLARITY_DEFAULT"] = p;


    p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("FIXED_REGISTER_VALUES");

    init_list_t init;
    init.dimensions = {
            {{Expression_component("31")}, {Expression_component("0")}, true},
            {{Expression_component("4")}, {Expression_component("0")}, false}
    };
    init.values = {{
                           {Expression_component("3")},
                   },
                   {
                           {Expression_component("3")},
                   },
                   {
                           {Expression_component("3")},
                   },
                   {
                           {Expression_component("SS_POLARITY_DEFAULT")},
                           {Expression_component("3'b0")},
                           {Expression_component("SS_POLARITY_DEFAULT")},
                           {Expression_component("5'b0")},
                           {Expression_component("4'hE")},
                           {Expression_component("4'b0")}
                   },
                   {
                           {Expression_component("2'h2")},
                           {Expression_component("2'b1")},
                           {Expression_component("2'h3")},
                           {Expression_component("4'hE")},
                           {Expression_component("4'b0")},
                   },
                   };
    p.add_initialization_list(produce_check_init_list(init));
    
    

    check_params["FIXED_REGISTER_VALUES"] = p;


    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;


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

    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("param_a");

    Initialization_list il;
    il.add_dimension({{Expression_component("7")}, {Expression_component("0")},true}, true);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")},false},false);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")},false},false);

    il.open_level();
    il.open_level();
    for(const auto& item:v1){
        il.add_item({item});
    }
    il.close_level();
    il.open_level();
    for(const auto& item:v2){
        il.add_item({item});
    }
    il.close_level();
    il.close_level();
    il.open_level();
    il.open_level();
    for(const auto& item:v2){
        il.add_item({item});
    }
    il.close_level();
    il.open_level();
    for(const auto& item:v1){
        il.add_item({item});
    }
    il.close_level();
    il.close_level();

    p.add_initialization_list(il);

    check_params["param_a"] = p;

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;


    HDL_parameter p = HDL_parameter();
    p.set_type(expression_parameter);
    p.set_name("test_parameter");

    init_list_t init;
    init.dimensions = {
            {{Expression_component("4")},{Expression_component("0")}, true}
    };
    init.values = {{
                           {Expression_component("$repeat_init"),Expression_component("5"),Expression_component(","),Expression_component("1'b1")}
                   }};

    p.add_initialization_list(produce_check_init_list_1d(init));


    check_params["test_parameter"] = p;

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    std::map<std::string, HDL_parameter> check_params;

    HDL_parameter p;
    p.set_name("test_parameter");
    p.set_type(expression_parameter);
    Initialization_list i;
    i.add_dimension({{Expression_component("4")}, {Expression_component("0")}, true}, true);
    i.add_dimension({{Expression_component("2")}, {Expression_component("0")}, false}, false);
    i.add_dimension({{Expression_component("1")}, {Expression_component("0")}, false}, false);
    i.add_item({Expression_component("0")});
    i.set_default();
    p.add_initialization_list(i);
    check_params["test_parameter"] = p;

    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
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

    auto parameter = i.get_parameters()["DECIMATED"];

    HDL_parameter check_param;
    check_param.set_name("DECIMATED");
    check_param.set_type(expression_parameter);
    check_param.add_component({Expression_component("DECIMATE")});

    ASSERT_EQ(parameter, check_param);
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

    std::map<std::string, HDL_parameter> check_params;



    ASSERT_EQ(check_params.size(), parameters.size());

    for(const auto& item:check_params){
        ASSERT_TRUE(parameters.contains(item.first));
        ASSERT_EQ(item.second, parameters[item.first]);
    }
}
 **/