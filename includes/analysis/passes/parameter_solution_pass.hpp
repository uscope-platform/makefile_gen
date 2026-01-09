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
#include "data_model/HDL/HDL_Resource.hpp"
#include "data_model/HDL/parameters/Expression_evaluator.hpp"
#include "data_model/data_store.hpp"


struct work_order {
    std::shared_ptr<HDL_instance_AST> node;
    std::map<std::string, resolved_parameter> parent_parameters;
    std::string path;
};

class parameter_solution_pass : public pass_base {
public:
    parameter_solution_pass(const std::shared_ptr<data_store> &d);

    void setup(const std::shared_ptr<HDL_instance_AST> &root) override;
     std::map<std::string, resolved_parameter> process_parameters(const Parameters_map &map);
private:
    void update_parameters_map(std::map<std::string, resolved_parameter> parameters, std::shared_ptr<HDL_instance_AST> node);
    std::map<std::string, resolved_parameter> override_parameters(work_order &work);
    std::shared_ptr<data_store> d_store;
};


#endif //MAKEFILEGEN_V2_PARAMETER_SOLVING_PASS_HPP