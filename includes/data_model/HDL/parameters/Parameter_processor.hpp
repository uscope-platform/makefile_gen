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
#include "data_model/HDL/parameters/Parameters_map.hpp"
#include "data_model/HDL/parameters/Expression_evaluator.hpp"


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
        unknown_parameter = false;
    };
    char * what () {
        return  (char*) "Internal exception, it should always be handled";
    }
    std::string str_val;
    bool unknown_parameter = true;
};

class array_value_exception  : public std::exception {
public:
    explicit array_value_exception(mdarray<int64_t> v) {
        array_value = v;
    };
    char * what () {
        return  (char*) "Internal exception, it should always be handled";
    }
    mdarray<int64_t> array_value;
};


class Parameter_processor {
public:
    Parameter_processor(const Parameters_map& parent_parameters, const std::shared_ptr<data_store> &ds);
    Parameter_processor(const Parameters_map& ep,
                        std::shared_ptr<Parameters_map> &cs
    );
    void set_trace_prefix(std::string &s) {trace_prefix = s;}
    Parameters_map process_parameters_map(const Parameters_map &map, HDL_Resource &spec);
    int64_t process_expression(const Expression& expr, int64_t *reslt_size);

    void set_data_store(std::shared_ptr<data_store> &ds){d_store = ds;};

    std::shared_ptr<HDL_parameter> process_parameter(const std::shared_ptr<HDL_parameter> &par, HDL_Resource &spec);
private:
    std::shared_ptr<HDL_parameter> process_scalar_function_parameter(const std::shared_ptr<HDL_parameter> &par,
        const HDL_function_def &fcn);
    std::shared_ptr<HDL_parameter> process_vector_function_parameter(const std::shared_ptr<HDL_parameter> &par,
        const HDL_function_def &fcn, HDL_Resource &spec);
    std::shared_ptr<HDL_parameter> process_unsupported_parameter(const std::shared_ptr<HDL_parameter> &par,
        const Expression &fcn);
    std::shared_ptr<HDL_parameter> process_scalar_parameter(const std::shared_ptr<HDL_parameter> &par);
    std::shared_ptr<HDL_parameter> process_array_parameter(const std::shared_ptr<HDL_parameter> &par);
    std::shared_ptr<HDL_parameter> process_packed_parameter(const std::shared_ptr<HDL_parameter> &par);
    Expression_component process_array_access(Expression_component &e);
    int64_t get_component_value(Expression_component &ec, int64_t *result_size);
    std::unordered_map<uint64_t, uint64_t> evaluate_loop(HDL_loop_metadata &loop, HDL_Resource &spec);
    int64_t evaluate_loop_expression(const Expression &e, std::shared_ptr<HDL_parameter> loop_var);
    mdarray<int64_t> merge_function_contributions(
        std::unordered_map<uint64_t, uint64_t> &explicit_values,
        std::unordered_map<uint64_t, uint64_t> &loop_values
    );

    int64_t get_package_parameter(const Expression_component &ex, int64_t *result_size);

    std::shared_ptr<Parameters_map> completed_set;
    std::map<std::string, std::shared_ptr<HDL_parameter>> string_set;

    std::shared_ptr<Parameters_map> external_parameters;

    std::unordered_map<std::string, std::vector<int64_t>> array_parameter_values;
    std::shared_ptr<data_store> d_store;
    std::string trace_prefix = "";
};


#endif //MAKEFILEGEN_V2_PARAMETER_PROCESSOR_HPP
