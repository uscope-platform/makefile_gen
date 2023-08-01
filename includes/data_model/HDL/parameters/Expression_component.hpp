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
#include <unordered_map>

enum expression_component_type {
    string_component=0,
    numeric_component=1,
    operator_component=2,
    function_component=3,
    array_component = 4
};

class Expression_component {
public:
    Expression_component();
    explicit Expression_component(std::string s);
    explicit Expression_component(uint32_t n);

    std::string get_raw_string_value();
    std::string get_string_value(){ return string_value;};
    uint32_t  get_numeric_value() {return numeric_value;};

    bool is_right_associative();
    uint32_t get_operator_precedence();
    std::string print_value();
    expression_component_type get_type()const {return component_type;};

    typedef enum{
        unary_operator = 0,
        binary_operator = 1
    } operator_type_t;

    operator_type_t get_operator_type();

    friend bool operator==(const Expression_component&lhs, const Expression_component&rhs);

    void set_array_value(std::vector<Expression_component> &v) {array_value = v;};
    std::vector<Expression_component> get_array_value() {return array_value;};

    void set_array_index(std::vector<std::vector<Expression_component>> &v) {array_index = v;};
    void add_array_index(std::vector<Expression_component> &c) {array_index.push_back(c);};
    std::vector<std::vector<Expression_component>> get_array_index() {return array_index;};

    static const std::string print_expression(const std::vector<Expression_component> &exp);
    const std::string print_index(const std::vector<std::vector<Expression_component>> &index);

private:
    void process_number();
    bool test_parameter_type(const std::regex &r, const std::string &s);

    expression_component_type component_type;

    std::string string_value;
    uint32_t numeric_value;

    std::vector<Expression_component> array_value;
    std::vector<std::vector<Expression_component>> array_index;


    std::set<std::string> operators_set = {
            "!", "~", "*", "/", "%","+","-","<<",">>"
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
    };


    std::unordered_map<std::string, uint32_t> operators_precedence = {
            {"$clog2", 0},
            {"$ceil", 0},
            {"$floor", 0},
            {"$pow", 0},
            {"!", 1},
            {"~", 1},
            {"*", 2},
            {"/", 2},
            {"%", 2},
            {"+", 3},
            {"-", 3},
            {"<<", 4},
            {">>", 4},
    };

    std::set<std::string> right_associative_set = {
            "$clog2","$ceil", "$floor","$pow", "!", "~"
    };
};

#endif //MAKEFILEGEN_V2_EXPRESSION_COMPONENT_HPP
