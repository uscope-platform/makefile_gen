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

#include "data_model/HDL/parameters/components/Replication.hpp"
#include "data_model/HDL/parameters/components/Concatenation.hpp"
#include "data_model/HDL/parameters/components/Expression_v2.hpp"
#include "data_model/HDL/parameters/components/token/Numeric_token.hpp"
#include "data_model/HDL/parameters/components/Expression_base.hpp"

#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>

CEREAL_REGISTER_TYPE(Replication)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Expression_base, Replication)


Replication::Replication(const Replication &other) {
    repetition_size = other.repetition_size;
    repeated_item = other.repeated_item;
}

Replication::Replication(Replication &&other) noexcept {
    repetition_size = other.repetition_size;
    repeated_item = other.repeated_item;
}

Replication & Replication::operator=(const Replication &other) {
    if (this != &other) {
        repetition_size = other.repetition_size;
        repeated_item = other.repeated_item;
    }
    return *this;
}

Replication & Replication::operator=(Replication &&other) noexcept {
    if (this != &other) {
        repetition_size = other.repetition_size;
        repeated_item = other.repeated_item;
    }
    return *this;
}

void Replication::set_size(const std::shared_ptr<Expression_base> &size) { repetition_size = size;}

parameter_deps_t Replication::get_dependencies()const {
    parameter_deps_t result;
    result.merge(repetition_size->get_dependencies());
    result.merge(repeated_item->get_dependencies());
    return result;
}


void Replication::propagate_expression(const qualified_identifier &constant_id,
    const std::shared_ptr<Expression_base> &value) {
    repetition_size->propagate_expression(constant_id, value);
    repeated_item->propagate_expression(constant_id, value);
}

void Replication::propagate_function(const hdl_function_statement &def) {
    repetition_size->propagate_function(def);
    repeated_item->propagate_function(def);
}

std::optional<resolved_parameter> Replication::evaluate(const std::map<qualified_identifier, resolved_parameter> &context) {
    mdarray<hdl_integer> result;
    auto raw_size = repetition_size->evaluate(context);
    if (!raw_size.has_value()) return std::nullopt;
    if (!raw_size.value().is_integer()) return std::nullopt;
    auto size = raw_size.value().get_integer().get_value();
    if (size <= 0) return std::nullopt;
    mdarray<hdl_integer>::md_1d_array repeated_value;
    if (repeated_item->is<Expression_v2>()) {
        auto item = repeated_item->as<Expression_v2>().evaluate(context);
        if (!item.has_value()) return std::nullopt;
        if (!item.value().is_integer()) throw std::runtime_error("Tried to replicate non integer");
        int64_t repeated_size = item.value().get_integer().get_size();
        if (!packing) {
            repeated_value = std::vector(size, item.value().get_integer());
        } else {
            return pack_repetition(item.value().get_integer() , repeated_size, size);
        }
    } else if (repeated_item->is<Concatenation>()) {

        auto raw_item = repeated_item->as<Concatenation>().evaluate(context);
        if (!raw_item.has_value()) return std::nullopt;
        auto item = raw_item.value();
        if (item.is_integer())
            repeated_value = std::vector(size, item.get_integer());
        else {
            auto  item_vect = item.get_int_array().get_1d_slice({0,0});
            for (int i = 0; i< size; i++) {
                repeated_value.insert(repeated_value.end(), item_vect.begin(), item_vect.end());
            }
        }
    } else if (!repeated_item->is<Expression_v2>() && !repeated_item->is<Concatenation>()){
        auto item = repeated_item->evaluate(context);
        if (!item.has_value()) return std::nullopt;
        if (!item.value().is_integer()) throw std::runtime_error("Tried to replicate non integer");
        auto num = std::dynamic_pointer_cast<Numeric_token>(repeated_item);
        int64_t repeated_size = num ? num->get_size() : 0;
        if (repeated_size <= 0) repeated_size = item.value().get_integer().get_size();
        if (!packing) {
            repeated_value = std::vector(size, item.value().get_integer());
        } else {
            return pack_repetition(item.value().get_integer() , repeated_size, size);
        }
    } else {
        throw std::runtime_error("Encountered a unknown parameter value type");
    }

    result.set_1d_slice({0,0}, repeated_value);
    return result;
}

hdl_integer Replication::pack_repetition(hdl_integer value, int64_t width, int64_t count) {
    hdl_integer packed_result = 0;
    if (width <= 0 || count <= 0) return packed_result;

    hdl_integer mask = (hdl_integer(1) << hdl_integer(width)) - 1;
    auto clean_value = value & mask;

    for (int64_t i = 0; i < count; i++) {
        int64_t shift_amount = i * width;
        packed_result = packed_result | (clean_value << hdl_integer(shift_amount));
    }

    return packed_result;
}

std::string Replication::print() const {
    std::ostringstream oss;
    oss << "{" << repetition_size->print()<<"{";
    oss << repeated_item->print();
    oss << "}}";
    return oss.str();
}

void Replication::set_container_sizes(const resolved_type &s, const std::map<qualified_identifier, resolved_parameter> &context) {
    packing = s.unpacked_sizes.empty();
}

std::optional<resolved_type> Replication::resolve_expression_type(
    const std::map<qualified_identifier, resolved_parameter> &context) const {
    auto item_t = repeated_item ? repeated_item->resolve_expression_type(context) : std::nullopt;
    if (!item_t) return std::nullopt;

    uint64_t count = 1;
    if (repetition_size) {
        auto size = repetition_size->evaluate(context);
        if (size && size->is_integer() && size->get_integer().get_value() > 0) {
            count = static_cast<uint64_t>(size->get_integer().get_value());
        }
    }

    if (item_t->is_real) {
        resolved_type result;
        result.is_real = true;
        return result;
    }

    resolved_type result;
    for (auto ps : item_t->packed_sizes) result.packed_sizes.push_back(ps * count);
    result.packed_ascending = item_t->packed_ascending;
    for (auto l : item_t->packed_left) result.packed_left.push_back(l);
    for (auto r : item_t->packed_right) result.packed_right.push_back(r);
    return result;
}
