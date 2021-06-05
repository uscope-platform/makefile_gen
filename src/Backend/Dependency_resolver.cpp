//
// Created by fils on 03/06/2021.
//

#include "Backend/Dependency_resolver.h"

Dependency_resolver::Dependency_resolver(std::string tl, std::shared_ptr<data_store> store) {
    top_level = std::move(tl);
    d_store = std::move(store);
}

std::vector<std::string> Dependency_resolver::get_dependencies() {
    get_dependencies(top_level);
    return std::vector<std::string>();
}

void Dependency_resolver::get_dependencies(const std::string& module_name) {
    // Excluded modules and primitives are not defined and thus get a reference to a null pointer, we must exit early from the function to avoid dereferencing it
    bool is_excluded = std::find(excluded_modules.begin(), excluded_modules.end(), module_name) != excluded_modules.end();
    bool is_primitive = d_store->is_primitive(module_name);
    if(is_excluded || is_primitive) return;

    //  interfaces never have dependencies so we can exit
    bool is_interface = d_store->get_HDL_resource(module_name)->is_interface();
    if(is_interface) return;

    hdl_deps_t deps =  d_store->get_HDL_resource(module_name)->get_dependencies();

    for(auto &item : deps){
        auto res = d_store->get_HDL_resource(item.first);
        dependencies.push_back(res);
        get_dependencies(item.first);
    }


}

void Dependency_resolver::set_excluded_modules(std::vector<std::string> exclusion_list) {
    excluded_modules = std::move(exclusion_list);
}
