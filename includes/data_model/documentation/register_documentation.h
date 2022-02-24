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

#ifndef MAKEFILEGEN_V2_REGISTER_DOCUMENTATION_H
#define MAKEFILEGEN_V2_REGISTER_DOCUMENTATION_H

#include <string>
#include "third_party/cereal/types/string.hpp"

class register_documentation {
public:
    register_documentation() = default;
    register_documentation(const std::string& n, uint32_t off, const std::string& desc, bool read, bool write);

    friend bool operator==(const register_documentation&lhs, const register_documentation&rhs);

    template<class Archive>
    void serialize(Archive & archive) {
        archive(name, offset, description, read_allowed, write_allowed);
    }

private:
    std::string name;
    uint32_t offset;
    std::string description;
    bool read_allowed;
    bool write_allowed;
};


#endif //MAKEFILEGEN_V2_REGISTER_DOCUMENTATION_H
