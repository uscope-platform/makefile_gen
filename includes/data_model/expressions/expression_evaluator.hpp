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

#ifndef MAKEFILEGEN_V2_EXPRESSION_EVALUATOR_HPP
#define MAKEFILEGEN_V2_EXPRESSION_EVALUATOR_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <set>

#include "data_model/expressions/bus_mapping_expression.hpp"
#include "data_model/HDL/HDL_Resource.hpp"
#include "data_model/HDL/HDL_instance.hpp"
#include "data_model/bus_mapping/address_resolver.hpp"

class expression_evaluator {
public:

    static uint32_t calculate_expression(std::vector<std::string> exp);

    static uint32_t calculate_expression(bus_mapping_expression exp, std::unordered_map<std::string, uint32_t> params);
    static std::vector<std::string> get_variable_names(bus_mapping_expression exp);
    static uint32_t calculate_expression(const bus_mapping_expression& exp, HDL_Resource &res, HDL_instance &dep, address_resolver &resolver);
};


#endif //MAKEFILEGEN_V2_EXPRESSION_EVALUATOR_HPP
