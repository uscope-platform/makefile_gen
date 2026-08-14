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


#include <charconv>
#include "data_model/HDL/parameters/components/token/Numeric_token.hpp"

#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>

CEREAL_REGISTER_TYPE(Numeric_token)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Expression_base, Numeric_token)

Numeric_token::Numeric_token(const Numeric_token &c) {
    value = c.value;
    container_size = c.container_size;
    binary_size = c.binary_size;
    sized_explicit = c.sized_explicit;
}

Numeric_token::Numeric_token(const std::string &s) {
    auto r = process_number(s);
    value = r.value;
    binary_size = r.binary_size;
    sized_explicit = r.sized_explicit;
}

Numeric_token::Numeric_token(std::variant<hdl_integer, double> n, int64_t b_s) {
    if(std::holds_alternative<double>(n)) {
        value = std::get<double>(n);
    } else {
        value = std::get<hdl_integer>(n);
    }
    binary_size = b_s;
    sized_explicit = b_s >= 0;
}

std::optional<resolved_parameter> Numeric_token::evaluate(
    const std::map<qualified_identifier, resolved_parameter> &context) {
    return value;
}

std::string Numeric_token::print() const {

    if (value.is_real())
        return  std::to_string(value.get_real());
    return std::to_string(value.get_integer());
}

int64_t Numeric_token::get_size() {
    return binary_size;
}

bool operator==(const Numeric_token &lhs, const Numeric_token &rhs) {
    bool ret_val = true;
    ret_val &= lhs.value == rhs.value;
    ret_val &= lhs.binary_size == rhs.binary_size;
    return ret_val;
}

std::optional<resolved_type> Numeric_token::resolve_expression_type(
    const std::map<qualified_identifier, resolved_parameter> &context) const {
    resolved_type result;
    if (value.is_real()) {
        result.is_real = true;
        return result;
    }
    uint64_t width = 32;
    if (sized_explicit && binary_size > 0) {
        width = static_cast<uint64_t>(binary_size);
    } else if (!sized_explicit) {
        auto int_val = value.get_integer();
        auto minimal = int_val.get_size();
        if (minimal > 32) width = minimal;
    }
    result.packed_sizes.push_back(width);
    result.packed_ascending.push_back(false);
    result.packed_left.push_back(static_cast<int64_t>(width) - 1);
    result.packed_right.push_back(0);
    return result;
}

void Numeric_token::set_container_sizes(const resolved_type &s,
    const std::map<qualified_identifier, resolved_parameter> &context) {
    container_size = 1;
    for (auto &ps : s.packed_sizes) container_size *= ps;
    for (auto &us : s.unpacked_sizes) container_size *= us;
}

Numeric_token::numeric_parse_result Numeric_token::process_number(const std::string_view &s) {
    numeric_parse_result result;
    result.binary_size = 0;
    result.sized_explicit = false;

    if (is_time_literal(s))
        return parse_time_literal(s);

    if (is_real_literal(s))
        return parse_real_literal(s);

    bool signed_number = false;
    bool negative_number = false;
    auto body = strip_sign(s, signed_number, negative_number);

    auto qualifiers = parse_qualifiers(body, signed_number);
    result.sized_explicit = qualifiers.sized_explicit;

    auto digits = purge_underscores(qualifiers.digits);

    auto [value, binary_size] = parse_integer_digits(digits, qualifiers.base, signed_number, qualifiers.explicit_size);
    if (negative_number) {
        auto int_val = value.get_integer();
        int1024_t negated = -int_val.to_wide();
        hdl_integer neg_val;
        neg_val.set_value(negated);
        neg_val.set_signed(int_val.get_signed());
        value = neg_val;
    }
    result.value = value;
    result.binary_size = binary_size;
    return result;
}

bool Numeric_token::is_time_literal(const std::string_view &s) {
    if (s.size() < 2) return false;
    static const std::string_view units[] = {"fs", "ps", "ns", "us", "ms", "s"};
    for (const auto &unit : units)
        if (s.ends_with(unit)) return true;
    return false;
}

Numeric_token::numeric_parse_result Numeric_token::parse_time_literal(const std::string_view &s) {
    numeric_parse_result result;
    result.binary_size = 64;
    result.sized_explicit = false;

    double scale = 1.0;
    size_t unit_size = 1;
    if (s.ends_with("fs")) { scale = 1e-15; unit_size = 2; }
    else if (s.ends_with("ps")) { scale = 1e-12; unit_size = 2; }
    else if (s.ends_with("ns")) { scale = 1e-9; unit_size = 2; }
    else if (s.ends_with("us")) { scale = 1e-6; unit_size = 2; }
    else if (s.ends_with("ms")) { scale = 1e-3; unit_size = 2; }

    auto number = s.substr(0, s.size() - unit_size);
    double value;
    std::from_chars(number.data(), number.data() + number.size(), value);
    result.value = value * scale;
    return result;
}

bool Numeric_token::is_real_literal(const std::string_view &s) {
    if (s.contains('\'')) return false;
    return s.contains('.') || s.find_first_of("eE") != std::string_view::npos;
}

Numeric_token::numeric_parse_result Numeric_token::parse_real_literal(const std::string_view &s) {
    numeric_parse_result result;
    result.binary_size = 64;
    result.sized_explicit = false;
    double value;
    std::from_chars(s.data(), s.data() + s.size(), value);
    result.value = value;
    return result;
}

std::string_view Numeric_token::strip_sign(const std::string_view &s, bool &is_signed, bool &is_negative) {
    if (s.starts_with("+") || s.starts_with("-")) {
        is_signed = true;
        is_negative = s.starts_with("-");
        return s.substr(1);
    }
    return s;
}

Numeric_token::literal_qualifiers Numeric_token::parse_qualifiers(const std::string_view &body, bool &is_signed) {
    literal_qualifiers qualifiers;
    qualifiers.explicit_size = -1;
    qualifiers.sized_explicit = false;

    std::string_view raw_value;
    if (body.contains('\'')) {
        raw_value = body.substr(body.find_first_of('\'') + 1);
        auto size_str = body.substr(0, body.find_first_of('\''));
        auto [ptr, ec] = std::from_chars(size_str.data(), size_str.data() + size_str.size(), qualifiers.explicit_size, 10);
        if (ec == std::errc() && ptr != size_str.data()) qualifiers.sized_explicit = true;
    } else {
        raw_value = body;
    }

    if (raw_value.starts_with('s')) {
        raw_value = raw_value.substr(1);
        is_signed = true;
    }

    qualifiers.base = detect_base(raw_value);
    qualifiers.digits = raw_value;
    return qualifiers;
}

int Numeric_token::detect_base(std::string_view &digits) {
    int base = 10;
    if (digits.starts_with("d")) {
        base = 10;
        digits = digits.substr(1);
    }
    if (digits.starts_with("b")) {
        base = 2;
        digits = digits.substr(1);
    }
    if (digits.starts_with("o")) {
        base = 8;
        digits = digits.substr(1);
    }
    if (digits.starts_with("h")) {
        base = 16;
        digits = digits.substr(1);
    }
    return base;
}

std::string Numeric_token::purge_underscores(const std::string_view &digits) {
    std::string purged_value(digits);
    std::erase(purged_value, '_');
    return purged_value;
}

std::pair<resolved_parameter, int64_t> Numeric_token::parse_integer_digits(const std::string &digits, int base,
    bool is_signed, int64_t explicit_size) {
    if (is_signed) {
        int64_t value;
        auto [ptr, ec] = std::from_chars(digits.data(), digits.data() + digits.size(), value, base);
        if (ec == std::errc::result_out_of_range)
            return process_wide_integer(digits, base, is_signed, explicit_size);
        if (ec != std::errc() || ptr != digits.data() + digits.size())
            return {0, 0};
        hdl_integer ret(value);
        return finalize_integer(ret, explicit_size, is_signed);
    } else {
        uint64_t value;
        auto [ptr, ec] = std::from_chars(digits.data(), digits.data() + digits.size(), value, base);
        if (ec == std::errc::result_out_of_range)
            return process_wide_integer(digits, base, is_signed, explicit_size);
        if (ec != std::errc() || ptr != digits.data() + digits.size())
            return {0, 0};
        hdl_integer ret;
        ret.set_value(value);
        return finalize_integer(ret, explicit_size, is_signed);
    }
}

std::pair<resolved_parameter, int64_t> Numeric_token::finalize_integer(hdl_integer int_val, int64_t explicit_size,
    bool is_signed) {
    int_val.set_signed(is_signed);
    if (explicit_size < 0) explicit_size = int_val.get_size();
    return {int_val, explicit_size};
}

std::pair<resolved_parameter, int64_t> Numeric_token::process_wide_integer(const std::string_view &raw_string, uint8_t base,
    bool signed_number, int64_t explicit_size) {
    hdl_integer res;

    std::string prefixed_string;
    switch (base) {
        case 16: prefixed_string = "0x" + std::string(raw_string); break;
        case 10: prefixed_string = std::string(raw_string); break;
        case 8: prefixed_string = '0' + std::string(raw_string); break;
        case 2: prefixed_string = "0b" + std::string(raw_string); break;

    }
    int1024_t wide_num(prefixed_string.c_str());

    res.set_value(wide_num);
    res.set_signed(signed_number);
    if (explicit_size < 0) explicit_size = res.get_size();
    return {res, explicit_size};
}

bool Numeric_token::isEqual(const Expression_base &other) const {
    const auto& rhs = static_cast<const Numeric_token&>(other);

    return std::tie( value, binary_size) == std::tie(rhs.value, rhs.binary_size);
}
