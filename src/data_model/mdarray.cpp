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

#include "data_model/mdarray.hpp"

void mdarray::set_2d_slice(std::vector<int64_t> idx, const md_2d_array &val) {
    if(idx[0]>=data.size()){
        data.resize(idx[0]+1);
    }
    data[idx[0]] =  val;
}

void mdarray::set_1d_slice(std::vector<int64_t> idx, const md_1d_array &val) {
    if(idx[0]>=data.size()){
        data.resize(idx[0]+1);
    }
    if(idx[1]>=data[idx[0]].size()){
        data[idx[0]].resize(idx[1]+1);
    }
    data[idx[0]][idx[1]] = val;
}

void mdarray::set_value(std::vector<int64_t> idx, int64_t val) {
    if(idx[0]>=data.size()){
        data.resize(idx[0]+1);
    }
    if(idx[1]>=data[idx[0]].size()){
        data[idx[0]].resize(idx[1]+1);
    }
    if(idx[2]>=data[idx[0]][idx[2]].size()){
        data[idx[0]][idx[1]].resize(idx[2]+1);
    }
    data[idx[0]][idx[1]][idx[2]] = val;
}

void PrintTo(const mdarray &res, std::ostream *os) {
    std::string result = "{";
    for(auto & item_2d:res.data){
        result += "{";
        for(auto &item_1d:item_2d){
            result += "{";
            for(auto &item:item_1d){
                result += std::to_string(item);
                if (&item != &item_1d.back()) result += ", ";
            }
            result += "}";
            if (&item_1d != &item_2d.back()) result += ", ";
        }
        result += "}";
        if (&item_2d != &res.data.back()) result += ", ";
    }

    *os << result;
}

md_3d_array mdarray::dump() {
    return data;
}

