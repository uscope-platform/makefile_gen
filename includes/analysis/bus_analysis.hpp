//  Copyright 2023 Filippo Savi
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

#ifndef MAKEFILEGEN_V2_BUS_ANALYSIS_HPP
#define MAKEFILEGEN_V2_BUS_ANALYSIS_HPP

#include "data_model/HDL/HDL_instance.hpp"
class bus_analysis {
public:
    bus_analysis(const HDL_instance &a);

private:
    HDL_instance AST;
};


#endif //MAKEFILEGEN_V2_BUS_ANALYSIS_HPP
