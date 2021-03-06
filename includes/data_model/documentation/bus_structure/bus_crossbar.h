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


#ifndef MAKEFILEGEN_V2_BUS_CROSSBAR_H
#define MAKEFILEGEN_V2_BUS_CROSSBAR_H

#include "bus_component.h"
#include "bus_module.h"

#include "third_party/cereal/types/vector.hpp"
#include "third_party/cereal/types/memory.hpp"


#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <memory>

class bus_crossbar : public bus_component{
public:
    bus_crossbar() = default;
    bus_crossbar(std::string p);
    void set_target(const std::string &t) {target = t;};
    std::string get_target() {return target;};
    void set_parameter(std::string p) {parameter_name = std::move(p);};
    std::string get_parameter() {return parameter_name;};

    void add_child(const std::shared_ptr<bus_component>& c);

    [[nodiscard]] uint32_t get_base_address() const {return base_address;};
    void  set_base_address(uint32_t ba) { base_address = ba;};

    std::vector<std::shared_ptr<bus_component>> get_children() {return children;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(base_address, parameter_name, children);
    }


    friend bool operator==(const bus_crossbar&lhs, const bus_crossbar&rhs);
private:
    std::vector<std::shared_ptr<bus_component>> children;
    uint32_t base_address;
    std::string parameter_name;
    std::string target;

};

#include "third_party/cereal/types/polymorphic.hpp"
#include "third_party/cereal/archives/binary.hpp"

CEREAL_REGISTER_TYPE(bus_crossbar);
CEREAL_REGISTER_POLYMORPHIC_RELATION(bus_component, bus_crossbar)
#endif //MAKEFILEGEN_V2_BUS_CROSSBAR_H
