//
// Created by fils on 27/05/2021.
//

#include "analysis/sv_visitor.h"

#include <utility>

sv_visitor::sv_visitor(std::string p) {
    path = std::move(p);
}


void sv_visitor::enterModule_declaration(sv2017::Module_declarationContext *ctx) {
    nesting_level++;
    declarations_stack.push(declared_feature);
    dependencies_stack.push(instantiated_features);
}


void sv_visitor::exitModule_declaration(sv2017::Module_declarationContext *ctx) {
    std::shared_ptr<HDL_Resource> e = std::make_shared<HDL_Resource>(declared_feature.second, declared_feature.first, path, instantiated_features, verilog_entity);
    entities.push_back(e);
    if(nesting_level>1){
        declared_feature = declarations_stack.top();
        declarations_stack.pop();
        instantiated_features = dependencies_stack.top();
        dependencies_stack.pop();
        nesting_level--;
    }
}

void sv_visitor::exitModule_header_common(sv2017::Module_header_commonContext *ctx) {
    std::string module_name = ctx->identifier()->getText();
    declared_feature = std::make_pair(module_name, module);
}

void sv_visitor::exitModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) {
    std::string module_name = ctx->identifier()->getText();
    instantiated_features[module_name] = module;
}

void sv_visitor::exitInterface_header(sv2017::Interface_headerContext *ctx) {
    std::string interface_name = ctx->identifier()->getText();
    instantiated_features[interface_name] = interface;
}

std::vector<std::shared_ptr<HDL_Resource>> sv_visitor::get_entities() {
    return entities;
}
