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

#ifndef MAKEFILEGEN_V2_HDL_LOOPS_FACTORY_H
#define MAKEFILEGEN_V2_HDL_LOOPS_FACTORY_H

#include <vector>
#include "data_model/HDL/HDL_instance.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"

class HDL_loops_factory {
public:
    void new_loop();

    void add_instance(HDL_instance &i);
    void add_expression(const Expression &e);
    void set_identifier(std::shared_ptr<HDL_parameter> &id) {loop_specs.init  = id;}

    std::vector<HDL_instance> get_instances();
    bool in_loop(){return active;}
private:
    std::vector<HDL_instance> repeated_instances;
    generate_loop loop_specs;

    bool end_cond_valid = false;
    bool active = false;
};


#endif //MAKEFILEGEN_V2_HDL_LOOPS_FACTORY_H
