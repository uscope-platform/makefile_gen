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


#ifndef MAKEFILEGEN_V2_HDL_FUNCTION_CALL_HPP
#define MAKEFILEGEN_V2_HDL_FUNCTION_CALL_HPP

#include "data_model/HDL/parameters/Parameter_value_base.hpp"
#include "data_model/HDL/parameters/Expression_component.hpp"



class HDL_function_call : public Parameter_value_base{
public:
    HDL_function_call() = default;
    explicit HDL_function_call(const std::string &n){function_name = n;}
    void set_name(const std::string &n){function_name = n;}
    std::string get_name(){return function_name;}
    void add_argument(const std::shared_ptr<Parameter_value_base> &p);

    std::set<qualified_identifier> get_dependencies()const;
    bool propagate_constant(const qualified_identifier &constant_id, const resolved_parameter &value);
    std::optional<resolved_parameter> evaluate(bool pack_result);
    std::string print() const;
    int64_t get_size();

    int64_t get_depth();

    [[nodiscard]] bool empty() const;

    std::shared_ptr<Parameter_value_base> clone_ptr() const;



    template<class Archive>
    void serialize( Archive & ar ) {
        ar(function_name, arguments);
    }

private:
    std::string function_name;
    std::vector<std::shared_ptr<Parameter_value_base>> arguments;

    bool isEqual(const Parameter_value_base& other) const override;

};


#endif //MAKEFILEGEN_V2_HDL_FUNCTION_CALL_HPP