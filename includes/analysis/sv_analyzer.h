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

#include "data_model/HDL_Resource.h"

#include "data_model/bus_structure/bus_registers.h"
#include "data_model/bus_structure/bus_crossbar.h"
#include "data_model/bus_structure/bus_module.h"


#include "mgp_sv/sv2017Lexer.h"
#include "mgp_sv/sv2017.h"
#include "analysis/sv_visitor.h"
#include "antlr4-runtime.h"

class sv_analyzer {
public:
    explicit sv_analyzer(const std::string& file_path);
    void cleanup_content(const std::string& regex);
    std::vector<std::shared_ptr<HDL_Resource>> analyze();

private:

    void analyze_package_docstings(std::unordered_map<std::string, uint32_t> parameters);
    void analyze_register(const std::string& docstring, const std::string& parameter_name, uint32_t address);
    void analyze_module(const std::string& docstring, const std::string& parameter_name, uint32_t address);
    void analyze_crossbar(const std::string& docstring, const std::string& parameter_name, uint32_t address, bool is_root);

    void construct_bus_hierarchy(std::shared_ptr<bus_crossbar> dict);

    std::unordered_map<std::string, std::shared_ptr<bus_registers>> registers_dict;
    std::unordered_map<std::string, std::shared_ptr<bus_module>> modules_dict;
    std::unordered_map<std::string, std::shared_ptr<bus_crossbar>> crossbar_dict;

    std::vector<std::shared_ptr<bus_crossbar>> bus_roots;
    std::string path;
    std::string processed_content;
    sv_visitor sv_modules_explorer;

    static std::string ltrim(const std::string &s) {
        size_t start = s.find_first_not_of(" \n\r\t\f\v");
        return (start == std::string::npos) ? "" : s.substr(start);
    }

    static std::string rtrim(const std::string &s) {
        size_t end = s.find_last_not_of(" \n\r\t\f\v");
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }

    static std::string trim(const std::string &s) {
        return rtrim(ltrim(s));
    }
};


class SvParserErrorListener : public antlr4::BaseErrorListener {
public:
    std::string file_path;
    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol, size_t line, size_t charPositionInLine,
                     const std::string &msg, std::exception_ptr e) override;
};
#endif //MAKEFILEGEN_V2_SV_ANALYZER_H
