##############################################################################################################
#                                             DOWNLOAD ANTLR JAR                                             #
##############################################################################################################
include(ExternalProject)

SET(ANTLR_JAR antlr-${ANTLR_VERSION}-complete.jar)

ExternalProject_Add(antlr_jar
        URL https://github.com/antlr/website-antlr4/blob/gh-pages/download/${ANTLR_JAR}?raw=true
        DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/antlr_jar
        DOWNLOAD_NAME ${ANTLR_JAR}
        DOWNLOAD_NO_EXTRACT ON
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        )


##############################################################################################################
#                                             GENERATE SV PARSER                                             #
##############################################################################################################

set(SV_PARSER_SRC
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017BaseListener.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017BaseListener.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017Listener.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017Listener.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017BaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017BaseVisitor.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017Visitor.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017Visitor.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017Lexer.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_sv/sv2017Lexer.h
        )

set(ANTLR_CLASSPATH ${CMAKE_CURRENT_BINARY_DIR}/antlr_jar/${ANTLR_JAR})

set(ANTLR_OPTIONS -Dlanguage=Cpp -visitor -listener  -encoding iso-8859-1)
set(ANTLR_OUTPUT -o ${PROJECT_SOURCE_DIR}/includes/mgp_sv)

add_custom_command(
        OUTPUT ${SV_PARSER_SRC}
        DEPENDS ${PROJECT_SOURCE_DIR}/grammars/sv2017.g4
        COMMAND java -cp "${ANTLR_CLASSPATH}" org.antlr.v4.Tool -package mgp_sv ${ANTLR_OPTIONS} ${ANTLR_OUTPUT} ${PROJECT_SOURCE_DIR}/grammars/sv2017.g4
        COMMAND java -cp "${ANTLR_CLASSPATH}" org.antlr.v4.Tool -package mgp_sv ${ANTLR_OPTIONS} ${ANTLR_OUTPUT} ${PROJECT_SOURCE_DIR}/grammars/sv2017Lexer.g4
        COMMENT "generating sources for System Verilog parser"
)

add_custom_target(sv_parser_gen DEPENDS  ${SV_PARSER_SRC})

add_dependencies(sv_parser_gen antlr_jar)


##############################################################################################################
#                                            GENERATE VHDL PARSER                                            #
##############################################################################################################

set(VHDL_PARSER_SRC
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParser.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParser.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParserBaseListener.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParserBaseListener.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParserListener.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParserListener.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParserBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParserBaseVisitor.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParserVisitor.h
        ${PROJECT_SOURCE_DIR}/src/includes/mgp_vh/vhdlParserVisitor.cpp
        )

set(ANTLR_OUTPUT -o ${PROJECT_SOURCE_DIR}/includes/mgp_vh)

add_custom_command(
        OUTPUT ${VHDL_PARSER_SRC}
        DEPENDS ${PROJECT_SOURCE_DIR}/grammars/vhdlParser.g4
        COMMAND java -cp "${ANTLR_CLASSPATH}" org.antlr.v4.Tool -package mgp_vh ${ANTLR_OPTIONS} ${ANTLR_OUTPUT} ${PROJECT_SOURCE_DIR}/grammars/vhdlLexer.g4
        COMMAND java -cp "${ANTLR_CLASSPATH}" org.antlr.v4.Tool -package mgp_vh ${ANTLR_OPTIONS} ${ANTLR_OUTPUT} ${PROJECT_SOURCE_DIR}/grammars/vhdlParser.g4
        COMMENT "generating sources for VHDL parser"
)
