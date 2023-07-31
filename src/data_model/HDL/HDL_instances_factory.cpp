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

#include "data_model/HDL/HDL_instances_factory.hpp"


void HDL_instances_factory::new_dependency(const std::string &n, const std::string &p, dependency_class dc) {
    current_instance = HDL_instance(n, p, dc);
    valid_instance = true;
}

void HDL_instances_factory::add_parameter(const std::string &name, const HDL_parameter &p) {
    current_instance.add_parameter(name, p);
}

void HDL_instances_factory::add_port(const std::string &name, const std::string &value) {
    current_instance.add_port_connection(name, value);
}

HDL_instance HDL_instances_factory::get_dependency() {
    valid_instance = false;
    return current_instance;
}

void HDL_instances_factory::add_array_quantifier(const expression &exp) {
    current_instance.add_array_quantifier(exp);
}