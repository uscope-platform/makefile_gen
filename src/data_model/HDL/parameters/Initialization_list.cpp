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

#include "data_model/HDL/parameters/Initialization_list.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"



Initialization_list::Initialization_list(const Expression &e) {
    expression_leaves.push_back(e);
}


void Initialization_list::add_dimension(const dimension_t &d, bool packed) {
    if(packed){
        packed_dimensions.push_back(d);
    } else{
        unpacked_dimensions.push_back(d);
    }

}

void Initialization_list::add_item(const Expression &e) {
    if(last_dimension){
        expression_leaves.push_back(e);
    } else{
        lower_dimension_leaves.back().add_item(e);
    }
}

void Initialization_list::open_level() {
    if(last_dimension){

        last_dimension = false;
        for(auto &item:expression_leaves){
            Initialization_list ll(item);
            for(const auto& dim:packed_dimensions){
                ll.add_dimension(dim, true);
            }

            for(int i = 1; i< unpacked_dimensions.size(); i++){
                ll.add_dimension(unpacked_dimensions[i], false);
            }
            lower_dimension_leaves.push_back(ll);
        }

        expression_leaves.clear();
        lower_dimension_leaves.emplace_back();
        for(const auto& dim:packed_dimensions){
            lower_dimension_leaves.back().add_dimension(dim, true);
        }

        for(int i = 1; i< unpacked_dimensions.size(); i++){
            lower_dimension_leaves.back().add_dimension(unpacked_dimensions[i], false);
        }
    } else{
        lower_dimension_leaves.back().open_level();
    }

}

void Initialization_list::close_level() {
    if(!unpacked_dimensions.empty()){
        if(!last_dimension){
            lower_dimension_leaves.back().close_level();
            last_dimension = true;
        } else {
            last_dimension = true;
        }
    }

}

bool operator==(const Initialization_list &lhs, const Initialization_list &rhs) {
    bool ret = true;

    // last dimension is an internal variable only needed during construction, as such it does not need comparison
    ret &= lhs.lower_dimension_leaves == rhs.lower_dimension_leaves;
    ret &= lhs.expression_leaves == rhs.expression_leaves;

    if(lhs.unpacked_dimensions.size() != rhs.unpacked_dimensions.size()) return false;
    for(int i = 0; i<lhs.unpacked_dimensions.size(); i++){
        ret &= lhs.unpacked_dimensions[i].packed == rhs.unpacked_dimensions[i].packed;
        ret &= lhs.unpacked_dimensions[i].first_bound == rhs.unpacked_dimensions[i].first_bound;
        ret &= lhs.unpacked_dimensions[i].second_bound == rhs.unpacked_dimensions[i].second_bound;
    }

    if(lhs.packed_dimensions.size() != rhs.packed_dimensions.size()) return false;
    for(int i = 0; i<lhs.packed_dimensions.size(); i++){
        ret &= lhs.packed_dimensions[i].packed == rhs.packed_dimensions[i].packed;
        ret &= lhs.packed_dimensions[i].first_bound == rhs.packed_dimensions[i].first_bound;
        ret &= lhs.packed_dimensions[i].second_bound == rhs.packed_dimensions[i].second_bound;
    }


    return ret;
}

bool Initialization_list::empty() {
    return expression_leaves.empty() && lower_dimension_leaves.empty();
}

void Initialization_list::link_processor(const std::shared_ptr<std::unordered_map<std::string, int64_t>> &wp,
                                         const std::shared_ptr<std::map<std::string, HDL_parameter>> &ep) {
    external_parameters = ep;
    working_param_values = wp;
    for(auto &item:lower_dimension_leaves){
        item.link_processor(wp, ep);
    }
}

int64_t Initialization_list::get_value_at(std::vector<uint64_t> idx) {
    return 0;
}

xt::xarray<int64_t> Initialization_list::get_values() {
    xt::xarray<int64_t> ret;

    if(!expression_leaves.empty()){
        return get_1d_list_values();
    } else {
        std::vector<xt::xarray<int64_t>> leaves_values;
        for(auto &item:lower_dimension_leaves){
            leaves_values.push_back(item.get_values());
        }
    }
    return ret;
}

xt::xarray<int64_t> Initialization_list::get_1d_list_values() {


    std::map<std::string, HDL_parameter> e_p;
    for(const auto& item:*external_parameters){
        e_p.insert(item);
    }
    for(const auto&item:*working_param_values){
        HDL_parameter p;
        p.set_name(item.first);
        p.set_value(item.second);
        e_p.insert({item.first, p});
    }
    std::vector<uint64_t> values;
    for(auto &expr:expression_leaves){

        Parameter_processor p(e_p, nullptr);
        values.push_back(p.process_expression(expr));
    }
    std::vector<std::size_t> shape = { 1,values.size()};
    auto ret = xt::adapt(values, shape);
    return ret;
}
