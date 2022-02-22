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

#include "data_model/bus_structure/bus_component.h"
#include "data_model/bus_structure/bus_module.h"
#include "data_model/bus_structure/bus_registers.h"

#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <memory>

class bus_crossbar : public bus_component{
public:
    bus_crossbar(std::vector<std::string> c, std::string p);
    explicit bus_crossbar(const std::string& serialized_obj);
    void add_child(const std::shared_ptr<bus_component>& c);

    std::vector<std::shared_ptr<bus_component>> get_children() {return children;};
    std::vector<std::string> get_raw_children_list() {return raw_children_list;};
    std::string to_string(std::string prefix) override;

    operator std::string();
    friend bool operator==(const bus_crossbar&lhs, const bus_crossbar&rhs);
private:
    std::vector<std::shared_ptr<bus_component>> children;
    std::vector<std::string> raw_children_list;

};


#endif //MAKEFILEGEN_V2_BUS_CROSSBAR_H
