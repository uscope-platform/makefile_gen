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
    string_value_array = c.string_value_array;
    numeric_value_array = c.numeric_value_array;
    type = c.type;
    expression_components = c.expression_components;
    array_value = c.array_value;
    i_l = c.i_l;
}

HDL_parameter::HDL_parameter() {
    type = string_parameter;
    numeric_value_array = {0};
    string_value_array = {""};
}


std::string HDL_parameter::get_string_value() const {
    return string_value_array[0];
}

bool operator==(const HDL_parameter &lhs, const HDL_parameter &rhs) {
    bool ret_val = true;
    ret_val &= lhs.name == rhs.name;
    ret_val &= lhs.string_value_array == rhs.string_value_array;
    ret_val &= lhs.numeric_value_array == rhs.numeric_value_array;
    ret_val &= lhs.type == rhs.type;
    ret_val &= lhs.expression_components == rhs.expression_components;
    ret_val &= lhs.array_value == rhs.array_value;
    ret_val &= lhs.i_l == rhs.i_l;
    return ret_val;
}

bool operator<(const HDL_parameter &lhs, const HDL_parameter &rhs) {
    return lhs.name<rhs.name;
}

bool HDL_parameter::is_empty() {
    bool ret = true;

    ret &= name.empty();
    ret &= string_value_array.empty();
    ret &= numeric_value_array.empty();
    ret &= expression_components.empty();
    return ret;
}

void HDL_parameter::set_value(int64_t val) {
    type = numeric_parameter;
    numeric_value_array[0] = val;
}

void HDL_parameter::set_value(const std::string &v) {
    type = string_parameter;
    string_value_array[0] = v;
}

int64_t HDL_parameter::get_numeric_value() const {
    return numeric_value_array[0];
}


HDL_parameter::operator std::string() {
    std::string ret_val;
    switch (type) {
        case string_parameter:
            ret_val = string_value_array[0];
            break;
        case numeric_parameter:
            ret_val =  std::to_string(numeric_value_array[0]);
            break;
        case array_parameter:
            ret_val = "array value";
        case expression_parameter:
            break;
    }
    return ret_val;

}

void HDL_parameter::add_component(const Expression_component& component) {
    expression_components.push_back(component);
}

void PrintTo(const HDL_parameter &param, std::ostream *os) {
    std::string result = param.to_string();
    *os << result;
}

std::string HDL_parameter::to_string() const {
    std::string result = "\nHDL parameter:\n  NAME: " + name +
                         "\n  TYPE: " + parameter_type_to_string(type);

    if(type == numeric_parameter){
        result += "\n  VALUE: " + std::to_string(numeric_value_array[0]);
    }

    result += "\n  EXPRESSION:\n";

    auto comps = expression_components;

    for(auto &item:comps){
        result += "    " + item.print_value() + "\n";
    }

    result += "\n  INITIALIZATION LIST:\n    ";

    std::ostringstream s;
    PrintTo(i_l,&s);
    result += s.str();

    return result;
}

nlohmann::json HDL_parameter::dump() {
    nlohmann::json ret;

    ret["name"] = name;
    ret["type"] = parameter_type_to_string(type);
    if(type == string_parameter){
        ret["value"] = string_value_array;
    } else if(type == numeric_parameter){

        ret["value"]= numeric_value_array;
    } else if(type == array_parameter){
        ret["value"] = array_value.dump();
    }



    return ret;
}

