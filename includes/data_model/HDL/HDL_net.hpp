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


#ifndef HDL_NET_HPP
#define HDL_NET_HPP

#include<string>
#include <nlohmann/json.hpp>

#include "data_model/HDL/parameters/HDL_parameter.hpp"

class HDL_net {
public:
    HDL_net() = default;
    explicit HDL_net(const std::string &s) {name = s;}
    std::string name;
    HDL_parameter array_accessor;
    std::string get_full_name() const;

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, array_accessor);
    }

    friend bool operator==(const HDL_net &lhs, const HDL_net &rhs) {
        return lhs.name == rhs.name
               && lhs.array_accessor == rhs.array_accessor;
    }

    friend bool operator!=(const HDL_net &lhs, const HDL_net &rhs) {
        return !(lhs == rhs);
    }

    virtual nlohmann::json dump();
};


#endif //HDL_NET_HPP
