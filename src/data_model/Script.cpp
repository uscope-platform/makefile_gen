//
// Created by fils on 02/06/2021.
//

#include "data_model/Script.h"



Script::Script(std::string n, const std::string& t) {
    name = std::move(n);
    if(t=="tcl") type = tcl_script;
    else if (t=="python" || t == "py") type = python_script;
    else type = uninit_script;
}

Script::Script(const std::string& serialized_script) {
    std::istringstream stream(serialized_script);
    std::vector<std::string> tokens;
    std::string tmp;
    tokens.reserve(3);
    while(std::getline(stream, tmp, ',')) {
        tokens.push_back(tmp);
    }
    name = std::string(tokens[0]);
    path = std::string(tokens[1]);
    type = script_type_t(std::stoi(tokens[2]));
    tokens.erase(tokens.begin(), tokens.begin()+3);
    for(auto & token : tokens){
        arguments.push_back(token);
    }

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

std::string Script::get_path() {
    return path;
}

Script::operator std::string() {
    std::ostringstream ret_val;
    ret_val << name << "," << path << "," << type << ",";

    for(const auto& item:arguments){
        ret_val << item << ",";
    }
    return ret_val.str();
}

bool operator==(const Script &lhs, const Script &rhs) {

    bool cond_1 = lhs.name == rhs.name;
    bool cond_2 = lhs.path == rhs.path;
    bool cond_3 = lhs.type == rhs.type;
    bool cond_4 = lhs.arguments == rhs.arguments;

    return cond_1 && cond_2 && cond_3 && cond_4;
}
