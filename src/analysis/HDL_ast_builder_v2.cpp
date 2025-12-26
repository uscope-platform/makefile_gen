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
        ret.push_back(build_ast(item));
    }
    return ret;
}

std::shared_ptr<HDL_instance_AST> HDL_ast_builder_v2::build_ast(const std::string &top_level_module) {

        HDL_instance_AST i;
        i.set_name("TL");
        i.set_type(top_level_module);
        i.set_dependency_class(module);

        std::stack< std::shared_ptr<HDL_instance_AST> > working_stack;
        working_stack.push(std::make_shared<HDL_instance_AST>(i));

        std::shared_ptr<HDL_instance_AST>  parent = nullptr;


        while (!working_stack.empty()) {
            auto working_instance = working_stack.top();
            working_stack.pop();

            auto type = working_instance->get_type();

            auto new_node = std::make_shared<HDL_instance_AST>();

            if(
                dep_file.is_module_excluded(type) ||
                d_store->is_primitive(type)
            ) continue;

            if(i.get_dependency_class() == module || i.get_dependency_class() == interface ) {

                if (!d_store->contains_hdl_entity(type)) {
                    std::cerr << "ERROR:\n HDL entity: " + type + " Not found\n";
                }
                auto res = d_store->get_HDL_resource(type);


                new_node->set_channel_groups(i.get_channel_groups());
                new_node->set_ports(i.get_ports());
                new_node->set_if_specs(res.get_if_port_specs());

                new_node->set_name(i.get_name());
                new_node->set_type(type);
                new_node->set_dependency_class(module);
                new_node->set_repeated(i.get_repeated());
                new_node->set_repetition_idx(i.get_repetition_idx());
                if (parent != nullptr) {
                    new_node->set_parent(parent);
                    parent->add_child(new_node);
                }
                parent = new_node;
                for (auto &dep: i.get_dependencies()) {
                    working_stack.push(dep);
                }

            }
        }
    return {};
}
