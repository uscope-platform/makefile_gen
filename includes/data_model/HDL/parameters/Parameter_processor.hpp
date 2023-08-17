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
#include <utility>

#include "data_model/HDL/HDL_Resource.hpp"
#include "data_model/data_store.hpp"



class string_parameter_exception : public std::exception {
public:
    explicit string_parameter_exception(std::string v) {
        str_val = v;
    };
    char * what () {
        return  (char*) "Internal exception, it should always be handled";
    }
    std::string str_val;
};

class Parameter_processor_Exception : public std::exception {
public:
    Parameter_processor_Exception() = default;
    explicit Parameter_processor_Exception(std::string v) {
        str_val = v;
    };
    char * what () {
        return  (char*) "Internal exception, it should always be handled";
    }
    std::string str_val;
};

class array_value_exception  : public std::exception {
public:
    explicit array_value_exception(mdarray v) {
        array_value = v;
    };
    char * what () {
        return  (char*) "Internal exception, it should always be handled";
    }
    mdarray array_value;
};


class Parameter_processor {
public:
    Parameter_processor(const std::map<std::string, HDL_parameter>& parent_parameters, const std::shared_ptr<data_store> &ds);
    Parameter_processor(const std::map<std::string, HDL_parameter>& ep,
                        std::shared_ptr<std::unordered_map<std::string, HDL_parameter>> &cs
    );
    std::map<std::string, HDL_parameter> process_parameters_map(std::map<std::string, HDL_parameter> &map, HDL_Resource &spec);
    static void convert_parameters(std::vector<HDL_Resource> &v);
    HDL_Resource process_resource(const HDL_Resource &res);
    int64_t process_expression(const std::vector<Expression_component>& expr, int64_t *reslt_size);

    static std::vector<Expression_component> expr_vector_to_rpn(const std::vector<Expression_component>& v);

    static int64_t evaluate_binary_expression(int64_t op_a, int64_t op_b, const std::string& operation);
    static int64_t evaluate_unary_expression(int64_t operand, const std::string& operation);
    void set_data_store(std::shared_ptr<data_store> &ds){d_store = ds;};

private:

    HDL_parameter process_scalar_parameter(const HDL_parameter &par);
    HDL_parameter process_array_parameter(const HDL_parameter &par);
    HDL_parameter process_packed_parameter(const HDL_parameter &par);
    Expression_component process_array_access(Expression_component &e);
    int64_t get_component_value(Expression_component &ec, int64_t *result_size);

    std::shared_ptr<std::unordered_map<std::string, HDL_parameter>> compleated_set;

    std::shared_ptr<std::map<std::string, HDL_parameter>> external_parameters;

    std::unordered_map<std::string, std::vector<int64_t>> array_parameter_values;

    std::shared_ptr<data_store> d_store;
};


#endif //MAKEFILEGEN_V2_PARAMETER_PROCESSOR_HPP
