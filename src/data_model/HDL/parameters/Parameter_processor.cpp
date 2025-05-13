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


Parameter_processor::Parameter_processor(const Parameters_map &parent_parameters, const std::shared_ptr<data_store> &ds) {
    d_store = ds;
    external_parameters = std::make_shared<Parameters_map>(parent_parameters);
    compleated_set = std::make_shared<Parameters_map>();
}

Parameter_processor::Parameter_processor(const Parameters_map &ep,
                                         std::shared_ptr<Parameters_map> &cs) {
    d_store = {};
    external_parameters = std::make_shared<Parameters_map>(ep);
    compleated_set = cs;
}

Parameters_map Parameter_processor::process_parameters_map(const Parameters_map &map, HDL_Resource &spec) {


    Parameters_map working_set = map;
    Parameters_map next_working_set;
    int override_cnt = 5;
    while (!working_set.empty() && override_cnt != 0){
        for(auto &item:working_set){
            try{
                auto par = item;
                auto dbg = par->get_name();
                if(external_parameters->contains(item->get_name())){
                    // The parameter needs to be copied out of external parameters and into the completed set otherwise it will go out of scope
                    auto param = external_parameters->get(item->get_name());
                    compleated_set->insert(param);
                } else {
                    compleated_set->insert(process_parameter(par, spec));
                }
            } catch (Parameter_processor_Exception &ex){
                if(!ex.unknown_parameter){
                    auto p = item;
                    p->set_value(ex.str_val);
                    string_set.insert({ex.str_val, p});
                }
                next_working_set.insert(item);
            }
        }

        for(auto &item:string_set){
            if(!next_working_set.contains(item.first)){
                compleated_set->insert(item.second);
                next_working_set.erase(item.second->get_name());
            }
        }
        working_set = next_working_set;
        string_set.clear();
        next_working_set.clear();
        override_cnt--;
    }

    for(auto &item:working_set){
        compleated_set->insert(item);
    }

    return *compleated_set;
}


std::shared_ptr<HDL_parameter> Parameter_processor::process_parameter(const std::shared_ptr<HDL_parameter> &par, HDL_Resource &spec) {
    std::shared_ptr<HDL_parameter> p;
    if(par->get_type()== function_parameter) {
        auto fs = spec.get_functions();
        auto components = par->get_expression_components();
        if(components.size() != 1) {
            throw std::runtime_error("ERROR: Function initialized parameters with arguments are not supported");
        }
        auto function = spec.get_functions().at(components[0].get_string_value());
        if(function.is_scalar()) {
            p = process_scalar_function_parameter(par, function);
        } else {
            p = process_vector_function_parameter(par, function);
        }
    } else if(par->is_array()){
        auto spec_il = spec.get_parameters().get(par->get_name())->get_i_l();
        auto param_il = par->get_i_l();
        param_il.set_packed_dimensions(spec_il.get_packed_dimensions());
        param_il.set_unpacked_dimensions(spec_il.get_unpacked_dimensions());
        par->add_initialization_list(param_il);
        p =  process_array_parameter(par);
    } else {
        p = process_scalar_parameter(par);
    }
    return p;
}

std::shared_ptr<HDL_parameter> Parameter_processor::process_scalar_function_parameter(
    const std::shared_ptr<HDL_parameter> &par,
    const HDL_function &fcn
) {
    std::shared_ptr<HDL_parameter> return_par = par;
    auto expr = fcn.get_assignments()[0].value;
    auto res = process_expression(expr, nullptr);
    return_par->set_value(res);
    return return_par;
}

std::shared_ptr<HDL_parameter> Parameter_processor::process_vector_function_parameter(
    const std::shared_ptr<HDL_parameter> &par, const HDL_function &fcn) {
    int i = 0;
}


std::shared_ptr<HDL_parameter> Parameter_processor::process_scalar_parameter(const std::shared_ptr<HDL_parameter> &par) {

    std::shared_ptr<HDL_parameter> return_par = par;
    auto components = return_par->get_expression_components();

    if(par->get_type() == numeric_parameter){
        return return_par;
    }

    if(components.empty()){
        std::string error_s = "PARAMETER PROCESSING ERROR: Encountered Empty parameter (" + par->get_name() + ")";
        throw std::runtime_error(error_s);
    }


    try {
        if (external_parameters->contains(return_par->get_name())) {
            if(external_parameters->get(return_par->get_name())->is_array()){
                auto value = external_parameters->get(return_par->get_name())->get_array_value();
                return_par->set_array_value(value);
            } else {
                auto parameter = external_parameters->get(return_par->get_name());
                if(parameter->get_type() == numeric_parameter){
                    auto value = parameter->get_numeric_value();
                    return_par->set_expression_components({Expression_component(std::to_string(value))});
                    return_par->set_value(value);
                } else {
                    auto value = parameter->get_string_value();
                    return_par->set_expression_components({Expression_component(value)});
                    return_par->set_value(value);
                }
            }

        } else {
            return_par->set_value(process_expression(components, nullptr));;
        }



    } catch (array_value_exception &ex){
        return_par->set_array_value(ex.array_value);
    } catch (string_parameter_exception &ex){
        return_par->set_value(ex.str_val);
    }

    return return_par;
}


int64_t Parameter_processor::process_expression(const std::vector<Expression_component> &expr, int64_t *result_size) {

    std::vector<Expression_component> rpn_vect;
    if(!expr[0].is_rpn()){
        if(expr.size()==1){
            auto comp = expr[0];
            return get_component_value(comp, result_size);
        } else {
            rpn_vect = expr_vector_to_rpn(expr);
        }
    } else {
        if(expr.size() == 2){
            auto comp = expr[1];
            return get_component_value(comp, result_size);
        } else {
            rpn_vect = std::move(expr);
            rpn_vect.erase(rpn_vect.begin());
        }

    }

    std::vector<Expression_component> processed_rpn;


    for(auto i : rpn_vect){
        if(!i.get_array_index().empty()){
            i = process_array_access(i);
        }

        if(i.get_type() == numeric_component || i.get_type() == operator_component || i.get_type()==function_component){
            processed_rpn.push_back(i);
        } else if(i.get_type() == string_component) {
            if(external_parameters->contains(i.get_string_value())) {
                Expression_component e(external_parameters->get(i.get_raw_string_value())->get_numeric_value());
                processed_rpn.emplace_back(e);
            } else if(compleated_set->contains(i.get_raw_string_value())){
                processed_rpn.emplace_back(compleated_set->get(i.get_raw_string_value())->get_numeric_value());
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

void Parameter_processor::convert_parameters(std::vector<HDL_Resource> &v) {
    for(auto &res:v){
        Parameters_map new_params;
        for(auto &item: res.get_parameters()){
            new_params.insert(item);
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
            Parameter_processor p({}, d_store);
            auto pkg_params = p.process_parameters_map(res.get_parameters(),res);
            auto val = pkg_params.get(ec.get_string_value())->get_numeric_value();
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
        auto parameter = external_parameters->get(param_name);
        if (parameter->get_type() == array_parameter) {
            throw array_value_exception(parameter->get_array_value());
        } else if(parameter->get_type() == string_parameter) {
            throw string_parameter_exception(parameter->get_string_value());
        } else {
            val = parameter->get_numeric_value();
            if(result_size != nullptr){
                *result_size = std::ceil(std::log2(val));
                if(val == 0) {
                    *result_size = Expression_component::calculate_binary_size(val);
                }
            }
        }
    } else if(compleated_set->contains(param_name)) {
        if (compleated_set->get(param_name)->is_array()) {
            throw array_value_exception(compleated_set->get(param_name)->get_array_value());
        } else {
            val = compleated_set->get(param_name)->get_numeric_value();
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
        auto res = process_expression(raw_idx[i], nullptr);
        array_index_values[raw_idx.size()-1-i] = res;
    }

    std::reverse(array_index_values.begin(), array_index_values.end());

    std::shared_ptr<HDL_parameter> p;
    if(external_parameters->contains(e.get_string_value())){
        p = external_parameters->get(e.get_string_value());
    }else if(compleated_set->contains(e.get_string_value())){
        p = compleated_set->get(e.get_string_value());
    } else {
        throw Parameter_processor_Exception();
    }
    int64_t  val;
    if(p->get_type() == array_parameter){
        val = p->get_array_value().get_value(array_index_values);
    } else {
        auto mask = 0x1<<array_index_values[2];
        val = (p->get_numeric_value()&mask)>>array_index_values[2];
    }
    return Expression_component(val);
}

std::shared_ptr<HDL_parameter> Parameter_processor::process_array_parameter(const std::shared_ptr<HDL_parameter> &par) {
    std::shared_ptr<HDL_parameter> return_par = par;
    mdarray arr_val;
    if(external_parameters->contains(par->get_name())){
        if(external_parameters->get(par->get_name())->get_type()==array_parameter){
            arr_val = external_parameters->get(par->get_name())->get_array_value();
            return_par->add_initialization_list({});
        } else {
            Initialization_list il = external_parameters->get(par->get_name())->get_i_l();
            il.link_processor( external_parameters, compleated_set, d_store);
            arr_val = il.get_values();
        }

    } else {
        Initialization_list il = return_par->get_i_l();
        il.link_processor( external_parameters, compleated_set, d_store);
        arr_val = il.get_values();
    }

    if(return_par->get_i_l().get_unpacked_dimensions().empty()){
        return_par->set_value(arr_val.get_value({0,0,0}));
    } else {
        return_par->set_array_value(arr_val);
    }
    return_par->clear_expression_components();
    compleated_set->insert(return_par);
    return return_par;
}

std::shared_ptr<HDL_parameter> Parameter_processor::process_packed_parameter(const std::shared_ptr<HDL_parameter> &par) {
    std::shared_ptr<HDL_parameter> return_par = par;
    Initialization_list il;
    if(external_parameters->contains(return_par->get_name())){
        if(external_parameters->get(return_par->get_name())->get_type() == numeric_parameter){
            return_par->set_value(external_parameters->get(return_par->get_name())->get_numeric_value());
            return return_par;
        } else if(external_parameters->get(return_par->get_name())->get_type() == string_parameter){
            return_par->set_value(external_parameters->get(return_par->get_name())->get_string_value());
            return return_par;
        } else{
            il = external_parameters->get(return_par->get_name())->get_i_l();
        }
    } else {
        il = return_par->get_i_l();
    }
    il.link_processor( external_parameters,  compleated_set, d_store);
    auto val_array = il.get_values();
    return_par->set_value(val_array.get_value({0,0,0}));

    return return_par;
}

