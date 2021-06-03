//
// Created by fils on 27/05/2021.
//

#ifndef MAKEFILEGEN_V2_SV_VISITOR_H
#define MAKEFILEGEN_V2_SV_VISITOR_H

#include "mgp_sv/sv2017BaseListener.h"
#include "mgp_sv/sv2017.h"
#include "data_model/HDL_Resource.h"

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

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


    std::vector<std::shared_ptr<HDL_Resource>> get_entities();
private:
    hdl_declaration_t declared_feature;
    hdl_deps_t instantiated_features;
    int nesting_level = 0;
    std::stack<hdl_declaration_t> declarations_stack;
    std::stack<hdl_deps_t> dependencies_stack;
    std::string path;
    std::vector<std::shared_ptr<HDL_Resource>> entities;
};


#endif //MAKEFILEGEN_V2_SV_VISITOR_H
