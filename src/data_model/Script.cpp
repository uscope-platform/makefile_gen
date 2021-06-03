//
// Created by fils on 02/06/2021.
//

#include "data_model/Script.h"

#include <utility>

Script::Script(std::string n, const std::string& t) {
    name = std::move(n);
    if(t=="tcl") type = tcl_script;
    else if (t=="python" || t == "py") type = python_script;
    else type = uninit_script;
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

void Script::set_arguments(std::vector<std::string> args) {
    arguments = std::move(args);
}

void Script::set_path(std::string p) {
    path = std::move(p);
}
