//  Copyright 2023 Filippo Savi
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

#include "data_model/documentation/channel.hpp"

channel::channel(const channel &c) {
    phys_width = c.phys_width;
    channel_number = c.channel_number;
    name = c.name;
    mux_setting = c.mux_setting;
    enabled = c.enabled;
    min = c.min;
    max = c.max;
    scaling_factor = c.scaling_factor;
    signed_data = c.signed_data;
}

bool operator==(const channel &lhs, const channel &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.channel_number == rhs.channel_number;
    ret &= lhs.phys_width == rhs.phys_width;
    ret &= lhs.mux_setting == rhs.mux_setting;
    ret &= lhs.enabled == rhs.enabled;
    ret &= lhs.min == rhs.min;
    ret &= lhs.max == rhs.max;
    ret &= lhs.scaling_factor == rhs.scaling_factor;
    ret &= lhs.signed_data == rhs.signed_data;

    return ret;
}
