set(MGP_VH_PARSER_LIB_SRCS /
        vhdlLexer.cpp /
        vhdlParser.cpp /
        vhdlParserBaseListener.cpp /
        vhdlParserBaseVisitor.cpp /
        vhdlParserVisitor.cpp /
        vhdlParserListener.cpp )

set(MGP_VH_PARSER_LIB_INCL /
        vhdlLexer.h /
        vhdlParser.h /
        vhdlParserBaseListener.h /
        vhdlParserBaseVisitor.h /
        vhdlParserVisitor.h /
        vhdlParserListener.h )

add_library(mgp_vh_lib STATIC ${MGP_VH_PARSER_LIB_SRCS} ${MGP_VH_PARSER_LIB_INCL})

set_property(TARGET mgp_vh_lib PROPERTY INTERPROCEDURAL_OPTIMIZATION True)

target_link_libraries(mgp_vh_lib antlr4-runtime)
set_property(TARGET mgp_vh_lib PROPERTY POSITION_INDEPENDENT_CODE 1)


