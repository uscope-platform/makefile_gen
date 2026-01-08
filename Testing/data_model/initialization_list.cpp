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

#include "data_model/HDL/parameters/Initialization_list.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "frontend/analysis/sv_analyzer.hpp"


Initialization_list construct_packed_list(const std::vector<std::vector<std::vector<std::vector<std::string>>>> &in, const mdarray<int64_t>::md_2d_array &dims, std::vector<bool> packing){
    Initialization_list li;

    for(int i = 0; i<dims.size(); i++){
        dimension_t d;
        d.first_bound = Expression({Expression_component(std::to_string(dims[i][0]))});
        d.second_bound = Expression({Expression_component(std::to_string(dims[i][1]))});
        d.packed = packing[i];
        li.add_dimension(d, packing[i]);
    }



    return li;
}


TEST(Initialization_list, get_values_1d_unpacked)  {


    Initialization_list il;

    il.add_dimension({{Expression({Expression_component("4")})}, {Expression({Expression_component("0")})}, false}, false);
    il.add_item(std::make_shared<Expression>(Expression({Expression_component("5")})));
    il.add_item(std::make_shared<Expression>(Expression({Expression_component("3")})));
    il.add_item(std::make_shared<Expression>(Expression({Expression_component("4")})));
    il.add_item(std::make_shared<Expression>(Expression({Expression_component("6")})));
    il.add_item(std::make_shared<Expression>(Expression({Expression_component("69")})));


    mdarray<int64_t> check_array;
    check_array.set_1d_slice({0, 0}, {69, 6, 4 , 3, 5});

    auto res = il.evaluate();
    ASSERT_TRUE(res.has_value());
    auto values = std::get<mdarray<int64_t>>(res.value());


}


TEST(Initialization_list, get_values_2d_unpacked) {

    Initialization_list il;

    il.add_dimension({{Expression({Expression_component("2")})}, {Expression({Expression_component("0")})}, false}, false);
    il.add_dimension({{Expression({Expression_component("1")})}, {Expression({Expression_component("0")})}, false}, false);
    Concatenation c;
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("5")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("3")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("4")})));
    il.add_item(std::make_shared<Concatenation>(c));
    c = Concatenation();
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("6")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("69")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("54")})));
    il.add_item(std::make_shared<Concatenation>(c));


    mdarray<int64_t> check_array;
    check_array.set_2d_slice({0, 0}, {{54,69,6},{4,3,5}});

    auto res = il.evaluate();
    ASSERT_TRUE(res.has_value());
    auto values = std::get<mdarray<int64_t>>(res.value());

}


TEST(Initialization_list, get_values_3d_unpacked) {





    Initialization_list il;

    il.add_dimension({{Expression({Expression_component("2")})}, {Expression({Expression_component("0")})}, false}, false);
    il.add_dimension({{Expression({Expression_component("1")})}, {Expression({Expression_component("0")})}, false}, false);
    il.add_dimension({{Expression({Expression_component("1")})}, {Expression({Expression_component("0")})}, false}, false);

    Concatenation c_inner, c_outer;
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("5")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("3")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("4")})));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    c_inner = Concatenation();
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("6")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("69")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("54")})));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    il.add_item(std::make_shared<Concatenation>(c_outer));
    c_inner = Concatenation();
    c_outer = Concatenation();
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("57")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("13")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("24")})));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    c_inner = Concatenation();
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("43")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("82")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("11")})));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    il.add_item(std::make_shared<Concatenation>(c_outer));



    mdarray<int64_t> check_array;
    check_array.set_data({{{11,82,43},{24,13,57}},{{54,69,6},{4,3,5}}});

    auto res = il.evaluate();
    ASSERT_TRUE(res.has_value());
    auto values = std::get<mdarray<int64_t>>(res.value());

}

TEST(Initialization_list, packed_concatenation) {

    Initialization_list il;

    il.add_dimension({{Expression_component("7")}, {Expression_component("0")}, true}, true);
    Concatenation c;
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));

    il.add_item(std::make_shared<Concatenation>(c));
    auto res = il.get_values();


    auto values = std::get<int64_t>(res);

    ASSERT_EQ(169, values);

}



TEST(Initialization_list, get_values_1d_packed) {


    Initialization_list il;
    il.add_dimension(
        {{{Expression_component(2)}},{{Expression_component(0)}}, true
        }, true);

    il.add_dimension(
        {{{Expression_component(4)}},{{Expression_component(0)}}, false
        }, false);

    Concatenation c;
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    il.add_item(std::make_shared<Concatenation>(c));
    c = Concatenation();
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    il.add_item(std::make_shared<Concatenation>(c));
    c = Concatenation();
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    il.add_item(std::make_shared<Concatenation>(c));
    c = Concatenation();
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    il.add_item(std::make_shared<Concatenation>(c));
    c = Concatenation();
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    il.add_item(std::make_shared<Concatenation>(c));


    mdarray<int64_t> check_array;
    check_array.set_1d_slice({0, 0}, {1, 6, 5, 2, 5});

    auto res = il.evaluate();
    ASSERT_TRUE(res.has_value());
    auto values = std::get<mdarray<int64_t>>(res.value());


}

TEST(Initialization_list, get_values_2d_packed) {


    Initialization_list il;
    il.add_dimension(
        {{{Expression_component(2)}},{{Expression_component(0)}}, true
        }, true);

    il.add_dimension(
        {{{Expression_component(1)}},{{Expression_component(0)}}, false
        }, false);


    il.add_dimension(
        {{{Expression_component(1)}},{{Expression_component(0)}}, false
        }, false);



    Concatenation c_inner, c_outer;
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    c_inner = Concatenation();
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    il.add_item(std::make_shared<Concatenation>(c_outer));
    c_inner = Concatenation();
    c_outer = Concatenation();
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    c_inner = Concatenation();
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    il.add_item(std::make_shared<Concatenation>(c_outer));


    mdarray<int64_t> check_array;
    check_array.set_2d_slice({0}, {{6, 5}, {2, 5}});

    auto res = il.evaluate();
    ASSERT_TRUE(res.has_value());
    auto values = std::get<mdarray<int64_t>>(res.value());

}

TEST(Initialization_list, get_values_3d_packed) {


    Initialization_list il;
    il.add_dimension(
        {{{Expression_component(1)}},{{Expression_component(0)}}, true
        }, true);

    il.add_dimension(
        {{{Expression_component(1)}},{{Expression_component(0)}}, false
        }, false);


    il.add_dimension(
        {{{Expression_component(1)}},{{Expression_component(0)}}, false
        }, false);

    il.add_dimension(
        {{{Expression_component(1)}},{{Expression_component(0)}}, false
        }, false);


    Concatenation c_pack, c_inner, c_outer;
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Concatenation>(c_pack));
    c_pack = Concatenation();
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_inner.add_component(std::make_shared<Concatenation>(c_pack));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    c_pack = Concatenation();
    c_inner = Concatenation();
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_inner.add_component(std::make_shared<Concatenation>(c_pack));
    c_pack = Concatenation();
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Concatenation>(c_pack));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    il.add_item(std::make_shared<Concatenation>(c_outer));
    c_pack = Concatenation();
    c_inner = Concatenation();
    c_outer = Concatenation();
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Concatenation>(c_pack));
    c_pack = Concatenation();
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_inner.add_component(std::make_shared<Concatenation>(c_pack));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    c_pack = Concatenation();
    c_inner = Concatenation();
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_inner.add_component(std::make_shared<Concatenation>(c_pack));
    c_pack = Concatenation();
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b0")})));
    c_pack.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c_inner.add_component(std::make_shared<Concatenation>(c_pack));
    c_outer.add_component(std::make_shared<Concatenation>(c_inner));
    il.add_item(std::make_shared<Concatenation>(c_outer));




    mdarray<int64_t> check_array;
    check_array.set_data(
    {
            {
                {1, 2},
                {0, 3}
            },
            {
                {3, 0},
                {2, 1}
            }
        }
    );

    auto res = il.evaluate();
    ASSERT_TRUE(res.has_value());
    auto values = std::get<mdarray<int64_t>>(res.value());


}

TEST(Initialization_list, get_values_concatenation_initialization) {


    Initialization_list il;
    il.add_dimension({{Expression_component("31")}, {Expression_component("0")}, true}, true);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}, false}, false);

    Concatenation c;
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("31")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("43")})));
    il.set_scalar(std::make_shared<Concatenation>(c));

    mdarray<int64_t> check_array;
    check_array.set_1d_slice({0, 0}, {43, 31});

    auto res = il.evaluate();
    ASSERT_TRUE(res.has_value());
    auto values = std::get<mdarray<int64_t>>(res.value());

    ASSERT_EQ(check_array, values);

}

TEST(Initialization_list, get_values_1d_mixed_packed_unpacked) {
    Initialization_list il;
    il.add_dimension({{Expression_component("31")}, {Expression_component("0")}, true}, true);
    il.add_dimension({{Expression_component("4")}, {Expression_component("0")}, false}, false);
    il.add_item(std::make_shared<Expression>(Expression({Expression_component("3")})));
    il.add_item(std::make_shared<Expression>(Expression({Expression_component("3")})));
    il.add_item(std::make_shared<Expression>(Expression({Expression_component("3")})));
    Concatenation c;
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("3'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("1'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("5'b0")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("4'hE")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("4'b0")})));
    il.add_item(std::make_shared<Concatenation>(c));
    c = Concatenation();
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("2'h2")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("2'b1")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("2'h3")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("4'hE")})));
    c.add_component(std::make_shared<Expression>(Expression({Expression_component("4'b0")})));
    il.add_item(std::make_shared<Concatenation>(c));

    mdarray<int64_t> check_array;
    check_array.set_1d_slice({0, 0}, {0x27e0, 0x220e0, 3 , 3, 3});

    auto res = il.evaluate();
    ASSERT_TRUE(res.has_value());
    auto values = std::get<mdarray<int64_t>>(res.value());

    ASSERT_EQ(check_array, values);

}



TEST(Initialization_list, get_array_dependencies) {
    std::string test_pattern = R"(
        module dependency #(
            parameter SS_POLARITY_DEFAULT = 0
        )();

            localparam [31:0] FIXED_REGISTER_VALUES [3:0]= '{SS_POLARITY_DEFAULT,SS_POLARITY_DEFAULT,1};

            localparam [31:0] VARIABLE_INITIAL_VALUES [2:0] = '{3{2'h2}};
            parameter [31:0] INITIAL_REGISTER_VALUES [N_REGISTERS-1:0] = {VARIABLE_INITIAL_VALUES, FIXED_REGISTER_VALUES};

        endmodule

    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto params = resource.get_parameters();
    auto deps_a = params.get("INITIAL_REGISTER_VALUES")->get_dependencies();
    auto deps_b = params.get("FIXED_REGISTER_VALUES")->get_dependencies();
    auto deps_c = params.get("VARIABLE_INITIAL_VALUES")->get_dependencies();

    EXPECT_EQ(deps_a, std::set<std::string>({"VARIABLE_INITIAL_VALUES", "N_REGISTERS", "FIXED_REGISTER_VALUES"}));
    EXPECT_EQ(deps_b, std::set<std::string>({"SS_POLARITY_DEFAULT"}));
    EXPECT_TRUE(deps_c.empty());

}

TEST(Initialization_list, concatenation_of_packed_arrays) {
    std::string test_pattern = R"(
        module dependency #(
            parameter SS_POLARITY_DEFAULT = 0,
            N_CHANNELS=3
        )();
            localparam  N_REGISTERS = 4 + N_CHANNELS;

            localparam [31:0] FIXED_REGISTER_VALUES [3:0]= '{
            0,
            0,
            1,
            {SS_POLARITY_DEFAULT,3'b0,SS_POLARITY_DEFAULT,5'b0,4'hE,4'b0}
            };

            localparam [31:0] VARIABLE_INITIAL_VALUES [2:0] = '{3{2'h2}};
            parameter [31:0] INITIAL_REGISTER_VALUES [N_REGISTERS-1:0] = {VARIABLE_INITIAL_VALUES, FIXED_REGISTER_VALUES};

        endmodule

    )";


    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto resource = analyzer.analyze()[0];

    auto p = resource.get_default_parameters();
    auto param = p["INITIAL_REGISTER_VALUES"];
    mdarray<int64_t>::md_1d_array check_array = {224,1,0,0,2,2,2};
    auto result = std::get<mdarray<int64_t>>(param).get_1d_slice({0,0});

    ASSERT_EQ(check_array, result);

}
