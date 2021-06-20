//
// Created by fils on 03/06/2021.
//

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
