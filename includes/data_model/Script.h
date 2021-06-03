//
// Created by fils on 02/06/2021.
//

#ifndef MAKEFILEGEN_V2_SCRIPT_H
#define MAKEFILEGEN_V2_SCRIPT_H

#include <string>
#include <vector>

#include "Resource_base.h"

#define SCRIPT_TCL 0
#define SCRIPT_PYTHON 1
#define SCRIPT_UNINITIALIZED 2

enum script_type_t {tcl_script=SCRIPT_TCL, python_script=SCRIPT_PYTHON, uninit_script=SCRIPT_UNINITIALIZED};

class Script : public Resource_base {
public:
    Script(std::string n, const std::string& t);
    std::string get_name();
    script_type_t get_type();
    void set_arguments(std::vector<std::string> args);
    void set_path(std::string p);
    std::vector<std::string> get_arguments();
private:
    std::string name;
    std::string path;
    script_type_t type;
    std::vector<std::string> arguments;
};


#endif //MAKEFILEGEN_V2_SCRIPT_H
