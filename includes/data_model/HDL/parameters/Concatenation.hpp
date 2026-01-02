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


#ifndef MAKEFILEGEN_V2_CONCATENATION_HPP
#define MAKEFILEGEN_V2_CONCATENATION_HPP

#include "data_model/HDL/parameters/Expression.hpp"

#include <cereal/types/vector.hpp>

class Concatenation {
public:
    Concatenation() = default;
    void add_component(const Expression &expr) {components.push_back(expr);}

    Concatenation(const Concatenation &other) = default;
    Concatenation(Concatenation &&other) noexcept = default;

    Concatenation & operator=(const Concatenation &other) = default;
    Concatenation & operator=(Concatenation &&other) noexcept = default;

    std::set<std::string> get_dependencies();
    bool propagate_constant(const std::string &name, const resolved_parameter &value);
    std::variant<int64_t, mdarray<int64_t>> elaborate();

    std::string print() const;
    friend bool operator==(const Concatenation &lhs, const Concatenation &rhs) {
        return lhs.components == rhs.components;
    }

    friend bool operator!=(const Concatenation &lhs, const Concatenation &rhs) {
        return !(lhs == rhs);
    }


    template<class Archive>
    void serialize( Archive & ar ) {
        ar(components);
    }

private:
    std::vector<Expression> components;
};


#endif //MAKEFILEGEN_V2_CONCATENATION_HPP