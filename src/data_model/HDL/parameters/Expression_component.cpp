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

#include "data_model/HDL/parameters/Expression.hpp"

const std::regex Expression_component::sv_constant_regex(R"(^\d*'(s)?(h|d|o|b)([0-9a-fA-F]+))");
const std::regex Expression_component::number_regex("^\\d+$");
const std::regex Expression_component::size_regex(R"(^(\d*)'[0-9a-zA-Z]+)");

Expression_component::Expression_component(const Expression_component &c) {
    component_type = c.component_type;
    value = c.value;
    array_index = c.array_index;
    package_prefix = c.package_prefix;
    binary_size = c.binary_size;
}


Expression_component::Expression_component() {

    value = 0;
    component_type = string_component;
}

Expression_component::Expression_component(const std::string &s) {

    if(operators_set.contains(s)) {
        component_type = operator_component;
    } else if(functions_set.contains(s)) {
        component_type = function_component;
    } else {
        component_type = string_component;
    }
    value =  std::move(s);
    process_number();
}

Expression_component::Expression_component(int64_t n) {
    value = n;
    component_type = numeric_component;
}

bool Expression_component::is_string() const {
    return component_type == string_component && !parenthesis_set.contains(std::get<std::string>(value));
}


bool operator==(const Expression_component &lhs, const Expression_component &rhs) {
    bool ret_val = true;
    ret_val &= lhs.value == rhs.value;
    ret_val &= lhs.component_type == rhs.component_type;
    ret_val &= lhs.array_index == rhs.array_index;
    ret_val &= lhs.package_prefix == rhs.package_prefix;
    ret_val &= lhs.binary_size == rhs.binary_size;
    return ret_val;
}

std::string Expression_component::print_value() {
    std::string ret_val;
     if(component_type == numeric_component){
        ret_val = std::to_string(std::get<int64_t>(value));
    } else {
        if(!array_index.empty()){
            ret_val = std::get<std::string>(value) + print_index(array_index);
        } else {
            ret_val = std::get<std::string>(value);
        }
    }


    return ret_val;
}

void Expression_component::process_number() {

    std::string raw_value = std::get<std::string>(value);

    if(test_parameter_type(number_regex, raw_value)) {
        value = static_cast<int64_t>(std::stoul(raw_value));
        component_type = numeric_component;
        binary_size = calculate_binary_size(std::get<int64_t>(value));
    } else if(test_parameter_type(sv_constant_regex, raw_value)){
        std::smatch base_match;
        if(std::regex_search(raw_value, base_match, sv_constant_regex)){
            // Process value
            std::string base;
            std::string str_value;
            switch (base_match.size()) {
                case 3:
                    base = base_match[1].str();
                    str_value = base_match[2].str();
                    break;
                case 4:
                    base = base_match[2].str();
                    str_value = base_match[3].str();
                    break;
            }
            if(base =="h"){
                value = static_cast<int64_t>(std::stoul(str_value, nullptr, 16));
            } else if(base =="d") {
                value = static_cast<int64_t>(std::stoul(str_value, nullptr, 10));
            } else if(base =="o") {
                value = static_cast<int64_t>(std::stoul(str_value, nullptr, 8));
            } else if(base =="b") {
                value = static_cast<int64_t>(std::stoul(str_value, nullptr, 2));
            }
            // Process size

            if(std::regex_search(raw_value, base_match, size_regex)){
                if(!base_match[1].str().empty()) {
                    binary_size = std::stoll(base_match[1].str());
                } else {
                    binary_size = calculate_binary_size(std::get<int64_t>(value));
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
    std::string  base_string;
    if (std::holds_alternative<std::string>(value)) base_string = std::get<std::string>(value);
    else base_string = std::to_string(std::get<int64_t>(value));
    if(array_index.empty()){
        return base_string;
    } else {
        return base_string + print_index(array_index);
    }
}

Expression_component::operator_type_t Expression_component::get_operator_type() {
    if(component_type != operator_component && component_type != function_component){
        throw std::runtime_error("Error: attempted to get the type of a non operator/function expression component");
    }
    return operators_types[std::get<std::string>(value)];
}

int64_t Expression_component::get_operator_precedence() {
    if(component_type != operator_component && component_type != function_component){
        throw std::runtime_error("Error: attempted to get the precedence of a non operator/function expression component");
    }
    return operators_precedence[std::get<std::string>(value)];
}

bool Expression_component::is_right_associative() {
    if(component_type != operator_component && component_type != function_component){
        throw std::runtime_error("Error: attempted to get the right associativity of a non operator/function expression component");
    }
    return right_associative_set.contains(std::get<std::string>(value));
}

const std::string Expression_component::print_index(const std::vector<Expression> &index) {
    std::string ret_val;
    for(auto &item:index){
        ret_val += "[" + item.print() + "]";
    }
    return ret_val;
}

nlohmann::json Expression_component::dump() {
    nlohmann::json ret;

    return ret;
}

int64_t Expression_component::calculate_binary_size(int64_t in) {
    auto n_bits = std::log2(in);
    if(std::isinf(n_bits) || n_bits == 0) {
        return 1;
    }else{
        return  std::ceil(n_bits);
    }
}

void Expression_component::add_array_index(const Expression &c) {
    array_index.push_back(c);
}
