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

std::vector<Resource> vhdl_analyzer::analyze() {

    std::istringstream istream(processed_content);


    antlr4::ANTLRInputStream antlr_istream(istream);
    mgp_vh::vhdlLexer lexer(&antlr_istream);
    antlr4::CommonTokenStream tok_stream(&lexer);

    tok_stream.fill();
    mgp_vh::vhdlParser parser(&tok_stream);
    parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);
    antlr4::tree::ParseTree *Tree = parser.design_file();

    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&vhdl_modules_explorer, Tree);

    return  vhdl_modules_explorer.get_entities();
}
