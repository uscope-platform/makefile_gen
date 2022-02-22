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


#ifndef MAKEFILEGEN_V2_BUS_MODULE_H
#define MAKEFILEGEN_V2_BUS_MODULE_H

#include "data_model/bus_structure/bus_component.h"

#include <memory>
#include <sstream>
#include <vector>
#include <string>

class bus_module : public bus_component{
    public:
    bus_module(std::string n, std::string t, std::string p);
    explicit bus_module(const std::string& serialized_obj);
    std::string get_name() {return name;};
    std::string get_module_type() {return instance_type;};
    std::string to_string(std::string prefix) override;

    operator std::string();
    friend bool operator==(const bus_module&lhs, const bus_module&rhs);
private:
    std::string name;
    std::string instance_type;
};


#endif //MAKEFILEGEN_V2_BUS_MODULE_H
