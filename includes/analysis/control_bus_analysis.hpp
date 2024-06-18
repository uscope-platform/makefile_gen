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

#ifndef MAKEFILEGEN_V2_CONTROL_BUS_ANALYSIS_HPP
#define MAKEFILEGEN_V2_CONTROL_BUS_ANALYSIS_HPP

#include "data_model/HDL/HDL_instance_AST.hpp"
#include "data_model/bus_mapping/bus_specs_manager.hpp"
#include "data_model/data_store.hpp"
#include "data_model/settings_store.hpp"
#include "data_model/Depfile.hpp"



typedef struct {
    std::shared_ptr<HDL_instance_AST> node;
    std::string interface;
    int64_t address;
    bool parametric;
    std::string current_module_top;
    std::string current_module_prefix;
    proxy_target proxy;
}analysis_context;

struct bus_context{
    std::string name;
    int64_t address;
    int idx;
    bool in_array;
};


class control_bus_analysis {
public:
    explicit control_bus_analysis(const Depfile &df);
    void analyze_bus(std::shared_ptr<HDL_instance_AST> &ast);
    void analyze_bus(std::shared_ptr<HDL_instance_AST> &ast, const std::string &intf);
private:

    std::vector<analysis_context> process_interconnect(const analysis_context &inst);
    std::vector<analysis_context> process_simple_interconnect(const analysis_context &inst);
    std::vector<analysis_context> process_parametric_interconnect(const analysis_context &inst);
    std::vector<analysis_context> process_nested_module(const analysis_context &inst);
    void process_leaf_node(const analysis_context &inst);
    void analize_node(const std::vector<analysis_context> &c);
    std::vector<bus_context> expand_bus_array(
            const std::vector<std::string> &s,
            const std::shared_ptr<HDL_instance_AST> &parent,
            const std::vector<int64_t> &a
            );


    Depfile dfile;
    std::string bus_type;
    bus_specs_manager specs_manager;

};


#endif //MAKEFILEGEN_V2_CONTROL_BUS_ANALYSIS_HPP
