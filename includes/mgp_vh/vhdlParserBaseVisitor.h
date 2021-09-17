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

#pragma once


#include "antlr4-runtime.h"
#include "vhdlParserVisitor.h"


namespace mgp_vh {

/**
 * This class provides an empty implementation of vhdlParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  vhdlParserBaseVisitor : public vhdlParserVisitor {
public:

  virtual antlrcpp::Any visitAny_keyword(vhdlParser::Any_keywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName_literal(vhdlParser::Name_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName(vhdlParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName_slice_part(vhdlParser::Name_slice_partContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName_attribute_part(vhdlParser::Name_attribute_partContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_name(vhdlParser::Attribute_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSuffix(vhdlParser::SuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplicit_range(vhdlParser::Explicit_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelected_name(vhdlParser::Selected_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_declaration(vhdlParser::Entity_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_declarative_item(vhdlParser::Entity_declarative_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_statement(vhdlParser::Entity_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArchitecture_body(vhdlParser::Architecture_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_declarative_item(vhdlParser::Block_declarative_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfiguration_declaration(vhdlParser::Configuration_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfiguration_declarative_item(vhdlParser::Configuration_declarative_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_configuration(vhdlParser::Block_configurationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_specification(vhdlParser::Block_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_specification(vhdlParser::Generate_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfiguration_item(vhdlParser::Configuration_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_configuration(vhdlParser::Component_configurationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubprogram_declaration(vhdlParser::Subprogram_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubprogram_specification(vhdlParser::Subprogram_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedure_specification(vhdlParser::Procedure_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_specification(vhdlParser::Function_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubprogram_header(vhdlParser::Subprogram_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesignator(vhdlParser::DesignatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_symbol(vhdlParser::Operator_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormal_parameter_list(vhdlParser::Formal_parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubprogram_body(vhdlParser::Subprogram_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubprogram_kind(vhdlParser::Subprogram_kindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubprogram_instantiation_declaration(vhdlParser::Subprogram_instantiation_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignature(vhdlParser::SignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_declaration(vhdlParser::Package_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_declarative_item(vhdlParser::Package_declarative_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_body(vhdlParser::Package_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_instantiation_declaration(vhdlParser::Package_instantiation_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalar_type_definition(vhdlParser::Scalar_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange_constraint(vhdlParser::Range_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange(vhdlParser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDirection(vhdlParser::DirectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumeration_type_definition(vhdlParser::Enumeration_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumeration_literal(vhdlParser::Enumeration_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_type_definition(vhdlParser::Integer_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPhysical_type_definition(vhdlParser::Physical_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary_unit_declaration(vhdlParser::Primary_unit_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSecondary_unit_declaration(vhdlParser::Secondary_unit_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloating_type_definition(vhdlParser::Floating_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComposite_type_definition(vhdlParser::Composite_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_type_definition(vhdlParser::Array_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnbounded_array_definition(vhdlParser::Unbounded_array_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstrained_array_definition(vhdlParser::Constrained_array_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex_subtype_definition(vhdlParser::Index_subtype_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_constraint(vhdlParser::Array_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_element_constraint(vhdlParser::Array_element_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex_constraint(vhdlParser::Index_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiscrete_range(vhdlParser::Discrete_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecord_type_definition(vhdlParser::Record_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement_declaration(vhdlParser::Element_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_list(vhdlParser::Identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement_subtype_definition(vhdlParser::Element_subtype_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecord_constraint(vhdlParser::Record_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecord_element_constraint(vhdlParser::Record_element_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccess_type_definition(vhdlParser::Access_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIncomplete_type_declaration(vhdlParser::Incomplete_type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFile_type_definition(vhdlParser::File_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProtected_type_definition(vhdlParser::Protected_type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProtected_type_declaration(vhdlParser::Protected_type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProtected_type_declarative_item(vhdlParser::Protected_type_declarative_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProtected_type_body(vhdlParser::Protected_type_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_declaration(vhdlParser::Type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFull_type_declaration(vhdlParser::Full_type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_definition(vhdlParser::Type_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubtype_declaration(vhdlParser::Subtype_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubtype_indication(vhdlParser::Subtype_indicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResolution_indication(vhdlParser::Resolution_indicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement_resolution(vhdlParser::Element_resolutionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_element_resolution(vhdlParser::Array_element_resolutionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecord_resolution(vhdlParser::Record_resolutionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecord_element_resolution(vhdlParser::Record_element_resolutionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_mark(vhdlParser::Type_markContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint(vhdlParser::ConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement_constraint(vhdlParser::Element_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObject_declaration(vhdlParser::Object_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_declaration(vhdlParser::Constant_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignal_declaration(vhdlParser::Signal_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignal_kind(vhdlParser::Signal_kindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_declaration(vhdlParser::Variable_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFile_declaration(vhdlParser::File_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFile_open_information(vhdlParser::File_open_informationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFile_logical_name(vhdlParser::File_logical_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_declaration(vhdlParser::Interface_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_object_declaration(vhdlParser::Interface_object_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_constant_declaration(vhdlParser::Interface_constant_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_signal_declaration(vhdlParser::Interface_signal_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_variable_declaration(vhdlParser::Interface_variable_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_file_declaration(vhdlParser::Interface_file_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignal_mode(vhdlParser::Signal_modeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_type_declaration(vhdlParser::Interface_type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_incomplete_type_declaration(vhdlParser::Interface_incomplete_type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_subprogram_declaration(vhdlParser::Interface_subprogram_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_subprogram_specification(vhdlParser::Interface_subprogram_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_procedure_specification(vhdlParser::Interface_procedure_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_function_specification(vhdlParser::Interface_function_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_subprogram_default(vhdlParser::Interface_subprogram_defaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_package_declaration(vhdlParser::Interface_package_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_package_generic_map_aspect(vhdlParser::Interface_package_generic_map_aspectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_list(vhdlParser::Interface_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_element(vhdlParser::Interface_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneric_clause(vhdlParser::Generic_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneric_list(vhdlParser::Generic_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_clause(vhdlParser::Port_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_list(vhdlParser::Port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssociation_list(vhdlParser::Association_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssociation_element(vhdlParser::Association_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormal_part(vhdlParser::Formal_partContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitActual_part(vhdlParser::Actual_partContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitActual_designator(vhdlParser::Actual_designatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneric_map_aspect(vhdlParser::Generic_map_aspectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_map_aspect(vhdlParser::Port_map_aspectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_declaration(vhdlParser::Alias_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_designator(vhdlParser::Alias_designatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_declaration(vhdlParser::Attribute_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_declaration(vhdlParser::Component_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroup_template_declaration(vhdlParser::Group_template_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_class_entry_list(vhdlParser::Entity_class_entry_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_class_entry(vhdlParser::Entity_class_entryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroup_declaration(vhdlParser::Group_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroup_constituent_list(vhdlParser::Group_constituent_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroup_constituent(vhdlParser::Group_constituentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_specification(vhdlParser::Attribute_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_specification(vhdlParser::Entity_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_class(vhdlParser::Entity_classContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_name_list(vhdlParser::Entity_name_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_designator(vhdlParser::Entity_designatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_tag(vhdlParser::Entity_tagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfiguration_specification(vhdlParser::Configuration_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_configuration_specification(vhdlParser::Simple_configuration_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_configuration_specification(vhdlParser::Compound_configuration_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_specification(vhdlParser::Component_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstantiation_list(vhdlParser::Instantiation_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinding_indication(vhdlParser::Binding_indicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntity_aspect(vhdlParser::Entity_aspectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVerification_unit_binding_indication(vhdlParser::Verification_unit_binding_indicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVerification_unit_list(vhdlParser::Verification_unit_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDisconnection_specification(vhdlParser::Disconnection_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGuarded_signal_specification(vhdlParser::Guarded_signal_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignal_list(vhdlParser::Signal_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_designator(vhdlParser::Attribute_designatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternal_name(vhdlParser::External_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternal_pathname(vhdlParser::External_pathnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_pathname(vhdlParser::Package_pathnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAbsolute_pathname(vhdlParser::Absolute_pathnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelative_pathname(vhdlParser::Relative_pathnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartial_pathname(vhdlParser::Partial_pathnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPathname_element(vhdlParser::Pathname_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(vhdlParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_expression(vhdlParser::Simple_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary(vhdlParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogical_operator(vhdlParser::Logical_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational_operator(vhdlParser::Relational_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShift_operator(vhdlParser::Shift_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdding_operator(vhdlParser::Adding_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(vhdlParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplying_operator(vhdlParser::Multiplying_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMiscellaneous_operator(vhdlParser::Miscellaneous_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumeric_literal(vhdlParser::Numeric_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPhysical_literal(vhdlParser::Physical_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAggregate(vhdlParser::AggregateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement_association(vhdlParser::Element_associationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChoices(vhdlParser::ChoicesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChoice(vhdlParser::ChoiceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQualified_expression(vhdlParser::Qualified_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllocator(vhdlParser::AllocatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_of_statements(vhdlParser::Sequence_of_statementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequential_statement(vhdlParser::Sequential_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWait_statement(vhdlParser::Wait_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSensitivity_clause(vhdlParser::Sensitivity_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSensitivity_list(vhdlParser::Sensitivity_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_clause(vhdlParser::Condition_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(vhdlParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimeout_clause(vhdlParser::Timeout_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssertion_statement(vhdlParser::Assertion_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssertion(vhdlParser::AssertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReport_statement(vhdlParser::Report_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignal_assignment_statement(vhdlParser::Signal_assignment_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_signal_assignment(vhdlParser::Simple_signal_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_waveform_assignment(vhdlParser::Simple_waveform_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_force_assignment(vhdlParser::Simple_force_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_release_assignment(vhdlParser::Simple_release_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForce_mode(vhdlParser::Force_modeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay_mechanism(vhdlParser::Delay_mechanismContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTarget(vhdlParser::TargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWaveform(vhdlParser::WaveformContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWaveform_element(vhdlParser::Waveform_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_signal_assignment(vhdlParser::Conditional_signal_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_waveform_assignment(vhdlParser::Conditional_waveform_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_waveforms(vhdlParser::Conditional_waveformsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_force_assignment(vhdlParser::Conditional_force_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_expressions(vhdlParser::Conditional_expressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelected_signal_assignment(vhdlParser::Selected_signal_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelected_waveform_assignment(vhdlParser::Selected_waveform_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelected_waveforms(vhdlParser::Selected_waveformsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelected_force_assignment(vhdlParser::Selected_force_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelected_expressions(vhdlParser::Selected_expressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_assignment_statement(vhdlParser::Variable_assignment_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_variable_assignment(vhdlParser::Simple_variable_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_variable_assignment(vhdlParser::Conditional_variable_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelected_variable_assignment(vhdlParser::Selected_variable_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedure_call_statement(vhdlParser::Procedure_call_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedure_call(vhdlParser::Procedure_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_statement(vhdlParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_statement(vhdlParser::Case_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_statement_alternative(vhdlParser::Case_statement_alternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop_statement(vhdlParser::Loop_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIteration_scheme(vhdlParser::Iteration_schemeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_specification(vhdlParser::Parameter_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNext_statement(vhdlParser::Next_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExit_statement(vhdlParser::Exit_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_statement(vhdlParser::Return_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNull_statement(vhdlParser::Null_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_statement_with_optional_label(vhdlParser::Concurrent_statement_with_optional_labelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_statement(vhdlParser::Concurrent_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_statement(vhdlParser::Block_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_header(vhdlParser::Block_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcess_statement(vhdlParser::Process_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcess_sensitivity_list(vhdlParser::Process_sensitivity_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcess_or_package_declarative_item(vhdlParser::Process_or_package_declarative_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcess_declarative_item(vhdlParser::Process_declarative_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_procedure_call_statement(vhdlParser::Concurrent_procedure_call_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_assertion_statement(vhdlParser::Concurrent_assertion_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_signal_assignment_statement(vhdlParser::Concurrent_signal_assignment_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_signal_assignment_any(vhdlParser::Concurrent_signal_assignment_anyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_selected_signal_assignment(vhdlParser::Concurrent_selected_signal_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_instantiation_statement(vhdlParser::Component_instantiation_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstantiated_unit(vhdlParser::Instantiated_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_statement(vhdlParser::Generate_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_generate_statement(vhdlParser::For_generate_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_generate_statement(vhdlParser::If_generate_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_generate_statement(vhdlParser::Case_generate_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_generate_alternative(vhdlParser::Case_generate_alternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_statement_body_with_begin_end(vhdlParser::Generate_statement_body_with_begin_endContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_statement_body(vhdlParser::Generate_statement_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabel(vhdlParser::LabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUse_clause(vhdlParser::Use_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesign_file(vhdlParser::Design_fileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesign_unit(vhdlParser::Design_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibrary_unit(vhdlParser::Library_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary_unit(vhdlParser::Primary_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSecondary_unit(vhdlParser::Secondary_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibrary_clause(vhdlParser::Library_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogical_name_list(vhdlParser::Logical_name_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContext_declaration(vhdlParser::Context_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContext_clause(vhdlParser::Context_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContext_item(vhdlParser::Context_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContext_reference(vhdlParser::Context_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(vhdlParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace mgp_vh
