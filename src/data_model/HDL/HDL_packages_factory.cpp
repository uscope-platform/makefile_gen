// Copyright 2021 Filippo Savi
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "data_model/HDL/HDL_packages_factory.hpp"


void HDL_packages_factory::new_package(std::string &p) {
    resources_factory_base<HDL_Resource>::new_resource(p);
    current_resource.set_type(package);
}

HDL_Resource HDL_packages_factory::get_package() {
    calculate_unresolved_parameters();
    current_resource.set_parameters(numeric_parameters);
    return resources_factory_base<HDL_Resource>::get_resource();
}

void HDL_packages_factory::add_numeric_parameter(const std::string &name, uint32_t val) {
    numeric_parameters[name] = val;
}

void HDL_packages_factory::calculate_unresolved_parameters() {
    std::vector<expression> remaining_parameters;

    while(!unresolved_parameters.empty()){
        remaining_parameters.clear();
        //update parameters with calculated values
        for(auto &np:numeric_parameters){
            for(auto &item:unresolved_parameters){
                item.update_expression(np.first, np.second);
            }
        }

        // Calculate available expressions
        for(auto &item:unresolved_parameters){
            try{
                std::string param_name = item.get_name();
                uint32_t res = calculate_expression(item.get_expression());
                numeric_parameters[param_name] = res;
            } catch(std::invalid_argument &ex){
                remaining_parameters.push_back(item);
            }
        }

        unresolved_parameters = remaining_parameters;
    }
}
uint32_t HDL_packages_factory::calculate_expression(std::vector<std::string> exp) {
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

void HDL_packages_factory::add_string_parameter(const std::string &s) {

}

