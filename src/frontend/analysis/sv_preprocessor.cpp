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


#include "frontend/analysis/sv_preprocessor.hpp"

#include <fmt/format.h>

sv_preprocessor::sv_preprocessor(const std::filesystem::path &in) {
    path = in;
}

std::string sv_preprocessor::preprocess(const std::filesystem::path &in) {
    path = in;
    std::ifstream ifs(in);
    return preprocess(ifs);
}

std::string sv_preprocessor::preprocess(std::istream &in) {
    static constexpr auto identifier_pattern = ctre::search<R"(`([a-zA-Z_][a-zA-Z0-9_]*))">;
    simple_defines = {};

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

        if (trimmed_line.starts_with("`define")) {
            auto [identifier, value] = parse_two_arg_directive(trimmed_line, 7);
            simple_defines[std::string(identifier)] =  value;
        } else if (trimmed_line.starts_with("`else")) {

        } else if (trimmed_line.starts_with("`elsif")) {

        } else if (trimmed_line.starts_with("`endif")) {

        } else if (trimmed_line.starts_with("`ifdef")) {

        } else if (trimmed_line.starts_with("`ifndef")) {

        } else if (trimmed_line.starts_with("`include")) {

        } else if (trimmed_line.starts_with("`undef")) {
            auto identifier = parse_one_arg_directive(trimmed_line, 6);
            simple_defines.erase(std::string(identifier));
        } else if (trimmed_line.starts_with("`undefineall")) {
            simple_defines.clear();
        } else if (!skipped_directive) {

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
        if (!simple_defines.contains(id)) {
            throw std::runtime_error(fmt::format("{}:{} MACRO {} is not defined", path, line_number, id));
        }
        replacement = simple_defines.at(id);
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

std::pair<std::string_view, std::string_view> sv_preprocessor::parse_two_arg_directive(const std::string_view &sv, int prefix_length) {
    auto trimmed_view = sv.substr(prefix_length);
    trimmed_view = trimmed_view.substr(trimmed_view.find_first_not_of("\t "));
    auto id_last = trimmed_view.find_first_of("\t ");
    auto identifier = trimmed_view.substr(0, id_last);
    auto remaining_view = trimmed_view.substr(id_last+1);
    auto value = remaining_view.substr(remaining_view.find_first_not_of("\t "));
    return {identifier, value};
}

std::string_view sv_preprocessor::parse_one_arg_directive(const std::string_view &sv, int prefix_length) {
    auto trimmed_line = sv.substr(prefix_length);
    return trimmed_line.substr( trimmed_line.find_first_not_of(' '));
}
