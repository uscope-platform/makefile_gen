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

#include "data_model/HDL/HDL_net.hpp"

std::string HDL_net::get_full_name() const {
    auto base_name = name;
    if(!range.accessor.empty()) {
        base_name += "[" + Expression_component::print_expression(range.accessor);
        if(!range.range.empty()) {
            if(range.type ==HDL_range::increasing_range) base_name += "+";
            else if(range.type ==HDL_range::decreasing_range) base_name += "-";
            base_name += ":" + Expression_component::print_expression(range.range);
        }
        base_name += "]";
    } else if(!index.empty()) {
        base_name += "[" + Expression_component::print_expression(index) + "]";
    }
    return base_name;

}

nlohmann::json HDL_net::dump() {
    nlohmann::json ret;
    ret["name"] = name;
    return ret;
}
