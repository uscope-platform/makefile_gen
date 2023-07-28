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

#include "data_model/HDL/parameters/Parameter_processor.hpp"

HDL_Resource Parameter_processor::process_resource(const HDL_Resource &res) {

    HDL_Resource return_res = res;

    std::unordered_map<std::basic_string<char>, HDL_parameter> processed_parameters;
    std::unordered_map<std::basic_string<char>, HDL_parameter> working_set = return_res.get_parameters();
    std::unordered_map<std::basic_string<char>, HDL_parameter> next_working_set;

    bool processing_complete = false;

    while(!working_set.empty() && !processing_complete){
        for(auto &item:working_set){
            auto processed_param = process_parameter(item.second);
            if(processed_param.second){
                processed_parameters[item.first] = processed_param.first;
                working_param_values[item.first] = processed_param.first.get_numeric_value();
            } else{
                next_working_set[item.first] = item.second;
            }
        }

        if(working_set == next_working_set){
            processing_complete = true;
        }
        working_set = next_working_set;
        next_working_set.clear();
    }

    return return_res;
}

std::pair<HDL_parameter, bool> Parameter_processor::process_parameter(const HDL_parameter &par) {

    HDL_parameter return_par = par;
    bool processing_complete = false;

    auto operands = return_par.get_operands();
    auto operators = return_par.get_operators();


    if(operators.empty() && operands.size() > 1){
        throw std::runtime_error("PARAMETER PROCESSING ERROR:\nEncountered parameter expression with multiple operands and no operators");
    }

    // PROCESS SIMPLE PARAMETERS
    if(operators.empty() && operands.size() == 1){
        std::string value = operands.top();
        uint32_t val;
        if(test_parameter_type(classification_regexes.numeric, value)) {
            val = std::stoul(value);
        } else if(test_parameter_type(classification_regexes.sv_constant, value)){
            val = process_numeric_parameter(value);
        } else{
            if(working_param_values.contains(value)){
                val = working_param_values[value];
            } else {
                return {return_par, processing_complete};
            }
        }

        return_par.set_type(numeric_parameter);
        return_par.set_value(val);
        processing_complete = true;
    }

    //PROCESS SIMPLE EXPRESSIONS
    if(operators.size() == 1){
        if(!operators_precedence.contains(operators.top())){

        } else {
            if(operators_types[operators.top()] == unary_operator){
                auto operand_s = operands.top();
                if(working_param_values.contains(operand_s)){
                    uint32_t operand = working_param_values[operand_s];
                    return_par.set_type(numeric_parameter);
                    return_par.set_value(evaluate_unary_expression(operand, operators.top()));
                    processing_complete = true;
                }
            } else if(operators_types[operators.top()]== binary_operator){
                auto operand_a_s = operands.top();
                operands.pop();
                auto operand_b_s = operands.top();
                if(working_param_values.contains(operand_a_s) && working_param_values.contains(operand_b_s)){
                    uint32_t operand_a = working_param_values[operand_a_s];
                    uint32_t operand_b = working_param_values[operand_b_s];
                    return_par.set_type(numeric_parameter);
                    return_par.set_value(evaluate_binary_expression(operand_a, operand_b, operators.top()));
                    processing_complete = true;
                }
            } else {
                throw std::runtime_error("Error: parenthesis encountered in simple operation");
            }
        }

    }

    //PROCESS COMPLEX EXPRESSIONS

    return {return_par, processing_complete};
}



bool Parameter_processor::test_parameter_type(const std::string &r, const std::string &s) {
    const std::regex regex(r);
    std::smatch base_match;
    if(std::regex_search(s, base_match, regex)){
        return true;
    } else{
        return false;
    }
}

uint32_t Parameter_processor::process_numeric_parameter(const std::string &raw_value) {
    std::regex r(classification_regexes.sv_constant);

    std::smatch base_match;
    if(std::regex_search(raw_value, base_match, r)){
        if(base_match[1].str() =="h"){
            return std::stoul(base_match[2], nullptr, 16);
        } else if(base_match[1].str() =="d") {
            return std::stoul(base_match[2], nullptr, 10);
        } else if(base_match[1].str() =="o") {
            return std::stoul(base_match[2], nullptr, 8);
        } else if(base_match[1].str() =="b") {
            return std::stoul(base_match[2], nullptr, 2);
        }
    }
    throw std::runtime_error("Invalid SV constant encountered while processing parameters: \"" + raw_value + "\"");
}

uint32_t Parameter_processor::evaluate_binary_expression(uint32_t op_a, uint32_t op_b, std::string operation) {
    if(operation == "+"){
        return op_a + op_b;
    } else if(operation ==  "-"){
        return op_a - op_b;
    } else if(operation ==  "*"){
        return op_a * op_b;
    } else if(operation ==  "/"){
        return op_a / op_b;
    } else if(operation ==  "%"){
        return op_a % op_b;
    } else if(operation ==  "<<"){
        return op_a << op_b;
    } else if(operation ==  ">>"){
        return op_a >> op_b;
    } else{
        throw std::runtime_error("Error: Attempted evaluation of an unsupported binary expression expression " + operation);
    }
}

uint32_t Parameter_processor::evaluate_unary_expression(uint32_t operand, std::string operation) {
    if(operation == "!"){
        return !operand;
    } else if(operation ==  "~"){
        return ~operand;
    } else if(operation ==  "$clog2"){
        return (uint32_t) ceil(log2(operand));
    } else if(operation ==  "$ceil"){
        return (uint32_t) ceil(operand);
    } else if(operation ==  "$floor"){
        return (uint32_t) floor(operand);
    } else{
        throw std::runtime_error("Error: Attempted evaluation of an unsupported binary expression expression " + operation);
    }
}
