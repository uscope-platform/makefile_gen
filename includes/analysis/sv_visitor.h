// Copyright 2021 University of Nottingham Ningbo China
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

#ifndef MAKEFILEGEN_V2_SV_VISITOR_H
#define MAKEFILEGEN_V2_SV_VISITOR_H

#include "mgp_sv/sv2017BaseListener.h"
#include "mgp_sv/sv2017.h"
#include "data_model/HDL_Resource.h"

#include <regex>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <filesystem>

using namespace mgp_sv;





class sv_visitor : public sv2017BaseListener {

public:
    explicit sv_visitor(std::string p);
    void enterModule_declaration(sv2017::Module_declarationContext *ctx) override;
    void exitModule_declaration(sv2017::Module_declarationContext *ctx) override;
    void exitInterface_declaration(sv2017::Interface_declarationContext *ctx) override;
    void exitModule_header_common(sv2017::Module_header_commonContext *ctx) override;
    void exitModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) override;
    void exitInterface_header(sv2017::Interface_headerContext *ctx) override;
    void exitPrimaryTfCall(sv2017::PrimaryTfCallContext *ctx) override;
    void exitPackage_declaration(sv2017::Package_declarationContext *ctx) override;
    void exitPackage_or_class_scoped_path(sv2017::Package_or_class_scoped_pathContext *ctx) override;
    void exitPackage_item(sv2017::Package_itemContext *ctx) override;
    const bool is_package_declared() {return file_declare_package;};
    std::vector<std::shared_ptr<HDL_Resource>> get_entities();
private:
    hdl_declaration_t declared_feature;
    hdl_deps_t instantiated_features;
    int nesting_level = 0;
    std::stack<hdl_declaration_t> declarations_stack;
    std::stack<hdl_deps_t> dependencies_stack;
    std::string path;
    std::vector<std::shared_ptr<HDL_Resource>> entities;

    bool file_declare_package;
};


#endif //MAKEFILEGEN_V2_SV_VISITOR_H
