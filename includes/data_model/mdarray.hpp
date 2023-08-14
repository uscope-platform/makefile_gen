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

#ifndef MAKEFILEGEN_V2_MDARRAY_HPP
#define MAKEFILEGEN_V2_MDARRAY_HPP

#include <vector>
#include <cstdint>
#include <iostream>
#include <nlohmann/json.hpp>

typedef std::vector<int64_t> md_1d_array;
typedef std::vector<md_1d_array> md_2d_array;
typedef std::vector<md_2d_array> md_3d_array;


class mdarray {

public:
    void set_value(std::vector<int64_t> idx, int64_t val);
    void set_1d_slice(std::vector<int64_t> idx, const md_1d_array &val);
    void set_2d_slice(std::vector<int64_t> idx, const md_2d_array& val);
    void set_data(const md_3d_array &d){data = d;}

    md_3d_array get_data(){return data;};
    md_2d_array get_2d_slice(std::vector<int64_t> idx){return data[idx[0]];};
    md_1d_array get_1d_slice(std::vector<int64_t> idx){return data[idx[0]][idx[1]];};
    int64_t get_value(std::vector<int64_t> idx){return data[idx[0]][idx[1]][idx[2]];};
    md_3d_array dump();

    friend bool operator==(const mdarray&lhs, const mdarray&rhs){
        return lhs.data == rhs.data;
    };

    friend void PrintTo(const mdarray& res, std::ostream* os);

private:
    md_3d_array data;
};


#endif //MAKEFILEGEN_V2_MDARRAY_HPP
