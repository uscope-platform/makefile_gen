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


Parameter_processor::Parameter_processor(const std::map<std::string, HDL_parameter> &parent_parameters, const std::shared_ptr<data_store> &ds) {
    d_store = ds;
    external_parameters = std::make_shared<std::map<std::string, HDL_parameter>>(parent_parameters);
    working_param_values = std::make_shared<std::unordered_map<std::string, int64_t>>();
    working_param_array_values = std::make_shared<std::unordered_map<std::string, mdarray>>();
}

Parameter_processor::Parameter_processor(const std::map<std::string, HDL_parameter> &ep,
                                         std::shared_ptr<std::unordered_map<std::string, int64_t>> &wp,
                                         std::shared_ptr<std::unordered_map<std::string, mdarray>> &wpa) {
    d_store = {};
    external_parameters = std::make_shared<std::map<std::string, HDL_parameter>>(ep);
    working_param_values = wp;
    working_param_array_values = wpa;
}


HDL_Resource Parameter_processor::process_resource(const HDL_Resource &res) {


    HDL_Resource return_res = res;

    std::map<std::basic_string<char>, HDL_parameter> processed_parameters;
    std::map<std::basic_string<char>, HDL_parameter> working_set = return_res.get_parameters();
    std::map<std::basic_string<char>, HDL_parameter> next_working_set;

    bool processing_complete = false;
    int nesting_limit = 1000;
    while(!working_set.empty() && !processing_complete && nesting_limit >0){
        bool list_init_complete = true;
        for(auto &item:working_set){
            if(item.second.is_array()){
                try{
                    Initialization_list il;
                    if(external_parameters->contains(item.first)){
                        il = external_parameters->at(item.first).get_i_l();
                    } else {
                        il = item.second.get_i_l();
                    }

                    il.link_processor(working_param_values, external_parameters, working_param_array_values);
                    working_param_array_values->insert({item.first, il.get_values()});
                    processed_parameters[item.first] = item.second;
                    list_init_complete = true;
                } catch (Parameter_processor_Exception &ex) {
                    next_working_set.insert(item);
                    list_init_complete = false;
                }
            } else {
                try{
                    auto processed_param = process_parameter(item.second);
                    processed_parameters[item.first] = processed_param;
                    working_param_values->insert({item.first, processed_param.get_numeric_value()});
                } catch (Parameter_processor_Exception &ex){
                    next_working_set[item.first] = item.second;
                }
            }
        }

        if(working_set == next_working_set && list_init_complete){
            processing_complete = true;
        }
        working_set = next_working_set;
        next_working_set.clear();
        nesting_limit--;
        if(nesting_limit==0){
            std::cerr<<"Warning: infinite loop detected while processing the following parameters: \n";
            for(const auto& item:working_set){
                std::cerr<< "    - " + item.second.get_name() + "\n";
            }
            std::cerr<<return_res.get_path() + "\n";
        }
    }

    for(auto &item:working_set){
        processed_parameters[item.first] = item.second;
    }

    return_res.set_parameters(processed_parameters);

    return return_res;
}

std::map<std::string, HDL_parameter> Parameter_processor::process_parameters_map(std::map<std::string, HDL_parameter> &map) {
    std::map<std::string, HDL_parameter> ret;
    for(auto &item:map){
        try{
            auto par = item.second;
            par.set_expression_components(expr_vector_to_rpn(par.get_expression_components()));
            ret[item.first] = process_parameter(par);
        } catch (array_override_exception &ex) {
            auto array_value = ex.array_value;
            auto p_n = ex.param_name;
            for(const auto& item:array_value){
                //TODO: harray balues
            }
        }
    }

    return ret;
}


HDL_parameter Parameter_processor::process_parameter(const HDL_parameter &par) {

    HDL_parameter return_par = par;
    current_parameter = par.get_name();
    auto components = return_par.get_expression_components();


    if(components.empty()){
        throw std::runtime_error("PARAMETER PROCESSING ERROR:\n Empty parameter");
    }

    if(par.get_type() == numeric_parameter){
        return return_par;
    }
    int64_t value;
    if(external_parameters->contains(return_par.get_name())){
        value = external_parameters->at(return_par.get_name()).get_numeric_value();
        return_par.set_expression_components({Expression_component(std::to_string(value) )});
    } else{
        value = process_expression(components);
    }

    return_par.set_value(value);
    return_par.set_type(numeric_parameter);
    return return_par;
}


int64_t Parameter_processor::process_expression(const std::vector<Expression_component> &expr) {

    std::vector<Expression_component> processed_rpn;

    if(expr.size() == 1){
        auto comp = expr[0];
        return get_component_value(comp);
    }

    for(auto i : expr){
        if(!i.get_array_index().empty()){
            i = process_array_access(i);
        }

        if(i.get_type() == numeric_component || i.get_type() == operator_component || i.get_type()==function_component){
            processed_rpn.push_back(i);
        } else if(i.get_type() == string_component) {
            if(external_parameters->contains(i.get_string_value())){
                Expression_component e(external_parameters->at(i.get_raw_string_value()).get_numeric_value());
                processed_rpn.emplace_back(e);
            } else if(working_param_values->contains(i.get_raw_string_value())){
                processed_rpn.emplace_back(working_param_values->at(i.get_raw_string_value()));
            } else {
                throw Parameter_processor_Exception();
            }
        }

    }

    std::stack<Expression_component> evaluator_stack;

    for(auto & i : processed_rpn){
        if(i.get_type() == numeric_component){
            evaluator_stack.push(i);
        } else {
            int64_t result;
            if(i.get_operator_type() == Expression_component::unary_operator){
                auto op = get_component_value(evaluator_stack.top());
                result = evaluate_unary_expression(op, i.get_string_value());
                evaluator_stack.pop();
            } else if(i.get_operator_type() == Expression_component::binary_operator){
                int64_t op_a;
                auto op_b = get_component_value(evaluator_stack.top());
                evaluator_stack.pop();
                if(processed_rpn.size()==2)
                    op_a = 0;
                else {
                    op_a = get_component_value(evaluator_stack.top());
                    evaluator_stack.pop();
                }

                result = evaluate_binary_expression(op_a, op_b, i.get_raw_string_value());
            }
            evaluator_stack.emplace(result);
        }
    }

    return evaluator_stack.top().get_numeric_value();
}


int64_t Parameter_processor::evaluate_binary_expression(int64_t op_a, int64_t op_b, const std::string& operation) {
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

int64_t Parameter_processor::evaluate_unary_expression(int64_t operand, const std::string& operation) {
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
        std::map<std::string, HDL_parameter> new_params;
        for(auto &item: res.get_parameters()){
            auto rpn_expr = expr_vector_to_rpn(item.second.get_expression_components());
            item.second.set_expression_components(rpn_expr);
            new_params[item.first] = item.second;
        }
        res.set_parameters(new_params);
    }
}

int64_t Parameter_processor::get_component_value(Expression_component &ec) {

    if(ec.get_type() == numeric_component){
        return ec.get_numeric_value();
    } else if(ec.get_type() == operator_component || ec.get_type() == function_component){
        throw std::runtime_error("Error: attempted to get the numeric value of an operator or Function");
    }

    if(!ec.get_package_prefix().empty()){

        auto pkg = ec.get_package_prefix();
        if(d_store->contains_hdl_entity(pkg)){
            auto res = d_store->get_HDL_resource(pkg);
            auto val = res.get_parameters()[ec.get_string_value()].get_numeric_value();
            return val;
        } else{
            throw std::runtime_error("Error: Encountered unknown package: " + ec.get_package_prefix());
        }
    }

    std::string param_name;
    if(!ec.get_array_index().empty()){
        return process_array_access(ec).get_numeric_value();
    } else{
        param_name = ec.get_string_value();
    }

    int value_type = 0;

    std::map<std::vector<int64_t>, int64_t>   result_array;
    int64_t val;
    for(auto &item:*external_parameters){
        if(param_name == item.first){
            val = external_parameters->at(param_name).get_numeric_value();
            value_type = 1;
        } else{
            bool is_prefix = item.first.compare(0, param_name.size(), param_name) == 0;
            if(is_prefix){

                std::istringstream iss(item.first.substr(param_name.length()));
                std::vector<int64_t> indexes;
                std::string s;
                while (std::getline(iss, s, '_')) {
                    if(!s.empty()){
                        indexes.push_back(std::stoll(s));
                    }
                }
                result_array[indexes] = item.second.get_numeric_value();
                value_type = 2;
            }
        }
    }

    if(value_type == 2) {
        throw array_override_exception(result_array, current_parameter);
    } else if(working_param_values->contains(param_name)) {
        val = working_param_values->at(param_name);
    } else if(working_param_array_values->contains(param_name)){
        throw array_value_exception(working_param_array_values->at(param_name));
    } else if(value_type == 0) {
        throw Parameter_processor_Exception();
    }

    return val;
}

Expression_component Parameter_processor::process_array_access(Expression_component &e) {
    if(e.get_array_index().size() > 3){
        throw std::invalid_argument("ERROR: Arrays with more than 3 parameters are not supported");
    }
    std::vector<int64_t> array_index_values(3, 0);

    auto raw_idx = e.get_array_index();

    for(uint64_t i = 0; i<raw_idx.size(); i++){
        auto rpn_expr = expr_vector_to_rpn(raw_idx[i]);
        auto res = process_expression(rpn_expr);
        array_index_values[raw_idx.size()-1-i] = res;
    }

    std::reverse(array_index_values.begin(), array_index_values.end());

    if(working_param_array_values->contains(e.get_string_value())){
        auto val = working_param_array_values->at(e.get_string_value()).get_value(array_index_values);
        return Expression_component(val);
    } else {
        throw Parameter_processor_Exception();
    }
}

