

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

#ifndef HDL_CONCAT_FACTORY_HPP
#define HDL_CONCAT_FACTORY_HPP

#include <vector>

#include "data_model/HDL/HDL_net.hpp"

class HDL_concat_factory {
public:
    void start_concat(const std::string &p) {
        active = true;
        port_name = p;
    }

    void add_net(const HDL_net &n) {
        if(active) {
            nets.push_back(n);
        }
    }

    std::vector<HDL_net> get_nets() {
        return nets;
    }
    bool is_concat() {return active;}
private:
    std::string port_name;
    std::vector<HDL_net> nets;
    bool active = false;
};



#endif //HDL_CONCAT_FACTORY_HPP
