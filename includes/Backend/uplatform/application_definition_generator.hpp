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

#include "data_model/HDL/HDL_instance_AST.hpp"

class application_definition_generator {
public:
    explicit application_definition_generator(
            const std::shared_ptr<HDL_instance_AST> &l,
            const nlohmann::json &p,
            const std::map<std::string, std::string> &a
    );
    void add_cores(std::vector<processor_instance> cs);
    void add_datapoints(const std::vector<nlohmann::json>& dp);
    void write_definition_file(const std::string &path);
    void construct_application(const std::string &name);
    std::string get_definition_string();

private:
    std::map<std::string, uint32_t> get_parameters(const nlohmann::json &spec, std::shared_ptr<HDL_instance_AST> &node);
    void process_ast(const std::shared_ptr<HDL_instance_AST> &l);
    void deduplicate_peripheral_names();
    void denormalize_addresses();
    static std::string uint_to_hex(uint32_t i);

    nlohmann::json application;
    std::vector<nlohmann::json> peripherals;

    std::vector<processor_instance> cores_spec;
    std::vector<nlohmann::json> cores;

    nlohmann::json periph_defs;
    std::map<std::string, std::string> alias_map;

};


#endif //MAKEFILEGEN_V2_APPLICATION_DEFINITION_GENERATOR_HPP
