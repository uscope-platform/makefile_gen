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

#include "data_model/HDL/parameters/components/HDL_function_call.hpp"
#include "data_model/HDL/parameters/components/token/Identifier_token.hpp"
#include "data_model/HDL/parameters/components/token/Numeric_token.hpp"
#include "data_model/HDL/parameters/components/Replication.hpp"
#include "data_model/HDL/types/HDL_struct_type.hpp"
#include "data_model/HDL/types/HDL_simple_type.hpp"
#include "data_model/HDL/types/HDL_external_type.hpp"
#include "data_model/HDL/types/HDL_enum_type.hpp"
#include "data_model/HDL/types/HDL_union_type.hpp"
#include "analysis/type_cast_engine.hpp"

#include "analysis/loop_solver.hpp"

#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <sstream>


CEREAL_REGISTER_TYPE(HDL_function_call)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Expression_base, HDL_function_call)

void HDL_function_call::add_argument(const std::shared_ptr<Expression_base> &p) {
    arguments.push_back(p);
}

parameter_deps_t HDL_function_call::get_dependencies() const {
    parameter_deps_t retval;
    for (auto &arg:arguments) {
        retval.merge(arg->get_dependencies());
    }
    for(auto &s:body) {
        retval.merge(s->get_dependencies());
    }
    retval.functions.insert(qualified_identifier(package_prefix, function_name));
    return retval;
}


void HDL_function_call::propagate_function(const hdl_function_statement &def) {
    if(def.get_name() == function_name) {
        body.clear();
        for (const auto &stmt : def.get_body())
            body.push_back(stmt->clone());
        return_type = def.get_return_type();
        auto arg_names = def.get_arguments_names();
        for (int i =0;i<arg_names.size(); i++) {
            if (i >= static_cast<int>(arguments.size())) break;
            auto arg_val = arguments[i];
            for (auto &stmt : body) {
                if (auto asgn = std::dynamic_pointer_cast<hdl_assignment_statement>(stmt)) {
                    if (asgn->get_value())
                        asgn->get_value()->propagate_expression(qualified_identifier(arg_names[i]), arg_val);
                    if (asgn->get_index())
                        asgn->get_index()->propagate_expression(qualified_identifier(arg_names[i]), arg_val);
                }
            }
        }
    }
}

void HDL_function_call::walk_body(
    const std::string &fcn_name,
    const std::vector<std::shared_ptr<hdl_statement_base>> &stmts,
    std::map<qualified_identifier, resolved_parameter> ctx,
    std::map<int64_t, hdl_integer> &value_map,
    std::map<int64_t, int64_t> &size_map,
    const std::shared_ptr<hdl_type> &rt
) {
    for (const auto &stmt : stmts) {
        if (auto asgn = std::dynamic_pointer_cast<hdl_assignment_statement>(stmt)) {
            if (!asgn->get_value()) continue;
            auto val = asgn->get_value()->evaluate(ctx);
            if (!val.has_value()) continue;

            const auto &target = asgn->get_target();
            if (target == fcn_name) {
                int64_t idx = 0;
                if (asgn->get_index()) {
                    auto idx_res = asgn->get_index()->evaluate(ctx);
                    if (!idx_res.has_value() || !idx_res.value().is_integer()) continue;
                    idx = idx_res.value().get_integer().get_value();
                }
                if (val.value().is_integer()) {
                    value_map[idx] = val.value().get_integer();
                    size_map[idx] = val.value().get_integer().get_size();
                } else if (val.value().is_int_array()) {
                    value_map[idx] = val.value().get_int_array().get_1d_slice({0, 0})[0];
                    size_map[idx] = 0;
                }
            } else if (rt && rt->is<HDL_struct_type>() && target.starts_with(fcn_name + ".")) {
                std::string field_name = target.substr(fcn_name.size() + 1);
                const auto& members = rt->as<HDL_struct_type>().member;
                for (size_t i = 0; i < members.size(); ++i) {
                    if (members[i].name == field_name) {
                        int64_t idx = static_cast<int64_t>(i);
                        if (asgn->get_index()) {
                            auto idx_res = asgn->get_index()->evaluate(ctx);
                            if (!idx_res.has_value() || !idx_res.value().is_integer()) continue;
                            idx = idx_res.value().get_integer().get_value();
                        }
                        if (val.value().is_integer()) {
                            value_map[idx] = val.value().get_integer();
                            size_map[idx] = val.value().get_integer().get_size();
                        } else if (val.value().is_int_array()) {
                            value_map[idx] = val.value().get_int_array().get_1d_slice({0, 0})[0];
                            size_map[idx] = 0;
                        }
                        break;
                    }
                }
            } else {
                ctx[qualified_identifier(target)] = val.value();
            }
        } else if (auto loop = std::dynamic_pointer_cast<hdl_loop_statement>(stmt)) {
            auto indices = loop_solver::solve_loop(*loop, ctx);
            auto loop_var = loop->get_init()->get_identifier();
            for (auto &idx : indices) {
                auto loop_ctx = ctx;
                loop_ctx[loop_var] = resolved_parameter(idx);
                walk_body(fcn_name, loop->get_body(), loop_ctx, value_map, size_map, rt);
            }
        } else if (auto cond = std::dynamic_pointer_cast<hdl_conditional_statement>(stmt)) {
            bool matched = false;
            for (auto &branch : cond->get_branches()) {
                if (branch.condition) {
                    auto result = branch.condition->evaluate(ctx);
                    if (result.has_value() && result.value().is_integer() && result.value().get_integer() != 0) {
                        matched = true;
                        walk_body(fcn_name, branch.body, ctx, value_map, size_map, rt);
                        break;
                    }
                }
            }
            if (!matched)
                walk_body(fcn_name, cond->get_else_body(), ctx, value_map, size_map, rt);
        }
    }
}

std::optional<resolved_parameter> HDL_function_call::evaluate(const std::map<qualified_identifier, resolved_parameter> &context) {
    if (function_name.starts_with("$")) {
        return evaluate_system_task(context);
    }
    if (body.empty()) return std::nullopt;

    std::map<int64_t, hdl_integer> value_map;
    std::map<int64_t, int64_t> size_map;
    walk_body(function_name, body, context, value_map, size_map, return_type);

    if (value_map.empty()) return std::nullopt;

    size_t max_idx = static_cast<size_t>(value_map.rbegin()->first) + 1;
    std::vector<hdl_integer> values(max_idx);
    std::vector<int64_t> sizes(max_idx);
    for (auto &[idx, val] : value_map) {
        if (idx >= 0 && static_cast<size_t>(idx) < max_idx) {
            values[idx] = val;
            sizes[idx] = size_map[idx];
        }
    }

    if (values.size() == 1) {
        return resolved_parameter(values[0]);
    }

    apply_return_order_reversal(values, sizes, context);

    if (packing) {
        return resolved_parameter(pack_values(values, sizes));
    }

    mdarray<hdl_integer> result;
    result.set_1d_slice({0, 0}, values);
    return result;
}

void HDL_function_call::apply_return_order_reversal(
    std::vector<hdl_integer> &values,
    std::vector<int64_t> &value_sizes,
    const std::map<qualified_identifier, resolved_parameter> &context
) {
    if (packing || !has_return_unpacked_ascending) return;
    if (return_unpacked_ascending != container_unpacked_ascending) {
        std::reverse(values.begin(), values.end());
        std::reverse(value_sizes.begin(), value_sizes.end());
    }
}

namespace {

std::string unquote(const std::string &s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"')
        return s.substr(1, s.size() - 2);
    return s;
}

std::string to_binary_string(int1024_t v, int width) {
    if (v == 0) return width > 0 ? std::string(width, '0') : "0";
    std::string s;
    while (v != 0) {
        s.push_back((v & 1) ? '1' : '0');
        v >>= 1;
    }
    std::reverse(s.begin(), s.end());
    if (width > 0 && static_cast<int>(s.size()) < width) s = std::string(width - s.size(), '0') + s;
    return s;
}

std::string format_value(const resolved_parameter &arg, char spec, int width, bool zero_pad) {
    std::ostringstream piece;
    switch (spec) {
        case 'd': case 'i':
            if (arg.is_real()) piece << static_cast<int64_t>(arg.get_real());
            else if (arg.is_integer()) piece << arg.get_integer().to_wide();
            else if (arg.is_string()) piece << arg.get_string();
            else piece << 0;
            break;
        case 'x': case 'h':
            piece << std::hex;
            if (zero_pad && width > 0) piece << std::setw(width) << std::setfill('0');
            if (arg.is_integer()) piece << arg.get_integer().to_wide();
            else if (arg.is_real()) piece << static_cast<int64_t>(arg.get_real());
            else piece << 0;
            break;
        case 'X': case 'H':
            piece << std::hex << std::uppercase;
            if (zero_pad && width > 0) piece << std::setw(width) << std::setfill('0');
            if (arg.is_integer()) piece << arg.get_integer().to_wide();
            else if (arg.is_real()) piece << static_cast<int64_t>(arg.get_real());
            else piece << 0;
            break;
        case 'o':
            piece << std::oct;
            if (zero_pad && width > 0) piece << std::setw(width) << std::setfill('0');
            if (arg.is_integer()) piece << arg.get_integer().to_wide();
            else if (arg.is_real()) piece << static_cast<int64_t>(arg.get_real());
            else piece << 0;
            break;
        case 'b':
            if (arg.is_integer()) piece << to_binary_string(arg.get_integer().to_wide(), zero_pad ? width : 0);
            else if (arg.is_real()) piece << to_binary_string(static_cast<int64_t>(arg.get_real()), zero_pad ? width : 0);
            else piece << 0;
            break;
        case 's':
            if (arg.is_string()) piece << unquote(arg.get_string());
            else if (arg.is_integer()) piece << arg.get_integer().to_string();
            else if (arg.is_real()) piece << arg.get_real();
            break;
        case 'f': case 'F':
            if (arg.is_real()) piece << std::fixed << arg.get_real();
            else if (arg.is_integer()) piece << std::fixed << static_cast<double>(arg.get_integer().to_wide());
            else piece << std::fixed << 0.0;
            break;
        case 'e': case 'E':
            if (arg.is_real()) piece << std::scientific << arg.get_real();
            else if (arg.is_integer()) piece << std::scientific << static_cast<double>(arg.get_integer().to_wide());
            else piece << std::scientific << 0.0;
            break;
        case 'g': case 'G':
            if (arg.is_real()) piece << arg.get_real();
            else if (arg.is_integer()) piece << static_cast<double>(arg.get_integer().to_wide());
            else piece << 0.0;
            break;
        default:
            piece << "%" << spec;
            break;
    }
    return piece.str();
}

std::string format_string(const std::string &fmt, const std::vector<resolved_parameter> &args) {
    std::ostringstream out;
    size_t arg_idx = 0;
    for (size_t i = 0; i < fmt.size(); i++) {
        if (fmt[i] != '%') { out << fmt[i]; continue; }
        i++;
        if (i >= fmt.size()) { out << "%"; break; }
        if (fmt[i] == '%') { out << "%"; continue; }
        bool zero_pad = false;
        if (fmt[i] == '0') { zero_pad = true; i++; }
        int width = 0;
        while (i < fmt.size() && std::isdigit(static_cast<unsigned char>(fmt[i]))) {
            width = width * 10 + (fmt[i] - '0');
            i++;
        }
        if (i >= fmt.size()) break;
        char spec = fmt[i];
        if (arg_idx >= args.size()) { out << "%" << spec; continue; }
        out << format_value(args[arg_idx++], spec, width, zero_pad);
    }
    return out.str();
}

} // namespace

std::optional<resolved_parameter> HDL_function_call::evaluate_system_task(const std::map<qualified_identifier, resolved_parameter> &context) {
    std::string task_name = function_name.substr(1, function_name.size()-1);
    if (task_name == "bits" || task_name == "size" || task_name == "left" || task_name == "right" ||
        task_name == "high" || task_name == "low" || task_name == "dimensions" || task_name == "unpacked_dimensions") {
        return evaluate_type_query(context, task_name);
    }
    if (task_name == "typename") {
        return evaluate_typename(context);
    }
    if (task_name == "signed" || task_name == "unsigned") {
        return evaluate_signedness(context, task_name);
    }

    std::vector<resolved_parameter> resolved_arguments;
    for (auto &arg:arguments) {
        auto resolved_val = arg->evaluate(context);
        if (!resolved_val.has_value()) return std::nullopt;
        resolved_arguments.push_back(resolved_val.value());
    }
    if (resolved_arguments.empty()) {
        spdlog::warn("System task {} requires at least one argument", function_name);
        return std::nullopt;
    }
    if (task_name == "rtoi") {
        if (resolved_arguments[0].is_real()) {
            return static_cast<hdl_integer>(std::trunc(resolved_arguments[0].get_real()));
        }
        if (resolved_arguments[0].is_integer()) {
            return resolved_arguments[0].get_integer();
        }
        spdlog::warn("Encountered an invalid argument for a $rtoi call");
        return  0;
    }
    if (task_name == "itor") {
        if (resolved_arguments[0].is_real()) {
            return resolved_arguments[0].get_real();
        } else if (resolved_arguments[0].is_integer()) {
            return static_cast<double>(resolved_arguments[0].get_integer().get_value());
        }
        spdlog::warn("Encountered an invalid argument for a $itor call");
        return  0;
    }
    if (task_name == "ceil") {
        if (resolved_arguments[0].is_real()) {
            return std::ceil(resolved_arguments[0].get_real());
        } else if (resolved_arguments[0].is_integer()) {
            return resolved_arguments[0].get_integer();
        }
        spdlog::warn("Encountered an invalid argument for a $ceil call");
    }
    if (task_name == "floor") {
        if (resolved_arguments[0].is_real()) {
            return std::floor(resolved_arguments[0].get_real());
        } else if (resolved_arguments[0].is_integer()) {
            return resolved_arguments[0].get_integer();
        }
        spdlog::warn("Encountered an invalid argument for a $floor call");

    }
    if (task_name == "ln") {
        double arg = resolved_arguments[0].is_real() ? resolved_arguments[0].get_real()
                     : static_cast<double>(resolved_arguments[0].get_integer().get_value());
        if (arg <= 0) { spdlog::warn("$ln argument must be positive"); return 0; }
        return std::log(arg);
    }
    if (task_name == "log10") {
        double arg = resolved_arguments[0].is_real() ? resolved_arguments[0].get_real()
                     : static_cast<double>(resolved_arguments[0].get_integer().get_value());
        if (arg <= 0) { spdlog::warn("$log10 argument must be positive"); return 0; }
        return std::log10(arg);
    }
    if (task_name == "sqrt") {
        double arg = resolved_arguments[0].is_real() ? resolved_arguments[0].get_real()
                     : static_cast<double>(resolved_arguments[0].get_integer().get_value());
        if (arg < 0) { spdlog::warn("$sqrt argument must be non-negative"); return 0; }
        return std::sqrt(arg);
    }
    if (task_name == "pow") {
        if (resolved_arguments.size() < 2) {
            spdlog::warn("$pow requires exactly 2 arguments");
            return 0;
        }
        double base = resolved_arguments[0].is_real()
                          ? resolved_arguments[0].get_real()
                          : static_cast<double>(resolved_arguments[0].get_integer().get_value());
        double exponent = resolved_arguments[1].is_real()
                              ? resolved_arguments[1].get_real()
                              : static_cast<double>(resolved_arguments[1].get_integer().get_value());
        return std::pow(base, exponent);
    }
    if (task_name == "min") {
        if (resolved_arguments.empty()) {
            spdlog::warn("$min requires at least 1 argument");
            return 0;
        }
        if (resolved_arguments.size() == 1) return resolved_arguments[0];
        bool all_int = std::ranges::all_of(resolved_arguments, [](const auto &a) { return a.is_integer(); });
        if (all_int) {
            auto result = resolved_arguments[0].get_integer();
            for (size_t i = 1; i < resolved_arguments.size(); i++) {
                if (resolved_arguments[i].get_integer() < result) result = resolved_arguments[i].get_integer();
            }
            return result;
        } else {
            double result = resolved_arguments[0].is_real()
                                ? resolved_arguments[0].get_real()
                                : static_cast<double>(resolved_arguments[0].get_integer().get_value());
            for (size_t i = 1; i < resolved_arguments.size(); i++) {
                double v = resolved_arguments[i].is_real()
                               ? resolved_arguments[i].get_real()
                               : static_cast<double>(resolved_arguments[i].get_integer().get_value());
                if (v < result) result = v;
            }
            return result;
        }
    }
    if (task_name == "max") {
        if (resolved_arguments.empty()) {
            spdlog::warn("$max requires at least 1 argument");
            return 0;
        }
        if (resolved_arguments.size() == 1) return resolved_arguments[0];
        bool all_int = std::ranges::all_of(resolved_arguments, [](const auto &a) { return a.is_integer(); });
        if (all_int) {
            auto result = resolved_arguments[0].get_integer();
            for (size_t i = 1; i < resolved_arguments.size(); i++) {
                if (result < resolved_arguments[i].get_integer()) result = resolved_arguments[i].get_integer();
            }
            return result;
        } else {
            double result = resolved_arguments[0].is_real()
                                ? resolved_arguments[0].get_real()
                                : static_cast<double>(resolved_arguments[0].get_integer().get_value());
            for (size_t i = 1; i < resolved_arguments.size(); i++) {
                double v = resolved_arguments[i].is_real()
                               ? resolved_arguments[i].get_real()
                               : static_cast<double>(resolved_arguments[i].get_integer().get_value());
                if (result < v) result = v;
            }
            return result;
        }
    }
    if (task_name == "countones") {
        if (resolved_arguments[0].is_integer()) {
            uint64_t val = static_cast<uint64_t>(resolved_arguments[0].get_integer().get_value());
            return static_cast<hdl_integer>(std::popcount(val));
        }
        spdlog::warn("Encountered an invalid argument for a $countones call");
        return 0;
    }
    if (task_name == "sin") {
        if (resolved_arguments[0].is_real()) return std::sin(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::sin(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $sin call");
        return 0;
    }
    if (task_name == "cos") {
        if (resolved_arguments[0].is_real()) return std::cos(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::cos(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $cos call");
        return 0;
    }
    if (task_name == "tan") {
        if (resolved_arguments[0].is_real()) return std::tan(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::tan(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $tan call");
        return 0;
    }
    if (task_name == "sinh") {
        if (resolved_arguments[0].is_real()) return std::sinh(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::sinh(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $sinh call");
        return 0;
    }
    if (task_name == "cosh") {
        if (resolved_arguments[0].is_real()) return std::cosh(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::cosh(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $cosh call");
        return 0;
    }
    if (task_name == "tanh") {
        if (resolved_arguments[0].is_real()) return std::tanh(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::tanh(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $tanh call");
        return 0;
    }
    if (task_name == "asinh") {
        if (resolved_arguments[0].is_real()) return std::asinh(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::asinh(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $asinh call");
        return 0;
    }
    if (task_name == "acosh") {
        if (resolved_arguments[0].is_real()) return std::acosh(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::acosh(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $acosh call");
        return 0;
    }
    if (task_name == "atanh") {
        if (resolved_arguments[0].is_real()) return std::atanh(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::atanh(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $atanh call");
        return 0;
    }
    if (task_name == "exp") {
        if (resolved_arguments[0].is_real()) return std::exp(resolved_arguments[0].get_real());
        if (resolved_arguments[0].is_integer()) return std::exp(static_cast<double>(resolved_arguments[0].get_integer().get_value()));
        spdlog::warn("Encountered an invalid argument for a $exp call");
        return 0;
    }
    if (task_name == "hypot") {
        if (resolved_arguments.size() < 2) { spdlog::warn("$hypot requires exactly 2 arguments"); return 0; }
        double a = resolved_arguments[0].is_real() ? resolved_arguments[0].get_real()
                    : static_cast<double>(resolved_arguments[0].get_integer().get_value());
        double b = resolved_arguments[1].is_real() ? resolved_arguments[1].get_real()
                    : static_cast<double>(resolved_arguments[1].get_integer().get_value());
        return std::hypot(a, b);
    }
    if (task_name == "onehot") {
        if (resolved_arguments[0].is_integer()) {
            uint64_t v = static_cast<uint64_t>(resolved_arguments[0].get_integer().get_value());
            return static_cast<hdl_integer>(v != 0 && std::popcount(v) == 1);
        }
        spdlog::warn("Encountered an invalid argument for a $onehot call");
        return 0;
    }
    if (task_name == "onehot0") {
        if (resolved_arguments[0].is_integer()) {
            uint64_t v = static_cast<uint64_t>(resolved_arguments[0].get_integer().get_value());
            return static_cast<hdl_integer>(std::popcount(v) <= 1);
        }
        spdlog::warn("Encountered an invalid argument for a $onehot0 call");
        return 0;
    }
    if (task_name == "isunknown") {
        return 0;
    }
    if (task_name == "isunbounded") {
        // No unbounded types are representable in this tool, so this always
        // resolves to false in constant evaluation.
        return 0;
    }
    if (task_name == "clog2") {
        if (resolved_arguments[0].is_real()) {
            return static_cast<hdl_integer>(std::ceil(std::log2(resolved_arguments[0].get_real())));
        } else if (resolved_arguments[0].is_integer()) {
            auto arg = resolved_arguments[0].get_integer().to_wide();
            if (arg <= 1) return static_cast<hdl_integer>(0);
            int bits = 0;
            auto tmp = arg - 1;
            while (tmp != 0) { tmp >>= 1; bits++; }
            return static_cast<hdl_integer>(bits);
        }
        spdlog::warn("Encountered an invalid argument for a $clog2 call");
    }

    auto to_double = [](const resolved_parameter &p) -> std::optional<double> {
        if (p.is_real()) return p.get_real();
        if (p.is_integer()) return static_cast<double>(p.get_integer().to_wide());
        return std::nullopt;
    };

    if (task_name == "log2") {
        auto arg = to_double(resolved_arguments[0]);
        if (!arg) { spdlog::warn("Encountered an invalid argument for a $log2 call"); return 0; }
        if (*arg <= 0) { spdlog::warn("$log2 argument must be positive"); return 0; }
        return std::log2(*arg);
    }
    if (task_name == "asin") {
        auto arg = to_double(resolved_arguments[0]);
        if (!arg) { spdlog::warn("Encountered an invalid argument for a $asin call"); return 0; }
        if (*arg < -1.0 || *arg > 1.0) { spdlog::warn("$asin argument must be in the range [-1, 1]"); return 0; }
        return std::asin(*arg);
    }
    if (task_name == "acos") {
        auto arg = to_double(resolved_arguments[0]);
        if (!arg) { spdlog::warn("Encountered an invalid argument for a $acos call"); return 0; }
        if (*arg < -1.0 || *arg > 1.0) { spdlog::warn("$acos argument must be in the range [-1, 1]"); return 0; }
        return std::acos(*arg);
    }
    if (task_name == "atan") {
        auto arg = to_double(resolved_arguments[0]);
        if (!arg) { spdlog::warn("Encountered an invalid argument for a $atan call"); return 0; }
        return std::atan(*arg);
    }
    if (task_name == "atan2") {
        if (resolved_arguments.size() < 2) { spdlog::warn("$atan2 requires exactly 2 arguments"); return 0; }
        auto y = to_double(resolved_arguments[0]);
        auto x = to_double(resolved_arguments[1]);
        if (!y || !x) { spdlog::warn("Encountered an invalid argument for a $atan2 call"); return 0; }
        return std::atan2(*y, *x);
    }
    if (task_name == "round") {
        auto arg = to_double(resolved_arguments[0]);
        if (!arg) { spdlog::warn("Encountered an invalid argument for a $round call"); return 0; }
        return std::round(*arg);
    }
    if (task_name == "truncate") {
        auto arg = to_double(resolved_arguments[0]);
        if (!arg) { spdlog::warn("Encountered an invalid argument for a $truncate call"); return 0; }
        return std::trunc(*arg);
    }
    if (task_name == "countbits") {
        if (resolved_arguments.size() < 2) { spdlog::warn("$countbits requires exactly 2 arguments"); return 0; }
        if (!resolved_arguments[0].is_integer() || !resolved_arguments[1].is_integer()) {
            spdlog::warn("Encountered an invalid argument for a $countbits call");
            return 0;
        }
        int1024_t ctrl = resolved_arguments[1].get_integer().to_wide();
        int ctrl_width = 1;
        auto ctrl_type = arguments[1]->resolve_expression_type(context);
        if (ctrl_type) ctrl_width = std::max(1, static_cast<int>(packed_width(*ctrl_type)));
        else ctrl_width = std::max(1, static_cast<int>(resolved_arguments[1].get_integer().get_size()));
        bool count_ones = false, count_zeros = false;
        for (int i = 0; i < ctrl_width; i++) {
            if ((ctrl >> i) & 1) count_ones = true; else count_zeros = true;
        }
        int1024_t value = resolved_arguments[0].get_integer().to_wide();
        int expr_width = 64;
        auto expr_type = arguments[0]->resolve_expression_type(context);
        if (expr_type) expr_width = static_cast<int>(packed_width(*expr_type));
        else expr_width = std::max(1, static_cast<int>(resolved_arguments[0].get_integer().get_size()));
        int64_t count = 0;
        for (int i = 0; i < expr_width && i < 1024; i++) {
            bool bit = ((value >> i) & 1) != 0;
            if (bit && count_ones) count++;
            if (!bit && count_zeros) count++;
        }
        return static_cast<hdl_integer>(count);
    }
    if (task_name == "realtobits") {
        if (resolved_arguments[0].is_real()) {
            double d = resolved_arguments[0].get_real();
            uint64_t bits;
            std::memcpy(&bits, &d, sizeof(bits));
            return static_cast<hdl_integer>(bits);
        }
        spdlog::warn("Encountered an invalid argument for a $realtobits call");
        return 0;
    }
    if (task_name == "bitstoreal") {
        if (resolved_arguments[0].is_integer()) {
            uint64_t bits = static_cast<uint64_t>(resolved_arguments[0].get_integer().to_wide());
            double d;
            std::memcpy(&d, &bits, sizeof(d));
            return d;
        }
        spdlog::warn("Encountered an invalid argument for a $bitstoreal call");
        return 0;
    }
    if (task_name == "shortrealtobits") {
        if (resolved_arguments[0].is_real()) {
            float f = static_cast<float>(resolved_arguments[0].get_real());
            uint32_t bits;
            std::memcpy(&bits, &f, sizeof(bits));
            return static_cast<hdl_integer>(bits);
        }
        spdlog::warn("Encountered an invalid argument for a $shortrealtobits call");
        return 0;
    }
    if (task_name == "bitstoshortreal") {
        if (resolved_arguments[0].is_integer()) {
            uint32_t bits = static_cast<uint32_t>(resolved_arguments[0].get_integer().to_wide());
            float f;
            std::memcpy(&f, &bits, sizeof(f));
            return static_cast<double>(f);
        }
        spdlog::warn("Encountered an invalid argument for a $bitstoshortreal call");
        return 0;
    }
    if (task_name == "random" || task_name == "urandom" || task_name == "urandom_range" || task_name.starts_with("dist_")) {
        spdlog::warn("{} is not supported in constant expressions, defaulting to 0", function_name);
        return 0;
    }
    if (task_name == "len") {
        if (resolved_arguments[0].is_string()) {
            return static_cast<hdl_integer>(unquote(resolved_arguments[0].get_string()).size());
        }
        spdlog::warn("Encountered an invalid argument for a $len call");
        return 0;
    }
    if (task_name == "to_lower") {
        if (resolved_arguments[0].is_string()) {
            auto s = unquote(resolved_arguments[0].get_string());
            std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
            return s;
        }
        spdlog::warn("Encountered an invalid argument for a $to_lower call");
        return std::string("");
    }
    if (task_name == "to_upper") {
        if (resolved_arguments[0].is_string()) {
            auto s = unquote(resolved_arguments[0].get_string());
            std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::toupper(c); });
            return s;
        }
        spdlog::warn("Encountered an invalid argument for a $to_upper call");
        return std::string("");
    }
    if (task_name == "atoi") {
        if (resolved_arguments[0].is_string()) {
            const auto s = unquote(resolved_arguments[0].get_string());
            size_t i = 0;
            bool neg = false;
            if (i < s.size() && (s[i] == '+' || s[i] == '-')) { neg = (s[i] == '-'); i++; }
            int64_t val = 0;
            bool any = false;
            while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i]))) {
                val = val * 10 + (s[i] - '0');
                any = true;
                i++;
            }
            if (!any) return static_cast<hdl_integer>(0);
            return static_cast<hdl_integer>(neg ? -val : val);
        }
        spdlog::warn("Encountered an invalid argument for a $atoi call");
        return 0;
    }
    if (task_name == "compare") {
        if (resolved_arguments.size() >= 2 && resolved_arguments[0].is_string() && resolved_arguments[1].is_string()) {
            int cmp = unquote(resolved_arguments[0].get_string()).compare(unquote(resolved_arguments[1].get_string()));
            return static_cast<hdl_integer>(cmp < 0 ? -1 : (cmp > 0 ? 1 : 0));
        }
        spdlog::warn("Encountered an invalid argument for a $compare call");
        return 0;
    }
    if (task_name == "substr") {
        if (resolved_arguments.size() < 3) { spdlog::warn("$substr requires exactly 3 arguments"); return std::string(""); }
        if (!resolved_arguments[0].is_string() || !resolved_arguments[1].is_integer() || !resolved_arguments[2].is_integer()) {
            spdlog::warn("Encountered an invalid argument for a $substr call");
            return std::string("");
        }
        const auto s = unquote(resolved_arguments[0].get_string());
        int64_t start = resolved_arguments[1].get_integer().get_value();
        int64_t end = resolved_arguments[2].get_integer().get_value();
        if (start < 0) start = 0;
        if (end >= static_cast<int64_t>(s.size())) end = static_cast<int64_t>(s.size()) - 1;
        if (start > end) return std::string("");
        return s.substr(static_cast<size_t>(start), static_cast<size_t>(end - start + 1));
    }
    if (task_name == "sformatf") {
        if (resolved_arguments[0].is_string()) {
            std::vector<resolved_parameter> fmt_args(resolved_arguments.begin() + 1, resolved_arguments.end());
            return format_string(unquote(resolved_arguments[0].get_string()), fmt_args);
        }
        spdlog::warn("Encountered an invalid argument for a $sformatf call");
        return std::string("");
    }
    spdlog::warn("Unsupported system task {} encountered while parsing a parameter", function_name);
    return 0;
}

namespace {

struct type_dimension {
    uint64_t size;
    int64_t left;
    int64_t right;
};

std::optional<resolved_type> resolve_argument_type(
    const std::shared_ptr<Expression_base> &arg,
    const std::map<qualified_identifier, resolved_parameter> &context
) {
    if (!arg) return std::nullopt;
    auto type = arg->resolve_expression_type(context);
    if (type) return type;

    auto val = arg->evaluate(context);
    if (!val) return std::nullopt;
    if (val->is_real()) {
        resolved_type result;
        result.is_real = true;
        return result;
    }
    if (val->is_integer()) {
        resolved_type result;
        auto width = val->get_integer().get_size();
        if (width == 0) width = 32;
        result.packed_sizes.push_back(width);
        result.packed_ascending.push_back(false);
        result.packed_left.push_back(static_cast<int64_t>(width) - 1);
        result.packed_right.push_back(0);
        return result;
    }
    return std::nullopt;
}

std::vector<type_dimension> collect_dimensions(const resolved_type &t) {
    std::vector<type_dimension> dims;
    for (size_t i = 0; i < t.unpacked_sizes.size(); i++) {
        bool asc = i < t.unpacked_ascending.size() ? t.unpacked_ascending[i] : false;
        int64_t left = i < t.unpacked_left.size()
            ? t.unpacked_left[i]
            : (asc ? 0 : static_cast<int64_t>(t.unpacked_sizes[i]) - 1);
        int64_t right = i < t.unpacked_right.size()
            ? t.unpacked_right[i]
            : (asc ? static_cast<int64_t>(t.unpacked_sizes[i]) - 1 : 0);
        dims.push_back({t.unpacked_sizes[i], left, right});
    }
    for (size_t i = 0; i < t.packed_sizes.size(); i++) {
        bool asc = i < t.packed_ascending.size() ? t.packed_ascending[i] : false;
        int64_t left = i < t.packed_left.size()
            ? t.packed_left[i]
            : (asc ? 0 : static_cast<int64_t>(t.packed_sizes[i]) - 1);
        int64_t right = i < t.packed_right.size()
            ? t.packed_right[i]
            : (asc ? static_cast<int64_t>(t.packed_sizes[i]) - 1 : 0);
        dims.push_back({t.packed_sizes[i], left, right});
    }
    return dims;
}

} // namespace

std::optional<resolved_parameter> HDL_function_call::evaluate_type_query(
    const std::map<qualified_identifier, resolved_parameter> &context, const std::string &task_name) {
    if (arguments.empty()) {
        spdlog::warn("${} requires at least one argument", task_name);
        return std::nullopt;
    }

    int dim = 1;
    if (arguments.size() >= 2) {
        auto dim_val = arguments[1]->evaluate(context);
        if (dim_val && dim_val->is_integer()) dim = dim_val->get_integer().get_value();
    }

    auto type = resolve_argument_type(arguments[0], context);

    if (task_name == "bits") {
        if (!type) {
            spdlog::warn("$bits argument type could not be resolved, defaulting to 0");
            return 0;
        }
        if (type->is_real) return static_cast<hdl_integer>(64);
        uint64_t bits = 1;
        bool any = false;
        for (auto s : type->packed_sizes) { bits *= s; any = true; }
        for (auto s : type->unpacked_sizes) { bits *= s; any = true; }
        if (!any) {
            spdlog::warn("$bits argument is of unsupported type, defaulting to 0");
            return 0;
        }
        return static_cast<hdl_integer>(bits);
    }

    if (task_name == "dimensions" || task_name == "unpacked_dimensions") {
        if (!type) {
            spdlog::warn("${} argument type could not be resolved, defaulting to 0", task_name);
            return 0;
        }
        if (type->is_real) return static_cast<hdl_integer>(0);
        if (task_name == "dimensions")
            return static_cast<hdl_integer>(type->packed_sizes.size() + type->unpacked_sizes.size());
        return static_cast<hdl_integer>(type->unpacked_sizes.size());
    }

    if (!type) {
        spdlog::warn("${} argument type could not be resolved, defaulting to 0", task_name);
        return 0;
    }
    if (type->is_real) {
        spdlog::warn("${} is not defined for real arguments, defaulting to 0", task_name);
        return 0;
    }
    auto dims = collect_dimensions(*type);
    if (dim < 1 || static_cast<size_t>(dim) > dims.size()) {
        spdlog::warn("${} dimension {} is out of range, defaulting to 0", task_name, dim);
        return 0;
    }
    const auto &d = dims[dim - 1];
    if (task_name == "size") return static_cast<hdl_integer>(d.size);
    if (task_name == "left") return static_cast<hdl_integer>(d.left);
    if (task_name == "right") return static_cast<hdl_integer>(d.right);
    if (task_name == "high") return static_cast<hdl_integer>(std::max(d.left, d.right));
    return static_cast<hdl_integer>(std::min(d.left, d.right));
}

std::optional<resolved_parameter> HDL_function_call::evaluate_typename(
    const std::map<qualified_identifier, resolved_parameter> &context) {
    if (arguments.empty()) {
        spdlog::warn("$typename requires at least one argument");
        return resolved_parameter("");
    }
    auto &arg = arguments[0];
    if (arg->is<Identifier_token>()) {
        auto t = arg->as<Identifier_token>().get_expression_type();
        if (t) {
            if (t->is<HDL_simple_type>())
                return resolved_parameter(t->as<HDL_simple_type>().get_type_name());
            if (t->is<HDL_struct_type>()) return resolved_parameter("struct");
            if (t->is<HDL_union_type>()) return resolved_parameter("union");
            if (t->is<HDL_enum_type>()) return resolved_parameter("enum");
            if (t->is<HDL_external_type>()) return resolved_parameter(t->as<HDL_external_type>().to_print());
        }
    }
    auto type = resolve_argument_type(arg, context);
    if (type) {
        if (type->is_real) return resolved_parameter("real");
        if (!type->packed_sizes.empty() || !type->unpacked_sizes.empty()) return resolved_parameter("logic");
    }
    auto val = arg->evaluate(context);
    if (val) {
        if (val->is_real()) return resolved_parameter("real");
        if (val->is_string()) return resolved_parameter("string");
        if (val->is_integer()) return resolved_parameter("integer");
    }
    spdlog::warn("$typename argument type could not be determined, defaulting to empty");
    return resolved_parameter("");
}

std::optional<resolved_parameter> HDL_function_call::evaluate_signedness(
    const std::map<qualified_identifier, resolved_parameter> &context, const std::string &task_name) {
    if (arguments.empty()) {
        spdlog::warn("${} requires at least one argument", task_name);
        return 0;
    }
    auto &arg = arguments[0];
    auto val = arg->evaluate(context);
    if (!val || !val->is_integer()) {
        spdlog::warn("Encountered an invalid argument for a ${} call", task_name);
        return 0;
    }

    uint64_t container = 32;
    auto type = arg->resolve_expression_type(context);
    if (type) {
        uint64_t width = packed_width(*type);
        if (width > 0) container = width;
    } else if (arg->is<Numeric_token>()) {
        auto &num = arg->as<Numeric_token>();
        if (num.is_sized_explicit() && num.get_size() > 0) container = static_cast<uint64_t>(num.get_size());
    }

    if (task_name == "signed") return type_cast_engine::to_signed(val->get_integer(), container);
    return type_cast_engine::to_unsigned(val->get_integer(), container);
}

std::optional<resolved_type> HDL_function_call::resolve_expression_type(
    const std::map<qualified_identifier, resolved_parameter> &context) const {
    if (function_name.starts_with("$")) {
        if ((function_name == "$signed" || function_name == "$unsigned") && !arguments.empty()) {
            return arguments[0]->resolve_expression_type(context);
        }
        if (function_name == "$bits" && !arguments.empty()) {
            return resolve_argument_type(arguments[0], context);
        }
    }
    if (return_type) {
        return return_type->evaluate_type(context);
    }
    return std::nullopt;
}

void HDL_function_call::set_container_sizes(const resolved_type &s, const std::map<qualified_identifier, resolved_parameter> &context) {
    packing = s.unpacked_sizes.empty();
    container_unpacked_ascending = s.unpacked_ascending.empty() ? true : s.unpacked_ascending[0];
    if (s.return_unpacked_ascending.has_value()) {
        return_unpacked_ascending = s.return_unpacked_ascending.value();
        has_return_unpacked_ascending = true;
    }
    if (s.packed_sizes.empty() && s.unpacked_sizes.empty()) return;
    for (auto &stmt : body) {
        if (auto asgn = std::dynamic_pointer_cast<hdl_assignment_statement>(stmt)) {
            if (asgn->get_value()) asgn->get_value()->set_container_sizes(s, context);
        } else if (auto loop = std::dynamic_pointer_cast<hdl_loop_statement>(stmt)) {
            for (auto &bs : loop->get_body()) {
                if (auto la = std::dynamic_pointer_cast<hdl_assignment_statement>(bs)) {
                    if (la->get_value()) la->get_value()->set_container_sizes(s, context);
                }
            }
        }
    }
}


std::string HDL_function_call::print() const {
    std::ostringstream result;
    if (!package_prefix.empty()) result<< package_prefix << "::";
    result << function_name << "(";
    for(int i = 0; i< arguments.size(); i++) {
        result << arguments[i]->print();
        if( arguments.size()>1 && i<arguments.size()-1) result << ", ";
    }
    result << ")";
    return result.str();
}

bool HDL_function_call::empty() const {
    return function_name.empty();
}

bool HDL_function_call::isEqual(const Expression_base &other) const {
    bool is_equal = true;


    const auto& rhs = static_cast<const HDL_function_call&>(other);
    is_equal &= function_name == rhs.function_name;
    if (arguments.size() != rhs.arguments.size()) return false;
    for (int i = 0; i< arguments.size(); i++) {
        is_equal &= *arguments[i] == *rhs.arguments[i];
    }
    is_equal &= body.size() == rhs.body.size();
    for (size_t i = 0; i < body.size(); i++)
        is_equal &= *body[i] == *rhs.body[i];
    is_equal &= package_prefix == rhs.package_prefix;
    return is_equal;
}
