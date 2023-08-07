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
#include "data_model/data_store.hpp"

class Parameter_processor_Exception : public std::exception {
public:
    char * what () {
        return  (char*) "Internal exception, it should always be handled";
    }
};

class Parameter_processor {
public:
    Parameter_processor(const std::map<std::string, HDL_parameter>& parent_parameters, const std::shared_ptr<data_store> &ds);
    static void convert_parameters(std::vector<HDL_Resource> &v);
    HDL_Resource process_resource(const HDL_Resource &res);
    HDL_parameter process_parameter(const HDL_parameter &par);
    int64_t process_expression(const std::vector<Expression_component>& expr);

    std::unordered_map<std::string, HDL_parameter> process_initialization_list(
        const std::string& param_name,
        std::vector<std::vector<Expression_component>> &il,
        std::vector<dimension_t> &dims
    );

    std::vector<int64_t> process_array_dimensions(std::vector<dimension_t> dims);

    int64_t get_flattened_array_index(std::string param_name, std::vector<Expression> idx);

    static std::vector<Expression_component> expr_vector_to_rpn(const std::vector<Expression_component>& v);

    static int64_t evaluate_binary_expression(int64_t op_a, int64_t op_b, const std::string& operation);
    static int64_t evaluate_unary_expression(int64_t operand, const std::string& operation);

    int64_t get_component_value(Expression_component &ec);
private:

    std::unordered_map<std::string, int64_t> working_param_values;
    std::unordered_map<std::string, std::vector<dimension_t>> array_dimensions;
    std::unordered_map<std::string, int64_t> external_parameters;

    std::unordered_map<std::string, std::vector<int64_t>> array_parameter_values;

    std::shared_ptr<data_store> d_store;
};


#endif //MAKEFILEGEN_V2_PARAMETER_PROCESSOR_HPP
