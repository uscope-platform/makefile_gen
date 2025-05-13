//  Copyright 2025 Filippo Savi
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

#include"data_model/HDL/parameters/Expression_evaluator.hpp"


std::vector<Expression_component> Expression_evaluator::expr_vector_to_rpn(const std::vector<Expression_component> &v) {// IMPLEMENTATION OF THE SHUNTING YARD ALGORITHM
    std::vector<Expression_component> rpn_exp;
    std::stack<Expression_component> shunting_stack;

    if(v.size()==0){
        return {};
    }
    if(v[0].is_rpn()){
        return v;
    }

    for(auto item:v){
        if(item.get_type() == operator_component){ // token is operator
            while (
                    !shunting_stack.empty() &&
                    shunting_stack.top().get_raw_string_value()!="(" &&
                    (
                        shunting_stack.top().get_type() == function_component ||
                        shunting_stack.top().get_operator_precedence()<item.get_operator_precedence() ||
                        shunting_stack.top().get_operator_precedence()==item.get_operator_precedence() &&
                        !shunting_stack.top().is_right_associative()
                    )
            ){
                rpn_exp.push_back(shunting_stack.top());
                shunting_stack.pop();
            }
            shunting_stack.push(item);
        } else if(item.get_raw_string_value() == "(" || item.get_type() == function_component){
            shunting_stack.push(item);
        } else if(item.get_raw_string_value() == ")"){
            while (shunting_stack.top().get_raw_string_value() != "(") {
                rpn_exp.push_back(shunting_stack.top());
                shunting_stack.pop();
                if(shunting_stack.top().get_type()==function_component){
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
    Expression_component e("");
    e.set_rpn_marker();
    rpn_exp.insert(rpn_exp.begin(), {e});
    return rpn_exp;
}

int64_t Expression_evaluator::evaluate_binary_expression(int64_t op_a, int64_t op_b, const std::string &operation) {
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
    } else if(operation ==  ">"){
        return op_a > op_b;
    } else if(operation ==  ">="){
        return op_a >= op_b;
    } else if(operation ==  "<"){
        return op_a < op_b;
    } else if(operation ==  "<="){
        return op_a <= op_b;
    } else if(operation ==  "=="){
        return op_a == op_b;
    } else if(operation ==  "!="){
        return op_a != op_b;
    } else{
        throw std::runtime_error("Error: Attempted evaluation of an unsupported binary expression expression " + operation);
    }
}

int64_t Expression_evaluator::evaluate_unary_expression(int64_t operand, const std::string &operation) {
    if(operation == "!"){
        return !operand;
    } else if(operation ==  "~"){
        return ~operand;
    } else if(operation ==  "$clog2"){
        return (int64_t) ceil(log2((double) operand));
    } else if(operation ==  "$ceil"){
        return (int64_t) ceil((double) operand);
    } else if(operation ==  "$floor"){
        return (int64_t) floor((double) operand);
    } else{
        throw std::runtime_error("Error: Attempted evaluation of an unsupported unary expression expression " + operation);
    }
}
