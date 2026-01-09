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

parameter_solution_pass::parameter_solution_pass(const std::shared_ptr<data_store> &d) {
    d_store = d;
}

void parameter_solution_pass::setup(const std::shared_ptr<HDL_instance_AST> &root) {
    auto root_res = d_store->get_HDL_resource(root->get_type());

    std::stack<work_order> working_stack;
    working_stack.push({
        root,
        {},
        root->get_name()
    });


    while(!working_stack.empty()) {
        auto current_node = working_stack.top();
        working_stack.pop();
        spdlog::trace("Processing dependency {} in module {}",current_node.path, current_node.node->get_type());


        auto current_param_values = override_parameters(current_node);

        auto current_res = d_store->get_HDL_resource(current_node.node->get_type());
        for(auto item:current_node.node->get_dependencies()) {
            working_stack.push({
                item,
                current_param_values,
                current_node.path + "." + item->get_name()
            });
        }
    }
}


std::map<std::string, resolved_parameter>   parameter_solution_pass::process_parameters(const Parameters_map &map_in) {
    auto map = map_in.clone();

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

void parameter_solution_pass::update_parameters_map(std::map<std::string, resolved_parameter> solved_parameters, std::shared_ptr<HDL_instance_AST> node) {
    auto node_parameters = node->get_parameters();
    auto resource = d_store->get_HDL_resource(node->get_type());

    for(auto &param:resource.get_parameters()) {
        std::shared_ptr<HDL_parameter> ast_param;
        if(node_parameters.contains(param->get_name()))
            ast_param = node_parameters.get(param->get_name());
        else
            ast_param = std::make_shared<HDL_parameter>(*param);
        resolved_parameter param_val;
        if(solved_parameters.contains(param->get_name())) {
            param_val = solved_parameters[param->get_name()];
        } else {
            param_val = resource.get_default_parameters()[param->get_name()];
        }
        if(std::holds_alternative<int64_t>(param_val)) ast_param->set_value(std::get<int64_t>(param_val));
        else if(std::holds_alternative<std::string>(param_val)) ast_param->set_value(std::get<std::string>(param_val));
        else if(std::holds_alternative<mdarray<int64_t>>(param_val)) ast_param->set_array_value(std::get<mdarray<int64_t>>(param_val));
        if(!node_parameters.contains(param->get_name())) node_parameters.insert(ast_param);
    }

    node->set_parameters(node_parameters);
}

std::map<std::string, resolved_parameter> parameter_solution_pass::override_parameters(work_order &work) {
    auto node_spec = d_store->get_HDL_resource(work.node->get_type());
    auto node_defaults = node_spec.get_default_parameters();
    auto node_overrides = work.node->get_parameters();
    auto node_parameters = node_spec.get_parameters();

    std::map<std::string, resolved_parameter> solved_parameters;

    if(node_overrides.empty()) {
        solved_parameters = node_defaults;
    } else{

        Parameters_map to_solve;
        for(const auto override:node_overrides) {
            for(const auto &param: node_parameters) {
                if(param->get_dependencies().contains(override->get_name())) {
                    to_solve.insert(param);
                }
            }
        }

        for(auto &param:node_overrides) {
            auto deps = param->get_dependencies();
            for(auto &dep:deps) {
                if(work.parent_parameters.contains(dep)) {\
                    param->propagate_constant(dep, work.parent_parameters[dep]);
                    to_solve.insert(param);
                } else {
                    throw std::runtime_error("Parameter " + dep + " is not defined in the design");
                }
            }
            to_solve.insert(param);
        }
        solved_parameters = process_parameters(to_solve);
        for(auto &param:solved_parameters) {
            node_defaults[param.first] = param.second;
        }
    }

    update_parameters_map(solved_parameters, work.node);
    return node_defaults;
}
