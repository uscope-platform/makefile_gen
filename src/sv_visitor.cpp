//
// Created by fils on 27/05/2021.
//

#include "sv_visitor.h"

void sv_visitor::exitModule_header_common(sv2017::Module_header_commonContext *ctx) {
    std::string module_name = ctx->identifier()->getText();
    declared_features[module_name] = module;
}

void sv_visitor::exitModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) {
    std::string module_name = ctx->identifier()->getText();
    instantiated_features[module_name] = module;
}

void sv_visitor::exitInterface_header(sv2017::Interface_headerContext *ctx) {
    std::string interface_name = ctx->identifier()->getText();
    instantiated_features[interface_name] = interface;
}

std::unordered_map<std::string, sv_feature> sv_visitor::get_declared_features() {
    return declared_features;
}

std::unordered_map<std::string, sv_feature> sv_visitor::get_instantiated_features() {
    return instantiated_features;
}
