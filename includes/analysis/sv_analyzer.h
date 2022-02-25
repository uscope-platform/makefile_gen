// Copyright 2021 University of Nottingham Ningbo China
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

#ifndef MAKEFILEGEN_V2_SV_ANALYZER_H
#define MAKEFILEGEN_V2_SV_ANALYZER_H

#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <vector>

#include "third_party/json.hpp"
#include "data_model/HDL_Resource.h"
#include "data_model/documentation/bus_structure/bus_registers.h"
#include "data_model/documentation/bus_structure/bus_crossbar.h"
#include "data_model/documentation/bus_structure/bus_module.h"
#include "analysis/documentation_analyzer.h"

#include "mgp_sv/sv2017Lexer.h"
#include "mgp_sv/sv2017.h"
#include "analysis/sv_visitor.h"
#include "antlr4-runtime.h"

class sv_analyzer {
public:
    explicit sv_analyzer(const std::string& file_path);
    void cleanup_content(const std::string& regex);
    std::vector<HDL_Resource> analyze();

private:

    void process_hdl();
    void search_bus_defining_package(std::string &content);


    std::unordered_map<std::string, uint32_t> parameters;

    std::string path;
    std::string processed_content;
    sv_visitor sv_modules_explorer;
    bool is_bus_defining_package;
    HDL_Resource package_ptr;

};


class SvParserErrorListener : public antlr4::BaseErrorListener {
public:
    std::string file_path;
    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol, size_t line, size_t charPositionInLine,
                     const std::string &msg, std::exception_ptr e) override;
};
#endif //MAKEFILEGEN_V2_SV_ANALYZER_H
