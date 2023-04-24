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

#include "data_model/expressions/expression.hpp"


expression::expression(std::string n, uint32_t a) {
    name = std::move(n);
}

expression::expression(const expression &e) {
    name = e.name;
    expression_components = e.expression_components;
}

expression::expression(std::string n, std::vector<std::string> e) {
    name = std::move(n);
    expression_components = std::move(e);
}

void expression::update_expression(const std::string& n, uint32_t value) {
    for (auto & expression_component : expression_components) {
        if(expression_component == n){
            expression_component = std::to_string(value);
        }
    }
}

bool operator==(const expression &lhs, const expression &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.expression_components == rhs.expression_components;
    return ret;
}

