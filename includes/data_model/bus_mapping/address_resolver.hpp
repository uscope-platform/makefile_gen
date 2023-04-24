//  Copyright 2023 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef MAKEFILEGEN_V2_ADDRESS_RESOLVER_HPP
#define MAKEFILEGEN_V2_ADDRESS_RESOLVER_HPP


#include <string>
#include <regex>

#include "data_model/HDL/HDL_Resource.hpp"

class address_resolver {
public:
    explicit address_resolver(const HDL_Resource &bdp);
    void push_parameters_map(HDL_dependency &instance);
    void pop_parameters_map();
    uint32_t get_address(const std::string &str, HDL_Resource &parent_res, HDL_dependency &parent_dep);
    uint32_t get_address(const std::string &str, HDL_Resource &parent_res, HDL_dependency &parent_dep, int stack_level);
    bool is_sv_constant(const std::string &s);
    uint32_t parse_sv_constant(const std::string &s);
private:

    HDL_Resource bus_defining_package;
    std::vector<std::unordered_map<std::string, std::string>> parameters_stack;
};

#endif //MAKEFILEGEN_V2_ADDRESS_RESOLVER_HPP
