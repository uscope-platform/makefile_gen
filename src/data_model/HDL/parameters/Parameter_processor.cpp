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
;
    while(!working_set.empty() && !processing_complete){
        bool list_init_complete = true;
        for(auto &item:working_set){
            if(!item.second.get_initialization_list().empty()){
                auto il = item.second.get_initialization_list();
                auto ret = process_initialization_list(item.first, il, external_parameters);
                if(ret.second){
                    next_working_set.insert(ret.first.begin(), ret.first.end());
                    list_init_complete = true;
                } else{
                    next_working_set.insert(item);
                    list_init_complete = false;
                }
            } else {
                auto processed_param = process_parameter(item.second, external_parameters);
                if(processed_param.second){
                    processed_parameters[item.first] = processed_param.first;
                    working_param_values[item.first] = processed_param.first.get_numeric_value();
                } else{
                    next_working_set[item.first] = item.second;
                }
            }

        }

        if(working_set == next_working_set && list_init_complete){
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

    std::unordered_set<std::string> dependencies;


    if(components.empty()){
        throw std::runtime_error("PARAMETER PROCESSING ERROR:\n Empty parameter");
    }



    // PROCESS SIMPLE PARAMETERS
    if(components.size() == 1){
        if(!components[0].get_array_index().empty()){
            auto comp = get_array_index(components[0].get_string_value(), components[0].get_array_index(), dependencies,parent_parameters);
            if(comp.second){
                std::string param_name = components[0].get_string_value() + "_" + std::to_string(comp.first);
                uint32_t val;
                if(parent_parameters.contains(param_name)){
                    val = parent_parameters[param_name];
                    dependencies.insert(param_name);
                } if(working_param_values.contains(param_name)){
                    val = working_param_values[param_name];
                    dependencies.insert(param_name);
                } else {
                    return {return_par, processing_complete};
                }
                return_par.set_type(numeric_parameter);
                return_par.set_value(val);
                return_par.set_dependencies(dependencies);
                return {return_par, true};
            } else{
                return {return_par, false};
            }
        }else if(components[0].get_type() ==string_component){
            std::string value = components[0].get_string_value();
            uint32_t val;
            if(parent_parameters.contains(par.get_name())){
                val = parent_parameters[par.get_name()];
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
        } else if(components[0].get_type()== numeric_component){
            return_par.set_type(numeric_parameter);
            return_par.set_value(components[0].get_numeric_value());
            processing_complete = true;
        } else {
            throw std::runtime_error("Error: Malformed expression composed by a single operator or Function");
        }
    }


    auto proc_expr = process_expression(components, dependencies, parent_parameters);
    if(proc_expr.second){
        return_par.set_dependencies(dependencies);
        return_par.set_type(numeric_parameter);
        return_par.set_value(proc_expr.first);
        processing_complete = true;
    }

    return {return_par, processing_complete};
}

std::pair<uint32_t , bool> Parameter_processor::get_array_index(std::string param_name, std::vector<Expression> idx, std::unordered_set<std::string> &deps, std::unordered_map<std::string, uint32_t> parent_parameters) {
    bool index_ready = true;
    std::vector<uint32_t> array_index_values;
    for(auto &item:idx){
        auto rpn_expr = expr_vector_to_rpn(item);
        auto res = process_expression(rpn_expr, deps, parent_parameters);
        index_ready |= res.second;
        if(res.second){
            array_index_values.push_back(res.first);
        }
    }

    if(index_ready){
        constexpr std::size_t dimensions[] = {2, 2};

        size_t index = 0;
        size_t mul = 1;

        for (size_t i = 0; i < array_index_values.size(); ++i) {
            auto j = array_index_values.size()-i-1;
            index += array_index_values[j] * mul;
            mul *= dimensions[j];
        }
        return {index, true};
    } else{
        return {0, false};
    }

}



std::pair<uint32_t , bool>  Parameter_processor::process_expression(const std::vector<Expression_component>& expr, std::unordered_set<std::string> &deps) {
    return process_expression(expr, deps, {});
}

std::pair<uint32_t, bool>
Parameter_processor::process_expression(const std::vector<Expression_component> &expr, std::unordered_set<std::string> &deps,
                                        std::unordered_map<std::string, uint32_t> parent_parameters) {
    uint32_t ret_value = 0;
    bool return_valid = false;

    std::vector<Expression_component> processed_rpn;

    for(auto i : expr){
        if(!i.get_array_index().empty()){
            bool index_ready = false;
            std::vector<uint32_t> array_index_values;
            for(auto &item:i.get_array_index()){
                auto rpn_expr = expr_vector_to_rpn(item);
                auto res = process_expression(rpn_expr, deps, parent_parameters);
                index_ready |= res.second;
                if(res.second){
                    array_index_values.push_back(res.first);
                }
            }
            if(index_ready){
                Expression_component ne(i.get_string_value() + "_"+ std::to_string(array_index_values[0]));
                i = ne;
            } else{
                return {ret_value, return_valid};
            }

        }

        if(i.get_type() == numeric_component || i.get_type() == operator_component || i.get_type()==function_component){
            processed_rpn.push_back(i);
        } else if(i.get_type() == string_component) {
            if(parent_parameters.contains(i.get_string_value())){
                processed_rpn.emplace_back(parent_parameters[i.get_raw_string_value()]);
                deps.insert(i.get_raw_string_value());
            } else if(working_param_values.contains(i.get_raw_string_value())){
                processed_rpn.emplace_back(working_param_values[i.get_raw_string_value()]);
                deps.insert(i.get_raw_string_value());
            } else {
                return {ret_value, return_valid};
            }
        }

    }

    std::stack<Expression_component> evaluator_stack;

    for(auto & i : processed_rpn){
        if(i.get_type() == numeric_component){
            evaluator_stack.push(i);
        } else {
            uint32_t result;
            if(i.get_operator_type() == Expression_component::unary_operator){
                result = evaluate_unary_expression(evaluator_stack.top().get_numeric_value(), i.get_string_value());
                evaluator_stack.pop();
            } else if(i.get_operator_type() == Expression_component::binary_operator){
                auto op_b = evaluator_stack.top().get_numeric_value();
                evaluator_stack.pop();
                auto op_a = evaluator_stack.top().get_numeric_value();
                evaluator_stack.pop();
                result = evaluate_binary_expression(op_a, op_b, i.get_raw_string_value());
            }
            evaluator_stack.push(Expression_component(result));
        }
    }

    return {evaluator_stack.top().get_numeric_value(),true};
}


uint32_t Parameter_processor::evaluate_binary_expression(uint32_t op_a, uint32_t op_b, const std::string& operation) {
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

uint32_t Parameter_processor::evaluate_unary_expression(uint32_t operand, const std::string& operation) {
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
        if(item.get_type() == operator_component){ // token is operator
            while (
                    !shunting_stack.empty() &&
                    shunting_stack.top().get_raw_string_value()!="(" &&
                    (
                        shunting_stack.top().get_type() == function_component &&
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

std::pair<std::unordered_map<std::string, HDL_parameter>, bool>
Parameter_processor::process_initialization_list(const std::string& param_name, std::vector<std::vector<Expression_component>> &il,const std::unordered_map<std::string, uint32_t> parent_parameters) {
    std::unordered_map<std::string, HDL_parameter> ret;
    bool ret_valid = false;
    for(int i = 0; i<il.size(); i++){
        if(il[i][0].get_string_value() == "$repeat_init"){
            std::unordered_set<std::string> deps;
            auto init_size = process_expression(il[i+1], deps, parent_parameters);
            auto init_val = process_expression(il[i+2], deps, parent_parameters);
            i +=3;
            if(init_size.second && init_val.second){
                for(int j =0; j<init_size.first; j++){
                    HDL_parameter p;
                    auto name = param_name+"_"+std::to_string(j);
                    p.set_name(name);
                    p.set_expression_components({Expression_component(std::to_string(init_val.first))});
                    ret[name] = p;
                }
                ret_valid = true;
            } else {
                ret_valid = false;
            }

        } else{
            HDL_parameter p;
            auto name = param_name+"_"+std::to_string(i);
            p.set_name(name);
            p.set_expression_components(il[i]);
            ret[name] = p;
            ret_valid = true;
        }
    }
    return {ret,ret_valid};
}

