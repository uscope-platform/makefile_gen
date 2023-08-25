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

#ifndef MAKEFILEGEN_V2_PERIPHERAL_DEFINITION_GENERATOR_HPP
#define MAKEFILEGEN_V2_PERIPHERAL_DEFINITION_GENERATOR_HPP

#include <memory>
#include <nlohmann/json.hpp>

#include "data_model/data_store.hpp"
#include "data_model/Depfile.hpp"

class peripheral_definition_generator {
public:
    peripheral_definition_generator(std::shared_ptr<data_store> &d, const std::shared_ptr<HDL_instance> &l);

    nlohmann::json get_peripheral_definitions() {return peripheral_defs;};
    std::map<std::string, std::string> get_alias_map() const{return alias_map;};
    void write_definition_file(const std::string &path);
    std::string get_definition_string();

private:

    void generate_peripheral(const HDL_Resource &res,const Parameters_map &parameters);
    nlohmann::json generate_field(field_documentation &doc, const Parameters_map &parameters);
    std::vector<nlohmann::json> generate_simple_module_registers(const std::vector<register_documentation> &r);
    std::vector<nlohmann::json> generate_parametric_module_registers(const std::vector<register_documentation> &r, const Parameters_map &parameters);

    uint32_t get_parameter_value(std::vector<std::string> s, const Parameters_map &parameters);
    std::string ver;
    std::shared_ptr<data_store> d_store;
    std::vector<HDL_Resource> submodules_to_generate;

    std::map<std::string, std::string> alias_map;

    nlohmann::json peripheral_defs;
};


#endif //MAKEFILEGEN_V2_PERIPHERAL_DEFINITION_GENERATOR_HPP
