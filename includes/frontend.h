//
// Created by fils on 27/05/2021.
//

#ifndef MAKEFILEGEN_V2_FRONTEND_H
#define MAKEFILEGEN_V2_FRONTEND_H

#include <string>
#include <sstream>
#include <fstream>
#include <regex>

#include "../includes/mgp_sv/sv2017Lexer.h"
#include "../includes/mgp_sv/sv2017.h"
#include "sv_visitor.h"
#include "antlr4-runtime.h"

class frontend {
public:
    frontend(const std::string& file_path);
    void cleanup_content(const std::string& regex);
    void parse();
    std::string get_string();
    std::unordered_map<std::string, sv_feature> get_declared_features();
    std::unordered_map<std::string, sv_feature> get_instantiated_features();
private:
    std::string path;
    std::string processed_content;
    sv_visitor sv_modules_explorer;

};


#endif //MAKEFILEGEN_V2_FRONTEND_H
