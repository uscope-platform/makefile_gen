set(MAKEFILEGEN_TESTS
        test_main.cpp
        data_model/Depfile_test.cpp
        data_model/Script_test.cpp
        data_model/Constraints_test.cpp
        data_model/hdl_resource_testing.cpp
        data_model/settings_store_test.cpp
        data_model/data_store_test.cpp
        data_model/DataFile_test.cpp
        data_model/bus_structure_test.cpp
        data_model/module_register_documentation.cpp
        analysis/documentation_analyzer.cpp
        analysis/analysis.cpp
        Backend/Application_management_test.cpp
        Backend/Application_definition_generator.cpp)


add_executable(tests ${MAKEFILEGEN_TESTS} ${MAKEFILE_GEN_SRCS})


# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} pthread mgp_sv_lib mgp_vh_lib OpenSSL::SSL)

set(CHECK_FILES_DIR ${CMAKE_CURRENT_BINARY_DIR}/check_files)
make_directory(${CHECK_FILES_DIR})

configure_file(files/Depfile ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(check_files/Depfile_gs ${CHECK_FILES_DIR} COPYONLY)
configure_file(check_files/test_package.sv ${CHECK_FILES_DIR} COPYONLY)
configure_file(check_files/test_sv_module.sv ${CHECK_FILES_DIR} COPYONLY)
configure_file(check_files/test_vhdl_module.vhd ${CHECK_FILES_DIR} COPYONLY)
configure_file(check_files/top_synth_sv.sv ${CHECK_FILES_DIR} COPYONLY)
configure_file(check_files/top_tb_sv.sv ${CHECK_FILES_DIR} COPYONLY)

set(CHECK_FILES_DIR ${CMAKE_CURRENT_BINARY_DIR}/check_files/documentation_analyzer)
make_directory(${CHECK_FILES_DIR})
configure_file(check_files/documentation_analyzer/test_bus_hierarchy.sv ${CHECK_FILES_DIR} COPYONLY)
configure_file(check_files/documentation_analyzer/test_module_hierarchy.sv ${CHECK_FILES_DIR} COPYONLY)