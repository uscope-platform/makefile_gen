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

Dependency_resolver::Dependency_resolver(std::string tl, std::shared_ptr<data_store> store) {
    top_level = std::move(tl);
    d_store = std::move(store);
}

std::set<std::string> Dependency_resolver::get_dependencies() {
    std::set<std::string> ret_val;
    for(auto& item: hdl_dependencies){
        ret_val.insert(item.get_path());
    }
    for(auto& item: mem_init_dependencies){
        ret_val.insert(item.get_path());
    }
    return ret_val;
}

void Dependency_resolver::resolve_dependencies() {
    resolve_dependencies(top_level);
    hdl_dependencies.push_back(d_store->get_HDL_resource(top_level));
}

void Dependency_resolver::resolve_dependencies(const std::string& module_name) {
    // Excluded modules and primitives are not defined and thus get a reference to a null pointer, we must exit early from the function to avoid dereferencing it
    bool is_excluded = std::find(excluded_modules.begin(), excluded_modules.end(), module_name) != excluded_modules.end();
    bool is_primitive = d_store->is_primitive(module_name);
    if(is_excluded || is_primitive) return;

    //  interfaces never have dependencies so we can exit
    HDL_Resource resource = d_store->get_HDL_resource(module_name);
    if(resource == HDL_Resource()){
        std::cerr << "ERROR: module or interface " << module_name << " not found"<<std::endl;
        exit(1);
    }

    bool is_interface = resource.is_interface();
    if(is_interface) return;

    if(resource.has_processors()){
        auto proc = resource.get_processor_doc();
        detected_processors.insert(detected_processors.end(), proc.begin(), proc.end());
    }

    std::vector<HDL_dependency> deps =  resource.get_dependencies();

    for(auto &item : deps){
        auto res = d_store->get_HDL_resource(item.get_type());
        bool dep_excluded = std::find(excluded_modules.begin(), excluded_modules.end(), item.get_type()) != excluded_modules.end();
        if(res != HDL_Resource() && !dep_excluded) hdl_dependencies.push_back(res);
        if(item.get_dependency_class() != memory_init){
            resolve_dependencies(item.get_type());
        } else {
            DataFile dep = d_store->get_data_file(item.get_type());
            if(dep == DataFile()){
                std::cerr << "ERROR: memory initialization file " << item.get_type() << " not found"<<std::endl;
                exit(1);
            } else{
                mem_init_dependencies.push_back(dep);
            }

        }

    }


}

void Dependency_resolver::set_excluded_modules(std::vector<std::string> exclusion_list) {
    excluded_modules = std::move(exclusion_list);
}

void Dependency_resolver::add_explicit_dependencies(const std::vector<std::string>& dep_list) {
    for(const auto& item: dep_list){
        hdl_dependencies.push_back(d_store->get_HDL_resource(item));
        resolve_dependencies(item);
    }
}

