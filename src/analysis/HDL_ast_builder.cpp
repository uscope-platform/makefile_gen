//  Copyright 2023 Filippo Savi
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

#include "analysis/HDL_ast_builder.hpp"

#include <utility>

HDL_ast_builder::HDL_ast_builder(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d) {
    s_store = s;
    d_store = d;
}

void HDL_ast_builder::build_ast(const std::string& top_level_module, std::unordered_map<std::string, HDL_parameter> external_parameters) {
    auto tl_res = d_store->get_HDL_resource(top_level_module);

    HDL_instance tl_dep;
    tl_dep.set_name("TL");
    tl_dep.set_type(top_level_module);
    tl_dep.add_parameters(std::move(external_parameters));

    // TODO: RECURSIVELY BUILD THE AST BY WALKING THROUGH THE DEFINITIONS
}
