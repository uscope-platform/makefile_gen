//  Copyright 2026 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "frontend/analysis/vhdl/vhdl_analyzer.hpp"

#include <sstream>

vhdl_analyzer::vhdl_analyzer(const std::string &file_path): vhdl_modules_explorer(file_path) {
    path = file_path;

}

void vhdl_analyzer::cleanup_content(const std::string &regex) {
    std::ifstream t(path);


    t.seekg(0, std::ios::end);
    processed_content.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    processed_content.assign((std::istreambuf_iterator<char>(t)),
                       std::istreambuf_iterator<char>());


}

hdl_file vhdl_analyzer::analyze() {

    std::istringstream istream(processed_content);


    antlr4::ANTLRInputStream antlr_istream(istream);
    mgp_vh::vhdlLexer lexer(&antlr_istream);
    antlr4::CommonTokenStream tok_stream(&lexer);

    tok_stream.fill();

    VhParserErrorListener error_listener;
    error_listener.file_path = path;
    mgp_vh::vhdlParser parser(&tok_stream);
    parser.removeErrorListeners();
    parser.addErrorListener(&error_listener);

    antlr4::tree::ParseTree *Tree = parser.design_file();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&vhdl_modules_explorer, Tree);
    hdl_file result;
    result.set_content(vhdl_modules_explorer.get_entities());
    return  result;
}

hdl_file vhdl_analyzer::analyze_content(const std::string &content, const std::string &src_path) {
    path = src_path;
    processed_content = content;
    return analyze();
}

void VhParserErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                      size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
    // Standardized compiler-style error header (file:line:column: error: message)
    std::cerr << this->file_path << ":" << line << ":" << (charPositionInLine + 1) << ": error: " << msg << "\n";

    // Fetch the underlying input stream to print the offending line
    if (recognizer != nullptr) {
        auto tokens = dynamic_cast<antlr4::TokenStream*>(recognizer->getInputStream());
        if (tokens != nullptr) {
            // Get the text of the entire source line where the error occurred
            std::string input = tokens->getTokenSource()->getInputStream()->toString();
            std::stringstream ss(input);
            std::string lineText;
            // Move to the correct line in the source string
            for (size_t i = 0; i < line; ++i) {
                std::getline(ss, lineText);
            }
            // Print the offending line of code
            std::cerr << " " << line << " | " << lineText << "\n";

            // Print the visual caret (^) pointer underneath the offending character
            std::cerr << std::string(std::to_string(line).length() + 1, ' ') << " | "; // Aligns with the '|'
            std::cerr << std::string(charPositionInLine, ' ') << "^\n";
        }
    }
    std::cerr << std::endl;
}
