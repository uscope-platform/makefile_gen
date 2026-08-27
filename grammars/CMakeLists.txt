##############################################################################################################
#                                             ANTLR PARSER REGENERATION                                     #
##############################################################################################################
#
# The generated parser sources are committed in includes/mgp_sv and
# includes/mgp_vh, so non-Debug builds never need Java or network access.
# Debug builds regenerate the parsers from the grammars, which is when the
# grammar is most likely to change during development (and requires a JDK and
# the ANTLR jar to be downloadable).
##############################################################################################################

string(TOLOWER "${CMAKE_BUILD_TYPE}" ANANKE_BUILD_TYPE_LOWER)
if(ANANKE_BUILD_TYPE_LOWER STREQUAL "debug")

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

    set(ANTLR_CLASSPATH ${CMAKE_CURRENT_BINARY_DIR}/antlr_jar/${ANTLR_JAR})
    set(ANTLR_OPTIONS -Dlanguage=Cpp -visitor -listener -encoding iso-8859-1)
    set(ANTLR_OUTPUT -o ${PROJECT_SOURCE_DIR}/includes/mgp_sv)

    ##########################################################################################################
    #                                             GENERATE SV PARSER                                         #
    ##########################################################################################################

    set(SV_PARSER_SRC
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017.interp
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017.tokens
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017BaseListener.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017BaseListener.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017Listener.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017Listener.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017BaseVisitor.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017BaseVisitor.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017Visitor.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017Visitor.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017Lexer.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017Lexer.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017Lexer.interp
            ${PROJECT_SOURCE_DIR}/includes/mgp_sv/sv2017Lexer.tokens
            )

    add_custom_command(
            OUTPUT ${SV_PARSER_SRC}
            DEPENDS ${PROJECT_SOURCE_DIR}/grammars/sv2017.g4 ${PROJECT_SOURCE_DIR}/grammars/sv2017Lexer.g4
            COMMAND java -cp "${ANTLR_CLASSPATH}" org.antlr.v4.Tool -package mgp_sv ${ANTLR_OPTIONS} ${ANTLR_OUTPUT} ${PROJECT_SOURCE_DIR}/grammars/sv2017.g4
            COMMAND java -cp "${ANTLR_CLASSPATH}" org.antlr.v4.Tool -package mgp_sv ${ANTLR_OPTIONS} ${ANTLR_OUTPUT} ${PROJECT_SOURCE_DIR}/grammars/sv2017Lexer.g4
            COMMENT "generating sources for System Verilog parser"
            )

    add_custom_target(sv_parser_gen DEPENDS ${SV_PARSER_SRC})
    add_dependencies(sv_parser_gen antlr_jar)

    ##########################################################################################################
    #                                            GENERATE VHDL PARSER                                        #
    ##########################################################################################################

    set(ANTLR_OUTPUT -o ${PROJECT_SOURCE_DIR}/includes/mgp_vh)

    set(VHDL_PARSER_SRC
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlLexer.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlLexer.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlLexer.interp
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlLexer.tokens
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParser.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParser.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParser.interp
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParser.tokens
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParserBaseListener.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParserBaseListener.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParserListener.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParserListener.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParserBaseVisitor.cpp
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParserBaseVisitor.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParserVisitor.h
            ${PROJECT_SOURCE_DIR}/includes/mgp_vh/vhdlParserVisitor.cpp
            )

    add_custom_command(
            OUTPUT ${VHDL_PARSER_SRC}
            DEPENDS ${PROJECT_SOURCE_DIR}/grammars/vhdlLexer.g4 ${PROJECT_SOURCE_DIR}/grammars/vhdlParser.g4
            COMMAND java -cp "${ANTLR_CLASSPATH}" org.antlr.v4.Tool -package mgp_vh ${ANTLR_OPTIONS} ${ANTLR_OUTPUT} ${PROJECT_SOURCE_DIR}/grammars/vhdlLexer.g4
            COMMAND java -cp "${ANTLR_CLASSPATH}" org.antlr.v4.Tool -package mgp_vh ${ANTLR_OPTIONS} ${ANTLR_OUTPUT} ${PROJECT_SOURCE_DIR}/grammars/vhdlParser.g4
            COMMENT "generating sources for VHDL parser"
            )

    add_custom_target(vh_parser_gen DEPENDS ${VHDL_PARSER_SRC})
    add_dependencies(vh_parser_gen antlr_jar)

    add_custom_target(parsers)
    add_dependencies(parsers sv_parser_gen vh_parser_gen)

else()

    add_custom_target(parsers)
    message(STATUS "Non-Debug build: using the committed parsers, no Java required")

endif()