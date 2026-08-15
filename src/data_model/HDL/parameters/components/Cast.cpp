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

#include <spdlog/spdlog.h>
#include "data_model/HDL/parameters/components/Cast.hpp"
#include "analysis/type_cast_engine.hpp"

#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>

CEREAL_REGISTER_TYPE(Cast)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Expression_base, Cast)

Cast::Cast(const Cast &other) {
    size = other.size;
    type_cast = other.type_cast;
    target_type = other.target_type;
    content = other.content;
}

Cast::Cast(Cast &&other) noexcept {
    size = other.size;
    type_cast = other.type_cast;
    target_type = other.target_type;
    content = other.content;
}

parameter_deps_t Cast::get_dependencies() const {
    parameter_deps_t deps;
    deps.merge(content->get_dependencies());
    if (size) deps.merge(size->get_dependencies());
    return deps;
}

std::expected<resolved_parameter, solver_errors> Cast::evaluate(const std::map<qualified_identifier, resolved_parameter> &context) {
    if (type_cast) {
        if (!container_size) return std::unexpected{missing_value};
        auto content_val = content->evaluate(context);
        if (!content_val.has_value()) return std::unexpected{missing_value};
        uint64_t container = 64;
        if (!container_size->packed_sizes.empty()) container = packed_width(*container_size);
        if (target_type == "signed" || target_type == "unsigned") {
            if (!content_val.value().is_integer()) {
                spdlog::warn("Casting of non scalar integer values is not supported");
                return std::unexpected{wrong_type};
            }
            if (target_type == "signed") {
                return type_cast_engine::to_signed(content_val.value().get_integer(), container);
            }
            return type_cast_engine::to_unsigned(content_val.value().get_integer(), container);
        }
        if (target_type == "int"){
            if (content_val.value().is_real()) {
                return type_cast_engine::to_int(content_val.value().get_real(), container);
            } else if (content_val.value().is_integer()) {
                return type_cast_engine::to_int(content_val.value().get_integer(), container);
            }
            spdlog::warn("Casting of non scalar integer values is not supported");
            return std::unexpected{wrong_type};
        }
    } else {
        auto content_val = content->evaluate(context);
        if (!content_val.has_value()) return std::unexpected{missing_value};
        if (!content_val.value().is_integer()) return content_val.value();
        if (!size) return std::unexpected{missing_value};
        auto raw_cast_size = size->evaluate(context);
        if (!raw_cast_size.has_value()) return std::unexpected{missing_value};
        if (!raw_cast_size.value().is_integer()) {
            spdlog::warn("Cast size evaluates to a non integer");
            return content_val.value();
        }
        auto raw_value = content_val.value().get_integer();
        auto cast_size = raw_cast_size.value().get_integer().get_value();
        if (cast_size <= 0) {
            spdlog::warn("Cast size must be a positive integer");
            return content_val.value();
        }
        if (cast_size >= 1024) {
            spdlog::warn("Cast size {} exceeds supported width, truncating to 1024 bits", cast_size);
            cast_size = 1024;
        }
        int1024_t mask = (int1024_t(1) << cast_size) - 1;
        hdl_integer result;
        result.set_value(raw_value.to_wide() & mask);
        result.set_size(cast_size);
        return result;
    }
        return std::unexpected{missing_value};
}

std::string Cast::print() const {
    std::string prefix;
    if (type_cast) prefix = target_type;
    else if (size) prefix = size->print();
    return  prefix + "'(" + content->print() + ")";
}

void Cast::propagate_expression(const qualified_identifier &constant_id,
    const std::shared_ptr<Expression_base> &value) {

    content->propagate_expression(constant_id, value);
    if (size) size->propagate_expression(constant_id, value);
}



void Cast::set_container_sizes(const resolved_type &s, const std::map<qualified_identifier, resolved_parameter> &context) {
    container_size = s;
    if (type_cast)
        content->set_container_sizes(s, context);
    else {
        if (!size) return;
        auto cast_size = size->evaluate(context);
        if (!cast_size.has_value() || !cast_size.value().is_integer()) return;
        resolved_type t;
        t.packed_sizes.push_back(cast_size.value().get_integer().get_value());
        t.packed_ascending.push_back(true);
        content->set_container_sizes(t, context);
    }
}

std::optional<resolved_type> Cast::resolve_expression_type(
    const std::map<qualified_identifier, resolved_parameter> &context) const {
    if (type_cast) {
        if (container_size && (!container_size->packed_sizes.empty() || !container_size->unpacked_sizes.empty())) {
            return container_size;
        }
        if (target_type == "real" || target_type == "shortreal" || target_type == "realtime") {
            resolved_type result;
            result.is_real = true;
            return result;
        }
    }
    if (size) {
        auto cast_size = size->evaluate(context);
        if (cast_size && cast_size->is_integer() && cast_size->get_integer().get_value() > 0) {
            uint64_t w = static_cast<uint64_t>(cast_size->get_integer().get_value());
            resolved_type result;
            result.packed_sizes.push_back(w);
            result.packed_ascending.push_back(false);
            result.packed_left.push_back(static_cast<int64_t>(w) - 1);
            result.packed_right.push_back(0);
            return result;
        }
    }
    if (content) return content->resolve_expression_type(context);
    return std::nullopt;
}


bool Cast::isEqual(const Expression_base &other) const {

    const auto& rhs = static_cast<const Cast&>(other);
    bool res = true;
    res &= *content == *rhs.content;
    if (size && rhs.size) res &= *size == *rhs.size;
    else if (size || rhs.size) return false;
    res &= type_cast == rhs.type_cast;
    res &= target_type == rhs.target_type;
    return res;
}
