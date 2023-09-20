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

#ifndef MAKEFILEGEN_V2_CHANNEL_HPP
#define MAKEFILEGEN_V2_CHANNEL_HPP

#include <string>


class channel {
public:
    channel() = default;
    channel(const channel &inst);


    void set_name(const std::string &s) {name = s;}
    std::string get_name() const{return name;};

    void set_enabled(const bool &d){enabled = d;};
    bool get_enabled() const {return enabled;};

    void set_phys_width(unsigned int pw){phys_width = pw;};
    unsigned int get_phys_width() const {return phys_width;};

    void set_mux_setting(unsigned int m){mux_setting = m;};
    unsigned int get_mux_setting() const {return mux_setting;};

    void set_channel_number(unsigned int cn){channel_number = cn;};
    unsigned int get_channel_number() const {return channel_number;};

    void set_signed(bool s){signed_data = s;};
    bool get_signed() const {return signed_data;};

    int get_min()const{return min;};
    int get_max()const{return max;};
    double get_scaling_factor()const{return scaling_factor;};


    friend bool operator==(const channel&lhs, const channel&rhs);
private:
    std::string name;
    bool enabled = false;
    unsigned int phys_width = 32;
    uint64_t mux_setting = 0;
    unsigned int channel_number = 0;
    bool signed_data = true;

    int min = 0;
    int max = 1000;
    double scaling_factor = 1.0;

};


#endif //MAKEFILEGEN_V2_CHANNEL_HPP
