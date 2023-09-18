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

#include "data_model/HDL/HDL_interfaces_factory.hpp"


void HDL_interfaces_factory::new_interface(std::string &p) {
    resources_factory_base<HDL_Resource>::new_basic_resource();
    current_resource.set_path(p);
    current_resource.set_type(interface);
}

HDL_Resource HDL_interfaces_factory::get_interface() {
    return resources_factory_base<HDL_Resource>::get_resource();
}

void HDL_interfaces_factory::add_parameter(const std::shared_ptr<HDL_parameter> &p) {
    current_resource.add_parameter(p);
}

