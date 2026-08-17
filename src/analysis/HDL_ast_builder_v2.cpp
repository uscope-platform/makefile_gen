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

#include "analysis/HDL_ast_builder_v2.hpp"
#include "crash_context.hpp"

#include <algorithm>

#include "analysis/loop_solver.hpp"
#include "data_model/HDL/parameters/components/token/Numeric_token.hpp"
#include "data_model/HDL/statement/hdl_statements.hpp"

namespace {
    std::string format_module_chain(const std::vector<std::string> &chain) {
        std::string ret;
        for (size_t i = 0; i < chain.size(); i++) {
            if (i) ret += " -> ";
            ret += chain[i];
        }
        return ret;
    }
}
HDL_ast_builder_v2::HDL_ast_builder_v2(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d,
                                       const Depfile &d_f, int max_recursion_depth)
    : max_recursion_depth(max_recursion_depth) {
    s_store = s;
    d_store = d;
    dep_file = d_f;
}

std::vector<std::shared_ptr<hdl_ast_node>> HDL_ast_builder_v2::build_ast(const std::vector<std::string> &modules) {
    std::vector<std::shared_ptr<hdl_ast_node>> ret;
    ret.reserve(modules.size());
    pass_manager m(d_store);
    for(auto &item:modules){
        auto ast = build_ast(item);
        m.apply_passes(ast);
        ret.push_back(ast);
    }


    return ret;
}

std::shared_ptr<hdl_ast_node> HDL_ast_builder_v2::build_ast(const std::string &top_level_module) {

        auto top = std::make_shared<hdl_ast_node>();
        top->set_name("TL");
        top->set_type(top_level_module);
        top->set_dependency_class(module);

        std::stack< work_order> working_stack;
        working_stack.push({top, {}, "TL", {}, {}, {top_level_module}});



        while (!working_stack.empty()) {
            auto wo = working_stack.top();
            auto working_instance = wo.node;
            working_stack.pop();

            auto type = working_instance->get_type();

            if(
                dep_file.is_module_excluded(type) ||
                d_store->is_primitive(type)
            ) continue;

            if(working_instance->get_dependency_class() == module || working_instance->get_dependency_class() == interface ) {
                std::string res_path;
                auto res_opt = d_store->get_HDL_resource(type, res_path);

                if (!res_opt.has_value()) {
                    spdlog::error("Definition of module {} while AST building", type);
                    continue;
                }
                auto res = res_opt.value();
                crash_ctx.set(type, res_path);

                spdlog::trace("Processing dependency {} in module {}",working_instance->get_name(), type);
                auto current_param_values = parameter_solver::override_parameters(wo, d_store);

                std::vector<work_order> child_wo;
                auto child_path = wo.path + "." + working_instance->get_name();

                std::unordered_map<std::string, std::string> interfaces_map;
                for (auto &[port_name, port_net] :wo.node->get_ports()) {
                    auto port_spec = res->get_port_specs()[port_name];
                    if (port_spec.direction == interface_port) {
                        interfaces_map[port_name] = port_spec.if_info.type;
                    }
                }
                for (auto &stmt : res->get_statements()) {
                    auto processed = process_statement(stmt, working_instance, current_param_values, child_path, interfaces_map, wo.module_chain);
                    if (!processed) {
                        if (processed.error() == recursive_module) {
                            spdlog::error("Skipping cyclic module hierarchy rooted at {}::{}", working_instance->get_type(), working_instance->get_name());
                        } else {
                            spdlog::warn("An error happened while processing instance {}::{}", working_instance->get_type(), working_instance->get_name());
                        }
                        continue;
                    }
                    child_wo.insert(child_wo.end(), processed.value().begin(), processed.value().end());
                }
                apply_parameter_overrides(res->get_statements(), wo.pending_overrides, child_wo);
                for (const auto &c:child_wo| std::views::reverse) {
                    working_stack.push(c);
                }
            }
        }
    return top;
}

bool HDL_ast_builder_v2::evaluate_condition(const std::shared_ptr<Expression_base> &cond,
    const std::map<qualified_identifier, resolved_parameter> &parameters) {
    if (!cond) return false;
    auto result = cond->evaluate(parameters);
    return result.has_value() && result.value().is_integer() && result.value().get_integer() != 0;
}

std::expected<void, solver_errors> HDL_ast_builder_v2::process_quantifier(const std::shared_ptr<HDL_parameter> &quantifier, const std::map<qualified_identifier, resolved_parameter> &parameters) {

    if (quantifier != nullptr) {
        auto value = quantifier->evaluate(parameters);
        if (!value.has_value()) return std::unexpected{value.error()};
        quantifier->set_value(value.value());
    }
    return {};
}

std::expected<std::vector<work_order>, solver_errors> HDL_ast_builder_v2::process_statement(
    const std::shared_ptr<hdl_statement_base> &stmt,
    const std::shared_ptr<hdl_ast_node> &parent,
    const std::map<qualified_identifier, resolved_parameter> &params,
    const std::string &path,
    const std::unordered_map<std::string, std::string> &if_map,
    const std::vector<std::string> &module_chain
) {
    if (auto inst = std::dynamic_pointer_cast<hdl_instance_statement>(stmt))
        return process_instance(inst, parent, params, path, if_map, module_chain);
    if (auto loop = std::dynamic_pointer_cast<hdl_loop_statement>(stmt))
        return process_loop(*loop, parent, params, path, if_map, module_chain);
    if (auto cond = std::dynamic_pointer_cast<hdl_conditional_statement>(stmt))
        return process_conditional(*cond, parent, params, path, if_map, module_chain);
    return {};
}

std::expected<std::vector<work_order>, solver_errors> HDL_ast_builder_v2::process_instance(
    const std::shared_ptr<hdl_instance_statement> &inst,
    const std::shared_ptr<hdl_ast_node> &parent,
    const std::map<qualified_identifier, resolved_parameter> &params,
    const std::string &path,
    const std::unordered_map<std::string, std::string> &if_map,
    const std::vector<std::string> &module_chain,
    bool active
) {
    std::vector<work_order> orders;
    auto dc = inst->get_dependency_class();
    if (dc != module && dc != interface) return orders;
    auto child = std::make_shared<hdl_ast_node>(*inst);
    child->set_parent(parent);
    child->set_active(active);
    auto type = inst->get_type();
    auto recursion_depth = std::count(module_chain.begin(), module_chain.end(), type);
    if (recursion_depth >= max_recursion_depth) {
        spdlog::error("Recursive module hierarchy detected at depth {} (limit {}): {} -> {}",
                      recursion_depth + 1, max_recursion_depth, format_module_chain(module_chain), type);
        return std::unexpected{recursive_module};
    }
    if (dep_file.is_module_excluded(type) || d_store->is_primitive(type)) child->set_dependency_class(primitive);
    if (auto err = process_quantifier(child->get_array_quantifier(), params); !err) return std::unexpected{err.error()};
    auto child_chain = module_chain;
    child_chain.push_back(type);
    parent->add_child(child);
    orders.push_back({child, params, path, if_map, {}, child_chain});
    return orders;
}

std::expected<std::vector<work_order>, solver_errors> HDL_ast_builder_v2::process_loop(
    const hdl_loop_statement &loop,
    const std::shared_ptr<hdl_ast_node> &parent,
    const std::map<qualified_identifier, resolved_parameter> &params,
    const std::string &path,
    const std::unordered_map<std::string, std::string> &if_map,
    const std::vector<std::string> &module_chain
) {
    if (!loop.get_init() || loop.get_init()->get_name().empty())
        return {};

    std::vector<work_order> orders;
    auto indices = loop_solver::solve_loop(loop, params);
    auto loop_var_name = loop.get_init()->get_name();
    for (auto &body_stmt : loop.get_body()) {
        for (auto &idx : indices) {
            auto parent_params = params;
            parent_params[qualified_identifier(loop_var_name)] = resolved_parameter(idx);

            if (auto body_inst = std::dynamic_pointer_cast<hdl_instance_statement>(body_stmt)) {
                auto child = std::make_shared<hdl_ast_node>(*body_inst);
                child->set_parent(parent);
                auto inst_type = body_inst->get_type();
                auto dc = body_inst->get_dependency_class();
                if ((dc == module || dc == interface) &&
                    std::count(module_chain.begin(), module_chain.end(), inst_type) >= max_recursion_depth) {
                    spdlog::error("Recursive module hierarchy detected at depth {} (limit {}): {} -> {}",
                                  std::count(module_chain.begin(), module_chain.end(), inst_type) + 1,
                                  max_recursion_depth, format_module_chain(module_chain), inst_type);
                    return std::unexpected{recursive_module};
                }
                if (dep_file.is_module_excluded(inst_type) || d_store->is_primitive(inst_type)) child->set_dependency_class(primitive);
                if (auto err = process_quantifier(child->get_array_quantifier(), params); !err) return std::unexpected{err.error()};

                std::unordered_map<std::string, std::vector<HDL_net>> new_ports;
                for (auto &[port_name, nets] : child->get_ports()) {
                    std::vector<HDL_net> port_content;
                    for (auto &n : nets) {
                        if (n.is_array()) {
                            auto new_net = n;
                            Expression_v2 n_idx;
                            n_idx.set_lhs(std::make_shared<Numeric_token>(std::variant<hdl_integer, double>(idx), 0));
                            new_net.set_index({n_idx});
                            port_content.emplace_back(new_net);
                        } else {
                            port_content.push_back(n);
                        }
                    }
                    new_ports[port_name] = port_content;
                }
                child->set_ports(new_ports);

                auto child_chain = module_chain;
                child_chain.push_back(inst_type);
                parent->add_child(child);
                orders.push_back({child, parent_params, path, if_map, {}, child_chain});
            } else {
                auto wo = process_statement(body_stmt, parent, parent_params, path, if_map, module_chain);
                if (!wo) return std::unexpected{wo.error()};
                orders.insert(orders.end(), wo.value().begin(), wo.value().end());
            }
        }
    }
    return orders;
}

std::expected<std::vector<work_order>, solver_errors> HDL_ast_builder_v2::process_conditional(
    const hdl_conditional_statement &cond,
    const std::shared_ptr<hdl_ast_node> &parent,
    const std::map<qualified_identifier, resolved_parameter> &params,
    const std::string &path,
    const std::unordered_map<std::string, std::string> &if_map,
    const std::vector<std::string> &module_chain
) {
    std::vector<work_order> orders;
    bool any_matched = false;
    for (auto &branch : cond.get_branches()) {
        bool selected = evaluate_condition(branch.condition, params);
        any_matched = any_matched || selected;
        for (auto &body_stmt : branch.body) {
            if (auto inst = std::dynamic_pointer_cast<hdl_instance_statement>(body_stmt)) {
                auto wo = process_instance(inst, parent, params, path, if_map, module_chain, selected);
                if (!wo)return std::unexpected{wo.error()};
                orders.insert(orders.end(), wo.value().begin(), wo.value().end());
            } else {
                auto wo = process_statement(body_stmt, parent, params, path, if_map, module_chain);
                if (!wo) return std::unexpected{wo.error()};
                orders.insert(orders.end(), wo.value().begin(), wo.value().end());
            }
        }
    }
    for (auto &body_stmt : cond.get_else_body()) {
        if (auto inst = std::dynamic_pointer_cast<hdl_instance_statement>(body_stmt)) {
            auto wo = process_instance(inst, parent, params, path, if_map, module_chain, !any_matched);
            if (!wo) return std::unexpected{wo.error()};
            orders.insert(orders.end(), wo.value().begin(), wo.value().end());
        } else {
            auto wo = process_statement(body_stmt, parent, params, path, if_map, module_chain);
            if (!wo) return std::unexpected{wo.error()};
            orders.insert(orders.end(), wo.value().begin(), wo.value().end());
        }
    }
    return orders;
}

void HDL_ast_builder_v2::apply_parameter_overrides(
    const std::vector<std::shared_ptr<hdl_statement_base>> &statements,
    const std::vector<pending_parameter_override> &inherited,
    std::vector<work_order> &child_wo
) {
    // Resolve each override one level at a time against the child work orders.
    // If the remaining path is exhausted, the override is injected onto the
    // target instance's node; otherwise it is forwarded to the matching child
    // work order for the next level.
    auto find_child = [&](const std::string &name) -> work_order* {
        for (auto &wo : child_wo) {
            if (wo.node->get_name() == name) return &wo;
        }
        return nullptr;
    };

    auto handle = [&](const std::vector<std::string> &path, const std::string &pname,
                      const std::shared_ptr<Expression_base> &value) {
        if (path.empty()) return;
        auto child = find_child(path[0]);
        if (!child) {
            spdlog::warn("defparam target path not found, ignoring");
            return;
        }
        if (path.size() == 1) {
            auto p = std::make_shared<HDL_parameter>(pname);
            p->set_raw_value(value);
            child->node->add_parameter(p);
        } else {
            pending_parameter_override po;
            po.path.assign(path.begin() + 1, path.end());
            po.parameter_name = pname;
            po.value = value;
            child->pending_overrides.push_back(po);
        }
    };

    for (const auto &stmt : statements) {
        auto dp = std::dynamic_pointer_cast<hdl_parameter_override_statement>(stmt);
        if (!dp) continue;
        handle(dp->get_instance_path(), dp->get_parameter_name(), dp->get_value());
    }

    for (const auto &po : inherited) {
        handle(po.path, po.parameter_name, po.value);
    }
}
