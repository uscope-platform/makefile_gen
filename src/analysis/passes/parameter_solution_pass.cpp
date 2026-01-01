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

std::map<std::string, resolved_parameter>   parameter_solution_pass::process_parameters(const Parameters_map &map_in) {
    auto map = Parameters_map::deep_copy(map_in);

    std::map<std::string, resolved_parameter> solved_parameters;
    std::map<std::string, std::set<std::string>> dependencies_map;
    for (auto &param: map) {
        auto param_name = param->get_name();
        dependencies_map[param_name] = {};
        auto param_deps = param->get_dependencies();
        for (auto dep:param_deps) {
            if (!map.contains(dep) && !param->is_array()) {
                solved_parameters.insert({param_name, dep});
            } else {
                dependencies_map[param_name].insert(dep);
            }
        }
    }


        int rounds_counter = 0;
        while (!dependencies_map.empty() && rounds_counter < 100) {
            for (auto &[param_name, dependencies] : dependencies_map ) {
                if (dependencies.empty() && !solved_parameters.contains(param_name)) {
                    auto to_solve = map.const_get(param_name);

                    auto value = to_solve->get_i_l().evaluate();

                    if (value.has_value()) {
                        solved_parameters.insert({param_name, value.value()});
                    }

                }
            }

            for (auto &param: solved_parameters) {
                bool propagation_complete = true;
                for (auto &dep: dependencies_map) {
                    if (dep.second.contains(param.first)) {
                        propagation_complete &= map.get(dep.first)->propagate_constant(param.first, param.second);
                        if (propagation_complete) dep.second.erase(param.first);
                    }
                }
                    dependencies_map.erase(param.first);
            }
            rounds_counter++;
        }

        if (rounds_counter >=100) {
            spdlog::warn("Some parameters could not be solved in 100 passes");
        }



    return solved_parameters;
}
