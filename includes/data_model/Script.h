//
// Created by fils on 02/06/2021.
//

#ifndef MAKEFILEGEN_V2_SCRIPT_H
#define MAKEFILEGEN_V2_SCRIPT_H

#include <string>
#include <vector>
#include <sstream>
#include <utility>


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
    Script(std::string n, const std::string& t);
    explicit Script(const std::string& serialized_script);
    std::string get_name();
    script_type_t get_type();
    void set_include_products(bool gen);
    bool get_include_products() const;
    void set_arguments(std::vector<std::string> args);
    void set_path(std::string p);
    std::string get_path();
    std::vector<std::string> get_arguments();

    operator std::string();
    friend bool operator==(const Script&lhs, const Script&rhs);
private:
    std::string name;
    std::string path;
    script_type_t type;
    bool include_products;
    std::vector<std::string> arguments;
};


#endif //MAKEFILEGEN_V2_SCRIPT_H
