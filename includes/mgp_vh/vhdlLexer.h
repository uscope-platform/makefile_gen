
// Generated from /home/filssavi/git/makefile_gen/grammars/vhdlLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"


namespace mgp_vh {


class  vhdlLexer : public antlr4::Lexer {
public:
  enum {
    KW_PROCESS = 1, KW_CONTEXT = 2, KW_POSTPONED = 3, KW_LINKAGE = 4, KW_COMPONENT = 5, 
    KW_ABS = 6, KW_DEFAULT = 7, KW_THEN = 8, KW_BLOCK = 9, KW_REM = 10, 
    KW_INERTIAL = 11, KW_NEXT = 12, KW_ENTITY = 13, KW_ON = 14, KW_GROUP = 15, 
    KW_XNOR = 16, KW_FILE = 17, KW_PURE = 18, KW_GUARDED = 19, KW_GENERIC = 20, 
    KW_RANGE = 21, KW_ELSE = 22, KW_USE = 23, KW_SHARED = 24, KW_MOD = 25, 
    KW_LOOP = 26, KW_RECORD = 27, KW_SIGNAL = 28, KW_REJECT = 29, KW_BEGIN = 30, 
    KW_SLA = 31, KW_DISCONNECT = 32, KW_OF = 33, KW_PROCEDURE = 34, KW_SRL = 35, 
    KW_VUNIT = 36, KW_ATTRIBUTE = 37, KW_VARIABLE = 38, KW_PROPERTY = 39, 
    KW_UNAFFECTED = 40, KW_XOR = 41, KW_REGISTER = 42, KW_SUBTYPE = 43, 
    KW_TO = 44, KW_NEW = 45, KW_REPORT = 46, KW_CONSTANT = 47, KW_BUFFER = 48, 
    KW_BODY = 49, KW_AFTER = 50, KW_TRANSPORT = 51, KW_FUNCTION = 52, KW_END = 53, 
    KW_SELECT = 54, KW_OR = 55, KW_LIBRARY = 56, KW_ELSIF = 57, KW_SLL = 58, 
    KW_MAP = 59, KW_SRA = 60, KW_PROTECTED = 61, KW_DOWNTO = 62, KW_LABEL = 63, 
    KW_ALL = 64, KW_ALIAS = 65, KW_GENERATE = 66, KW_NOR = 67, KW_IN = 68, 
    KW_RELEASE = 69, KW_EXIT = 70, KW_RETURN = 71, KW_WITH = 72, KW_UNTIL = 73, 
    KW_AND = 74, KW_INOUT = 75, KW_WAIT = 76, KW_NAND = 77, KW_ARRAY = 78, 
    KW_FORCE = 79, KW_WHILE = 80, KW_IMPURE = 81, KW_PACKAGE = 82, KW_UNITS = 83, 
    KW_ASSERT = 84, KW_PARAMETER = 85, KW_SEVERITY = 86, KW_LITERAL = 87, 
    KW_FOR = 88, KW_ROR = 89, KW_IF = 90, KW_OUT = 91, KW_ROL = 92, KW_IS = 93, 
    KW_SEQUENCE = 94, KW_OTHERS = 95, KW_TYPE = 96, KW_CASE = 97, KW_NOT = 98, 
    KW_CONFIGURATION = 99, KW_OPEN = 100, KW_ARCHITECTURE = 101, KW_BUS = 102, 
    KW_ACCESS = 103, KW_WHEN = 104, KW_PORT = 105, KW_NULL = 106, BASIC_IDENTIFIER = 107, 
    EXTENDED_IDENTIFIER = 108, DECIMAL_LITERAL = 109, INTEGER = 110, BASED_LITERAL = 111, 
    CHARACTER_LITERAL = 112, STRING_LITERAL = 113, BIT_STRING_LITERAL = 114, 
    COMMENT = 115, BLOCK_COMMENT = 116, TAB = 117, SPACE = 118, NEWLINE = 119, 
    CR = 120, SPACE_CHARACTER = 121, DBLQUOTE = 122, UNDERSCORE = 123, DIGIT = 124, 
    SEMI = 125, LPAREN = 126, RPAREN = 127, LSQUARE_BR = 128, RSQUARE_BR = 129, 
    APOSTROPHE = 130, SHIFT_LEFT = 131, SHIFT_RIGHT = 132, AT = 133, HASHTAG = 134, 
    COMMA = 135, DOT = 136, QUESTIONMARK = 137, COLON = 138, EQ = 139, NE = 140, 
    LT = 141, GT = 142, GE = 143, EQ_MATCH = 144, NE_MATCH = 145, LT_MATCH = 146, 
    LE_MATCH = 147, GT_MATCH = 148, GE_MATCH = 149, PLUS = 150, MINUS = 151, 
    AMPERSAND = 152, BAR = 153, BACKSLASH = 154, MUL = 155, DIV = 156, DOUBLESTAR = 157, 
    CONASGN = 158, GRAVE_ACCENT = 159, UP = 160, VARASGN = 161, BOX = 162, 
    ARROW = 163, COND_OP = 164
  };

  explicit vhdlLexer(antlr4::CharStream *input);

  ~vhdlLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.
  bool CHARACTER_LITERALSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};

}  // namespace mgp_vh
