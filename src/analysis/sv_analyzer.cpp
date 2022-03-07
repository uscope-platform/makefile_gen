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
    search_bus_defining_package(raw_content);
    sv_modules_explorer.set_contains_bus_defining_package(is_bus_defining_package);
    processed_content = std::regex_replace(raw_content,e,"");

}

std::vector<HDL_Resource> sv_analyzer::analyze() {
    process_hdl();

    auto entities = sv_modules_explorer.get_entities();

    documentation_analyzer doc(processed_content);

    if(is_bus_defining_package){
        for(auto &e:entities){
            if(e.get_type() == package){
                parameters = e.get_parameters();
            }
        }
    }

    doc.process_documentation(parameters);
    auto roots = doc.get_bus_roots();

    for(auto &item: roots){
        for(auto &e:entities){
            if(e.getName() == item->get_target()){
                e.add_bus_roots(item);
            }
        }
    };

    auto subs = doc.get_bus_submodules();
    for(auto &item: subs){
        for(auto &e:entities){
            if(e.getName() == item.first){
                e.set_submodules(item.second);
            }
        }
    };

    auto modules_doc = doc.get_modules_documentation();
    for(auto &e:entities){
        e.set_documentation(modules_doc[e.getName()]);
    }

    return  entities;
}


void sv_analyzer::process_hdl() {

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

}

void sv_analyzer::search_bus_defining_package(std::string &content) {
    std::regex definition(R"(`define MKF_GEN_ANALYZE_BUS)");
    is_bus_defining_package = std::regex_search(content,definition);
}




void SvParserErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                        size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
    std::cerr << "Error in file: "<< this->file_path<< std::endl;
    std::cerr << "\t" << msg<< std::endl;
}
