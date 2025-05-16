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


struct HDL_selection {
    Expression accessor;
    Expression range;
    enum range_type_t{ explicit_range, increasing_range, decreasing_range};
    range_type_t type = explicit_range;

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(accessor, range,type);
    }


    friend bool operator==(const HDL_selection &lhs, const HDL_selection &rhs) {
        bool retval =true;
        retval &= lhs.accessor == rhs.accessor;
        retval &= lhs.range == rhs.range;
        retval &= lhs.type == rhs.type;
        return retval;
    }

};


class HDL_net {
public:
    HDL_net() = default;
    explicit HDL_net(const std::string &s) {name = s;}
    std::string name;

    HDL_selection selection;
    HDL_parameter replication_target;
    HDL_parameter replication_size;
    std::string get_full_name() const;

    bool is_replication() {
        return !replication_size.is_empty();
    }
    bool is_array() {
        return !selection.accessor.empty();
    }


    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, selection,replication_size, replication_target);
    }

    friend bool operator==(const HDL_net &lhs, const HDL_net &rhs) {
        bool retval =true;
        retval &= lhs.name == rhs.name;
        retval &= lhs.selection == rhs.selection;
        retval &= lhs.replication_size == rhs.replication_size;
        retval &= lhs.replication_target == rhs.replication_target;
        return retval;
    }

    friend bool operator!=(const HDL_net &lhs, const HDL_net &rhs) {
        return !(lhs == rhs);
    }

    virtual nlohmann::json dump();
};


#endif //HDL_NET_HPP
