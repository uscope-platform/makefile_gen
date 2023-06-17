//  Copyright 2023 Filippo Savi
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

#include "data_model/HDL/HDL_parameter.hpp"


HDL_parameter::HDL_parameter() {
    type = string_parameter;
}


std::string HDL_parameter::get_string_value() {
    if(value.empty())
        return default_value;
    else
        return value;
}

bool operator==(const HDL_parameter &lhs, const HDL_parameter &rhs) {
    bool ret_val = true;
    ret_val &= lhs.name == rhs.name;
    ret_val &= lhs.default_value == rhs.default_value;
    ret_val &= lhs.value == rhs.value;

    return ret_val;
}

bool operator<(const HDL_parameter &lhs, const HDL_parameter &rhs) {
    return lhs.name<rhs.name;
}

bool HDL_parameter::is_empty() {
    bool ret = true;

    ret &= name.empty();
    ret &= default_value.empty();
    ret &= value.empty();

    return ret;
}

void HDL_parameter::set_value(uint32_t val) {
    type = numeric_parameter;
    numeric_value = val;
}

void HDL_parameter::set_value(const std::string &v) {
    type = string_parameter;
    value = v;
}

void HDL_parameter::set_default_value(const std::string &dv) {
    type = string_parameter;
    default_value = dv;
}

uint32_t HDL_parameter::get_numeric_value() {
    return numeric_value;
}
