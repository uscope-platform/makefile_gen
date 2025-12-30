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


#include "data_model/HDL/parameters/Expression.hpp"

std::string Expression::print() const {
    std::string ret_val;
    for(auto &item:components){
        if(item.get_type() == numeric_component){
            ret_val += std::to_string(item.get_numeric_value());
        } else if(item.get_type() == string_component || item.get_type() == operator_component || item.get_type()== function_component) {
            if(!item.get_package_prefix().empty()){
                ret_val += item.get_package_prefix() + "::";
            }
            ret_val += item.get_string_value();
        }
    }
    return ret_val;
}

Expression Expression::to_rpm() const {
    Expression rpn_exp;
    std::stack<Expression_component> shunting_stack;

    if(components.empty()){
        return {};
    }
    if(rpn){
        Expression expr;
        expr.components = components;
        expr.rpn = rpn;
        return expr;
    }

    for(auto item:components){
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
    rpn_exp.rpn = true;
    return rpn_exp;
}

std::optional<int64_t> Expression::evaluate() {
    return evaluate(nullptr);
}

std::optional<int64_t> Expression::evaluate(int64_t *result_size) {
    if (components.size() == 1) {
        if (components[0].is_numeric()) return components[0].get_numeric_value();
        return std::nullopt;
    }

    auto expr_stack = to_rpm();



    std::stack<Expression_component> evaluator_stack;
    for(auto & i : expr_stack.components){
        if(i.get_type() == numeric_component) {
            evaluator_stack.push(i);
        } else {
            int64_t result;
            if(i.get_operator_type() == Expression_component::unary_operator){
                auto op = evaluator_stack.top().get_numeric_value();
                result = evaluate_unary_expression(op, i.get_string_value());
                evaluator_stack.pop();
            } else if(i.get_operator_type() == Expression_component::binary_operator){
                int64_t op_a;
                auto op_b = evaluator_stack.top().get_numeric_value();
                evaluator_stack.pop();
                if(expr_stack.components.size()==2)
                    op_a = 0;
                else {
                    op_a = evaluator_stack.top().get_numeric_value();
                    evaluator_stack.pop();
                }

                result = evaluate_binary_expression(op_a, op_b, i.get_raw_string_value());
            }
            evaluator_stack.emplace(result);
        }
    }
    if(result_size != nullptr){

        *result_size = Expression_component::calculate_binary_size(evaluator_stack.top().get_numeric_value());
    }
    if (evaluator_stack.empty())throw std::runtime_error("Evaluation of an empty expression");
    return evaluator_stack.top().get_numeric_value();



}


int64_t Expression::evaluate_binary_expression(int64_t op_a, int64_t op_b, const std::string &operation) {
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

int64_t Expression::evaluate_unary_expression(int64_t operand, const std::string &operation) {
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
void Expression::propagate_constant(const std::string &name, int64_t value) {
    for (auto & component : components) {
        if (component.get_type() == string_component) {
            if (component.get_string_value() == name) {
                component.set_numeric_value(value);
            }
        }
    }
}