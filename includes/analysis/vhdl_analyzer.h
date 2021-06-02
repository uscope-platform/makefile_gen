//
// Created by fils on 30/05/2021.
//

#ifndef MAKEFILEGEN_V2_VHDL_ANALYZER_H
#define MAKEFILEGEN_V2_VHDL_ANALYZER_H

#include <string>
#include <vector>
#include <fstream>

#include "data_model/HDL_Resource.h"
#include "vhdl_visitor.h"
#include "antlr4-runtime.h"
#include "mgp_vh/vhdlLexer.h"
#include "mgp_vh/vhdlParser.h"

class vhdl_analyzer {

public:
    explicit vhdl_analyzer(const std::string& file_path);
    void cleanup_content(const std::string& regex);
    std::vector<HDL_Resource> analyze();

private:
    std::string path;
    std::string processed_content;
    vhdl_visitor vhdl_modules_explorer;


};

class VhParserErrorListener : public antlr4::BaseErrorListener {
public:
    std::string file_path;
    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol, size_t line, size_t charPositionInLine,
                             const std::string &msg, std::exception_ptr e) override;
};

#endif //MAKEFILEGEN_V2_VHDL_ANALYZER_H
