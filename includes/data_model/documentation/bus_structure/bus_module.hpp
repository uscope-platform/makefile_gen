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


#ifndef MAKEFILEGEN_V2_BUS_MODULE_HPP
#define MAKEFILEGEN_V2_BUS_MODULE_HPP

#include "bus_component.hpp"


#include <memory>
#include <sstream>
#include <vector>
#include <string>

class bus_module : public bus_component{
    public:
    bus_module() = default;
    bus_module(std::string n, std::string t);
    std::string get_name() {return name;};
    std::string get_module_type() {return instance_type;};
    [[nodiscard]] uint32_t get_base_address() const {return base_address;};
    void  set_base_address(uint32_t ba) { base_address = ba;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, base_address, instance_type);
    }

    friend bool operator==(const bus_module&lhs, const bus_module&rhs);
private:
    std::string name;
    uint32_t base_address;
    std::string instance_type;
};

#include "third_party/cereal/types/polymorphic.hpp"
#include "third_party/cereal/archives/binary.hpp"

CEREAL_REGISTER_TYPE(bus_module);
CEREAL_REGISTER_POLYMORPHIC_RELATION(bus_component, bus_module)
#endif //MAKEFILEGEN_V2_BUS_MODULE_HPP
