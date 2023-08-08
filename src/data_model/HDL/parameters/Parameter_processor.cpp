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
    for(auto &item:parent_parameters){
        if(item.second.get_type() != numeric_parameter){
            continue;
        }
        external_parameters[item.first] = item.second.get_numeric_value();
    }
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
            if(!item.second.get_initialization_list().empty()){
                if(!item.second.get_dimensions().empty()){
                    array_dimensions[item.first] = item.second.get_dimensions();
                }
                auto il = item.second.get_initialization_list();
                try{
                    auto dims = item.second.get_dimensions();
                    auto processed_list = process_initialization_list(item.first, il,dims);
                    next_working_set.insert(processed_list.begin(), processed_list.end());
                    list_init_complete = true;
                } catch (Parameter_processor_Exception &ex) {
                    next_working_set.insert(item);
                    list_init_complete = false;
                }

            } else {
                try{
                    auto processed_param = process_parameter(item.second);
                    processed_parameters[item.first] = processed_param;
                    working_param_values[item.first] = processed_param.get_numeric_value();
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


HDL_parameter Parameter_processor::process_parameter(const HDL_parameter &par) {

    HDL_parameter return_par = par;
    auto components = return_par.get_expression_components();


    if(components.empty()){
        throw std::runtime_error("PARAMETER PROCESSING ERROR:\n Empty parameter");
    }

    if(par.get_type() == numeric_parameter){
        return return_par;
    }
    auto value = process_expression(components);
    return_par.set_value(value);
    return_par.set_type(numeric_parameter);
    return return_par;
}

int64_t Parameter_processor::get_flattened_array_index(std::string param_name, std::vector<Expression> idx) {

    std::vector<int64_t> array_index_values;
    for(auto &item:idx){
        auto rpn_expr = expr_vector_to_rpn(item);
        auto res = process_expression(rpn_expr);
        array_index_values.push_back(res);
    }

    auto dims = process_array_dimensions(array_dimensions[param_name]);
    if(dims.empty()){
        throw Parameter_processor_Exception();
    }

    size_t index = 0;
    size_t mul = 1;

    for (size_t i = 0; i < array_index_values.size(); ++i) {
        auto j = array_index_values.size()-i-1;
        index += array_index_values[j] * mul;
        mul *= dims[j];
    }
    return index;

}



int64_t Parameter_processor::process_expression(const std::vector<Expression_component> &expr) {

    std::vector<Expression_component> processed_rpn;

    if(expr.size() == 1){
        auto comp = expr[0];
        return get_component_value(comp);
    }

    for(auto i : expr){
        if(!i.get_array_index().empty()){
            std::vector<int64_t> array_index_values;
            for(auto &item:i.get_array_index()){
                auto rpn_expr = expr_vector_to_rpn(item);
                auto res = process_expression(rpn_expr);
                array_index_values.push_back(res);
            }
            Expression_component ne(i.get_string_value() + "_"+ std::to_string(array_index_values[0]));
            i = ne;

        }

        if(i.get_type() == numeric_component || i.get_type() == operator_component || i.get_type()==function_component){
            processed_rpn.push_back(i);
        } else if(i.get_type() == string_component) {
            if(external_parameters.contains(i.get_string_value())){
                processed_rpn.emplace_back(external_parameters[i.get_raw_string_value()]);
            } else if(working_param_values.contains(i.get_raw_string_value())){
                processed_rpn.emplace_back(working_param_values[i.get_raw_string_value()]);
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
        return (int64_t) ceil(log2(operand));
    } else if(operation ==  "$ceil"){
        return (int64_t) ceil(operand);
    } else if(operation ==  "$floor"){
        return (int64_t) floor(operand);
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


std::unordered_map<std::string, HDL_parameter>
Parameter_processor::process_initialization_list(
        const std::string& param_name,
        std::vector<std::vector<Expression>> &raw_il,
        std::vector<dimension_t> &dims) {

    std::unordered_map<std::string, HDL_parameter> ret;


    if(raw_il.size() == 2 && dims.size() == 2){
        ret = process_complete_2d_init_list(param_name, raw_il, dims);
    } else if(raw_il.size()== 1 && dims.size() == 2) {
        ret = process_simple_2d_init_list(param_name, raw_il, dims);
    } else if(raw_il.size() == 1 && dims.size() == 1){
        ret = process_1d_init_list(param_name, raw_il, dims);
    } else{
        throw std::invalid_argument("Error: Unsupported multidimentional array");
    }
/*
    std::reverse(il.begin(),il.end());



    bool packing_status = dims[0].packed;
    for(int i = 1; i<dims.size();i++){
        if(packing_status != dims[i].packed){
            packing_status = false;
            break;
        }
    }

    if(packing_status){

        int64_t val = 0;
        for(int i = 0; i<il.size(); i++){
            auto init_val = process_expression(il[i]);
            val += (int64_t)std::pow(2, i)*init_val;
        }
        HDL_parameter p;
        p.set_name(param_name);
        p.set_expression_components({Expression_component(std::to_string(val))});
        array_parameter_values[param_name].push_back(val);
        ret[param_name] = p;
    } else {
        int64_t last_list_item = 0;
        for(int i = 0; i<il.size(); i++){
            if(il[i][0].get_string_value() == "$repeat_init"){

            } else{
                if(il[i][0].get_type() == string_component){
                    if(array_parameter_values.contains(il[i][0].get_string_value())){
                        auto array_to_concat = array_parameter_values[il[i][0].get_string_value()];

                        for(int64_t j = last_list_item; j<last_list_item+array_to_concat.size(); j++){
                            HDL_parameter p;
                            auto name = param_name+"_"+std::to_string(j);
                            p.set_name(name);
                            auto val = array_to_concat[j-last_list_item];
                            p.set_expression_components({Expression_component(std::to_string(val))});
                            array_parameter_values[param_name].push_back(val);
                            ret[name] = p;
                        }
                        last_list_item += array_to_concat.size();

                    } else{
                        throw Parameter_processor_Exception();
                    }

                } else {
                    HDL_parameter p;
                    auto name = param_name+"_"+std::to_string(last_list_item);
                    p.set_name(name);
                    p.set_expression_components(il[i]);
                    auto val = process_expression(expr_vector_to_rpn(il[i]));
                    p.set_value(val);
                    array_parameter_values[param_name].push_back(val);
                    ret[name] = p;
                    last_list_item++;
                }


            }
        }
    }

*/
    return ret;
}

std::vector<int64_t> Parameter_processor::process_array_dimensions(std::vector<dimension_t> dims) {
    std::vector<int64_t> ret;
    for(auto &item:dims){
        auto first_val = process_expression(expr_vector_to_rpn(item.first_bound));
        auto second_val = process_expression(expr_vector_to_rpn(item.second_bound));
        ret.push_back(std::max(first_val, second_val)+1);
    }
    return ret;
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
            param_name = ec.get_string_value();
            std::vector<int64_t> array_index_values;
            for(auto &item:ec.get_array_index()){
                auto rpn_expr = expr_vector_to_rpn(item);
                auto res = process_expression(rpn_expr);
                param_name += "_"+ std::to_string(res);
            }
    } else{
        param_name = ec.get_string_value();
    }


    int64_t val;
    if(external_parameters.contains(param_name)){
        val = external_parameters[param_name];
    } else if(working_param_values.contains(param_name)){
        val = working_param_values[param_name];
    } else {
        throw Parameter_processor_Exception();
    }

    return val;
}

std::unordered_map<std::string, HDL_parameter>
Parameter_processor::process_complete_2d_init_list(const std::string &param_name,
                                                   std::vector<std::vector<Expression>> &il,
                                                   std::vector<dimension_t> &dims) {
    std::vector<std::vector<int64_t>> raw_values;

    std::unordered_map<std::string, HDL_parameter> ret_val;

    for(int i = 0; i<il.size(); i++){
        raw_values.push_back({});
        for(auto item:il[i]){
            if(item[0].get_string_value()=="$repeat_init"){

                Expression init_size_expr, init_val_expr;
                bool size_sect = true;
                for(int j = 1; j<item.size(); j++){
                    if(item[j].get_string_value() == ","){
                        size_sect = false;
                    } else if(size_sect){
                        init_size_expr.push_back(item[j]);
                    } else {
                        init_val_expr.push_back(item[j]);
                    }
                }
                auto init_size = process_expression(expr_vector_to_rpn(init_size_expr));
                auto init_val = process_expression(expr_vector_to_rpn(init_val_expr));

                for(int64_t j = 0; j<init_size; j++){
                    raw_values[i].push_back(init_val);
                }
            } else{
                raw_values[i].push_back(process_expression(item));
            }
        }

    }

    if(dims[0].packed){
        std::vector<int64_t> values;
        for(int j = 0; j<raw_values.size(); j++){
            int64_t val = 0;
            auto packed_values = raw_values[j];
            std::reverse(packed_values.begin(), packed_values.end());
            for(int i = 0; i<packed_values.size(); i++){
                val += (int64_t)std::pow(2, i)*packed_values[i];
            }
            values.push_back(val);
        }
        for(int i = 0; i< values.size(); i++){
            HDL_parameter p;
            p.set_name(param_name + "_" + std::to_string(i));
            p.set_expression_components({Expression_component(std::to_string(values[values.size()-1-i]))});
            array_parameter_values[param_name].push_back(values[values.size()-1-i]);
            ret_val[param_name + "_" + std::to_string(i)] = p;
        }

    } else{
        std::vector<std::vector<uint64_t>> raw_values;

        auto outer_dim = get_dimension_size(dims[1]);
        auto inner_dim = get_dimension_size(dims[0]);

        for(int i = 0; i<outer_dim; i++){
            raw_values.push_back({});
            for(int j = 0; j<inner_dim; j++){
                if(il[i][j][0].get_string_value() == "$repeat_init"){
                    int i = 0;
                }
                raw_values[i].push_back(process_expression(il[i][j]));
            }
        }
        for(int i = 0; i<outer_dim; i++){
            for(int j = 0; j<inner_dim; j++){
                HDL_parameter p;
                auto name = param_name+"_"+std::to_string(i) + "_" +std::to_string(j);
                p.set_name(name);
                p.set_expression_components(il[outer_dim-1-i][inner_dim-1-j]);
                p.set_value(raw_values[outer_dim-1-i][inner_dim-1-j]);
                array_parameter_values[param_name].push_back(raw_values[outer_dim-1-i][inner_dim-1-j]);
                ret_val[name] = p;
            }
        }
    }

    return ret_val;
}

std::unordered_map<std::string, HDL_parameter>
Parameter_processor::process_simple_2d_init_list(const std::string &param_name,
                                                 std::vector<std::vector<Expression>> &il,
                                                 std::vector<dimension_t> &dims) {
    throw std::invalid_argument("SIMPLE 2D LIST NOT IMPLEMENTED YET");
}

std::unordered_map<std::string, HDL_parameter>
Parameter_processor::process_1d_init_list(const std::string &param_name, std::vector<std::vector<Expression>> &il,
                                          std::vector<dimension_t> &dims) {

    std::unordered_map<std::string, HDL_parameter> ret_val;
    if(dims[0].packed){
        int64_t val = 0;
        auto packed_values = il[0];
        std::reverse(packed_values.begin(), packed_values.end());
        for(int i = 0; i<packed_values.size(); i++){
            val += (int64_t)std::pow(2, i)* process_expression(expr_vector_to_rpn(packed_values[i]));
        }
        HDL_parameter p;
        p.set_name(param_name);
        p.set_expression_components({Expression_component(std::to_string(val))});
        p.set_value(val);
        array_parameter_values[param_name].push_back(val);
        ret_val[param_name] = p;
    } else {

        auto reverse_il = il[0];
        std::reverse(reverse_il.begin(), reverse_il.end());

        auto arr_size = get_dimension_size(dims[0]);

        int last_item_addr = 0;
        for(int i = 0; ret_val.size()<arr_size; i++){

            if(reverse_il[i][0].get_string_value() == "$repeat_init"){
                auto expanded_list = process_repeat_initialization(param_name, reverse_il[i], last_item_addr);
                for(auto item:expanded_list){
                    ret_val[item.get_name()] = item;
                    array_parameter_values[param_name].push_back(item.get_numeric_value());
                }
                last_item_addr += expanded_list.size();
            } else{
                if(reverse_il[i][0].get_type() == string_component){
                    if(array_parameter_values.contains(reverse_il[i][0].get_string_value())){
                        auto array_to_concat = array_parameter_values[reverse_il[i][0].get_string_value()];

                        for(int64_t j = last_item_addr; j<last_item_addr+array_to_concat.size(); j++){
                            HDL_parameter p;
                            auto name = param_name+"_"+std::to_string(j);
                            p.set_name(name);
                            auto val = array_to_concat[j-last_item_addr];
                            p.set_expression_components({Expression_component(std::to_string(val))});
                            array_parameter_values[param_name].push_back(val);
                            ret_val[name] = p;
                        }
                        last_item_addr += array_to_concat.size();
                    } else{
                        throw Parameter_processor_Exception();
                    }

                } else{
                    HDL_parameter p;
                    auto name = param_name+"_"+std::to_string(last_item_addr);
                    p.set_name(name);
                    p.set_expression_components(reverse_il[i]);
                    auto val = process_expression(expr_vector_to_rpn(reverse_il[i]));
                    p.set_value(val);
                    array_parameter_values[param_name].push_back(val);
                    ret_val[name] = p;
                    last_item_addr++;
                }
            }


        }
        int i = 0;
    }


    return ret_val;
}

uint64_t Parameter_processor::get_dimension_size(dimension_t &d) {
    return std::max(process_expression(expr_vector_to_rpn(d.first_bound)), process_expression(expr_vector_to_rpn(d.second_bound)))+1;
}

std::vector<HDL_parameter> Parameter_processor::process_repeat_initialization(const std::string &param_name, Expression &e, uint64_t last_item_addr) {
    std::vector<HDL_parameter> ret;
    Expression init_size_expr, init_val_expr;
    bool size_sect = true;
    for(int j = 1; j<e.size(); j++){
        if(e[j].get_string_value() == ","){
            size_sect = false;
        } else if(size_sect){
            init_size_expr.push_back(e[j]);
        } else {
            init_val_expr.push_back(e[j]);
        }
    }
    auto init_size = process_expression(expr_vector_to_rpn(init_size_expr));
    auto init_val = process_expression(expr_vector_to_rpn(init_val_expr));

    for(int64_t j = last_item_addr; j<last_item_addr+init_size; j++){
        HDL_parameter p;
        auto name = param_name+"_"+std::to_string(last_item_addr+j);
        p.set_name(name);
        p.set_expression_components({Expression_component(std::to_string(init_val))});
        p.set_value(init_val);
        ret.push_back(p);
    }
    return ret;
}
