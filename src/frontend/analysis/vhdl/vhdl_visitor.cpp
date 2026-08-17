//  Copyright 2026 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "frontend/analysis/vhdl/vhdl_visitor.hpp"

#include <algorithm>
#include <cctype>

namespace {

    bool is_extended_identifier(const std::string &s) {
        return s.size() >= 2 && s.front() == '\\' && s.back() == '\\';
    }

    // Canonical form of a VHDL identifier: extended identifiers keep their
    // case and lose their backslash delimiters, all others are lower-cased.
    std::string canon(const std::string &s) {
        if (is_extended_identifier(s)) return s.substr(1, s.size() - 2);
        std::string ret = s;
        std::transform(ret.begin(), ret.end(), ret.begin(),
                       [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        return ret;
    }

}

vhdl_visitor::vhdl_visitor(std::string p) {
    path = std::move(p);
}


void vhdl_visitor::enterEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) {
    std::string module_name = canon(ctx->identifier()[0]->getText());
    size_t line_number = ctx->getStart()->getLine();
    modules_factory.new_module(module_name,module, line_number);
}

void vhdl_visitor::exitArchitecture_body(mgp_vh::vhdlParser::Architecture_bodyContext *ctx) {
    std::string name = canon(ctx->name()->getText());
    for(auto &item:entities){
        if(item->is<hdl_resource_statement>() && item->as<hdl_resource_statement>().getName() == name){
            for (auto &stmt : statement_map[item->as<hdl_resource_statement>().getName()]) {
                item->as<hdl_resource_statement>().add_statement(stmt);
            }
        }
    }
}


void vhdl_visitor::exitEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) {
    entities.push_back(modules_factory.get_module());
}

void vhdl_visitor::exitConcurrent_statement(mgp_vh::vhdlParser::Concurrent_statementContext *ctx) {
    if(ctx->component_instantiation_statement()!= nullptr){
        auto instantiation = ctx->component_instantiation_statement();
        std::string module_name;
        if(instantiation->instantiated_unit()->name()->suffix() != nullptr){
            module_name = canon(instantiation->instantiated_unit()->name()->suffix()->getText());
        } else{
            module_name = canon(instantiation->instantiated_unit()->name()->name_literal()->identifier()->getText());
        }
        auto stmt = std::make_shared<hdl_instance_statement>();
        stmt->set_name(canon(ctx->label()->getText()));
        stmt->set_type(module_name);
        stmt->set_dependency_class(module);
        statement_map[current_architecture].push_back(stmt);
    }
}

void vhdl_visitor::enterArchitecture_body(mgp_vh::vhdlParser::Architecture_bodyContext *ctx) {
    current_architecture = canon(ctx->name()->getText());
}
