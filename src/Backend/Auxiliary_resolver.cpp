//
// Created by fils on 06/06/2021.
//


#include "Backend/Auxiliary_resolver.h"



Auxiliary_resolver::Auxiliary_resolver(std::shared_ptr<data_store> store) {
    d_store = std::move(store);
}

std::set<std::string> Auxiliary_resolver::get_tcl_scripts(const std::vector<Script> &names) {
    return this->get_scripts_by_type(names, tcl_script);
}

std::set<std::string> Auxiliary_resolver::get_python_scripts(const std::vector<Script> &names) {
    return this->get_scripts_by_type(names, python_script);
}

std::set<std::string> Auxiliary_resolver::get_constraints(const std::vector<Constraints> &names) {
    std::set<std::string> ret_val;
    for(auto item : names){
        std::string constraint_name = std::regex_replace(item.get_name(), std::regex("\\.xdc"), "");
        std::shared_ptr<Constraints> cnstr = d_store->get_constraint(constraint_name);
        ret_val.insert(cnstr->get_path());
    }
    return ret_val;
}

std::set<std::string>
Auxiliary_resolver::get_scripts_by_type(const std::vector<Script> &names, script_type_t type) {
    std::set<std::string> ret_val;
    for(auto item : names){
        std::string script_name = std::regex_replace(item.get_name(), std::regex("\\.tcl|\\.py"), "");
        std::shared_ptr<Script> scr = d_store->get_script(script_name);
        if(scr->get_type() == type) ret_val.insert(scr->get_path());

    }
    return ret_val;
}
