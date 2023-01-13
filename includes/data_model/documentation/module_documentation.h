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

#ifndef MAKEFILEGEN_V2_MODULE_DOCUMENTATION_H
#define MAKEFILEGEN_V2_MODULE_DOCUMENTATION_H

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <utility>

#include "third_party/cereal/types/vector.hpp"
#include "data_model/documentation/register_documentation.h"
#include "data_model/documentation/bus_structure/bus_crossbar.h"
#include "data_model/documentation/processor_instance.h"

class module_documentation {
public:
    module_documentation() = default;
    void add_register(const register_documentation& reg);
    void set_processor_io(std::vector<io> i) {processor_io = i;};
    void set_name(const std::string &n) {name = n;};
    std::vector<register_documentation> get_registers() {return  registers;};

    template<class Archive>
    void serialize(Archive & archive) {
        archive(name, registers, processor_io);
    }

    friend bool operator==(const module_documentation&lhs, const module_documentation&rhs);
private:
    std::string name;
    std::vector<register_documentation> registers;
    std::vector<io> processor_io;

};


#endif //MAKEFILEGEN_V2_MODULE_DOCUMENTATION_H
