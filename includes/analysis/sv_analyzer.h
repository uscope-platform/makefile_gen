//
// Created by fils on 27/05/2021.
//

#ifndef MAKEFILEGEN_V2_SV_ANALYZER_H
#define MAKEFILEGEN_V2_SV_ANALYZER_H

#include <string>
#include <sstream>
#include <fstream>
#include <regex>

#include "mgp_sv/sv2017Lexer.h"
#include "mgp_sv/sv2017.h"
#include "analysis/sv_visitor.h"
#include "antlr4-runtime.h"

class sv_analyzer {
public:
    explicit sv_analyzer(const std::string& file_path);
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


#endif //MAKEFILEGEN_V2_SV_ANALYZER_H
