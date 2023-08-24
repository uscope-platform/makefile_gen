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

#ifndef MAKEFILEGEN_V2_APPLICATION_DEFINITION_GENERATOR_HPP
#define MAKEFILEGEN_V2_APPLICATION_DEFINITION_GENERATOR_HPP

#include <string>
#include <utility>
#include <nlohmann/json.hpp>

#include "data_model/Depfile.hpp"
#include "data_model/data_store.hpp"

#include "data_model/HDL/HDL_instance.hpp"

class application_definition_generator {
public:
    explicit application_definition_generator(const std::shared_ptr<HDL_instance> &l);
    void add_cores(std::vector<processor_instance> cs);
    void write_definition_file(const std::string &path);
    void construct_application(const std::string &name);
private:

    void process_ast(const std::shared_ptr<HDL_instance> &l);
    void deduplicate_peripheral_names();
    void denormalize_addresses();
    static std::string uint_to_hex(uint32_t i);

    nlohmann::json application;
    std::vector<nlohmann::json> peripherals;

    std::vector<processor_instance> cores_spec;
    std::vector<nlohmann::json> cores;
};


#endif //MAKEFILEGEN_V2_APPLICATION_DEFINITION_GENERATOR_HPP
