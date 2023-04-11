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

#include "data_model/bus_mapping/address_resolver.hpp"

address_resolver::address_resolver(const HDL_Resource &bdp) {
    bus_defining_package = bdp;
}

uint32_t address_resolver::get_address(const std::string &str, HDL_Resource &parent) {
    return get_address(str,parent, 0);
}

uint32_t address_resolver::get_address(const std::string &str, HDL_Resource &parent, int stack_level) {
    auto param_name = str.substr(str.find("::")+2, str.size());
    if(bus_defining_package.is_numeric_parameter(param_name)){
        return  bus_defining_package.get_numeric_parameter(param_name);
    } else if((parameters_stack.end()- stack_level)->contains(str)){
        return get_address((parameters_stack.end()- stack_level)->at(str), parent, stack_level+1);
    } else if(parent.is_string_parameter(str)){
        auto param_value = parent.get_string_parameter(str);
        try{
            if(is_sv_constant(param_value)) return parse_sv_constant(param_value);
            else return std::stoul(param_value, nullptr, 0);

        } catch (std::invalid_argument &ex){
            return get_address(param_value, parent);
        }
    } else{
        std::regex expr(R"(([a-zA-Z0-9_']*)\s*(\+|\-)\s*([a-zA-Z0-9_']*))");
        std::smatch base_match;
        if(std::regex_search(str, base_match, expr)){
            if(base_match.size()!= 4){
                return 0;
            }
            auto op_a_str = base_match[1].str();
            auto op_b_str = base_match[3].str();
            uint32_t op_a, op_b;
            if(is_sv_constant(op_a_str)){
                op_a = parse_sv_constant(op_a_str);
            } else{
                op_a = get_address(op_a_str, parent);
            }
            if(is_sv_constant(op_b_str)){
                op_b = parse_sv_constant(op_b_str);
            } else{
                op_b = get_address(op_b_str, parent);
            }
            auto optor = base_match[2].str();
            if(optor == "+"){
                return op_a + op_b;
            }else if(optor == "-"){
                return op_a - op_b;
            } else{
                return 0;
            }
        }
        // try and parse the parameter value as an expression;
        return 0;
    }
}


bool address_resolver::is_sv_constant(const std::string &s) {
    std::regex r("^\\d*'(h|d|o|b)([0-9a-fA-F]+)");
    std::smatch base_match;
    if(std::regex_search(s, base_match, r)){
        return true;
    } else{
        return false;
    }
}

uint32_t address_resolver::parse_sv_constant(const std::string &s) {
    std::regex r("^\\d*'(h|d|o|b)");
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

void address_resolver::push_parameters_map(HDL_dependency &instance) {

    auto params = instance.get_parameters();
    parameters_stack.push_back(params);

}

void address_resolver::pop_parameters_map() {
    parameters_stack.pop_back();
}

