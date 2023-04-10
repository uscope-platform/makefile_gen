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

#ifndef MAKEFILEGEN_V2_HDL_MODULES_FACTORY_HPP
#define MAKEFILEGEN_V2_HDL_MODULES_FACTORY_HPP

#include "data_model/HDL/HDL_Resource.hpp"
#include "data_model/HDL/resource_factory_base.hpp"

#include "data_model/HDL/HDL_dependency.hpp"

class HDL_modules_factory : protected resources_factory_base<HDL_Resource> {

public:
    void new_module(std::string &p);
    HDL_Resource get_module();
    void set_module_name(const std::string &n) { set_name(n);};

    void add_instance(const HDL_dependency &i);
    void add_interface_dep(const HDL_dependency &i);
    void add_mem_file_dep(const HDL_dependency &i);
    void add_package_dep(const HDL_dependency &i);

    void add_parameter(const std::string&p_n, const std::string &v);

    void add_port(const std::string &p_n, port_direction_t dir);
    void add_if_port_specs(const std::string &p_n,const std::string &if_name, const std::string &modport);
    bool is_current_valid() {return valid_resource;};
};


#endif //MAKEFILEGEN_V2_HDL_MODULES_FACTORY_HPP
