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

#include "data_model/HDL/parameters/HDL_function_call.hpp"

#include "analysis/loop_solver.hpp"
#include "data_model/HDL/parameters/Expression.hpp"

void HDL_function_call::add_argument(const std::shared_ptr<Parameter_value_base> &p) {
    arguments.push_back(p);
}

std::set<qualified_identifier> HDL_function_call::get_dependencies() const {
    std::set<qualified_identifier> retval;
    for (auto &arg:arguments) {
        auto deps = arg->get_dependencies();
        retval.insert(deps.begin(), deps.end());
    }
    return retval;
}

bool HDL_function_call::propagate_constant(const qualified_identifier &constant_id, const resolved_parameter &value) {
    bool retval = true;
    for (auto &arg:arguments) {
        retval &= arg->propagate_constant(constant_id, value);
    }
    return  retval;
}

void HDL_function_call::propagate_function(const HDL_function_def &def) {
    if(def.name == function_name) {
        assignments = def.get_assignments();
        loop_metadata = def.get_loop();
    }
}

std::optional<resolved_parameter> HDL_function_call::evaluate(bool pack_result) {
    if( !loop_metadata.has_value() && assignments.size() == 1) {
        return evaluate_scalar();
    } else {
        return evaluate_vector();
    }
}

std::optional<resolved_parameter> HDL_function_call::evaluate_scalar() {
    return assignments[0].get_value()->evaluate(false);
}

std::optional<resolved_parameter> HDL_function_call::evaluate_vector() {
    std::vector<int64_t> loop_indexes;
    if(loop_metadata.has_value()) {
        loop_indexes = loop_solver::solve_loop(loop_metadata.value());

        qualified_identifier loop_var = {"", loop_metadata.value().get_init().get_name()};
    } else {
        loop_indexes = {};
    }
    std::vector<int64_t> values(assignments.size() + loop_indexes.size());
    for(auto &a:assignments) {
        auto idx = a.get_index().value()->evaluate(false);
        if(!idx.has_value()) return std::nullopt;
        if(!std::holds_alternative<int64_t>(idx.value())) return std::nullopt;
        auto idx_val = std::get<int64_t>(idx.value());
        auto value = a.get_value()->evaluate(false);
        if(!value.has_value()) return std::nullopt;
        values[idx_val] = std::get<int64_t>(value.value());
    }

    if(loop_metadata.has_value()) {
        qualified_identifier loop_var = {"", loop_metadata.value().get_init().get_name()};
        auto loop_assignments = loop_metadata.value().get_assignments();
        for(int i = 0; i<loop_assignments.size(); i++) {
            for(auto &l:loop_indexes) {
                auto la = loop_assignments[i].clone();
                la.get_index().value()->propagate_constant(loop_var, l);
                auto idx = la.get_index().value()->evaluate(false);
                la.get_value()->propagate_constant(loop_var, l);
                auto var = la.get_value()->evaluate(false);
                values[std::get<int64_t>(idx.value())] = std::get<int64_t>(var.value());
            }
        }
    }

    mdarray<int64_t> result;
    result.set_1d_slice({0, 0}, values);
    return result;
}




std::string HDL_function_call::print() const {
    std::ostringstream result;
    result << function_name << "(";
    for(int i = 0; i< arguments.size(); i++) {
        result << arguments[0]->print();
        if( arguments.size()>1 && i<arguments.size()-1) result << ", ";
    }
    result << ")";
    return result.str();
}

int64_t HDL_function_call::get_size() {
    return 0;
}

int64_t HDL_function_call::get_depth() {
    int64_t ret = 1;
    for(auto &comp:arguments){
        if(comp->is_concatenation() || comp->is_replication()) {
            auto child_ret = comp->get_depth();
            ret = std::max(ret, child_ret+1);
        }

    }
    return ret;
}

bool HDL_function_call::empty() const {
    return function_name.empty();
}

std::shared_ptr<Parameter_value_base> HDL_function_call::clone_ptr() const {
    HDL_function_call c;
    for (auto &arg:arguments) {
        c.add_argument(arg->clone_ptr());
    }
    c.set_name(function_name);
    c.loop_metadata = loop_metadata;
    c.assignments = assignments;
    return std::make_shared<HDL_function_call>(c);
}

bool HDL_function_call::isEqual(const Parameter_value_base &other) const {
    bool is_equal = true;


    const auto& rhs = static_cast<const HDL_function_call&>(other);
    is_equal &= function_name == rhs.function_name;
    if (arguments.size() != rhs.arguments.size()) return false;
    for (int i = 0; i< arguments.size(); i++) {
        is_equal &= *arguments[i] == *rhs.arguments[i];
    }
    is_equal &= loop_metadata == rhs.loop_metadata;
    is_equal &= assignments == rhs.assignments;
    return is_equal;
}
