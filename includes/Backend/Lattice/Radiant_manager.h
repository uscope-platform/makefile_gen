//
// Created by fils on 20/06/2021.
//

#ifndef MAKEFILEGEN_V2_RADIANT_MANAGER_H
#define MAKEFILEGEN_V2_RADIANT_MANAGER_H

#include <vector>
#include <string>

#include "../../data_model/settings_store.h"
#include "../Toolchain_manager.h"
#include <utility>


class Radiant_manager : public Toolchain_manager {
public:
    Radiant_manager(std::shared_ptr<settings_store> s, bool del_mkfile, std::string name);
    void create_project(const std::string& makefile, bool start_gui) override;

private:
    std::string radiant_path;
};

#endif //MAKEFILEGEN_V2_RADIANT_MANAGER_H
