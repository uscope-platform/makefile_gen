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
#include <charconv>
#include <string>

#include <spdlog/spdlog.h>

#include "data_model/HDL/parameters/components/token/Numeric_token.hpp"
#include "data_model/HDL/parameters/components/token/Real_token.hpp"
#include "data_model/HDL/parameters/components/token/Identifier_token.hpp"
#include "data_model/HDL/parameters/components/token/String_token.hpp"
#include "data_model/HDL/types/HDL_simple_type.hpp"

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

void vhdl_visitor::enterGeneric_clause(mgp_vh::vhdlParser::Generic_clauseContext *ctx) {
    in_generic_clause = true;
}

void vhdl_visitor::exitGeneric_clause(mgp_vh::vhdlParser::Generic_clauseContext *ctx) {
    in_generic_clause = false;
}

void vhdl_visitor::enterInterface_constant_declaration(
        mgp_vh::vhdlParser::Interface_constant_declarationContext *ctx) {
    if (in_generic_clause)
        start_generic(ctx->identifier_list(), ctx->subtype_indication());
}

void vhdl_visitor::exitInterface_constant_declaration(
        mgp_vh::vhdlParser::Interface_constant_declarationContext *ctx) {
    if (in_generic_clause)
        finalize_generic(ctx->identifier_list());
}

void vhdl_visitor::enterInterface_signal_declaration(
        mgp_vh::vhdlParser::Interface_signal_declarationContext *ctx) {
    // A generic declared without the `constant` keyword (the common form,
    // e.g. `N : integer := 8`) is parsed as an interface signal declaration.
    // Only treat it as a generic when inside a generic clause.
    if (in_generic_clause)
        start_generic(ctx->identifier_list(), ctx->subtype_indication());
}

void vhdl_visitor::exitInterface_signal_declaration(
        mgp_vh::vhdlParser::Interface_signal_declarationContext *ctx) {
    if (in_generic_clause)
        finalize_generic(ctx->identifier_list());
}

void vhdl_visitor::enterSubtype_indication(mgp_vh::vhdlParser::Subtype_indicationContext *ctx) {
    if (in_generic_clause) in_subtype_indication = true;
}

void vhdl_visitor::exitSubtype_indication(mgp_vh::vhdlParser::Subtype_indicationContext *ctx) {
    if (in_generic_clause) in_subtype_indication = false;
}

void vhdl_visitor::start_generic(mgp_vh::vhdlParser::Identifier_listContext *ids,
                                 mgp_vh::vhdlParser::Subtype_indicationContext *type) {
    if (!ids || ids->identifier().empty()) return;
    params_factory.set_type(make_generic_type(type));
    params_factory.start_param_assignment();
    params_factory.new_parameter(canon(ids->identifier(0)->getText()));
}

void vhdl_visitor::finalize_generic(mgp_vh::vhdlParser::Identifier_listContext *ids) {
    if (!ids || ids->identifier().empty()) return;
    params_factory.stop_param_assignment();

    // The default expression (built by the listener callbacks) belongs to the
    // first name; the remaining names in the list share the same type/default,
    // so clone it.
    auto base = params_factory.get_parameter();
    modules_factory.add_parameter(base);
    for (size_t i = 1; i < ids->identifier().size(); i++) {
        auto clone = std::make_shared<HDL_parameter>(*base);
        clone->set_name(canon(ids->identifier(i)->getText()));
        modules_factory.add_parameter(clone);
    }
}

std::shared_ptr<hdl_type> vhdl_visitor::make_generic_type(
        mgp_vh::vhdlParser::Subtype_indicationContext *type) {
    auto t = std::make_shared<HDL_simple_type>();
    if (type && type->type_mark() && type->type_mark()->name() &&
        type->type_mark()->name()->name_literal() &&
        type->type_mark()->name()->name_literal()->identifier()) {
        std::string type_name = canon(type->type_mark()->name()->name_literal()->identifier()->getText());
        t->set_type_name(type_name);
        // integer/natural/positive are signed integer-like scalars.
        if (type_name == "integer" || type_name == "natural" || type_name == "positive")
            t->set_signed(true);
        if (type_name == "real")
            t->set_real(true);
    }
    return t;
}

bool vhdl_visitor::has_expr_operator(mgp_vh::vhdlParser::ExpressionContext *ctx) {
    return ctx && (ctx->shift_operator() || ctx->relational_operator() || ctx->logical_operator());
}

bool vhdl_visitor::simple_is_nonleaf(mgp_vh::vhdlParser::Simple_expressionContext *ctx) {
    return ctx && (ctx->DOUBLESTAR() || ctx->KW_ABS() || ctx->KW_NOT() || ctx->logical_operator()
        || ctx->sign() || ctx->multiplying_operator() || ctx->adding_operator());
}

void vhdl_visitor::enterExpression(mgp_vh::vhdlParser::ExpressionContext *ctx) {
    if (is_in_generic_expression() && (has_expr_operator(ctx) || ctx->COND_OP()))
        params_factory.start_expression_new(true);
}

void vhdl_visitor::exitExpression(mgp_vh::vhdlParser::ExpressionContext *ctx) {
    if (!is_in_generic_expression()) return;

    auto op = Expression_v2::none;
    if (ctx->COND_OP()) {
        // VHDL `??` condition operator: normalize a condition to 0/1.
        op = Expression_v2::condition_op;
    } else if (ctx->shift_operator()) {
        if (ctx->shift_operator()->KW_SLL()) op = Expression_v2::logic_shift_left;
        else if (ctx->shift_operator()->KW_SRL()) op = Expression_v2::logic_shift_right;
        else if (ctx->shift_operator()->KW_SLA()) op = Expression_v2::arithmetic_shift_left;
        else if (ctx->shift_operator()->KW_SRA()) op = Expression_v2::arithmetic_shift_right;
        else if (ctx->shift_operator()->KW_ROL()) op = Expression_v2::rotate_left;
        else if (ctx->shift_operator()->KW_ROR()) op = Expression_v2::rotate_right;
    } else if (ctx->relational_operator()) {
        if (ctx->relational_operator()->EQ()) op = Expression_v2::equal;
        else if (ctx->relational_operator()->NE()) op = Expression_v2::not_equal;
        else if (ctx->relational_operator()->LT()) op = Expression_v2::less;
        else if (ctx->relational_operator()->CONASGN()) op = Expression_v2::less_equal; // VHDL <=
        else if (ctx->relational_operator()->GT()) op = Expression_v2::greater;
        else if (ctx->relational_operator()->GE()) op = Expression_v2::greater_equal;
    } else if (ctx->logical_operator()) {
        if (ctx->logical_operator()->KW_AND()) op = Expression_v2::bitwise_and;
        else if (ctx->logical_operator()->KW_OR()) op = Expression_v2::bitwise_or;
        else if (ctx->logical_operator()->KW_XOR()) op = Expression_v2::bitwise_xor;
        else if (ctx->logical_operator()->KW_XNOR()) op = Expression_v2::bitwise_xnor;
    }
    if (op != Expression_v2::none)
        params_factory.set_operation(op);
    if (op != Expression_v2::none)
        params_factory.stop_expression_new(true);
}

void vhdl_visitor::enterSimple_expression(mgp_vh::vhdlParser::Simple_expressionContext *ctx) {
    // An unambiguous aggregate primary is handled by enter/exitAggregate; skip
    // bracketing it here so the aggregate elements reach level 0 independently.
    if (is_in_generic_expression() && !simple_is_aggregate(ctx))
        params_factory.start_expression_new(simple_is_nonleaf(ctx));
}

void vhdl_visitor::exitSimple_expression(mgp_vh::vhdlParser::Simple_expressionContext *ctx) {
    if (!is_in_generic_expression() || simple_is_aggregate(ctx)) return;

    if (simple_is_nonleaf(ctx)) {
        if (ctx->DOUBLESTAR()) {
            params_factory.set_operation(Expression_v2::power);
        } else if (ctx->KW_ABS()) {
            params_factory.set_operation(Expression_v2::abs_value);
        } else if (ctx->KW_NOT()) {
            params_factory.set_operation(Expression_v2::bitwise_neg);
        } else if (ctx->logical_operator()) {
            // VHDL allows a logical operator as a unary reduction over a vector.
            if (ctx->logical_operator()->KW_AND() || ctx->logical_operator()->KW_NAND())
                params_factory.set_operation(Expression_v2::reduction_and);
            else if (ctx->logical_operator()->KW_OR() || ctx->logical_operator()->KW_NOR())
                params_factory.set_operation(Expression_v2::reduction_or);
            else
                params_factory.set_operation(Expression_v2::reduction_xor);
        } else if (ctx->multiplying_operator()) {
            auto op = Expression_v2::multiply;
            if (ctx->multiplying_operator()->DIV()) op = Expression_v2::divide;
            else if (ctx->multiplying_operator()->KW_MOD()) op = Expression_v2::v_mod;   // floor mod
            else if (ctx->multiplying_operator()->KW_REM()) op = Expression_v2::modulo;  // truncated rem
            params_factory.set_operation(op);
        } else if (ctx->adding_operator()) {
            if (ctx->adding_operator()->PLUS()) params_factory.set_operation(Expression_v2::add);
            else if (ctx->adding_operator()->MINUS()) params_factory.set_operation(Expression_v2::subtract);
            else spdlog::warn("VHDL concatenation (&) in generic default not supported, ignored");
        } else if (ctx->sign() && ctx->sign()->MINUS()) {
            params_factory.set_operation(Expression_v2::subtract);
        }
    }
    params_factory.stop_expression_new(simple_is_nonleaf(ctx));
}

void vhdl_visitor::exitNumeric_literal(mgp_vh::vhdlParser::Numeric_literalContext *ctx) {
    if (!is_in_generic_expression() || !params_factory.is_component_relevant()) return;

    // A bare identifier: a reference to another generic/constant.
    if (ctx->name() && ctx->name()->name_literal() && ctx->name()->name_literal()->identifier()) {
        params_factory.add_component(std::make_shared<Identifier_token>(
            qualified_identifier(canon(ctx->name()->name_literal()->identifier()->getText()))));
        return;
    }

    // A character literal ('a') or string literal ("...") also arrive through
    // the `name` rule.
    if (ctx->name() && ctx->name()->name_literal()) {
        auto lit = ctx->name()->name_literal();
        if (lit->CHARACTER_LITERAL()) {
            params_factory.add_component(make_character_value(lit->CHARACTER_LITERAL()->getText()));
            return;
        }
        if (lit->operator_symbol() && lit->operator_symbol()->STRING_LITERAL()) {
            auto str = lit->operator_symbol()->STRING_LITERAL()->getText();
            params_factory.add_component(std::make_shared<String_token>(str));
            return;
        }
    }

    params_factory.add_component(make_vhdl_value(ctx->getText()));
}

void vhdl_visitor::exitPrimary(mgp_vh::vhdlParser::PrimaryContext *ctx) {
    if (!is_in_generic_expression() || !params_factory.is_component_relevant()) return;
    if (ctx->BIT_STRING_LITERAL()) {
        // Treat a bit string literal as a sized numeric value (e.g. x"FF").
        params_factory.add_component(make_vhdl_value(ctx->BIT_STRING_LITERAL()->getText()));
    }
}

void vhdl_visitor::enterAggregate(mgp_vh::vhdlParser::AggregateContext *ctx) {
    // `(expr)` is ambiguous between a parenthesized expression and a
    // single-element aggregate. Only treat it as an aggregate when it is
    // unambiguous: multiple elements, or an element with `choices`/`others`.
    if (is_in_generic_expression() && is_aggregate(ctx))
        params_factory.start_initialization_list();
}

void vhdl_visitor::exitAggregate(mgp_vh::vhdlParser::AggregateContext *ctx) {
    if (!is_in_generic_expression() || !is_aggregate(ctx)) return;

    // An aggregate using `others` sets the default-initialization flag.
    bool default_assignment = false;
    for (auto *el : ctx->element_association()) {
        if (el->choices()) {
            for (auto *c : el->choices()->choice()) {
                if (c->KW_OTHERS()) { default_assignment = true; break; }
            }
        }
        if (default_assignment) break;
    }
    params_factory.stop_initialization_list(default_assignment);
}

void vhdl_visitor::enterChoices(mgp_vh::vhdlParser::ChoicesContext *ctx) {
    in_aggregate_choices = true;
}

void vhdl_visitor::exitChoices(mgp_vh::vhdlParser::ChoicesContext *ctx) {
    in_aggregate_choices = false;
}

bool vhdl_visitor::is_aggregate(mgp_vh::vhdlParser::AggregateContext *ctx) {
    if (ctx->element_association().size() > 1) return true;
    // Single element: unambiguous aggregate only if it has `choices`
    // (e.g. `(0 => a)` or `(others => a)`).
    if (!ctx->element_association().empty())
        return ctx->element_association(0)->choices() != nullptr;
    return false;
}

bool vhdl_visitor::simple_is_aggregate(mgp_vh::vhdlParser::Simple_expressionContext *ctx) {
    return ctx && ctx->primary(0) && ctx->primary(0)->aggregate() &&
           is_aggregate(ctx->primary(0)->aggregate());
}

bool vhdl_visitor::is_in_generic_expression() const {
    return in_generic_clause && !in_subtype_indication && !in_aggregate_choices;
}

std::shared_ptr<Expression_base> vhdl_visitor::make_character_value(const std::string &text) {
    // A VHDL character literal like 'a' is represented by its ASCII value.
    // The text includes the surrounding apostrophes.
    if (text.size() >= 3 && text.front() == '\'' && text.back() == '\'') {
        char c = text[1];
        return std::make_shared<Numeric_token>(std::to_string(static_cast<int>(static_cast<unsigned char>(c))));
    }
    spdlog::warn("Malformed VHDL character literal '{}' in generic default, ignored", text);
    return nullptr;
}

std::shared_ptr<Expression_base> vhdl_visitor::make_vhdl_value(const std::string &text) {
    if (text.empty()) return nullptr;

    // Bit-string literal, e.g. x"FF", b"1010", o"17", d"255",
    // 8x"1F", ub"1101", sx"FF".
    if (text.find('"') != std::string::npos) {
        size_t quote_open = text.find('"');
        std::string prefix = text.substr(0, quote_open);
        size_t quote_close = text.rfind('"');
        if (quote_close > quote_open) {
            std::string digits = text.substr(quote_open + 1, quote_close - quote_open - 1);
            // prefix = [width](u|s)?base
            int64_t width = -1;
            bool signed_number = false;
            size_t i = 0;
            // Optional integer width.
            while (i < prefix.size() && std::isdigit(static_cast<unsigned char>(prefix[i]))) i++;
            if (i > 0) {
                std::from_chars(prefix.data(), prefix.data() + i, width, 10);
            }
            if (i < prefix.size() && (prefix[i] == 'u' || prefix[i] == 's')) {
                signed_number = prefix[i] == 's';
                i++;
            }
            if (i < prefix.size()) {
                int base = 10;
                char base_char = std::tolower(static_cast<unsigned char>(prefix[i]));
                if (base_char == 'b') base = 2;
                else if (base_char == 'o') base = 8;
                else if (base_char == 'x') base = 16;
                else if (base_char == 'd') base = 10;

                int64_t value = 0;
                bool valid = true;
                for (char c : digits) {
                    if (c == '_') continue;
                    int d;
                    if (c >= '0' && c <= '9') d = c - '0';
                    else if (c >= 'a' && c <= 'f') d = c - 'a' + 10;
                    else if (c >= 'A' && c <= 'F') d = c - 'A' + 10;
                    else { valid = false; break; }
                    if (d >= base) { valid = false; break; }
                    value = value * base + d;
                }
                if (valid) {
                    auto tok = std::make_shared<Numeric_token>(std::to_string(value));
                    if (width > 0) {
                        tok->set_binary_size(width);
                        tok->set_sized_explicit(true);
                        if (signed_number) {
                            // Interpret as a two's-complement signed value of `width` bits.
                            auto v = value;
                            if (v & (int64_t(1) << (width - 1))) v -= (int64_t(1) << width);
                            tok = std::make_shared<Numeric_token>(std::to_string(v));
                        }
                    }
                    return tok;
                }
            }
        }
        spdlog::warn("Malformed VHDL bit-string literal '{}' in generic default, ignored", text);
        return nullptr;
    }

    // VHDL based literal, e.g. 16#FF# or 2#1010#.
    size_t hash_pos = text.find('#');
    if (hash_pos != std::string::npos && text.size() > hash_pos + 1 && text.back() == '#') {
        std::string base_str = text.substr(0, hash_pos);
        std::string digits = text.substr(hash_pos + 1, text.size() - hash_pos - 2);
        int base = 10;
        std::from_chars(base_str.data(), base_str.data() + base_str.size(), base, 10);
        // Reject base > 16 or invalid digits.
        if (base >= 2 && base <= 16 && !digits.empty()) {
            int64_t value = 0;
            for (char c : digits) {
                if (c == '_') continue;
                int d = 0;
                if (c >= '0' && c <= '9') d = c - '0';
                else if (c >= 'a' && c <= 'f') d = c - 'a' + 10;
                else if (c >= 'A' && c <= 'F') d = c - 'A' + 10;
                else { d = -1; break; }
                if (d >= base) { d = -1; break; }
                value = value * base + d;
            }
            auto tok = std::make_shared<Numeric_token>(std::to_string(value));
            return tok;
        }
    }

    // Real literal (contains '.', or exponent without a base prefix).
    bool is_real = text.find('.') != std::string::npos;
    if (!is_real) {
        // exponent like 1e3 or 1E-3
        size_t epos = text.find_first_of("eE");
        is_real = epos != std::string::npos;
    }
    if (is_real) {
        std::string cleaned = text;
        cleaned.erase(std::remove(cleaned.begin(), cleaned.end(), '_'), cleaned.end());
        return std::make_shared<Real_token>(cleaned);
    }

    // Plain integer (underscores are handled by Numeric_token).
    return std::make_shared<Numeric_token>(text);
}
