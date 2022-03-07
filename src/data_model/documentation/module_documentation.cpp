// Copyright 2021 Filippo Savi
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include "data_model/documentation/module_documentation.h"


void module_documentation::add_register(const register_documentation& reg) {
    registers.push_back(reg);
}



bool operator==(const module_documentation &lhs, const module_documentation &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.registers.size() == rhs.registers.size();

    if(ret){
        for(int i = 0; i<lhs.registers.size(); i++){
            ret &= lhs.registers[i] == rhs.registers[i];
        }
    }

    return ret;
}
