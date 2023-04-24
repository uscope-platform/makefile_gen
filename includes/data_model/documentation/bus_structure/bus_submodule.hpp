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
#ifndef MAKEFILEGEN_V2_BUS_SUBMODULE_HPP
#define MAKEFILEGEN_V2_BUS_SUBMODULE_HPP


#include <utility>

#include "data_model/documentation/bus_structure/bus_component.hpp"

class bus_submodule : public bus_component{
public:
    bus_submodule() = default;
    std::string get_name() {return name;};
    void set_name(std::string n) {name = std::move(n);};

    std::string get_module_type() {return instance_type;};
    void set_module_type(const std::string t);

    void add_child(const bus_submodule& sub){children.push_back(sub);};
    std::vector<bus_submodule> get_children() {return children;};

    [[nodiscard]] uint32_t get_offset() const {return offset;};
    void  set_offset(uint32_t o) { offset = o;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, offset, instance_type);
    }

    friend bool operator==(const bus_submodule&lhs, const bus_submodule&rhs);
private:
    std::string name;
    std::string instance_type;
    std::vector<bus_submodule> children;
    uint32_t offset;

};

#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>

CEREAL_REGISTER_TYPE(bus_submodule);
CEREAL_REGISTER_POLYMORPHIC_RELATION(bus_component, bus_submodule)


#endif //MAKEFILEGEN_V2_BUS_SUBMODULE_HPP
