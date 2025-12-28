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

#include "analysis/passes/parameter_solution_pass.hpp"

parameter_solution_pass::parameter_solution_pass() {
    parameters_map = {};
}

void parameter_solution_pass::setup(const std::shared_ptr<HDL_instance_AST> &root) {
    int i = 0;
}

void parameter_solution_pass::process_node(const std::shared_ptr<HDL_instance_AST> &node) {
    int i = 0;
}

Parameters_map parameter_solution_pass::process_parameters(const Parameters_map &map) {
    Parameters_map solved_parameters;
    std::map<std::string, std::vector<std::string>> dependencies_map;
    for (auto &param: map) {
        auto param_name = param->get_name();
        dependencies_map[param_name] = {};
        for (auto &comp:param->get_expression_components().components) {
            auto type = comp.get_type();
            if (type == string_component) {
                dependencies_map[param_name].push_back(comp.get_string_value());
            }
        }
    }
    for (auto &[param, dependencies] : dependencies_map ) {
        if (dependencies_map.empty()) {

        }
    }
    return solved_parameters;
}
