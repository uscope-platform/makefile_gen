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

#ifndef MAKEFILEGEN_V2_PARAMETER_PROCESSOR_HPP
#define MAKEFILEGEN_V2_PARAMETER_PROCESSOR_HPP

#include <cmath>

#include "data_model/HDL/HDL_Resource.hpp"


class Parameter_processor {
public:
    Parameter_processor() = default;
    void convert_parameters(std::vector<HDL_Resource> &v);
    HDL_Resource process_resource(const HDL_Resource &res);
    std::pair<HDL_parameter, bool> process_parameter(const HDL_parameter &par);
    std::pair<uint32_t, bool>  process_expression(const std::vector<std::string>& expr, std::unordered_set<std::string> &deps);
    uint32_t process_number(const std::string &val);

    std::vector<std::string> expr_vector_to_rpn(const std::vector<std::string>& v);

    static uint32_t evaluate_binary_expression(uint32_t op_a, uint32_t op_b, std::string operation);
    static uint32_t evaluate_unary_expression(uint32_t operand, std::string operation);
private:
    bool test_parameter_type(const std::string &r, const std::string &s);

    std::unordered_map<std::string, uint32_t> working_param_values;

    typedef struct {
        std::string type;
        std::string operation;
        uint32_t number;
    }expr_component_t;

    typedef enum{
        unary_operator = 0,
        binary_operator = 1,
        immediate_operator = 2
    } operator_type_t;


    struct {
        std::string numeric;
        std::string sv_constant;
        std::string array_init;
        std::string array;
    } classification_regexes = {
            "^\\d*$",
            "^\\d*'(h|d|o|b)([0-9a-fA-F]+)",
            R"(\{([a-zA-Z0-9_']+)\{([a-zA-Z0-9_']+)\}\})",
            R"(\{([^\}]+)\})"
    };

    std::set<std::string> operators_set = {
            "!", "~", "*", "/", "%","+","-","<<",">>"
    };

    std::set<std::string> functions_set = {
            "$clog2","$ceil", "$floor","$pow"
    };

    std::set<std::string> right_associative_set = {
            "$clog2","$ceil", "$floor","$pow", "!", "~"
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



};


#endif //MAKEFILEGEN_V2_PARAMETER_PROCESSOR_HPP
