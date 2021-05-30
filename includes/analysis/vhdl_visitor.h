//
// Created by fils on 30/05/2021.
//

#ifndef MAKEFILEGEN_V2_VHDL_VISITOR_H
#define MAKEFILEGEN_V2_VHDL_VISITOR_H

#include <string>
#include <vector>
#include <stack>
#include "data_model/Resource.h"

#include "mgp_vh/vhdlParserBaseListener.h"
#include "mgp_vh/vhdlParser.h"


class vhdl_visitor : public mgp_vh::vhdlParserBaseListener {

public:
    explicit vhdl_visitor(std::string p);
    void enterEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) override;
    void exitEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) override;
    void exitComponent_instantiation_statement(mgp_vh::vhdlParser::Component_instantiation_statementContext *ctx) override;
    std::vector<Resource> get_entities();
private:
    hdl_declaration_t declared_feature;
    hdl_deps_t instantiated_features;
    int nesting_level = 0;
    std::stack<hdl_declaration_t> declarations_stack;
    std::stack<hdl_deps_t> dependencies_stack;
    std::string path;
    std::vector<Resource> entities;

};


#endif //MAKEFILEGEN_V2_VHDL_VISITOR_H
