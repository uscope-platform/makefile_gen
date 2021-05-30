//
// Created by fils on 30/05/2021.
//

#include "analysis/vhdl_visitor.h"

#include <utility>

vhdl_visitor::vhdl_visitor(std::string p) {
    path = std::move(p);
}

std::vector<Resource> vhdl_visitor::get_entities() {
    return entities;
}

void vhdl_visitor::enterEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) {
    nesting_level++;
    declarations_stack.push(declared_feature);
    dependencies_stack.push(instantiated_features);
    std::string module_name = ctx->identifier()[0]->getText();
    declared_feature = std::make_pair(module_name, null_feature);
}

void vhdl_visitor::exitEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) {
    Resource entity(declared_feature.second, declared_feature.first, path, instantiated_features, vhdl_entity);
    entities.push_back(entity);
    if(nesting_level>1){
        declared_feature = declarations_stack.top();
        declarations_stack.pop();
        instantiated_features = dependencies_stack.top();
        dependencies_stack.pop();
        nesting_level--;
    }
}

void vhdl_visitor::exitComponent_instantiation_statement(mgp_vh::vhdlParser::Component_instantiation_statementContext *ctx) {
    std::string module_name;
    if(ctx->instantiated_unit()->name()->suffix() != NULL){
        module_name = ctx->instantiated_unit()->name()->suffix()->getText();
    } else{
        module_name = ctx->instantiated_unit()->name()->name_literal()->identifier()->getText();
    }

    instantiated_features[module_name] = module;
}