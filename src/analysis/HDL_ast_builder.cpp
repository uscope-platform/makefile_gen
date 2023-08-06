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


HDL_ast_builder::HDL_ast_builder(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d) {
    s_store = s;
    d_store = d;
    log_structure = true;
}

HDL_instance HDL_ast_builder::build_ast(const std::string& top_level_module, std::map<std::string, HDL_parameter> external_parameters) {
    top_level = HDL_instance();
    top_level.set_name("TL");

    auto tl_res = d_store->get_HDL_resource(top_level_module);

    top_level.set_type(top_level_module);

    Parameter_processor p(external_parameters, d_store);
    auto res = p.process_resource(tl_res);

    top_level.add_parameters(res.get_parameters());

    std::vector<nlohmann::json> leaves;
    for(auto &dep: tl_res.get_dependencies()){
        auto ll_ret =recursive_build_ast(dep, top_level.get_parameters());
        top_level.add_child(ll_ret.first);
        leaves.push_back(ll_ret.second);
    }

    if(log_structure) {
        log["module_type"] = top_level.get_type();
        log["instance_name"] = top_level.get_name();
        nlohmann::json params;
        for(auto &item: top_level.get_parameters()){
            if(item.second.get_type()== string_parameter){
                params[item.first] = item.second.get_string_value();
            } else{
                params[item.first] = item.second.get_numeric_value();
            }
        }
        log["parameters"] = params;
        log["leaves"] = leaves;

        std::ofstream file("mkfg_tree_dump.json");
        file << std::setw(4) << log << std::endl;
        file.close();
    }


    return  top_level;
}



std::pair<HDL_instance,nlohmann::json> HDL_ast_builder::recursive_build_ast(HDL_instance &i,const std::map<std::string, HDL_parameter> &external_parameters) {
    nlohmann::json current_log;
    HDL_instance ret_inst;

    if(!d_store->contains_hdl_entity(i.get_type())){
        std::cerr << "ERROR:\n HDL entity :" + i.get_type() + " Not found\n";
    }
    auto res = d_store->get_HDL_resource(i.get_type());

    Parameter_processor p(external_parameters, d_store);
    res = p.process_resource(res);



    ret_inst.set_name(i.get_name());
    ret_inst.set_type(i.get_type());
    ret_inst.add_parameters(res.get_parameters());

    if(log_structure){
        std::cout << "Processing Instance "<< i.get_name() << " of module "<<  i.get_type() << std::endl;
        current_log["module_type"] = i.get_type();
        current_log["instance_name"]= i.get_name();
        nlohmann::json params;
        for(auto &item: res.get_parameters()){
            if(item.second.get_type()== string_parameter){
                params[item.first] = item.second.get_string_value();
            } else{
                params[item.first] = item.second.get_numeric_value();
            }
        }
        current_log["parameters"] = params;
    }


    std::vector<nlohmann::json> leaves;
    for(auto &dep: res.get_dependencies()){
        if(dep.get_dependency_class() != package){
            auto ll_ret = recursive_build_ast(dep,res.get_parameters());
            ret_inst.add_child(ll_ret.first);
            leaves.push_back(ll_ret.second);
        }
    }


    if(log_structure){
        current_log["leaves"] = leaves;
    }

    return {ret_inst, current_log};
}
