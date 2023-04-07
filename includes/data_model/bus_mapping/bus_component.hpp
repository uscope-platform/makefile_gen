//  Copyright 2023 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef MAKEFILEGEN_V2_BUS_COMPONENT_HPP
#define MAKEFILEGEN_V2_BUS_COMPONENT_HPP

#include <string>
#include <unordered_map>
#include <third_party/json.hpp>
#include <iostream>

namespace bus_mapping{

    typedef enum{
        source = 0,
        sink = 1,
        interconnect = 2
    }bus_component_class;

    class bus_component {
    public:
        explicit bus_component(const std::string &name, nlohmann::json &comp_spec);
        void set_defaults(nlohmann::json &spec);
        friend bool operator==(const bus_component &lhs, const bus_component&rhs);
    private:
        bus_component_class component_class;
        std::unordered_map<std::string, std::string> component_specs;
        std::string name;
    };
}


#endif //MAKEFILEGEN_V2_BUS_COMPONENT_HPP
