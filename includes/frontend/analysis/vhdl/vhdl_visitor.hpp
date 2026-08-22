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

#ifndef ANANKE_VHDL_VISITOR_HPP
#define ANANKE_VHDL_VISITOR_HPP

#include <string>
#include <utility>
#include <vector>
#include <stack>
#include <optional>

#include "data_model/HDL/statement/hdl_instance_statement.hpp"
#include "data_model/HDL/factories/HDL_modules_factory.hpp"
#include "data_model/HDL/factories/HDL_parameters_factory.hpp"
#include "data_model/HDL/parameters/components/HDL_builtin_function.hpp"

#include "mgp_vh/vhdlParserBaseListener.h"
#include "mgp_vh/vhdlParser.h"


class vhdl_visitor : public mgp_vh::vhdlParserBaseListener {

public:
    explicit vhdl_visitor(std::string p);
    void enterEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) override;
    void exitEntity_declaration(mgp_vh::vhdlParser::Entity_declarationContext *ctx) override;
    void enterArchitecture_body(mgp_vh::vhdlParser::Architecture_bodyContext *ctx) override;
    void exitArchitecture_body(mgp_vh::vhdlParser::Architecture_bodyContext *ctx) override;
    void exitConcurrent_statement(mgp_vh::vhdlParser::Concurrent_statementContext *ctx) override;

    void enterGeneric_clause(mgp_vh::vhdlParser::Generic_clauseContext *ctx) override;
    void exitGeneric_clause(mgp_vh::vhdlParser::Generic_clauseContext *ctx) override;
    void enterInterface_constant_declaration(mgp_vh::vhdlParser::Interface_constant_declarationContext *ctx) override;
    void exitInterface_constant_declaration(mgp_vh::vhdlParser::Interface_constant_declarationContext *ctx) override;
    void enterInterface_signal_declaration(mgp_vh::vhdlParser::Interface_signal_declarationContext *ctx) override;
    void exitInterface_signal_declaration(mgp_vh::vhdlParser::Interface_signal_declarationContext *ctx) override;
    void enterSubtype_indication(mgp_vh::vhdlParser::Subtype_indicationContext *ctx) override;
    void exitSubtype_indication(mgp_vh::vhdlParser::Subtype_indicationContext *ctx) override;

    void enterExpression(mgp_vh::vhdlParser::ExpressionContext *ctx) override;
    void exitExpression(mgp_vh::vhdlParser::ExpressionContext *ctx) override;
    void enterSimple_expression(mgp_vh::vhdlParser::Simple_expressionContext *ctx) override;
    void exitSimple_expression(mgp_vh::vhdlParser::Simple_expressionContext *ctx) override;
    void enterNumeric_literal(mgp_vh::vhdlParser::Numeric_literalContext *ctx) override;
    void exitNumeric_literal(mgp_vh::vhdlParser::Numeric_literalContext *ctx) override;
    void exitPrimary(mgp_vh::vhdlParser::PrimaryContext *ctx) override;
    void enterAggregate(mgp_vh::vhdlParser::AggregateContext *ctx) override;
    void exitAggregate(mgp_vh::vhdlParser::AggregateContext *ctx) override;
    void enterChoices(mgp_vh::vhdlParser::ChoicesContext *ctx) override;
    void exitChoices(mgp_vh::vhdlParser::ChoicesContext *ctx) override;
    void enterActual_part(mgp_vh::vhdlParser::Actual_partContext *ctx) override;
    void exitActual_part(mgp_vh::vhdlParser::Actual_partContext *ctx) override;
    void enterQualified_expression(mgp_vh::vhdlParser::Qualified_expressionContext *ctx) override;
    void exitQualified_expression(mgp_vh::vhdlParser::Qualified_expressionContext *ctx) override;

    std::vector<std::shared_ptr<hdl_statement_base>> get_entities() {return entities;}
private:
    void start_generic(mgp_vh::vhdlParser::Identifier_listContext *ids,
                       mgp_vh::vhdlParser::Subtype_indicationContext *type);
    void finalize_generic(mgp_vh::vhdlParser::Identifier_listContext *ids);
    std::shared_ptr<hdl_type> make_generic_type(mgp_vh::vhdlParser::Subtype_indicationContext *type);
    std::shared_ptr<Expression_base> make_vhdl_value(const std::string &text);
    std::shared_ptr<Expression_base> make_character_value(const std::string &text);
    bool is_in_generic_expression() const;
    static bool is_aggregate(mgp_vh::vhdlParser::AggregateContext *ctx);
    static bool simple_is_aggregate(mgp_vh::vhdlParser::Simple_expressionContext *ctx);
    static bool has_expr_operator(mgp_vh::vhdlParser::ExpressionContext *ctx);
    static bool simple_is_nonleaf(mgp_vh::vhdlParser::Simple_expressionContext *ctx);
    static bool is_function_call(mgp_vh::vhdlParser::NameContext *nm);
    static std::string extract_call_name(mgp_vh::vhdlParser::NameContext *nm);
    static bool is_vhdl_builtin(const std::string &name);

    std::string path;
    std::vector<std::shared_ptr<hdl_statement_base>>  entities;
    std::unordered_map<std::string, std::vector<std::shared_ptr<hdl_statement_base>>> statement_map;
    std::string current_architecture;
    bool in_generic_clause = false;
    bool in_subtype_indication = false;
    bool in_aggregate_choices = false;

    HDL_modules_factory modules_factory;
    HDL_parameters_factory params_factory;
};


#endif //ANANKE_VHDL_VISITOR_HPP
