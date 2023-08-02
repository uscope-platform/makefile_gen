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

#include "data_model/expressions/bus_mapping_expression.hpp"


bus_mapping_expression::bus_mapping_expression(std::string n, uint32_t a) {
    name = std::move(n);
}

bus_mapping_expression::bus_mapping_expression(const bus_mapping_expression &e) {
    name = e.name;
    expression_components = e.expression_components;
}

bus_mapping_expression::bus_mapping_expression(std::string n, std::vector<std::string> e) {
    name = std::move(n);
    expression_components = std::move(e);
}

void bus_mapping_expression::update_expression(const std::string& n, uint32_t value) {
    for (auto & expression_component : expression_components) {
        if(expression_component == n){
            expression_component = std::to_string(value);
        }
    }
}

bool operator==(const bus_mapping_expression &lhs, const bus_mapping_expression &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.expression_components == rhs.expression_components;
    return ret;
}

bus_mapping_expression::bus_mapping_expression(std::string text) {
    name = "exp";
    std::vector<std::string> tokens;
    std::string purged_text = std::regex_replace (text,std::regex("\\s+"),"sub-$2");
    std::regex re(R"(([a-z0-9A-Z$_]+)(\+|\-|\*|\/)([a-z0-9A-Z$_]+))");
    std::smatch sm;
    if(std::regex_match(purged_text, sm, re)){
        expression_components.push_back(sm[1]);
        expression_components.push_back(sm[2]);
        expression_components.push_back(sm[3]);
    } else{
        expression_components.push_back(text);
    }

}

