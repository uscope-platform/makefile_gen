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


#include "data_model/documentation/bus_structure/bus_component.hpp"

#include "data_model/documentation/bus_structure/bus_crossbar.hpp"
#include "data_model/documentation/bus_structure/bus_module.hpp"
#include "data_model/documentation/bus_structure/bus_submodule.hpp"
#include "data_model/bus_mapping/bus_component.hpp"


bool bus_component::compare(std::shared_ptr<bus_component> &lhs, std::shared_ptr<bus_component> &rhs) {
    bool ret = true;
    auto&  ptr_l = *lhs;
    auto&  ptr_r = *rhs;

    ret &= typeid(ptr_l) == typeid(ptr_r);
    if (typeid(lhs) == typeid(bus_crossbar)) {
        ret &= *std::static_pointer_cast<bus_crossbar>(lhs) == *std::static_pointer_cast<bus_crossbar>(rhs);
    } else if(typeid(lhs) == typeid(bus_module)) {
        ret &= *std::static_pointer_cast<bus_module>(lhs) == *std::static_pointer_cast<bus_module>(rhs);
    } else if(typeid(lhs) == typeid(bus_submodule)){
        ret &= *std::static_pointer_cast<bus_submodule>(lhs) == *std::static_pointer_cast<bus_submodule>(rhs);
    }
    return ret;
}

bool bus_component::compare(const std::shared_ptr<bus_component> &lhs, const std::shared_ptr<bus_component> &rhs) {
    bool ret = true;
    auto&  ptr_l = *lhs;
    auto&  ptr_r = *rhs;

    ret &= typeid(ptr_l) == typeid(ptr_r);
    if (typeid(ptr_l) == typeid(bus_crossbar)) {
        ret &= *std::static_pointer_cast<bus_crossbar>(lhs) == *std::static_pointer_cast<bus_crossbar>(rhs);
    } else if(typeid(ptr_l) == typeid(bus_module)) {
        ret &= *std::static_pointer_cast<bus_module>(lhs) == *std::static_pointer_cast<bus_module>(rhs);
    } else if(typeid(lhs) == typeid(bus_submodule)){
        ret &= *std::static_pointer_cast<bus_submodule>(lhs) == *std::static_pointer_cast<bus_submodule>(rhs);
    }
    return ret;
}
