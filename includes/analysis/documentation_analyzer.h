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

#include "data_model/bus_structure/bus_structure.h"
#include "mgp_sv/sv2017Lexer.h"
#include "mgp_sv/sv2017.h"

#include "third_party/json.hpp"

class documentation_analyzer {
public:
    explicit documentation_analyzer(std::string &s, std::unordered_map<std::string, uint32_t> parameters);
    std::vector<std::shared_ptr<bus_crossbar>> get_bus_roots();
private:
    void analyze_documentation_object(nlohmann::json &obj);
    void construct_bus_hierarchy(const std::shared_ptr<bus_crossbar>& dict);
    void analyze_register(nlohmann::json &obj);
    void analyze_module(nlohmann::json &obj);
    void analyze_crossbar(nlohmann::json &obj, bool is_root);

    std::unordered_map<std::string, uint32_t> parameters_dict;

    std::vector<nlohmann::json> documentation_comments;

    std::unordered_map<std::string, std::shared_ptr<bus_registers>> registers_dict;
    std::unordered_map<std::string, std::shared_ptr<bus_module>> modules_dict;
    std::unordered_map<std::string, std::shared_ptr<bus_crossbar>> crossbar_dict;

    std::vector<std::shared_ptr<bus_crossbar>> bus_roots;

};


#endif //MAKEFILEGEN_V2_DOCUMENTATION_ANALYZER_H
