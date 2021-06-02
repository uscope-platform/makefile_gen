//
// Created by fils on 27/05/2021.
//



#include "analysis/sv_analyzer.h"

sv_analyzer::sv_analyzer(const std::string& file_path) : sv_modules_explorer(file_path){
    path = file_path;
}

void sv_analyzer::cleanup_content(const std::string& regex) {
    std::ifstream t(path);
    std::string raw_content;

    t.seekg(0, std::ios::end);
    raw_content.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    raw_content.assign((std::istreambuf_iterator<char>(t)),
                       std::istreambuf_iterator<char>());

    std::regex e (regex);
    processed_content = std::regex_replace (raw_content,e,"");

}

std::vector<std::shared_ptr<Resource_base>> sv_analyzer::analyze() {

    std::istringstream istream(processed_content);


    antlr4::ANTLRInputStream antlr_istream(istream);
    mgp_sv::sv2017Lexer lexer(&antlr_istream);
    antlr4::CommonTokenStream tok_stream(&lexer);

    tok_stream.fill();

    SvParserErrorListener error_listener;
    error_listener.file_path = path;

    mgp_sv::sv2017 parser(&tok_stream);

    parser.removeErrorListeners();
    parser.addErrorListener(&error_listener);

    //parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);
    antlr4::tree::ParseTree *Tree = parser.source_text();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&sv_modules_explorer, Tree);



    return  sv_modules_explorer.get_entities();
}

void SvParserErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                        size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
    std::cerr << "Error in file: "<< this->file_path<< std::endl;
    std::cerr << "\t" << msg<< std::endl;
}
