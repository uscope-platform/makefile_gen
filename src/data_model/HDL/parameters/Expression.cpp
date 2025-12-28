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


#include "data_model/HDL/parameters/Expression.hpp"

std::string Expression::print() const {
    std::string ret_val;
    for(auto &item:components){
        if(item.get_type() == numeric_component){
            ret_val += std::to_string(item.get_numeric_value());
        } else if(item.get_type() == string_component || item.get_type() == operator_component || item.get_type()== function_component) {
            if(!item.get_package_prefix().empty()){
                ret_val += item.get_package_prefix() + "::";
            }
            ret_val += item.get_string_value();
        }
    }
    return ret_val;
}
