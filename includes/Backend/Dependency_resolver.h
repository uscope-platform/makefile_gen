// Copyright 2021 University of Nottingham Ningbo China
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MAKEFILEGEN_V2_DEPENDENCY_RESOLVER_H
#define MAKEFILEGEN_V2_DEPENDENCY_RESOLVER_H

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

#include "data_model/data_store.h"

class Dependency_resolver {
public:
    Dependency_resolver(std::string tl, std::shared_ptr<data_store> store);
    std::set<std::string> get_dependencies();
    void set_excluded_modules(std::vector<std::string> exclusion_list);
    void add_explicit_dependencies(const std::vector<std::string>& dep_list);

private:
    std::vector<HDL_Resource> hdl_dependencies;
    std::vector<DataFile> mem_init_dependencies;
    void resolve_dependencies(const std::string& module_name);

    std::vector<std::string> excluded_modules;
    std::shared_ptr<data_store> d_store;
    std::string top_level;
};


#endif //MAKEFILEGEN_V2_DEPENDENCY_RESOLVER_H
