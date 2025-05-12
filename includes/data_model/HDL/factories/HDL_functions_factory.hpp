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


#ifndef HDL_FUNCTIONS_FACTORY_HPP
#define HDL_FUNCTIONS_FACTORY_HPP
#include <string>

#include "data_model/HDL/parameters/HDL_function.hpp"

class HDL_functions_factory {
public:
    HDL_functions_factory() = default;
    void set_name(const std::string  &s) {
        f.set_name(s);
    }
    void start_assignment(const std::string &n) {current_assigned_variable = n;}
    void add_component(const Expression_component &c);
    void close_lvalue();
    void close_assignment();
    HDL_function get_function();
private:

    HDL_function f;
    bool ignore_assignment = false;
    Expression new_expression;
    std::string current_assigned_variable;
};



#endif //HDL_FUNCTIONS_FACTORY_HPP
