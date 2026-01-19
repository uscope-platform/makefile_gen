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
#include<set>


#include "data_model/HDL/HDL_loop.hpp"

class Expression;

class HDL_function_def {
public:

    void set_name(const std::string &s) { name = s;}
    void start_assignment(const std::string &n, Expression idx);
    void close_assignment(Expression val);
    void add_assignment(const assignment &a){assignments.push_back(a);}
    void add_loop_metadata(const HDL_loop_metadata &l){loop_metadata = l;}
    bool is_scalar() const;
    std::optional<resolved_parameter> evaluate_scalar();
    std::optional<resolved_parameter> evaluate_vector();
    std::vector<assignment> get_assignments()const{ return assignments;};
    std::optional<HDL_loop_metadata> get_loop()const{ return loop_metadata;};
    bool operator==(const HDL_function_def &rhs) const;

    std::set<qualified_identifier> get_dependencies()const;
    bool propagate_constant(const qualified_identifier &name, const resolved_parameter &value);\
    std::optional<resolved_parameter> evaluate(bool pack_result);

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, assignments, loop_metadata);
    }
    std::string name;
private:
    std::vector<assignment> assignments;
    std::optional<HDL_loop_metadata> loop_metadata;
};



#endif //HDL_FUNCTION_HPP
