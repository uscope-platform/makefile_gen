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

#include "data_model/HDL/HDL_loops_factory.h"

void HDL_loops_factory::new_loop() {
    repeated_instances.clear();
    end_cond_valid = false;
    active = true;
}


std::vector<HDL_instance> HDL_loops_factory::get_instances() {
    active = false;
    return repeated_instances;
}

void HDL_loops_factory::add_expression(const Expression &e) {
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

