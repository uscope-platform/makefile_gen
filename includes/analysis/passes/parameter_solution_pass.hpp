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


#ifndef MAKEFILEGEN_V2_PARAMETER_SOLVING_PASS_HPP
#define MAKEFILEGEN_V2_PARAMETER_SOLVING_PASS_HPP

#include "analysis/passes/pass_base.hpp"

enum parameter_type {
    string_parameter,
    numeric_parameter,
    array_parameter
};

struct parameter_value {
    uint64_t numeric_value;
    std::string string_value;
    parameter_type type;
};

class parameter_solution_pass : public pass_base {
public:
    parameter_solution_pass();
    void process_node(const std::shared_ptr<HDL_instance_AST> &node) override;
private:
    std::unordered_map<std::string, parameter_value> parameters_map;
};


#endif //MAKEFILEGEN_V2_PARAMETER_SOLVING_PASS_HPP