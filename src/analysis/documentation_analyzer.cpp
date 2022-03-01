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

#include <utility>


documentation_analyzer::documentation_analyzer(std::istream &s) {
    parse_documentation(s);
}

documentation_analyzer::documentation_analyzer(std::string &s) {

    std::istringstream istream(s);
    parse_documentation(istream);

}

void documentation_analyzer::parse_documentation(std::istream &stream) {
    antlr4::ANTLRInputStream antlr_istream(stream);
    mgp_sv::sv2017Lexer lexer(&antlr_istream);
    antlr4::CommonTokenStream documentation_stream(&lexer,mgp_sv::sv2017Lexer::DOCUMENTATION_CHANNEL);

    while(true){
        size_t current_tok = documentation_stream.LA(1);
        if(current_tok ==mgp_sv::sv2017::EOF) break;
        raw_documentation_comments.push_back(documentation_stream.LT(1)->getText());
        documentation_stream.consume();
    }
}


void documentation_analyzer::process_documentation(std::unordered_map<std::string, uint32_t> parameters) {
    parameters_dict = std::move(parameters);
    std::vector<nlohmann::json> documentation_comments;

    for(auto &str:raw_documentation_comments){
        std::regex comment_boundaries(R"((\/\*\*|\*\*\/))");
        std::string content = std::regex_replace(str, comment_boundaries, "");

        nlohmann::json obj;
        std::istringstream ss(content);
        ss >> obj;
        documentation_comments.push_back(obj);
    }

    for(auto &obj:documentation_comments){
        analyze_documentation_object(obj);
    }

}


std::vector<std::shared_ptr<bus_crossbar>> documentation_analyzer::get_bus_roots() {
    return bus_roots;
}

void documentation_analyzer::analyze_documentation_object(nlohmann::json &obj) {
    std::string type = obj["type"];
    if(type == "bus_hierarchy") {
        analyze_bus_hierarchy(obj);
    } else if(type == "peripheral") {
        analyze_peripheral(obj);
    }
}

void documentation_analyzer::analyze_bus_hierarchy(nlohmann::json &obj) {
    bus_crossbar root;
    root.set_parameter(obj["name"]);

    std::vector<nlohmann::json> children = obj["children"];

    for (auto &item:children) {
        std::string type = item["type"];
        if(type == "module"){
            root.add_child(analyze_module(item));
        } else if(type == "registers") {
            root.add_child(analyze_register(item));
        } else if(type == "crossbar") {
            root.add_child(analyze_crossbar(item));
        }
    }
    root.set_base_address(parameters_dict[obj["name"]]);
    bus_roots.push_back(std::make_shared<bus_crossbar>(root));
}


std::shared_ptr<bus_registers> documentation_analyzer::analyze_register(nlohmann::json &obj) {

    std::string target_module = obj["target"];
    std::string parameter_name =  obj["name"];
    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>(target_module, parameter_name);
    reg->set_base_address(parameters_dict[parameter_name]);
    return reg;
}

std::shared_ptr<bus_module> documentation_analyzer::analyze_module(nlohmann::json &obj) {

    std::string target_module = obj["target"]["type"];
    std::string target_instance = obj["target"]["name"];
    std::string parameter_name =  obj["name"];
    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>(target_instance, target_module, parameter_name);
    mod->set_base_address(parameters_dict[parameter_name]);
    return mod;
}

std::shared_ptr<bus_crossbar> documentation_analyzer::analyze_crossbar(nlohmann::json &obj) {

    std::string parameter_name = obj["name"];

    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>();
    xbar->set_parameter(parameter_name);

    std::vector<nlohmann::json> children = obj["children"];
    for (auto &item:children) {
        std::string type = item["type"];
        if(type == "module"){
            xbar->add_child(analyze_module(item));
        } else if(type == "registers") {
            xbar->add_child(analyze_register(item));
        } else if(type == "crossbar") {
            xbar->add_child(analyze_crossbar(item));
        }
    }

    xbar->set_base_address(parameters_dict[parameter_name]);
    return xbar;
}

void documentation_analyzer::analyze_peripheral(nlohmann::json &obj) {
    module_documentation mod_doc;
    std::string str_n = obj["name"];
    mod_doc.set_name(str_n);
    for(auto &item : obj["registers"]){
        std::string off =item["offset"];
        uint32_t offset = std::stoul(off, nullptr, 0);
        std::string dir = item["direction"];
        bool read_allowed = dir.find('R') != std::string::npos;
        bool write_allowed = dir.find('W') != std::string::npos;
        register_documentation reg_doc(item["name"], offset, item["description"], read_allowed, write_allowed);

        if(item.contains("fields")){
            for(auto &f_obj:item["fields"]){
                auto field_doc = analyze_register_field(f_obj);
                reg_doc.add_field(field_doc);
            }
        }
        mod_doc.add_register(reg_doc);
    }
    modules_doc[str_n] = mod_doc;
}

std::unordered_map<std::string, module_documentation> documentation_analyzer::get_modules_documentation() {
    return modules_doc;
}

field_documentation documentation_analyzer::analyze_register_field(nlohmann::json &obj) {
    std::string name = obj["name"];
    std::string desc = obj["description"];
    uint8_t start_pos = obj["start_position"];
    uint8_t length = obj["length"];
    field_documentation doc(name, desc, start_pos, length);
    return doc;
}




