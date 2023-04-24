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

#include "analysis/sv_visitor.hpp"

sv_visitor::sv_visitor(std::string p) {
    path = std::move(p);
}


void sv_visitor::enterModule_declaration(sv2017::Module_declarationContext *ctx) {
    current_declaration_type = "module";
    modules_factory.new_module(path);
}


void sv_visitor::exitModule_declaration(sv2017::Module_declarationContext *ctx) {
    entities.push_back(modules_factory.get_module());
}

void sv_visitor::enterInterface_declaration(sv2017::Interface_declarationContext *ctx) {
    current_declaration_type = "interface";
    interfaces_factory.new_interface(path);
}

void sv_visitor::exitInterface_declaration(sv2017::Interface_declarationContext *ctx) {
    std::string interface_name = ctx->interface_header()->identifier()->getText();
    interfaces_factory.set_interface_name(interface_name);
    entities.push_back(interfaces_factory.get_interface());
}

void sv_visitor::exitModule_header_common(sv2017::Module_header_commonContext *ctx) {
    std::string module_name = ctx->identifier()->getText();
    modules_factory.set_module_name(module_name);
}

void sv_visitor::enterModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) {
    std::string module_name = ctx->identifier()->getText();
    std::string instance_name = ctx->hierarchical_instance(0)->name_of_instance()->identifier()->getText();

    deps_factory.new_dependency(instance_name, module_name, module);
}


void sv_visitor::exitModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) {
    modules_factory.add_instance(deps_factory.get_dependency());
}


void sv_visitor::exitInterface_header(sv2017::Interface_headerContext *ctx) {
    std::string interface_name = ctx->identifier()->getText();
    if(modules_factory.is_current_valid()){
        HDL_dependency dep("__scoped_declaration__", interface_name, interface);
        modules_factory.add_interface_dep(dep);
    }

}

std::vector<HDL_Resource> sv_visitor::get_entities() {
    return entities;
}

void sv_visitor::exitPrimaryTfCall(sv2017::PrimaryTfCallContext *ctx) {
    std::string call_name = ctx->any_system_tf_identifier()->getText();
    if(call_name=="$readmemh" || call_name=="$readmemb"){
        std::string data_file = ctx->list_of_arguments()->expression()[0]->getText();
        data_file = std::regex_replace(data_file, std::regex("\\\""), "");
        std::filesystem::path p = data_file;
        if(p.extension().string() == ".dat"|| p.extension().string() == ".mem"){
            HDL_dependency dep("__init_file__", p.stem(), memory_init);
            modules_factory.add_mem_file_dep(dep);
        }
    }
}

void sv_visitor::enterPackage_declaration(sv2017::Package_declarationContext *ctx) {
    packages_factory.new_package(path);
}

void sv_visitor::exitPackage_declaration(sv2017::Package_declarationContext *ctx) {
    std::string package_name = ctx->identifier()[0]->getText();
    packages_factory.set_package_name(package_name);
    entities.push_back(packages_factory.get_package());
}

void sv_visitor::exitPackage_or_class_scoped_path(sv2017::Package_or_class_scoped_pathContext *ctx) {
    if(!ctx->DOUBLE_COLON().empty()){
        std::string package_name = ctx->package_or_class_scoped_path_item()[0]->identifier()->getText();
        std::string package_item = ctx->package_or_class_scoped_path_item()[1]->identifier()->getText();
        HDL_dependency dep(package_item, package_name, package);
        modules_factory.add_package_dep(dep);
    }

}

void sv_visitor::enterParameter_declaration(sv2017::Parameter_declarationContext *ctx) {
    std::string dbg = ctx->getText();
    current_parameter = ctx->list_of_param_assignments()[0].param_assignment()[0]->identifier()->getText();
}

void sv_visitor::exitParameter_declaration(sv2017::Parameter_declarationContext *ctx) {
    if(file_contains_bus_defining_package){
        if(string_components.size() == 1){
            try {
                uint32_t addr = std::stoul(string_components.front());
                packages_factory.add_numeric_parameter(current_parameter, addr);
            } catch (std::invalid_argument const& ex){
                if(packages_factory.numeric_parameter_exists(string_components.front())){
                    packages_factory.add_numeric_parameter(current_parameter, packages_factory.get_numeric_parameter(string_components.front()));
                } else{
                    expression par(current_parameter, string_components);
                    packages_factory.add_unresolved_parameter(par);
                }
            }
        } else{
            expression par(current_parameter, string_components);
            packages_factory.add_unresolved_parameter(par);
        }
        string_components.clear();
    }
}

void sv_visitor::exitExpression(sv2017::ExpressionContext *ctx) {
    if(file_contains_bus_defining_package){
        if(ctx->expression().size()>1){
            if(ctx->operator_plus_minus()== nullptr && ctx->operator_mul_div_mod()== nullptr){
                std::cerr<< "Warning: unsupported operation detected in parameter assignment expression" << std::endl;
            }
        }
    }

}

void sv_visitor::exitPrimaryLit(sv2017::PrimaryLitContext *ctx) {
    if(file_contains_bus_defining_package || in_module_array_def){
        uint32_t numeric_val = parse_number(ctx->getText());
        string_components.push_back(std::to_string(numeric_val));
    }

}

void sv_visitor::exitPrimaryPath(sv2017::PrimaryPathContext *ctx) {
    if(file_contains_bus_defining_package || in_module_array_def){
        std::string dbg = ctx->getText();
        string_components.push_back(ctx->getText());
    }
}

void sv_visitor::exitOperator_plus_minus(sv2017::Operator_plus_minusContext *ctx) {
    if(file_contains_bus_defining_package || in_module_array_def){
        string_components.push_back(ctx->getText());
    }
}

void sv_visitor::exitOperator_mul_div_mod(sv2017::Operator_mul_div_modContext *ctx) {
    if(file_contains_bus_defining_package || in_module_array_def){
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

void sv_visitor::exitAnsi_port_declaration(sv2017::Ansi_port_declarationContext *ctx) {
    if(current_declaration_type == "module"){
        std::string port_name = ctx->port_identifier()->getText();
        port_direction_t dir;
        if(ctx->port_direction() == nullptr){
            if(ctx->DOT()){
                dir = modport;
                std::string if_type = ctx->identifier(0)->getText();
                std::string modport_type = ctx->identifier(1)->getText();
                modules_factory.add_if_port_specs(port_name, if_type, modport_type);
            } else{
                dir = raw_port;
            }
        } else{
            std::string dir_s = ctx->port_direction()->getText();
            if(dir_s=="input")
                dir = input_port;
            else if(dir_s=="output")
                dir = output_port;
            else if(dir_s=="inout")
                dir = inout_port;
        }
        modules_factory.add_port(port_name, dir);
    }
}

void sv_visitor::exitNamed_port_connection(sv2017::Named_port_connectionContext *ctx) {
    auto port_name = ctx->identifier()->getText();
    std::string connecting_item;
    if(ctx->expression() != nullptr){
       connecting_item = ctx->expression()->getText();
    }
    if(deps_factory.is_valid_dependency()){
        deps_factory.add_port(port_name, connecting_item);
    }
}

void sv_visitor::exitNamed_parameter_assignment(sv2017::Named_parameter_assignmentContext *ctx) {
    auto param_name = ctx->identifier()->getText();
    auto param_value = ctx->param_expression()->getText();
    if(deps_factory.is_valid_dependency()){
        deps_factory.add_parameter(param_name, param_value);
    }
}

void sv_visitor::exitParam_assignment(sv2017::Param_assignmentContext *ctx) {
    auto p_n = ctx->identifier()->getText();
    auto val = ctx->constant_param_expression()->getText();
    auto vz = val[0];
    if ( val.front() == '"' ) {
        val.erase( 0, 1 ); // erase the first character
        val.erase( val.size() - 1 ); // erase the last character
        val = std::regex_replace(val, std::regex("\\\\"), "");
    }

    modules_factory.add_parameter(p_n, val);
}

void sv_visitor::enterName_of_instance(sv2017::Name_of_instanceContext *ctx) {
    if(!ctx->unpacked_dimension().empty()){
        in_module_array_def = true;
    }
}

void sv_visitor::exitName_of_instance(sv2017::Name_of_instanceContext *ctx) {
    if(in_module_array_def){
        expression q(ctx->identifier()->getText(), string_components);
        deps_factory.add_array_quantifier(q);
        string_components.clear();
    }
    in_module_array_def = false;
}


void sv_visitor::exitUnpacked_dimension(sv2017::Unpacked_dimensionContext *ctx) {

}




