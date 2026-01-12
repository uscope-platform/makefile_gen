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

#ifndef HDL_LOOP_HPP
#define HDL_LOOP_HPP

#include "parameters/HDL_parameter.hpp"

#include <optional>
#include <cereal/types/optional.hpp>

struct assignment {
    friend bool operator==(const assignment &lhs, const assignment &rhs) {
        return lhs.name == rhs.name
               && lhs.index == rhs.index
               && lhs.value == rhs.value;
    }

    friend bool operator!=(const assignment &lhs, const assignment &rhs) {
        return !(lhs == rhs);
    }

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, index, value);
    }
    std::string name;
    std::optional<Expression> index;
    Expression value;
};

class HDL_loop_metadata {

public:

    HDL_loop_metadata() = default;

    HDL_loop_metadata(const HDL_loop_metadata &other)
        : locked(other.locked),
          init(other.init),
          end_c(other.end_c),
          iter(other.iter),
          assignments(other.assignments) {
    }

    HDL_loop_metadata(HDL_loop_metadata &&other) noexcept
        : locked(other.locked),
          init(std::move(other.init)),
          end_c(std::move(other.end_c)),
          iter(std::move(other.iter)),
          assignments(std::move(other.assignments)) {
    }

    HDL_loop_metadata & operator=(const HDL_loop_metadata &other) {
        if(this == &other)
            return *this;
        locked = other.locked;
        init = other.init;
        end_c = other.end_c;
        iter = other.iter;
        assignments = other.assignments;
        return *this;
    }

    HDL_loop_metadata & operator=(HDL_loop_metadata &&other) noexcept {
        if(this == &other)
            return *this;
        locked = other.locked;
        init = std::move(other.init);
        end_c = std::move(other.end_c);
        iter = std::move(other.iter);
        assignments = std::move(other.assignments);
        return *this;
    }

    void propagate_constant(const std::string &name, const resolved_parameter &value) {
        init.propagate_constant(name, value);
        end_c.propagate_constant(name, value);
        iter.propagate_constant(name, value);
    }

    void lock() {locked = true;}
    void set_init(const HDL_parameter &p) {
        locking_violation_check();
        init = p;
    }
    void set_end_c(const Expression &e) {
        locking_violation_check();
        end_c = e;
    }
    void set_iter(const Expression &i) {
        locking_violation_check();
        iter = i;
    }
    void add_assignment(const assignment &a) {
        locking_violation_check();
        assignments.push_back(a);
    }
    void set_assignments(const std::vector<assignment> &a) {
        locking_violation_check();
        assignments = a;
    }
    HDL_parameter get_init() const {
        return init;
    }
    Expression get_end_c() const {
        return end_c;
    }
    Expression get_iter() const {
        return iter;
    }
    std::vector<assignment> get_assignments() const {
        return assignments;
    }
    template<class Archive>
    void serialize(Archive & archive){
        archive( init, end_c, iter, assignments);
    }
    void locking_violation_check() {
        if(locked) {
            spdlog::error("Attempting to modify a locked loop with index {}",init.get_name());
            exit(1);
        }
    }
private:
    bool locked = false;
    HDL_parameter init;
    Expression end_c;
    Expression iter;
    std::vector<assignment> assignments;

    friend bool operator==(const HDL_loop_metadata &lhs, const HDL_loop_metadata &rhs) {
        return lhs.locked == rhs.locked
               && lhs.init == rhs.init
               && lhs.end_c == rhs.end_c
               && lhs.iter == rhs.iter
               && lhs.assignments == rhs.assignments;
    }

    friend bool operator!=(const HDL_loop_metadata &lhs, const HDL_loop_metadata &rhs) {
        return !(lhs == rhs);
    }



};

#endif //HDL_LOOP_HPP
