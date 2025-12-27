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
#include <spdlog/spdlog.h>

#include "data_model/HDL/parameters/Expression_component.hpp"
#include "data_model/HDL/parameters/Initialization_list.hpp"

#include <cereal/types/vector.hpp>
#include "cereal/types/utility.hpp"


class HDL_parameter {
public:

    HDL_parameter( const HDL_parameter &c );
    HDL_parameter();
    void set_name(const std::string &n) {
        locking_violation_check();
        name  = n;
    };
    std::shared_ptr<HDL_parameter> clone() const;
    void set_scope(const std::string &s){ scope = s;}
    std::string get_scope() {return  scope;}
    void set_value(const std::string &v);
    void set_value(int64_t val);
    std::string get_string_value() const;
    int64_t  get_numeric_value() const;

    explicit operator std::string();

    bool is_array() const {return !i_l.empty();};
    bool is_packed_array() {return i_l.is_packed();};

    std::string get_name() const {return name;};

    enum parameter_type {
        string_parameter=0,
        numeric_parameter=1,
        array_parameter = 2,
        expression_parameter = 4,
        function_parameter = 5
    };

    parameter_type get_type() const {return type;}
    void set_type(parameter_type t) {
        type = t;
    }

    bool is_empty();

    void add_component(const Expression_component &component);
    void set_expression_components(const Expression  &c) {
        locking_violation_check();
        expression_components = c;
    };
    Expression  get_expression_components() { return expression_components;}
    void clear_expression_components() {
        locking_violation_check();
        expression_components.clear();
    }

    void set_array_value(const mdarray &arr){
        locking_violation_check();
        type = array_parameter;
        array_value = arr;
    };
    mdarray get_array_value(){return array_value;};

    std::string value_as_string() const;
    std::string to_string() const;

    friend bool operator <(const HDL_parameter& lhs, const HDL_parameter& rhs);
    friend bool operator==(const HDL_parameter&lhs, const HDL_parameter&rhs);

    friend void PrintTo(const HDL_parameter& point, std::ostream* os);


    void add_initialization_list(const Initialization_list &i){
        locking_violation_check();
        i_l = i;
    }
    Initialization_list get_i_l() {return i_l;}

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, string_value_array, numeric_value,array_value,type,
           expression_components, i_l);
    }

    void set_loop_index() {
        locking_violation_check();
        loop_index = true;
    }
    bool is_loop_index() const {return loop_index;}
    nlohmann::json dump();

    void lock_parameter(){lock = true;}

    void locking_violation_check() {
        if(lock) {
            spdlog::error("Attempting to modify a locked parameter {}",name);
            exit(1);
        }
    }
private:

    bool lock = false;

    std::string name;
    std::string scope;
    std::vector<std::string> string_value_array;
    int64_t numeric_value;
    mdarray array_value;
    parameter_type type;
    bool loop_index = false;

    Expression expression_components;

    Initialization_list i_l;
};

constexpr std::string parameter_type_to_string(HDL_parameter::parameter_type in){
    switch(in){
        case HDL_parameter::string_parameter: return "string_parameter";
        case HDL_parameter::numeric_parameter: return "numeric_parameter";
        case HDL_parameter::array_parameter: return "array_parameter";
        case HDL_parameter::expression_parameter: return "expression_parameter";
        case HDL_parameter::function_parameter: return "function_parameter";
        default: return "unknown parameter type";
    }
}

#endif //MAKEFILEGEN_V2_HDL_PARAMETER_HPP
