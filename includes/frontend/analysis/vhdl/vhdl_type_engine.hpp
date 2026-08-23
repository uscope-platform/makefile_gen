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

#ifndef ANANKE_VHDL_TYPE_ENGINE_HPP
#define ANANKE_VHDL_TYPE_ENGINE_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "data_model/HDL/types/hdl_type.hpp"
#include "data_model/HDL/types/HDL_simple_type.hpp"
#include "data_model/HDL/types/HDL_struct_type.hpp"
#include "data_model/HDL/types/HDL_enum_type.hpp"
#include "data_model/HDL/types/HDL_external_type.hpp"
#include "data_model/HDL/parameters/common/qualified_identifier.hpp"
#include "data_model/HDL/parameters/common/dimension.hpp"
#include "data_model/HDL/parameters/components/Expression_base.hpp"
#include "data_model/HDL/parameters/components/Expression_v2.hpp"
#include "data_model/HDL/factories/parameters/expressions_factory.hpp"

// Kind of a local `type X is ...` declaration.
enum class vhdl_type_kind {
    none,
    enumeration,
    scalar,
    array,
    record
};

// VHDL type resolution: maps `subtype_indication`s and local `type`/`subtype`
// declarations onto the shared hdl_type model. The engine is driven from the
// vhdl_visitor: range bound expressions are routed into it by the expression
// listener callbacks, mirroring how the SystemVerilog Type_engine collects
// dimension ranges. A small context stack keeps nested resolution (record
// member types, array element types) working inside a type declaration.
class vhdl_type_engine {
public:
    vhdl_type_engine() = default;

    // --- per-file type/subtype registry ---
    void register_type(const std::string &name, const std::shared_ptr<hdl_type> &t);
    bool has_type(const std::string &name) const;
    std::shared_ptr<hdl_type> get_type(const std::string &name) const;

    // --- subtype resolution (generic/port subtype, declaration element types) ---
    void start_type_resolution();
    void set_type_mark(const std::string &name);
    std::shared_ptr<hdl_type> finish_type_resolution();
    bool in_subtype_context() const;

    // --- type declaration (type X is ...) ---
    void start_type_declaration(const std::string &name);
    void set_declaration_kind(vhdl_type_kind kind);
    void add_enum_literal(const std::string &name);
    void begin_record_element(const std::vector<std::string> &names);
    void end_record_element(const std::shared_ptr<hdl_type> &member_type);
    void set_array_element_type(const std::shared_ptr<hdl_type> &t);
    std::shared_ptr<hdl_type> finish_type_declaration();
    bool in_declaration() const;

    // --- range / constraint accumulation (driven by visitor expression callbacks) ---
    bool active() const { return !context_stack.empty(); }
    bool in_range() const { return range_active; }
    void start_array_constraint();
    void stop_array_constraint();
    bool in_array_constraint() const { return in_index_constraint; }
    void start_range();
    void start_bound_expression(bool nonleaf);
    void add_range_component(const std::shared_ptr<Expression_base> &c);
    void set_range_operation(Expression_v2::expression_operator op);
    void stop_bound_expression(bool nonleaf);
    void stop_range(bool descending);

private:
    std::shared_ptr<hdl_type> make_base_type(const std::string &name);
    std::vector<dimension_t> &current_dimension_target();

    enum class build_context { subtype, declaration };
    std::vector<build_context> context_stack;

    std::map<std::string, std::shared_ptr<hdl_type>> type_registry;

    // subtype resolution state
    std::string type_mark_name;
    std::vector<dimension_t> array_dimensions;

    // type declaration state
    std::string declared_type_name;
    vhdl_type_kind decl_kind = vhdl_type_kind::none;
    std::vector<std::string> enum_members;
    std::vector<struct_member> record_members;
    std::vector<std::string> pending_element_names;
    std::vector<dimension_t> decl_array_dims;
    std::shared_ptr<hdl_type> array_element_type;

    // range accumulation
    bool in_index_constraint = false;
    bool range_active = false;
    expressions_factory range_expr;
    std::vector<std::shared_ptr<Expression_base>> range_bounds;
};

#endif //ANANKE_VHDL_TYPE_ENGINE_HPP