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

#include <cmath>

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
    context_stack.push_back(build_context::subtype);
    type_mark_name.clear();
    array_dimensions.clear();
    range_bounds.clear();
    range_active = false;
    in_index_constraint = false;
}

bool vhdl_type_engine::in_subtype_context() const {
    return !context_stack.empty() && context_stack.back() == build_context::subtype;
}

void vhdl_type_engine::set_type_mark(const std::string &name) {
    if (in_subtype_context()) type_mark_name = name;
}

std::shared_ptr<hdl_type> vhdl_type_engine::finish_type_resolution() {
    if (context_stack.empty() || context_stack.back() != build_context::subtype) {
        spdlog::warn("vhdl_type_engine: finish_type_resolution without an active subtype");
        return std::make_shared<HDL_external_type>(qualified_identifier(type_mark_name));
    }
    context_stack.pop_back();

    auto base = make_base_type(type_mark_name);
    if (!array_dimensions.empty() && base->is<HDL_simple_type>()) {
        auto simple = base->as<HDL_simple_type>();
        simple.set_packed_dimensions(array_dimensions);
        base = std::make_shared<HDL_simple_type>(simple);
    }

    type_mark_name.clear();
    array_dimensions.clear();
    range_bounds.clear();
    range_active = false;
    in_index_constraint = false;
    return base;
}

void vhdl_type_engine::start_type_declaration(const std::string &name) {
    context_stack.push_back(build_context::declaration);
    declared_type_name = name;
    decl_kind = vhdl_type_kind::none;
    enum_members.clear();
    record_members.clear();
    pending_element_names.clear();
    decl_array_dims.clear();
    array_element_type = nullptr;
    range_bounds.clear();
    range_active = false;
    in_index_constraint = false;
}

bool vhdl_type_engine::in_declaration() const {
    return !context_stack.empty() && context_stack.back() == build_context::declaration;
}

void vhdl_type_engine::set_declaration_kind(vhdl_type_kind kind) {
    decl_kind = kind;
}

void vhdl_type_engine::add_enum_literal(const std::string &name) {
    if (in_declaration() && decl_kind == vhdl_type_kind::enumeration)
        enum_members.push_back(name);
}

void vhdl_type_engine::begin_record_element(const std::vector<std::string> &names) {
    if (in_declaration() && decl_kind == vhdl_type_kind::record)
        pending_element_names = names;
}

void vhdl_type_engine::end_record_element(const std::shared_ptr<hdl_type> &member_type) {
    if (!in_declaration() || decl_kind != vhdl_type_kind::record) return;
    for (const auto &n : pending_element_names)
        record_members.push_back({n, member_type});
    pending_element_names.clear();
}

void vhdl_type_engine::set_array_element_type(const std::shared_ptr<hdl_type> &t) {
    if (in_declaration() && decl_kind == vhdl_type_kind::array)
        array_element_type = t;
}

std::shared_ptr<hdl_type> vhdl_type_engine::finish_type_declaration() {
    if (context_stack.empty() || context_stack.back() != build_context::declaration) {
        spdlog::warn("vhdl_type_engine: finish_type_declaration without an active declaration");
        return std::make_shared<HDL_external_type>(qualified_identifier(declared_type_name));
    }
    context_stack.pop_back();

    std::shared_ptr<hdl_type> result;
    switch (decl_kind) {
        case vhdl_type_kind::enumeration: {
            auto e = std::make_shared<HDL_enum_type>();
            for (size_t i = 0; i < enum_members.size(); i++)
                e->members.push_back({enum_members[i], static_cast<uint64_t>(i)});
            result = e;
            break;
        }
        case vhdl_type_kind::scalar: {
            auto t = std::make_shared<HDL_simple_type>();
            t->set_type_name(declared_type_name);
            t->set_packed_dimensions(decl_array_dims);
            result = t;
            break;
        }
        case vhdl_type_kind::array: {
            // Arrays of bit-like elements are modeled as packed vectors; arrays
            // of other element types aren't representable in the shared type
            // model yet, so they degrade to an external (unknown) type.
            bool bit_like = array_element_type && array_element_type->is<HDL_simple_type>() &&
                (array_element_type->as<HDL_simple_type>().get_type_name() == "std_logic" ||
                 array_element_type->as<HDL_simple_type>().get_type_name() == "bit" ||
                 array_element_type->as<HDL_simple_type>().get_type_name() == "boolean");
            if (bit_like) {
                auto t = std::make_shared<HDL_simple_type>();
                t->set_type_name(declared_type_name);
                t->set_packed_dimensions(decl_array_dims);
                result = t;
            } else {
                result = std::make_shared<HDL_external_type>(qualified_identifier(declared_type_name));
            }
            break;
        }
        case vhdl_type_kind::record: {
            auto r = std::make_shared<HDL_struct_type>();
            r->member = record_members;
            result = r;
            break;
        }
        default:
            result = std::make_shared<HDL_external_type>(qualified_identifier(declared_type_name));
            break;
    }

    if (!declared_type_name.empty())
        register_type(declared_type_name, result);

    declared_type_name.clear();
    decl_kind = vhdl_type_kind::none;
    enum_members.clear();
    record_members.clear();
    pending_element_names.clear();
    decl_array_dims.clear();
    array_element_type = nullptr;
    range_bounds.clear();
    range_active = false;
    in_index_constraint = false;
    return result;
}

// --- range / constraint accumulation ---

void vhdl_type_engine::start_array_constraint() {
    if (active()) in_index_constraint = true;
}

void vhdl_type_engine::stop_array_constraint() {
    in_index_constraint = false;
}

std::vector<dimension_t> &vhdl_type_engine::current_dimension_target() {
    return in_declaration() ? decl_array_dims : array_dimensions;
}

void vhdl_type_engine::start_range() {
    if (!active()) return;
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
    current_dimension_target().push_back(d);
    range_bounds.clear();
}

// --- base type from a type_mark name ---

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
    // Vectors: packed dimension(s) are applied by the caller.
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