//  Copyright 2025 Filippo Savi
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


#ifndef HDL_NET_FACTORY_HPP
#define HDL_NET_FACTORY_HPP

#include "data_model/HDL/HDL_net.hpp"

class HDL_net_factory {
public:
    void new_net(const std::string &name);
    std::vector<HDL_net> get_nets();
    void add_accessor_component(const std::string &c);
    void add_range_component(const std::string &c);
    void set_range_type(HDL_selection::range_type_t t);
    void add_replication_size(const std::string &c);
    void add_replication_target(const std::string &c);
private:
    std::vector<HDL_net> nets;
    HDL_net current_net;
};



#endif //HDL_NET_FACTORY_HPP
