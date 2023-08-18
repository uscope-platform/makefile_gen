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

#include "data_model/expressions/expression_evaluator.hpp"



uint32_t expression_evaluator::calculate_expression(std::vector<std::string> exp) {
    for (int i = 0; i< exp.size(); i++) {
        if(exp[i] == "*"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a*op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
            --i;
        } else if(exp[i] == "/"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a/op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
        } else if(exp[i]=="%"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a%op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
        }
    }


    for (int i = 0; i< exp.size(); i++) {
        if(exp[i] == "+"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a+op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
            --i;
        } else if(exp[i] == "-"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a-op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
        }
    }
    return std::stoul(exp[0]);
}

std::vector<std::string> expression_evaluator::get_variable_names(bus_mapping_expression exp) {
    std::vector<std::string> ret_val;
    for(auto &item:exp.get_expression()){
        std::set<std::string> operators = {"+", "*", "-", "/", "%"};
        if(operators.contains(item))
            continue;
        try{
            std::stoul(item);
        }catch(std::exception& e){
            ret_val.push_back(item);
        }
    }
    return ret_val;
}

uint32_t
expression_evaluator::calculate_expression(bus_mapping_expression exp, std::unordered_map<std::string, uint32_t> params) {

    for(auto &np:params){
        exp.update_expression(np.first, np.second);
    }

    return expression_evaluator::calculate_expression(exp.get_expression());

}

uint32_t expression_evaluator::calculate_expression(const bus_mapping_expression& exp, HDL_Resource &res, HDL_instance &dep,
                                                    address_resolver &resolver) {

    std::unordered_map<std::string, uint32_t> params;
    for(auto &val: expression_evaluator::get_variable_names(exp)){
        params[val] = resolver.get_address(val, res, dep, 0);
    }
    return expression_evaluator::calculate_expression(exp, params);
}
