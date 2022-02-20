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

std::vector<std::shared_ptr<HDL_Resource>> sv_analyzer::analyze() {

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


    if(is_bus_defining_package){
        std::vector<std::shared_ptr<HDL_Resource>> entities = sv_modules_explorer.get_entities();
        std::shared_ptr<HDL_Resource> declared_package;
        for(auto &e:entities){
            if(e->get_type() == package){
                declared_package = e;
            }
        }
        analyze_package_docstings(declared_package->get_parameters());
    }
    return  sv_modules_explorer.get_entities();
}

void sv_analyzer::analyze_package_docstings(std::unordered_map<std::string, uint32_t> parameters) {
    std::regex docstring_ex(R"(/\*[^*]*\*+(?:[^/*][^*]*\*+)*/)");
    std::regex type_ex(R"((?: )*type: (.*))");
    std::regex parameter_ex(R"((?: )*parameter: (.*))");

    for(std::sregex_iterator i = std::sregex_iterator(processed_content.begin(), processed_content.end(), docstring_ex);
        i != std::sregex_iterator();
        ++i ) {
        std::smatch m = *i;
        std::string docstring =  trim(m.str().substr(3,m.str().length()-6));
        regex_search(docstring, m, type_ex);
        std::string t = m[1];
        regex_search(docstring, m, parameter_ex);
        std::string param_name = m[1];
        if(t=="crossbar"){
            analyze_crossbar(docstring, param_name,parameters[param_name], false);
        } else if(t=="module"){
            analyze_module(docstring, param_name,parameters[param_name]);
        } else if(t=="registers"){
            analyze_register(docstring, param_name,parameters[param_name]);
        } else if(t=="bus_root"){
            analyze_crossbar(docstring, param_name,parameters[param_name], true);
        }
    }
    for(auto &item:bus_roots){
        construct_bus_hierarchy(item);
    }
}

void sv_analyzer::construct_bus_hierarchy(std::shared_ptr<bus_crossbar> dict) {
    std::vector<std::string> childs = dict->get_raw_children_list();
    if(childs.empty()) {
        return;
    }
    for(auto &item:childs){
        if(modules_dict.count(item)!= 0 ){
            dict->add_child(modules_dict[item]);
            modules_dict.erase(item);
        } else if(registers_dict.count(item) != 0){
            dict->add_child(registers_dict[item]);
            registers_dict.erase(item);
        } else if(crossbar_dict.count(item) != 0){
            construct_bus_hierarchy(crossbar_dict[item]);
            dict->add_child(crossbar_dict[item]);
            crossbar_dict.erase(item);
        }
    }

}

void sv_analyzer::analyze_register(const std::string& docstring, const std::string& parameter_name, uint32_t address) {
    std::regex target_ex(R"((?: )*target: (.*))");
    std::smatch m;
    regex_search(docstring, m, target_ex);
    std::string target_module = m[1];
    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>(target_module, parameter_name);
    reg->set_base_address(address);
    registers_dict[target_module] = reg;
}

void sv_analyzer::analyze_module(const std::string& docstring, const std::string& parameter_name, uint32_t address) {
    std::regex target_ex(R"((?: )*target: (.*) (.*))");
    std::smatch m;
    regex_search(docstring, m, target_ex);
    std::string target_module = m[1];
    std::string target_instance = m[2];
    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>(target_instance, target_module, parameter_name);
    mod->set_base_address(address);
    modules_dict[parameter_name] = mod;
}

void sv_analyzer::analyze_crossbar(const std::string& docstring, const std::string& parameter_name, uint32_t address, bool is_root) {

    std::regex children_list_ex(R"((?: )*children: (.*))");
    std::regex child_ex(R"(([a-zA-Z0-9$_]+))");
    std::smatch m;
    regex_search(docstring, m, children_list_ex);
    std::vector<std::string> children_vect;

    std::istringstream iss(m[1]);
    std::string item;
    while (std::getline(iss, item, ' ')) {
        children_vect.push_back(item);
    }

    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>(children_vect, parameter_name);
    xbar->set_base_address(address);
    if(is_root){
        bus_roots.push_back(xbar);
    } else {
        crossbar_dict[parameter_name] = xbar;
    }

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
