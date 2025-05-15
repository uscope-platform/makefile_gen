// Copyright 2021 Filippo Savi
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// Unless required by applicable law or agreed to in writing, software

#ifndef MAKEFILEGEN_V2_HDL_INSTANCES_FACTORY_HPP
#define MAKEFILEGEN_V2_HDL_INSTANCES_FACTORY_HPP

#include "data_model/HDL/HDL_instance.hpp"
#include "data_model/HDL/factories/HDL_net_factory.hpp"

class HDL_instances_factory {
public:
    void new_dependency(const std::string &n, const std::string &p, dependency_class dc);
    void add_parameter(const std::string &name, const std::shared_ptr<HDL_parameter> &p);
    void add_port(const std::string &name, const HDL_net &value);
    HDL_instance get_dependency();
    void start_concat_port(const std::string &n);
    void stop_concat_port();

    void add_port_connection_element(const std::string &s);
    bool is_valid_dependency() const{return valid_instance;}
    bool is_in_array_range() const { return in_array_range != 0;}
    bool is_interface() const {return in_interface;}
    void start_bit_selection();
    void stop_bit_selection();

    void start_interface();
    void stop_interface();
    void start_array() {in_array = 1;}

    void start_array_range() {in_array_range = 1;}
    void advance_array_range_phase(const std::string &op);


    void add_array_quantifier(const std::shared_ptr<HDL_parameter> &p);

private:
    bool in_bit_selection = false;
    bool in_concat = false;
    int in_array_range = 0;
    bool in_interface = false;
    int in_array = 0;
    HDL_net_factory net_factory;
    std::string concat_port_name;

    HDL_instance current_instance;
    bool valid_instance;
};




#endif //MAKEFILEGEN_V2_HDL_INSTANCES_FACTORY_HPP
