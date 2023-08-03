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

#ifndef MAKEFILEGEN_V2_SV_VISITOR_HPP
#define MAKEFILEGEN_V2_SV_VISITOR_HPP

#include "mgp_sv/sv2017BaseListener.h"
#include "mgp_sv/sv2017.h"

#include "data_model/HDL/HDL_parameters_factory.hpp"
#include "data_model/HDL/HDL_modules_factory.hpp"
#include "data_model/HDL/HDL_interfaces_factory.hpp"
#include "data_model/HDL/HDL_packages_factory.hpp"
#include "data_model/HDL/HDL_instances_factory.hpp"

#include "data_model/HDL/HDL_instance.hpp"
#include "data_model/HDL/HDL_Resource.hpp"

#include "data_model/expressions/bus_mapping_expression.hpp"

#include <regex>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <filesystem>
#include <nlohmann/json.hpp>

using namespace mgp_sv;

class sv_visitor : public sv2017BaseListener {

public:
    explicit sv_visitor(std::string p);
    void set_contains_bus_defining_package(bool b) { file_contains_bus_defining_package = b;};

    void enterModule_declaration(sv2017::Module_declarationContext *ctx) override;
    void exitModule_declaration(sv2017::Module_declarationContext *ctx) override;
    void enterInterface_declaration(sv2017::Interface_declarationContext *ctx) override;
    void exitInterface_declaration(sv2017::Interface_declarationContext *ctx) override;
    void exitModule_header_common(sv2017::Module_header_commonContext *ctx) override;
    void enterModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) override;
    void exitModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *ctx) override;
    void exitInterface_header(sv2017::Interface_headerContext *ctx) override;
    void enterPrimaryTfCall(sv2017::PrimaryTfCallContext *ctx) override;
    void exitPrimaryTfCall(sv2017::PrimaryTfCallContext *ctx) override;
    void enterPackage_declaration(sv2017::Package_declarationContext *ctx) override;
    void exitPackage_declaration(sv2017::Package_declarationContext *ctx) override;
    void exitPackage_or_class_scoped_path(sv2017::Package_or_class_scoped_pathContext *ctx) override;
    void enterParameter_declaration(sv2017::Parameter_declarationContext *ctx) override;
    void exitParameter_declaration(sv2017::Parameter_declarationContext *ctx) override;
    void enterParam_assignment(sv2017::Param_assignmentContext *ctx) override;
    void exitParam_assignment(sv2017::Param_assignmentContext *ctx) override;
    void exitAnsi_port_declaration(sv2017::Ansi_port_declarationContext *ctx) override;

    void exitExpression(sv2017::ExpressionContext *ctx) override;
    void exitOperator_mul_div_mod(sv2017::Operator_mul_div_modContext *ctx) override;
    void exitOperator_plus_minus(sv2017::Operator_plus_minusContext *ctx) override;
    void exitOperator_shift(sv2017::Operator_shiftContext *ctx) override;

    void exitPrimaryLit(sv2017::PrimaryLitContext *ctx) override;
    void exitPrimaryPath(sv2017::PrimaryPathContext *ctx) override;

    void exitNamed_port_connection(sv2017::Named_port_connectionContext *ctx) override;
    void exitNamed_parameter_assignment(sv2017::Named_parameter_assignmentContext *ctx) override;

    void enterName_of_instance(sv2017::Name_of_instanceContext *ctx) override;
    void exitName_of_instance(sv2017::Name_of_instanceContext *ctx) override;

    void enterPrimaryPar(sv2017::PrimaryParContext *ctx) override;
    void exitPrimaryPar(sv2017::PrimaryParContext *ctx) override;

    void enterAssignment_pattern(sv2017::Assignment_patternContext *ctx) override;
    void exitAssignment_pattern(sv2017::Assignment_patternContext *ctx) override;

    void exitPrimaryBitSelect(sv2017::PrimaryBitSelectContext *ctx) override;

    void enterBit_select(sv2017::Bit_selectContext *ctx) override;
    void exitBit_select(sv2017::Bit_selectContext *ctx) override;

    void exitRange_expression(sv2017::Range_expressionContext *ctx) override;

    void enterUnpacked_dimension(sv2017::Unpacked_dimensionContext *ctx) override;
    void exitUnpacked_dimension(sv2017::Unpacked_dimensionContext *ctx) override;


    void exitFirst_range_identifier(sv2017::First_range_identifierContext *ctx) override;

    void enterConstant_param_expression(sv2017::Constant_param_expressionContext *) override;

    void enterReplication(sv2017::ReplicationContext *ctx) override;
    void exitReplication(sv2017::ReplicationContext *ctx) override;


    static uint32_t parse_number(const std::string& s);
    std::vector<HDL_Resource> get_entities();

private:

    std::string path;
    std::vector<HDL_Resource> entities;

    std::string current_parameter;
    bool file_contains_bus_defining_package;
    std::vector<std::string> current_operands;
    std::vector<std::string> current_operators;
    std::string current_declaration_type;

    bool in_module_array_def = false;

    std::vector<std::string> string_components;

    HDL_modules_factory modules_factory;
    HDL_interfaces_factory interfaces_factory;
    HDL_packages_factory packages_factory;
    HDL_instances_factory deps_factory;
    HDL_parameters_factory params_factory;

    std::string package_prefix;
    std::string package_item;
};


#endif //MAKEFILEGEN_V2_SV_VISITOR_HPP
