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
        auto ast = build_ast(item);
        pass_manager pass_mgr;
        pass_mgr.apply_passes(ast);
        ret.push_back(ast);
    }
    return ret;
}

std::shared_ptr<HDL_instance_AST> HDL_ast_builder_v2::build_ast(const std::string &top_level_module) {

        auto top = std::make_shared<HDL_instance_AST>();
        top->set_name("TL");
        top->set_type(top_level_module);
        top->set_dependency_class(module);

        std::stack< std::shared_ptr<HDL_instance_AST> > working_stack;
        working_stack.push(top);


        while (!working_stack.empty()) {
            auto working_instance = working_stack.top();
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

                for (auto &dep: res.get_dependencies()) {

                    auto child = std::make_shared<HDL_instance_AST>(dep);

                    child->set_parent(working_instance);
                    working_instance->add_child(child);

                    working_stack.push(child);
                }
            }
        }
    return top;
}
