Analysis and Bus Mapping
========================

.. meta::
   :description: The bus analyses and data-flow capabilities of Ananke.

.. note::

   This page is a placeholder. Content to be added.

Planned content:

* Control-bus (AXI-Lite) analysis and address-map extraction
  (:file:`src/analysis/control_bus_analysis.cpp`).
* Proxy subsystem analysis (:file:`src/analysis/proxy_bus_analysis.cpp`).
* AXI-Stream data-acquisition analysis: tracing a sink back to its sources and
  computing runtime selector settings
  (:file:`src/analysis/data_acquisition_analysis.cpp`).
* Bus specification files (:file:`bus_specs/axi_lite.json`,
  :file:`bus_specs/axi_stream.json`) and the ``bus_specs_manager``.
* Soft-core processor detection (:file:`src/analysis/passes/processor_detection.cpp`).
* The uplatform output formats: peripheral and application definitions
  (:file:`src/Backend/uplatform/`).
