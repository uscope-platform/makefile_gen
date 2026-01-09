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


#include "analysis/passes/loop_solution_pass.hpp"

void loop_solution_pass::setup(const std::shared_ptr<HDL_instance_AST> &root) {

    std::stack<std::shared_ptr<HDL_instance_AST>> working_stack;
    working_stack.push(root);


    while(!working_stack.empty()) {
        auto current_node = working_stack.top();
        working_stack.pop();
        spdlog::trace("Processing dependency {} in module {}",current_node->get_name(), current_node->get_type());
        process_loops(current_node);
        for(auto item:current_node->get_dependencies()) {
            working_stack.push(item);
        }
    }
}

std::vector<std::shared_ptr<HDL_instance_AST>> loop_solution_pass::process_loops(
    const std::shared_ptr<HDL_instance_AST> &node) {

    if (node->get_n_loops() == 1) {
        auto loop = node->get_inner_loop();
        int i = 0;
    }
    if (node->get_n_loops()>1) {
        spdlog::warn("Nested loops are not supported by parameter analysis\n In HDL instance: " + node->get_name() + " of type: " + node->get_type() + " is in a nested loop");
    }
    return {};
}

