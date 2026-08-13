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


#ifndef ANANKE_HDL_INTEGER_HPP
#define ANANKE_HDL_INTEGER_HPP

#include <cstdint>
#include <cmath>
#include <string>
#include <variant>
#include <nlohmann/json.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/string.hpp>

#include "third_party/uintwide_t.h"

using int1024_t = ::math::wide_integer::int1024_t;

namespace math {
    namespace wide_integer {
        inline void to_json(nlohmann::json& j, const int1024_t& val) {
            std::stringstream ss;
            // Check sign manually because stream formatting can vary by library version
            if (val < 0) {
                // Negate to print absolute value safely
                int1024_t abs_val = -val;
                ss << "-0x" << std::hex << abs_val;
            } else {
                ss << "0x" << std::hex << val;
            }
            j = ss.str();
        }

        inline void from_json(const nlohmann::json& j, int1024_t& val) {
            std::string s = j.get<std::string>();
            bool is_negative = false;

            if (s.rfind('-', 0) == 0) {
                is_negative = true;
                s = s.substr(1);
            }
            if (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0) {
                s = s.substr(2);
            }

            val = int1024_t(("0x" + s).c_str());
            if (is_negative) {
                val = -val;
            }
        }

        template <class Archive>
            void save(Archive& ar, const int1024_t& val) {
            std::stringstream ss;
            ss << std::hex << val;
            std::string s = ss.str();
            ar(s); // Save it safely as a string
        }

        template <class Archive>
        void load(Archive& ar, int1024_t& val) {
            std::string s;
            ar(s); // Load the string representation
            val = int1024_t(("0x" + s).c_str());
        }
    }
}

class hdl_integer {

public:
    hdl_integer() = default;

    hdl_integer(const hdl_integer &other) = default;
    hdl_integer(hdl_integer &&other) noexcept = default;
    hdl_integer & operator=(const hdl_integer &other) = default;
    hdl_integer & operator=(hdl_integer &&other) noexcept = default;

    hdl_integer(int64_t val) {
        content = val;
    }

    [[nodiscard]] int1024_t to_wide() const {
        if (std::holds_alternative<int1024_t>(content))
            return std::get<int1024_t>(content);
        return int1024_t(std::get<int64_t>(content));
    }
    [[nodiscard]] bool is_wide() const { return std::holds_alternative<int1024_t>(content); }

    void set_size(const int64_t s);
    void set_value(const uint64_t v);
    void set_value(const int1024_t v);
    void set_signed(const bool s) {signedness = s;}
    [[nodiscard]] int64_t get_value() const {
        if (std::holds_alternative<int1024_t>(content))
            return static_cast<int64_t>(std::get<int1024_t>(content));
        return std::get<int64_t>(content);
    }
    [[nodiscard]] int1024_t get_wide() const { return to_wide(); }

    uint64_t get_size();
    bool get_signed(){return signedness;}

    hdl_integer operator+(const hdl_integer &o) const;
    hdl_integer operator-(const hdl_integer &o) const;
    hdl_integer operator*(const hdl_integer &o) const;
    hdl_integer operator/(const hdl_integer &o) const;
    hdl_integer operator%(const hdl_integer &o) const;

    hdl_integer operator&&(const hdl_integer &o) const;
    hdl_integer operator||(const hdl_integer &o) const;
    hdl_integer operator&(const hdl_integer &o) const;
    hdl_integer operator|(const hdl_integer &o) const;
    hdl_integer operator^(const hdl_integer &o) const;
    hdl_integer operator~() const;
    hdl_integer operator!() const;

    hdl_integer operator<<(const hdl_integer &o) const;
    hdl_integer operator>>(const hdl_integer &o) const;

    hdl_integer& operator+=(const hdl_integer &rhs) {
        if (!is_wide() && !rhs.is_wide()) {
            content = get_value() + rhs.get_value();
        } else {
            content = to_wide() + rhs.to_wide();
        }
        return *this;
    }

    hdl_integer& operator|=(const hdl_integer &rhs) {
        if (!is_wide() && !rhs.is_wide()) {
            content = get_value() | rhs.get_value();
        } else {
            content = to_wide() | rhs.to_wide();
        }
        return *this;
    }

    std::string to_string() const {
        if (std::holds_alternative<int1024_t>(content)) {
            std::stringstream ss;
            ss << std::get<int1024_t>(content);
            return ss.str();
        }
        return std::to_string(std::get<int64_t>(content));
    }

    friend bool operator==(const hdl_integer &lhs, const hdl_integer &rhs) {
        return lhs.to_wide() == rhs.to_wide();
    }

    friend bool operator<(const hdl_integer &lhs, const hdl_integer &rhs) {
        return lhs.to_wide() < rhs.to_wide();
    }

    friend bool operator<=(const hdl_integer &lhs, const hdl_integer &rhs) {
        return !(rhs < lhs);
    }

    friend bool operator>(const hdl_integer &lhs, const hdl_integer &rhs) {
        return rhs < lhs;
    }

    friend bool operator>=(const hdl_integer &lhs, const hdl_integer &rhs) {
        return !(lhs < rhs);
    }

    template<class Archive>
    void serialize(Archive &ar) {
        ar(content, size, signedness);
    }

    friend void to_json(nlohmann::json& j, const hdl_integer& val) {
        j["value"] = val.get_value();
        j["size"] = val.size;
        j["signedness"] = val.signedness;
        j["wide_value"] = val.get_wide();
        j["wide"] = val.is_wide();
    }

    friend void from_json(const nlohmann::json& j, hdl_integer& val) {
        if (j.at("wide").get<bool>()) {
            val.content = j.at("wide_value").get<int1024_t>();
        } else {
            val.content = j.at("value").get<int64_t>();
        }
        val.size = j.at("size").get<uint64_t>();
        val.signedness = j.at("signedness").get<bool>();
    }

private:

    std::variant<int64_t, int1024_t> content;
    uint64_t size = 0;
    bool signedness = false;
};
namespace std {

    // Support for std::to_string(hdl_integer)
    inline std::string to_string(const hdl_integer& s) {
        return s.to_string();
    }

    // Support for std::abs(hdl_integer)
    inline hdl_integer abs(const hdl_integer& s) {
        auto w = s.to_wide();
        if (w < 0) {
            hdl_integer result;
            result.set_value(-w);
            return result;
        }
        return s;
    }
    inline hdl_integer pow(const hdl_integer &a, const hdl_integer &b) {
        double base = static_cast<double>(a.to_wide());
        double exp = static_cast<double>(b.to_wide());
        return static_cast<int64_t>(std::pow(base, exp));
    }
}


#endif //ANANKE_HDL_INTEGER_HPP
