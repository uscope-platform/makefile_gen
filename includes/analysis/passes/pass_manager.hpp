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

#ifndef MAKEFILEGEN_V2_PASS_MANAGER_HPP
#define MAKEFILEGEN_V2_PASS_MANAGER_HPP

#include <memory>
#include <vector>

#include "analysis/passes/pass_base.hpp"
#include "analysis/passes/parameter_solution_pass.hpp"

class pass_manager {
public:
   pass_manager();
   std::shared_ptr<HDL_instance_AST> apply_passes(const std::shared_ptr<HDL_instance_AST> &c);
private:
   std::shared_ptr<HDL_instance_AST> apply_pass(const std::shared_ptr<HDL_instance_AST> &c,const std::shared_ptr<pass_base> &pass);
   std::vector<std::shared_ptr<pass_base>> passes;
};


#endif //MAKEFILEGEN_V2_PASS_MANAGER_HPP