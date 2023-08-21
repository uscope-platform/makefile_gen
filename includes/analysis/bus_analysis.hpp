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
#include "data_model/data_store.hpp"
#include "data_model/settings_store.hpp"
#include "data_model/Depfile.hpp"

class bus_analysis {
public:
    explicit bus_analysis(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &ds, const Depfile &df);
    void analyze_bus(HDL_instance &ast);
private:
    std::shared_ptr<settings_store> s_store;
    std::shared_ptr<data_store> d_store;
    Depfile dfile;
};


#endif //MAKEFILEGEN_V2_BUS_ANALYSIS_HPP