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
    return Parameter_value_base::get_dependencies();
}

bool Ternary::propagate_constant(const qualified_identifier &constant_id, const resolved_parameter &value) {
    return Parameter_value_base::propagate_constant(constant_id, value);
}

std::optional<resolved_parameter> Ternary::evaluate(bool pack_result) {
    return Parameter_value_base::evaluate(pack_result);
}

std::string Ternary::print() const {
    return Parameter_value_base::print();
}

int64_t Ternary::get_size() {
    return Parameter_value_base::get_size();
}

int64_t Ternary::get_depth() {
    return Parameter_value_base::get_depth();
}

bool Ternary::empty() const {
}

std::shared_ptr<Parameter_value_base> Ternary::clone_ptr() const {
}

bool Ternary::isEqual(const Parameter_value_base &other) const {
}
