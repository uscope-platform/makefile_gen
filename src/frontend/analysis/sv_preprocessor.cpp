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

sv_preprocessor::sv_preprocessor(const std::filesystem::path &in) {
    path = in;
}

std::string sv_preprocessor::preprocess(const std::filesystem::path &in) {
    path = in;
    std::ifstream ifs(in);
    return preprocess(ifs);
}

std::string sv_preprocessor::preprocess(std::istream &in) {

    std::ostringstream out;

    std::string line;
    while (std::getline(in, line)) {
        std::string_view trimmed_line = line;
        // If it starts with whitespace, find where the whitespace ends
        if (auto prefix = ctre::starts_with<R"(\s+ )">(trimmed_line)) {
            // Just chop off the length of the match. No loops, no result arrays.
            trimmed_line.remove_prefix(prefix.size());
        }

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

        if (trimmed_line.starts_with("`__LINE__")) {

        } else if (trimmed_line.starts_with("`define")) {

        } else if (trimmed_line.starts_with("`else")) {

        } else if (trimmed_line.starts_with("`elsif")) {

        } else if (trimmed_line.starts_with("`endif")) {

        } else if (trimmed_line.starts_with("`ifdef")) {

        } else if (trimmed_line.starts_with("`ifndef")) {

        } else if (trimmed_line.starts_with("`include")) {

        } else if (trimmed_line.starts_with("`undef")) {

        } else if (trimmed_line.starts_with("`undefineall")) {

        } else if (!skipped_directive) {
            auto result = line;
            if (auto [whole, name] = ctre::search<R"(`([a-zA-Z_][a-zA-Z0-9_]*))">(line); whole) {
                if (name) {
                    std::string_view identifier = name;
                    if (identifier == "__FILE__") {
                        result = "";
                        std::string_view prefix{line.begin(), whole.begin()};
                        std::string_view suffix{whole.end(), line.end()};

                        result.reserve(prefix.size() + path.size() + suffix.size());
                        result.append(prefix).append("\"").append(path).append("\"").append(suffix);
                    } else {
                        int i = 0;
                    }
                }

            }
            out << result << std::endl;
        }
    }
    auto retval = out.str();
    retval.pop_back();
    return retval;
}