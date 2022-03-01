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

#include "data_model/documentation/field_documentation.h"

#include <utility>

field_documentation::field_documentation() {
    name = "";
    description = "";
    start_position = 0;
    length = 0;

}

field_documentation::field_documentation(std::string n, std::string desc, uint8_t start, uint8_t len) {
    name = std::move(n);
    description = std::move(desc);
    start_position = start;
    length = len;
}

bool operator==(const field_documentation &lhs, const field_documentation &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.description == rhs.description;
    ret &= lhs.start_position == rhs.start_position;
    ret &= lhs.length == rhs.length;

    return ret;
}

