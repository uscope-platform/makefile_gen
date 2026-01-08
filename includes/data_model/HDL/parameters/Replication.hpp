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
#include "data_model/HDL/parameters/Parameter_value_base.hpp"


class Replication : public Parameter_value_base{
public:
    Replication() {
        type = replication;
    };
    Replication(const Expression &size, std::shared_ptr<Parameter_value_base> item) {
        repeated_item = std::move(item);
        repetition_size = size;
        type = replication;
    }

    Replication(const Replication &other) {
        repetition_size = other.repetition_size;
        if(other.repeated_item != nullptr) repeated_item = other.repeated_item->clone_ptr();
        type = other.type;
    }

    Replication(Replication &&other) noexcept {
        repetition_size = other.repetition_size;
        if(other.repeated_item != nullptr) repeated_item = other.repeated_item->clone_ptr();
        type = other.type;
    }

    Replication clone() const;
    int64_t get_depth() override;

    Replication &operator=(const Replication &other) {
        if (this != &other) {
            repetition_size = other.repetition_size;
            if(other.repeated_item != nullptr) repeated_item = other.repeated_item->clone_ptr();
            type = other.type;
        }
        return *this;
    }

    Replication &operator=(Replication &&other) noexcept {
        if (this != &other) {
            repetition_size = other.repetition_size;
            if(other.repeated_item != nullptr) repeated_item = other.repeated_item->clone_ptr();
            type = other.type;
        }
        return *this;
    }


    void set_item(std::shared_ptr<Parameter_value_base> item){ repeated_item = std::move(item);}
    void set_size(const Expression &size){ repetition_size = size;}

    std::set<std::string> get_dependencies()const;
    bool propagate_constant(const std::string &name, const resolved_parameter &value);
    std::optional<resolved_parameter> evaluate(bool pack_result);

    int64_t pack_repetition(int64_t value, int64_t width, int64_t count);

    std::string print() const;
    friend bool operator==(const Replication &lhs, const Replication &rhs) {
        if(lhs.repeated_item == nullptr &&  lhs.repeated_item == nullptr ) return true;
        if(lhs.repeated_item == nullptr || lhs.repeated_item == nullptr) return false;

        return std::tie(lhs.repetition_size, *lhs.repeated_item) ==  std::tie(rhs.repetition_size, *rhs.repeated_item);
    }

    friend bool operator!=(const Replication &lhs, const Replication &rhs) {
        return !(lhs == rhs);
    }

    std::shared_ptr<Parameter_value_base> clone_ptr() const override {
        return std::make_shared<Replication>(*this);  // Copy constructor
    }


    template<class Archive>
    void serialize( Archive & ar ) {
        ar(repetition_size, repeated_item);
    }
    bool isEqual(const Parameter_value_base &other) const override{
        // Clangd error "No viable conversion" usually means:
        // 1. The compiler thinks 'other' isn't a Parameter_value_base (check headers)
        // 2. Replication isn't fully defined yet.

        const auto& rhs = static_cast<const Replication&>(other);

        // Use the base operator== for the shared_ptr to handle the polymorphism
        return repetition_size == rhs.repetition_size &&
               *repeated_item == *rhs.repeated_item;
    }
private:
    Expression repetition_size;
    std::shared_ptr<Parameter_value_base> repeated_item;
};


#endif //MAKEFILEGEN_V2_REPLICATION_HPP