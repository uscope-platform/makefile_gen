//  Copyright 2026 Filippo Savi
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

//
// Created by vivado on 1/17/26.
//

#ifndef MAKEFILEGEN_V2_QUALIFIED_IDENTIFIER_HPP
#define MAKEFILEGEN_V2_QUALIFIED_IDENTIFIER_HPP

#include <string>
#include <variant>
#include "data_model/mdarray.hpp"

using resolved_parameter = std::variant<int64_t, std::string, mdarray<int64_t>,  double>;

struct qualified_identifier {
    std::string prefix;
    std::string name;

    friend bool operator==(const qualified_identifier &lhs, const qualified_identifier &rhs) {
        return std::tie(lhs.prefix, lhs.name) == std::tie(rhs.prefix, rhs.name);
    }

    friend bool operator!=(const qualified_identifier &lhs, const qualified_identifier &rhs) {
        return !(lhs == rhs);
    }

    bool operator<(const qualified_identifier& other) const {
        return std::tie(prefix, name) < std::tie(other.prefix, other.name);
    }

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, prefix);
    }
};

#endif //MAKEFILEGEN_V2_QUALIFIED_IDENTIFIER_HPP