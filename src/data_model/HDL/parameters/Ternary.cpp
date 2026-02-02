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


#include "data_model/HDL/parameters/Ternary.hpp"

Ternary::Ternary() {
    type = ternary;
}

std::set<qualified_identifier> Ternary::get_dependencies() const {
    std::set<qualified_identifier> ret_val;
    auto cond_deps = condition.get_dependencies();
    ret_val.insert(cond_deps.begin(), cond_deps.end());

    auto true_deps = true_value->get_dependencies();
    ret_val.insert(true_deps.begin(), true_deps.end());

    auto false_deps = false_value->get_dependencies();
    ret_val.insert(false_deps.begin(), false_deps.end());
    return ret_val;
}

bool Ternary::propagate_constant(const qualified_identifier &constant_id, const resolved_parameter &value) {
    bool ret = true;
    ret &= condition.propagate_constant(constant_id, value);
    ret &= true_value->propagate_constant(constant_id, value);
    ret &= false_value->propagate_constant(constant_id, value);
    return ret;
}

std::optional<resolved_parameter> Ternary::evaluate(bool pack_result) {
    auto condition_value = condition.evaluate(true);
    if (!condition_value.has_value()) return std::nullopt;
    auto int_val = std::get<int64_t>(condition_value.value());
    if (int_val == 0) {
        return false_value->evaluate(true);
    } else {
        return true_value->evaluate(true);
    }
}

std::string Ternary::print() const {
    return Parameter_value_base::print();
}

int64_t Ternary::get_depth() {
    auto true_depth = true_value->get_depth();
    auto false_depth = false_value->get_depth();
    return std::max(true_depth, false_depth) +1;
}

std::shared_ptr<Parameter_value_base> Ternary::clone_ptr() const {
    return std::make_shared<Ternary>(*this);
}

bool Ternary::isEqual(const Parameter_value_base &other) const {
        const auto& rhs = static_cast<const Ternary&>(other);

    bool ret_val = true;
    ret_val &= condition == rhs.condition;
    ret_val &= *true_value == *rhs.true_value;
    ret_val &= *false_value == *rhs.false_value;
    return ret_val;
}
