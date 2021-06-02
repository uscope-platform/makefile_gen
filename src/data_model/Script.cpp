//
// Created by fils on 02/06/2021.
//

#include "data_model/Script.h"

#include <utility>

Script::Script(std::string n, const std::string& t, std::vector<std::string> args) {
    name = std::move(n);
    arguments = std::move(args);
    if(t=="tcl") type = tcl_script;
    else if (t=="python") type = python_script;
}

std::string Script::get_name() {
    return name;
}

script_type_t Script::get_type() {
    return type;
}

std::vector<std::string> Script::get_arguments() {
    return arguments;
}
