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

#ifndef MAKEFILEGEN_V2_CONSTRAINTS_H
#define MAKEFILEGEN_V2_CONSTRAINTS_H

#include <string>
#include <vector>
#include <utility>
#include <sstream>


class Constraints {
public:
    explicit Constraints(std::string n);
    Constraints(const std::string& serialized_constraints, bool serialized);

    std::string get_name();
    void set_path(std::string p);
    std::string get_path();

    operator std::string();
    friend bool operator==(const Constraints&lhs, const Constraints&rhs);

private:
    std::string name;
    std::string path;
};



#endif //MAKEFILEGEN_V2_CONSTRAINTS_H
