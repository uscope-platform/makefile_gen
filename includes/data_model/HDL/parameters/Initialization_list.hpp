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

#ifndef MAKEFILEGEN_V2_INITIALIZATION_LIST_HPP
#define MAKEFILEGEN_V2_INITIALIZATION_LIST_HPP


#include <vector>
#include <utility>
#include <xtensor/xarray.hpp>
#include <xtensor/xadapt.hpp>

#include "data_model/HDL/parameters/Expression_component.hpp"

// FORWARD DECLARATIONS
class HDL_parameter;

typedef  std::vector<Expression_component> Expression;

typedef struct dims_struct{
    Expression first_bound;
    Expression second_bound;
    bool packed;

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(first_bound, second_bound, packed);
    }

} dimension_t;

class Initialization_list {

public:
    Initialization_list() = default;
    explicit Initialization_list(const Expression &e);
    void add_dimension(const dimension_t &d, bool packed);
    void add_item(const Expression &e);
    void open_level();
    void close_level();
    bool is_last_level() {return last_dimension;};
    bool empty();

    void link_processor(const std::shared_ptr<std::unordered_map<std::string, int64_t>> &wp, const std::shared_ptr<std::map<std::string, HDL_parameter>> &ep);
    int64_t get_value_at(std::vector<uint64_t> idx);
    xt::xarray<int64_t> get_values();

    friend bool operator==(const Initialization_list&lhs, const Initialization_list&rhs);

private:

    xt::xarray<int64_t> get_1d_list_values();

    std::shared_ptr<std::unordered_map<std::string, int64_t>> working_param_values;
    std::shared_ptr<std::map<std::string, HDL_parameter>> external_parameters;

    std::vector<dimension_t> unpacked_dimensions;
    std::vector<dimension_t> packed_dimensions;

    bool last_dimension = true;
    std::vector<Expression> expression_leaves;
    std::vector<Initialization_list> lower_dimension_leaves;
};


#endif //MAKEFILEGEN_V2_INITIALIZATION_LIST_HPP
