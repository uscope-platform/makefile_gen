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

#ifndef MAKEFILEGEN_V2_DOCUMENTATION_ANALYZER_H
#define MAKEFILEGEN_V2_DOCUMENTATION_ANALYZER_H

#include <sstream>
#include <utility>
#include <antlr4-runtime.h>
#include <regex>

#include "data_model/documentation/bus_structure/bus_structure.h"
#include "data_model/documentation/module_documentation.h"
#include "data_model/documentation/register_documentation.h"
#include "data_model//documentation/processor_instance.h"
#include "mgp_sv/sv2017Lexer.h"
#include "mgp_sv/sv2017.h"

#include "third_party/json.hpp"

class documentation_analyzer {
public:
    explicit documentation_analyzer(std::string &s);
    explicit documentation_analyzer(std::istream &stream);
    void parse_documentation(std::istream &stream);
    void set_source_path(std::string &f_path) {path = f_path;};
    void process_documentation(std::unordered_map<std::string, uint32_t> parameters);
    std::vector<std::shared_ptr<bus_crossbar>> get_bus_roots();
    std::unordered_map<std::string, std::vector<bus_submodule>> get_bus_submodules();
    std::unordered_map<std::string, module_documentation> get_modules_documentation();
    std::unordered_map<std::string, processor_instance> get_processors_documentation();
private:
    void analyze_documentation_object(nlohmann::json &obj);
    void analyze_bus_hierarchy(nlohmann::json &obj);
    void analyze_module_hierarchy(nlohmann::json &obj);
    // BUS STRUCTURE DOCUMENTATION
    std::shared_ptr<bus_module> analyze_module(nlohmann::json &obj);
    bus_submodule analyze_submodule(nlohmann::json &obj);
    field_documentation analyze_register_field(nlohmann::json &obj);
    std::shared_ptr<bus_crossbar> analyze_crossbar(nlohmann::json &obj);
    // PERIPHERAL DOCUMENTATION
    void analyze_peripheral(nlohmann::json &obj);
    // PROCESSORS DOCUMENTATION
    void analyze_processor_instance(nlohmann::json &obj);

    std::unordered_map<std::string, uint32_t> parameters_dict;

    std::vector<std::string> raw_documentation_comments;

    std::vector<std::shared_ptr<bus_crossbar>> bus_roots;
    std::unordered_map<std::string, std::vector<bus_submodule>> bus_submodules;
    std::unordered_map<std::string, module_documentation> modules_doc;
    std::unordered_map<std::string, processor_instance> processors;
    std::string path;
};


#endif //MAKEFILEGEN_V2_DOCUMENTATION_ANALYZER_H
