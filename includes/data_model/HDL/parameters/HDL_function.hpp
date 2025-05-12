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

#ifndef HDL_FUNCTION_HPP
#define HDL_FUNCTION_HPP
#include <string>
#include <vector>
#include <cstdint>


#include "data_model/HDL/parameters/Expression_component.hpp"

typedef std::vector<Expression_component> Expression;

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
    Expression index;
    Expression value;
};


class HDL_function {
public:

    void set_name(const std::string &s) { name = s;}
    void start_assignment(const std::string &n, Expression idx);
    void close_assignment(Expression val);
    void add_assignment(const assignment &a){assignments.push_back(a);};

    bool operator==(const HDL_function &rhs) const;

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, assignments);
    }
    std::string name;
private:
    std::vector<assignment> assignments;
};



#endif //HDL_FUNCTION_HPP
