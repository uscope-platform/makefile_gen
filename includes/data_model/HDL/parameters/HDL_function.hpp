//  Copyright 2025 Filippo Savi
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

#ifndef HDL_FUNCTION_HPP
#define HDL_FUNCTION_HPP
#include <string>
#include <vector>
#include <cstdint>

enum function_output_type {
    function_output_string,
    function_output_number,
    function_output_array
};

class HDL_function {
public:
    void set_name(const std::string &s) { name = s;}

private:
    std::string name;
    function_output_type type = function_output_number;
    std::vector<uint32_t> output_dimensions;
};



#endif //HDL_FUNCTION_HPP
