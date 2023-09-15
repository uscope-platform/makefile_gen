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

#ifndef MAKEFILEGEN_V2_HDL_INSTANCE_AST_HPP
#define MAKEFILEGEN_V2_HDL_INSTANCE_AST_HPP

#include <vector>
#include <memory>

#include "data_model/HDL/HDL_instance.hpp"



class HDL_instance_AST : public HDL_instance {
public:
    HDL_instance_AST() = default;
    HDL_instance_AST(const HDL_instance_AST &c );
    HDL_instance_AST(const HDL_instance &c );

    std::vector<std::shared_ptr<HDL_instance_AST>> get_dependencies() {return child_instances;};
    void add_child(const std::shared_ptr<HDL_instance_AST> &i) {child_instances.push_back(i);};

    void set_parent(const std::shared_ptr<HDL_instance_AST> &p){parent = p;};
    std::shared_ptr<HDL_instance_AST> get_parent(){return parent;};

    void add_address(const int64_t &i) { bus_address.push_back(i);};
    std::vector<int64_t> get_address(){return bus_address;};

    void add_data_dependency(const std::string &p){data_dependencies.push_back(p);};
    std::vector<std::string> get_data_dependencies(){return data_dependencies;};

    void add_package_dependency(const std::string &p){package_dependencies.push_back(p);};
    std::vector<std::string> get_package_dependencies(){return package_dependencies;};

    void set_leaf_module_top(const std::string &s){leaf_module_top = s;};
    std::string get_leaf_module_top(){return leaf_module_top;};

    void set_if_specs(const std::unordered_map<std::string, std::array<std::string, 2>> &if_s){if_specs = if_s;};
    std::unordered_map<std::string, std::array<std::string, 2>> get_if_specs(){return if_specs;};

     nlohmann::json dump() override;

    friend bool operator==(const HDL_instance_AST&lhs, const HDL_instance_AST&rhs);

private:

    std::vector<int64_t> bus_address;
    std::shared_ptr<HDL_instance_AST> parent;
    std::vector<std::shared_ptr<HDL_instance_AST>> child_instances;

    std::vector<std::string> data_dependencies;
    std::vector<std::string> package_dependencies;

    std::unordered_map<std::string, std::array<std::string, 2>> if_specs;

    std::string leaf_module_top;
};


#endif //MAKEFILEGEN_V2_HDL_INSTANCE_AST_HPP
