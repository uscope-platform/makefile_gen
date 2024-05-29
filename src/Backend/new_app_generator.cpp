// Copyright 2021 University of Nottingham Ningbo China
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Backend/new_app_generator.hpp"

new_app_generator::new_app_generator(std::string &app_name, std::string &app_language) {
    name = app_name;
    lang = app_language;


    std::filesystem::create_directories(app_name + "/tb");
    std::filesystem::create_directories(app_name + "/rtl");
    write_depfile();
    write_synth_hdl();
    write_sim_hdl();
    write_constraints();

}

void new_app_generator::write_depfile() {

}

void new_app_generator::write_synth_hdl() {

}

void new_app_generator::write_sim_hdl() {

}


void new_app_generator::write_constraints() {

}

