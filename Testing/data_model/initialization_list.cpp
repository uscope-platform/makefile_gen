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

Initialization_list construct_unpacked_list(const md_3d_array &in, const md_2d_array &dims, std::vector<bool> packing){
    Initialization_list li;

    for(int i = 0; i<dims.size(); i++){
        dimension_t d = {{Expression_component(std::to_string(dims[i][0]))},
                         {Expression_component(std::to_string(dims[i][1]))}};
        li.add_dimension(d, packing[i]);
    }

    for(auto &item2d:in){
        if(dims.size()>2) li.open_level();
        for(auto &item1d:item2d){
            if(dims.size()>1) li.open_level();
            for(auto &item:item1d){
                li.add_item({Expression_component(std::to_string(item))});
            }
            if(dims.size()>1) li.close_level();
        }
        if(dims.size()>2) li.close_level();
    }

    return li;
}


Initialization_list construct_packed_list(const std::vector<std::vector<std::vector<std::vector<std::string>>>> &in, const md_2d_array &dims, std::vector<bool> packing){
    Initialization_list li;

    for(int i = 0; i<dims.size(); i++){
        dimension_t d = {{Expression_component(std::to_string(dims[i][0]))},
                         {Expression_component(std::to_string(dims[i][1]))}};
        li.add_dimension(d, packing[i]);
    }

    for(auto &item2d:in){
        if(dims.size()>3) li.open_level();
        for(auto &item1d:item2d){
            if(dims.size()>2) li.open_level();
            for(auto &item:item1d){
                if(packing[0]) li.open_level();
                for(auto &packed_item:item){
                    li.add_item({Expression_component(packed_item)});
                }
                if(packing[0]) li.close_level();
            }
            if(dims.size()>1) li.close_level();
        }
        if(dims.size()>2) li.close_level();
    }

    return li;
}


TEST(Initialization_list, get_values_1d_unpacked) {

    auto il = construct_unpacked_list(
            {{{5,3,4,6,69}}},
            {{4,0}},
            {false}
    );

    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    working_param_values->insert({"SS_POLARITY_DEFAULT", 1});

    il.link_processor(working_param_values, external_parameters);

    mdarray check_array;
    check_array.set_1d_slice({0, 0}, {69, 6, 4 , 3, 5});

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);

}


TEST(Initialization_list, get_values_2d_unpacked) {

    auto il = construct_unpacked_list(
            {{{5,3,4},{6,69,54}}},
            {{2,0},{1,0}},
            {false, false}
    );

    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    working_param_values->insert({"SS_POLARITY_DEFAULT", 1});

    il.link_processor(working_param_values, external_parameters);

    mdarray check_array;
    check_array.set_2d_slice({0, 0}, {{54,69,6},{4,3,5}});

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);

}


TEST(Initialization_list, get_values_3d_unpacked) {

    auto il = construct_unpacked_list(
            {{{5,3,4},{6,69,54}},{{57,13,24},{43,82,11}}},
            {{2,0},{1,0},{1,0}},
            {false, false, false}
    );


    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    working_param_values->insert({"SS_POLARITY_DEFAULT", 1});

    il.link_processor(working_param_values, external_parameters);

    mdarray check_array;
    check_array.set_data({{{11,82,43},{24,13,57}},{{54,69,6},{4,3,5}}});

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);

}


TEST(Initialization_list, get_values_1d_packed) {
    auto il = construct_packed_list(
            {{{{"1'b1", "1'b0", "1'b1"},{"1'b0", "1'b1", "1'b0"},{"1'b1", "1'b0", "1'b1"}, {"1'b1","1'b1","1'b0"}, {"1'b0","1'b0","1'b1"}}}},
            {{2,0},{4,0}},
            {true, false}
    );


    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    working_param_values->insert({"SS_POLARITY_DEFAULT", 1});

    il.link_processor(working_param_values, external_parameters);

    mdarray check_array;
    check_array.set_1d_slice({0, 0}, {1, 6, 5, 2, 5});

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);


}

TEST(Initialization_list, get_values_2d_packed) {
    auto il = construct_packed_list(
            {{{{"1'b1", "1'b0", "1'b1"},{"1'b0", "1'b1", "1'b0"}},{{"1'b1", "1'b0", "1'b1"}, {"1'b1","1'b1","1'b0"}}}},
            {{2,0},{1,0},{1,0}},
            {true, false, false}
    );

    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    working_param_values->insert({"SS_POLARITY_DEFAULT", 1});

    il.link_processor(working_param_values, external_parameters);

    mdarray check_array;
    check_array.set_2d_slice({0}, {{6, 5}, {2, 5}});

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);

}

TEST(Initialization_list, get_values_3d_packed) {

    auto il = construct_packed_list(
            {
                    {
                        {
                            {"1'b0", "1'b1"},
                            {"1'b1", "1'b0"}
                        },
                        {
                            {"1'b0", "1'b0"},
                            {"1'b1","1'b1"}
                        }
                    },
                    {
                        {
                            {"1'b1", "1'b1"},
                            {"1'b0", "1'b0"}
                        },
                        {
                            {"1'b1", "1'b0"},
                            {"1'b0","1'b1"}
                        }
                    },
                },
            {{1,0},{1,0},{1,0},{1,0}},
            {true, false, false}
    );
    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    working_param_values->insert({"SS_POLARITY_DEFAULT", 1});

    il.link_processor(working_param_values, external_parameters);

    mdarray check_array;
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

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);


}


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

    mdarray check_array;
    check_array.set_1d_slice({0, 0}, {3, 3, 3 , 226, 0});

    auto values = il.get_values();

    ASSERT_EQ(check_array, values);

}


TEST(Initialization_list, multidimensional_packed_array) {
    auto il = construct_packed_list(
            {
                    {
                        {
                                    {"1'b1", "1'b1", "1'b1", "1'b0", "1'b0", "1'b0", "1'b1", "1'b1"},
                                    {"1'b0", "1'b0", "1'b0", "1'b1", "1'b1", "1'b1", "1'b0", "1'b0"}
                        },
                        {
                                    {"1'b1", "1'b1", "1'b1", "1'b0", "1'b0", "1'b0", "1'b1", "1'b0"},
                                    {"1'b0", "1'b0", "1'b0", "1'b1", "1'b1", "1'b1", "1'b0", "1'b1"}
                        }
                    }
            },
            {{7,0},{1,0},{1,0}},
            {true, false}
    );

    auto working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    auto external_parameters =  std::make_shared<std::map<std::string, HDL_parameter>>();

    il.link_processor(working_param_values, external_parameters);



    auto values = il.get_values();

    mdarray check_array;
    check_array.set_2d_slice({0, 0}, {{29, 226}, {28 , 227}});

    ASSERT_EQ(check_array, values);
}