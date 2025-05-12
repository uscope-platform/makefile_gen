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


#ifndef HDL_FUNCTIONS_FACTORY_HPP
#define HDL_FUNCTIONS_FACTORY_HPP
#include <string>

#include "data_model/HDL/parameters/HDL_function.hpp"

class HDL_functions_factory {
public:
    void set_name(const std::string  &s) { f.set_name(s);}
private:
    HDL_function f;
};



#endif //HDL_FUNCTIONS_FACTORY_HPP
