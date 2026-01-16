//  Copyright 2025 Filippo Savi
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


#include "data_model/HDL/parameters/HDL_function.hpp"

#include "analysis/loop_solver.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"

void HDL_function::start_assignment(const std::string &n, Expression idx) {
    if(idx.empty())
        assignments.push_back({name, {}, {}});
    else
        assignments.push_back({name, idx, {}});
}

void HDL_function::close_assignment(Expression val) {
    assignments.back().value = val;
}

bool HDL_function::is_scalar() const {
    return  loop_metadata.get_assignments().empty() && assignments.size() == 1;
}

bool HDL_function::operator==(const HDL_function &rhs) const {
    bool retval = true;
    retval &= name == rhs.name;
    retval &= assignments == rhs.assignments;
    retval &= loop_metadata == rhs.loop_metadata;
    return retval;
}

std::set<qualified_identifier> HDL_function::get_dependencies() const {
    std::set<qualified_identifier> res;


    for(auto &la:loop_metadata.get_assignments()) {
        auto deps = la.value.get_dependencies();
        res.insert(deps.begin(), deps.end());
        if(la.index.has_value()) {
            deps = la.index.value().get_dependencies();
            res.insert(deps.begin(), deps.end());
        }

    }
    auto loop_deps = loop_metadata.get_init().get_dependencies();
    res.insert(loop_deps.begin(), loop_deps.end());
    loop_deps = loop_metadata.get_end_c().get_dependencies();
    res.insert(loop_deps.begin(), loop_deps.end());
    loop_deps = loop_metadata.get_iter().get_dependencies();
    res.insert(loop_deps.begin(), loop_deps.end());

    res.erase({"", loop_metadata.get_init().get_name()});

    for(auto &a:assignments) {
        auto deps = a.value.get_dependencies();
        res.insert(deps.begin(), deps.end());
        if(a.index.has_value()) {
            deps = a.index.value().get_dependencies();
            res.insert(deps.begin(), deps.end());
        }
    }

    return res;
}

bool HDL_function::propagate_constant(const qualified_identifier &constant_id, const resolved_parameter &value) {
    bool retval = true;
    for(auto &a:assignments) {
        retval &= a.value.propagate_constant(constant_id, value);
        if(a.index.has_value()) retval &= a.index.value().propagate_constant(constant_id, value);
    }
    retval &= loop_metadata.propagate_constant(constant_id, value);
    return retval;
}

std::optional<resolved_parameter> HDL_function::evaluate_scalar() {
    return assignments[0].value.evaluate(false);
}

std::optional<resolved_parameter> HDL_function::evaluate_vector() {
    std::vector<int64_t> loop_indexes;
    if(!loop_metadata.get_init().is_empty()) {
        loop_indexes = loop_solver::solve_loop(loop_metadata);
    } else {
        loop_indexes = {};
    }
    std::vector<int64_t> values(assignments.size() + loop_indexes.size());
    for(auto &a:assignments) {
        auto idx = a.index.value().evaluate(false);
        if(!idx.has_value()) return std::nullopt;
        if(!std::holds_alternative<int64_t>(idx.value())) return std::nullopt;
        auto idx_val = std::get<int64_t>(idx.value());
        auto value = a.value.evaluate(false);
        if(!value.has_value()) return std::nullopt;
        values[idx_val] = std::get<int64_t>(value.value());
    }

    qualified_identifier loop_var = {"", loop_metadata.get_init().get_name()};
    auto loop_assignments = loop_metadata.get_assignments();
    for(int i = 0; i<loop_assignments.size(); i++) {
        for(auto &l:loop_indexes) {
            auto la = loop_assignments[i];
            la.index.value().propagate_constant(loop_var, l);
            auto idx = la.index.value().evaluate(false);
            la.value.propagate_constant(loop_var, l);
            auto var = la.value.evaluate(false);
            values[std::get<int64_t>(idx.value())] = std::get<int64_t>(var.value());
        }
    }

    mdarray<int64_t> result;
    result.set_1d_slice({0, 0}, values);
    return result;
}

std::optional<resolved_parameter> HDL_function::evaluate(bool pack_result) {
    if( loop_metadata.get_assignments().empty() && assignments.size() == 1) {
        return evaluate_scalar();
    } else {
        return evaluate_vector();
    }
}
