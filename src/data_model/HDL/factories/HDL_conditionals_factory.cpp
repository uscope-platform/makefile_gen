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

#include "data_model/HDL/factories/HDL_conditionals_factory.hpp"


void HDL_conditionals_factory::new_conditional() {
    _statement = hdl_conditional_statement();
    _if_stack = std::stack<if_frame>();
    _if_stack.push({0, false});
    _body_item_depth = 0;
    _nesting = 1;
    active = true;
    in_else = false;
}

void HDL_conditionals_factory::add_branch() {
    _statement.add_branch(nullptr);
    _if_stack.push({_body_item_depth, false});
    _nesting++;
    in_else = false;
}

void HDL_conditionals_factory::set_condition(const std::shared_ptr<Expression_base> &cond) {
    _statement.set_condition(cond);
}

void HDL_conditionals_factory::enter_body_item() {
    if (!_if_stack.empty() && _body_item_depth == _if_stack.top().base_depth) {
        if (!_if_stack.top().then_done) {
            in_else = false;
            _if_stack.top().then_done = true;
        } else {
            in_else = true;
        }
    }
    _body_item_depth++;
}

void HDL_conditionals_factory::exit_body_item() {
    if (_body_item_depth > 0)
        _body_item_depth--;
}

void HDL_conditionals_factory::add_statement(const std::shared_ptr<hdl_statement_base> &stmt) {
    if (in_else)
        _statement.add_to_else(stmt);
    else
        _statement.add_to_branch(stmt);
}

hdl_conditional_statement HDL_conditionals_factory::get_conditional() {
    _nesting--;
    if (_nesting > 0) {
        _if_stack.pop();
        return {};
    }
    auto ret = _statement;
    ret.flatten();
    _statement = hdl_conditional_statement();
    active = false;
    in_else = false;
    _body_item_depth = 0;
    return ret;
}
