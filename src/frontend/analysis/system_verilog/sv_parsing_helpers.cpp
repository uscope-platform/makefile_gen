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
//  limitations under the License.

#include "frontend/analysis/system_verilog/sv_parsing_helpers.hpp"

namespace {

    bool is_hex_digit(const char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    }

    // \d+(\.\d+)?
    bool is_time_number(const std::string_view &s) {
        if (s.empty()) return false;
        size_t int_end = s.find_first_not_of("0123456789");
        if (int_end == std::string_view::npos) return true;
        if (int_end == 0 || s[int_end] != '.') return false;
        auto frac = s.substr(int_end + 1);
        if (frac.empty()) return false;
        return frac.find_first_not_of("0123456789") == std::string_view::npos;
    }

    // \d+(\.\d+)?(s|ms|us|ns|ps|fs)
    bool is_time_literal(const std::string_view &s) {
        static const std::string_view units[] = {"fs", "ps", "ns", "us", "ms", "s"};
        for (const auto &unit : units) {
            if (s.size() > unit.size() && s.ends_with(unit))
                return is_time_number(s.substr(0, s.size() - unit.size()));
        }
        return false;
    }

    // ^[+\-]?(\d+\.\d*|\.\d+)([eE][+\-]?\d+)?$ | ^[+\-]?\d+[eE][+\-]?\d+$
    bool is_real_literal(const std::string_view &s) {
        size_t i = 0;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) i++;
        if (i >= s.size()) return false;

        size_t int_end = s.find_first_not_of("0123456789", i);
        bool has_int = int_end != i;
        if (int_end == std::string_view::npos) return false;

        if (s[int_end] == '.') {
            size_t frac_end = s.find_first_not_of("0123456789", int_end + 1);
            if (!has_int && (frac_end == int_end + 1 || int_end + 1 >= s.size())) return false;
            if (frac_end == std::string_view::npos) return true;
            if (s[frac_end] != 'e' && s[frac_end] != 'E') return false;
            int_end = frac_end;
        } else if (s[int_end] == 'e' || s[int_end] == 'E') {
            if (!has_int) return false;
        } else {
            return false;
        }

        size_t exp_digits = int_end + 1;
        if (exp_digits < s.size() && (s[exp_digits] == '+' || s[exp_digits] == '-')) exp_digits++;
        if (exp_digits >= s.size()) return false;
        return s.find_first_not_of("0123456789", exp_digits) == std::string_view::npos;
    }

    // ^\d+$
    bool is_unsigned_integer(const std::string_view &s) {
        return !s.empty() && s.find_first_not_of("0123456789") == std::string_view::npos;
    }

    // ^\d*'(s)?(h|d|o|b)([0-9a-fA-F]+)  (prefix match, matching ctre::search semantics)
    bool is_sized_literal(const std::string_view &s) {
        size_t int_end = s.find_first_not_of("0123456789");
        if (int_end == std::string_view::npos || int_end >= s.size() || s[int_end] != '\'') return false;
        size_t i = int_end + 1;
        if (i < s.size() && s[i] == 's') i++;
        if (i >= s.size() || !(s[i] == 'h' || s[i] == 'd' || s[i] == 'o' || s[i] == 'b')) return false;
        return i + 1 < s.size() && is_hex_digit(s[i + 1]);
    }

}

namespace sv_parsing_helpers {

    qualified_identifier parse_qualified_identifier(mgp_sv::sv2017::Package_or_class_scoped_pathContext *ctx) {
        auto items = ctx->package_or_class_scoped_path_item();
        auto d_colon = ctx->DOUBLE_COLON();

        if (d_colon.empty()) {
            return qualified_identifier(ctx->getText());
        }

        std::vector<std::string> prefix;
        std::string name;

        unsigned int first_item = 0;

        if (ctx->KW_DOLAR_UNIT()) {
            prefix.push_back("$unit");
            first_item = 0;
        } else if (ctx->KW_DOLAR_ROOT()) {
            prefix.push_back("$root");
            first_item = 0;
        } else if (ctx->implicit_class_handle()) {
            prefix.push_back(ctx->implicit_class_handle()->getText());
            first_item = 0;
        }

        unsigned int n_segments = items.size();
        for (unsigned int i = first_item; i < n_segments - 1; ++i) {
            prefix.push_back(items[i]->identifier()->getText());
        }
        name = items[n_segments - 1]->identifier()->getText();

        qualified_identifier qi(name);
        if (!prefix.empty()) {
            qi.set_package_prefix(prefix);
        }
        return qi;
    }

    std::shared_ptr<Expression_base> make_value(const std::string &s) {
        if (is_time_literal(s)) {
            return std::make_shared<Time_token>(s);
        }
        if (is_real_literal(s)) {
            return std::make_shared<Real_token>(s);
        }
        if (is_unsigned_integer(s) || is_sized_literal(s)) {
            return std::make_shared<Numeric_token>(s);
        }
        if (s.starts_with("\"")) {
            return std::make_shared<String_token>(s);
        }
        return std::make_shared<Identifier_token>(qualified_identifier(s));
    }

}
