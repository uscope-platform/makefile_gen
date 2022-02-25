// Copyright 2021 University of Nottingham Ningbo China
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

#ifndef MAKEFILEGEN_V2_SCRIPT_H
#define MAKEFILEGEN_V2_SCRIPT_H

#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "third_party/cereal/types/vector.hpp"
#include "third_party/cereal/types/string.hpp"

#define SCRIPT_TCL 0
#define SCRIPT_PYTHON 1
#define SCRIPT_UNINITIALIZED 2

enum script_type_t {tcl_script=SCRIPT_TCL, python_script=SCRIPT_PYTHON, uninit_script=SCRIPT_UNINITIALIZED};

///  Templated function used to convert a resource_type_t enum instance to the underlying integer for string conversion
/// \return integer feature code
template <typename script_type_t>
auto script_to_integer(script_type_t const value)
-> typename std::underlying_type<script_type_t>::type
{
    return static_cast<typename std::underlying_type<script_type_t>::type>(value);
}

class Script {
public:
    Script() = default;
    Script(const Script &S);
    Script(std::string n, const std::string& t);
    std::string get_name();
    script_type_t get_type();
    void set_product(bool gen, std::string t);
    [[nodiscard]] bool get_product_include() const;
    [[nodiscard]] std::string get_product_type() const;
    void set_arguments(std::vector<std::string> args);
    void set_path(std::string p);
    std::string get_path();
    std::vector<std::string> get_arguments();

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, path, type, product_type, product_include,arguments);
    }

    friend bool operator==(const Script&lhs, const Script&rhs);
private:
    std::string name;
    std::string path;
    script_type_t type;
    std::string product_type;
    bool product_include;
    std::vector<std::string> arguments;
};


#endif //MAKEFILEGEN_V2_SCRIPT_H
