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

#include "data_model/HDL/parameters/HDL_parameter.hpp"


HDL_parameter::HDL_parameter(const HDL_parameter &c) {
    name = c.name;
    scope = c.scope;
    value = c.value;
    type = c.type;
    expression_components = c.expression_components;
    i_l = c.i_l;
    loop_index = c.loop_index;
}

HDL_parameter::HDL_parameter() {
    type = string_parameter;
    value = std::vector<std::string>({""});
}


std::string HDL_parameter::get_string_value() const {
    if (std::holds_alternative<std::vector<std::string>>(value))
        return std::get<std::vector<std::string>>(value)[0];
    else
        return "";
}

bool operator==(const HDL_parameter &lhs, const HDL_parameter &rhs) {
    bool ret_val = true;
    ret_val &= lhs.name == rhs.name;
    ret_val &= lhs.scope == rhs.scope;
    ret_val &= lhs.value == rhs.value;
    ret_val &= lhs.type == rhs.type;
    ret_val &= lhs.expression_components == rhs.expression_components;
    ret_val &= lhs.i_l == rhs.i_l;
    ret_val &= lhs.loop_index == rhs.loop_index;
    return ret_val;
}

bool operator<(const HDL_parameter &lhs, const HDL_parameter &rhs) {
    return lhs.name<rhs.name;
}

bool HDL_parameter::is_empty() {
    bool ret = true;

    ret &= name.empty();
    if(type == string_parameter) {
        auto str_arr = std::get<std::vector<std::string>>(value);
        ret &= str_arr.empty() || str_arr.size() == 1 && str_arr[0].empty();
    }


    ret &= expression_components.empty();
    return ret;
}

void HDL_parameter::set_value(int64_t val) {
    locking_violation_check();
    type = numeric_parameter;
    if (!std::holds_alternative<mdarray<int64_t>>(value)) {
        value = mdarray<int64_t>({1,1,1}, val);
    } else {
        std::get<mdarray<int64_t>>(value).set_scalar(val);
    }
}

std::shared_ptr<HDL_parameter> HDL_parameter::clone() const {
    return std::make_shared<HDL_parameter>(*this);
}

void HDL_parameter::set_value(const std::string &v) {
    locking_violation_check();
    type = string_parameter;
    std::get<std::vector<std::string>>(value)[0] = v;
}

int64_t HDL_parameter::get_numeric_value() const {
    return std::get<mdarray<int64_t>>(value).get_scalar();
}


HDL_parameter::operator std::string() {
    std::string ret_val;
    switch (type) {
        case string_parameter:
            ret_val = std::get<std::vector<std::string>>(value)[0];
            break;
        case numeric_parameter:
            ret_val =  std::to_string(std::get<mdarray<int64_t>>(value).get_scalar());
            break;
        case array_parameter:
            ret_val = "array value";
        case expression_parameter:
            break;
    }
    return ret_val;

}

void HDL_parameter::add_component(const Expression_component& component) {
    locking_violation_check();
    expression_components.push_back(component);
}

void PrintTo(const HDL_parameter &param, std::ostream *os) {
    std::string result = param.to_string();
    *os << result;
}

std::string HDL_parameter::value_as_string() const {
    if(type == string_parameter) {
        return std::get<std::vector<std::string>>(value)[0];
    }
    if(type == numeric_parameter) {
        return std::to_string(std::get<mdarray<int64_t>>(value).get_scalar());
    }
    if(type == array_parameter) {
        return std::get<mdarray<int64_t>>(value).to_string();
    }
    return "";
}

std::string HDL_parameter::to_string() const {
    std::string result = "\nHDL parameter:\n  NAME: " + name +
                         "\n  SCOPE: " + scope +
                         "\n  TYPE: " + parameter_type_to_string(type);

    if(type == numeric_parameter){
        result += "\n  VALUE: " + std::to_string(std::get<mdarray<int64_t>>(value).get_scalar());
    }

    result += "\n  EXPRESSION:\n";

    auto comps = expression_components.print();

    result += "\n  INITIALIZATION LIST:\n    ";

    std::ostringstream s;
    PrintTo(i_l,&s);
    result += s.str();

    return result;
}

nlohmann::json HDL_parameter::dump() {
    nlohmann::json ret;

    ret["name"] = name;
    ret["scope"] = scope;
    ret["type"] = parameter_type_to_string(type);
    if(type == string_parameter){
        ret["value"] = std::get<std::vector<std::string>>(value);
    } else if(type == numeric_parameter){

        ret["value"]= std::vector<int64_t>({std::get<mdarray<int64_t>>(value).get_scalar()});
    } else if(type == array_parameter){
        ret["value"] = std::get<mdarray<int64_t>>(value).dump();
    }



    return ret;
}

