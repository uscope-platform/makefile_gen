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

#ifndef MAKEFILEGEN_V2_MODULE_DOCUMENTATION_HPP
#define MAKEFILEGEN_V2_MODULE_DOCUMENTATION_HPP

#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <sstream>
#include <utility>
#include <cereal/types/vector.hpp>

#include "data_model/documentation/register_documentation.hpp"
#include "data_model/documentation/processor_instance.hpp"

class module_documentation {
public:
    module_documentation() = default;
    void add_register(const register_documentation& reg);
    void set_processor_io(std::vector<io> i) {processor_io = std::move(i);};
    void set_name(const std::string &n) {name = n;};
    std::vector<register_documentation> get_registers() {return  registers;};
    void set_alias(const std::string &a){ alias = a;};
    std::string get_alias(){return alias;};
    bool is_aliased(){return alias!="";};

    template<class Archive>
    void serialize(Archive & archive) {
        archive(name, registers, alias, processor_io);
    }

    friend bool operator==(const module_documentation&lhs, const module_documentation&rhs);
private:
    std::string name;
    std::string alias;
    std::vector<register_documentation> registers;
    std::vector<io> processor_io;

};


#endif //MAKEFILEGEN_V2_MODULE_DOCUMENTATION_HPP
