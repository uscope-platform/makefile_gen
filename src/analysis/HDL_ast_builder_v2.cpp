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

#include "analysis/loop_solver.hpp"

HDL_ast_builder_v2::HDL_ast_builder_v2(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d,
                                       const Depfile &d_f){
    s_store = s;
    d_store = d;
    dep_file = d_f;
}

std::vector<std::shared_ptr<HDL_instance_AST>> HDL_ast_builder_v2::build_ast(const std::vector<std::string> &modules) {
    std::vector<std::shared_ptr<HDL_instance_AST>> ret;
    ret.reserve(modules.size());
    for(auto &item:modules){
        auto ast = build_ast(item);
        ret.push_back(ast);
    }
    return ret;
}

std::shared_ptr<HDL_instance_AST> HDL_ast_builder_v2::build_ast(const std::string &top_level_module) {

        auto top = std::make_shared<HDL_instance_AST>();
        top->set_name("TL");
        top->set_type(top_level_module);
        top->set_dependency_class(module);

        std::stack< work_order> working_stack;
        working_stack.push({top, {}, "TL"});



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

                if (!d_store->contains_hdl_entity(type)) {
                    std::cerr << "ERROR:\n HDL entity: " + type + " Not found\n";
                }
                auto res = d_store->get_HDL_resource(type);
                spdlog::trace("Processing dependency {} in module {}",working_instance->get_name(), type);
                auto current_param_values = parameter_solver::override_parameters(wo, d_store);

                for (auto &dep: res.get_dependencies()) {

                    auto child = std::make_shared<HDL_instance_AST>(dep);
                    child->set_parent(working_instance);

                    // The loop structure is attached to the looped instances, that need to be repeated,
                    // But the parent parameters only need to be propagated in its expressions
                    update_loop_constants(child, current_param_values);
                    auto loop_idx = loop_solver::solve_loop(child, res);
                    if (!loop_idx.empty()) {
                        for (auto &idx:loop_idx) {
                            auto new_child = std::make_shared<HDL_instance_AST>(*child);
                            auto specialized_child = specialize_instance(*new_child, idx, child->get_inner_loop().get_init().get_name());
                            working_instance->add_child(specialized_child);
                        }
                    } else {
                        working_instance->add_child(child);
                    }

                    working_stack.push({
                                    child,
                                    current_param_values,
                                    wo.path + "." + working_instance->get_name()
                                });
                }
            }
        }
    return top;
}

void HDL_ast_builder_v2::update_loop_constants(std::shared_ptr<HDL_instance_AST> &instance, const std::map<std::string, resolved_parameter> &parameters) {
    if (instance->get_n_loops()>0) {
        auto loop = instance->get_inner_loop();
        for (auto &[param_name, param_value]: parameters) {
            loop.propagate_constant(param_name, param_value);
        }
        instance->update_loop(loop, 0);
    }
}


std::shared_ptr<HDL_instance_AST> HDL_ast_builder_v2::specialize_instance(const HDL_instance_AST &i, int64_t idx, std::string idx_name) {
    HDL_instance_AST specialized_d = i;
    specialized_d.set_repeated(true);
    specialized_d.set_repetition_idx(idx);

    std::unordered_map<std::string, std::vector<HDL_net>> new_ports;

    std::string accessor = "[" + idx_name + "]";

    for(auto &[port_name, nets]:specialized_d.get_ports()){
        std::vector<HDL_net> port_content;
        for(auto &n:nets){
            if(n.is_array()) {
                auto new_net = n;
                Expression n_idx;
                n_idx.emplace_back(idx);
                new_net.set_index(n_idx);
                port_content.emplace_back(new_net);
            } else {
                port_content.push_back(n);
            }
        }
        new_ports[port_name] = port_content;
    }
    specialized_d.set_ports(new_ports);
    return std::make_shared<HDL_instance_AST>(specialized_d);
}