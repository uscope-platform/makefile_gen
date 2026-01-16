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

#include "analysis/parameter_solver.hpp"

std::map<qualified_identifier, resolved_parameter>   parameter_solver::process_parameters(const Parameters_map &map_in, std::unordered_map<std::string, HDL_function> function_defs) {
    auto map = map_in.clone();

    std::map<qualified_identifier, resolved_parameter> solved_parameters;
    auto dependencies_map = get_dependency_map(map_in, function_defs);


        int rounds_counter = 0;
        while (!dependencies_map.empty() && rounds_counter < 100) {
            for (auto &[param_id, dependencies] : dependencies_map ) {
                if (dependencies.empty() && !solved_parameters.contains(param_id)) {
                    auto to_solve = map.const_get(param_id.name);
                    std::optional<resolved_parameter> value;
                    if(to_solve->is_function()) {
                        auto fcn_name = std::get<std::string>(to_solve->get_i_l().evaluate().value());
                        auto fcn = function_defs[fcn_name];
                        value = fcn.evaluate(false);
                    } else {
                        value = to_solve->get_i_l().evaluate();
                    }

                    if (value.has_value()) {
                        solved_parameters.insert({param_id, value.value()});
                    }

                } else {
                    for(const auto&[prefix, name]:dependencies) {
                        if(!prefix.empty()) {
                            // Package parameters can only be evaluated during_ast_construction, thus use a placeholder
                            solved_parameters.insert({param_id, "__RUNTIME_ONLY_PARAMETER__"});
                        }
                    }
                }
            }

            for (auto &[param_id, param_value]: solved_parameters) {
                bool propagation_complete = true;
                for (auto &dep: dependencies_map) {
                    if (dep.second.contains(param_id)) {
                        auto target = map.get(dep.first.name);
                        if(target->is_function()) {
                            auto fcn_name = std::get<std::string>(target->get_i_l().evaluate().value());
                            propagation_complete &= function_defs[fcn_name].propagate_constant(param_id, param_value);
                            if (propagation_complete) dep.second.erase(param_id);
                        } else {
                            propagation_complete &= target->propagate_constant(param_id, param_value);
                            if (propagation_complete) dep.second.erase(param_id);
                        }

                    }
                }
                    dependencies_map.erase(param_id);
            }
            rounds_counter++;
        }

        if (rounds_counter >=100) {
            spdlog::warn("Some parameters could not be solved in 100 passes");
        }

    return solved_parameters;
}


void parameter_solver::update_parameters_map(
    std::map<qualified_identifier, resolved_parameter> solved_parameters,
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
        if(solved_parameters.contains({"", param->get_name()})) {
            param_val = solved_parameters[{"", param->get_name()}];
        } else {
            param_val = resource.get_default_parameters()[{"", param->get_name()}];
        }
        if(std::holds_alternative<int64_t>(param_val)) ast_param->set_value(std::get<int64_t>(param_val));
        else if(std::holds_alternative<std::string>(param_val)) ast_param->set_value(std::get<std::string>(param_val));
        else if(std::holds_alternative<mdarray<int64_t>>(param_val)) ast_param->set_array_value(std::get<mdarray<int64_t>>(param_val));
        if(!node_parameters.contains(param->get_name())) node_parameters.insert(ast_param);
    }

    node->set_parameters(node_parameters);
}

std::map<qualified_identifier, resolved_parameter> parameter_solver::override_parameters(work_order &work, const std::shared_ptr<data_store> &d_store) {
    auto node_spec = d_store->get_HDL_resource(work.node->get_type());
    auto node_defaults = node_spec.get_default_parameters();
    auto node_overrides = work.node->get_parameters();
    auto node_parameters = node_spec.get_parameters();

    std::map<qualified_identifier, resolved_parameter> solved_parameters;
    // Override default parameters if necessary


    std::map<qualified_identifier, resolved_parameter> package_parameters;
    auto deps_map = get_dependency_map(node_parameters, {});
    for (auto &[param_name, param_deps]:deps_map) {
        for (const auto& identifier:param_deps) {
            if (!identifier.prefix.empty()) {
                auto package = d_store->get_HDL_resource(identifier.prefix);
                auto param_value = package.get_default_parameters();
                package_parameters[identifier] = param_value[{"", identifier.name}];
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
                    if(package_parameters.contains({dep.prefix, dep.name})) {
                        int i = 0;
                    } else if(work.parent_parameters.contains(dep)) {
                        if(param->propagate_constant(dep, work.parent_parameters[dep])) {
                            parameters_progress[param->get_name()]++;
                            if(parameters_progress[param->get_name()]== deps_map[{"", param->get_name()}].size()) {
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


    Parameters_map runtime_to_eval;
    for (auto [param_name, param_value]:solved_parameters) {
        if(std::holds_alternative<std::string>(param_value)) {
            if(std::get<std::string>(param_value) == "__RUNTIME_ONLY_PARAMETER__") {
                auto raw_param = node_parameters.get(param_name.name);
                for(auto &[param_id, param_val] :package_parameters) {
                    raw_param->propagate_constant(param_id, param_val);
                }
                runtime_to_eval.insert(raw_param);
            }
        }
    }
    auto runtime_params = process_parameters(runtime_to_eval, {});
    for (auto &[name, value]: solved_parameters) {
        if (runtime_params.contains(name)) value = runtime_params[name];
    }
    for (auto &[name, value]: node_defaults) {
        if (runtime_params.contains(name)) value = runtime_params[name];
    }
    update_parameters_map(solved_parameters, work.node, d_store);
    return node_defaults;
}

std::map<qualified_identifier, std::set<qualified_identifier>> parameter_solver::get_dependency_map(const Parameters_map &map,
    std::unordered_map<std::string, HDL_function> function_defs) {

    std::map<qualified_identifier, std::set<qualified_identifier>> dependencies_map;
    for (auto &param: map) {
        auto param_name = param->get_name();
        dependencies_map[{"", param_name}] = {};
        std::set<std::string> param_deps;
        if(param->is_function()) {
            auto fcn_name = std::get<std::string>(param->get_i_l().evaluate().value());
            auto fcn = function_defs[fcn_name];
            auto deps = fcn.get_dependencies();
            dependencies_map[{"", param_name}].insert(deps.begin(), deps.end());
        } else {
            auto deps = param->get_dependencies();
            dependencies_map[{"", param_name}].insert(deps.begin(), deps.end());
        }
    }
    return dependencies_map;
}
