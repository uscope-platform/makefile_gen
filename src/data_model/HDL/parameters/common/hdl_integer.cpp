//  Copyright 2026 Filippo Savi
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


#include "data_model/HDL/parameters/common/hdl_integer.hpp"

void hdl_integer::set_size(const int64_t v) {
    size = v;
}

void hdl_integer::set_value(const uint64_t v) {
    value = v;
    wide = false;
}

void hdl_integer::set_value(const int1024_t v) {
    wide_value = v;
    wide = true;
}

uint64_t hdl_integer::get_size() {
    if (size > 0) return size;
    if (wide) {
        int1024_t tmp = wide_value;
        int bits = 0;
        while (tmp != 0) {
            tmp >>= 1;
            bits++;
        }
        if (bits == 0) bits = 1;
        return static_cast<uint64_t>(bits);
    }
    if(value == 0) return 1;
    auto n_bits = std::log2(value);
    if(std::isinf(n_bits)) {
        return 1;
    }
    if(n_bits == 0) {
        return 1;
    }
    return static_cast<uint64_t>(std::ceil(n_bits));
}

hdl_integer hdl_integer::operator+(const hdl_integer &o) const {
    hdl_integer res;
    if (o.wide && wide) {
        auto res_val = o.wide_value + wide_value;
        res.set_value(res_val);
    }else if (o.wide && !wide) {
        auto res_val = o.wide_value + int1024_t(value);
        res.set_value(res_val);
    }else if (!o.wide && wide) {
        auto res_val = int1024_t(o.value) + wide_value;
        res.set_value(res_val);
    }else if (!o.wide && !wide) {
        return o.value + value;
    }
    return res;
}

hdl_integer hdl_integer::operator-(const hdl_integer &o) const {
    if (wide || o.wide) {
        hdl_integer res;
        res.set_value(to_wide() - o.to_wide());
        return res;
    }
    return value - o.value;
}

hdl_integer hdl_integer::operator*(const hdl_integer &o) const {
    if (wide || o.wide) {
        hdl_integer res;
        res.set_value(to_wide() * o.to_wide());
        return res;
    }
    return value * o.value;
}

hdl_integer hdl_integer::operator/(const hdl_integer &o) const {
    if (o.value == 0 && !o.wide) return 0;
    if (wide || o.wide) {
        auto divisor = o.to_wide();
        if (divisor == 0) return 0;
        hdl_integer res;
        res.set_value(to_wide() / divisor);
        return res;
    }
    if (o.value == 0) return 0;
    return value / o.value;
}

hdl_integer hdl_integer::operator%(const hdl_integer &o) const {
    if (o.value == 0 && !o.wide) return 0;
    if (wide || o.wide) {
        auto divisor = o.to_wide();
        if (divisor == 0) return 0;
        hdl_integer res;
        res.set_value(to_wide() % divisor);
        return res;
    }
    if (o.value == 0) return 0;
    return value % o.value;
}

hdl_integer hdl_integer::operator&&(const hdl_integer &o) const {
    if (wide || o.wide) {
        return static_cast<int64_t>(to_wide() != 0 && o.to_wide() != 0);
    }
    return value && o.value;
}

hdl_integer hdl_integer::operator||(const hdl_integer &o) const {
    if (wide || o.wide) {
        return static_cast<int64_t>(to_wide() != 0 || o.to_wide() != 0);
    }
    return value || o.value;
}

hdl_integer hdl_integer::operator&(const hdl_integer &o) const {
    if (wide || o.wide) {
        hdl_integer res;
        res.set_value(to_wide() & o.to_wide());
        return res;
    }
    return value & o.value;
}

hdl_integer hdl_integer::operator|(const hdl_integer &o) const {
    if (wide || o.wide) {
        hdl_integer res;
        res.set_value(to_wide() | o.to_wide());
        return res;
    }
    return value | o.value;
}

hdl_integer hdl_integer::operator^(const hdl_integer &o) const {
    if (wide || o.wide) {
        hdl_integer res;
        res.set_value(to_wide() ^ o.to_wide());
        return res;
    }
    return value ^ o.value;
}

hdl_integer hdl_integer::operator~() const {
    if (wide) {
        hdl_integer res;
        res.set_value(-wide_value - 1);
        return res;
    }
    return ~value;
}

hdl_integer hdl_integer::operator!() const {
    if (wide) {
        return static_cast<int64_t>(wide_value == 0);
    }
    return !value;
}

hdl_integer hdl_integer::operator<<(const hdl_integer &o) const {
    int64_t shift = o.value;
    if (wide || shift >= 64) {
        hdl_integer res;
        res.set_value(to_wide() << static_cast<int>(shift));
        return res;
    }
    if (shift >= 64) return 0;
    return value << shift;
}

hdl_integer hdl_integer::operator>>(const hdl_integer &o) const {
    int64_t shift = o.value;
    if (wide || shift >= 64) {
        hdl_integer res;
        res.set_value(to_wide() >> static_cast<int>(shift));
        return res;
    }
    if (shift >= 64) return 0;
    return value >> shift;
}
