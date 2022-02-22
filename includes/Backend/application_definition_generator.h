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

#ifndef MAKEFILEGEN_V2_APPLICATION_DEFINITION_GENERATOR_H
#define MAKEFILEGEN_V2_APPLICATION_DEFINITION_GENERATOR_H

#include <string>
#include <utility>


#include "third_party/json.hpp"
#include "data_model/Depfile.h"
#include "data_model/bus_structure/bus_structure.h"
#include "data_model/data_store.h"

class application_definition_generator {
public:
    explicit application_definition_generator(const Depfile& file, std::shared_ptr<data_store> store);
    void write_definition_file(const std::string &path);
private:
    void construct_application();
    void walk_bus_structure(const std::shared_ptr<bus_crossbar>& node);
    nlohmann::json generate_peripheral(std::shared_ptr<bus_module> m);
    nlohmann::json generate_peripheral(std::shared_ptr<bus_registers> r);
    static std::string uint_to_hex(uint32_t i);
    Depfile dep;

    std::shared_ptr<data_store> d_store;
    nlohmann::json application;
    std::shared_ptr<bus_crossbar> bus_root;
    std::vector<nlohmann::json> peripherals;
};


#endif //MAKEFILEGEN_V2_APPLICATION_DEFINITION_GENERATOR_H
