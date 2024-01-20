//  Copyright 2024 Filippo Savi
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
#ifndef MAKEFILEGEN_V2_SCOPE_HPP
#define MAKEFILEGEN_V2_SCOPE_HPP

#include <cstdint>

struct scope_data {
    uint64_t buffer_address = 0;
    uint64_t enable_address = 0;
    uint64_t data_length_address = 0;
    uint64_t mux_address = 0;
};

#endif //MAKEFILEGEN_V2_SCOPE_HPP
