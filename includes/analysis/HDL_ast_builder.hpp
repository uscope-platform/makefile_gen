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

#ifndef MAKEFILEGEN_V2_HDL_AST_BUILDER_HPP
#define MAKEFILEGEN_V2_HDL_AST_BUILDER_HPP

#include <memory>
#include <utility>

#include "data_model/data_store.hpp"
#include "data_model/settings_store.hpp"
#include "data_model/HDL/HDL_instance.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"

class HDL_ast_builder {
    public:
        HDL_ast_builder(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d);
        HDL_instance build_ast(const std::string& top_level_module, std::map<std::string, HDL_parameter> external_parameters);

    private:
        static  std::unordered_map<std::string, HDL_parameter> merge_parameters(std::unordered_map<std::string, HDL_parameter> parent_parameter,  std::unordered_map<std::string, HDL_parameter> instance_parameters, std::unordered_map<std::string, HDL_parameter> module_parameters);
        std::shared_ptr<settings_store> s_store;
        std::shared_ptr<data_store> d_store;
        HDL_instance top_level;
        int recursion_level;
        bool log_structure;
        void recursive_build_ast(HDL_instance &i,const std::map<std::string, HDL_parameter> &external_parameters);
};


#endif //MAKEFILEGEN_V2_HDL_AST_BUILDER_HPP
