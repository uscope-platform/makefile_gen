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

#ifndef MAKEFILEGEN_V2_REGISTER_DOCUMENTATION_HPP
#define MAKEFILEGEN_V2_REGISTER_DOCUMENTATION_HPP

#include <string>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/unordered_set.hpp>


#include "data_model/documentation/field_documentation.hpp"

class register_documentation {
public:
    register_documentation() = default;
    register_documentation(const std::string& n, uint32_t off, const std::string& desc, bool read, bool write);
    register_documentation(const std::string& n, const std::string& desc, bool read, bool write, const std::vector<std::string> &n_r);

    std::string get_name() const {return name;};
    uint32_t get_offset() const {return offset;};
    std::string get_description() const {return description;};
    bool get_read_allowed() const {return read_allowed;};
    bool get_write_allowed() const {return write_allowed;};

    bool is_parametric(){return parametric;};

    std::vector<std::string> get_n_regs() const{ return n_regs;};

    void set_variant(std::unordered_set<std::string> &v){variants = v;};
    std::unordered_set<std::string> get_variants() const { return variants;};

    void add_field(field_documentation &doc);
    std::vector<field_documentation> get_fields() const {return fields;};
    friend bool operator==(const register_documentation&lhs, const register_documentation&rhs);

    template<class Archive>
    void serialize(Archive & archive) {
        archive(name, offset, description, read_allowed, write_allowed, fields, parametric, n_regs, variants);
    }

private:
    std::string name;
    uint32_t offset;
    std::string description;
    bool read_allowed;
    bool write_allowed;
    std::vector<field_documentation> fields;
    bool parametric;
    std::vector<std::string> n_regs;

    std::unordered_set<std::string> variants;
};


#endif //MAKEFILEGEN_V2_REGISTER_DOCUMENTATION_HPP
