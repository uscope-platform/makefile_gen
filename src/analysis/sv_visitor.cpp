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

#include "analysis/sv_visitor.h"

#include <utility>

sv_visitor::sv_visitor(std::string p) {
    path = std::move(p);
}


void sv_visitor::enterModule_declaration(sv2017::Module_declarationContext *ctx) {
    nesting_level++;
    declarations_stack.push(declared_feature);
    dependencies_stack.push(instantiated_features);
    instantiated_features.clear();
}


void sv_visitor::exitModule_declaration(sv2017::Module_declarationContext *ctx) {

        std::shared_ptr<HDL_Resource> e = std::make_shared<HDL_Resource>(declared_feature.second, declared_feature.first, path, instantiated_features, verilog_entity);
        entities.push_back(e);
        if(!declarations_stack.empty()) {
            declared_feature = declarations_stack.top();
            declarations_stack.pop();
        }
        if(!dependencies_stack.empty()){
            instantiated_features = dependencies_stack.top();
            dependencies_stack.pop();
        } else{
            instantiated_features.clear();
        }

        nesting_level--;
}

void sv_visitor::exitInterface_declaration(sv2017::Interface_declarationContext *ctx) {
    std::string interface_name = ctx->interface_header()->identifier()->getText();
    hdl_deps_t dummy;
    std::shared_ptr<HDL_Resource> e = std::make_shared<HDL_Resource>(interface, interface_name, path, dummy, verilog_entity);
    entities.push_back(e);
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

void sv_visitor::exitPrimaryTfCall(sv2017::PrimaryTfCallContext *ctx) {
    std::string call_name = ctx->any_system_tf_identifier()->getText();
    if(call_name=="$readmemh" || call_name=="$readmemb"){
        std::string data_file = ctx->list_of_arguments()->expression()[0]->getText();
        data_file = std::regex_replace(data_file, std::regex("\\\""), "");
        std::filesystem::path p = data_file;
        if(p.extension().string() == ".dat"|| p.extension().string() == ".mem"){
            instantiated_features[p.stem()] = memory_init;
        }

    }
}

void sv_visitor::exitPackage_declaration(sv2017::Package_declarationContext *ctx) {
    std::string package_name = ctx->identifier()[0]->getText();
    std::shared_ptr<HDL_Resource> e = std::make_shared<HDL_Resource>(package, package_name, path, instantiated_features, verilog_entity);
    entities.push_back(e);
}

void sv_visitor::exitPackage_or_class_scoped_path(sv2017::Package_or_class_scoped_pathContext *ctx) {
    if(!ctx->DOUBLE_COLON().empty()){
        std::string package_name = ctx->package_or_class_scoped_path_item()[0]->identifier()->getText();
        instantiated_features[package_name] = package;
    }

}
