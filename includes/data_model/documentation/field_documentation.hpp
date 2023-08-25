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

#ifndef MAKEFILEGEN_V2_FIELD_DOCUMENTATION_HPP
#define MAKEFILEGEN_V2_FIELD_DOCUMENTATION_HPP

#include <string>
#include <vector>

class field_documentation {
public:
    field_documentation();
    field_documentation(std::string n, std::string desc, uint8_t start, uint8_t len);

    std::string get_name() {return name;};
    std::string get_description() {return description;};
    uint8_t get_starting_position() const {return start_position;};
    uint8_t get_length() const {return length;};
    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, description, start_position, length, n_fields);
    }

    void set_n_fields(const std::vector<std::string> &v){n_fields = v;};
    std::vector<std::string> get_n_fields(){return n_fields;};

    friend bool operator==(const field_documentation&lhs, const field_documentation&rhs);
private:
    std::string name;
    std::string description;
    uint8_t start_position;
    uint8_t length;
    std::vector<std::string> n_fields;
};


#endif //MAKEFILEGEN_V2_FIELD_DOCUMENTATION_HPP
