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

#include "Backend/Auxiliary_resolver.hpp"



Auxiliary_resolver::Auxiliary_resolver(std::shared_ptr<data_store> store) {
    d_store = std::move(store);
}

std::unordered_set<std::string> Auxiliary_resolver::get_tcl_script_paths(const std::vector<Script> &names) {
    return this->get_script_paths_by_type(names, tcl_script);
}

std::unordered_set<std::string> Auxiliary_resolver::get_python_script_paths(const std::vector<Script> &names) {
    return this->get_script_paths_by_type(names, python_script);
}

std::unordered_set<std::string> Auxiliary_resolver::get_constraints(const std::vector<Constraints> &names) {
    std::unordered_set<std::string> ret_val;
    for(auto item : names){
        std::string constraint_name = std::regex_replace(item.get_name(), std::regex("\\.xdc"), "");
        Constraints cnstr = d_store->get_constraint(constraint_name);
        if(cnstr == Constraints()){
            throw std::runtime_error("ERROR: constraint file " + constraint_name+ " not found!");
        }
        ret_val.insert(cnstr.get_path());
    }
    return ret_val;
}

std::unordered_set<std::string>
Auxiliary_resolver::get_script_paths_by_type(const std::vector<Script> &names, script_type_t type) {
    std::unordered_set<std::string> ret_val;
    for(auto item : names){
        std::string script_name = std::regex_replace(item.get_name(), std::regex("\\.tcl|\\.py"), "");
        Script scr = d_store->get_script(script_name);
        if(scr.get_type() == type) ret_val.insert(scr.get_path());

    }
    return ret_val;
}

std::vector<Script>  Auxiliary_resolver::get_script_objects_by_type(const std::vector<Script> &names, script_type_t type) {
    std::vector<Script> ret_val;
    for(auto item : names){
        std::string script_name = std::regex_replace(item.get_name(), std::regex("\\.tcl|\\.py"), "");
        Script scr =  d_store->get_script(script_name);

        if(scr.get_type() == type){
            scr.set_arguments(item.get_arguments());
            scr.set_product(item.get_product_include(), item.get_product_type());
            ret_val.push_back(scr);

        }
    }
    return ret_val;
}

std::vector<Script>  Auxiliary_resolver::get_tcl_objects(const std::vector<Script> &names) {
    return this->get_script_objects_by_type(names, tcl_script);
}

std::vector<Script> Auxiliary_resolver::get_python_objects(const std::vector<Script> &names) {
    return this->get_script_objects_by_type(names, python_script);
}
