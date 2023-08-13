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
    initialization_list = c.initialization_list;
    array_dimensions = c.array_dimensions;
    array_index = c.array_index;
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
    //ret_val &= lhs.initialization_list == rhs.initialization_list;

    if(lhs.array_dimensions.size() != rhs.array_dimensions.size()) return false;
    for(int i = 0; i<lhs.array_dimensions.size(); i++){
        ret_val &= lhs.array_dimensions[i].packed == rhs.array_dimensions[i].packed;
        ret_val &= lhs.array_dimensions[i].first_bound == rhs.array_dimensions[i].first_bound;
        ret_val &= lhs.array_dimensions[i].second_bound == rhs.array_dimensions[i].second_bound;
    }
    ret_val &= lhs.array_index == rhs.array_index;
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
    ret &= initialization_list.empty();
    ret &= array_dimensions.empty();
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

bool HDL_parameter::is_sv_constant(const std::string &s) const {
    return regex_string_test(classification_regexes.sv_constant, s);
}

int64_t HDL_parameter::parse_sv_constant(const std::string &s) const {
    std::regex r(classification_regexes.sv_constant);
    auto val = std::regex_replace(s, r, "");

    std::smatch base_match;
    if(std::regex_search(s, base_match, r)){
        if(base_match[1].str() =="h"){
            return std::stoul(val, nullptr, 16);
        } else if(base_match[1].str() =="d") {
            return std::stoul(val, nullptr, 10);
        } else if(base_match[1].str() =="o") {
            return std::stoul(val, nullptr, 8);
        } else if(base_match[1].str() =="b") {
            return std::stoul(val, nullptr, 2);
        }
    }
    return 0;
}

bool HDL_parameter::is_numeric_string(const std::string &s) const {
    return regex_string_test(classification_regexes.numeric, s);
}



bool HDL_parameter::regex_string_test(const std::string &r, const std::string &s) const{
    const std::regex regex(r);
    std::smatch base_match;
    if(std::regex_search(s, base_match, regex)){
        return true;
    } else{
        return false;
    }
}

std::pair<std::string, std::string> HDL_parameter::split_array_init(std::string s) {
    std::regex r(classification_regexes.array_init);
    auto val = std::regex_replace(s, r, "");

    std::smatch base_match;
    if(std::regex_search(s, base_match, r)){
        auto bm = base_match.length();
        return {base_match[1], base_match[2]};
    } else{
        throw std::runtime_error("Malformed array initiator string");
    }
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
        case string_array_parameter:
            ret_val = "{" +string_value_array[0];
            for(int i = 1; i<string_value_array.size(); i++){
                ret_val += ", " + string_value_array[i];
            }
            ret_val += "}";
            break;
        case numeric_array_parameter:
            ret_val = "{" + std::to_string(numeric_value_array[0]);
            for(int i = 1; i<string_value_array.size(); i++){
                ret_val += ", " + std::to_string(numeric_value_array[i]);
            }
            ret_val += "}";
            break;
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

    auto il = initialization_list;

    for(auto &item:il){
        result += "{";
        for(auto &dim:item){
            result += Expression_component::print_expression(dim);
            if (&dim != &item.back()) result += ", ";

        }
        result += "}";
    }

    result += "\n  ARRAY DIMENSIONS:\n    ";

    for(auto &item:array_dimensions){
        result += "[" + Expression_component::print_expression(item.first_bound) +
                ":" +  Expression_component::print_expression(item.second_bound) + "](" ;
        if(item.packed){
            result +="packed)";
        } else {
            result +="unpacked)";
        }
    }



    return result;
}

void HDL_parameter::append_initialization_list(std::vector<std::vector<Expression>> &list) {
    initialization_list.insert(initialization_list.end(), list.begin(), list.end());
}

nlohmann::json HDL_parameter::dump() {
    nlohmann::json ret;

    ret["name"] = name;
    ret["type"] = parameter_type_to_string(type);
    ret["string_value"] = string_value_array;
    ret["numeric_value"]= numeric_value_array;


    return ret;
}

