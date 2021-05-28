set(MAKEFILE_GEN_SRCS /
        main.cpp /
        analysis/sv_visitor.cpp /
        analysis/sv_analyzer.cpp /
        Repository_walker.cpp /
        data_store/data_store.cpp)

set(MAKEFILE_GEN_INCL /
        ../includes/main.hpp /
        ../includes/analysis/sv_visitor.h /
        ../includes/analysis/sv_analyzer.h /
        ../includes/third_party/CLI11.h /
        ../includes/third_party/json.hpp/
        ../includes/Repository_walker.h/
        ../includes/data_store/data_store.h)


add_executable(makefile_gen ${MAKEFILE_GEN_SRCS} ${MAKEFILE_GEN_INCL}  )

target_link_libraries(makefile_gen mgp_sv_lib)
