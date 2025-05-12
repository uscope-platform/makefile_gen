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


#include "analysis/HDL_loop_solver.hpp"

HDL_loop_solver::HDL_loop_solver(const Parameters_map &pm, const std::shared_ptr<data_store> &ds){
    parent_parameters = pm;
    d_store = ds;
}

std::vector<int64_t> HDL_loop_solver::solve_loop(HDL_loop_metadata &l, HDL_Resource &spec) {
    std::vector<int64_t> ret;
    Parameter_processor init_processor(parent_parameters,d_store);
    auto loop_variable = init_processor.process_parameter(std::make_shared<HDL_parameter>(l.init), spec);

    while(!is_loop_done(loop_variable, l.end_c)){
        ret.push_back(loop_variable->get_numeric_value());

        auto new_loop_var = process_expression(l.iter, loop_variable);

        loop_variable->set_value(new_loop_var);
    }

    return ret;
}

bool HDL_loop_solver::is_loop_done(std::shared_ptr<HDL_parameter> &lv, Expression end_cond) {

    auto ec = process_expression(end_cond, lv);
    return ec == 0;
}

int64_t HDL_loop_solver::process_expression(Expression &e, std::shared_ptr<HDL_parameter> loop_var) {
    Parameters_map end_condition_map = parent_parameters;
    end_condition_map.insert(loop_var);
    Parameter_processor processor(end_condition_map,d_store);

    return processor.process_expression(e, nullptr);
}
