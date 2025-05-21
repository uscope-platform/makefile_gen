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

#ifndef MAKEFILEGEN_V2_HDL_RESOURCE_HPP
#define MAKEFILEGEN_V2_HDL_RESOURCE_HPP

#include <utility>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

#include "data_model/HDL/HDL_instance.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/documentation/module_documentation.hpp"

#include <cereal/archives/binary.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/memory.hpp>

#include <spdlog/spdlog.h>
#include "data_model/HDL/HDL_definitions.hpp"
#include "parameters/HDL_function.hpp"

class HDL_Resource {
    public:
        HDL_Resource( const HDL_Resource &c );
        HDL_Resource();
        HDL_Resource(dependency_class type, std::string n, std::string p);

        std::vector<HDL_instance> get_dependencies(){return dependencies;};
        void set_dependencies(std::vector<HDL_instance> &d) {
            locking_violation_check();
            dependencies = d;
        };

        void add_dependencies(std::vector<HDL_instance> deps);
        void add_dependency(const HDL_instance &dep);

        void set_name(const std::string &n) {
            locking_violation_check();
            name  = n;
        };
        const std::string &getName() const {return name;};

        void set_path(const std::string &p) {
            locking_violation_check();
            path  = p;
        };
        std::string get_path() {return path;}
        void set_type(const dependency_class t) {
            locking_violation_check();
            hdl_type  = t;
        };
        dependency_class get_type() {return hdl_type;};
        bool is_interface();

        void set_ports(std::unordered_map<std::string, port_direction_t> m) {
            locking_violation_check();
            ports = std::move(m);
        };
        void add_ports(const std::string &p_n, port_direction_t dir) {
            locking_violation_check();
            ports[p_n] = dir;
        };

        void add_if_port_specs(const std::string &p_n, const std::string &if_name, const std::string &modport);
        std::unordered_map<std::string, std::array<std::string, 2>> get_if_port_specs();


        void add_processor_doc(processor_instance &p) {
            locking_violation_check();
            processor_docs.push_back(p);
        };
        std::vector<processor_instance> get_processor_doc() {return processor_docs;};
        bool  has_processors() {return !processor_docs.empty();};

        void add_parameter(const std::shared_ptr<HDL_parameter> &p) {
            locking_violation_check();
            parameters.insert(p);
        }
        void set_parameters(Parameters_map p);
        Parameters_map get_parameters() {return parameters;};

        void add_function(const HDL_function &f) {
            locking_violation_check();
            functions[f.name] = f;
        }
        std::unordered_map<std::string, HDL_function> get_functions() {return functions;};


        void set_documentation(module_documentation &d) {
            locking_violation_check();
            doc= d;
        };
        module_documentation get_documentation() const { return doc;}

        template<class Archive>
        void serialize( Archive & ar ) {
            ar(name, path, hdl_type, dependencies, if_specs, parameters, ports, doc, processor_docs, functions);
        }
        void lock_resource();

        bool is_empty();
        friend bool operator <(const HDL_Resource& lhs, const HDL_Resource& rhs);
        friend bool operator==(const HDL_Resource&lhs, const HDL_Resource&rhs);

        friend void PrintTo(const HDL_Resource& res, std::ostream* os);

        void locking_violation_check() {
            if(lock) {
                spdlog::error("Attempting to modify a locked resource {}:{}",path, name);
                exit(1);
            }
        }

private:
        bool lock = false;
        std::string name;
        std::string path;
        dependency_class hdl_type;
        std::vector<HDL_instance> dependencies;
        std::unordered_map<std::string, port_direction_t> ports;
        std::unordered_map<std::string, std::array<std::string, 2>> if_specs;

        Parameters_map parameters;
        std::unordered_map<std::string, HDL_function> functions;

        std::vector<processor_instance> processor_docs;

        // DOCUMENTATION``
        module_documentation doc;
    };




#endif //MAKEFILEGEN_V2_HDL_RESOURCE_HPP
