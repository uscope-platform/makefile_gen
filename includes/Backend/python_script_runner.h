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

#ifndef MAKEFILEGEN_V2_PYTHON_SCRIPT_RUNNER_H
#define MAKEFILEGEN_V2_PYTHON_SCRIPT_RUNNER_H

#include <set>
#include <string>
#include <memory>
#include <filesystem>

#include "../includes/data_model/Script.h"
#include "Toolchain_manager.h"

class python_script_runner :private Toolchain_manager{
public:
    void run_python_scripts(std::vector<Script> scripts);
    std::set<std::string>  get_script_dependencies();
    std::set<std::string>  get_hdl_dependencies();
    std::set<std::string>  get_constraints_dependencies();
private:
    std::set<std::string> script_dependencies;
    std::set<std::string> hdl_dependencies;
    std::set<std::string> constraints_depdendencies;
};


#endif //MAKEFILEGEN_V2_PYTHON_SCRIPT_RUNNER_H
