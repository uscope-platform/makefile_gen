//
// Created by fils on 20/06/2021.
//

#ifndef MAKEFILEGEN_V2_TOOLCHAIN_MANAGER_H
#define MAKEFILEGEN_V2_TOOLCHAIN_MANAGER_H


#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <filesystem>
#include <spawn.h>
#include <utility>

#include "../data_model/settings_store.h"

class Toolchain_manager {
public:
    Toolchain_manager() = default;
    Toolchain_manager(std::shared_ptr<settings_store> s, bool del_mkfile, std::string name);
    virtual void create_project(const std::string& makefile, bool start_gui) {};

protected:
    static std::vector<const char *> str_vect_to_char_p(const std::vector<std::string>& vect);
    static void spawn_process(const std::vector<std::string>&arg_v, bool daemonize, bool block);

    bool delete_makefile;
    std::string project_name;
    std::shared_ptr<settings_store> s_store;
};
#endif //MAKEFILEGEN_V2_TOOLCHAIN_MANAGER_H
