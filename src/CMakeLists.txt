

add_library(makefile_gen_lib STATIC)

target_sources(makefile_gen_lib
    PRIVATE
    analysis/HDL_ast_builder.cpp /
    analysis/data_acquisition_analysis.cpp /
    analysis/control_bus_analysis.cpp /
    analysis/HDL_loop_solver.cpp /
    analysis/proxy_bus_analysis.cpp /
    Backend/Dependency_resolver.cpp /
    Backend/uplatform/application_definition_generator.cpp /
    Backend/uplatform/peripheral_definition_generator.cpp /
    Backend/Xilinx/Vivado_manager.cpp /
    Backend/new_app_generator.cpp /
    Backend/Auxiliary_resolver.cpp /
    Backend/project_generator_base.cpp /
    Backend/Lattice/Radiant_manager.cpp /
    Backend/Toolchain_manager.cpp /
    Backend/python_script_runner.cpp /
    data_model/HDL/HDL_Resource.cpp /
    data_model/HDL/HDL_instance.cpp /
    data_model/HDL/HDL_instance_AST.cpp /
    data_model/HDL/factories/HDL_instances_factory.cpp /
    data_model/HDL/factories/HDL_modules_factory.cpp /
    data_model/HDL/factories/HDL_interfaces_factory.cpp /
    data_model/HDL/factories/HDL_loops_factory.cpp /
    data_model/HDL/factories/HDL_parameters_factory.cpp /
    data_model/HDL/factories/resource_factory_base.cpp /
    data_model/HDL/parameters/HDL_parameter.cpp /
    data_model/HDL/parameters/Expression_component.cpp /
    data_model/HDL/parameters/Parameter_processor.cpp /
    data_model/HDL/parameters/Initialization_list.cpp /
    data_model/HDL/parameters/HDL_function.cpp /
    data_model/HDL/factories/HDL_functions_factory.cpp /
    data_model/HDL/factories/nets/HDL_range_factory.cpp /
    data_model/HDL/factories/nets/HDL_concat_factory.cpp /
    data_model/HDL/factories/nets/HDL_net_factory.cpp /
    data_model/HDL/factories/nets/HDL_repetition_factory.cpp /
    data_model/HDL/parameters/Expression_evaluator.cpp /
    data_model/HDL/HDL_net.cpp /
    data_model/bus_mapping/bus_specs_manager.cpp /
    data_model/bus_mapping/mapper_bus_component.cpp /
    data_model/settings_store.cpp /
    data_model/data_store.cpp /
    data_model/DataFile.cpp /
    data_model/mdarray.cpp /
    data_model/documentation/module_documentation.cpp /
    data_model/documentation/register_documentation.cpp /
    data_model/documentation/field_documentation.cpp /
    data_model/documentation/processor_instance.cpp /
    data_model/documentation/channel_group.cpp /
    data_model/documentation/channel.cpp /
    data_model/Depfile.cpp /
    data_model/Script.cpp /
    data_model/Constraints.cpp /
    frontend/analysis/sv_visitor.cpp /
    frontend/analysis/sv_analyzer.cpp /
    frontend/Repository_walker.cpp /
    frontend/analysis/vhdl_analyzer.cpp /
    frontend/analysis/documentation_analyzer.cpp /
    frontend/analysis/vhdl_visitor.cpp /
    frontend/cache_manager.cpp
)

target_link_libraries(makefile_gen_lib PUBLIC
        mgp_sv_lib
        mgp_vh_lib
        antlr4_static
        spdlog::spdlog
        Threads::Threads
        cereal
        nlohmann_json::nlohmann_json
        OpenSSL::SSL
        gtest::gtest
)

set(TEMPLATE_FILES /
        ../templates/make_project_xlnx.j2 /
        ../templates/make_project_lscc.j2 /
        ../templates/make_bitstream_xlnx.j2)


add_executable(makefile_gen ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_property(TARGET makefile_gen PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
endif(CMAKE_BUILD_TYPE STREQUAL "Release")

target_link_libraries(makefile_gen PRIVATE makefile_gen_lib  CLI11::CLI11 )

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
