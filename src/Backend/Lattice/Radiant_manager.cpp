//
// Created by fils on 20/06/2021.
//

#include "Backend/Lattice/Radiant_manager.h"


Radiant_manager::Radiant_manager(std::shared_ptr<settings_store> s, bool del_mkfile, std::string name) : Toolchain_manager(std::move(s), del_mkfile, std::move(name)) {
    radiant_path = "";
    radiant_path = s_store->get_setting("radiant_path");
    if(radiant_path.empty()){
        std::cout<< "Enter the full path of the Radiant installation"<<std::endl;
        std::cin >> radiant_path;
        s_store->set_setting("radiant_path", radiant_path);
    }
}

void Radiant_manager::create_project(const std::string &makefile, bool start_gui) {
    std::vector<std::string> arg_v;
    arg_v.emplace_back(radiant_path + "/bin/lin64/radiantc");
    arg_v.push_back(makefile);

    spawn_process(arg_v, false, true);

    if(delete_makefile){
        std::filesystem::remove(makefile);
    }

    if(start_gui){

        arg_v.clear();
        arg_v.emplace_back(radiant_path + "/bin/lin64/radiant");
        arg_v.push_back(project_name + "_lscc/" + project_name+"_lscc.rdf");

        spawn_process(arg_v, true, false);
    }
}
