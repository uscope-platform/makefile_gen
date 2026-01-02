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


#include "data_model/HDL/parameters/Concatenation.hpp"

std::set<std::string> Concatenation::get_dependencies() {
    std::set<std::string> result;
    for (auto &comp:components) {
        auto comp_deps = comp.get_dependencies();
        result.insert(comp_deps.begin(), comp_deps.end());
    }
    return result;
}

bool Concatenation::propagate_constant(const std::string &name, const resolved_parameter &value) {
   bool retval = true;
    for (auto &comp:components) {
        retval &= comp.propagate_constant(name, value);
    }
    return retval;
}

std::variant<int64_t, mdarray<int64_t>> Concatenation::elaborate(){
    return 0;
}

std::string Concatenation::print()  const{
    std::ostringstream oss;
    oss << "{";
    for (int i = 0; i< components.size(); i++) {
        oss << components[i].print();
        if (components.size()>2) {
            if (i<components.size()-1) oss <<", ";
        }
    }
    oss <<"}";
    return oss.str();
}
