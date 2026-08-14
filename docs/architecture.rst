Architecture
============

.. meta::
   :description: High-level architecture of the Ananke build system.

.. note::

   This page is a placeholder. Content to be added.

Planned content:

* End-to-end pipeline overview:

  * Repository walker and file-type dispatch
    (:file:`src/frontend/Repository_walker.cpp`).
  * SystemVerilog preprocessor and analyzer
    (:file:`src/frontend/analysis/system_verilog/`).
  * VHDL analyzer (:file:`src/frontend/analysis/vhdl/`).
  * Data store and caching (:file:`src/data_model/data_store.cpp`).
  * AST builder and parameter solver
    (:file:`src/analysis/HDL_ast_builder_v2.cpp`).
  * Analysis passes (:file:`src/analysis/passes/`).
  * Bus and data-acquisition analyses
    (:file:`src/analysis/control_bus_analysis.cpp`,
    :file:`src/analysis/data_acquisition_analysis.cpp`).
  * Backends (:file:`src/Backend/`).

* The HDL data model: ``hdl_file``, ``hdl_resource_statement``,
  ``hdl_ast_node``, statements, parameters, and types.
* The frontend factory design: ``expressions_factory``, ``HDL_functions_factory``
  and the statement/net factories are event-driven state machines that are
  agnostic of the ANTLR parse tree; each language visitor is a thin translator
  into these factories. This is the deliberate language-neutral seam shared by
  the SystemVerilog and (future) VHDL frontends.
* Caching and incremental analysis semantics.
