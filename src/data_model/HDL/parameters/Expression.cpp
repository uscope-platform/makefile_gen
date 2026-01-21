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
        if(item.is_array()) {
            auto arr = std::get<mdarray<int64_t>>(item.get_value());
            ret_val += "{xxxxxxx}";
        } else if(item.is_numeric()){
            ret_val += std::to_string(std::get<int64_t>(item.get_value()));
        } else if(item.is_identifier()){
            if(!item.get_package_prefix().empty()){
                ret_val += item.get_package_prefix() + "::";
            }
            ret_val += std::get<std::string>(item.get_value());
        } else if(item.is_operator()) {
            ret_val += std::get<std::string>(item.get_value());
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
        if (item.is_numeric()) {
            rpn_exp.push_back(item);
        } else if(item.is_operator()){
            while (
                    !shunting_stack.empty() &&
                    std::get<std::string>(shunting_stack.top().get_value())!="(" &&
                    (
                        shunting_stack.top().is_function() ||
                        shunting_stack.top().get_operator_precedence()<item.get_operator_precedence() ||
                        shunting_stack.top().get_operator_precedence()==item.get_operator_precedence() &&
                        !shunting_stack.top().is_right_associative()
                    )
            ){
                rpn_exp.push_back(shunting_stack.top());
                shunting_stack.pop();
            }
            shunting_stack.push(item);
        } else if(std::get<std::string>(item.get_value()) == "(" || item.is_function()){
            shunting_stack.push(item);
        } else if(std::get<std::string>(item.get_value())  == ")"){
            while (std::get<std::string>(shunting_stack.top().get_value()) != "(") {
                rpn_exp.push_back(shunting_stack.top());
                shunting_stack.pop();
                if(shunting_stack.top().is_function()){
                    rpn_exp.push_back(shunting_stack.top());
                    shunting_stack.pop();
                }
            }
            shunting_stack.pop();
        } else {
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

std::optional<resolved_parameter> Expression::evaluate(bool pack_result) {
    if(components.empty()) return std::nullopt;
    if (components.size() == 1) {
        return components[0].get_value();
    }

    auto expr_stack = to_rpm();

    std::stack<Expression_component> evaluator_stack;
    for(auto & i : expr_stack.components){
        if(i.is_numeric()) {
            evaluator_stack.push(i);
        } else {
            int64_t result;
            if (!i.is_operator() && !i.is_function()) return std::nullopt;
            if(i.get_operator_type() == Expression_component::unary_operator){
                auto op = std::get<int64_t>(evaluator_stack.top().get_value());
                result = evaluate_unary_expression(op, std::get<std::string>(i.get_value()));
                evaluator_stack.pop();
            } else if(i.get_operator_type() == Expression_component::binary_operator){
                int64_t op_a;
                auto op_b = std::get<int64_t>(evaluator_stack.top().get_value());
                evaluator_stack.pop();
                if(expr_stack.components.size()==2)
                    op_a = 0;
                else {
                    op_a = std::get<int64_t>(evaluator_stack.top().get_value());
                    evaluator_stack.pop();
                }

                result = evaluate_binary_expression(op_a, op_b, std::get<std::string>(i.get_value()));
            }
            evaluator_stack.emplace(result, Expression_component::number);
        }
    }

    if (evaluator_stack.empty())throw std::runtime_error("Evaluation of an empty expression");
    return std::get<int64_t>(evaluator_stack.top().get_value());

}

int64_t Expression::get_size() {
    if (components.size() == 1) {
        return components[0].get_binary_size();
    }

    auto expression_value = evaluate(false);
    if(expression_value.has_value()) {
        if(std::holds_alternative<int64_t>(expression_value.value()))
            return Expression_component::calculate_binary_size(std::get<int64_t>(expression_value.value()));
    }
    return 0;
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

Expression Expression::clone()  const{
    Expression ret;
    ret.components = components;
    ret.rpn = rpn;
    return ret;
}

std::set<qualified_identifier> Expression::get_dependencies()const {
    std::set<qualified_identifier> result;
    for (auto &comp:components) {
        auto deps = comp.get_dependencies();
        result.insert(deps.begin(), deps.end());
    }
    return result;
}

bool Expression::propagate_constant(const qualified_identifier &constant_id, const resolved_parameter& param_value) {
    bool retval = true;
    for (auto & component : components) {
        if (component.is_identifier()) {
            retval &= component.propagate_constant(constant_id, param_value);
        }
    }
    return retval;
}

void Expression::propagate_function(const HDL_function_def &def) {
    for (auto & component : components) {
        component.propagate_function(def);
    }
}
