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



Initialization_list::Initialization_list(const Expression &e) {
    expression_leaves.push_back(e);
}


void Initialization_list::add_dimension(const dimension_t &d) {
    dimensions.push_back(d);
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

        int64_t n_dims_to_push;
        if(dimensions[0].packed){
            n_dims_to_push = dimensions.size()-2;
        } else {
            n_dims_to_push = dimensions.size()-1;
        }
        bool packed_concat = false;
        if(dimensions.size() == 2){
            packed_concat = dimensions[0].packed;
        }

        if(n_dims_to_push>=1 || packed_concat){
            last_dimension = false;
            for(auto &item:expression_leaves){
                lower_dimension_leaves.emplace_back(item);
                for(uint64_t i = dimensions.size()-1; i>n_dims_to_push; i--){
                    lower_dimension_leaves.back().add_dimension(dimensions[i]);
                }
            }
            expression_leaves.clear();
            lower_dimension_leaves.emplace_back();
            for(uint64_t i = dimensions.size()-1; i>n_dims_to_push; i--){
                lower_dimension_leaves.back().add_dimension(dimensions[i]);
            }
        }
    } else{
        lower_dimension_leaves.back().open_level();
    }

}

void Initialization_list::close_level() {
    if(dimensions.size()>1){
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

    ret &= lhs.last_dimension == rhs.last_dimension;
    ret &= lhs.lower_dimension_leaves == rhs.lower_dimension_leaves;
    ret &= lhs.expression_leaves == rhs.expression_leaves;

    if(lhs.dimensions.size() != rhs.dimensions.size()) return false;
    for(int i = 0; i<lhs.dimensions.size(); i++){
        ret &= lhs.dimensions[i].packed == rhs.dimensions[i].packed;
        ret &= lhs.dimensions[i].first_bound == rhs.dimensions[i].first_bound;
        ret &= lhs.dimensions[i].second_bound == rhs.dimensions[i].second_bound;
    }

    return ret;
}

bool Initialization_list::empty() {
    return expression_leaves.empty() && lower_dimension_leaves.empty();
}
