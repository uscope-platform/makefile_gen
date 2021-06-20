//
// Created by fils on 18/06/2021.
//


#include "Backend/Xilinx/Vivado_manager.h"

#include <utility>

Vivado_manager::Vivado_manager(std::shared_ptr<settings_store> s, bool del_mkfile, std::string name) : Toolchain_manager(std::move(s), del_mkfile, std::move(name)){
    vivado_path = "";
    vivado_path = s_store->get_setting("vivado_path");
    if(vivado_path.empty()){
        std::cout<< "Enter the full path of the Vivado installation"<<std::endl;
        std::cin >> vivado_path;
        s_store->set_setting("vivado_path", vivado_path);
    }
}

void Vivado_manager::create_project(const std::string& makefile, bool start_gui) {
    std::vector<std::string> arg_v;
    arg_v.emplace_back(vivado_path + "/bin/vivado");
    arg_v.emplace_back("-mode");
    arg_v.emplace_back("batch");
    arg_v.emplace_back("-nolog");
    arg_v.emplace_back("-nojournal");
    arg_v.emplace_back("-source");
    arg_v.push_back(makefile);

    spawn_process(arg_v, false, true);

    if(delete_makefile){
        std::filesystem::remove(makefile);
    }

    if(start_gui){

        arg_v.clear();
        arg_v.emplace_back(vivado_path + "/bin/vivado");
        arg_v.emplace_back("-nolog");
        arg_v.emplace_back("-nojournal");
        arg_v.push_back(project_name + "/" + project_name+".xpr");

        spawn_process(arg_v, true, false);
    }
}
