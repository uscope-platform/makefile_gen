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


enum port_direction_t {
    input_port = 0,
    output_port = 1,
    inout_port = 2,
    modport = 3
};

typedef std::unordered_map<std::string, sv_feature> hdl_deps_t;

typedef std::pair<std::string, sv_feature> hdl_declaration_t;

    class HDL_Resource {
    public:
        HDL_Resource( const HDL_Resource &c );
        HDL_Resource();
        HDL_Resource(sv_feature type, std::string n, std::string p, hdl_deps_t deps);
        hdl_deps_t get_dependencies() {return dependencies;};

        void add_dependencies(hdl_deps_t deps);
        void add_bus_roots(const std::shared_ptr<bus_crossbar>& bc) { bus_roots.push_back(bc);};
        void add_bus_roots(std::vector<std::shared_ptr<bus_crossbar>> bc) { bus_roots = std::move(bc);};
        std::vector<std::shared_ptr<bus_crossbar>> get_bus_roots() {return bus_roots;};

        void set_name(const std::string &n) {name  = n;};
        const std::string &getName() const {return name;};

        void set_path(const std::string &p) {path  = p;};
        std::string get_path() {return path;};
        void set_type(const sv_feature t) {hdl_type  = t;};
        sv_feature get_type() {return hdl_type;};
        bool is_interface();

        void set_ports(std::unordered_map<std::string, port_direction_t> m) {ports = std::move(m);};
        void add_ports(const std::string &p_n, port_direction_t dir) {ports[p_n] = dir;};

        void add_submodule(const bus_submodule &s) {bus_submodules.push_back(s);};
        void set_submodules(std::vector<bus_submodule> v) {bus_submodules = std::move(v);};
        std::vector<bus_submodule> get_submodules() {return bus_submodules;};

        void add_processor_doc(processor_instance &p) {processor_docs.push_back(p);};
        std::vector<processor_instance> get_processor_doc() {return processor_docs;};
        bool has_processors() {return !processor_docs.empty();};

        void add_parameter(std::string name, uint32_t val) {parameters[name] = val;};
        void set_parameters(std::unordered_map<std::string, uint32_t> p) { parameters = std::move(p);}
        std::unordered_map<std::string, uint32_t> get_parameters() {return parameters;};

        void set_documentation(module_documentation &d) {doc= d;};
        module_documentation get_documentation() { return doc;};

        template<class Archive>
        void serialize( Archive & ar ) {
            ar(name, path, hdl_type, dependencies, parameters, ports, bus_roots, bus_submodules, doc, processor_docs);
        }

        bool is_empty();

        friend bool operator==(const HDL_Resource&lhs, const HDL_Resource&rhs);
    private:
        std::string name;
        std::string path;
        sv_feature hdl_type;
        hdl_deps_t dependencies;
        std::vector<std::shared_ptr<bus_crossbar>> bus_roots;
        std::unordered_map<std::string, port_direction_t> ports;

        std::vector<HDL_Resource> deps_vector;
        //SV PACKAGE SPECIFIC PARAMETERS
        std::unordered_map<std::string, uint32_t> parameters;
        std::vector<bus_submodule> bus_submodules;
        std::vector<processor_instance> processor_docs;

        // DOCUMENTATION``
        module_documentation doc;
    };




#endif //MAKEFILEGEN_V2_HDL_RESOURCE_H
