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

#ifndef MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP
#define MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP

#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/resource_factory_base.hpp"
#include "data_model/expressions/expression.hpp"
#include "data_model/expressions/expression_evaluator.hpp"

class HDL_parameters_factory : protected resources_factory_base<HDL_parameter>{

public:
    void new_parameter();
    void set_local(bool l);
    HDL_parameter get_parameter();
    void set_value(const std::string &s);
    void set_parmeter_name(const std::string &s) { set_name(s);};
    void add_operand(const std::string &s);
    void add_operator(const std::string &s);
private:
    bool is_local{};
};


#endif //MAKEFILEGEN_V2_HDL_PARAMETERS_FACTORY_HPP
