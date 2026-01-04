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

std::optional<resolved_parameter> Replication::evaluate(bool packed) {
    mdarray<int64_t> result;
    auto raw_size = repetition_size.evaluate();
    if (!raw_size.has_value()) return false;
    if (!std::holds_alternative<int64_t>(raw_size.value())) return false;
    auto size = std::get<int64_t>(raw_size.value());
    mdarray<int64_t>::md_1d_array repeated_value;
    if (std::holds_alternative<Expression>(repeated_item)) {
        int64_t repeated_size;
        auto item = std::get<Expression>(repeated_item).evaluate(&repeated_size);
        if (!item.has_value()) return false;
        if (!std::holds_alternative<int64_t>(item.value())) throw std::runtime_error("Tried to replicate non integer");
        if (!packed) {
            repeated_value = std::vector(size, std::get<int64_t>(item.value()));
        } else {
            return pack_repetition(std::get<int64_t>(item.value()), repeated_size, size);
        }
    } else if (std::holds_alternative<Concatenation>(repeated_item)) {
        auto raw_item = std::get<Concatenation>(repeated_item).evaluate(packed);
        if (!raw_item.has_value()) return std::nullopt;
        auto item = raw_item.value();
        if (std::holds_alternative<int64_t>(item))
            repeated_value = std::vector(size, std::get<int64_t>(item));
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

int64_t Replication::pack_repetition(int64_t value, int64_t width, int64_t count) {
    int64_t packed_result = 0;

    int64_t mask = (static_cast<int64_t>(1) << width) - 1;
    int64_t clean_value = value & mask;

    for (int i = 0; i < count; i++) {
        int64_t shift_amount = static_cast<int64_t>(i) * width;
        packed_result |= (clean_value << shift_amount);
    }

    return packed_result;
}

std::string Replication::print() const {
    std::ostringstream oss;
    oss << "{" << repetition_size.print()<<"{";
    if (std::holds_alternative<Expression>(repeated_item))oss << std::get<Expression>(repeated_item).print();
    else if(std::holds_alternative<Concatenation>(repeated_item)) oss <<std::get<Concatenation>(repeated_item).print();
    oss << "}}";
    return oss.str();
}
