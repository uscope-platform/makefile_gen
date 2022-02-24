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


#include "data_model/documentation/bus_structure/bus_registers.h"



bus_registers::bus_registers(std::string n, std::string p){
    name = std::move(n);
    parameter_name = std::move(p);
    base_address = 0;
}


std::string bus_registers::pretty_print(std::string prefix) {
    return prefix + name + " [registers] -- " + parameter_name + " -- " + std::to_string(base_address);
}


bool operator==(const bus_registers &lhs, const bus_registers &rhs) {
    bool res = true;
    res &= lhs.name == rhs.name;
    res &= lhs.base_address == rhs.base_address;
    res &= lhs.parameter_name == rhs.parameter_name;
    return res;
}

