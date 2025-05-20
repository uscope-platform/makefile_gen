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

#include "analysis/HDL_loop_solver.hpp"


Parameter_processor::Parameter_processor(const Parameters_map &parent_parameters, const std::shared_ptr<data_store> &ds) {
    d_store = ds;
    external_parameters = std::make_shared<Parameters_map>(parent_parameters);
    completed_set = std::make_shared<Parameters_map>();
}

Parameter_processor::Parameter_processor(const Parameters_map &ep,
                                         std::shared_ptr<Parameters_map> &cs) {
    d_store = {};
    external_parameters = std::make_shared<Parameters_map>(ep);
    completed_set = cs;
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
                std::cout << "Processing parameter: " << dbg << std::endl;
                if(external_parameters->contains(item->get_name())){
                    // The parameter needs to be copied out of external parameters and into the completed set otherwise it will go out of scope
                    auto param = external_parameters->get(item->get_name());
                    completed_set->insert(param);
                } else {
                    completed_set->insert(process_parameter(par, spec));
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
                completed_set->insert(item.second);
                next_working_set.erase(item.second->get_name());
            }
        }
        working_set = next_working_set;
        string_set.clear();
        next_working_set.clear();
        override_cnt--;
    }

    for(auto &item:working_set){
        completed_set->insert(item);
    }

    return *completed_set;
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
            p = process_vector_function_parameter(par, function, spec);
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
    const std::shared_ptr<HDL_parameter> &par, const HDL_function &fcn, HDL_Resource &spec) {

    std::shared_ptr<HDL_parameter> return_par = par;
    std::unordered_map<uint64_t, uint64_t> explicit_values;
    try {
        for(auto &item:fcn.get_assignments()) {
            auto index = process_expression(item.index, nullptr);
            auto value = process_expression(item.value, nullptr);
            explicit_values.insert({index, value});
        }
    } catch(Parameter_processor_Exception ex) {
        int i = 0;
    }

    auto loop = fcn.get_loop();
    auto loop_values = evaluate_loop(loop, spec);


    return_par->set_array_value(merge_function_contributions(explicit_values, loop_values));
    return return_par;
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
            rpn_vect = Expression_evaluator::expr_vector_to_rpn(expr);
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
            } else if(completed_set->contains(i.get_raw_string_value())) {
                processed_rpn.emplace_back(completed_set->get(i.get_raw_string_value())->get_numeric_value());
            } else if(!i.get_package_prefix().empty()){
                int64_t val = get_package_parameter(i, nullptr);
                processed_rpn.emplace_back(val);
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
                result = Expression_evaluator::evaluate_unary_expression(op, i.get_string_value());
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

                result = Expression_evaluator::evaluate_binary_expression(op_a, op_b, i.get_raw_string_value());
            }
            evaluator_stack.emplace(result);
        }
    }
    if(result_size != nullptr){

        *result_size = Expression_component::calculate_binary_size(evaluator_stack.top().get_numeric_value());
    }
    return evaluator_stack.top().get_numeric_value();
}

int64_t Parameter_processor::get_package_parameter(const Expression_component &ex, int64_t *result_size) {
    int64_t return_val;
    auto pkg = ex.get_package_prefix();
    if(d_store->contains_hdl_entity(pkg)) {
        auto res = d_store->get_HDL_resource(pkg);
        Parameter_processor p({}, d_store);
        auto pkg_params = p.process_parameters_map(res.get_parameters(),res);
        return_val = pkg_params.get(ex.get_string_value())->get_numeric_value();
        if(result_size != nullptr){
            *result_size = Expression_component::calculate_binary_size(return_val);
        }
    } else {
        throw std::runtime_error("Error: The package " + pkg + " was not found");
    }
    return return_val;
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
        return get_package_parameter(ec, nullptr);
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
    } else if(completed_set->contains(param_name)) {
        if (completed_set->get(param_name)->is_array()) {
            throw array_value_exception(completed_set->get(param_name)->get_array_value());
        } else {
            val = completed_set->get(param_name)->get_numeric_value();
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

std::unordered_map<uint64_t, uint64_t> Parameter_processor::evaluate_loop(HDL_loop_metadata &loop, HDL_Resource &spec) {
    std::unordered_map<uint64_t, uint64_t> retval;

    if(loop.init.get_name().empty() && loop.init.get_type() == string_parameter) return retval;
    auto loop_variable = process_parameter(std::make_shared<HDL_parameter>(loop.init), spec);

    while(evaluate_loop_expression(loop.end_c,loop_variable) != 0){
        for(auto a:loop.assignments) {
            auto idx = evaluate_loop_expression(a.index, loop_variable);
            auto value = evaluate_loop_expression(a.value, loop_variable);
            retval.insert({idx, value});
        }

        auto new_loop_var = evaluate_loop_expression(loop.iter, loop_variable);
        loop_variable->set_value(new_loop_var);
    }

    return retval;

}


int64_t Parameter_processor::evaluate_loop_expression(Expression &e, std::shared_ptr<HDL_parameter> loop_var) {

    std::shared_ptr<HDL_parameter> shadowed_var= nullptr;
    if(external_parameters->contains(loop_var->get_name())) {
        shadowed_var = external_parameters->get(loop_var->get_name());
        external_parameters->erase(loop_var->get_name());
    }
    external_parameters->insert(loop_var);
    auto val = process_expression(e, nullptr);
    external_parameters->erase(loop_var->get_name());
    if(shadowed_var != nullptr) {
        external_parameters->insert(shadowed_var);
    }
    return val;
}

mdarray Parameter_processor::merge_function_contributions(std::unordered_map<uint64_t, uint64_t> &explicit_values,
    std::unordered_map<uint64_t, uint64_t> &loop_values) {
    auto output_size = explicit_values.size() + loop_values.size();
    md_1d_array parameter_value(output_size);

    for(auto &[idx, value]:explicit_values) {
        parameter_value[idx] = value;
    }
    for(auto &[idx, value]:loop_values) {
        if(explicit_values.contains(idx)) {
            throw std::runtime_error("ERROR: addressing conflicts in parameter initializing function are not supported");
        }
        parameter_value[idx] = value;
    }
    mdarray md_values;
    md_values.set_1d_slice({0, 0}, parameter_value);
    return md_values;
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
    }else if(completed_set->contains(e.get_string_value())){
        p = completed_set->get(e.get_string_value());
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
            il.link_processor( external_parameters, completed_set, d_store);
            arr_val = il.get_values();
        }

    } else {
        Initialization_list il = return_par->get_i_l();
        il.link_processor( external_parameters, completed_set, d_store);
        arr_val = il.get_values();
    }

    if(return_par->get_i_l().get_unpacked_dimensions().empty()){
        return_par->set_value(arr_val.get_value({0,0,0}));
    } else {
        return_par->set_array_value(arr_val);
    }
    return_par->clear_expression_components();
    completed_set->insert(return_par);
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
    il.link_processor( external_parameters,  completed_set, d_store);
    auto val_array = il.get_values();
    return_par->set_value(val_array.get_value({0,0,0}));

    return return_par;
}

