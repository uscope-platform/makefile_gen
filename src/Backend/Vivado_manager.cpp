//
// Created by fils on 18/06/2021.
//


#include "Backend/Vivado_manager.h"

#include <utility>


Vivado_manager::Vivado_manager(std::shared_ptr<settings_store> s, bool del_mkfile, std::string name) {
    delete_makefile = del_mkfile;
    project_name = std::move(name);
    s_store = std::move(s);
    vivado_path = "";
    vivado_path = s_store->get_setting("vivado_path");
    if(vivado_path.empty()){
        std::cout<< "Enter the full path of the Vivado installation"<<std::endl;
        std::cin >> vivado_path;
        s_store->set_setting("vivado_path", vivado_path);
    }
}

void Vivado_manager::create_project(const std::string& makefile, bool start_gui) {
    int pid = fork();
    if(pid== 0){
        std::vector<std::string> arg_v;
        arg_v.emplace_back(vivado_path + "/bin/vivado");
        arg_v.emplace_back("-mode");
        arg_v.emplace_back("batch");
        arg_v.emplace_back("-nolog");
        arg_v.emplace_back("-nojournal");
        arg_v.emplace_back("-source");
        arg_v.push_back(makefile);

        std::vector<const char *> args = str_vect_to_char_p(arg_v);


        execvp(args[0], const_cast<char *const *>(args.data()));
    }
    wait(nullptr);
    if(delete_makefile){
        std::filesystem::remove(makefile);
    }
    if(start_gui){
        std::vector<std::string> arg_v;
        arg_v.emplace_back(vivado_path + "/bin/vivado");
        arg_v.emplace_back("-nolog");
        arg_v.emplace_back("-nojournal");
        arg_v.push_back(project_name + "/" + project_name+".xpr");
        std::vector<const char *> args = str_vect_to_char_p(arg_v);
        execvp(args[0], const_cast<char *const *>(args.data()));
    }
}

std::vector<const char *> Vivado_manager::str_vect_to_char_p(const std::vector<std::string>& vect) {
    std::vector<const char *> args;
    args.reserve(vect.size() + 1);
    for( const auto& sp: vect) {
        args.push_back(sp.c_str());
    }
    args.push_back(nullptr);  // needed to terminate the args list

    return args;
}
