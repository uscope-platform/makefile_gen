
// Generated from /home/fils/git/makefilegen_v2/grammars/sv2017.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "sv2017.h"


namespace mgp_sv {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by sv2017.
 */
class  sv2017Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by sv2017.
   */
    virtual antlrcpp::Any visitSource_text(sv2017::Source_textContext *context) = 0;

    virtual antlrcpp::Any visitDescription(sv2017::DescriptionContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_operator(sv2017::Assignment_operatorContext *context) = 0;

    virtual antlrcpp::Any visitEdge_identifier(sv2017::Edge_identifierContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(sv2017::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitInteger_type(sv2017::Integer_typeContext *context) = 0;

    virtual antlrcpp::Any visitInteger_atom_type(sv2017::Integer_atom_typeContext *context) = 0;

    virtual antlrcpp::Any visitInteger_vector_type(sv2017::Integer_vector_typeContext *context) = 0;

    virtual antlrcpp::Any visitNon_integer_type(sv2017::Non_integer_typeContext *context) = 0;

    virtual antlrcpp::Any visitNet_type(sv2017::Net_typeContext *context) = 0;

    virtual antlrcpp::Any visitUnary_module_path_operator(sv2017::Unary_module_path_operatorContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(sv2017::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitInc_or_dec_operator(sv2017::Inc_or_dec_operatorContext *context) = 0;

    virtual antlrcpp::Any visitImplicit_class_handle(sv2017::Implicit_class_handleContext *context) = 0;

    virtual antlrcpp::Any visitIntegral_number(sv2017::Integral_numberContext *context) = 0;

    virtual antlrcpp::Any visitReal_number(sv2017::Real_numberContext *context) = 0;

    virtual antlrcpp::Any visitAny_system_tf_identifier(sv2017::Any_system_tf_identifierContext *context) = 0;

    virtual antlrcpp::Any visitSigning(sv2017::SigningContext *context) = 0;

    virtual antlrcpp::Any visitNumber(sv2017::NumberContext *context) = 0;

    virtual antlrcpp::Any visitTimeunits_declaration(sv2017::Timeunits_declarationContext *context) = 0;

    virtual antlrcpp::Any visitLifetime(sv2017::LifetimeContext *context) = 0;

    virtual antlrcpp::Any visitPort_direction(sv2017::Port_directionContext *context) = 0;

    virtual antlrcpp::Any visitAlways_keyword(sv2017::Always_keywordContext *context) = 0;

    virtual antlrcpp::Any visitJoin_keyword(sv2017::Join_keywordContext *context) = 0;

    virtual antlrcpp::Any visitUnique_priority(sv2017::Unique_priorityContext *context) = 0;

    virtual antlrcpp::Any visitDrive_strength(sv2017::Drive_strengthContext *context) = 0;

    virtual antlrcpp::Any visitStrength0(sv2017::Strength0Context *context) = 0;

    virtual antlrcpp::Any visitStrength1(sv2017::Strength1Context *context) = 0;

    virtual antlrcpp::Any visitCharge_strength(sv2017::Charge_strengthContext *context) = 0;

    virtual antlrcpp::Any visitSequence_lvar_port_direction(sv2017::Sequence_lvar_port_directionContext *context) = 0;

    virtual antlrcpp::Any visitBins_keyword(sv2017::Bins_keywordContext *context) = 0;

    virtual antlrcpp::Any visitClass_item_qualifier(sv2017::Class_item_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitRandom_qualifier(sv2017::Random_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitProperty_qualifier(sv2017::Property_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitMethod_qualifier(sv2017::Method_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_prototype_qualifier(sv2017::Constraint_prototype_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitCmos_switchtype(sv2017::Cmos_switchtypeContext *context) = 0;

    virtual antlrcpp::Any visitEnable_gatetype(sv2017::Enable_gatetypeContext *context) = 0;

    virtual antlrcpp::Any visitMos_switchtype(sv2017::Mos_switchtypeContext *context) = 0;

    virtual antlrcpp::Any visitN_input_gatetype(sv2017::N_input_gatetypeContext *context) = 0;

    virtual antlrcpp::Any visitN_output_gatetype(sv2017::N_output_gatetypeContext *context) = 0;

    virtual antlrcpp::Any visitPass_en_switchtype(sv2017::Pass_en_switchtypeContext *context) = 0;

    virtual antlrcpp::Any visitPass_switchtype(sv2017::Pass_switchtypeContext *context) = 0;

    virtual antlrcpp::Any visitAny_implication(sv2017::Any_implicationContext *context) = 0;

    virtual antlrcpp::Any visitTiming_check_event_control(sv2017::Timing_check_event_controlContext *context) = 0;

    virtual antlrcpp::Any visitImport_export(sv2017::Import_exportContext *context) = 0;

    virtual antlrcpp::Any visitArray_method_name(sv2017::Array_method_nameContext *context) = 0;

    virtual antlrcpp::Any visitOperator_mul_div_mod(sv2017::Operator_mul_div_modContext *context) = 0;

    virtual antlrcpp::Any visitOperator_plus_minus(sv2017::Operator_plus_minusContext *context) = 0;

    virtual antlrcpp::Any visitOperator_shift(sv2017::Operator_shiftContext *context) = 0;

    virtual antlrcpp::Any visitOperator_cmp(sv2017::Operator_cmpContext *context) = 0;

    virtual antlrcpp::Any visitOperator_eq_neq(sv2017::Operator_eq_neqContext *context) = 0;

    virtual antlrcpp::Any visitOperator_xor(sv2017::Operator_xorContext *context) = 0;

    virtual antlrcpp::Any visitOperator_impl(sv2017::Operator_implContext *context) = 0;

    virtual antlrcpp::Any visitUdp_nonansi_declaration(sv2017::Udp_nonansi_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_ansi_declaration(sv2017::Udp_ansi_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_declaration(sv2017::Udp_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_declaration_port_list(sv2017::Udp_declaration_port_listContext *context) = 0;

    virtual antlrcpp::Any visitUdp_port_declaration(sv2017::Udp_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_output_declaration(sv2017::Udp_output_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_input_declaration(sv2017::Udp_input_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_reg_declaration(sv2017::Udp_reg_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_body(sv2017::Udp_bodyContext *context) = 0;

    virtual antlrcpp::Any visitCombinational_body(sv2017::Combinational_bodyContext *context) = 0;

    virtual antlrcpp::Any visitCombinational_entry(sv2017::Combinational_entryContext *context) = 0;

    virtual antlrcpp::Any visitSequential_body(sv2017::Sequential_bodyContext *context) = 0;

    virtual antlrcpp::Any visitUdp_initial_statement(sv2017::Udp_initial_statementContext *context) = 0;

    virtual antlrcpp::Any visitSequential_entry(sv2017::Sequential_entryContext *context) = 0;

    virtual antlrcpp::Any visitSeq_input_list(sv2017::Seq_input_listContext *context) = 0;

    virtual antlrcpp::Any visitLevel_input_list(sv2017::Level_input_listContext *context) = 0;

    virtual antlrcpp::Any visitEdge_input_list(sv2017::Edge_input_listContext *context) = 0;

    virtual antlrcpp::Any visitEdge_indicator(sv2017::Edge_indicatorContext *context) = 0;

    virtual antlrcpp::Any visitCurrent_state(sv2017::Current_stateContext *context) = 0;

    virtual antlrcpp::Any visitNext_state(sv2017::Next_stateContext *context) = 0;

    virtual antlrcpp::Any visitInterface_declaration(sv2017::Interface_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_header(sv2017::Interface_headerContext *context) = 0;

    virtual antlrcpp::Any visitInterface_item(sv2017::Interface_itemContext *context) = 0;

    virtual antlrcpp::Any visitModport_declaration(sv2017::Modport_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_item(sv2017::Modport_itemContext *context) = 0;

    virtual antlrcpp::Any visitModport_ports_declaration(sv2017::Modport_ports_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_clocking_declaration(sv2017::Modport_clocking_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_simple_ports_declaration(sv2017::Modport_simple_ports_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_simple_port(sv2017::Modport_simple_portContext *context) = 0;

    virtual antlrcpp::Any visitModport_tf_ports_declaration(sv2017::Modport_tf_ports_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_tf_port(sv2017::Modport_tf_portContext *context) = 0;

    virtual antlrcpp::Any visitStatement_or_null(sv2017::Statement_or_nullContext *context) = 0;

    virtual antlrcpp::Any visitInitial_construct(sv2017::Initial_constructContext *context) = 0;

    virtual antlrcpp::Any visitDefault_clocking_or_dissable_construct(sv2017::Default_clocking_or_dissable_constructContext *context) = 0;

    virtual antlrcpp::Any visitStatement(sv2017::StatementContext *context) = 0;

    virtual antlrcpp::Any visitStatement_item(sv2017::Statement_itemContext *context) = 0;

    virtual antlrcpp::Any visitCycle_delay(sv2017::Cycle_delayContext *context) = 0;

    virtual antlrcpp::Any visitClocking_drive(sv2017::Clocking_driveContext *context) = 0;

    virtual antlrcpp::Any visitClockvar_expression(sv2017::Clockvar_expressionContext *context) = 0;

    virtual antlrcpp::Any visitFinal_construct(sv2017::Final_constructContext *context) = 0;

    virtual antlrcpp::Any visitBlocking_assignment(sv2017::Blocking_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_timing_control_statement(sv2017::Procedural_timing_control_statementContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_timing_control(sv2017::Procedural_timing_controlContext *context) = 0;

    virtual antlrcpp::Any visitEvent_control(sv2017::Event_controlContext *context) = 0;

    virtual antlrcpp::Any visitDelay_or_event_control(sv2017::Delay_or_event_controlContext *context) = 0;

    virtual antlrcpp::Any visitDelay3(sv2017::Delay3Context *context) = 0;

    virtual antlrcpp::Any visitDelay2(sv2017::Delay2Context *context) = 0;

    virtual antlrcpp::Any visitDelay_value(sv2017::Delay_valueContext *context) = 0;

    virtual antlrcpp::Any visitDelay_control(sv2017::Delay_controlContext *context) = 0;

    virtual antlrcpp::Any visitNonblocking_assignment(sv2017::Nonblocking_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_continuous_assignment(sv2017::Procedural_continuous_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitVariable_assignment(sv2017::Variable_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitAction_block(sv2017::Action_blockContext *context) = 0;

    virtual antlrcpp::Any visitSeq_block(sv2017::Seq_blockContext *context) = 0;

    virtual antlrcpp::Any visitPar_block(sv2017::Par_blockContext *context) = 0;

    virtual antlrcpp::Any visitCase_statement(sv2017::Case_statementContext *context) = 0;

    virtual antlrcpp::Any visitCase_keyword(sv2017::Case_keywordContext *context) = 0;

    virtual antlrcpp::Any visitCase_item(sv2017::Case_itemContext *context) = 0;

    virtual antlrcpp::Any visitCase_pattern_item(sv2017::Case_pattern_itemContext *context) = 0;

    virtual antlrcpp::Any visitCase_inside_item(sv2017::Case_inside_itemContext *context) = 0;

    virtual antlrcpp::Any visitRandcase_statement(sv2017::Randcase_statementContext *context) = 0;

    virtual antlrcpp::Any visitRandcase_item(sv2017::Randcase_itemContext *context) = 0;

    virtual antlrcpp::Any visitCond_predicate(sv2017::Cond_predicateContext *context) = 0;

    virtual antlrcpp::Any visitConditional_statement(sv2017::Conditional_statementContext *context) = 0;

    virtual antlrcpp::Any visitSubroutine_call_statement(sv2017::Subroutine_call_statementContext *context) = 0;

    virtual antlrcpp::Any visitDisable_statement(sv2017::Disable_statementContext *context) = 0;

    virtual antlrcpp::Any visitEvent_trigger(sv2017::Event_triggerContext *context) = 0;

    virtual antlrcpp::Any visitLoop_statement(sv2017::Loop_statementContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_assignments(sv2017::List_of_variable_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitFor_initialization(sv2017::For_initializationContext *context) = 0;

    virtual antlrcpp::Any visitFor_variable_declaration_var_assign(sv2017::For_variable_declaration_var_assignContext *context) = 0;

    virtual antlrcpp::Any visitFor_variable_declaration(sv2017::For_variable_declarationContext *context) = 0;

    virtual antlrcpp::Any visitFor_step(sv2017::For_stepContext *context) = 0;

    virtual antlrcpp::Any visitLoop_variables(sv2017::Loop_variablesContext *context) = 0;

    virtual antlrcpp::Any visitJump_statement(sv2017::Jump_statementContext *context) = 0;

    virtual antlrcpp::Any visitWait_statement(sv2017::Wait_statementContext *context) = 0;

    virtual antlrcpp::Any visitName_of_instance(sv2017::Name_of_instanceContext *context) = 0;

    virtual antlrcpp::Any visitChecker_instantiation(sv2017::Checker_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitList_of_checker_port_connections(sv2017::List_of_checker_port_connectionsContext *context) = 0;

    virtual antlrcpp::Any visitOrdered_checker_port_connection(sv2017::Ordered_checker_port_connectionContext *context) = 0;

    virtual antlrcpp::Any visitNamed_checker_port_connection(sv2017::Named_checker_port_connectionContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_assertion_statement(sv2017::Procedural_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitConcurrent_assertion_statement(sv2017::Concurrent_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitAssertion_item(sv2017::Assertion_itemContext *context) = 0;

    virtual antlrcpp::Any visitConcurrent_assertion_item(sv2017::Concurrent_assertion_itemContext *context) = 0;

    virtual antlrcpp::Any visitImmediate_assertion_statement(sv2017::Immediate_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimple_immediate_assertion_statement(sv2017::Simple_immediate_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimple_immediate_assert_statement(sv2017::Simple_immediate_assert_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimple_immediate_assume_statement(sv2017::Simple_immediate_assume_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimple_immediate_cover_statement(sv2017::Simple_immediate_cover_statementContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_assertion_statement(sv2017::Deferred_immediate_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitPrimitive_delay(sv2017::Primitive_delayContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_assert_statement(sv2017::Deferred_immediate_assert_statementContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_assume_statement(sv2017::Deferred_immediate_assume_statementContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_cover_statement(sv2017::Deferred_immediate_cover_statementContext *context) = 0;

    virtual antlrcpp::Any visitWeight_specification(sv2017::Weight_specificationContext *context) = 0;

    virtual antlrcpp::Any visitProduction_item(sv2017::Production_itemContext *context) = 0;

    virtual antlrcpp::Any visitRs_code_block(sv2017::Rs_code_blockContext *context) = 0;

    virtual antlrcpp::Any visitRandsequence_statement(sv2017::Randsequence_statementContext *context) = 0;

    virtual antlrcpp::Any visitRs_prod(sv2017::Rs_prodContext *context) = 0;

    virtual antlrcpp::Any visitRs_if_else(sv2017::Rs_if_elseContext *context) = 0;

    virtual antlrcpp::Any visitRs_repeat(sv2017::Rs_repeatContext *context) = 0;

    virtual antlrcpp::Any visitRs_case(sv2017::Rs_caseContext *context) = 0;

    virtual antlrcpp::Any visitRs_case_item(sv2017::Rs_case_itemContext *context) = 0;

    virtual antlrcpp::Any visitRs_rule(sv2017::Rs_ruleContext *context) = 0;

    virtual antlrcpp::Any visitRs_production_list(sv2017::Rs_production_listContext *context) = 0;

    virtual antlrcpp::Any visitProduction(sv2017::ProductionContext *context) = 0;

    virtual antlrcpp::Any visitTf_item_declaration(sv2017::Tf_item_declarationContext *context) = 0;

    virtual antlrcpp::Any visitTf_port_list(sv2017::Tf_port_listContext *context) = 0;

    virtual antlrcpp::Any visitTf_port_item(sv2017::Tf_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitTf_port_direction(sv2017::Tf_port_directionContext *context) = 0;

    virtual antlrcpp::Any visitTf_port_declaration(sv2017::Tf_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitList_of_tf_variable_identifiers_item(sv2017::List_of_tf_variable_identifiers_itemContext *context) = 0;

    virtual antlrcpp::Any visitList_of_tf_variable_identifiers(sv2017::List_of_tf_variable_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitExpect_property_statement(sv2017::Expect_property_statementContext *context) = 0;

    virtual antlrcpp::Any visitBlock_item_declaration(sv2017::Block_item_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParam_assignment(sv2017::Param_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitType_assignment(sv2017::Type_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitList_of_type_assignments(sv2017::List_of_type_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_param_assignments(sv2017::List_of_param_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitLocal_parameter_declaration(sv2017::Local_parameter_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParameter_declaration(sv2017::Parameter_declarationContext *context) = 0;

    virtual antlrcpp::Any visitType_declaration(sv2017::Type_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNet_type_declaration(sv2017::Net_type_declarationContext *context) = 0;

    virtual antlrcpp::Any visitLet_declaration(sv2017::Let_declarationContext *context) = 0;

    virtual antlrcpp::Any visitLet_port_list(sv2017::Let_port_listContext *context) = 0;

    virtual antlrcpp::Any visitLet_port_item(sv2017::Let_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitLet_formal_type(sv2017::Let_formal_typeContext *context) = 0;

    virtual antlrcpp::Any visitPackage_import_declaration(sv2017::Package_import_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPackage_import_item(sv2017::Package_import_itemContext *context) = 0;

    virtual antlrcpp::Any visitProperty_list_of_arguments(sv2017::Property_list_of_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitProperty_actual_arg(sv2017::Property_actual_argContext *context) = 0;

    virtual antlrcpp::Any visitProperty_formal_type(sv2017::Property_formal_typeContext *context) = 0;

    virtual antlrcpp::Any visitSequence_formal_type(sv2017::Sequence_formal_typeContext *context) = 0;

    virtual antlrcpp::Any visitProperty_instance(sv2017::Property_instanceContext *context) = 0;

    virtual antlrcpp::Any visitProperty_spec(sv2017::Property_specContext *context) = 0;

    virtual antlrcpp::Any visitProperty_expr(sv2017::Property_exprContext *context) = 0;

    virtual antlrcpp::Any visitProperty_case_item(sv2017::Property_case_itemContext *context) = 0;

    virtual antlrcpp::Any visitBit_select(sv2017::Bit_selectContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_with_bit_select(sv2017::Identifier_with_bit_selectContext *context) = 0;

    virtual antlrcpp::Any visitPackage_or_class_scoped_hier_id_with_select(sv2017::Package_or_class_scoped_hier_id_with_selectContext *context) = 0;

    virtual antlrcpp::Any visitPackage_or_class_scoped_path_item(sv2017::Package_or_class_scoped_path_itemContext *context) = 0;

    virtual antlrcpp::Any visitPackage_or_class_scoped_path(sv2017::Package_or_class_scoped_pathContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_identifier(sv2017::Hierarchical_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPackage_or_class_scoped_id(sv2017::Package_or_class_scoped_idContext *context) = 0;

    virtual antlrcpp::Any visitSelect(sv2017::SelectContext *context) = 0;

    virtual antlrcpp::Any visitEvent_expression_item(sv2017::Event_expression_itemContext *context) = 0;

    virtual antlrcpp::Any visitEvent_expression(sv2017::Event_expressionContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_abbrev(sv2017::Boolean_abbrevContext *context) = 0;

    virtual antlrcpp::Any visitSequence_abbrev(sv2017::Sequence_abbrevContext *context) = 0;

    virtual antlrcpp::Any visitConsecutive_repetition(sv2017::Consecutive_repetitionContext *context) = 0;

    virtual antlrcpp::Any visitNon_consecutive_repetition(sv2017::Non_consecutive_repetitionContext *context) = 0;

    virtual antlrcpp::Any visitGoto_repetition(sv2017::Goto_repetitionContext *context) = 0;

    virtual antlrcpp::Any visitCycle_delay_const_range_expression(sv2017::Cycle_delay_const_range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitSequence_instance(sv2017::Sequence_instanceContext *context) = 0;

    virtual antlrcpp::Any visitSequence_expr(sv2017::Sequence_exprContext *context) = 0;

    virtual antlrcpp::Any visitSequence_match_item(sv2017::Sequence_match_itemContext *context) = 0;

    virtual antlrcpp::Any visitOperator_assignment(sv2017::Operator_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitSequence_actual_arg(sv2017::Sequence_actual_argContext *context) = 0;

    virtual antlrcpp::Any visitDist_weight(sv2017::Dist_weightContext *context) = 0;

    virtual antlrcpp::Any visitClocking_declaration(sv2017::Clocking_declarationContext *context) = 0;

    virtual antlrcpp::Any visitClocking_item(sv2017::Clocking_itemContext *context) = 0;

    virtual antlrcpp::Any visitList_of_clocking_decl_assign(sv2017::List_of_clocking_decl_assignContext *context) = 0;

    virtual antlrcpp::Any visitClocking_decl_assign(sv2017::Clocking_decl_assignContext *context) = 0;

    virtual antlrcpp::Any visitDefault_skew(sv2017::Default_skewContext *context) = 0;

    virtual antlrcpp::Any visitClocking_direction(sv2017::Clocking_directionContext *context) = 0;

    virtual antlrcpp::Any visitClocking_skew(sv2017::Clocking_skewContext *context) = 0;

    virtual antlrcpp::Any visitClocking_event(sv2017::Clocking_eventContext *context) = 0;

    virtual antlrcpp::Any visitCycle_delay_range(sv2017::Cycle_delay_rangeContext *context) = 0;

    virtual antlrcpp::Any visitExpression_or_dist(sv2017::Expression_or_distContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_declaration(sv2017::Covergroup_declarationContext *context) = 0;

    virtual antlrcpp::Any visitCover_cross(sv2017::Cover_crossContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_list_2plus(sv2017::Identifier_list_2plusContext *context) = 0;

    virtual antlrcpp::Any visitCross_body(sv2017::Cross_bodyContext *context) = 0;

    virtual antlrcpp::Any visitCross_body_item(sv2017::Cross_body_itemContext *context) = 0;

    virtual antlrcpp::Any visitBins_selection_or_option(sv2017::Bins_selection_or_optionContext *context) = 0;

    virtual antlrcpp::Any visitBins_selection(sv2017::Bins_selectionContext *context) = 0;

    virtual antlrcpp::Any visitSelect_expression(sv2017::Select_expressionContext *context) = 0;

    virtual antlrcpp::Any visitSelect_condition(sv2017::Select_conditionContext *context) = 0;

    virtual antlrcpp::Any visitBins_expression(sv2017::Bins_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_range_list(sv2017::Covergroup_range_listContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_value_range(sv2017::Covergroup_value_rangeContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_expression(sv2017::Covergroup_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCoverage_spec_or_option(sv2017::Coverage_spec_or_optionContext *context) = 0;

    virtual antlrcpp::Any visitCoverage_option(sv2017::Coverage_optionContext *context) = 0;

    virtual antlrcpp::Any visitCoverage_spec(sv2017::Coverage_specContext *context) = 0;

    virtual antlrcpp::Any visitCover_point(sv2017::Cover_pointContext *context) = 0;

    virtual antlrcpp::Any visitBins_or_empty(sv2017::Bins_or_emptyContext *context) = 0;

    virtual antlrcpp::Any visitBins_or_options(sv2017::Bins_or_optionsContext *context) = 0;

    virtual antlrcpp::Any visitTrans_list(sv2017::Trans_listContext *context) = 0;

    virtual antlrcpp::Any visitTrans_set(sv2017::Trans_setContext *context) = 0;

    virtual antlrcpp::Any visitTrans_range_list(sv2017::Trans_range_listContext *context) = 0;

    virtual antlrcpp::Any visitRepeat_range(sv2017::Repeat_rangeContext *context) = 0;

    virtual antlrcpp::Any visitCoverage_event(sv2017::Coverage_eventContext *context) = 0;

    virtual antlrcpp::Any visitBlock_event_expression(sv2017::Block_event_expressionContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_btf_identifier(sv2017::Hierarchical_btf_identifierContext *context) = 0;

    virtual antlrcpp::Any visitAssertion_variable_declaration(sv2017::Assertion_variable_declarationContext *context) = 0;

    virtual antlrcpp::Any visitDist_item(sv2017::Dist_itemContext *context) = 0;

    virtual antlrcpp::Any visitValue_range(sv2017::Value_rangeContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_instance(sv2017::Attribute_instanceContext *context) = 0;

    virtual antlrcpp::Any visitAttr_spec(sv2017::Attr_specContext *context) = 0;

    virtual antlrcpp::Any visitClass_new(sv2017::Class_newContext *context) = 0;

    virtual antlrcpp::Any visitParam_expression(sv2017::Param_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_param_expression(sv2017::Constant_param_expressionContext *context) = 0;

    virtual antlrcpp::Any visitUnpacked_dimension(sv2017::Unpacked_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitPacked_dimension(sv2017::Packed_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitVariable_dimension(sv2017::Variable_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitStruct_union(sv2017::Struct_unionContext *context) = 0;

    virtual antlrcpp::Any visitEnum_base_type(sv2017::Enum_base_typeContext *context) = 0;

    virtual antlrcpp::Any visitData_type_primitive(sv2017::Data_type_primitiveContext *context) = 0;

    virtual antlrcpp::Any visitData_type(sv2017::Data_typeContext *context) = 0;

    virtual antlrcpp::Any visitData_type_or_implicit(sv2017::Data_type_or_implicitContext *context) = 0;

    virtual antlrcpp::Any visitImplicit_data_type(sv2017::Implicit_data_typeContext *context) = 0;

    virtual antlrcpp::Any visitSequence_list_of_arguments_named_item(sv2017::Sequence_list_of_arguments_named_itemContext *context) = 0;

    virtual antlrcpp::Any visitSequence_list_of_arguments(sv2017::Sequence_list_of_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_arguments_named_item(sv2017::List_of_arguments_named_itemContext *context) = 0;

    virtual antlrcpp::Any visitList_of_arguments(sv2017::List_of_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_literal(sv2017::Primary_literalContext *context) = 0;

    virtual antlrcpp::Any visitType_reference(sv2017::Type_referenceContext *context) = 0;

    virtual antlrcpp::Any visitPackage_scope(sv2017::Package_scopeContext *context) = 0;

    virtual antlrcpp::Any visitPs_identifier(sv2017::Ps_identifierContext *context) = 0;

    virtual antlrcpp::Any visitList_of_parameter_value_assignments(sv2017::List_of_parameter_value_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitParameter_value_assignment(sv2017::Parameter_value_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitClass_type(sv2017::Class_typeContext *context) = 0;

    virtual antlrcpp::Any visitClass_scope(sv2017::Class_scopeContext *context) = 0;

    virtual antlrcpp::Any visitRange_expression(sv2017::Range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_range_expression(sv2017::Constant_range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_mintypmax_expression(sv2017::Constant_mintypmax_expressionContext *context) = 0;

    virtual antlrcpp::Any visitMintypmax_expression(sv2017::Mintypmax_expressionContext *context) = 0;

    virtual antlrcpp::Any visitNamed_parameter_assignment(sv2017::Named_parameter_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryLit(sv2017::PrimaryLitContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryRandomize(sv2017::PrimaryRandomizeContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryAssig(sv2017::PrimaryAssigContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryBitSelect(sv2017::PrimaryBitSelectContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryTfCall(sv2017::PrimaryTfCallContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryTypeRef(sv2017::PrimaryTypeRefContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryCallArrayMethodNoArgs(sv2017::PrimaryCallArrayMethodNoArgsContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryCast(sv2017::PrimaryCastContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryPar(sv2017::PrimaryParContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryCall(sv2017::PrimaryCallContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryRandomize2(sv2017::PrimaryRandomize2Context *context) = 0;

    virtual antlrcpp::Any visitPrimaryDot(sv2017::PrimaryDotContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryStreaming_concatenation(sv2017::PrimaryStreaming_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryPath(sv2017::PrimaryPathContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryIndex(sv2017::PrimaryIndexContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryCallWith(sv2017::PrimaryCallWithContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryConcat(sv2017::PrimaryConcatContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryCast2(sv2017::PrimaryCast2Context *context) = 0;

    virtual antlrcpp::Any visitConstant_expression(sv2017::Constant_expressionContext *context) = 0;

    virtual antlrcpp::Any visitInc_or_dec_expressionPre(sv2017::Inc_or_dec_expressionPreContext *context) = 0;

    virtual antlrcpp::Any visitInc_or_dec_expressionPost(sv2017::Inc_or_dec_expressionPostContext *context) = 0;

    virtual antlrcpp::Any visitExpression(sv2017::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConcatenation(sv2017::ConcatenationContext *context) = 0;

    virtual antlrcpp::Any visitDynamic_array_new(sv2017::Dynamic_array_newContext *context) = 0;

    virtual antlrcpp::Any visitConst_or_range_expression(sv2017::Const_or_range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitVariable_decl_assignment(sv2017::Variable_decl_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_variable_lvalue(sv2017::Assignment_pattern_variable_lvalueContext *context) = 0;

    virtual antlrcpp::Any visitStream_operator(sv2017::Stream_operatorContext *context) = 0;

    virtual antlrcpp::Any visitSlice_size(sv2017::Slice_sizeContext *context) = 0;

    virtual antlrcpp::Any visitStreaming_concatenation(sv2017::Streaming_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitStream_concatenation(sv2017::Stream_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitStream_expression(sv2017::Stream_expressionContext *context) = 0;

    virtual antlrcpp::Any visitArray_range_expression(sv2017::Array_range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitOpen_range_list(sv2017::Open_range_listContext *context) = 0;

    virtual antlrcpp::Any visitPattern(sv2017::PatternContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern(sv2017::Assignment_patternContext *context) = 0;

    virtual antlrcpp::Any visitStructure_pattern_key(sv2017::Structure_pattern_keyContext *context) = 0;

    virtual antlrcpp::Any visitArray_pattern_key(sv2017::Array_pattern_keyContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_key(sv2017::Assignment_pattern_keyContext *context) = 0;

    virtual antlrcpp::Any visitStruct_union_member(sv2017::Struct_union_memberContext *context) = 0;

    virtual antlrcpp::Any visitData_type_or_void(sv2017::Data_type_or_voidContext *context) = 0;

    virtual antlrcpp::Any visitEnum_name_declaration(sv2017::Enum_name_declarationContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_expression(sv2017::Assignment_pattern_expressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_expression_type(sv2017::Assignment_pattern_expression_typeContext *context) = 0;

    virtual antlrcpp::Any visitNet_lvalue(sv2017::Net_lvalueContext *context) = 0;

    virtual antlrcpp::Any visitVariable_lvalue(sv2017::Variable_lvalueContext *context) = 0;

    virtual antlrcpp::Any visitSolve_before_list(sv2017::Solve_before_listContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_block_item(sv2017::Constraint_block_itemContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_expression(sv2017::Constraint_expressionContext *context) = 0;

    virtual antlrcpp::Any visitUniqueness_constraint(sv2017::Uniqueness_constraintContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_set(sv2017::Constraint_setContext *context) = 0;

    virtual antlrcpp::Any visitRandomize_call(sv2017::Randomize_callContext *context) = 0;

    virtual antlrcpp::Any visitModule_header_common(sv2017::Module_header_commonContext *context) = 0;

    virtual antlrcpp::Any visitModule_declaration(sv2017::Module_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModule_keyword(sv2017::Module_keywordContext *context) = 0;

    virtual antlrcpp::Any visitNet_port_type(sv2017::Net_port_typeContext *context) = 0;

    virtual antlrcpp::Any visitVar_data_type(sv2017::Var_data_typeContext *context) = 0;

    virtual antlrcpp::Any visitNet_or_var_data_type(sv2017::Net_or_var_data_typeContext *context) = 0;

    virtual antlrcpp::Any visitList_of_defparam_assignments(sv2017::List_of_defparam_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_net_decl_assignments(sv2017::List_of_net_decl_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_specparam_assignments(sv2017::List_of_specparam_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_decl_assignments(sv2017::List_of_variable_decl_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_identifiers_item(sv2017::List_of_variable_identifiers_itemContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_identifiers(sv2017::List_of_variable_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_port_identifiers(sv2017::List_of_variable_port_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitDefparam_assignment(sv2017::Defparam_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitNet_decl_assignment(sv2017::Net_decl_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitSpecparam_assignment(sv2017::Specparam_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitError_limit_value(sv2017::Error_limit_valueContext *context) = 0;

    virtual antlrcpp::Any visitReject_limit_value(sv2017::Reject_limit_valueContext *context) = 0;

    virtual antlrcpp::Any visitPulse_control_specparam(sv2017::Pulse_control_specparamContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_doted_index_at_end(sv2017::Identifier_doted_index_at_endContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_terminal_descriptor(sv2017::Specify_terminal_descriptorContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_input_terminal_descriptor(sv2017::Specify_input_terminal_descriptorContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_output_terminal_descriptor(sv2017::Specify_output_terminal_descriptorContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_item(sv2017::Specify_itemContext *context) = 0;

    virtual antlrcpp::Any visitPulsestyle_declaration(sv2017::Pulsestyle_declarationContext *context) = 0;

    virtual antlrcpp::Any visitShowcancelled_declaration(sv2017::Showcancelled_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPath_declaration(sv2017::Path_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSimple_path_declaration(sv2017::Simple_path_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPath_delay_value(sv2017::Path_delay_valueContext *context) = 0;

    virtual antlrcpp::Any visitList_of_path_outputs(sv2017::List_of_path_outputsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_path_inputs(sv2017::List_of_path_inputsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_paths(sv2017::List_of_pathsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_path_delay_expressions(sv2017::List_of_path_delay_expressionsContext *context) = 0;

    virtual antlrcpp::Any visitT_path_delay_expression(sv2017::T_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTrise_path_delay_expression(sv2017::Trise_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTfall_path_delay_expression(sv2017::Tfall_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTz_path_delay_expression(sv2017::Tz_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT01_path_delay_expression(sv2017::T01_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT10_path_delay_expression(sv2017::T10_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT0z_path_delay_expression(sv2017::T0z_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTz1_path_delay_expression(sv2017::Tz1_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT1z_path_delay_expression(sv2017::T1z_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTz0_path_delay_expression(sv2017::Tz0_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT0x_path_delay_expression(sv2017::T0x_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTx1_path_delay_expression(sv2017::Tx1_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT1x_path_delay_expression(sv2017::T1x_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTx0_path_delay_expression(sv2017::Tx0_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTxz_path_delay_expression(sv2017::Txz_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTzx_path_delay_expression(sv2017::Tzx_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitParallel_path_description(sv2017::Parallel_path_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitFull_path_description(sv2017::Full_path_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_list(sv2017::Identifier_listContext *context) = 0;

    virtual antlrcpp::Any visitSpecparam_declaration(sv2017::Specparam_declarationContext *context) = 0;

    virtual antlrcpp::Any visitEdge_sensitive_path_declaration(sv2017::Edge_sensitive_path_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParallel_edge_sensitive_path_description(sv2017::Parallel_edge_sensitive_path_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitFull_edge_sensitive_path_description(sv2017::Full_edge_sensitive_path_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitData_source_expression(sv2017::Data_source_expressionContext *context) = 0;

    virtual antlrcpp::Any visitData_declaration(sv2017::Data_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModule_path_expression(sv2017::Module_path_expressionContext *context) = 0;

    virtual antlrcpp::Any visitState_dependent_path_declaration(sv2017::State_dependent_path_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPackage_export_declaration(sv2017::Package_export_declarationContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_declaration(sv2017::Genvar_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNet_declaration(sv2017::Net_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParameter_port_list(sv2017::Parameter_port_listContext *context) = 0;

    virtual antlrcpp::Any visitParameter_port_declaration(sv2017::Parameter_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitList_of_port_declarations_ansi_item(sv2017::List_of_port_declarations_ansi_itemContext *context) = 0;

    virtual antlrcpp::Any visitList_of_port_declarations(sv2017::List_of_port_declarationsContext *context) = 0;

    virtual antlrcpp::Any visitNonansi_port_declaration(sv2017::Nonansi_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNonansi_port(sv2017::Nonansi_portContext *context) = 0;

    virtual antlrcpp::Any visitNonansi_port__expr(sv2017::Nonansi_port__exprContext *context) = 0;

    virtual antlrcpp::Any visitPort_identifier(sv2017::Port_identifierContext *context) = 0;

    virtual antlrcpp::Any visitAnsi_port_declaration(sv2017::Ansi_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSystem_timing_check(sv2017::System_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_setup_timing_check(sv2017::Dolar_setup_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_hold_timing_check(sv2017::Dolar_hold_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_setuphold_timing_check(sv2017::Dolar_setuphold_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_recovery_timing_check(sv2017::Dolar_recovery_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_removal_timing_check(sv2017::Dolar_removal_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_recrem_timing_check(sv2017::Dolar_recrem_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_skew_timing_check(sv2017::Dolar_skew_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_timeskew_timing_check(sv2017::Dolar_timeskew_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_fullskew_timing_check(sv2017::Dolar_fullskew_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_period_timing_check(sv2017::Dolar_period_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_width_timing_check(sv2017::Dolar_width_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitDolar_nochange_timing_check(sv2017::Dolar_nochange_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitTimecheck_condition(sv2017::Timecheck_conditionContext *context) = 0;

    virtual antlrcpp::Any visitControlled_reference_event(sv2017::Controlled_reference_eventContext *context) = 0;

    virtual antlrcpp::Any visitDelayed_reference(sv2017::Delayed_referenceContext *context) = 0;

    virtual antlrcpp::Any visitEnd_edge_offset(sv2017::End_edge_offsetContext *context) = 0;

    virtual antlrcpp::Any visitEvent_based_flag(sv2017::Event_based_flagContext *context) = 0;

    virtual antlrcpp::Any visitNotifier(sv2017::NotifierContext *context) = 0;

    virtual antlrcpp::Any visitRemain_active_flag(sv2017::Remain_active_flagContext *context) = 0;

    virtual antlrcpp::Any visitTimestamp_condition(sv2017::Timestamp_conditionContext *context) = 0;

    virtual antlrcpp::Any visitStart_edge_offset(sv2017::Start_edge_offsetContext *context) = 0;

    virtual antlrcpp::Any visitThreshold(sv2017::ThresholdContext *context) = 0;

    virtual antlrcpp::Any visitTiming_check_limit(sv2017::Timing_check_limitContext *context) = 0;

    virtual antlrcpp::Any visitTiming_check_event(sv2017::Timing_check_eventContext *context) = 0;

    virtual antlrcpp::Any visitTiming_check_condition(sv2017::Timing_check_conditionContext *context) = 0;

    virtual antlrcpp::Any visitScalar_timing_check_condition(sv2017::Scalar_timing_check_conditionContext *context) = 0;

    virtual antlrcpp::Any visitControlled_timing_check_event(sv2017::Controlled_timing_check_eventContext *context) = 0;

    virtual antlrcpp::Any visitFunction_data_type_or_implicit(sv2017::Function_data_type_or_implicitContext *context) = 0;

    virtual antlrcpp::Any visitExtern_tf_declaration(sv2017::Extern_tf_declarationContext *context) = 0;

    virtual antlrcpp::Any visitFunction_declaration(sv2017::Function_declarationContext *context) = 0;

    virtual antlrcpp::Any visitTask_prototype(sv2017::Task_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitFunction_prototype(sv2017::Function_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitDpi_import_export(sv2017::Dpi_import_exportContext *context) = 0;

    virtual antlrcpp::Any visitDpi_function_import_property(sv2017::Dpi_function_import_propertyContext *context) = 0;

    virtual antlrcpp::Any visitDpi_task_import_property(sv2017::Dpi_task_import_propertyContext *context) = 0;

    virtual antlrcpp::Any visitTask_and_function_declaration_common(sv2017::Task_and_function_declaration_commonContext *context) = 0;

    virtual antlrcpp::Any visitTask_declaration(sv2017::Task_declarationContext *context) = 0;

    virtual antlrcpp::Any visitMethod_prototype(sv2017::Method_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitExtern_constraint_declaration(sv2017::Extern_constraint_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_block(sv2017::Constraint_blockContext *context) = 0;

    virtual antlrcpp::Any visitChecker_port_list(sv2017::Checker_port_listContext *context) = 0;

    virtual antlrcpp::Any visitChecker_port_item(sv2017::Checker_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitChecker_port_direction(sv2017::Checker_port_directionContext *context) = 0;

    virtual antlrcpp::Any visitChecker_declaration(sv2017::Checker_declarationContext *context) = 0;

    virtual antlrcpp::Any visitClass_declaration(sv2017::Class_declarationContext *context) = 0;

    virtual antlrcpp::Any visitAlways_construct(sv2017::Always_constructContext *context) = 0;

    virtual antlrcpp::Any visitInterface_class_type(sv2017::Interface_class_typeContext *context) = 0;

    virtual antlrcpp::Any visitInterface_class_declaration(sv2017::Interface_class_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_class_item(sv2017::Interface_class_itemContext *context) = 0;

    virtual antlrcpp::Any visitInterface_class_method(sv2017::Interface_class_methodContext *context) = 0;

    virtual antlrcpp::Any visitPackage_declaration(sv2017::Package_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPackage_item(sv2017::Package_itemContext *context) = 0;

    virtual antlrcpp::Any visitProgram_declaration(sv2017::Program_declarationContext *context) = 0;

    virtual antlrcpp::Any visitProgram_header(sv2017::Program_headerContext *context) = 0;

    virtual antlrcpp::Any visitProgram_item(sv2017::Program_itemContext *context) = 0;

    virtual antlrcpp::Any visitNon_port_program_item(sv2017::Non_port_program_itemContext *context) = 0;

    virtual antlrcpp::Any visitAnonymous_program(sv2017::Anonymous_programContext *context) = 0;

    virtual antlrcpp::Any visitAnonymous_program_item(sv2017::Anonymous_program_itemContext *context) = 0;

    virtual antlrcpp::Any visitSequence_declaration(sv2017::Sequence_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSequence_port_list(sv2017::Sequence_port_listContext *context) = 0;

    virtual antlrcpp::Any visitSequence_port_item(sv2017::Sequence_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitProperty_declaration(sv2017::Property_declarationContext *context) = 0;

    virtual antlrcpp::Any visitProperty_port_list(sv2017::Property_port_listContext *context) = 0;

    virtual antlrcpp::Any visitProperty_port_item(sv2017::Property_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitContinuous_assign(sv2017::Continuous_assignContext *context) = 0;

    virtual antlrcpp::Any visitChecker_or_generate_item(sv2017::Checker_or_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_prototype(sv2017::Constraint_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitClass_constraint(sv2017::Class_constraintContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_declaration(sv2017::Constraint_declarationContext *context) = 0;

    virtual antlrcpp::Any visitClass_constructor_declaration(sv2017::Class_constructor_declarationContext *context) = 0;

    virtual antlrcpp::Any visitClass_property(sv2017::Class_propertyContext *context) = 0;

    virtual antlrcpp::Any visitClass_method(sv2017::Class_methodContext *context) = 0;

    virtual antlrcpp::Any visitClass_constructor_prototype(sv2017::Class_constructor_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitClass_item(sv2017::Class_itemContext *context) = 0;

    virtual antlrcpp::Any visitParameter_override(sv2017::Parameter_overrideContext *context) = 0;

    virtual antlrcpp::Any visitGate_instantiation(sv2017::Gate_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitEnable_gate_or_mos_switch_or_cmos_switch_instance(sv2017::Enable_gate_or_mos_switch_or_cmos_switch_instanceContext *context) = 0;

    virtual antlrcpp::Any visitN_input_gate_instance(sv2017::N_input_gate_instanceContext *context) = 0;

    virtual antlrcpp::Any visitN_output_gate_instance(sv2017::N_output_gate_instanceContext *context) = 0;

    virtual antlrcpp::Any visitPass_switch_instance(sv2017::Pass_switch_instanceContext *context) = 0;

    virtual antlrcpp::Any visitPass_enable_switch_instance(sv2017::Pass_enable_switch_instanceContext *context) = 0;

    virtual antlrcpp::Any visitPull_gate_instance(sv2017::Pull_gate_instanceContext *context) = 0;

    virtual antlrcpp::Any visitPulldown_strength(sv2017::Pulldown_strengthContext *context) = 0;

    virtual antlrcpp::Any visitPullup_strength(sv2017::Pullup_strengthContext *context) = 0;

    virtual antlrcpp::Any visitEnable_terminal(sv2017::Enable_terminalContext *context) = 0;

    virtual antlrcpp::Any visitInout_terminal(sv2017::Inout_terminalContext *context) = 0;

    virtual antlrcpp::Any visitInput_terminal(sv2017::Input_terminalContext *context) = 0;

    virtual antlrcpp::Any visitOutput_terminal(sv2017::Output_terminalContext *context) = 0;

    virtual antlrcpp::Any visitUdp_instantiation(sv2017::Udp_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_instance(sv2017::Udp_instanceContext *context) = 0;

    virtual antlrcpp::Any visitUdp_instance_body(sv2017::Udp_instance_bodyContext *context) = 0;

    virtual antlrcpp::Any visitModule_or_interface_or_program_or_udp_instantiation(sv2017::Module_or_interface_or_program_or_udp_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_instance(sv2017::Hierarchical_instanceContext *context) = 0;

    virtual antlrcpp::Any visitList_of_port_connections(sv2017::List_of_port_connectionsContext *context) = 0;

    virtual antlrcpp::Any visitOrdered_port_connection(sv2017::Ordered_port_connectionContext *context) = 0;

    virtual antlrcpp::Any visitNamed_port_connection(sv2017::Named_port_connectionContext *context) = 0;

    virtual antlrcpp::Any visitBind_directive(sv2017::Bind_directiveContext *context) = 0;

    virtual antlrcpp::Any visitBind_target_instance(sv2017::Bind_target_instanceContext *context) = 0;

    virtual antlrcpp::Any visitBind_target_instance_list(sv2017::Bind_target_instance_listContext *context) = 0;

    virtual antlrcpp::Any visitBind_instantiation(sv2017::Bind_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitConfig_declaration(sv2017::Config_declarationContext *context) = 0;

    virtual antlrcpp::Any visitDesign_statement(sv2017::Design_statementContext *context) = 0;

    virtual antlrcpp::Any visitConfig_rule_statement(sv2017::Config_rule_statementContext *context) = 0;

    virtual antlrcpp::Any visitInst_clause(sv2017::Inst_clauseContext *context) = 0;

    virtual antlrcpp::Any visitInst_name(sv2017::Inst_nameContext *context) = 0;

    virtual antlrcpp::Any visitCell_clause(sv2017::Cell_clauseContext *context) = 0;

    virtual antlrcpp::Any visitLiblist_clause(sv2017::Liblist_clauseContext *context) = 0;

    virtual antlrcpp::Any visitUse_clause(sv2017::Use_clauseContext *context) = 0;

    virtual antlrcpp::Any visitNet_alias(sv2017::Net_aliasContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_block(sv2017::Specify_blockContext *context) = 0;

    virtual antlrcpp::Any visitGenerate_region(sv2017::Generate_regionContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_expression(sv2017::Genvar_expressionContext *context) = 0;

    virtual antlrcpp::Any visitLoop_generate_construct(sv2017::Loop_generate_constructContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_initialization(sv2017::Genvar_initializationContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_iteration(sv2017::Genvar_iterationContext *context) = 0;

    virtual antlrcpp::Any visitConditional_generate_construct(sv2017::Conditional_generate_constructContext *context) = 0;

    virtual antlrcpp::Any visitIf_generate_construct(sv2017::If_generate_constructContext *context) = 0;

    virtual antlrcpp::Any visitCase_generate_construct(sv2017::Case_generate_constructContext *context) = 0;

    virtual antlrcpp::Any visitCase_generate_item(sv2017::Case_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitGenerate_begin_end_block(sv2017::Generate_begin_end_blockContext *context) = 0;

    virtual antlrcpp::Any visitGenerate_item(sv2017::Generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitProgram_generate_item(sv2017::Program_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitModule_or_generate_or_interface_or_checker_item(sv2017::Module_or_generate_or_interface_or_checker_itemContext *context) = 0;

    virtual antlrcpp::Any visitModule_or_generate_or_interface_item(sv2017::Module_or_generate_or_interface_itemContext *context) = 0;

    virtual antlrcpp::Any visitModule_or_generate_item(sv2017::Module_or_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitElaboration_system_task(sv2017::Elaboration_system_taskContext *context) = 0;

    virtual antlrcpp::Any visitModule_item_item(sv2017::Module_item_itemContext *context) = 0;

    virtual antlrcpp::Any visitModule_item(sv2017::Module_itemContext *context) = 0;


};

}  // namespace mgp_sv
