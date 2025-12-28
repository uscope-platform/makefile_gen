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


#include "data_model/HDL/parameters/Expression.hpp"
#include "data_model/HDL/HDL_loop.hpp"

class HDL_function {
public:

    void set_name(const std::string &s) { name = s;}
    void start_assignment(const std::string &n, Expression idx);
    void close_assignment(Expression val);
    void add_assignment(const assignment &a){assignments.push_back(a);}
    void add_loop_metadata(const HDL_loop_metadata &l){loop_metadata = l;}
    bool is_scalar() const;
    uint64_t evaluate_scalar();
    std::vector<uint64_t> evaluate_vector();
    std::vector<assignment> get_assignments()const{ return assignments;};
    HDL_loop_metadata get_loop()const{ return loop_metadata;};
    bool operator==(const HDL_function &rhs) const;

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, assignments, loop_metadata);
    }
    std::string name;
private:
    std::vector<assignment> assignments;
    HDL_loop_metadata loop_metadata;
};



#endif //HDL_FUNCTION_HPP
