//
// Created by fils on 28/05/2021.
//

#ifndef MAKEFILEGEN_V2_HDL_ENTITY_H
#define MAKEFILEGEN_V2_HDL_ENTITY_H

#include <utility>
#include <sstream>
#include <string>


#define SV_FEATURE_MODULE 0
#define SV_FEATURE_INTERFACE 1
#define SV_FEATURE_PROGRAM 2
#define SV_FEATURE_UDP 3

enum sv_feature {module=SV_FEATURE_MODULE, interface=SV_FEATURE_INTERFACE,program=SV_FEATURE_PROGRAM,udp=SV_FEATURE_UDP};


class HDL_entity {
    HDL_entity(std::string t, std::string n, std::string p);
    explicit operator std::string();
public:
    std::string type;
    std::string name;
    std::string path;
};


#endif //MAKEFILEGEN_V2_HDL_ENTITY_H
