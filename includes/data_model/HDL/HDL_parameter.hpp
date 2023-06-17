//  Copyright 2023 Filippo Savi
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

#ifndef MAKEFILEGEN_V2_HDL_PARAMETER_HPP
#define MAKEFILEGEN_V2_HDL_PARAMETER_HPP

#include <string>


enum parameter_type {
    string_parameter=0,
    numeric_parameter=1
};

class HDL_parameter {
public:
    HDL_parameter();
    void set_name(const std::string &n){name = n;};
    void set_default_value(const std::string &dv);
    void set_value(const std::string &v);
    void set_value(uint32_t val);
    std::string get_string_value();
    uint32_t  get_numeric_value();
    std::string get_name() const {return name;};

    parameter_type get_type(){return type;};

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, default_value, value);
    }

    bool is_empty();
    friend bool operator <(const HDL_parameter& lhs, const HDL_parameter& rhs);
    friend bool operator==(const HDL_parameter&lhs, const HDL_parameter&rhs);

private:
    std::string name;
    std::string default_value;
    std::string value;
    uint32_t numeric_value;
    parameter_type type;
};


#endif //MAKEFILEGEN_V2_HDL_PARAMETER_HPP
