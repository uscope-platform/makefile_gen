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
    taken_level.erase(loop_level);
    loop_level--;
    if (loop_level == 0) {
        phase = inactive;
        in_taken_branch = false;
        already_taken = false;
    } else {
        already_taken = already_taken_stack.back();
        already_taken_stack.pop_back();
    }
}

void conditional_solver::start_loop(bool if_taken) {
    loop_level++;
    if (loop_level>1) already_taken_stack.push_back(already_taken);
    if (loop_level == 1 || in_taken_branch) {
        phase = if_phase;
        if (if_taken) {
            taken_level.insert(loop_level);
            in_taken_branch = true;
            already_taken = true;
        } else {
            in_taken_branch = false;
            already_taken = false;
        }
    }
}

void conditional_solver::advance_elseif(bool if_taken) {
    if (loop_level == 1 || in_taken_branch|| taken_level.contains(loop_level-1)) {
        phase = elseif_phase;
        if (!in_taken_branch) {
            if (if_taken) {
                taken_level.insert(loop_level);
                in_taken_branch = true;
                already_taken = true;
            }
        }else {
            in_taken_branch = false;
        }
    }
}

void conditional_solver::advance_else() {
    if (loop_level == 1 || in_taken_branch|| taken_level.contains(loop_level-1)) {
        phase = else_phase;
        if (!already_taken) {
            taken_level.insert(loop_level);
            in_taken_branch = true;
        }
        else {
            in_taken_branch = false;
        }
    }
}

bool conditional_solver::is_active() const {
    return phase == inactive || (in_taken_branch && taken_level.contains(loop_level));
}
