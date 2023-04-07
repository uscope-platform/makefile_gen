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

#ifndef MAKEFILEGEN_V2_HDL_DEPENDENCY_HPP
#define MAKEFILEGEN_V2_HDL_DEPENDENCY_HPP

#include <unordered_map>
#include <string>
#include <utility>

#include "data_model/HDL/HDL_definitions.hpp"

#include "third_party/cereal/archives/binary.hpp"
#include "third_party/cereal/types/unordered_map.hpp"
#include "third_party/cereal/types/vector.hpp"
#include "third_party/cereal/types/memory.hpp"

class HDL_dependency {
public:
    HDL_dependency(std::string dep_name, std::string dep_type, dependency_class d_c);
    HDL_dependency() = default;

    void add_parameter(const std::string& parameter_name, std::string value);
    void add_port_connection(const std::string& port_name, std::string value);

    std::string get_name() const {return name;} ;
    std::string get_type() const {return type;};
    dependency_class get_dependency_class() const {return dep_class;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name,type, dep_class, ports_map, parameters_map);
    }

    friend bool operator==(const HDL_dependency&lhs, const HDL_dependency&rhs);
private:
    std::unordered_map<std::string, std::string> parameters_map;
    std::unordered_map<std::string, std::string> ports_map;
    dependency_class dep_class;
    std::string type;
    std::string name;
};


#endif //MAKEFILEGEN_V2_HDL_DEPENDENCY_HPP
