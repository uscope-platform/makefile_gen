// Copyright 2021 Filippo Savi
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "data_model/HDL/HDL_parameters_factory.hpp"


void HDL_parameters_factory::new_parameter() {
    p = HDL_parameter();
}

HDL_parameter HDL_parameters_factory::get_parameter() {
    return p;
}



void HDL_parameters_factory::set_value(const std::string &s) {
    if(is_local)
        p.set_value(s);
    else
        p.set_default_value(s);
}

void HDL_parameters_factory::set_parameter_name(const std::string &s) {
    p.set_name(s);
}

void HDL_parameters_factory::set_local(bool l) {
    is_local = l;
}



