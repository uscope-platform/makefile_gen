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

#include "analysis/bus_analysis.hpp"

bus_analysis::bus_analysis(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &ds, const Depfile &df) {
    dfile = df;
    d_store = ds;
    s_store = s;
}

void bus_analysis::analyze_bus(HDL_instance &ast) {
    auto bus = dfile.get_bus_section()["control"];

    std::string bus_if = bus["bus_interface"];
    std::string starting_module  = bus["starting_module"];
    std::string bus_type = bus["type"];

    std::vector<HDL_instance> bus_leaves;
    for(auto &dep:ast.get_dependencies()){
        for(auto &connection:dep.get_ports()){
            for(auto &item:connection.second){
                if(item == bus_if){
                    bus_leaves.push_back(dep);
                    goto breakNested;
                }
            }
        }
        breakNested:;
    }
    int i = 0;
}
