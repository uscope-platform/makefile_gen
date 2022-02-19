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

#include "data_model/parameter.h"

#include <utility>

parameter::parameter(std::string n, uint32_t a) {
    name = std::move(n);
    address = a;
    determined = true;
}

parameter::parameter(std::string n, std::vector<std::string> e) {
    name = std::move(n);
    address = 0;
    determined = false;
    expression_components = std::move(e);
}


void parameter::set_address(uint32_t a) {
    address = a;
    determined = true;
}

void parameter::update_expression(const std::string& n, uint32_t value) {
    for (auto & expression_component : expression_components) {
        if(expression_component == n){
            expression_component = std::to_string(value);
        }
    }
}
