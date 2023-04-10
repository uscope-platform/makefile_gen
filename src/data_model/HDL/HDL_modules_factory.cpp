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

#include "data_model/HDL/HDL_modules_factory.hpp"


void HDL_modules_factory::new_module(std::string &p) {
    resources_factory_base<HDL_Resource>::new_resource(p);
    current_resource.set_type(module);
}

void HDL_modules_factory::add_instance(const HDL_dependency &i) {

    current_resource.add_dependency(i);
}

void HDL_modules_factory::add_interface_dep(const HDL_dependency &i) {
    current_resource.add_dependency(i);
}

void HDL_modules_factory::add_mem_file_dep(const HDL_dependency &i) {
    current_resource.add_dependency(i);
}

void HDL_modules_factory::add_package_dep(const HDL_dependency &i) {
    current_resource.add_dependency(i);
}

void HDL_modules_factory::add_port(const std::string &p_n, port_direction_t dir) {
    current_resource.add_ports(p_n, dir);
}


HDL_Resource HDL_modules_factory::get_module() {
    return resources_factory_base<HDL_Resource>::get_resource();
}

void
HDL_modules_factory::add_if_port_specs(const std::string &p_n, const std::string &if_name, const std::string &modport) {
    current_resource.add_if_port_specs(p_n, if_name, modport);
}

void HDL_modules_factory::add_parameter(const std::string &p_n, const std::string &v) {
    current_resource.add_string_parameter(p_n, v);
}



