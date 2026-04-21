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

#ifndef MAKEFILEGEN_V2_SV_PREPROCESSOR_HPP
#define MAKEFILEGEN_V2_SV_PREPROCESSOR_HPP

#include <ctre.hpp>
#include <filesystem>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <variant>
#include <fmt/format.h>
#include "frontend/analysis/preprocessor/conditional_solver.hpp"

struct function_macro_argument {
    std::string name;
    std::string default_value;
    bool has_default;

    friend bool operator==(const function_macro_argument &lhs, const function_macro_argument &rhs) {
        return lhs.name == rhs.name
               && lhs.default_value == rhs.default_value
               && lhs.has_default == rhs.has_default;
    }

    friend bool operator!=(const function_macro_argument &lhs, const function_macro_argument &rhs) {
        return !(lhs == rhs);
    }
};

struct function_macro {

    std::vector<function_macro_argument> arguments;
    std::string value;

     friend bool operator==(const function_macro &lhs, const function_macro &rhs) {
            return lhs.arguments == rhs.arguments && lhs.value == rhs.value;
     }

     friend bool operator!=(const function_macro &lhs, const function_macro &rhs) {
        return !(lhs == rhs);
    }
};



class sv_preprocessor {
public:
    sv_preprocessor(const std::filesystem::path &in);
    std::string preprocess(const std::filesystem::path &in);
    std::string preprocess(std::istream& in);
    std::string flatten_source(const std::string_view &in);
private:
    std::string get_define_replacement(const std::string_view &v);
    std::string_view ltrim(const std::string_view &in);
    void parse_definition(const std::string_view &sv, int prefix_length);
    std::string_view parse_one_arg_directive(const std::string_view &sv, int prefix_length);
    std::optional<function_macro> parse_function_macro(const std::string_view &in);
    uint64_t line_number;
    std::unordered_map<std::string, std::variant<std::string, function_macro>> definitions;
    std::string path;
    conditional_solver c_solver;
};



#endif //MAKEFILEGEN_V2_SV_PREPROCESSOR_HPP
