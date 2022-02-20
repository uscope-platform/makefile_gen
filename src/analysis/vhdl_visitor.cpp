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

#include "analysis/vhdl_visitor.h"

#include <utility>

vhdl_visitor::vhdl_visitor(std::string p) {
    path = std::move(p);
}

std::vector<std::shared_ptr<HDL_Resource>> vhdl_visitor::get_entities() {
    return entities;
}

void vhdl_visitor::enterEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) {
    nesting_level++;
    declarations_stack.push(declared_feature);
    dependencies_stack.push(instantiated_features);
    std::string module_name = ctx->identifier()[0]->getText();
    declared_feature = std::make_pair(module_name, null_feature);
}

void vhdl_visitor::exitArchitecture_body(mgp_vh::vhdlParser::Architecture_bodyContext *ctx) {
    std::string name = ctx->name()->getText();
    for(auto &item:entities){
        if(item->getName() == name){
            item->add_dependencies(instantiated_features);
        }
    }
}


void vhdl_visitor::exitEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) {
    std::shared_ptr<HDL_Resource> e = std::make_shared<HDL_Resource>(declared_feature.second, declared_feature.first, path, instantiated_features, vhdl_entity);
    entities.push_back(e);
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
    if(ctx->instantiated_unit()->name()->suffix() != nullptr){
        module_name = ctx->instantiated_unit()->name()->suffix()->getText();
    } else{
        module_name = ctx->instantiated_unit()->name()->name_literal()->identifier()->getText();
    }

    instantiated_features[module_name] = module;
}

