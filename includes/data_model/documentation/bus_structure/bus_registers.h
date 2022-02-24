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

#include "bus_component.h"

#include <string>
#include <sstream>
#include <vector>
#include <utility>

class bus_registers : public bus_component{
public:
    bus_registers() = default;
    bus_registers(std::string n, std::string p);


    [[nodiscard]] uint32_t get_base_address() const {return base_address;};
    void  set_base_address(uint32_t ba) { base_address = ba;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, parameter_name, base_address);
    }

    std::string pretty_print(std::string prefix);
    std::string get_name() {return name;};
    friend bool operator==(const bus_registers&lhs, const bus_registers&rhs);
private:
    std::string name;
    std::string parameter_name;
    uint32_t base_address;
};

#include "third_party/cereal/types/polymorphic.hpp"
#include "third_party/cereal/archives/binary.hpp"

CEREAL_REGISTER_TYPE(bus_registers);
CEREAL_REGISTER_POLYMORPHIC_RELATION(bus_component, bus_registers)
#endif //MAKEFILEGEN_V2_BUS_REGISTERS_H
