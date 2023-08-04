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

    recursion_level = 0;
    auto tl_res = d_store->get_HDL_resource(top_level_module);


    top_level.set_type(top_level_module);

    Parameter_processor p(external_parameters, d_store);
    auto res = p.process_resource(tl_res);

    top_level.add_parameters(res.get_parameters());

    // TODO: RECURSIVELY BUILD THE AST BY WALKING THROUGH THE DEFINITIONS
    for(auto &dep: tl_res.get_dependencies()){
        recursive_build_ast(dep, top_level.get_parameters());
    }

    return  top_level;
}

std::unordered_map<std::string, HDL_parameter>
HDL_ast_builder::merge_parameters(std::unordered_map<std::string, HDL_parameter> parent_parameter,
                                  std::unordered_map<std::string, HDL_parameter> instance_parameters,
                                  std::unordered_map<std::string, HDL_parameter> module_parameters) {

    std::unordered_map<std::string, HDL_parameter> merged_parameters;



    for(auto &item:module_parameters){
        HDL_parameter selected_param;
        if(instance_parameters.contains(item.first)){
             selected_param = instance_parameters[item.first];
        } else {
            selected_param = item.second;
        }

        if(selected_param.is_numeric_string()) {
            selected_param.string_to_numeric();
        }else if(selected_param.is_array()){
            selected_param.string_to_array(parent_parameter, instance_parameters, module_parameters);
            //manage individual array components
        } else{
            if(parent_parameter.contains(selected_param.get_string_value())) {
                selected_param = parent_parameter[selected_param.get_string_value()];
            } else{
                int i = 0;
            }
        }

        merged_parameters.insert({item.first, selected_param});

    }

    return merged_parameters;
}



void HDL_ast_builder::recursive_build_ast(HDL_instance &i,const std::map<std::string, HDL_parameter> &external_parameters) {
    recursion_level++;

    auto res = d_store->get_HDL_resource(i.get_type());

    Parameter_processor p(external_parameters, d_store);
    res = p.process_resource(res);


    std::string prefix;
    for(int j =  0; j<recursion_level; j++){
        prefix += "  ";
    }

    auto module_name = i.get_type();

    if(log_structure){
        //std::cout<<"------------------------------------------------"<<std::endl;
        std::cout<< prefix << "MODULE: "<<  module_name << " INSTANCE: " << i.get_name() << std::endl;
        /*std::cout<<"------------------------------------------------"<<std::endl;


        for(auto &item: res.get_parameters()){
            std::cout<< prefix << item.first<< " ------ " << std::string(item.second) <<std::endl;
        }
        std::cout<<"------------------------------------------------"<<std::endl;*/

    }


    for(auto &dep: res.get_dependencies()){
        if(dep.get_dependency_class() != package)
            recursive_build_ast(dep,res.get_parameters());
    }
    recursion_level--;
}
