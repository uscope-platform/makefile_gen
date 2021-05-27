add_library(antlr4-runtime STATIC IMPORTED)
set_target_properties(antlr4-runtime PROPERTIES IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libantlr4-runtime.a")

add_subdirectory(mgp_sv)
add_subdirectory(mgp_vh)