//  Copyright 2024 Filippo Savi
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


#ifndef MAKEFILEGEN_V2_HDL_LOOP_SOLVER_HPP
#define MAKEFILEGEN_V2_HDL_LOOP_SOLVER_HPP


#include <memory>
#include "data_model/HDL/parameters/Parameters_map.hpp"
#include "data_model/HDL/HDL_instance.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"

class HDL_loop_solver {
public:
    HDL_loop_solver(const Parameters_map &pm, const std::shared_ptr<data_store> &ds);
    std::vector<int64_t> solve_loop(generate_loop &loop_specs, HDL_Resource &spec);
private:
    int64_t  process_expression(Expression &e, std::shared_ptr<HDL_parameter> loop_var);
    bool is_loop_done(std::shared_ptr<HDL_parameter> &lv, Expression end_cond);
    Parameters_map parent_parameters;
    std::shared_ptr<data_store> d_store;
};


#endif //MAKEFILEGEN_V2_HDL_LOOP_SOLVER_HPP
