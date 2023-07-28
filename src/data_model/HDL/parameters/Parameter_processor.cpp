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

    for(auto &item:working_set){
        processed_parameters[item.first] = item.second;
    }

    return_res.set_parameters(processed_parameters);

    return return_res;
}

std::pair<HDL_parameter, bool> Parameter_processor::process_parameter(const HDL_parameter &par) {

    HDL_parameter return_par = par;
    bool processing_complete = false;

    auto components = return_par.get_expression_components();



    if(components.empty()){
        throw std::runtime_error("PARAMETER PROCESSING ERROR:\n Empty parameter");
    }

    // PROCESS SIMPLE PARAMETERS
    if(components.size() == 1){
        std::string value = components[0];
        uint32_t val;
        if(test_parameter_type(classification_regexes.numeric, value) || test_parameter_type(classification_regexes.sv_constant, value)) {
            val = process_number(value);
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


    auto proc_expr = process_expression(components);
    if(proc_expr.second){
        return_par.set_type(numeric_parameter);
        return_par.set_value(proc_expr.first);
        processing_complete = true;
    }

    return {return_par, processing_complete};
}

std::pair<uint32_t , bool>  Parameter_processor::process_expression(std::vector<std::string> components) {
    uint32_t ret_value = 0;
    bool return_valid = false;

    auto rpn_expr = expr_vector_to_rpn(components);

    while(!rpn_expr.empty()){
        auto op_a_s = rpn_expr.front();
        rpn_expr.erase(rpn_expr.begin());
        uint32_t op_a;
        if(!working_param_values.contains(op_a_s)){
            if(
                !rpn_expr.empty() &&
                (
                    test_parameter_type(classification_regexes.numeric, op_a_s) ||
                    test_parameter_type(classification_regexes.sv_constant, op_a_s)
                )
            ){
                op_a = process_number(op_a_s);
            } else {
                break;
            }
        } else {
            op_a = working_param_values[op_a_s];
        }

        if(operators_set.contains(rpn_expr.front()) || functions_set.contains(rpn_expr.front())){
            // execute unary operation
            auto operation = rpn_expr.front();
            rpn_expr.erase(rpn_expr.begin());

            ret_value = evaluate_unary_expression(op_a, operation);
            return_valid = true;
        } else {
            auto op_b_s = rpn_expr.front();
            rpn_expr.erase(rpn_expr.begin());
            uint32_t op_b;
            if(!working_param_values.contains(op_b_s)){
                if(test_parameter_type(classification_regexes.numeric, op_b_s) || test_parameter_type(classification_regexes.sv_constant, op_b_s)){
                    op_b = process_number(op_b_s);
                } else{
                    break;
                }
            } else{
                op_b = working_param_values[op_b_s];
            }
            auto operation = rpn_expr.front();
            rpn_expr.erase(rpn_expr.begin());

            // execute binary operation

            ret_value = evaluate_binary_expression(op_a,op_b, operation);
            return_valid = true;
        }
        if(!rpn_expr.empty()){
            rpn_expr.insert(rpn_expr.begin(), std::to_string(ret_value));
        }
    }

    return {ret_value, return_valid};
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

uint32_t Parameter_processor::process_number(const std::string &raw_value) {
    if(test_parameter_type(classification_regexes.numeric, raw_value)) {
        return std::stoul(raw_value);
    } else if(test_parameter_type(classification_regexes.sv_constant, raw_value)){
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
        throw std::runtime_error("Error: Attempted evaluation of an unsupported unary expression expression " + operation);
    }
}

std::vector<std::string> Parameter_processor::expr_vector_to_rpn(const std::vector<std::string>& v) {
    // IMPLEMENTATION OF THE SHUNTING YARD ALGORITHM
    std::vector<std::string> rpn_exp;
    std::stack<std::string> shunting_stack;

    for(auto &item:v){
        if(operators_set.contains(item)){ // token is operator
            while (
                    !shunting_stack.empty() &&
                    shunting_stack.top()!="(" &&
                    (
                        operators_precedence[shunting_stack.top()]>operators_precedence[item] ||
                        operators_precedence[shunting_stack.top()]==operators_precedence[item]
                    )
            ){
                rpn_exp.push_back(shunting_stack.top());
                shunting_stack.pop();
            }
            shunting_stack.push(item);
        }else if(functions_set.contains(item)){ // token is function
            shunting_stack.push(item);
        } else if(item == "("){
            shunting_stack.push(item);
        } else if(item == ")"){
            while (shunting_stack.top() != "(") {
                rpn_exp.push_back(shunting_stack.top());
                shunting_stack.pop();
            }
            shunting_stack.pop();
        } else{ // token is number
            rpn_exp.push_back(item);
        }
    }

    while(!shunting_stack.empty()){
        rpn_exp.push_back(shunting_stack.top());
        shunting_stack.pop();
    }

    return rpn_exp;
}


