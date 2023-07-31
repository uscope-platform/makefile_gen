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



Expression_component::Expression_component() {
    string_value = "";
    numeric_value = 0;
    string_index = "";
    numeric_index = 0;
    index_type = no_index_type;
    component_type = string_component;
}

Expression_component::Expression_component(std::string s) {
    string_value =  std::move(s);
    numeric_value = 0;
    string_index = "";
    numeric_index = 0;
    index_type = no_index_type;
    component_type = string_component;
}

Expression_component::Expression_component(uint32_t n) {
    string_value =  "";
    numeric_value = n;
    string_index = "";
    numeric_index = 0;
    index_type = no_index_type;
    component_type = numeric_component;
}


bool operator==(const Expression_component &lhs, const Expression_component &rhs) {
    bool ret_val = true;
    ret_val &= lhs.string_value == rhs.string_value;
    ret_val &= lhs.numeric_value == rhs.numeric_value;
    ret_val &= lhs.numeric_index == rhs.numeric_index;
    ret_val &= lhs.string_index == rhs.string_index;
    ret_val &= lhs.index_type == rhs.index_type;
    ret_val &= lhs.component_type == rhs.component_type;
    return ret_val;
}

std::string Expression_component::print_value() {
    std::string ret_val;

    switch (index_type) {
        case no_index_type:
            if(component_type==string_component)
                ret_val = string_value;
            else
                ret_val = std::to_string(numeric_value);
            break;
        case string_index_type:
            if(component_type==string_component)
                ret_val = string_value + "[" + string_index + "]";
            else
                ret_val =  std::to_string(numeric_value); + "[" + string_index + "]";
            break;
        case numeric_index_type:
            if(component_type==string_component)
                ret_val = string_value + "[" + std::to_string(numeric_index)+ "]";
            else
                ret_val =  std::to_string(numeric_value); + "[" +  std::to_string(numeric_index)+ "]";
            break;
    }
    return ret_val;
}

void Expression_component::process_number(const std::string &val) {
    std::regex sv_constant_regex("^\\d*'(h|d|o|b)([0-9a-fA-F]+)");
    std::regex number_regex("^\\d*$");

    if(test_parameter_type(number_regex, val)) {
        numeric_value = std::stoul(val);
        component_type = numeric_component;
    } else if(test_parameter_type(sv_constant_regex, val)){
        std::smatch base_match;
        if(std::regex_search(val, base_match, sv_constant_regex)){
            if(base_match[1].str() =="h"){
                numeric_value = std::stoul(base_match[2], nullptr, 16);
            } else if(base_match[1].str() =="d") {
                numeric_value = std::stoul(base_match[2], nullptr, 10);
            } else if(base_match[1].str() =="o") {
                numeric_value = std::stoul(base_match[2], nullptr, 8);
            } else if(base_match[1].str() =="b") {
                numeric_value = std::stoul(base_match[2], nullptr, 2);
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
    if(index_type == no_index_type){
        return string_value;
    } else if(index_type == string_index_type){
        return string_value + "[" + string_index + "]";
    } else if(index_type == numeric_index_type){
        return string_value + "[" + std::to_string(numeric_index) + "]";
    } else {
        throw std::runtime_error("Error: unknown expression component index type");
    }
}

