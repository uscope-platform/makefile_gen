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


#ifndef MAKEFILEGEN_V2_BUS_COMPONENT_H
#define MAKEFILEGEN_V2_BUS_COMPONENT_H

#include <string>
#include <utility>
#include <memory>

#define BUS_CROSSBAR_TYPE 0
#define BUS_REGISTER_TYPE 1
#define BUS_MODULE_TYPE 2

enum component_type {bus_crossbar_t=BUS_CROSSBAR_TYPE, bus_register_t=BUS_REGISTER_TYPE,bus_module_t=BUS_MODULE_TYPE};


class bus_component {
public:
    bus_component(std::string n, component_type t);
    virtual std::string to_string(std::string prefix) {return "";};
    [[nodiscard]] uint32_t get_base_address() const {return base_address;};
    void  set_base_address(uint32_t ba) { base_address = ba;};
    static std::string component_to_string(const std::shared_ptr<bus_component>& p) { return component_to_string(p, "");};
    static std::string component_to_string(const std::shared_ptr<bus_component>& p, const std::string& prefix);
protected:
    std::string parameter_name;
    uint32_t base_address;
    component_type type;


};


#endif //MAKEFILEGEN_V2_BUS_COMPONENT_H
