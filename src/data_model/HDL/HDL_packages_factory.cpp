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

#include "data_model/HDL/HDL_packages_factory.hpp"


void HDL_packages_factory::new_package(std::string &p) {
    resources_factory_base<HDL_Resource>::new_basic_resource();
    current_resource.set_path(p);
    current_resource.set_type(package);
}

HDL_Resource HDL_packages_factory::get_package() {
    calculate_unresolved_parameters();
    current_resource.set_parameters(parameters);
    return resources_factory_base<HDL_Resource>::get_resource();
}

void HDL_packages_factory::add_numeric_parameter(const std::string &name, uint32_t val) {
    HDL_parameter p;
    p.set_name(name);
    p.set_value(val);
    parameters[name] = p;
}

void HDL_packages_factory::calculate_unresolved_parameters() {
    parameters = expression_evaluator::calculate_expressions(unresolved_parameters, parameters);
}


void HDL_packages_factory::add_string_parameter(const std::string &s) {

}

uint32_t HDL_packages_factory::get_numeric_parameter(const std::string &name) {
    return parameters[name].get_numeric_value();
}

