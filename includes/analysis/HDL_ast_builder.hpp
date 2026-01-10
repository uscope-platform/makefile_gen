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
#include "analysis/loop_solver.hpp"

class HDL_ast_builder {
    public:
        HDL_ast_builder(const std::shared_ptr<settings_store> &s, const std::shared_ptr<data_store> &d, const Depfile& d_f);
        std::vector<std::shared_ptr<HDL_instance_AST>> build_ast(const std::vector<std::string>& modules,const Parameters_map &external_parameters);

    private:
        std::shared_ptr<HDL_instance_AST> build_ast(const std::string& top_level_module,const Parameters_map &external_parameters);
        Parameters_map specialize_parameters(int64_t idx, const Parameters_map &params, std::string idx_name);
        Expression specialize_expression(Expression &e, Parameter_processor &p);
        HDL_instance_AST specialize_instance(HDL_instance_AST &i, int64_t idx, const Parameters_map &specialized_params, std::string idx_name);
        std::unordered_map<std::string, std::vector<HDL_net>>  specialize_ports(HDL_instance_AST &i, const Parameters_map &parameters_values);
        std::shared_ptr<settings_store> s_store;
        std::shared_ptr<data_store> d_store;
        std::optional<std::shared_ptr<HDL_instance_AST>> recursive_build_ast(HDL_instance_AST &i,
                                                                         const Parameters_map &external_parameters,
                                                                         const std::shared_ptr<HDL_instance_AST>& parent
                                                                         );

        std::string get_current_path() {
            if(current_path.empty()) return "";
            std::ostringstream oss;
            std::copy(current_path.begin(), current_path.end(),
           std::ostream_iterator<std::string>(oss, "."));
            return oss.str();
        }

        std::string trace_prefix = "";
        nlohmann::json log;
        Depfile dep_file;
        std::vector<std::string> current_path;

};


#endif //MAKEFILEGEN_V2_HDL_AST_BUILDER_HPP
