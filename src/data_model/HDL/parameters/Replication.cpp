//  Copyright 2026 Filippo Savi
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

#include "data_model/HDL/parameters/Replication.hpp"

std::set<std::string> Replication::get_dependencies()const {
    std::set<std::string> result, deps;
    deps = repetition_size.get_dependencies();
    result.insert(deps.begin(), deps.end());
    if (std::holds_alternative<Expression>(repeated_item))
        deps = std::get<Expression>(repeated_item).get_dependencies();
    else if (std::holds_alternative<Concatenation>(repeated_item))
        deps  = std::get<Concatenation>(repeated_item).get_dependencies();
    result.insert(deps.begin(), deps.end());
    return result;
}

bool Replication::propagate_constant(const std::string &name, const resolved_parameter &value) {
    bool result = true;

    result &= repetition_size.propagate_constant(name, value);
    if (std::holds_alternative<Expression>(repeated_item))
        result &= std::get<Expression>(repeated_item).propagate_constant(name, value);
    else if (std::holds_alternative<Concatenation>(repeated_item))
        result &= std::get<Concatenation>(repeated_item).propagate_constant(name, value);
    return result;
}

resolved_parameter Replication::evaluate() {
    mdarray<int64_t> result;
    auto raw_size = repetition_size.evaluate();
    if (!raw_size.has_value()) return false;
    if (!std::holds_alternative<int64_t>(raw_size.value())) return false;
    auto size = std::get<int64_t>(raw_size.value());
    mdarray<int64_t>::md_1d_array repeated_value;
    if (std::holds_alternative<Expression>(repeated_item)) {
        auto item = std::get<Expression>(repeated_item).evaluate();
        if (!item.has_value()) return false;
        if (!std::holds_alternative<int64_t>(item.value())) throw std::runtime_error("Tried to replicate non integer");
        repeated_value = std::vector<int64_t>(size, std::get<int64_t>(item.value()));
    } else if (std::holds_alternative<Concatenation>(repeated_item)) {
        auto item = std::get<Concatenation>(repeated_item).evaluate();

        if (std::holds_alternative<int64_t>(item))
            repeated_value = std::vector<int64_t>(size, std::get<int64_t>(item));
        else {
            auto  item_vect = std::get<mdarray<int64_t>>(item).get_1d_slice({0,0});
            for (int i = 0; i< size; i++) {
                repeated_value.insert(repeated_value.end(), item_vect.begin(), item_vect.end());
            }
        }
    }

    result.set_1d_slice({0,0}, repeated_value);
    return result;
}

std::string Replication::print() const {
    std::ostringstream oss;
    oss << "{" << repetition_size.print()<<"{";
    if (std::holds_alternative<Expression>(repeated_item))oss << std::get<Expression>(repeated_item).print();
    else if(std::holds_alternative<Concatenation>(repeated_item)) oss <<std::get<Concatenation>(repeated_item).print();
    oss << "}}";
    return oss.str();
}
