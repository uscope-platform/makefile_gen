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

enum expression_component_type {
    string_component=0,
    numeric_component=1
};

enum component_index_type {
    no_index_type = 0,
    string_index_type=1,
    numeric_index_type=2
};

class Expression_component {
public:
    Expression_component();
    explicit Expression_component(std::string s);
    explicit Expression_component(uint32_t n);

    std::string get_raw_string_value();
    std::string get_string_value(){ return string_value;};
    uint32_t  get_numeric_value() {return numeric_value;};

    std::string print_value();

    expression_component_type get_type()const {return component_type;};
    component_index_type get_index_type(){return index_type;};


    friend bool operator==(const Expression_component&lhs, const Expression_component&rhs);

private:
    void process_number(const std::string &val);
    bool test_parameter_type(const std::regex &r, const std::string &s);

    component_index_type index_type;
    expression_component_type component_type;

    std::string string_value;
    uint32_t numeric_value;

    std::string string_index;
    uint32_t numeric_index;
};

#endif //MAKEFILEGEN_V2_EXPRESSION_COMPONENT_HPP
