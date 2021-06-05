//
// Created by fils on 03/06/2021.
//

#ifndef MAKEFILEGEN_V2_DEPENDENCY_RESOLVER_H
#define MAKEFILEGEN_V2_DEPENDENCY_RESOLVER_H

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#include "data_model/data_store.h"

class Dependency_resolver {
public:
    Dependency_resolver(std::string tl, std::shared_ptr<data_store> store);
    std::set<std::string> get_dependencies();
    void set_excluded_modules(std::vector<std::string> exclusion_list);

private:
    std::vector<std::shared_ptr<HDL_Resource>> dependencies;
    void resolve_dependencies(const std::string& module_name);

    std::vector<std::string> excluded_modules;
    std::shared_ptr<data_store> d_store;
    std::string top_level;
};


#endif //MAKEFILEGEN_V2_DEPENDENCY_RESOLVER_H
