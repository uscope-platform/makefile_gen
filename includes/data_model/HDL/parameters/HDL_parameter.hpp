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
#include <unordered_set>

#include <cereal/types/vector.hpp>
#include <cereal/types/unordered_set.hpp>

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
    void set_value(uint32_t val);
    std::string get_string_value() const;
    uint32_t  get_numeric_value() const;

    operator std::string();

    bool is_numeric_string(const std::string &s) const;
    bool is_numeric_string() const {return is_numeric_string(string_value_array[0]);};
    bool is_sv_constant(const std::string &s) const;
    bool is_sv_constant() const {return is_sv_constant(string_value_array[0]);};
    bool is_array() const;
    bool is_repetition_array_init() const;

    void string_to_array(
                    const std::unordered_map<std::string, HDL_parameter>& parent_parameter,
                    const std::unordered_map<std::string, HDL_parameter>& instance_parameters,
                    const std::unordered_map<std::string, HDL_parameter>& module_parameters
                         );
    void string_to_numeric();

    uint32_t parse_sv_constant(const std::string &s) const;
    uint32_t parse_sv_constant() const {return parse_sv_constant(string_value_array[0]);};

    std::string get_name() const {return name;};

    void add_component(const std::string& component);

    parameter_type get_type(){return type;};
    void set_type(parameter_type t){type = t;};

    bool is_empty();


    void set_expression_components(std::vector<std::string> &c){expression_components = c;};
    std::vector<std::string>  get_expression_components() { return expression_components;};

    void add_dependency(std::string &s){dependencies.insert(s);};
    std::unordered_set<std::string> get_dependencies() { return dependencies;};
    void set_dependencies(std::unordered_set<std::string> d) {dependencies = std::move(d);};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, string_value_array, numeric_value_array);
    }

    std::string to_string() const;

    friend bool operator <(const HDL_parameter& lhs, const HDL_parameter& rhs);
    friend bool operator==(const HDL_parameter&lhs, const HDL_parameter&rhs);

    friend void PrintTo(const HDL_parameter& point, std::ostream* os);

private:

    uint32_t get_parameter_value(
            const std::string &p,
            const std::unordered_map<std::string, HDL_parameter>& parent_parameter,
            const std::unordered_map<std::string, HDL_parameter>& instance_parameters,
            const std::unordered_map<std::string, HDL_parameter>& module_parameters
            );

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
    std::vector<uint32_t> numeric_value_array;
    parameter_type type;


    std::unordered_set<std::string> dependencies;
    std::vector<std::string> expression_components;

};


#endif //MAKEFILEGEN_V2_HDL_PARAMETER_HPP
