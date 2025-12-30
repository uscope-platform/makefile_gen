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
#include "data_model/HDL/parameters/Parameters_map.hpp"


Initialization_list::Initialization_list(const Initialization_list &i) {
    completed_set = i.completed_set;
    external_parameters = i.external_parameters;

    unpacked_dimensions = i.unpacked_dimensions;
    packed_dimensions = i.packed_dimensions;

    last_dimension = i.last_dimension;
    expression_leaves = i.expression_leaves;
    lower_dimension_leaves = i.lower_dimension_leaves;
    default_initialization = i.default_initialization;
}

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
            if(lower_dimension_leaves.back().last_dimension){
                last_dimension = true;
            }
            lower_dimension_leaves.back().close_level();

        } else {
            last_dimension = true;
        }
    }
    if(!lower_dimension_leaves.empty() && packed_dimensions.size() + unpacked_dimensions.size() == 1){
        expression_leaves = lower_dimension_leaves[0].expression_leaves;
    }
}

bool operator==(const Initialization_list &lhs, const Initialization_list &rhs) {
    bool ret = true;

    // last dimension is an internal variable only needed during construction, as such it does not need comparison
    ret &= lhs.lower_dimension_leaves == rhs.lower_dimension_leaves;
    ret &= lhs.expression_leaves == rhs.expression_leaves;
    ret &= lhs.default_initialization == rhs.default_initialization;

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

bool Initialization_list::empty() const {
    return expression_leaves.empty() && lower_dimension_leaves.empty();
}

void Initialization_list::link_processor(const std::shared_ptr<Parameters_map> &ep,
                                         const std::shared_ptr<Parameters_map> &cs,
                                         const std::shared_ptr<data_store> &ds) {
    external_parameters = ep;
    completed_set = cs;
    d_store = ds;
    for(auto &item:lower_dimension_leaves){
        item.link_processor( ep, cs, ds);
    }
}

int64_t Initialization_list::get_value_at(std::vector<uint64_t> idx) {
    return 0;
}

mdarray<int64_t>  Initialization_list::get_values() {
    mdarray<int64_t> ret;

    if(default_initialization){
        return process_default_initialization();
    }
    auto size = unpacked_dimensions.size();

    if(size == 0 && !packed_dimensions.empty()){
        return get_packed_1d_list_values();
    } else if(size == 1){
        return get_1d_list_values();
    } else if(size ==2){
        return get_2d_list_values();
    } else if(size == 3){
        return get_3d_list_values();
    }
    return ret;
}

mdarray<int64_t> Initialization_list::get_1d_list_values() {

    if(!packed_dimensions.empty() && !lower_dimension_leaves.empty()) {
        return get_packed_1d_list_values();
    }


    auto p = get_parameter_processor();
    mdarray<int64_t>::md_1d_array values;
    for(auto &expr:expression_leaves){
        if(is_repetition(expr)){
            auto res = expand_repetition(expr, p, nullptr);
            values.insert(values.end(), res.begin(), res.end());
        } else{
            try{
                auto val = p.process_expression(expr, nullptr);
                values.push_back(val);
            } catch(array_value_exception &ex ){
                auto v = ex.array_value.get_1d_slice({0,0});
                values.insert(values.end(), v.begin(), v.end());
            }

        }
    }
    std::reverse(values.begin(), values.end());
    mdarray<int64_t> ret;
    ret.set_1d_slice({0, 0}, values);
    return ret;
}


std::pair<mdarray<int64_t>::md_1d_array, mdarray<int64_t>::md_1d_array> Initialization_list::get_sized_1d_list_values(bool &already_packed) {
    mdarray<int64_t>::md_1d_array values;
    mdarray<int64_t>::md_1d_array sizes;
    already_packed = false;
    auto p = get_parameter_processor();

    for(auto &expr:expression_leaves){
        if(is_repetition(expr)){
            std::vector<int64_t> sizes_tmp;
            auto res = expand_repetition(expr, p, &sizes_tmp);
            sizes.insert(sizes.end(), sizes_tmp.begin(), sizes_tmp.end());
            values.insert(values.end(), res.begin(), res.end());
        } else{
            try{
                if(expr.components.size() == 1 && expr.components[0].is_numeric()){
                    values.push_back(std::get<int64_t>(expr.components[0].get_value()));
                    sizes.push_back(expr.components[0].get_binary_size());
                } else {
                    int64_t  bin_size;
                    auto val = p.process_expression(expr, &bin_size);
                    sizes.push_back(bin_size);
                    values.push_back(val);
                }

            } catch(array_value_exception &ex ){
                auto v = ex.array_value.get_1d_slice({0,0});
                already_packed = true;
                values.insert(values.end(), v.rbegin(), v.rend());
            }

        }
    }
    if(!already_packed){
        std::reverse(values.begin(), values.end());
        std::reverse(sizes.begin(), sizes.end());
    }
    return {values, sizes};
}



mdarray<int64_t> Initialization_list::get_packed_1d_list_values() {
    mdarray<int64_t> ret;

    auto p = get_parameter_processor();
    mdarray<int64_t>::md_1d_array values;
    if(!lower_dimension_leaves.empty()){
        for(auto &item:lower_dimension_leaves){
            bool already_packed = false;
            auto raw_values = item.get_sized_1d_list_values(already_packed);
            if(!already_packed){
                auto val = pack_values(raw_values);
                values.push_back(val);
            } else{
                values.insert(values.end(), raw_values.first.begin(), raw_values.first.end());
            }
        }

    } else{

        mdarray<int64_t>::md_1d_array sizes;
        for(auto &item:expression_leaves){
            if(is_repetition(item)){
                values = expand_repetition(item, p, &sizes);
            } else{
                int64_t s;
                values.push_back(p.process_expression(item, &s));
                sizes.push_back(s);
            }
        }
        auto val = pack_values({values, sizes});
        values = {val};
    }


    std::reverse(values.begin(), values.end());
    ret.set_1d_slice({0, 0}, values);
    return ret;
}

int64_t Initialization_list::pack_values(const std::pair<mdarray<int64_t>::md_1d_array, mdarray<int64_t>::md_1d_array> &components) {

    int64_t total_size = 0;
    for(auto &size:components.second){
        total_size += size;
    }
    std::vector<bool> result(total_size, false);

    uint64_t current_wp = 0;
    for(ssize_t i =0; i<components.first.size(); i++){
        std::bitset<64> data = components.first[i];
        auto size = components.second[i];
        for(int j = 0; j<size; j++){
            result[current_wp] = data[j];
            current_wp++;
        }
    }

    int64_t packed_result = 0;
    for(int i = 0; i<result.size(); i++){
        packed_result += result[i]*std::pow(2, i);
    }

    return packed_result;
}


mdarray<int64_t> Initialization_list::get_2d_list_values() {
    mdarray<int64_t> ret;
    for(int i = 0; i< lower_dimension_leaves.size(); i++){
        auto sub_list = lower_dimension_leaves[i];
        auto row_val = sub_list.get_1d_list_values();
        auto idx = (int64_t)lower_dimension_leaves.size()-1-i;
        ret.set_1d_slice({0, idx}, row_val.get_1d_slice({0, 0}));
    }

    return ret;
}

mdarray<int64_t> Initialization_list::get_3d_list_values() {
    mdarray<int64_t> ret;
    for(int i = 0; i< lower_dimension_leaves.size(); i++){
        auto row_val = lower_dimension_leaves[i].get_2d_list_values();
        auto idx = (int64_t)lower_dimension_leaves.size()-1-i;
        ret.set_2d_slice({idx}, row_val.get_2d_slice({0}));
    }
    return ret;
}


Parameter_processor Initialization_list::get_parameter_processor() {
    Parameters_map e_p;
    for(const auto& item:*external_parameters){
        e_p.insert(item);
    }
    Parameter_processor p(e_p, completed_set);
    p.set_data_store(d_store);
    return p;
}

void PrintTo(const Initialization_list &il, std::ostream *os) {
    std::string result = "-----------------------------\n";
    result += "-----------------------------\n";
    result += "UNPACKED DIMENSIONS\n";
    for(const auto &item:il.unpacked_dimensions){
        result +="[" + item.first_bound.print() + ":" + item.second_bound.print()+ "]";
    }
    result += "PACKED DIMENSIONS\n";
    for(const auto &item:il.packed_dimensions){
        result +="[" + item.first_bound.print() + ":" + item.second_bound.print()+ "]";
    }

    result += "EXPRESSION LEAVES\n";
    for(const auto &item:il.expression_leaves){
        result +=  "  " + item.print() + "\n";
    }

    for(const auto &item:il.lower_dimension_leaves){
        std::ostringstream ss;
        PrintTo(item, &ss);
        result +=  "    " +  ss.str() + "\n";
    }
    result += "-----------------------------\n";
    result += "-----------------------------\n";

    *os << result;
}

std::vector<int64_t> Initialization_list::expand_repetition(Expression &e, Parameter_processor &p, std::vector<int64_t> *sizes) {
    Expression size_expr, val_expr;
    bool in_size = true;
    for(int i = 1; i<e.components.size(); i++){
        if(in_size){
            if(!e.components[i].is_numeric()){
                if (std::get<std::string>(e.components[i].get_value()) == ",") {
                    in_size = false;
                } else {
                    size_expr.push_back(e.components[i]);
                }
            } else{
                size_expr.push_back(e.components[i]);
            }
        } else {
            val_expr.push_back(e.components[i]);
        }
    }


    auto repetition_size = p.process_expression(size_expr, nullptr);
    int64_t value_bin_size;
    auto repetition_value = p.process_expression(val_expr,&value_bin_size);
    if(sizes != nullptr){
        for(int i = 0; i<repetition_size; i++){
            sizes->push_back(value_bin_size);
        }
    }

    auto ret_val = std::vector<int64_t>(repetition_size, repetition_value);
    return ret_val;
}

mdarray<int64_t> Initialization_list::process_default_initialization() {

    std::vector<int64_t> dimensions;
    mdarray<int64_t> result;

    auto p = get_parameter_processor();

    if(unpacked_dimensions.size()>3){
        throw std::runtime_error("Error: unpacked arrays with more than 3 dimensions are not supported");
    }

    for(const auto &item : unpacked_dimensions){
        auto first_dim = p.process_expression(item.first_bound, nullptr);
        auto second_dim = p.process_expression(item.second_bound, nullptr);
        dimensions.push_back(std::max(first_dim, second_dim)+1);
    }

    while(dimensions.size()<3){
        dimensions.insert(dimensions.begin(), 0);
    }

    auto init_value = p.process_expression(expression_leaves[0], nullptr);

    return {dimensions,init_value};


}




