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





TEST(Initialization_list, get_values_1d_mixed_packed_unpacked) {
    Initialization_list il;
    il.add_dimension({{Expression_component("31")}, {Expression_component("0")}},true);
    il.add_dimension({{Expression_component("4")}, {Expression_component("0")}},false);
    il.open_level();
    il.add_item({Expression_component("3")});
    il.close_level();
    il.open_level();
    il.add_item({Expression_component("3")});
    il.close_level();
    il.open_level();
    il.add_item({Expression_component("3")});
    il.close_level();
    il.open_level();
    il.add_item({Expression_component("SS_POLARITY_DEFAULT")});
    il.add_item({Expression_component("3'b0")});
    il.add_item({Expression_component("SS_POLARITY_DEFAULT")});
    il.add_item({Expression_component("5'b0")});
    il.add_item({Expression_component("4'hE")});
    il.add_item({Expression_component("4'b0")});
    il.close_level();
    il.open_level();
    il.add_item({Expression_component("2'h2")});
    il.add_item({Expression_component("2'b1")});
    il.add_item({Expression_component("2'h3")});
    il.add_item({Expression_component("4'hE")});
    il.add_item({Expression_component("4'b0")});
    il.close_level();



    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    working_param_values->insert({"SS_POLARITY_DEFAULT", 1});

    il.link_processor(working_param_values, external_parameters);

    xt::xarray<int64_t> check_array{
        {3, 3, 3 , 226, 0}
    };

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);

}


TEST(Initialization_list, multidimensional_packed_array) {


    Expression v1 = {
            Expression_component("1'b1"),
            Expression_component("1'b1"),
            Expression_component("1'b1"),
            Expression_component("1'b0"),
            Expression_component("1'b0"),
            Expression_component("1'b0"),
            Expression_component("1'b1"),
            Expression_component("1'b1")
    };
    Expression v2 = {
            Expression_component("1'b0"),
            Expression_component("1'b0"),
            Expression_component("1'b0"),
            Expression_component("1'b1"),
            Expression_component("1'b1"),
            Expression_component("1'b1"),
            Expression_component("1'b0"),
            Expression_component("1'b0")
    };

    Initialization_list il;
    il.add_dimension({{Expression_component("7")}, {Expression_component("0")}},true);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}},false);
    il.add_dimension({{Expression_component("1")}, {Expression_component("0")}},false);

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
    v1[7] = v1[6];
    v2[7] = v2[6];
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



    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    il.link_processor(working_param_values, external_parameters);

    xt::xarray<int64_t> check_array{
            {{226, 29}, {28 , 227}}
    };

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);
}