//  Copyright 2026 Filippo Savi
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

#include "frontend/analysis/preprocessor/conditional_solver.hpp"


void conditional_solver::close_loop() {
    loop_level--;
    if (loop_level == 0) {
        phase = inactive;
        in_taken_branch = false;
        already_taken = false;
    }
}

void conditional_solver::start_loop(bool if_taken) {
    phase = if_phase;
    in_taken_branch = if_taken;
    already_taken = if_taken;
    loop_level++;
}

void conditional_solver::advance_elseif(bool if_taken) {
    phase = elseif_phase;
    if (!in_taken_branch) {
        already_taken = if_taken;
        in_taken_branch = if_taken;
    }else {
        in_taken_branch = false;
    }
}

void conditional_solver::advance_else() {
    phase = else_phase;
    if (!already_taken) in_taken_branch = true;
    else in_taken_branch = false;

}
