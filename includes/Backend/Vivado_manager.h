//
// Created by fils on 18/06/2021.
//

#ifndef MAKEFILEGEN_V2_VIVADO_MANAGER_H
#define MAKEFILEGEN_V2_VIVADO_MANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <filesystem>

#include "data_model/settings_store.h"

class Vivado_manager {
public:
    Vivado_manager(std::shared_ptr<settings_store> s, bool del_mkfile, std::string name);
    void create_project(const std::string& makefile, bool start_gui);

private:
    static std::vector<const char *> str_vect_to_char_p(const std::vector<std::string>& vect);
    bool delete_makefile;
    std::string project_name;
    std::shared_ptr<settings_store> s_store;
    std::string vivado_path;
};


#endif //MAKEFILEGEN_V2_VIVADO_MANAGER_H
