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

void Initialization_list::link_processor(const std::shared_ptr<std::unordered_map<std::string, int64_t>> &wp,
                                         const std::shared_ptr<std::map<std::string, HDL_parameter>> &ep,
                                         const std::shared_ptr<std::unordered_map<std::string, mdarray>> &wap) {
    external_parameters = ep;
    working_param_values = wp;
    for(auto &item:lower_dimension_leaves){
        item.link_processor(wp, ep, wap);
    }
    working_param_array_values = wap;
}

int64_t Initialization_list::get_value_at(std::vector<uint64_t> idx) {
    return 0;
}

mdarray  Initialization_list::get_values() {
    mdarray ret;

    auto size = unpacked_dimensions.size();

    if(size == 1){
        return get_1d_list_values();
    } else if(size ==2){
        return get_2d_list_values();
    } else if(size == 3){
        return get_3d_list_values();
    }
    return ret;
}

mdarray Initialization_list::get_1d_list_values() {

    if(!packed_dimensions.empty() && !lower_dimension_leaves.empty())
        return get_packed_1d_list_values();

    auto p = get_parameter_processor();
    md_1d_array values;
    for(auto &expr:expression_leaves){
        if(is_repetition(expr)){
            auto res = expand_repetition(expr, p);
            values.insert(values.end(), res.begin(), res.end());
        } else{
            try{
                auto val = p.process_expression(Parameter_processor::expr_vector_to_rpn(expr));
                values.push_back(val);
            } catch(array_value_exception &ex ){
                auto v = ex.array_value.get_1d_slice({0,0});
                values.insert(values.end(), v.begin(), v.end());
            }

        }
    }
    std::reverse(values.begin(), values.end());
    mdarray ret;
    ret.set_1d_slice({0, 0}, values);
    return ret;
}

mdarray Initialization_list::get_packed_1d_list_values() {

    auto p = get_parameter_processor();
    md_1d_array values;
    for(auto &item:lower_dimension_leaves){

        auto packed_arr = item.get_1d_list_values().get_1d_slice({0,0});
        int64_t packed_val = 0;
        for(int i = 0; i<packed_arr.size(); i++){
            packed_val += (int64_t)std::pow(2, i)*packed_arr[i];
        }
        values.push_back(packed_val);
    }
    std::reverse(values.begin(), values.end());
    mdarray ret;
    ret.set_1d_slice({0, 0}, values);
    return ret;
}

mdarray Initialization_list::get_2d_list_values() {
    mdarray ret;
    for(int i = 0; i< lower_dimension_leaves.size(); i++){
        auto sub_list = lower_dimension_leaves[i];
        auto row_val = sub_list.get_1d_list_values();
        auto idx = (int64_t)lower_dimension_leaves.size()-1-i;
        ret.set_1d_slice({0, idx}, row_val.get_1d_slice({0, 0}));
    }

    return ret;
}

mdarray Initialization_list::get_3d_list_values() {
    mdarray ret;
    for(int i = 0; i< lower_dimension_leaves.size(); i++){
        auto row_val = lower_dimension_leaves[i].get_2d_list_values();
        auto idx = (int64_t)lower_dimension_leaves.size()-1-i;
        ret.set_2d_slice({idx}, row_val.get_2d_slice({0}));
    }
    return ret;
}


Parameter_processor Initialization_list::get_parameter_processor() {
    std::map<std::string, HDL_parameter> e_p;
    for(const auto& item:*external_parameters){
        e_p.insert(item);
    }

    return {e_p, working_param_values, working_param_array_values};
}

void PrintTo(const Initialization_list &il, std::ostream *os) {
    std::string result = "-----------------------------\n";
    result += "-----------------------------\n";
    result += "UNPACKED DIMENSIONS\n";
    for(const auto &item:il.unpacked_dimensions){
        result +="[" + Expression_component::print_expression(item.first_bound) + ":" + Expression_component::print_expression(item.second_bound)+ "]";
    }
    result += "PACKED DIMENSIONS\n";
    for(const auto &item:il.packed_dimensions){
        result +="[" + Expression_component::print_expression(item.first_bound) + ":" + Expression_component::print_expression(item.second_bound)+ "]";
    }

    result += "EXPRESSION LEAVES\n";
    for(const auto &item:il.expression_leaves){
        result +=  "  " + Expression_component::print_expression(item) + "\n";
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

std::vector<int64_t> Initialization_list::expand_repetition(Expression &e, Parameter_processor &p) {
    Expression size_expr, val_expr;
    bool in_size = true;
    for(int i = 1; i<e.size(); i++){
        if(in_size){
            if(e[i].get_string_value() == ","){
                in_size = false;
            } else{
                size_expr.push_back(e[i]);
            }
        } else {
            val_expr.push_back(e[i]);
        }
    }
    auto repetition_size = p.process_expression(Parameter_processor::expr_vector_to_rpn(size_expr));
    auto repetition_value = p.process_expression(Parameter_processor::expr_vector_to_rpn(val_expr));
    auto ret_val = std::vector<int64_t>(repetition_size, repetition_value);
    return ret_val;
}



