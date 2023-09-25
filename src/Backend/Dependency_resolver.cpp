// Copyright 2021 University of Nottingham Ningbo China
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Backend/Dependency_resolver.hpp"



Dependency_resolver_v2::Dependency_resolver_v2(const std::vector<std::shared_ptr<HDL_instance_AST>> &i, std::shared_ptr<data_store> store) {
    AST = i;
    d_store = std::move(store);
}

std::set<std::string> Dependency_resolver_v2::get_dependencies() {
    std::set<std::string> ret_val;
    for(auto &a:AST){
        auto deps = solve_dep(a);
        auto path = d_store->get_HDL_resource(a->get_type()).get_path();
        deps.insert(path);
        ret_val.insert(deps.begin(), deps.end());
    }

    return ret_val;
}

std::set<std::string> Dependency_resolver_v2::solve_dep(std::shared_ptr<HDL_instance_AST> &i) {
    std::set<std::string> ret_val;

    auto type = i->get_type();

    for(auto &dep:i->get_dependencies()){
        if(d_store->contains_hdl_entity(dep->get_type())){

            auto res = d_store->get_HDL_resource(dep->get_type());

            ret_val.insert(res.get_path());
        }
        auto dep_set = solve_dep(dep);
        ret_val.insert(dep_set.begin(), dep_set.end());
    }

    for(auto &item:i->get_package_dependencies()){
        ret_val.insert(item);
    }

    for(auto &item:i->get_data_dependencies()){
        ret_val.insert(item);
    }

    return ret_val;
}
