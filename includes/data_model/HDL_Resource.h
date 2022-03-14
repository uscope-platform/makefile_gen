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

#ifndef MAKEFILEGEN_V2_HDL_RESOURCE_H
#define MAKEFILEGEN_V2_HDL_RESOURCE_H

#include <utility>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

#include "data_model/documentation/module_documentation.h"
#include "data_model/documentation/bus_structure/bus_structure.h"

#include "third_party/cereal/archives/binary.hpp"
#include "third_party/cereal/types/unordered_map.hpp"
#include "third_party/cereal/types/vector.hpp"
#include "third_party/cereal/types/memory.hpp"

#define SV_FEATURE_MODULE 0
#define SV_FEATURE_INTERFACE 1
#define SV_FEATURE_PROGRAM 2
#define SV_FEATURE_UDP 3
#define SV_FEATURE_NULL 4
#define SV_FEATURE_PACKAGE 6
#define SV_MEMORY_INIT_FILE 5

enum sv_feature {module=SV_FEATURE_MODULE, interface=SV_FEATURE_INTERFACE,program=SV_FEATURE_PROGRAM,
        udp=SV_FEATURE_UDP, null_feature=SV_FEATURE_NULL, memory_init=SV_MEMORY_INIT_FILE, package=SV_FEATURE_PACKAGE};

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
    HDL_Resource( const HDL_Resource &c );
    HDL_Resource() = default;
    HDL_Resource(sv_feature type, std::string n, std::string p, hdl_deps_t deps, resource_type_t r_type);
    hdl_deps_t get_dependencies();
    void add_dependencies(hdl_deps_t deps);
    void add_bus_roots(const std::shared_ptr<bus_crossbar>& bc) { bus_roots.push_back(bc);};
    void add_bus_roots(std::vector<std::shared_ptr<bus_crossbar>> bc) { bus_roots = std::move(bc);};
    std::vector<std::shared_ptr<bus_crossbar>> get_bus_roots() {return bus_roots;};
    const std::string &getName() const;
    std::string get_path();
    sv_feature get_type() {return hdl_type;};
    bool is_interface();

    void add_submodule(const bus_submodule &s) {bus_submodules.push_back(s);};
    void set_submodules(std::vector<bus_submodule> v) {bus_submodules = std::move(v);};
    std::vector<bus_submodule> get_submodules() {return bus_submodules;};

    void set_parameters(std::unordered_map<std::string, uint32_t> p) { parameters = std::move(p);}
    std::unordered_map<std::string, uint32_t> get_parameters() {return parameters;};

    void set_documentation(module_documentation &d) {doc= d;};
    module_documentation get_documentation() { return doc;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, path, resource_type, hdl_type, dependencies, parameters, bus_roots, bus_submodules, doc);
    }

    friend bool operator==(const HDL_Resource&lhs, const HDL_Resource&rhs);
private:
    std::string name;
    std::string path;
    resource_type_t resource_type;
    sv_feature hdl_type;
    hdl_deps_t dependencies;
    std::vector<std::shared_ptr<bus_crossbar>> bus_roots;

    //SV PACKAGE SPECIFIC PARAMETERS
    std::unordered_map<std::string, uint32_t> parameters;
    std::vector<bus_submodule> bus_submodules;

    // DOCUMENTATION
    module_documentation doc;
};




#endif //MAKEFILEGEN_V2_HDL_RESOURCE_H
