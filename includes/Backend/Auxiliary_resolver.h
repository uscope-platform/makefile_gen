//
// Created by fils on 06/06/2021.
//

#ifndef MAKEFILEGEN_V2_AUXILIARY_RESOLVER_H
#define MAKEFILEGEN_V2_AUXILIARY_RESOLVER_H

#include <utility>
#include <set>
#include <vector>
#include <regex>

#include "data_model/data_store.h"

class Auxiliary_resolver {
public:
    explicit Auxiliary_resolver(std::shared_ptr<data_store> store);
    std::set<std::string> get_tcl_scripts(const std::vector<Script> &names);
    std::set<std::string> get_python_scripts(const std::vector<Script> &names);
    std::set<std::string> get_constraints(const std::vector<Constraints> &names);
private:
    std::set<std::string> get_scripts_by_type(const std::vector<Script> &names, script_type_t type);
    std::shared_ptr<data_store> d_store;
};


#endif //MAKEFILEGEN_V2_AUXILIARY_RESOLVER_H
