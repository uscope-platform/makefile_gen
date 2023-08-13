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

#include "data_model/HDL/parameters/Expression_component.hpp"


Expression_component::Expression_component(const Expression_component &c) {
    component_type = c.component_type;
    string_value = c.string_value;
    numeric_value = c.numeric_value;
    array_index = c.array_index;
    array_value = c.array_value;
    package_prefix = c.package_prefix;
}


Expression_component::Expression_component() {
    string_value = "";
    numeric_value = 0;
    component_type = string_component;
}

Expression_component::Expression_component(std::string s) {
    numeric_value = 0;
    if(operators_set.contains(s)) {
        component_type = operator_component;
    } else if(functions_set.contains(s)){
        component_type = function_component;
    } else {
        component_type = string_component;
    }
    string_value =  std::move(s);
    process_number();
}

Expression_component::Expression_component(int64_t n) {
    numeric_value = n;
    component_type = numeric_component;
}


bool operator==(const Expression_component &lhs, const Expression_component &rhs) {
    bool ret_val = true;
    ret_val &= lhs.string_value == rhs.string_value;
    ret_val &= lhs.numeric_value == rhs.numeric_value;
    ret_val &= lhs.component_type == rhs.component_type;
    ret_val &= lhs.array_value == rhs.array_value;
    ret_val &= lhs.array_index == rhs.array_index;
    ret_val &= lhs.package_prefix == rhs.package_prefix;
    return ret_val;
}

std::string Expression_component::print_value() {
    std::string ret_val;
    if(component_type == array_component) {

    } else if(component_type == numeric_component){
        ret_val = std::to_string(numeric_value);
    } else {
        if(!array_index.empty()){
            ret_val = string_value + print_index(array_index);
        } else {
            ret_val = string_value;
        }
    }


    return ret_val;
}

void Expression_component::process_number() {

    std::regex sv_constant_regex(R"(^\d*'(s)?(h|d|o|b)([0-9a-fA-F]+))");
    std::regex number_regex("^\\d*$");

    if(test_parameter_type(number_regex, string_value)) {
        numeric_value = std::stoul(string_value);
        component_type = numeric_component;
    } else if(test_parameter_type(sv_constant_regex, string_value)){
        std::smatch base_match;
        if(std::regex_search(string_value, base_match, sv_constant_regex)){
            // Process value
            std::string base;
            std::string value;
            switch (base_match.size()) {
                case 3:
                    base = base_match[1].str();
                    value = base_match[2].str();
                    break;
                case 4:
                    base = base_match[2].str();
                    value = base_match[3].str();
                    break;
            }
            if(base =="h"){
                numeric_value = std::stoul(value, nullptr, 16);
            } else if(base =="d") {
                numeric_value = std::stoul(value, nullptr, 10);
            } else if(base =="o") {
                numeric_value = std::stoul(value, nullptr, 8);
            } else if(base =="b") {
                numeric_value = std::stoul(value, nullptr, 2);
            }
            // Process size
            std::regex r(R"(^(\d*)'[0-9a-zA-Z]+)");

            if(std::regex_search(string_value, base_match, r)){
                if(!base_match[1].str().empty()) {
                    binary_size = std::stoll(base_match[1].str());
                } else {
                    binary_size = std::ceil(std::log2(numeric_value));
                }
            }
        }
        component_type = numeric_component;
    }
}

bool Expression_component::test_parameter_type(const std::regex &r, const std::string &s) {

    std::smatch base_match;
    if(std::regex_search(s, base_match, r)){
        return true;
    } else{
        return false;
    }
}

std::string Expression_component::get_raw_string_value() {
    if(array_index.empty()){
        return string_value;
    } else {
        return string_value + print_index(array_index);
    }
}

Expression_component::operator_type_t Expression_component::get_operator_type() {
    if(component_type != operator_component && component_type != function_component){
        throw std::runtime_error("Error: attempted to get the type of a non operator/function expression component");
    }
    return operators_types[string_value];
}

int64_t Expression_component::get_operator_precedence() {
    if(component_type != operator_component && component_type != function_component){
        throw std::runtime_error("Error: attempted to get the precedence of a non operator/function expression component");
    }
    return operators_precedence[string_value];
}

bool Expression_component::is_right_associative() {
    if(component_type != operator_component && component_type != function_component){
        throw std::runtime_error("Error: attempted to get the right associativity of a non operator/function expression component");
    }
    return right_associative_set.contains(string_value);
}

const std::string Expression_component::print_expression(const std::vector<Expression_component> &exp) {
    std::string ret_val;
    for(auto &item:exp){
        if(item.get_type() == numeric_component){
            ret_val += std::to_string(item.numeric_value);
        } else if(item.get_type() == string_component || item.get_type() == operator_component || item.get_type()== function_component) {
            if(!item.package_prefix.empty()){
                ret_val += item.package_prefix + "::";
            }
            ret_val += item.string_value;
        }
    }
    return ret_val;
}

const std::string Expression_component::print_index(const std::vector<std::vector<Expression_component>> &index) {
    std::string ret_val;
    for(auto &item:array_index){
        ret_val += "[" + print_expression(item) + "]";
    }
    return ret_val;
}

nlohmann::json Expression_component::dump() {
    nlohmann::json ret;

    return ret;
}


