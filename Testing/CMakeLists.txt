set(MAKEFILEGEN_TESTS
        test_main.cpp
        data_model/Depfile_test.cpp
        data_model/Script_test.cpp
        data_model/Constraints_test.cpp
        data_model/hdl_resource_testing.cpp
        data_model/settings_store_test.cpp
        data_model/data_store_test.cpp
        Backend/Application_management_test.cpp)

set(TESTED_SOURCES
        ../src/data_model/Depfile.cpp
        ../src/data_model/Constraints.cpp
        ../src/data_model/Script.cpp
        ../src/data_model/HDL_Resource.cpp
        ../src/data_model/settings_store.cpp
        ../src/data_model/data_store.cpp
        ../src/Backend/new_app_generator.cpp
        )

add_executable(tests ${MAKEFILEGEN_TESTS} ${TESTED_SOURCES})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

set(CHECK_FILES_DIR ${CMAKE_CURRENT_BINARY_DIR}/check_files)
make_directory(${CHECK_FILES_DIR})

configure_file(files/Depfile ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(check_files/Depfile_gs ${CHECK_FILES_DIR} COPYONLY)
configure_file(check_files/top_synth_sv.sv ${CHECK_FILES_DIR} COPYONLY)
configure_file(check_files/top_tb_sv.sv ${CHECK_FILES_DIR} COPYONLY)


