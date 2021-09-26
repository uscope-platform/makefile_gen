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

#include "Backend/new_app_generator.h"

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
    std::string templates_dir = TEMPLATES_FOLDER;
    std::string template_file = templates_dir + "/Depfile.j2";
    inja::Template tpl = env.parse_template(template_file);


    data["app_name"] = name;
    std::string result = env.render(tpl, data);

    std::ofstream stream(name+"/Depfile");
    stream<<result;
}

void new_app_generator::write_synth_hdl() {
    std::string templates_dir = TEMPLATES_FOLDER;
    std::string template_file = templates_dir + "/top_synth_" + lang + ".j2";;

    inja::Template tpl = env.parse_template(template_file);

    data["top_module_name"] = name;
    std::string result = env.render(tpl, data);

    std::ofstream stream(name+"/rtl/"+name+"."+lang);
    stream<<result;
}

void new_app_generator::write_sim_hdl() {
    std::string templates_dir = TEMPLATES_FOLDER;
    std::string template_file = templates_dir + "/top_tb_" + lang + ".j2";;

    inja::Template tpl = env.parse_template(template_file);

    data["top_module_name"] = name+"_tb";
    std::string result = env.render(tpl, data);
    std::ofstream stream(name+"/tb/"+name+"_tb."+lang);
    stream<<result;
}


void new_app_generator::write_constraints() {
    std::ofstream ofs(name+"/"+name+".xdc");
    ofs.close();
}

