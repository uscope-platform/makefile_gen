//
// Created by fils on 28/05/2021.
//

#ifndef MAKEFILEGEN_V2_HDL_RESOURCE_H
#define MAKEFILEGEN_V2_HDL_RESOURCE_H

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

enum sv_feature {module=SV_FEATURE_MODULE, interface=SV_FEATURE_INTERFACE,program=SV_FEATURE_PROGRAM,
        udp=SV_FEATURE_UDP, null_feature=SV_FEATURE_NULL};

///  Templated function used to convert a sv_feature enum instance to the underlying integer for string conversion
/// \return integer feature code
template <typename sv_feature>
auto feature_to_integer(sv_feature const value)
-> typename std::underlying_type<sv_feature>::type
{
    return static_cast<typename std::underlying_type<sv_feature>::type>(value);
}


#define RES_VERILOG_ENTITY 0
#define RES_VHDL_ENTITY 1
#define RES_SCRIPT 2
#define RES_CONSTRAINT 3
#define RES_NULL 4
enum resource_type_t {verilog_entity=RES_VERILOG_ENTITY, vhdl_entity=RES_VHDL_ENTITY,
        script=RES_SCRIPT, constraint=RES_CONSTRAINT, null_resource=RES_NULL};

///  Templated function used to convert a resource_type_t enum instance to the underlying integer for string conversion
/// \return integer feature code
template <typename resource_type_t>
auto resource_to_integer(resource_type_t const value)
-> typename std::underlying_type<resource_type_t>::type
{
    return static_cast<typename std::underlying_type<resource_type_t>::type>(value);
}

typedef std::unordered_map<std::string,sv_feature> hdl_deps_t;

typedef std::pair<std::string, sv_feature> hdl_declaration_t;

class HDL_Resource {
public:
    HDL_Resource();
    HDL_Resource(sv_feature type, std::string n, std::string p, hdl_deps_t deps, resource_type_t r_type);
    explicit HDL_Resource(const std::string& serialized_obj);
    operator std::string();

    const std::string &getName() const;

private:
    std::string name;
    std::string path;
    resource_type_t resource_type;
    sv_feature hdl_type;

    hdl_deps_t dependencies;
};


#endif //MAKEFILEGEN_V2_HDL_RESOURCE_H
