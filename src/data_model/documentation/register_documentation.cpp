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

#include "data_model/documentation/register_documentation.hpp"

register_documentation::register_documentation(const std::string& n, uint32_t off, const std::string& desc, bool read, bool write) {
    name = n;
    offset = off;
    description = desc;
    read_allowed = read;
    write_allowed = write;
}

bool operator==(const register_documentation &lhs, const register_documentation &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.offset == rhs.offset;
    ret &= lhs.description == rhs.description;
    ret &= lhs.read_allowed == rhs.read_allowed;
    ret &= lhs.write_allowed == rhs.write_allowed;

    ret &= lhs.fields.size() == rhs.fields.size();

    if(ret){
        for(int i = 0; i<lhs.fields.size(); i++){
            ret &= lhs.fields[i] == rhs.fields[i];
        }
    }

    return ret;
}

void register_documentation::add_field(field_documentation &doc) {
     fields.push_back(doc);
}
