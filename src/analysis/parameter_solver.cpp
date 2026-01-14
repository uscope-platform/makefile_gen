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

#include "../../includes/analysis/parameter_solver.hpp"

std::map<std::string, resolved_parameter>   parameter_solver::process_parameters(const Parameters_map &map_in, std::unordered_map<std::string, HDL_function> function_defs) {
    auto map = map_in.clone();

    std::map<std::string, resolved_parameter> solved_parameters;
    auto dependencies_map = get_dependency_map(map_in, function_defs);


        int rounds_counter = 0;
        while (!dependencies_map.empty() && rounds_counter < 100) {
            for (auto &[param_name, dependencies] : dependencies_map ) {
                if (dependencies.empty() && !solved_parameters.contains(param_name)) {
                    auto to_solve = map.const_get(param_name);
                    std::optional<resolved_parameter> value;
                    if(to_solve->is_function()) {
                        auto fcn_name = std::get<std::string>(to_solve->get_i_l().evaluate().value());
                        auto fcn = function_defs[fcn_name];
                        value = fcn.evaluate(false);
                    } else {
                        value = to_solve->get_i_l().evaluate();
                    }

                    if (value.has_value()) {
                        solved_parameters.insert({param_name, value.value()});
                    }

                }
            }

            for (auto &[param_name, param_value]: solved_parameters) {
                bool propagation_complete = true;
                for (auto &dep: dependencies_map) {
                    if (dep.second.contains({"", param_name})) {
                        auto target = map.get(dep.first);
                        if(target->is_function()) {
                            auto fcn_name = std::get<std::string>(target->get_i_l().evaluate().value());
                            propagation_complete &= function_defs[fcn_name].propagate_constant(param_name, param_value);
                            if (propagation_complete) dep.second.erase({"", param_name});
                        } else {
                            propagation_complete &= target->propagate_constant(param_name, param_value);
                            if (propagation_complete) dep.second.erase({"", param_name});
                        }

                    }
                }
                    dependencies_map.erase(param_name);
            }
            rounds_counter++;
        }

        if (rounds_counter >=100) {
            spdlog::warn("Some parameters could not be solved in 100 passes");
        }

    return solved_parameters;
}


void parameter_solver::update_parameters_map(
    std::map<std::string, resolved_parameter> solved_parameters,
    std::shared_ptr<HDL_instance_AST> node,
    const std::shared_ptr<data_store> &d_store
) {
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

std::map<std::string, resolved_parameter> parameter_solver::override_parameters(work_order &work, const std::shared_ptr<data_store> &d_store) {
    auto node_spec = d_store->get_HDL_resource(work.node->get_type());
    auto node_defaults = node_spec.get_default_parameters();
    auto node_overrides = work.node->get_parameters();
    auto node_parameters = node_spec.get_parameters();

    std::map<std::string, resolved_parameter> solved_parameters;
    // Override default parameters if necessary

    std::map<qualified_identifier, resolved_parameter> package_parameters;
    auto deps_map = get_dependency_map(node_parameters, {});
    for (auto &[param_name, param_deps]:deps_map) {
        for (const auto& identifier:param_deps) {
            if (!identifier.prefix.empty()) {
                auto package = d_store->get_HDL_resource(identifier.prefix);
                auto param_value = package.get_default_parameters()[identifier.name];
                package_parameters[identifier] = param_value;
            }
        }
    }
    deps_map = get_dependency_map(node_overrides, {});
    if(node_overrides.empty()) {
        solved_parameters = node_defaults;
    } else{
        Parameters_map to_solve;
        for(const auto& override:node_overrides) {
            for(const auto &param: node_parameters) {
                auto deps = param->get_dependencies();
                if(deps.contains({"", override->get_name()}) && !node_overrides.contains(param->get_name())) {
                    to_solve.insert(param);
                }
            }
        }

        int solution_rounds = 0;
        std::unordered_map<std::string, uint32_t> parameters_progress;
        std::set<std::string> completed_parameters;
        while(completed_parameters.size() != node_overrides.size()) {
            if(solution_rounds > 100) throw std::runtime_error("Exceded maximum number of iterations when solving a parameter override");
            for(auto &param:node_overrides) {
                if(completed_parameters.contains(param->get_name())) continue;
                auto deps = param->get_dependencies();
                if(deps.empty()) {
                    if(!to_solve.contains(param->get_name())) {
                        completed_parameters.insert(param->get_name());
                        to_solve.insert(param);
                    }
                }
                for(auto &dep:deps) {
                    if(work.parent_parameters.contains(dep.name)) {
                        if(param->propagate_constant(dep.name, work.parent_parameters[dep.name])) {
                            parameters_progress[param->get_name()]++;
                            if(parameters_progress[param->get_name()]== deps_map[param->get_name()].size()) {
                                to_solve.insert(param);
                                completed_parameters.insert(param->get_name());
                            }
                        }
                    } else {
                        throw std::runtime_error("Parameter " + dep.prefix +"::" +dep.name + " is not defined in the design");
                    }
                }
            }
            ++solution_rounds;
        }

        solved_parameters = process_parameters(to_solve,{});
        for(auto &param:solved_parameters) {
            node_defaults[param.first] = param.second;
        }
    }

    for (auto param:solved_parameters) {
        int i = 0;
    }


    update_parameters_map(solved_parameters, work.node, d_store);
    return node_defaults;
}

std::map<std::string, std::set<qualified_identifier>> parameter_solver::get_dependency_map(const Parameters_map &map,
    std::unordered_map<std::string, HDL_function> function_defs) {

    std::map<std::string, std::set<qualified_identifier>> dependencies_map;
    for (auto &param: map) {
        auto param_name = param->get_name();
        dependencies_map[param_name] = {};
        std::set<std::string> param_deps;
        if(param->is_function()) {
            auto fcn_name = std::get<std::string>(param->get_i_l().evaluate().value());
            auto fcn = function_defs[fcn_name];
            auto deps = fcn.get_dependencies();
            dependencies_map[param_name].insert(deps.begin(), deps.end());
        } else {
            auto deps = param->get_dependencies();
            dependencies_map[param_name].insert(deps.begin(), deps.end());
        }
    }
    return dependencies_map;
}
