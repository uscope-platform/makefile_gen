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

#include "analysis/sv_visitor.h"



sv_visitor::sv_visitor(std::string p) {
    path = std::move(p);
    file_declare_package = false;
}


void sv_visitor::enterModule_declaration(sv2017::Module_declarationContext *ctx) {
    nesting_level++;
    declarations_stack.push(declared_feature);
    dependencies_stack.push(instantiated_features);
    instantiated_features.clear();
}


void sv_visitor::exitModule_declaration(sv2017::Module_declarationContext *ctx) {

        std::shared_ptr<HDL_Resource> e = std::make_shared<HDL_Resource>(declared_feature.second, declared_feature.first, path, instantiated_features, verilog_entity);
        entities.push_back(e);
        if(!declarations_stack.empty()) {
            declared_feature = declarations_stack.top();
            declarations_stack.pop();
        }
        if(!dependencies_stack.empty()){
            instantiated_features = dependencies_stack.top();
            dependencies_stack.pop();
        } else{
            instantiated_features.clear();
        }

        nesting_level--;
}

void sv_visitor::exitInterface_declaration(sv2017::Interface_declarationContext *ctx) {
    std::string interface_name = ctx->interface_header()->identifier()->getText();
    hdl_deps_t dummy;
    std::shared_ptr<HDL_Resource> e = std::make_shared<HDL_Resource>(interface, interface_name, path, dummy, verilog_entity);
    entities.push_back(e);
}

void sv_visitor::exitModule_header_common(sv2017::Module_header_commonContext *ctx) {
    std::string module_name = ctx->identifier()->getText();
    declared_feature = std::make_pair(module_name, module);
}

void sv_visitor::exitModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) {
    std::string module_name = ctx->identifier()->getText();
    instantiated_features[module_name] = module;
}

void sv_visitor::exitInterface_header(sv2017::Interface_headerContext *ctx) {
    std::string interface_name = ctx->identifier()->getText();
    instantiated_features[interface_name] = interface;
}

std::vector<std::shared_ptr<HDL_Resource>> sv_visitor::get_entities() {
    return entities;
}

void sv_visitor::exitPrimaryTfCall(sv2017::PrimaryTfCallContext *ctx) {
    std::string call_name = ctx->any_system_tf_identifier()->getText();
    if(call_name=="$readmemh" || call_name=="$readmemb"){
        std::string data_file = ctx->list_of_arguments()->expression()[0]->getText();
        data_file = std::regex_replace(data_file, std::regex("\\\""), "");
        std::filesystem::path p = data_file;
        if(p.extension().string() == ".dat"|| p.extension().string() == ".mem"){
            instantiated_features[p.stem()] = memory_init;
        }

    }
}

void sv_visitor::enterPackage_declaration(sv2017::Package_declarationContext *ctx) {
    file_declare_package = true;
}

void sv_visitor::exitPackage_declaration(sv2017::Package_declarationContext *ctx) {
    std::string package_name = ctx->identifier()[0]->getText();
    calculate_package_parameters();
    std::shared_ptr<HDL_Resource> e = std::make_shared<HDL_Resource>(package, package_name, path, instantiated_features, verilog_entity);
    e->set_parameters(package_parameters);
    package_parameters.clear();
    entities.push_back(e);
}

void sv_visitor::exitPackage_or_class_scoped_path(sv2017::Package_or_class_scoped_pathContext *ctx) {
    if(!ctx->DOUBLE_COLON().empty()){
        std::string package_name = ctx->package_or_class_scoped_path_item()[0]->identifier()->getText();
        instantiated_features[package_name] = package;
    }

}

void sv_visitor::enterParameter_declaration(sv2017::Parameter_declarationContext *ctx) {
    std::string dbg = ctx->getText();
    current_parameter = ctx->list_of_param_assignments()[0].param_assignment()[0]->identifier()->getText();
}

void sv_visitor::exitParameter_declaration(sv2017::Parameter_declarationContext *ctx) {
    if(file_declare_package){
        if(string_components.size() == 1){
            try {
                uint32_t addr = std::stoul(string_components.front());
                numeric_parameters[current_parameter] = addr;
            } catch (std::invalid_argument const& ex){
                if(numeric_parameters.count(string_components.front())>0){
                    numeric_parameters[current_parameter] = numeric_parameters[string_components.front()];
                } else{
                    parameter par(current_parameter, string_components);
                    package_parameters.push_back(par);
                }
            }
        } else{
            parameter par(current_parameter, string_components);
            package_parameters.push_back(par);
        }
        string_components.clear();
    }

}

void sv_visitor::exitExpression(sv2017::ExpressionContext *ctx) {
    if(file_declare_package){
        if(ctx->expression().size()>1){
            if(ctx->operator_plus_minus()== nullptr && ctx->operator_mul_div_mod()== nullptr){
                std::cerr<< "Warning: unsupported operation detected in parameter assignment expression" << std::endl;
            }
        }
    }

}

void sv_visitor::exitPrimaryLit(sv2017::PrimaryLitContext *ctx) {
    if(file_declare_package){
        uint32_t numeric_val = parse_number(ctx->getText());
        string_components.push_back(std::to_string(numeric_val));
    }
}

void sv_visitor::exitPrimaryPath(sv2017::PrimaryPathContext *ctx) {
    if(file_declare_package){
        std::string dbg = ctx->getText();
        string_components.push_back(ctx->getText());
    }
}

void sv_visitor::exitOperator_plus_minus(sv2017::Operator_plus_minusContext *ctx) {
    if(file_declare_package){
        string_components.push_back(ctx->getText());
    }
}

void sv_visitor::exitOperator_mul_div_mod(sv2017::Operator_mul_div_modContext *ctx) {
    if(file_declare_package){
        string_components.push_back(ctx->getText());
    }
}

uint32_t sv_visitor::parse_number(const std::string& s) {
    std::regex hex_number(R"(\d*'h([0-9a-fA-F]*))");
    std::regex dec_number(R"(^(?:\d*'d)?([0-9]*)$)");
    std::regex oct_number(R"(^\d*'o([0-7]*)$)");
    std::regex bin_number(R"(\d*'b([0-1]*))");

    std::smatch sm;
    if(std::regex_match(s,sm, hex_number)){
        return std::stoul(sm[1],nullptr, 16);
    } else if(std::regex_match(s,sm, dec_number)){
        return std::stoul(sm[1],nullptr, 10);
    } else if(std::regex_match(s,sm, oct_number)){
        return std::stoul(sm[1],nullptr, 8);
    } else if(std::regex_match(s,sm, bin_number)){
        return std::stoul(sm[1],nullptr, 2);
    }
    return 0;
}


void sv_visitor::calculate_package_parameters() {
    std::vector<parameter> remaining_parameters;

    while(!package_parameters.empty()){
        remaining_parameters.clear();
        //update parameters with calculated values
        for(auto &np:numeric_parameters){
            for(auto &item:package_parameters){
                item.update_expression(np.first, np.second);
            }
        }

        // Calculate available expressions
        for(auto &item:package_parameters){
            try{
                std::string param_name = item.get_name();
                uint32_t res = calculate_expression(item.get_expression());
                numeric_parameters[param_name] = res;
            } catch(std::invalid_argument &ex){
                remaining_parameters.push_back(item);
            }
        }

        package_parameters = remaining_parameters;
    }

}

uint32_t sv_visitor::calculate_expression(std::vector<std::string> exp) {

    for (int i = 0; i< exp.size(); i++) {
        if(exp[i] == "*"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a*op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
            --i;
        } else if(exp[i] == "/"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a/op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
        } else if(exp[i]=="%"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a%op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
        }
    }


    for (int i = 0; i< exp.size(); i++) {
        if(exp[i] == "+"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a+op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
            --i;
        } else if(exp[i] == "-"){
            uint32_t op_a = std::stoul(exp[i-1]);
            uint32_t op_b = std::stoul(exp[i+1]);
            exp[i-1] = std::to_string(op_a-op_b);
            exp.erase(exp.begin()+i);
            exp.erase(exp.begin()+i);
        }
    }
    return std::stoul(exp[0]);
}