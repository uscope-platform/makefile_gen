//
// Created by fils on 02/06/2021.
//

#ifndef MAKEFILEGEN_V2_SCRIPT_H
#define MAKEFILEGEN_V2_SCRIPT_H

#include <string>
#include <vector>

#define SCRIPT_TCL 0
#define SCRIPT_PYTHON 1

enum script_type_t {tcl_script=SCRIPT_TCL, python_script=SCRIPT_PYTHON};

class Script {
public:
    Script(std::string n, const std::string& t, std::vector<std::string> args);
    std::string get_name();
    script_type_t get_type();
    std::vector<std::string> get_arguments();
private:
    std::string name;
    script_type_t type;
    std::vector<std::string> arguments;
};


#endif //MAKEFILEGEN_V2_SCRIPT_H
