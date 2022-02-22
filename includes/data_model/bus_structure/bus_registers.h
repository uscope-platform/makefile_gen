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


#ifndef MAKEFILEGEN_V2_BUS_REGISTERS_H
#define MAKEFILEGEN_V2_BUS_REGISTERS_H

#include "data_model/bus_structure/bus_component.h"

#include <string>
#include <sstream>
#include <vector>
#include <utility>

class bus_registers : public bus_component{
public:
    bus_registers(std::string n, std::string p);
    explicit bus_registers(const std::string& serialized_obj);
    operator std::string();
    std::string to_string(std::string prefix) override;
    std::string get_name() {return name;};
    friend bool operator==(const bus_registers&lhs, const bus_registers&rhs);
private:
    std::string name;
};


#endif //MAKEFILEGEN_V2_BUS_REGISTERS_H
