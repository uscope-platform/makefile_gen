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


#include "data_model/bus_structure/bus_component.h"

#include "data_model/bus_structure/bus_crossbar.h"
#include "data_model/bus_structure/bus_module.h"
#include "data_model/bus_structure/bus_registers.h"

bus_component::bus_component(std::string n, component_type t) {
    type = t;
    base_address = 0;
    parameter_name = std::move(n);
}

std::string bus_component::component_to_string(const std::shared_ptr<bus_component>& p, const std::string& prefix) {
    std::string ret;
    switch (p->type) {
        case bus_crossbar_t:
            ret = std::static_pointer_cast<bus_crossbar>(p)->to_string(prefix);
            break;
        case bus_register_t:
            ret = std::static_pointer_cast<bus_registers>(p)->to_string(prefix);
            break;
        case bus_module_t:
            ret = std::static_pointer_cast<bus_module>(p)->to_string(prefix);
            break;
        default:
            break;
    }
    return ret;
}
