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

#include "frontend/analysis/vhdl/vhdl_type_engine.hpp"

#include <spdlog/spdlog.h>

void vhdl_type_engine::register_type(const std::string &name, const std::shared_ptr<hdl_type> &t) {
    type_registry[name] = t;
}

bool vhdl_type_engine::has_type(const std::string &name) const {
    return type_registry.contains(name);
}

std::shared_ptr<hdl_type> vhdl_type_engine::get_type(const std::string &name) const {
    return type_registry.at(name);
}

void vhdl_type_engine::start_type_resolution() {
    resolving = true;
    type_mark_name.clear();
    array_dimensions.clear();
    range_bounds.clear();
    range_active = false;
    in_index_constraint = false;
}

void vhdl_type_engine::set_type_mark(const std::string &name) {
    if (resolving) type_mark_name = name;
}

void vhdl_type_engine::start_array_constraint() {
    if (resolving) in_index_constraint = true;
}

void vhdl_type_engine::stop_array_constraint() {
    in_index_constraint = false;
}

void vhdl_type_engine::start_range() {
    if (!resolving) return;
    range_active = true;
    range_bounds.clear();
    range_expr.clear_expression();
}

void vhdl_type_engine::start_bound_expression(bool nonleaf) {
    range_expr.start_expression(nonleaf);
}

void vhdl_type_engine::add_range_component(const std::shared_ptr<Expression_base> &c) {
    range_expr.add_component(c);
}

void vhdl_type_engine::set_range_operation(Expression_v2::expression_operator op) {
    range_expr.set_operation(op);
}

void vhdl_type_engine::stop_bound_expression(bool nonleaf) {
    range_expr.stop_expression(nonleaf);
    if (range_expr.get_level() == 0) {
        auto expr = range_expr.get_expression_v2();
        if (expr.has_value()) {
            if (expr->get_operation() != Expression_v2::none) {
                range_bounds.push_back(Expression_v2::unwrap(expr.value()));
            } else if (auto lhs = expr->get_lhs()) {
                range_bounds.push_back(lhs);
            }
        }
        range_expr.clear_expression();
    }
}

void vhdl_type_engine::stop_range(bool descending) {
    if (!range_active) return;
    range_active = false;
    if (range_bounds.size() < 2) {
        range_bounds.clear();
        return;
    }

    dimension_t d;
    d.first_bound = range_bounds[0];
    d.second_bound = range_bounds[1];
    d.packed = true;
    // descending (downto): first > second; ascending (to): first < second.
    array_dimensions.push_back(d);
    range_bounds.clear();
}

std::shared_ptr<hdl_type> vhdl_type_engine::make_base_type(const std::string &name) {
    auto t = std::make_shared<HDL_simple_type>();

    // 1-bit scalar logic/boolean types.
    if (name == "bit" || name == "std_logic" || name == "boolean" || name == "character") {
        t->set_type_name(name);
        return t;
    }
    // Integer-like scalars (unbounded; no packed dimension).
    if (name == "integer") {
        t->set_type_name(name);
        t->set_signed(true);
        return t;
    }
    if (name == "natural" || name == "positive") {
        t->set_type_name(name);
        return t;
    }
    if (name == "real") {
        t->set_type_name(name);
        t->set_real(true);
        return t;
    }
    if (name == "time") {
        t->set_type_name(name);
        return t;
    }
    // Vectors: packed dimension(s) are applied by finish_type_resolution.
    if (name == "std_logic_vector" || name == "bit_vector") {
        t->set_type_name(name);
        return t;
    }
    if (name == "signed") {
        t->set_type_name(name);
        t->set_signed(true);
        return t;
    }
    if (name == "unsigned") {
        t->set_type_name(name);
        return t;
    }

    // A locally declared type/subtype.
    if (auto it = type_registry.find(name); it != type_registry.end()) {
        return it->second;
    }

    // Anything else (work.*, unknown) degrades to an external type reference.
    return std::make_shared<HDL_external_type>(qualified_identifier(name));
}

std::shared_ptr<hdl_type> vhdl_type_engine::finish_type_resolution() {
    auto base = make_base_type(type_mark_name);

    if (!array_dimensions.empty() && base->is<HDL_simple_type>()) {
        auto simple = base->as<HDL_simple_type>();
        simple.set_packed_dimensions(array_dimensions);
        base = std::make_shared<HDL_simple_type>(simple);
    }

    resolving = false;
    type_mark_name.clear();
    array_dimensions.clear();
    range_bounds.clear();
    range_active = false;
    in_index_constraint = false;
    return base;
}