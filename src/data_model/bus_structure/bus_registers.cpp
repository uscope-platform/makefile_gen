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


#include "data_model/bus_structure/bus_registers.h"



bus_registers::bus_registers(std::string n, std::string p) : bus_component(std::move(p), bus_register_t){
    name = std::move(n);
}

std::string bus_registers::to_string(std::string prefix) {
    return prefix + name + " [registers] -- " + parameter_name + " -- " + std::to_string(base_address);
}

