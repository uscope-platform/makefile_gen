//
// Created by fils on 20/06/2021.
//

#include "Backend/Toolchain_manager.h"

Toolchain_manager::Toolchain_manager(std::shared_ptr <settings_store> s, bool del_mkfile, std::string name) {
    delete_makefile = del_mkfile;
    project_name = std::move(name);
    s_store = std::move(s);
}

std::vector<const char *> Toolchain_manager::str_vect_to_char_p(const std::vector <std::string> &vect) {
    std::vector<const char *> args;
    args.reserve(vect.size() + 1);
    for( const auto& sp: vect) {
        args.push_back(sp.c_str());
    }
    args.push_back(nullptr);  // needed to terminate the args list

    return args;
}

void Toolchain_manager::spawn_process(const std::vector <std::string> &arg_v, bool daemonize, bool block) {
    int pid = fork();
    if(pid== 0){
        std::vector<const char *> args = str_vect_to_char_p(arg_v);
        if(daemonize) setsid();
        execvp(args[0], const_cast<char *const *>(args.data()));

    }
    if(block) wait(nullptr);
}
