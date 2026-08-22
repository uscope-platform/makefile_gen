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
#include "data_model/HDL/types/HDL_external_type.hpp"
#include "data_model/HDL/parameters/common/qualified_identifier.hpp"
#include "data_model/HDL/parameters/common/dimension.hpp"
#include "data_model/HDL/parameters/components/Expression_base.hpp"
#include "data_model/HDL/parameters/components/Expression_v2.hpp"
#include "data_model/HDL/factories/parameters/expressions_factory.hpp"

// VHDL type resolution: maps a `subtype_indication` (type_mark + optional
// array/range constraint) onto the shared hdl_type model. The engine is driven
// from the vhdl_visitor: range bound expressions are routed into it by the
// expression listener callbacks, mirroring how the SystemVerilog Type_engine
// collects dimension ranges.
class vhdl_type_engine {
public:
    vhdl_type_engine() = default;

    // --- per-file type/subtype registry (type/subtype declarations) ---
    void register_type(const std::string &name, const std::shared_ptr<hdl_type> &t);
    bool has_type(const std::string &name) const;
    std::shared_ptr<hdl_type> get_type(const std::string &name) const;

    // --- subtype resolution ---
    void start_type_resolution();
    void set_type_mark(const std::string &name);
    bool active() const { return resolving; }

    // array constraint (index_constraint): dimensions are collected here
    void start_array_constraint();
    void stop_array_constraint();
    bool in_array_constraint() const { return in_index_constraint; }

    // range accumulation (explicit_range)
    void start_range();
    void start_bound_expression(bool nonleaf);
    void add_range_component(const std::shared_ptr<Expression_base> &c);
    void set_range_operation(Expression_v2::expression_operator op);
    void stop_bound_expression(bool nonleaf);
    void stop_range(bool descending);
    bool in_range() const { return range_active; }

    std::shared_ptr<hdl_type> finish_type_resolution();

private:
    std::shared_ptr<hdl_type> make_base_type(const std::string &name);

    std::map<std::string, std::shared_ptr<hdl_type>> type_registry;
    bool resolving = false;
    std::string type_mark_name;

    bool in_index_constraint = false;
    bool range_active = false;
    expressions_factory range_expr;
    std::vector<std::shared_ptr<Expression_base>> range_bounds;

    std::vector<dimension_t> array_dimensions;
};

#endif //ANANKE_VHDL_TYPE_ENGINE_HPP