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
    dependencies = c.dependencies;
    expression_components = c.expression_components;
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
    ret_val &= lhs.dependencies == rhs.dependencies;

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
    ret &= dependencies.empty();

    return ret;
}

void HDL_parameter::set_value(uint32_t val) {
    type = numeric_parameter;
    numeric_value_array[0] = val;
}

void HDL_parameter::set_value(const std::string &v) {
    type = string_parameter;
    string_value_array[0] = v;
}

uint32_t HDL_parameter::get_numeric_value() const {
    return numeric_value_array[0];
}

bool HDL_parameter::is_sv_constant(const std::string &s) const {
    return regex_string_test(classification_regexes.sv_constant, s);
}

uint32_t HDL_parameter::parse_sv_constant(const std::string &s) const {
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

void HDL_parameter::string_to_numeric() {
    if(is_numeric_string()){
        numeric_value_array[0] = std::stoul(get_string_value(), nullptr, 0);
    } else if(is_sv_constant()) {
        numeric_value_array[0] = parse_sv_constant();
    }
    type = numeric_parameter;
}


bool HDL_parameter::is_array() const {
    return regex_string_test(classification_regexes.array, get_string_value());
}

void HDL_parameter::string_to_array(
        const std::unordered_map<std::string, HDL_parameter>& parent_parameter,
        const std::unordered_map<std::string, HDL_parameter>& instance_parameters,
        const std::unordered_map<std::string, HDL_parameter>& module_parameters
        ) {
    std::vector<std::string> array;
    const std::regex regex(classification_regexes.array);
    std::smatch base_match;
    auto s = get_string_value();
    if(is_repetition_array_init()){
        //implement support for these
        auto init_strings = split_array_init(s);
        uint32_t arr_size;
        if(is_numeric_string(init_strings.first)){
            arr_size = std::stoul(init_strings.first, nullptr, 0);
        } else if(is_sv_constant(init_strings.first)){
            arr_size = parse_sv_constant(init_strings.first);
        } else {
            arr_size = get_parameter_value(init_strings.first, parent_parameter,instance_parameters, module_parameters);
        }
        array.insert(array.end(), arr_size, init_strings.second);
        type = string_array_parameter;
    }else{
        if(std::regex_search(s, base_match, regex)){
            std::stringstream ss(base_match[1].str());
            std::string item;

            while (std::getline(ss, item, ',')) {
                array.push_back(item);
            }
        }else{
            array.push_back(s);
        }
    }

    string_value_array = array;
}

bool HDL_parameter::is_repetition_array_init() const {
    return regex_string_test(classification_regexes.array_init, get_string_value()); // this regex is still wonky
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
    }
    return ret_val;

}

void HDL_parameter::add_component(const Expression_component& component) {
    expression_components.push_back(component);
}


uint32_t HDL_parameter::get_parameter_value(const std::string &p,
                                            const std::unordered_map<std::string, HDL_parameter> &parent_parameter,
                                            const std::unordered_map<std::string, HDL_parameter> &instance_parameters,
                                            const std::unordered_map<std::string, HDL_parameter> &module_parameters) {



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

    result += "\n  DEPENDENCIES:\n";

    auto deps = dependencies;

    for(auto &item:deps){
        result += "    " + item + "\n";
    }

    result += "\n  EXPRESSION:\n";

    auto comps = expression_components;

    for(auto &item:comps){
        result += "    " + item.print_value() + "\n";
    }

    return result;
}
