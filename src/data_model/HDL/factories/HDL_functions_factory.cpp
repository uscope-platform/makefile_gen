//  Copyright 2025 Filippo Savi
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

#include "data_model/HDL/factories/HDL_functions_factory.hpp"

void HDL_functions_factory::add_component(const Expression_component &c) {
    new_expression.push_back(c);
}

void HDL_functions_factory::close_lvalue() {
    if(current_assigned_variable == f.name) {
        f.start_assignment(current_assigned_variable, new_expression);
    } else {
        ignore_assignment = true;
    }
        new_expression.clear();
}

void HDL_functions_factory::close_assignment() {
    if(!ignore_assignment)
        f.close_assignment(new_expression);
    ignore_assignment = false;
    new_expression.clear();
}

HDL_function_def HDL_functions_factory::get_function() {
    auto current_function = f;
    f = HDL_function_def();
    new_expression.clear();
    return current_function;
}
