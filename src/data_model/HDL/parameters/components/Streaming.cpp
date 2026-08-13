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

#include "data_model/HDL/parameters/components/Streaming.hpp"
#include "data_model/HDL/parameters/components/token/Numeric_token.hpp"

#include <sstream>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>

CEREAL_REGISTER_TYPE(Streaming)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Expression_base, Streaming)

parameter_deps_t Streaming::get_dependencies() const {
    parameter_deps_t result;
    for (const auto &comp : components) result.merge(comp->get_dependencies());
    if (slice_size) result.merge(slice_size->get_dependencies());
    return result;
}

void Streaming::propagate_expression(const qualified_identifier &constant_id,
    const std::shared_ptr<Expression_base> &value) {
    for (auto &comp : components) comp->propagate_expression(constant_id, value);
    if (slice_size) slice_size->propagate_expression(constant_id, value);
}

void Streaming::propagate_function(const hdl_function_statement &def) {
    for (auto &comp : components) comp->propagate_function(def);
    if (slice_size) slice_size->propagate_function(def);
}

static hdl_integer reverse_bits(hdl_integer value, int64_t width) {
    hdl_integer result = 0;
    for (int64_t i = 0; i < width; i++) {
        hdl_integer bit = (value >> static_cast<int64_t>(i)) & hdl_integer(1);
        if (bit.get_value()) result |= (hdl_integer(1) << (width - 1 - i));
    }
    return result;
}

std::optional<resolved_parameter> Streaming::evaluate(const std::map<qualified_identifier, resolved_parameter> &context) {
    if (components.empty()) return std::nullopt;

    // Evaluate all components; use declared literal width when available.
    std::vector<hdl_integer> values;
    std::vector<int64_t> widths;
    int64_t total_width = 0;
    for (const auto &comp : components) {
        auto v = comp->evaluate(context);
        if (!v.has_value() || !v.value().is_integer()) return std::nullopt;
        auto raw = v.value().get_integer();
        int64_t w = 0;
        if (auto num = std::dynamic_pointer_cast<Numeric_token>(comp)) w = num->get_size();
        if (w <= 0) w = raw.get_size();
        widths.push_back(w);
        values.push_back(raw);
        total_width += w;
    }

    // Build P = MSB-first concatenation: components[0] is the most significant.
    hdl_integer P = 0;
    int64_t shift = total_width;
    for (size_t i = 0; i < values.size(); i++) {
        shift -= widths[i];
        hdl_integer masked = values[i] & ((widths[i] >= 64) ? ~0ULL : (1ULL << widths[i]) - 1);
        P |= masked << shift;
    }

    // Determine slice size (default 1).
    int64_t slice = 1;
    if (slice_size) {
        auto s = slice_size->evaluate(context);
        if (s.has_value() && s.value().is_integer() && s.value().get_integer().get_value() > 0)
            slice = s.value().get_integer().get_value();
    }

    // Split P into slices from MSB.
    std::vector<hdl_integer> slices;
    for (int64_t off = total_width; off > 0; off -= slice) {
        int64_t start = off - slice;
        if (start < 0) start = 0;
        int64_t w = off - start;
        hdl_integer mask = (w >= 64) ? ~0ULL : (1ULL << w) - 1;
        slices.push_back((P >> start) & mask);
    }

    // Assemble the result.
    hdl_integer result = 0;
    int64_t out_shift = 0;
    if (direction == left) {
        // Left-to-right: reverse slice order, bits within slice unchanged.
        for (size_t i = 0; i < slices.size(); i++) {
            int64_t w = total_width - static_cast<int64_t>(i) * slice;
            if (w > slice) w = slice;
            result |= slices[i] << out_shift;
            out_shift += w;
        }
    } else {
        // Right-to-left: keep slice order, reverse bits within each slice.
        for (const auto &s : slices) {
            hdl_integer rs = reverse_bits(s, slice);
            result |= rs << out_shift;
            out_shift += slice;
        }
    }

    return resolved_parameter(result);
}

std::string Streaming::print() const {
    std::ostringstream oss;
    oss << "{";
    if (direction == left) oss << "<<";
    else oss << ">>";
    if (slice_size) oss << slice_size->print();
    oss << "{";
    for (size_t i = 0; i < components.size(); i++) {
        if (i > 0) oss << ", ";
        oss << components[i]->print();
    }
    oss << "}}";
    return oss.str();
}

void Streaming::set_container_sizes(const resolved_type &s,
    const std::map<qualified_identifier, resolved_parameter> &context) {
    for (auto &comp : components) comp->set_container_sizes(s, context);
    if (slice_size) slice_size->set_container_sizes(s, context);
}

bool operator==(const Streaming &lhs, const Streaming &rhs) {
    if (lhs.direction != rhs.direction) return false;
    if (lhs.components.size() != rhs.components.size()) return false;
    for (size_t i = 0; i < lhs.components.size(); i++) {
        if (!(*lhs.components[i] == *rhs.components[i])) return false;
    }
    if (lhs.slice_size && rhs.slice_size) {
        if (!(*lhs.slice_size == *rhs.slice_size)) return false;
    } else if (lhs.slice_size || rhs.slice_size) {
        return false;
    }
    return true;
}

bool Streaming::isEqual(const Expression_base &other) const {
    const auto &rhs = static_cast<const Streaming &>(other);
    return *this == rhs;
}
