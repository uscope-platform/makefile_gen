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


HDL_ast_builder::HDL_ast_builder(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d, const Depfile& d_f) :dep_file(d_f) {
    s_store = s;
    d_store = d;
    log_structure = false;
}

std::vector<HDL_instance> HDL_ast_builder::build_ast(const std::vector<std::string> &modules,
                                                     std::map<std::string, HDL_parameter> external_parameters) {
    std::vector<HDL_instance> ret;
    ret.reserve(modules.size());
    for(auto &item:modules){
        ret.push_back(build_ast(item, external_parameters));
    }
    return ret;
}


HDL_instance HDL_ast_builder::build_ast(const std::string& top_level_module, std::map<std::string, HDL_parameter> external_parameters) {

    HDL_instance i;
    i.set_name("TL");
    i.set_type(top_level_module);
    i.set_dependency_class(module);

    auto top_level = recursive_build_ast(i, external_parameters);
    top_level.set_dependency_class(module);

    return  top_level;
}




HDL_instance HDL_ast_builder::recursive_build_ast(HDL_instance &i,const std::map<std::string, HDL_parameter> &external_parameters) {

    HDL_instance ret_inst;

    auto type = i.get_type();

    if(
        dep_file.is_module_excluded(type) ||
        d_store->is_primitive(type)
    ){
        return {};
    }

    if(i.get_dependency_class() == module || i.get_dependency_class() == interface ) {

        if (!d_store->contains_hdl_entity(type)) {
            std::cerr << "ERROR:\n HDL entity :" + type + " Not found\n";
        }
        auto res = d_store->get_HDL_resource(type);

        Parameter_processor p(external_parameters, d_store);
        auto parent_parameters = i.get_parameters();
        auto instance_parameters = p.process_parameters_map(parent_parameters, res);

        p = Parameter_processor(instance_parameters, d_store);
        res = p.process_resource(res);

        ret_inst.set_ports(i.get_ports());

        ret_inst.set_name(i.get_name());
        ret_inst.set_type(type);
        ret_inst.set_dependency_class(module);
        ret_inst.add_parameters(res.get_parameters());

        if (log_structure) {
            std::cout << "Processing Instance " << i.get_name() << " of module " << type << std::endl;
        }

        std::vector<nlohmann::json> leaves;
        for(auto &dep: res.get_dependencies()){
            if(dep.get_dependency_class() != package  && dep.get_dependency_class() != memory_init){
                auto ll_ret = recursive_build_ast(dep,res.get_parameters());
                ret_inst.add_child(ll_ret);
            } else if(dep.get_dependency_class() == memory_init){
                auto path = d_store->get_data_file(dep.get_type()).get_path();
                ret_inst.add_data_dependency(path);
            } else{
                auto path = d_store->get_HDL_resource(dep.get_type()).get_path();
                ret_inst.add_package_dependency(path);
            }
        }

    }


    return ret_inst;
}

