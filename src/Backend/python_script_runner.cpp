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
            arg_v.emplace_back(base_path + "/" + args[0]);
            spawn_process(arg_v, false, true);
        }
    }
}

std::vector<std::string> python_script_runner::get_additional_dependencies() {
    return additional_dependencies;
}
