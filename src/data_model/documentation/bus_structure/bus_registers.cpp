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

bus_registers::bus_registers(const std::string &serialized_obj) {
    std::istringstream ss(serialized_obj);
    std::vector<std::string> tokens;

    std::string tmp;
    while(std::getline(ss, tmp, ',')) {
        tokens.push_back(tmp);
    }
    name = std::string(tokens[0]);
    parameter_name =  std::string(tokens[1]);
    base_address = std::stoul(tokens[2]);
    type = component_type(std::stoi(tokens[3]));
}

std::string bus_registers::to_string(std::string prefix) {
    return prefix + name + " [registers] -- " + parameter_name + " -- " + std::to_string(base_address);
}



bus_registers::operator std::string() {
    std::ostringstream tmp;
    tmp << name << "," << parameter_name << "," << std::to_string(base_address) << "," << component_type_to_integer(type);
    return tmp.str();
}

bool operator==(const bus_registers &lhs, const bus_registers &rhs) {
    bool res = true;
    res &= lhs.name == rhs.name;
    res &= lhs.base_address == rhs.base_address;
    res &= lhs.parameter_name == rhs.parameter_name;
    res &= lhs.type == rhs.type;
    return res;
}

