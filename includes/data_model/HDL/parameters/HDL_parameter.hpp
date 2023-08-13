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

#ifndef MAKEFILEGEN_V2_HDL_PARAMETER_HPP
#define MAKEFILEGEN_V2_HDL_PARAMETER_HPP

#include <string>
#include <regex>
#include <nlohmann/json.hpp>

#include "data_model/HDL/parameters/Expression_component.hpp"
#include "data_model/HDL/parameters/Initialization_list.hpp"

#include <cereal/types/vector.hpp>
#include "cereal/types/utility.hpp"

enum parameter_type {
    string_parameter=0,
    numeric_parameter=1,
    string_array_parameter=2,
    numeric_array_parameter=3,
    expression_parameter = 4
};


constexpr std::string parameter_type_to_string(parameter_type in){
    switch(in){
        case string_parameter: return "string_parameter";
        case numeric_parameter: return "numeric_parameter";
        case string_array_parameter: return "string_array_parameter";
        case numeric_array_parameter: return "numeric_array_parameter";
        case expression_parameter: return "expression_parameter";
        default: return "unknown parameter type";
    }
}


class HDL_parameter {
public:

    HDL_parameter( const HDL_parameter &c );
    HDL_parameter();
    void set_name(const std::string &n) {name  = n;};

    void set_value(const std::string &v);
    void set_value(int64_t val);
    std::string get_string_value() const;
    int64_t  get_numeric_value() const;

    operator std::string();

    bool is_numeric_string(const std::string &s) const;
    bool is_numeric_string() const {return is_numeric_string(string_value_array[0]);};
    bool is_sv_constant(const std::string &s) const;
    bool is_sv_constant() const {return is_sv_constant(string_value_array[0]);};
    bool is_array() const {return !i_l.empty();};


    int64_t parse_sv_constant(const std::string &s) const;
    int64_t parse_sv_constant() const {return parse_sv_constant(string_value_array[0]);};

    std::string get_name() const {return name;};

    parameter_type get_type() const {return type;};
    void set_type(parameter_type t){type = t;};

    bool is_empty();

    void add_component(const Expression_component &component);
    void set_expression_components(const Expression  &c){expression_components = c;};
    Expression  get_expression_components() { return expression_components;};

    std::string to_string() const;

    friend bool operator <(const HDL_parameter& lhs, const HDL_parameter& rhs);
    friend bool operator==(const HDL_parameter&lhs, const HDL_parameter&rhs);

    friend void PrintTo(const HDL_parameter& point, std::ostream* os);


    void add_initialization_list(const Initialization_list &i){ i_l = i;};
    void set_initialization_list(std::vector<std::vector<Expression>> &list) {initialization_list = list;};
    void append_initialization_list(std::vector<std::vector<Expression>> &list);
    std::vector<std::vector<Expression>> get_initialization_list(){ return initialization_list;};
    Initialization_list get_i_l() {return i_l;};

    void set_array_index(const std::vector<int64_t> &i) {array_index = i;};
    std::vector<int64_t> get_array_index(){return array_index;};
    bool is_array_element() {return !array_index.empty();};

    void add_dimension(const dimension_t &e) {array_dimensions.push_back(e);};
    std::vector<dimension_t> get_dimensions(){return array_dimensions;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, string_value_array, numeric_value_array, type,
           expression_components, initialization_list,array_dimensions,
           array_index);
    }

    nlohmann::json dump();

private:

    bool regex_string_test(const std::string &r, const std::string &s) const;
    std::pair<std::string, std::string> split_array_init(std::string s);

    struct {
        std::string numeric = R"(^\d*$)";
        std::string sv_constant = R"(^\d*'(h|d|o|b)([0-9a-fA-F]+))";
        std::string array_init = R"(\{([a-zA-Z0-9_']+)\{([a-zA-Z0-9_']+)\}\})";
        std::string array = R"(\{([^\}]+)\})";
    } classification_regexes;


    std::string name;
    std::vector<std::string> string_value_array;
    std::vector<int64_t> numeric_value_array;
    parameter_type type;

    std::vector<int64_t> array_index;

    Expression expression_components;
    std::vector<std::vector<Expression>> initialization_list;
    std::vector<dimension_t> array_dimensions;

    Initialization_list i_l;
};


#endif //MAKEFILEGEN_V2_HDL_PARAMETER_HPP
