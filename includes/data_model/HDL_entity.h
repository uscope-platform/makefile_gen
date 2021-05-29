//
// Created by fils on 28/05/2021.
//

#ifndef MAKEFILEGEN_V2_HDL_ENTITY_H
#define MAKEFILEGEN_V2_HDL_ENTITY_H

#include <utility>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#define SV_FEATURE_MODULE 0
#define SV_FEATURE_INTERFACE 1
#define SV_FEATURE_PROGRAM 2
#define SV_FEATURE_UDP 3
#define SV_FEATURE_NULL 4

enum sv_feature {module=SV_FEATURE_MODULE, interface=SV_FEATURE_INTERFACE,program=SV_FEATURE_PROGRAM,udp=SV_FEATURE_UDP, null=SV_FEATURE_NULL};

///  Templated function used to convert a sv_feature enum instance to the underlying integer for string conversion
/// \return integer feature code
template <typename sv_feature>
auto as_integer(sv_feature const value)
-> typename std::underlying_type<sv_feature>::type
{
    return static_cast<typename std::underlying_type<sv_feature>::type>(value);
}

typedef std::unordered_map<std::string,sv_feature> hdl_deps_t;

class HDL_entity {
public:
    HDL_entity();
    HDL_entity(sv_feature type, std::string n, std::string p, hdl_deps_t deps, std::string lang);
    explicit HDL_entity(const std::string& serialized_obj);
    operator std::string();

    const std::string &getName() const;

private:
    std::string name;
    sv_feature type;
    std::string language;
    std::string path;
    hdl_deps_t dependencies;
};


#endif //MAKEFILEGEN_V2_HDL_ENTITY_H
