//
// Created by fils on 27/06/2021.
//

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
    void run_python_scripts(std::set<std::shared_ptr<Script>> scripts);
    std::vector<std::string> get_additional_dependencies();
private:
    std::vector<std::string> additional_dependencies;
};


#endif //MAKEFILEGEN_V2_PYTHON_SCRIPT_RUNNER_H
