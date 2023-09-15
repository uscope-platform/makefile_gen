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

#ifndef MAKEFILEGEN_V2_DATA_ACQUISITION_ANALYSIS_HPP
#define MAKEFILEGEN_V2_DATA_ACQUISITION_ANALYSIS_HPP

#include <memory>
#include "data_model/HDL/HDL_instance_AST.hpp"
#include "data_model/bus_mapping/bus_specs_manager.hpp"

class data_acquisition_analysis {
public:
    explicit data_acquisition_analysis(bool logging) {log = logging;};
    void analyze(std::shared_ptr<HDL_instance_AST> &ast);
private:
    void backtrace_scope_inputs(const std::shared_ptr<HDL_instance_AST> &node, std::string intf);

    std::optional<std::vector<std::string>> process_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port);
    std::vector<std::string> process_n_to_1_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port);
    std::vector<std::string> process_1_to_n_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port);
    std::vector<std::string> process_1_to_1_node(const std::shared_ptr<HDL_instance_AST> &node, std::string port);
    void process_source(const std::shared_ptr<HDL_instance_AST> &node, std::string port);
    std::set<std::pair<std::string, std::string>> explored_nodes;
    std::vector<std::shared_ptr<HDL_instance_AST>> find_sinks(std::shared_ptr<HDL_instance_AST> &ast);
    bus_specs_manager specs_manager;
    std::string bus_type = "axi_stream";
    bool log = false;
};


#endif //MAKEFILEGEN_V2_DATA_ACQUISITION_ANALYSIS_HPP
