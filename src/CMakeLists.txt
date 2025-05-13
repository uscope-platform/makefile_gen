set(MAKEFILE_GEN_SRCS_I /
        ${CMAKE_CURRENT_SOURCE_DIR}/analysis/HDL_ast_builder.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/analysis/data_acquisition_analysis.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/analysis/control_bus_analysis.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/analysis/HDL_loop_solver.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/analysis/proxy_bus_analysis.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/Dependency_resolver.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/uplatform/application_definition_generator.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/uplatform/peripheral_definition_generator.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/Xilinx/Vivado_manager.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/new_app_generator.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/Auxiliary_resolver.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/project_generator_base.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/Lattice/Radiant_manager.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/Toolchain_manager.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/python_script_runner.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/HDL_Resource.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/HDL_instance.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/HDL_instance_AST.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/factories/HDL_instances_factory.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/factories/HDL_modules_factory.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/factories/HDL_interfaces_factory.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/factories/HDL_loops_factory.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/factories/HDL_parameters_factory.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/factories/resource_factory_base.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/parameters/HDL_parameter.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/parameters/Expression_component.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/parameters/Parameter_processor.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/parameters/Initialization_list.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/parameters/HDL_function.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/bus_mapping/bus_specs_manager.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/bus_mapping/mapper_bus_component.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/settings_store.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/data_store.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/DataFile.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/mdarray.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/documentation/module_documentation.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/documentation/register_documentation.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/documentation/field_documentation.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/documentation/processor_instance.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/documentation/channel_group.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/documentation/channel.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/Depfile.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/Script.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/Constraints.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/frontend/analysis/sv_visitor.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/frontend/analysis/sv_analyzer.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/frontend/Repository_walker.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/frontend/analysis/vhdl_analyzer.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/frontend/analysis/documentation_analyzer.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/frontend/analysis/vhdl_visitor.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/frontend/cache_manager.cpp /
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/factories/HDL_functions_factory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/data_model/HDL/parameters/Expression_evaluator.cpp
)

set(MAKEFILE_GEN_SRCS ${MAKEFILE_GEN_SRCS_I}  PARENT_SCOPE)

set(TEMPLATE_FILES /
        ../templates/make_project_xlnx.j2 /
        ../templates/make_project_lscc.j2 /
        ../templates/make_bitstream_xlnx.j2)


add_executable(makefile_gen ${MAKEFILE_GEN_SRCS_I} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_property(TARGET makefile_gen PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
endif(CMAKE_BUILD_TYPE STREQUAL "Release")

target_link_libraries(makefile_gen PRIVATE mgp_sv_lib)
target_link_libraries(makefile_gen PRIVATE mgp_vh_lib)

target_link_libraries(makefile_gen PRIVATE Threads::Threads cereal nlohmann_json::nlohmann_json OpenSSL::SSL CLI11::CLI11 gtest::gtest)

## INSTALLATION SECTION

install(TARGETS makefile_gen DESTINATION /usr/local/bin)
install(DIRECTORY ../bus_specs/ DESTINATION /usr/local/etc/makefile_gen/specs)

## PACKAGING SECTION

SET(MAJOR_VERSION "1")
SET(MINOR_VERSION "0")
SET(PATCH_VERSION "0")

SET(CPACK_PACKAGE_DESCRIPTION "makefile_gen FPGA tool")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Simple build system and project generator for FPGA")
SET(CPACK_PACKAGE_VENDOR "filippo savi")
SET(CPACK_PACKAGE_CONTACT "filippo.savi@unimore.it")
SET(CPACK_PACKAGE_VERSION_MAJOR "${MAJOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
SET(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
set(CPACK_PACKAGE_EXECUTABLES makefile_gen)

#dependencies for this service menu
SET(CPACK_DEBIAN_PACKAGE_DEPENDS " libssl-dev , libantlr4-runtime-dev ")
SET(CPACK_DEBIAN_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})

INCLUDE(CPack)
