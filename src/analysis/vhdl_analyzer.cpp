//
// Created by fils on 30/05/2021.
//

#include "analysis/vhdl_analyzer.h"

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

std::vector<std::shared_ptr<HDL_Resource>> vhdl_analyzer::analyze() {

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

    return  vhdl_modules_explorer.get_entities();
}

void VhParserErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                      size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
    std::cerr << "Error in file: "<< this->file_path << " At line: " << line << " Column: "<< charPositionInLine << std::endl;
    std::cerr << "\t" << msg<< std::endl;
}
