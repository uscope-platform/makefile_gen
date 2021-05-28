set(MAKEFILE_GEN_SRCS /
        main.cpp /
        sv_visitor.cpp /
        frontend.cpp /
        Repository_walker.cpp)

set(MAKEFILE_GEN_INCL /
        ../includes/main.hpp /
        ../includes/sv_visitor.h /
        ../includes/frontend.h /
        ../includes/CLI11.h /
        ../includes/json.hpp/
        ../includes/Repository_walker.h)


add_executable(makefile_gen ${MAKEFILE_GEN_SRCS} ${MAKEFILE_GEN_INCL}  )

target_link_libraries(makefile_gen mgp_sv_lib)
