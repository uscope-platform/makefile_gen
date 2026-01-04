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


#ifndef MAKEFILEGEN_V2_REPLICATION_HPP
#define MAKEFILEGEN_V2_REPLICATION_HPP

#include "data_model/HDL/parameters/Expression.hpp"
#include "data_model/HDL/parameters/Concatenation.hpp"


class Replication {
public:
    Replication() = default;
    Replication(const Expression &size, const std::variant<Expression, Concatenation> &item) {
        repeated_item = item;
        repetition_size = size;
    }

    Replication(const Replication &other) = default;
    Replication(Replication &&other) noexcept = default;

    Replication & operator=(const Replication &other) = default;
    Replication & operator=(Replication &&other) noexcept = default;

    void set_item(const std::variant<Expression, Concatenation> &item){ repeated_item = item;}
    void set_size(const Expression &size){ repetition_size = size;}

    std::set<std::string> get_dependencies()const;
    bool propagate_constant(const std::string &name, const resolved_parameter &value);
    resolved_parameter evaluate(bool packed);

    int64_t pack_repetition(int64_t value, int64_t width, int64_t count);

    std::string print() const;
    friend bool operator==(const Replication &lhs, const Replication &rhs) {
        return std::tie(lhs.repetition_size, lhs.repeated_item) ==  std::tie(rhs.repetition_size, rhs.repeated_item);
    }

    friend bool operator!=(const Replication &lhs, const Replication &rhs) {
        return !(lhs == rhs);
    }


    template<class Archive>
    void serialize( Archive & ar ) {
        ar(repetition_size, repeated_item);
    }

private:
    Expression repetition_size;
    std::variant<Expression, Concatenation> repeated_item;
};


#endif //MAKEFILEGEN_V2_REPLICATION_HPP