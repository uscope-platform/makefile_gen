//
// Created by fils on 30/05/2021.
//

#include "analysis/vhdl_visitor.h"

vhdl_visitor::vhdl_visitor(std::string p) {

}

std::vector<Resource> vhdl_visitor::get_entities() {
    return entities;
}
