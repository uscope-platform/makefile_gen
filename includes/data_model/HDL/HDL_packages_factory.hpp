// Copyright 2021 Filippo Savi
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

#ifndef MAKEFILEGEN_V2_HDL_PACKAGES_FACTORY_HPP
#define MAKEFILEGEN_V2_HDL_PACKAGES_FACTORY_HPP


#include "data_model/HDL/HDL_Resource.h"
#include "data_model/HDL/resource_factory_base.hpp"
#include "data_model/expression.h"


class HDL_packages_factory : protected resources_factory_base<HDL_Resource>{

public:
    void new_package(std::string &p);
    HDL_Resource get_package();
    void set_package_name(const std::string &n) { set_name(n);};
    void add_numeric_parameter(const std::string &name, uint32_t val);
    void add_string_parameter(const std::string &s);
    void add_unresolved_parameter(expression p) {unresolved_parameters.push_back(p);};
    uint32_t get_numeric_parameter(const std::string &name){ return numeric_parameters[name];};
    bool numeric_parameter_exists(const std::string &name) {return numeric_parameters.count(name)>0;};
private:
    void calculate_unresolved_parameters();
    static uint32_t calculate_expression(std::vector<std::string> exp);
    std::vector<expression> unresolved_parameters;
    std::unordered_map<std::string, uint32_t> numeric_parameters;

};


#endif //MAKEFILEGEN_V2_HDL_PACKAGES_FACTORY_HPP
