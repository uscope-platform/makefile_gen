//
// Created by fils on 27/06/2021.
//

#include "Backend/python_script_runner.h"

void python_script_runner::run_python_scripts(std::set<std::shared_ptr<Script>> scripts) {
    for(const auto& item: scripts){
        std::filesystem::path p(item->get_path());
        std::string base_path = p.parent_path();
        std::vector<std::string> args =  item->get_arguments();
        std::vector<std::string> arg_v;
        arg_v.emplace_back("python3");
        arg_v.emplace_back(p);
        if(!args.empty()) {
            std::string target = base_path + "/" + args[0];
            arg_v.emplace_back(target);
            spawn_process(arg_v, false, true);
            if(item->get_product_include()){
                std::string tmp_type = item->get_product_type();
                if(tmp_type == "tcl"){
                    script_dependencies.insert(target);
                } else if(tmp_type == "hdl"){
                    hdl_dependencies.insert(target);
                } else if(tmp_type == "xdc"){
                    constraints_depdendencies.insert(target);
                }
            }

        }

    }
}

std::set<std::string> python_script_runner::get_script_dependencies() {
    return script_dependencies;
}

std::set<std::string> python_script_runner::get_hdl_dependencies() {
    return hdl_dependencies;
}

std::set<std::string> python_script_runner::get_constraints_dependencies() {
    return constraints_depdendencies;
}
