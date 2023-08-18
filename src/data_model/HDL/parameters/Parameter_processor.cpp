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
    compleated_set = std::make_shared<std::unordered_map<std::string, HDL_parameter>>();
}

Parameter_processor::Parameter_processor(const std::map<std::string, HDL_parameter> &ep,
                                         std::shared_ptr<std::unordered_map<std::string, HDL_parameter>> &cs) {
    d_store = {};
    external_parameters = std::make_shared<std::map<std::string, HDL_parameter>>(ep);
    compleated_set = cs;
}


HDL_Resource Parameter_processor::process_resource(const HDL_Resource &res) {


    HDL_Resource return_res = res;

    std::map<std::basic_string<char>, HDL_parameter> working_set = return_res.get_parameters();
    std::map<std::basic_string<char>, HDL_parameter> next_working_set;

    int nesting_limit = 1000;
    bool processing_complete = false;
    while(!working_set.empty() && !processing_complete){
        for(auto &item:working_set){
            try{
                HDL_parameter processed_param;
                if(item.second.is_packed_array()){
                    processed_param = process_packed_parameter(item.second);
                }else if(item.second.is_array()){
                    processed_param = process_array_parameter(item.second);
                } else {
                    processed_param = process_scalar_parameter(item.second);
                }
                compleated_set->insert({item.first, processed_param});
            } catch (Parameter_processor_Exception &ex) {
                next_working_set.insert(item);
            }
        }

        if(working_set == next_working_set){
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
            exit(1);
        }
    }


    std::map<std::basic_string<char>, HDL_parameter> processed_parameters(compleated_set->begin(), compleated_set->end());

    for(auto &item:working_set){
        auto param = item.second;
        std::string value;
        for(auto &val : param.get_expression_components()){
            value += val.get_raw_string_value();
        }

        value.erase(std::remove( value.begin(), value.end(), '\"' ),value.end());
        param.set_value(value);
        processed_parameters[item.first] = param;
    }

    return_res.set_parameters(processed_parameters);

    return return_res;
}

std::map<std::string, HDL_parameter> Parameter_processor::process_parameters_map(std::map<std::string, HDL_parameter> &map, HDL_Resource &spec) {
    std::map<std::string, HDL_parameter> ret;
    for(auto &item:map){
        auto par = item.second;
        par.set_expression_components(expr_vector_to_rpn(par.get_expression_components()));
        if(external_parameters->contains(item.first)){
            ret[item.first] = external_parameters->at(item.first);
        } else {
            if(par.is_array()){
                auto spec_il = spec.get_parameters()[par.get_name()].get_i_l();
                auto param_il = par.get_i_l();
                param_il.set_packed_dimensions(spec_il.get_packed_dimensions());
                param_il.set_unpacked_dimensions(spec_il.get_unpacked_dimensions());
                par.add_initialization_list(param_il);
                ret[item.first] = process_array_parameter(par);
            } else {
                try{
                    ret[item.first] = process_scalar_parameter(par);
                } catch (Parameter_processor_Exception &ex){
                    HDL_parameter p = item.second;
                    p.set_value(ex.str_val);
                    ret[item.first] = p;
                }

            }
        }
    }
    return ret;
}


HDL_parameter Parameter_processor::process_scalar_parameter(const HDL_parameter &par) {

    HDL_parameter return_par = par;
    auto components = return_par.get_expression_components();


    if(components.empty()){
        throw std::runtime_error("PARAMETER PROCESSING ERROR:\n Empty parameter");
    }

    if(par.get_type() == numeric_parameter){
        return return_par;
    }

    try {
        if (external_parameters->contains(return_par.get_name())) {
            if(external_parameters->at(return_par.get_name()).is_array()){
                auto value = external_parameters->at(return_par.get_name()).get_array_value();
                return_par.set_array_value(value);
            } else {
                auto parameter = external_parameters->at(return_par.get_name());
                if(parameter.get_type() == numeric_parameter){
                    auto value = parameter.get_numeric_value();
                    return_par.set_expression_components({Expression_component(std::to_string(value))});
                    return_par.set_value(value);
                } else {
                    auto value = parameter.get_string_value();
                    return_par.set_expression_components({Expression_component(value)});
                    return_par.set_value(value);
                }
            }

        } else {
            return_par.set_value(process_expression(components, nullptr));;
        }



    } catch (array_value_exception &ex){
        return_par.set_array_value(ex.array_value);
    } catch (string_parameter_exception &ex){
        return_par.set_value(ex.str_val);
    }

    return return_par;
}


int64_t Parameter_processor::process_expression(const std::vector<Expression_component> &expr, int64_t *result_size) {

    std::vector<Expression_component> processed_rpn;

    if(expr.size() == 1){
        auto comp = expr[0];
        return get_component_value(comp, result_size);
    }

    for(auto i : expr){
        if(!i.get_array_index().empty()){
            i = process_array_access(i);
        }

        if(i.get_type() == numeric_component || i.get_type() == operator_component || i.get_type()==function_component){
            processed_rpn.push_back(i);
        } else if(i.get_type() == string_component) {
            if(external_parameters->contains(i.get_string_value())) {
                Expression_component e(external_parameters->at(i.get_raw_string_value()).get_numeric_value());
                processed_rpn.emplace_back(e);
            } else if(compleated_set->contains(i.get_raw_string_value())){
                processed_rpn.emplace_back(compleated_set->at(i.get_raw_string_value()).get_numeric_value());
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
                auto op = get_component_value(evaluator_stack.top(), nullptr);
                result = evaluate_unary_expression(op, i.get_string_value());
                evaluator_stack.pop();
            } else if(i.get_operator_type() == Expression_component::binary_operator){
                int64_t op_a;
                auto op_b = get_component_value(evaluator_stack.top(), nullptr);
                evaluator_stack.pop();
                if(processed_rpn.size()==2)
                    op_a = 0;
                else {
                    op_a = get_component_value(evaluator_stack.top(), nullptr);
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

int64_t Parameter_processor::get_component_value(Expression_component &ec, int64_t *result_size) {

    if(ec.get_type() == numeric_component){
        if(result_size != nullptr){
            *result_size = ec.get_binary_size();
        }
        return ec.get_numeric_value();
    } else if(ec.get_type() == operator_component || ec.get_type() == function_component){
        throw std::runtime_error("Error: attempted to get the numeric value of an operator or Function");
    }

    if(!ec.get_package_prefix().empty()){

        auto pkg = ec.get_package_prefix();
        if(d_store->contains_hdl_entity(pkg)){
            auto res = d_store->get_HDL_resource(pkg);
            auto val = res.get_parameters()[ec.get_string_value()].get_numeric_value();
            if(result_size != nullptr){
                *result_size = Expression_component::calculate_binary_size(val);
            }
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

    std::map<std::vector<int64_t>, int64_t>   result_array;
    int64_t val;

    if(external_parameters->contains(param_name)) {
        auto parameter = external_parameters->at(param_name);
        if (parameter.get_type() == array_parameter) {
            throw array_value_exception(parameter.get_array_value());
        } else if(parameter.get_type() == string_parameter) {
            throw string_parameter_exception(parameter.get_string_value());
        } else {
            val = parameter.get_numeric_value();
            if(result_size != nullptr){
                *result_size = std::ceil(std::log2(val));
                if(val == 0) {
                    *result_size = Expression_component::calculate_binary_size(val);
                }
            }
        }
    } else if(compleated_set->contains(param_name)) {
        if (compleated_set->at(param_name).is_array()) {
            throw array_value_exception(compleated_set->at(param_name).get_array_value());
        } else {
            val = compleated_set->at(param_name).get_numeric_value();
            if (result_size != nullptr) {
                *result_size = Expression_component::calculate_binary_size(val);
            }
        }
    } else {
        auto s = ec.get_string_value();
        s.erase(std::remove( s.begin(), s.end(), '\"' ),s.end());
        throw Parameter_processor_Exception(s);
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
        auto res = process_expression(rpn_expr, nullptr);
        array_index_values[raw_idx.size()-1-i] = res;
    }

    std::reverse(array_index_values.begin(), array_index_values.end());

    HDL_parameter p;
    if(external_parameters->contains(e.get_string_value())){
        p = external_parameters->at(e.get_string_value());
    }else if(compleated_set->contains(e.get_string_value())){
        p = compleated_set->at(e.get_string_value());
    } else {
        throw Parameter_processor_Exception();
    }
    int64_t  val;
    if(p.get_type() == array_parameter){
        val = p.get_array_value().get_value(array_index_values);
    } else {
        auto mask = 0x1<<array_index_values[2];
        val = (p.get_numeric_value()&mask)>>array_index_values[2];
    }
    return Expression_component(val);
}

HDL_parameter Parameter_processor::process_array_parameter(const HDL_parameter &par) {
    HDL_parameter return_par = par;
    mdarray arr_val;
    if(external_parameters->contains(par.get_name())){
        if(external_parameters->at(par.get_name()).get_type()==array_parameter){
            arr_val = external_parameters->at(par.get_name()).get_array_value();
            return_par.add_initialization_list({});
        } else {
            Initialization_list il = external_parameters->at(par.get_name()).get_i_l();
            il.link_processor( external_parameters, compleated_set, d_store);
            arr_val = il.get_values();
        }

    } else {
        Initialization_list il = return_par.get_i_l();
        il.link_processor( external_parameters, compleated_set, d_store);
        arr_val = il.get_values();
    }
    return_par.set_array_value(arr_val);
    return_par.clear_expression_components();
    compleated_set->insert({par.get_name(), return_par});
    return return_par;
}

HDL_parameter Parameter_processor::process_packed_parameter(const HDL_parameter &par) {
    HDL_parameter return_par = par;
    Initialization_list il;
    if(external_parameters->contains(return_par.get_name())){
        if(external_parameters->at(return_par.get_name()).get_type() == numeric_parameter){
            return_par.set_value(external_parameters->at(return_par.get_name()).get_numeric_value());
            return return_par;
        } else if(external_parameters->at(return_par.get_name()).get_type() == string_parameter){
            return_par.set_value(external_parameters->at(return_par.get_name()).get_string_value());
            return return_par;
        } else{
            il = external_parameters->at(return_par.get_name()).get_i_l();
        }
    } else {
        il = return_par.get_i_l();
    }
    il.link_processor( external_parameters,  compleated_set, d_store);
    auto val_array = il.get_values();
    return_par.set_value(val_array.get_value({0,0,0}));

    return return_par;
}

