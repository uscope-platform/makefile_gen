set(MAKEFILE_GEN_SRCS /
        main.cpp /
        analysis/sv_visitor.cpp /
        analysis/sv_analyzer.cpp /
        frontend/Repository_walker.cpp /
        data_model/settings_store.cpp /
        data_model/HDL_Resource.cpp /
        data_model/data_store.cpp /
        analysis/vhdl_analyzer.cpp /
        analysis/vhdl_visitor.cpp /
        data_model/Depfile.cpp /
        data_model/Script.cpp /
        data_model/Constraints.cpp /
        Backend/Dependency_resolver.cpp /
        Backend/Xilinx/Vivado_manager.cpp /
        Backend/Auxiliary_resolver.cpp /
        frontend/cache_manager.cpp /
        Backend/project_generator_base.cpp /
        Backend/Lattice/Radiant_manager.cpp /
        Backend/Toolchain_manager.cpp )

set(MAKEFILE_GEN_INCL /
        ../includes/main.hpp /
        ../includes/analysis/sv_visitor.h /
        ../includes/analysis/sv_analyzer.h /
        ../includes/third_party/CLI11.h /
        ../includes/frontend/Repository_walker.h /
        ../includes/data_model/settings_store.h /
        ../includes/data_model/HDL_Resource.h /
        ../includes/data_model/data_store.h /
        ../includes/third_party/thread_pool.hpp/
        ../includes/analysis/vhdl_analyzer.h /
        ../includes/analysis/vhdl_visitor.h /
        ../includes/data_model/Depfile.h /
        ../includes/data_model/Script.h /
        ../includes/data_model/Constraints.h /
        ../includes/Backend/Dependency_resolver.h /
        ../includes/Backend/Xilinx/xilinx_project_generator.h /
        ../includes/Backend/Xilinx/Vivado_manager.h /
        ../includes/Backend/Auxiliary_resolver.h /
        ../includes/frontend/cache_manager.h /      
        ../includes/Backend/Lattice/lattice_project_generator.h /
        ../includes/Backend/project_generator_base.h /
        ../includes/Backend/Lattice/Radiant_manager.h /
        ../includes/Backend/Toolchain_manager.h)

set(TEMPLATE_FILES /
        ../templates/make_project_xlnx.j2 /
        ../templates/make_project_lscc.j2 /
        ../templates/make_bitstream_xlnx.j2)


add_executable(makefile_gen ${MAKEFILE_GEN_SRCS} ${MAKEFILE_GEN_INCL})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DTEMPLATES_FOLDER="${CMAKE_SOURCE_DIR}/templates")
else()
    add_definitions(-DTEMPLATES_FOLDER="/usr/local/etc/makefile_gen")
    set_property(TARGET makefile_gen PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

target_link_libraries(makefile_gen PRIVATE mgp_sv_lib)
target_link_libraries(makefile_gen PRIVATE mgp_vh_lib)

target_link_libraries(makefile_gen PRIVATE Threads::Threads)
target_link_libraries(makefile_gen PRIVATE OpenSSL::SSL)




## INSTALLATION SECTION

install(TARGETS makefile_gen DESTINATION /usr/local/bin)
install(DIRECTORY ../templates/ DESTINATION /usr/local/etc/makefile_gen)

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
