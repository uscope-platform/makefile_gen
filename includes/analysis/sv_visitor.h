//
// Created by fils on 27/05/2021.
//

#ifndef MAKEFILEGEN_V2_SV_VISITOR_H
#define MAKEFILEGEN_V2_SV_VISITOR_H

#include "mgp_sv/sv2017BaseListener.h"
#include "mgp_sv/sv2017.h"
#include "data_model/HDL_entity.h"

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace mgp_sv;

class sv_visitor : public sv2017BaseListener {

public:
    void exitModule_header_common(sv2017::Module_header_commonContext *ctx) override;
    void exitModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) override;
    void exitInterface_header(sv2017::Interface_headerContext *ctx) override;
    std::unordered_map<std::string,sv_feature> get_declared_features();
    std::unordered_map<std::string,sv_feature> get_instantiated_features();

private:
    std::unordered_map<std::string,sv_feature> declared_features;
    std::unordered_map<std::string,sv_feature> instantiated_features;
};


#endif //MAKEFILEGEN_V2_SV_VISITOR_H
