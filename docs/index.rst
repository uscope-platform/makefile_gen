Ananke Documentation
====================

.. meta::
   :description: Documentation for Ananke, an FPGA HDL build system.

Ananke is a build system for FPGA HDL development. It parses SystemVerilog
(and, to a lesser extent, VHDL), fully evaluates compile-time parameters,
builds an elaborated AST, and from it generates vendor projects, address maps,
software-facing data structures, and data-flow analyses.


.. toctree::
   :maxdepth: 2
   :caption: Overview

   getting_started
   depfile_reference

.. toctree::
   :maxdepth: 2
   :caption: Developer Guide

   architecture
   toolchain_backends
   analysis_and_bus
   documentation_format

.. toctree::
   :maxdepth: 2
   :caption: Roadmap

   implementation_gaps
