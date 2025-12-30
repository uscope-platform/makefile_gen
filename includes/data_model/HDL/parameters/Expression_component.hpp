//  Copyright 2023 Filippo Savi
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

#ifndef MAKEFILEGEN_V2_EXPRESSION_COMPONENT_HPP
#define MAKEFILEGEN_V2_EXPRESSION_COMPONENT_HPP

#include <string>
#include <utility>
#include <regex>
#include <set>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <variant>
#include <cmath>

#include <cereal/types/vector.hpp>

struct Expression;

class Expression_component {
public:

    Expression_component();
    Expression_component( const Expression_component &c );
    explicit Expression_component(const std::string &s);
    explicit Expression_component(int64_t n);
    bool is_string() const;
    bool is_numeric() const {return std::holds_alternative<int64_t>(value);}
    bool is_function() const {
        if (is_numeric()) return false;
        return functions_set.contains(std::get<std::string>(value));
    }
    bool is_operator() const {
        if (is_numeric()) return false;
        return operators_set.contains(std::get<std::string>(value));
    }

    std::variant<int64_t, std::string> get_value()const {return value;}
    void set_value(const std::variant<int64_t, std::string> &v){value = v;}

    void set_package_prefix(const std::string &s) {package_prefix = s;};
    std::string get_package_prefix() const {return package_prefix;};

    bool is_right_associative();
    int64_t get_operator_precedence();
    std::string print_value();

    static int64_t calculate_binary_size(int64_t in);
    typedef enum{
        unary_operator = 0,
        binary_operator = 1
    } operator_type_t;

    operator_type_t get_operator_type();

    friend bool operator==(const Expression_component&lhs, const Expression_component&rhs);

    void set_array_index(const std::vector<Expression> &v) {array_index = v;}
    void add_array_index(const Expression &c);
    std::vector<Expression> get_array_index() {return array_index;};

    const std::string print_index(const std::vector<Expression> &index);

    int64_t get_binary_size() const{return binary_size;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(value, array_index, package_prefix, binary_size);
    }

    nlohmann::json dump();


private:
    void process_number();
    bool test_parameter_type(const std::regex &r, const std::string &s);

    std::variant<int64_t, std::string> value;

    std::string package_prefix;

    int64_t binary_size = 0;

    static const std::regex sv_constant_regex;
    static const std::regex number_regex;
    static const std::regex size_regex;

    std::vector<Expression> array_index;


    std::set<std::string> operators_set = {
            "!", "~", "*", "/", "%","+","-","<<",">>", ">", ">=", "<", "<=", "==", "!="
    };

    std::set<std::string> parenthesis_set = {
        "(", ")", "[", "]", "{", "}"
};

    std::set<std::string> functions_set = {
            "$clog2","$ceil", "$floor","$pow"
    };


    std::unordered_map<std::string, operator_type_t> operators_types = {
            {"$clog2", unary_operator},
            {"$ceil", unary_operator},
            {"$floor", unary_operator},
            {"$pow", binary_operator},
            {"!", unary_operator},
            {"~", unary_operator},
            {"*", binary_operator},
            {"/", binary_operator},
            {"%", binary_operator},
            {"+", binary_operator},
            {"-", binary_operator},
            {"<<", binary_operator},
            {">>", binary_operator},
            {">", binary_operator},
            {">=", binary_operator},
            {"<", binary_operator},
            {"<=", binary_operator},
            {"==",  binary_operator},
            {"!=", binary_operator}
    };


    std::unordered_map<std::string, int64_t> operators_precedence = {
            {"$clog2", 0},
            {"$ceil",  0},
            {"$floor", 0},
            {"$pow",   0},
            {"!",      1},
            {"~",      1},
            {"*",      2},
            {"/",      2},
            {"%",      2},
            {"+",      3},
            {"-",      3},
            {"<<",     4},
            {">>",     4},
            {">",      5},
            {">=",     5},
            {"<",      5},
            {"<=",     5},
            {"==",     5},
            {"!=",     5}
    };

    std::set<std::string> right_associative_set = {
            "$clog2","$ceil", "$floor","$pow", "!", "~"
    };
};

#endif //MAKEFILEGEN_V2_EXPRESSION_COMPONENT_HPP
