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

std::vector<std::shared_ptr<HDL_instance_AST>> HDL_ast_builder::build_ast(const std::vector<std::string> &modules,
                                                                      const Parameters_map &external_parameters) {
    std::vector<std::shared_ptr<HDL_instance_AST>> ret;
    ret.reserve(modules.size());
    for(auto &item:modules){
        ret.push_back(build_ast(item, external_parameters));
    }
    return ret;
}


std::shared_ptr<HDL_instance_AST> HDL_ast_builder::build_ast(const std::string& top_level_module, const Parameters_map &external_parameters) {

    HDL_instance_AST i;
    i.set_name("TL");
    i.set_type(top_level_module);
    i.set_dependency_class(module);

    if (auto top_level = recursive_build_ast(i, external_parameters, nullptr)){
        auto val = *top_level;
        val->set_dependency_class(module);
        return  val;
    } else{
        return {};
    }

}




std::optional<std::shared_ptr<HDL_instance_AST>> HDL_ast_builder::recursive_build_ast(
        HDL_instance_AST &i,
        const Parameters_map &external_parameters,
        const std::shared_ptr<HDL_instance_AST>& parent
) {

    auto ret_inst = std::make_shared<HDL_instance_AST>();

    auto type = i.get_type();

    if(
        dep_file.is_module_excluded(type) ||
        d_store->is_primitive(type)
    ){
        return {};
    }
    bool stop = type == "hil_base_logic";
    if(i.get_dependency_class() == module || i.get_dependency_class() == interface ) {

        if (!d_store->contains_hdl_entity(type)) {
            std::cerr << "ERROR:\n HDL entity: " + type + " Not found\n";
        }
        auto res = d_store->get_HDL_resource(type);

        Parameter_processor p(external_parameters, d_store);
        auto parent_parameters = i.get_parameters_copy();
        auto instance_parameters = p.process_parameters_map(parent_parameters, res);


        Parameter_processor p2 = Parameter_processor(instance_parameters, d_store);
        auto pm = res.get_parameters();
        auto new_params = p2.process_parameters_map(pm, res);

        std::vector<processor_instance> processors;
        if(res.has_processors()){
            processors = res.get_processor_doc();

            for(auto &proc:processors){
                auto addr_s = proc.get_address();
                auto addr_vals = new_params.get(addr_s);
                int64_t address;

                if(addr_vals->is_array()){
                    auto addr_idx = proc.get_address_idx();
                    address = addr_vals->get_array_value().get_value({0,0,addr_idx});
                } else {
                    address = addr_vals->get_numeric_value();
                }
                proc.set_address_value(address);
            }
        }

        ret_inst->set_channel_groups(i.get_channel_groups());
        ret_inst->set_ports(i.get_ports());
        ret_inst->set_if_specs(res.get_if_port_specs());

        ret_inst->set_name(i.get_name());
        ret_inst->set_type(type);
        ret_inst->set_dependency_class(module);
        ret_inst->add_parameters(new_params);
        ret_inst->set_parent(parent);

        ret_inst->add_array_quantifier(i.get_array_quantifier());
        ret_inst->set_processors(processors);

        if (log_structure) {
            std::cout << "Processing Instance " << i.get_name() << " of module " << type << std::endl;
        }

        std::vector<nlohmann::json> leaves;
        for(auto &dep: res.get_dependencies()){
            if(dep.get_dependency_class() != package  && dep.get_dependency_class() != memory_init){
                HDL_instance_AST d = dep;
                auto dbg = d.get_name();
                bool do_break = dbg == "core_c";
                if(d.get_n_loops()>1){
                    std::cout << "WARNING: Nested loops are not supported by parameter analysis\n In HDL instance: " + i.get_name() + " of type: " + type + " is in a nested loop" << std::endl;
                } else if(d.get_n_loops() == 1){
                    HDL_loop_solver solver(new_params, d_store);
                    auto loop = d.get_inner_loop();
                    auto indices =solver.solve_loop(loop, res);
                    for(auto index:indices){
                        auto specialized_params = specialize_parameters(index, new_params, loop.init.get_name());
                        auto specialized_d = specialize_instance(d, index,specialized_params, loop.init.get_name());
                        if (auto ll_ret = recursive_build_ast(specialized_d,specialized_params, ret_inst))
                            ret_inst->add_child(*ll_ret);
                    }
                } else {
                    if (auto ll_ret = recursive_build_ast(d,new_params, ret_inst))
                        ret_inst->add_child(*ll_ret);
                }


            } else if(dep.get_dependency_class() == memory_init){
                auto path = d_store->get_data_file(dep.get_type()).get_path();
                ret_inst->add_data_dependency(path);
            } else{
                auto path = d_store->get_HDL_resource(dep.get_type()).get_path();
                ret_inst->add_package_dependency(path);
            }
        }

    }


    return ret_inst;
}

HDL_instance_AST HDL_ast_builder::specialize_instance(HDL_instance_AST &i, int64_t idx,  const Parameters_map &specialized_params, std::string idx_name) {
    HDL_instance_AST specialized_d = i;
    specialized_d.set_repeated(true);
    specialized_d.set_repetition_idx(idx);

    std::unordered_map<std::string, std::vector<std::string>> new_ports;

    std::string accessor = "[" + idx_name + "]";

    for(auto &p:specialized_d.get_ports()){
        std::vector<std::string> port_content;
        for(auto &conn:p.second){
            if(conn.length()>accessor.length() && conn.compare(conn.length()-accessor.length(), accessor.length(), accessor) == 0){
                auto base = conn.substr(0, conn.length()-accessor.length());
                port_content.push_back(base);
            } else {
                port_content.push_back(conn);
            }
        }
        new_ports[p.first] = port_content;
    }
    specialized_d.set_ports(new_ports);
    return specialized_d;
}

Parameters_map
HDL_ast_builder::specialize_parameters(int64_t idx, const Parameters_map &params,
                                       std::string idx_name) {
    Parameters_map specialized_params = params;
    std::shared_ptr<HDL_parameter> idx_param = std::make_shared<HDL_parameter>();
    idx_param->set_name(idx_name);
    idx_param->set_value(idx);
    specialized_params.insert(idx_param);
    return specialized_params;
}

