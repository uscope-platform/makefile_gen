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
    return process_resource(res, {});
}

HDL_Resource Parameter_processor::process_resource(const HDL_Resource &res,
                                                   const std::unordered_map<std::string, HDL_parameter>& pp) {


    std::unordered_map<std::string, uint32_t> external_parameters;

    for(auto &item:pp){
        if(item.second.get_type() != numeric_parameter){
            throw std::runtime_error("ERROR: Non numeric parameter reached the parameter processor as external value");
        }
        external_parameters[item.first] = item.second.get_numeric_value();
    }

    HDL_Resource return_res = res;

    std::unordered_map<std::basic_string<char>, HDL_parameter> processed_parameters;
    std::unordered_map<std::basic_string<char>, HDL_parameter> working_set = return_res.get_parameters();
    std::unordered_map<std::basic_string<char>, HDL_parameter> next_working_set;

    bool processing_complete = false;

    while(!working_set.empty() && !processing_complete){
        for(auto &item:working_set){
            auto processed_param = process_parameter(item.second, external_parameters);
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
    return process_parameter(par, {});
}

std::pair<HDL_parameter, bool> Parameter_processor::process_parameter(const HDL_parameter &par,
                                                                      std::unordered_map<std::string, uint32_t> parent_parameters) {

    HDL_parameter return_par = par;
    bool processing_complete = false;

    auto components = return_par.get_expression_components();



    if(components.empty()){
        throw std::runtime_error("PARAMETER PROCESSING ERROR:\n Empty parameter");
    }

    // PROCESS SIMPLE PARAMETERS
    if(components.size() == 1){
        std::string value = components[0].get_string_value();
        uint32_t val;
        if(parent_parameters.contains(par.get_name())){
            val = parent_parameters[par.get_name()];
        } else if(test_parameter_type(classification_regexes.numeric, value) || test_parameter_type(classification_regexes.sv_constant, value)) {
            val = process_number(value);
        } else{
            if(parent_parameters.contains(value)){
                val = parent_parameters[value];
            } else if(working_param_values.contains(value)){
                val = working_param_values[value];
            } else {
                return {return_par, processing_complete};
            }
        }

        return_par.set_type(numeric_parameter);
        return_par.set_value(val);
        processing_complete = true;
    }


    std::unordered_set<std::string> dependencies;
    auto proc_expr = process_expression(components, dependencies, parent_parameters);
    if(proc_expr.second){
        return_par.set_dependencies(dependencies);
        return_par.set_type(numeric_parameter);
        return_par.set_value(proc_expr.first);
        processing_complete = true;
    }

    return {return_par, processing_complete};
}

std::pair<uint32_t , bool>  Parameter_processor::process_expression(const std::vector<Expression_component>& expr, std::unordered_set<std::string> &deps) {
    return process_expression(expr, deps, {});
}

std::pair<uint32_t, bool>
Parameter_processor::process_expression(const std::vector<Expression_component> &expr, std::unordered_set<std::string> &deps,
                                        std::unordered_map<std::string, uint32_t> parent_parameters) {
    uint32_t ret_value = 0;
    bool return_valid = false;

    std::vector<expr_component_t> processed_rpn;

    for(auto i : expr){


        if(i.get_type() == numeric_component){
            expr_component_t c;
            c.number = i.get_numeric_value();
            c.type = "number";
            processed_rpn.push_back(c);
        } else if(i.get_type() == string_component){
            //TODO: Adapt parameter processor to work directly on expression components
            if(parent_parameters.contains(i.get_string_value())){
                expr_component_t c;
                c.number = parent_parameters[i.get_raw_string_value()];
                c.type = "number";
                processed_rpn.push_back(c);
                deps.insert(i.get_raw_string_value());
            } else if(working_param_values.contains(i.get_raw_string_value())){
                expr_component_t c;
                c.number = working_param_values[i.get_raw_string_value()];
                c.type = "number";
                processed_rpn.push_back(c);
                deps.insert(i.get_raw_string_value());
            } else if(operators_set.contains(i.get_raw_string_value()) || functions_set.contains(i.get_raw_string_value())) {
                expr_component_t c;
                c.operation = i.get_raw_string_value();
                c.type = "operator";
                processed_rpn.push_back(c);
            }else {
                return {ret_value, return_valid};
            }
        }

    }

    std::stack<expr_component_t> evaluator_stack;

    for(auto & i : processed_rpn){
        if(i.type == "number"){
            evaluator_stack.push(i);
        } else {
            expr_component_t c;
            c.type = "number";
            if(operators_types[i.operation] == unary_operator){
                c.number = evaluate_unary_expression(evaluator_stack.top().number, i.operation);
                evaluator_stack.pop();
            } else if(operators_types[i.operation] == binary_operator){
                auto op_b = evaluator_stack.top().number;
                evaluator_stack.pop();
                auto op_a = evaluator_stack.top().number;
                evaluator_stack.pop();
                c.number = evaluate_binary_expression(op_a, op_b, i.operation);
            }
            evaluator_stack.push(c);
        }
    }

    return {evaluator_stack.top().number, true};
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

std::vector<Expression_component> Parameter_processor::expr_vector_to_rpn(const std::vector<Expression_component>& v) {
    // IMPLEMENTATION OF THE SHUNTING YARD ALGORITHM
    std::vector<Expression_component> rpn_exp;
    std::stack<Expression_component> shunting_stack;

    for(auto item:v){
        if(operators_set.contains(item.get_raw_string_value())){ // token is operator
            while (
                    !shunting_stack.empty() &&
                    shunting_stack.top().get_raw_string_value()!="(" &&
                    (
                        !functions_set.contains(shunting_stack.top().get_raw_string_value()) &&
                        operators_precedence[shunting_stack.top().get_raw_string_value()]<operators_precedence[item.get_raw_string_value()] ||
                        operators_precedence[shunting_stack.top().get_raw_string_value()]==operators_precedence[item.get_raw_string_value()] &&
                        !right_associative_set.contains(shunting_stack.top().get_raw_string_value())
                    )
            ){
                rpn_exp.push_back(shunting_stack.top());
                shunting_stack.pop();
            }
            shunting_stack.push(item);
        } else if(item.get_raw_string_value() == "(" || functions_set.contains(item.get_raw_string_value())){
            shunting_stack.push(item);
        } else if(item.get_raw_string_value() == ")"){
            while (shunting_stack.top().get_raw_string_value() != "(") {
                rpn_exp.push_back(shunting_stack.top());
                shunting_stack.pop();
                if(functions_set.contains(shunting_stack.top().get_raw_string_value())){
                    rpn_exp.push_back(shunting_stack.top());
                    shunting_stack.pop();
                }
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

void Parameter_processor::convert_parameters(std::vector<HDL_Resource> &v) {
    for(auto &res:v){
        std::unordered_map<std::string, HDL_parameter> new_params;
        for(auto &item: res.get_parameters()){
            auto rpn_expr = expr_vector_to_rpn(item.second.get_expression_components());
            item.second.set_expression_components(rpn_expr);
            new_params[item.first] = item.second;
        }
        res.set_parameters(new_params);
    }
}


