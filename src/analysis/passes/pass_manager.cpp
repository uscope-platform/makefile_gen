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


#include "analysis/passes/pass_manager.hpp"

pass_manager::pass_manager() {
    passes = {
        std::make_shared<parameter_solution_pass>()
    };
}

std::shared_ptr<HDL_instance_AST> pass_manager::apply_passes(const std::shared_ptr<HDL_instance_AST> &c) {
    std::shared_ptr<HDL_instance_AST> working_tree = c;
    for (const auto &pass: passes) {
        working_tree = apply_pass(working_tree, pass);
    }
}

std::shared_ptr<HDL_instance_AST> pass_manager::apply_pass(const std::shared_ptr<HDL_instance_AST> &c, const std::shared_ptr<pass_base> &pass) {

    std::stack<std::shared_ptr<HDL_instance_AST>> working_set;
    working_set.push(c);
    while (!working_set.empty()) {
        auto working_item = working_set.top();
        working_set.pop();
        pass->process_node(working_item);
        for (const auto &dep: working_item->get_dependencies()) {
            working_set.push(dep);
        }
    }
}
