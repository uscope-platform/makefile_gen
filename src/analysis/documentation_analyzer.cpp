// Copyright 2021 Filippo Savi
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

#include "analysis/documentation_analyzer.h"




documentation_analyzer::documentation_analyzer(std::string &s, std::unordered_map<std::string, uint32_t> parameters) {

    parameters_dict = std::move(parameters);
    std::istringstream istream(s);


    antlr4::ANTLRInputStream antlr_istream(istream);
    mgp_sv::sv2017Lexer lexer(&antlr_istream);
    antlr4::CommonTokenStream documentation_stream(&lexer,mgp_sv::sv2017Lexer::DOCUMENTATION_CHANNEL);

    std::vector<std::string> raw_documentation_comments;


    while(true){
        size_t current_tok = documentation_stream.LA(1);
        if(current_tok ==mgp_sv::sv2017::EOF) break;
        raw_documentation_comments.push_back(documentation_stream.LT(1)->getText());
        documentation_stream.consume();
    }

    for(auto &str:raw_documentation_comments){
        std::regex comment_boundaries(R"((\/\*\*|\*\*\/))");
        std::string content = std::regex_replace(str, comment_boundaries, "");

        nlohmann::json obj;
        std::istringstream ss(content);
        ss >> obj;
        analyze_documentation_object(obj);
    }

    for(auto &item:bus_roots){
        construct_bus_hierarchy(item);
    }

}



std::vector<std::shared_ptr<bus_crossbar>> documentation_analyzer::get_bus_roots() {
    return bus_roots;
}

void documentation_analyzer::analyze_documentation_object(nlohmann::json &obj) {
    if(obj["type"] == "package_parameter") {
        if(obj["class"] == "module"){
            analyze_module(obj);
        } else if(obj["class"] == "registers") {
            analyze_register(obj);
        } else if( obj["class"] == "crossbar") {
            analyze_crossbar(obj, false);
        } else if( obj["class"] == "bus_root"){
            analyze_crossbar(obj, true);
        }
    } else if(obj["type"] == "peripheral") {

    }
}

void documentation_analyzer::analyze_register(nlohmann::json &obj) {

    std::string target_module = obj["target"];
    std::string parameter_name =  obj["name"];
    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>(target_module, parameter_name);
    reg->set_base_address(parameters_dict[parameter_name]);
    registers_dict[target_module] = reg;
}

void documentation_analyzer::analyze_module(nlohmann::json &obj) {

    std::string target_module = obj["target"]["module_type"];
    std::string target_instance = obj["target"]["instance_name"];
    std::string parameter_name =  obj["name"];
    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>(target_instance, target_module, parameter_name);
    mod->set_base_address(parameters_dict[parameter_name]);
    modules_dict[parameter_name] = mod;
}

void documentation_analyzer::analyze_crossbar(nlohmann::json &obj, bool is_root) {

    std::string parameter_name = obj["name"];
    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>(obj["children"], parameter_name);

    xbar->set_base_address(parameters_dict[parameter_name]);

    if(is_root){
        bus_roots.push_back(xbar);
    } else {
        crossbar_dict[parameter_name] = xbar;
    }

}

void documentation_analyzer::construct_bus_hierarchy(const std::shared_ptr<bus_crossbar>& dict) {
    std::vector<std::string> childs = dict->get_raw_children_list();
    if(childs.empty()) {
        return;
    }
    for(auto &item:childs){
        if(modules_dict.count(item)!= 0 ){
            dict->add_child(modules_dict[item]);
            modules_dict.erase(item);
        } else if(registers_dict.count(item) != 0){
            dict->add_child(registers_dict[item]);
            registers_dict.erase(item);
        } else if(crossbar_dict.count(item) != 0){
            construct_bus_hierarchy(crossbar_dict[item]);
            dict->add_child(crossbar_dict[item]);
            crossbar_dict.erase(item);
        }
    }
}
