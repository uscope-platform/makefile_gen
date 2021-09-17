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
            for(int i = 1; i<args.size(); ++i) {
                arg_v.push_back(args[i]);
            }
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
