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
    array_parameter = 2,
    expression_parameter = 4
};


constexpr std::string parameter_type_to_string(parameter_type in){
    switch(in){
        case string_parameter: return "string_parameter";
        case numeric_parameter: return "numeric_parameter";
        case array_parameter: return "array_parameter";
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

    explicit operator std::string();

    bool is_array() const {return !i_l.empty();};
    bool is_packed_array() {return i_l.is_packed();};

    std::string get_name() const {return name;};

    parameter_type get_type() const {return type;};
    void set_type(parameter_type t){type = t;};

    bool is_empty();

    void add_component(const Expression_component &component);
    void set_expression_components(const Expression  &c){expression_components = c;};
    Expression  get_expression_components() { return expression_components;};
    void clear_expression_components(){expression_components.clear();};

    void set_array_value(const mdarray &arr){
        type = array_parameter;
        array_value = arr;
    };
    mdarray get_array_value(){return array_value;};

    std::string to_string() const;

    friend bool operator <(const HDL_parameter& lhs, const HDL_parameter& rhs);
    friend bool operator==(const HDL_parameter&lhs, const HDL_parameter&rhs);

    friend void PrintTo(const HDL_parameter& point, std::ostream* os);


    void add_initialization_list(const Initialization_list &i){ i_l = i;};
    Initialization_list get_i_l() {return i_l;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, string_value_array, numeric_value_array, type,
           expression_components, i_l);
    }

    nlohmann::json dump();

private:

    std::string name;
    std::vector<std::string> string_value_array;
    std::vector<int64_t> numeric_value_array;
    mdarray array_value;
    parameter_type type;

    Expression expression_components;

    Initialization_list i_l;
};


#endif //MAKEFILEGEN_V2_HDL_PARAMETER_HPP
