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


#include "data_model/documentation/bus_structure/bus_module.hpp"

#include <utility>

bus_module::bus_module(std::string n, std::string t) {
    instance_type = std::move(t);
    base_address = 0;
    name = std::move(n);
}

bool operator==(const bus_module &lhs, const bus_module &rhs) {
    bool res = true;
    res &= lhs.name == rhs.name;
    res &= lhs.instance_type == rhs.instance_type;
    res &= lhs.base_address == rhs.base_address;
    return res;
}
