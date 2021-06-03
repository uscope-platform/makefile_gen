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
    bool is_excluded = std::find(excluded_modules.begin(), excluded_modules.end(), module_name) != excluded_modules.end();
    auto module = d_store->get_HDL_resource(module_name);

    if(!(is_excluded || module->is_interface())) {
        auto deps = module->get_dependencies();
        dependencies.insert(deps.begin(), deps.end());
        for(auto &item : deps){
            get_dependencies(item.first);
        }
    }

}

void Dependency_resolver::set_excluded_modules(std::vector<std::string> exclusion_list) {
    excluded_modules = std::move(exclusion_list);
}
