//  Copyright 2025 Filippo Savi
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

#include "data_model/HDL/factories/HDL_loops_factory.h"

void HDL_loops_factory::new_loop() {
    repeated_instances.clear();
    end_cond_valid = false;
    active = true;
}

void HDL_loops_factory::clear() {
    repeated_instances.clear();
    loop_specs = HDL_loop_metadata();
    current_expression.clear();
    loop_phase = init;
    end_cond_valid = false;
    active = false;
}


std::vector<HDL_instance> HDL_loops_factory::get_instances() {
    active = false;
    return repeated_instances;
}

void HDL_loops_factory::add_component(const Expression_component &c) {
    current_expression.push_back(c);
}

void HDL_loops_factory::add_loop_variable(const std::string &p) {
    loop_specs.init = HDL_parameter();
    loop_specs.init.set_name(p);
}

void HDL_loops_factory::set_phase(loop_phase_t p) {
    loop_phase = p;
    if(p==init) {
        current_expression.clear();
    } else if(p==end) {
        loop_specs.init.set_expression_components(current_expression);
        loop_specs.init.set_type(expression_parameter);
        current_expression.clear();
    } else if(p==step) {
        loop_specs.end_c = current_expression;
        current_expression.clear();
    } else if(p==body) {
        loop_specs.iter = current_expression;
        current_expression.clear();
    }
}

void HDL_loops_factory::add_expression(const Expression &e) {
    if(loop_phase == step) {
        current_expression = e;
    }
    if(end_cond_valid){
        loop_specs.iter = e;
    } else {
        loop_specs.end_c = e;
        end_cond_valid = true;
    }
}

void HDL_loops_factory::add_instance(HDL_instance &i) {
    i.add_loop(loop_specs);
    repeated_instances.push_back(i);
}

