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

#ifndef MAKEFILEGEN_V2_PARAMETER_H
#define MAKEFILEGEN_V2_PARAMETER_H


#include <string>
#include <vector>
#include <stack>

class parameter {
public:
    parameter(std::string n, uint32_t a);
    parameter(std::string n, std::vector<std::string> e);
    [[nodiscard]] bool is_determined() const {return determined;};
    std::string get_name() {return name;};
    [[nodiscard]] uint32_t get_address() const {return address;};
    [[nodiscard]] std::vector<std::string> get_expression() const {return expression_components;};
    void set_address(uint32_t a);
    void update_expression(const std::string& n, uint32_t value);
private:
    std::string name;
    uint32_t address;
    bool determined;
    std::vector<std::string> expression_components;
};


#endif //MAKEFILEGEN_V2_PARAMETER_H
