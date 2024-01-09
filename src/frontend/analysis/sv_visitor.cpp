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

#include "frontend/analysis/sv_visitor.hpp"

sv_visitor::sv_visitor(std::string p) {
    path = std::move(p);
}


void sv_visitor::enterModule_declaration(sv2017::Module_declarationContext *ctx) {
    current_declaration_type = "module";
    modules_factory.new_module(path, module);
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
    if(loops_factory.in_loop()){
        auto dep = deps_factory.get_dependency();
         loops_factory.add_instance(dep);
    } else {
        modules_factory.add_instance(deps_factory.get_dependency());
    }

}


void sv_visitor::exitInterface_header(sv2017::Interface_headerContext *ctx) {
    std::string interface_name = ctx->identifier()->getText();
    if(modules_factory.is_current_valid()){
        HDL_instance dep("__scoped_declaration__", interface_name, interface);
        modules_factory.add_interface_dep(dep);
    }

}

std::vector<HDL_Resource> sv_visitor::get_entities() {
    return entities;
}

void sv_visitor::enterPrimaryTfCall(sv2017::PrimaryTfCallContext *ctx) {
    if(params_factory.is_component_relevant()){
        std::string call_name = ctx->any_system_tf_identifier()->getText();
        params_factory.add_component(Expression_component(call_name));
        params_factory.add_component(Expression_component("("));
        if(ctx->data_type() != nullptr){
            if(!package_prefix.empty()){
                Expression_component ec(package_item);
                ec.set_package_prefix(package_prefix);
                params_factory.add_component(ec);
                package_prefix.clear();
                package_item.clear();
            } else{
                params_factory.add_component(Expression_component(ctx->data_type()->getText()));
            }

        }
    }
}
void sv_visitor::exitPrimaryTfCall(sv2017::PrimaryTfCallContext *ctx) {
    std::string call_name = ctx->any_system_tf_identifier()->getText();
    if(call_name=="$readmemh" || call_name=="$readmemb"){
        std::string data_file = ctx->list_of_arguments()->expression()[0]->getText();
        data_file = std::regex_replace(data_file, std::regex("\\\""), "");
        std::filesystem::path p = data_file;
        if(p.extension().string() == ".dat"|| p.extension().string() == ".mem"){
            HDL_instance dep("__init_file__", p.stem(), memory_init);
            modules_factory.add_mem_file_dep(dep);
        }
    }
    if(params_factory.is_component_relevant()) {
        params_factory.add_component(Expression_component(")"));
    }
}

void sv_visitor::enterPackage_declaration(sv2017::Package_declarationContext *ctx) {
    modules_factory.new_module(path, package);
}

void sv_visitor::exitPackage_declaration(sv2017::Package_declarationContext *ctx) {
    std::string package_name = ctx->identifier()[0]->getText();
    auto package = modules_factory.get_module();
    package.set_name(package_name);
    entities.push_back(package);
}

void sv_visitor::exitPackage_or_class_scoped_path(sv2017::Package_or_class_scoped_pathContext *ctx) {
    if(!ctx->DOUBLE_COLON().empty()){
        package_prefix = ctx->package_or_class_scoped_path_item()[0]->identifier()->getText();
        package_item = ctx->package_or_class_scoped_path_item()[1]->identifier()->getText();
        HDL_instance dep(package_item, package_prefix, package);
        modules_factory.add_package_dep(dep);
    }
}

void sv_visitor::enterParameter_declaration(sv2017::Parameter_declarationContext *ctx) {
    in_param_declaration = true;
    current_parameter = ctx->list_of_param_assignments()[0].param_assignment()[0]->identifier()->getText();
}

void sv_visitor::exitParameter_declaration(sv2017::Parameter_declarationContext *ctx) {
    in_param_declaration = false;
}

void sv_visitor::enterExpression(sv2017::ExpressionContext *ctx) {
    params_factory.start_expression_new();
    if(ctx->QUESTIONMARK() != nullptr){
        params_factory.start_ternary_operator();
    }
}

void sv_visitor::exitExpression(sv2017::ExpressionContext *ctx) {
    std::string type;
    if(ctx->QUESTIONMARK() != nullptr){
        type = "ternary";
    }
    params_factory.stop_expression_new();

}

void sv_visitor::exitPrimaryLit(sv2017::PrimaryLitContext *ctx) {
    if(params_factory.is_component_relevant()){
        params_factory.add_component(Expression_component(ctx->getText()));
    }
    if(deps_factory.is_valid_dependency()){
        deps_factory.add_port_connection_element(ctx->getText());
    }
}



void sv_visitor::exitPrimaryPath(sv2017::PrimaryPathContext *ctx) {
    auto p = ctx->getText();
    if(deps_factory.is_valid_dependency()){
        deps_factory.add_port_connection_element(p);
    }
    if(params_factory.is_component_relevant()){
        if(!package_prefix.empty()){
            Expression_component ec(package_item);
            ec.set_package_prefix(package_prefix);
            params_factory.add_component(ec);
            package_prefix.clear();
            package_item.clear();
        } else {
            params_factory.add_component(Expression_component(p));
        }

    }
}

void sv_visitor::exitOperator_plus_minus(sv2017::Operator_plus_minusContext *ctx) {
    if(params_factory.is_component_relevant()){
        params_factory.add_component(Expression_component(ctx->getText()));
    }
}

void sv_visitor::exitOperator_mul_div_mod(sv2017::Operator_mul_div_modContext *ctx) {
    if(params_factory.is_component_relevant()){
        params_factory.add_component(Expression_component(ctx->getText()));
    }
}


void sv_visitor::exitOperator_shift(sv2017::Operator_shiftContext *ctx) {
    if(params_factory.is_component_relevant()){
        params_factory.add_component(Expression_component(ctx->getText()));
    }
}

void sv_visitor::exitUnary_operator(sv2017::Unary_operatorContext *ctx) {
    if(ctx->PLUS() != nullptr || ctx->MINUS() != nullptr){
        if(params_factory.is_component_relevant()){
            params_factory.add_component(Expression_component(ctx->getText()));
        }
    }
}

void sv_visitor::exitOperator_cmp(sv2017::Operator_cmpContext *ctx) {
    if(params_factory.is_component_relevant()){
        params_factory.add_component(Expression_component(ctx->getText()));
    }
}

void sv_visitor::exitOperator_eq_neq(sv2017::Operator_eq_neqContext *ctx) {
    if(params_factory.is_component_relevant()){
        params_factory.add_component(Expression_component(ctx->getText()));
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

void sv_visitor::enterNamed_port_connection(sv2017::Named_port_connectionContext *ctx) {
    if(deps_factory.is_valid_dependency()){
        if(ctx->port_concatenation_connection() != nullptr){
            deps_factory.start_concat_port(ctx->identifier()->getText());
        }
    }
}

void sv_visitor::exitNamed_port_connection(sv2017::Named_port_connectionContext *ctx) {
    auto port_name = ctx->identifier()->getText();
    std::string connecting_item;
    if(ctx->port_expression_connection() != nullptr){
        connecting_item = ctx->port_expression_connection()->expression()->getText();
        if(deps_factory.is_valid_dependency()){
            deps_factory.add_port(port_name, connecting_item);
        }
    }
    if(ctx->port_concatenation_connection() != nullptr){
        if(deps_factory.is_valid_dependency()){
            deps_factory.stop_concat_port();
        }
    }
}

void sv_visitor::enterNamed_parameter_assignment(sv2017::Named_parameter_assignmentContext *ctx) {
    params_factory.start_instance_parameter_assignment(ctx->identifier()->getText());
}

void sv_visitor::exitNamed_parameter_assignment(sv2017::Named_parameter_assignmentContext *ctx) {
    auto param = params_factory.get_parameter();
    if(deps_factory.is_valid_dependency()){
        deps_factory.add_parameter(ctx->identifier()->getText(), param);
    }
}

void sv_visitor::enterParam_assignment(sv2017::Param_assignmentContext *ctx) {
    auto p_n = ctx->identifier()->getText();
    params_factory.start_param_assignment();
    params_factory.new_parameter();
    params_factory.set_parmeter_name(p_n);
}


void sv_visitor::exitParam_assignment(sv2017::Param_assignmentContext *ctx) {
    params_factory.stop_param_assignment();


    auto p_n = ctx->identifier()->getText();
    if(params_factory.in_packed_context()) {
        params_factory.stop_packed_assignment();
    }else if(ctx->replication_assignment() != nullptr){
        params_factory.start_packed_assignment();
        params_factory.stop_packed_assignment();
    } else {
        if(!package_prefix.empty()){
            Expression_component ec(package_item);
            ec.set_package_prefix(package_prefix);
            params_factory.add_component(ec);
            package_prefix.clear();
            package_item.clear();
        } else{
            auto val = ctx->constant_param_expression()->getText();
            params_factory.add_component(Expression_component(val));
        }
    }

    if(modules_factory.is_current_valid()){
        modules_factory.add_parameter(params_factory.get_parameter());
    } else if(interfaces_factory.is_current_valid()){
        interfaces_factory.add_parameter(params_factory.get_parameter());
    }

}


void sv_visitor::enterPrimaryPar(sv2017::PrimaryParContext *ctx) {
    params_factory.add_component(Expression_component("("));
}

void sv_visitor::exitPrimaryPar(sv2017::PrimaryParContext *ctx) {
    params_factory.add_component(Expression_component(")"));
}

void sv_visitor::enterAssignment_pattern(sv2017::Assignment_patternContext *ctx) {
    params_factory.start_initialization_list();

}

void sv_visitor::exitAssignment_pattern(sv2017::Assignment_patternContext *ctx) {
    bool default_assignment = false;
    if(!ctx->structure_pattern_key().empty()){
        if(ctx->structure_pattern_key()[0]->assignment_pattern_key() != nullptr){
            if(ctx->structure_pattern_key()[0]->assignment_pattern_key()->KW_DEFAULT() != nullptr){
                default_assignment = true;
            }
        }
    }

    params_factory.stop_initialization_list(default_assignment);
}

void sv_visitor::enterPrimaryBitSelect(sv2017::PrimaryBitSelectContext *ctx) {
    if(deps_factory.is_valid_dependency()){
        deps_factory.start_concat_partials_exclusion();
    }
}

void sv_visitor::exitPrimaryBitSelect(sv2017::PrimaryBitSelectContext *ctx) {
    params_factory.close_array_index();
    if(deps_factory.is_valid_dependency()){
        deps_factory.stop_concat_partials_exclusion();
        auto p = ctx->getText();
        deps_factory.add_port_connection_element(p);
    }
}

void sv_visitor::enterPrimaryIndex(sv2017::PrimaryIndexContext *ctx) {
    if(deps_factory.is_valid_dependency()){
        deps_factory.start_concat_partials_exclusion();
    }
}

void sv_visitor::exitPrimaryIndex(sv2017::PrimaryIndexContext *ctx) {
    if(deps_factory.is_valid_dependency()){
        deps_factory.stop_concat_partials_exclusion();
        auto p = ctx->getText();
        deps_factory.add_port_connection_element(p);
    }
}

void sv_visitor::enterPrimaryDot(sv2017::PrimaryDotContext *ctx) {
    if(deps_factory.is_valid_dependency()){
        deps_factory.start_concat_partials_exclusion();
    }
}

void sv_visitor::exitPrimaryDot(sv2017::PrimaryDotContext *ctx) {
    if(deps_factory.is_valid_dependency()){
        deps_factory.stop_concat_partials_exclusion();
        auto p = ctx->getText();
        deps_factory.add_port_connection_element(p);
    }
}

void sv_visitor::enterPrimaryRepl(sv2017::PrimaryReplContext *ctx) {
    if(deps_factory.is_valid_dependency()){
        deps_factory.start_concat_partials_exclusion();
    }
}

void sv_visitor::exitPrimaryRepl(sv2017::PrimaryReplContext *ctx) {
    if(deps_factory.is_valid_dependency()){
        deps_factory.stop_concat_partials_exclusion();
        auto p = ctx->getText();
        deps_factory.add_port_connection_element(p);
    }
}

void sv_visitor::enterConstant_param_expression(sv2017::Constant_param_expressionContext *ctx) {
    if(ctx->concatenation() != nullptr){
        params_factory.start_packed_assignment();
    }
}

void sv_visitor::enterBit_select(sv2017::Bit_selectContext *ctx) {
    params_factory.start_bit_selection();
}

void sv_visitor::exitBit_select(sv2017::Bit_selectContext *ctx) {
    params_factory.stop_bit_selection();
}

void sv_visitor::exitRange_expression(sv2017::Range_expressionContext *ctx) {
}

void sv_visitor::enterUnpacked_dimension(sv2017::Unpacked_dimensionContext *ctx) {
    params_factory.start_unpacked_dimension_declaration();
}

void sv_visitor::exitUnpacked_dimension(sv2017::Unpacked_dimensionContext *ctx) {
    params_factory.stop_unpacked_dimension_declaration();
}

void sv_visitor::exitFirst_range_identifier(sv2017::First_range_identifierContext *ctx) {
    params_factory.close_first_range();
}


void sv_visitor::enterReplication(sv2017::ReplicationContext *ctx) {
    params_factory.start_replication();
}



void sv_visitor::exitReplication_size(sv2017::Replication_sizeContext *ctx) {
    params_factory.close_replication_size();
}

void sv_visitor::exitReplication(sv2017::ReplicationContext *ctx) {
    params_factory.stop_replication();
}

void sv_visitor::enterReplication_assignment(sv2017::Replication_assignmentContext *ctx) {
    params_factory.start_replication_assignment();
}

void sv_visitor::exitReplication_assignment(sv2017::Replication_assignmentContext *ctx) {
    params_factory.stop_replication_assignment();
}

void sv_visitor::enterConcatenation(sv2017::ConcatenationContext *ctx) {
    params_factory.start_concatenation();
}

void sv_visitor::exitConcatenation(sv2017::ConcatenationContext *ctx) {
    params_factory.stop_concatenation();
}

void sv_visitor::enterData_type_or_implicit(sv2017::Data_type_or_implicitContext *ctx) {
    bool is_packed = false;
    if(ctx->implicit_data_type() != nullptr){
        if(!ctx->implicit_data_type()->packed_dimension().empty()){
            is_packed = true;
        }
    } else{
        if(!ctx->data_type()->variable_dimension().empty()){
            is_packed = true;
        }
    }
    if(is_packed & in_param_declaration){
        params_factory.start_packed_dimension();
    }

}

void sv_visitor::exitData_type_or_implicit(sv2017::Data_type_or_implicitContext *ctx) {
    if(in_param_declaration){
        params_factory.stop_packed_dimension();
    } else{
        params_factory.clear_expression();
    }
}

void sv_visitor::enterLoop_generate_construct(sv2017::Loop_generate_constructContext *) {
    loops_factory.new_loop();
}

void sv_visitor::exitLoop_generate_construct(sv2017::Loop_generate_constructContext *) {
    auto inst = loops_factory.get_instances();
    for(auto &i:loops_factory.get_instances()){
        modules_factory.add_instance(i);
    }
}

void sv_visitor::enterGenvar_initialization(sv2017::Genvar_initializationContext *ctx) {
    std::string id = ctx->identifier()->getText();
    params_factory.start_param_assignment();
    params_factory.new_parameter();
    params_factory.set_parmeter_name(id);
}

void sv_visitor::exitGenvar_initialization(sv2017::Genvar_initializationContext *ctx) {
    auto param = params_factory.get_parameter();
    params_factory.stop_param_assignment();
    loops_factory.set_identifier(*param);
}

void sv_visitor::enterGenvar_expression(sv2017::Genvar_expressionContext *ctx) {
    params_factory.start_param_assignment();
    params_factory.new_parameter();
    params_factory.set_parmeter_name("genvar_expr");
}

void sv_visitor::exitGenvar_expression(sv2017::Genvar_expressionContext *ctx) {
    auto param = params_factory.get_parameter();
    auto ex = param->get_expression_components();
    loops_factory.add_expression (ex);
}

void sv_visitor::enterGenvar_iteration(sv2017::Genvar_iterationContext *ctx) {
    sv2017BaseListener::enterGenvar_iteration(ctx);
}

void sv_visitor::exitGenvar_iteration(sv2017::Genvar_iterationContext *ctx) {
   if(ctx->inc_or_dec_operator() != nullptr) {

       Expression e;
       e.emplace_back(ctx->identifier()->getText());
       if(ctx->inc_or_dec_operator()->INCR() != nullptr){
           e.emplace_back("+");
       } else if(ctx->inc_or_dec_operator()->DECR() != nullptr){
           e.emplace_back("-");
       }
       e.emplace_back(1);
       loops_factory.add_expression(e);
   }
}






