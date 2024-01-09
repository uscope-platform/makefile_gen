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
#include <optional>
#include <nlohmann/json.hpp>

#include "data_model/data_store.hpp"
#include "data_model/Depfile.hpp"
#include "data_model/settings_store.hpp"
#include "data_model/HDL/HDL_instance.hpp"
#include "data_model/HDL/HDL_instance_AST.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"
#include "analysis/HDL_loop_solver.hpp"

class HDL_ast_builder {
    public:
        HDL_ast_builder(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d, const Depfile& d_f);
        std::shared_ptr<HDL_instance_AST> build_ast(const std::string& top_level_module,const Parameters_map &external_parameters);
        std::vector<std::shared_ptr<HDL_instance_AST>> build_ast(const std::vector<std::string>& modules,const Parameters_map &external_parameters);

    private:
        Parameters_map specialize_parameters(int64_t idx, const Parameters_map &params, std::string idx_name);
        HDL_instance_AST specialize_instance(HDL_instance_AST &i, int64_t idx, const Parameters_map &specialized_params, std::string idx_name);
        std::shared_ptr<settings_store> s_store;
        std::shared_ptr<data_store> d_store;
        bool log_structure;
        std::optional<std::shared_ptr<HDL_instance_AST>> recursive_build_ast(HDL_instance_AST &i,
                                                                         const Parameters_map &external_parameters,
                                                                         const std::shared_ptr<HDL_instance_AST>& parent
                                                                         );
        nlohmann::json log;
        Depfile dep_file;


};


#endif //MAKEFILEGEN_V2_HDL_AST_BUILDER_HPP
