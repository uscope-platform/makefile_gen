//  Copyright 2026 Filippo Savi
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


#ifndef MAKEFILEGEN_V2_EXPRESSIONS_FACTORY_HPP
#define MAKEFILEGEN_V2_EXPRESSIONS_FACTORY_HPP

#include "data_model/HDL/parameters/Expression.hpp"

class expressions_factory {
public:
    void increase_level() {expression_level++;}
    void decrease_level() {expression_level--;}
    void push_level() {levels_stack.push(expression_level); expression_level = 0;}
    void pop_level() {expression_level = levels_stack.top(); levels_stack.pop();}
    void clear_level() {expression_level = 0;}
    void start_expression();
    void stop_expression();
    Expression get_expression();
    [[nodiscard]] bool is_active() const {return active;}
    [[nodiscard]] int get_level() const {return expression_level;}
private:
    bool active = false;
    int expression_level = 0;
    Expression current;
    std::stack<int> levels_stack;
};


#endif //MAKEFILEGEN_V2_EXPRESSIONS_FACTORY_HPP