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
        data_model/Resource_base.cpp /
        data_model/Constraints.cpp /
        Backend/Dependency_resolver.cpp /
        Backend/xilinx_project_generator.cpp /
        Backend/Auxiliary_resolver.cpp /
        frontend/cache_manager.cpp /
        Backend/Vivado_manager.cpp )

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
        ../includes/data_model/Resource_base.h /
        ../includes/data_model/Constraints.h /
        ../includes/Backend/Dependency_resolver.h /
        ../includes/Backend/xilinx_project_generator.h /
        ../includes/Backend/Auxiliary_resolver.h /
        ../includes/frontend/cache_manager.h /
        ../includes/Backend/Vivado_manager.h)


add_executable(makefile_gen ${MAKEFILE_GEN_SRCS} ${MAKEFILE_GEN_INCL})

target_link_libraries(makefile_gen mgp_sv_lib)
target_link_libraries(makefile_gen mgp_vh_lib)
target_link_libraries(makefile_gen pthread)
target_link_libraries(makefile_gen crypto)