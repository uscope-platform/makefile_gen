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


#include "frontend/analysis/preprocessor/sv_preprocessor.hpp"


sv_preprocessor:: sv_preprocessor(const std::filesystem::path &in) {
    path = in;
}

std::string sv_preprocessor::preprocess(const std::filesystem::path &in) {
    path = in;
    std::ifstream ifs(in);
    return preprocess(ifs);
}

std::string sv_preprocessor::preprocess(std::istream &in) {
    static constexpr auto identifier_pattern = ctre::search<R"(`([a-zA-Z_][a-zA-Z0-9_]*))">;
    definitions = {};

    std::ostringstream out;

    std::string line;
    line_number = 1;
    while (std::getline(in, line)) {
       std::string_view trimmed_line = ltrim(line);

        bool skipped_directive = trimmed_line.starts_with("`resetall")
        || trimmed_line.starts_with("`timescale")
        || trimmed_line.starts_with("`default_nettype")
        || trimmed_line.starts_with("`nounconnected_drive")
        || trimmed_line.starts_with("`unconnected_drive")
        || trimmed_line.starts_with("`endcelldefine")
        || trimmed_line.starts_with("`celldefine")
        || trimmed_line.starts_with("`pragma")
        || trimmed_line.starts_with("`end_keywords")
        || trimmed_line.starts_with("`begin_keywords")
        || trimmed_line.starts_with("`line");

        if (trimmed_line.starts_with("`define") && c_solver.is_active()) {
          parse_definition(trimmed_line, 7);
        } else if (trimmed_line.starts_with("`include")&& c_solver.is_active()) {

        } else if (trimmed_line.starts_with("`ifdef")) {
            auto condition = parse_one_arg_directive(trimmed_line, 6);
            c_solver.start_loop(definitions.contains(std::string(condition)));
        } else if (trimmed_line.starts_with("`ifndef")) {
            auto condition = parse_one_arg_directive(trimmed_line, 7);
            c_solver.start_loop(!definitions.contains(std::string(condition)));
        } else if (trimmed_line.starts_with("`elsif")) {
            auto condition = parse_one_arg_directive(trimmed_line, 6);
            c_solver.advance_elseif(definitions.contains(std::string(condition)));
        } else if (trimmed_line.starts_with("`else")) {
            c_solver.advance_else();
        } else if (trimmed_line.starts_with("`endif")) {
            c_solver.close_loop();
        } else if (trimmed_line.starts_with("`undef") && c_solver.is_active()) {
            auto identifier = parse_one_arg_directive(trimmed_line, 6);
            definitions.erase(std::string(identifier));
        } else if (trimmed_line.starts_with("`undefineall") && c_solver.is_active()) {
            definitions.clear();
        } else if (!skipped_directive && c_solver.is_active()) {

            std::string result;
            std::string_view remaining = line;

            while (auto match = identifier_pattern(remaining)) {
                result.append(remaining.begin(), match.begin());
                result.append(get_define_replacement(match));

                remaining = std::string_view{match.end(), remaining.end()};
            }

            result.append(remaining);

            out << result << std::endl;
        }
        line_number++;
    }
    auto retval = out.str();
    retval.pop_back();
    return retval;
}



std::string sv_preprocessor::get_define_replacement(const std::string_view &identifier) {
    std::string_view purged_identifier = {identifier.begin()+1, identifier.end()};
    std::string replacement;
    if (purged_identifier == "__FILE__") {
        replacement = "\"" + path + "\"";

    } else if (purged_identifier == "__LINE__"){
        replacement = std::to_string(line_number);
    } else {
        auto id = std::string(purged_identifier);
        if (!definitions.contains(id)) {
            throw std::runtime_error(fmt::format("{}:{} MACRO {} is not defined", path, line_number, id));
        }
        auto def = definitions.at(id);
        if (std::holds_alternative<std::string>(def)) {
            replacement = std::get<std::string>(def);
        }
    }
    return replacement;
}

std::string_view sv_preprocessor::ltrim(const std::string_view &in) {
    if (in.empty()) {
        return in;
    }
    const auto start = in.find_first_not_of(" \t");
    if (start == std::string_view::npos) {
        return in;
    }
    return in.substr(start);
}

void sv_preprocessor::parse_definition(const std::string_view &sv, int prefix_length) {
    auto trimmed_view = sv.substr(prefix_length);
    trimmed_view = trimmed_view.substr(trimmed_view.find_first_not_of("\t "));
    auto id_last = trimmed_view.find_first_of("\t (");
    auto identifier = trimmed_view.substr(0, id_last);
    if (id_last == std::string_view::npos) {
        definitions[std::string(identifier)] = "";
        return;
    }
    auto remaining_view = trimmed_view.substr(id_last+1);
    if (trimmed_view[id_last] == '(') {
        auto macro = parse_function_macro(trimmed_view.substr(id_last+1));
        if (!macro.has_value()) {
            throw std::runtime_error(fmt::format("The arguments list in macro {} is never closed [{}]", identifier, path));
        }
        definitions[std::string(identifier)] = macro.value();
    } else {
        auto value = remaining_view.substr(remaining_view.find_first_not_of("\t "));
        definitions[std::string(identifier)] =  std::string{value};
    }

}

std::string_view sv_preprocessor::parse_one_arg_directive(const std::string_view &sv, int prefix_length) {
    auto trimmed_line = sv.substr(prefix_length);
    return trimmed_line.substr( trimmed_line.find_first_not_of(' '));
}

std::optional<function_macro> sv_preprocessor::parse_function_macro(const std::string_view &in) {
    function_macro macro;
    int nesting_level = 0;
    int args_last = 0;
    for (; args_last< in.size(); args_last++) {
        if (in[args_last] == '(') nesting_level++;
        if (in[args_last] == ')') {
            if (nesting_level>0) nesting_level--;
            else break;
        }
    }
    if (args_last == in.size()-1) {
        return {};
    }
    auto raw_arguments = in.substr(0, args_last);
    nesting_level = 0;
    int current_arg_start = 0;
    for (int i = 0; i< raw_arguments.size(); i++) {
        const auto c = raw_arguments[i];
        if (c == '(' || c == '[' || c == '{') nesting_level++;
        if (c == ')' || c == ']' || c == '}') nesting_level--;
        if (c==',' && nesting_level == 0) {
            auto arg_text = raw_arguments.substr(current_arg_start, i-current_arg_start);
            current_arg_start = i+1;
            macro.arguments.emplace_back(ltrim(arg_text));
        }
    }
    macro.arguments.emplace_back(ltrim(raw_arguments.substr(current_arg_start, raw_arguments.size()-current_arg_start)));
    macro.value = ltrim(in.substr(args_last+1));
    return macro;
}

std::string sv_preprocessor::flatten_source(const std::string_view &in) {

    std::string result;
    result.reserve(in.size());
    size_t cursor = 0;
    bool in_string = false;
    bool in_macro = false;

    // Source flattening uses a search and append approach to be cache and SIMD friendly
    // The main loop keeps searching for potentially problematic characters and appends as needed
    while (cursor < in.size()) {

        size_t next = in.find_first_of("/\"\\`\n\r", cursor);

        if (next == std::string_view::npos) {
            result.append(in.substr(cursor));
            break;
        }

        if (next > cursor) {
            result.append(in.substr(cursor, next - cursor));
        }
        cursor = next;
        char trigger = in[cursor];

        if (trigger == '\n' || trigger == '\r') {
            in_macro = false;
            result.push_back(trigger);
            cursor++;
        } else if (trigger == '`') {
            auto directive = in.substr(cursor);
            if (directive.starts_with("`define")) {
                in_macro = true;
            }
            result.push_back('`');
            cursor++;
        } else if (trigger == '/') {
         if (cursor != in.size()-1) {
             if (in[cursor + 1] == '/') {
                 size_t end = in.find('\n', cursor + 2);
                 if (end == std::string_view::npos) end = in.size();
                 result.append(in.substr(cursor, end - cursor));
                 cursor = end;
             } else if (in[cursor + 1] == '*') {
                 size_t end = in.find("*/", cursor + 2);
                 if (end == std::string_view::npos) end = in.size() - 2;
                 result.append(in.substr(cursor, (end + 2) - cursor));
                 cursor = end + 2;
             }
             else {
                 result.push_back('/');
                 cursor++;
             }
         } else {
             result.push_back('/');
             cursor++;
         }
        } else if (trigger == '"') {
            if (in_string) {
                in_string = false;
            } else {
                in_string = true;
            }
            result.push_back('"');
            cursor++;
        } else if (trigger == '\\') {
            if (cursor + 1 < in.size()) {
                char next = in[cursor + 1];

                // skip backslash and newline when necessary
                if (next == '\n' || next == '\r') {
                    if (in_macro || in_string) {
                        cursor += (next == '\r' && in[cursor+2] == '\n') ? 3 : 2;

                        continue;
                    }
                }

                //keep escaped quotes as is
                if (in_string && next == '"') {
                    result.push_back('\\');
                    result.push_back('"');
                    cursor += 2;
                    continue;
                }
            }
            // pass through normal backslashes
            result.push_back('\\');
            cursor++;
        }
    }

    return result;
}

