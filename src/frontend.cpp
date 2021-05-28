//
// Created by fils on 27/05/2021.
//



#include "frontend.h"

frontend::frontend(const std::string& file_path) {
    path = file_path;

}

void frontend::cleanup_content(const std::string& regex) {
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

std::string frontend::get_string() {
    return processed_content;
}

void frontend::parse() {

    std::istringstream istream(processed_content);


    antlr4::ANTLRInputStream antlr_istream(istream);
    mgp_sv::sv2017Lexer lexer(&antlr_istream);
    antlr4::CommonTokenStream tok_stream(&lexer);

    tok_stream.fill();
    mgp_sv::sv2017 parser(&tok_stream);

    antlr4::tree::ParseTree *Tree = parser.source_text();

    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&sv_modules_explorer, Tree);
}

std::unordered_map<std::string, sv_feature> frontend::get_declared_features() {
    return sv_modules_explorer.get_declared_features();
}

std::unordered_map<std::string, sv_feature> frontend::get_instantiated_features() {
    return sv_modules_explorer.get_instantiated_features();
}
