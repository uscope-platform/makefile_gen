
// Generated from /home/fils/git/makefile_gen/grammars/sv2017Lexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


namespace mgp_sv {


class  sv2017Lexer : public antlr4::Lexer {
public:
  enum {
    KW_DOLAR_ERROR = 1, KW_DOLAR_FATAL = 2, KW_DOLAR_FULLSKEW = 3, KW_DOLAR_HOLD = 4, 
    KW_DOLAR_INFO = 5, KW_DOLAR_NOCHANGE = 6, KW_DOLAR_PERIOD = 7, KW_DOLAR_RECOVERY = 8, 
    KW_DOLAR_RECREM = 9, KW_DOLAR_REMOVAL = 10, KW_DOLAR_ROOT = 11, KW_DOLAR_SETUP = 12, 
    KW_DOLAR_SETUPHOLD = 13, KW_DOLAR_SKEW = 14, KW_DOLAR_TIMESKEW = 15, 
    KW_DOLAR_UNIT = 16, KW_DOLAR_WARNING = 17, KW_DOLAR_WIDTH = 18, KW_1STEP = 19, 
    KW_PATHPULSE_DOLAR = 20, KW_ACCEPT_ON = 21, KW_ALIAS = 22, KW_ALWAYS = 23, 
    KW_ALWAYS_COMB = 24, KW_ALWAYS_FF = 25, KW_ALWAYS_LATCH = 26, KW_AND = 27, 
    KW_ASSERT = 28, KW_ASSIGN = 29, KW_ASSUME = 30, KW_AUTOMATIC = 31, KW_BEFORE = 32, 
    KW_BEGIN = 33, KW_BIND = 34, KW_BINS = 35, KW_BINSOF = 36, KW_BIT = 37, 
    KW_BREAK = 38, KW_BUF = 39, KW_BUFIF0 = 40, KW_BUFIF1 = 41, KW_BYTE = 42, 
    KW_CASE = 43, KW_CASEX = 44, KW_CASEZ = 45, KW_CELL = 46, KW_CHANDLE = 47, 
    KW_CHECKER = 48, KW_CLASS = 49, KW_CLOCKING = 50, KW_CMOS = 51, KW_CONFIG = 52, 
    KW_CONST = 53, KW_CONSTRAINT = 54, KW_CONTEXT = 55, KW_CONTINUE = 56, 
    KW_COVER = 57, KW_COVERGROUP = 58, KW_COVERPOINT = 59, KW_CROSS = 60, 
    KW_DEASSIGN = 61, KW_DEFAULT = 62, KW_DEFPARAM = 63, KW_DESIGN = 64, 
    KW_DISABLE = 65, KW_DIST = 66, KW_DO = 67, KW_EDGE = 68, KW_ELSE = 69, 
    KW_END = 70, KW_ENDCASE = 71, KW_ENDCHECKER = 72, KW_ENDCLASS = 73, 
    KW_ENDCLOCKING = 74, KW_ENDCONFIG = 75, KW_ENDFUNCTION = 76, KW_ENDGENERATE = 77, 
    KW_ENDGROUP = 78, KW_ENDINTERFACE = 79, KW_ENDMODULE = 80, KW_ENDPACKAGE = 81, 
    KW_ENDPRIMITIVE = 82, KW_ENDPROGRAM = 83, KW_ENDPROPERTY = 84, KW_ENDSEQUENCE = 85, 
    KW_ENDSPECIFY = 86, KW_ENDTABLE = 87, KW_ENDTASK = 88, KW_ENUM = 89, 
    KW_EVENT = 90, KW_EVENTUALLY = 91, KW_EXPECT = 92, KW_EXPORT = 93, KW_EXTENDS = 94, 
    KW_EXTERN = 95, KW_FINAL = 96, KW_FIRST_MATCH = 97, KW_FOR = 98, KW_FORCE = 99, 
    KW_FOREACH = 100, KW_FOREVER = 101, KW_FORK = 102, KW_FORKJOIN = 103, 
    KW_FUNCTION = 104, KW_GENERATE = 105, KW_GENVAR = 106, KW_GLOBAL = 107, 
    KW_HIGHZ0 = 108, KW_HIGHZ1 = 109, KW_IF = 110, KW_IFF = 111, KW_IFNONE = 112, 
    KW_IGNORE_BINS = 113, KW_ILLEGAL_BINS = 114, KW_IMPLEMENTS = 115, KW_IMPLIES = 116, 
    KW_IMPORT = 117, KW_INCDIR = 118, KW_INCLUDE = 119, KW_INITIAL = 120, 
    KW_INOUT = 121, KW_INPUT = 122, KW_INSIDE = 123, KW_INSTANCE = 124, 
    KW_INT = 125, KW_INTEGER = 126, KW_INTERCONNECT = 127, KW_INTERFACE = 128, 
    KW_INTERSECT = 129, KW_JOIN = 130, KW_JOIN_ANY = 131, KW_JOIN_NONE = 132, 
    KW_LARGE = 133, KW_LET = 134, KW_LIBRARY = 135, KW_LIBLIST = 136, KW_LOCAL = 137, 
    KW_LOCALPARAM = 138, KW_LOGIC = 139, KW_LONGINT = 140, KW_MACROMODULE = 141, 
    KW_MATCHES = 142, KW_MEDIUM = 143, KW_MODPORT = 144, KW_MODULE = 145, 
    KW_NAND = 146, KW_NEGEDGE = 147, KW_NETTYPE = 148, KW_NEW = 149, KW_NEXTTIME = 150, 
    KW_NMOS = 151, KW_NOR = 152, KW_NOSHOWCANCELLED = 153, KW_NOT = 154, 
    KW_NOTIF0 = 155, KW_NOTIF1 = 156, KW_NULL = 157, KW_OPTION = 158, KW_OR = 159, 
    KW_OUTPUT = 160, KW_PACKAGE = 161, KW_PACKED = 162, KW_PARAMETER = 163, 
    KW_PMOS = 164, KW_POSEDGE = 165, KW_PRIMITIVE = 166, KW_PRIORITY = 167, 
    KW_PROGRAM = 168, KW_PROPERTY = 169, KW_PROTECTED = 170, KW_PULL0 = 171, 
    KW_PULL1 = 172, KW_PULLDOWN = 173, KW_PULLUP = 174, KW_PULSESTYLE_ONDETECT = 175, 
    KW_PULSESTYLE_ONEVENT = 176, KW_PURE = 177, KW_RAND = 178, KW_RANDC = 179, 
    KW_RANDCASE = 180, KW_RANDOMIZE = 181, KW_RANDSEQUENCE = 182, KW_RCMOS = 183, 
    KW_REAL = 184, KW_REALTIME = 185, KW_REF = 186, KW_REG = 187, KW_REJECT_ON = 188, 
    KW_RELEASE = 189, KW_REPEAT = 190, KW_RESTRICT = 191, KW_RETURN = 192, 
    KW_RNMOS = 193, KW_RPMOS = 194, KW_RTRAN = 195, KW_RTRANIF0 = 196, KW_RTRANIF1 = 197, 
    KW_S_ALWAYS = 198, KW_S_EVENTUALLY = 199, KW_S_NEXTTIME = 200, KW_S_UNTIL = 201, 
    KW_S_UNTIL_WITH = 202, KW_SAMPLE = 203, KW_SCALARED = 204, KW_SEQUENCE = 205, 
    KW_SHORTINT = 206, KW_SHORTREAL = 207, KW_SHOWCANCELLED = 208, KW_SIGNED = 209, 
    KW_SMALL = 210, KW_SOFT = 211, KW_SOLVE = 212, KW_SPECIFY = 213, KW_SPECPARAM = 214, 
    KW_STATIC = 215, KW_STD = 216, KW_STRING = 217, KW_STRONG = 218, KW_STRONG0 = 219, 
    KW_STRONG1 = 220, KW_STRUCT = 221, KW_SUPER = 222, KW_SUPPLY0 = 223, 
    KW_SUPPLY1 = 224, KW_SYNC_ACCEPT_ON = 225, KW_SYNC_REJECT_ON = 226, 
    KW_TABLE = 227, KW_TAGGED = 228, KW_TASK = 229, KW_THIS = 230, KW_THROUGHOUT = 231, 
    KW_TIME = 232, KW_TIMEPRECISION = 233, KW_TIMEUNIT = 234, KW_TRAN = 235, 
    KW_TRANIF0 = 236, KW_TRANIF1 = 237, KW_TRI = 238, KW_TRI0 = 239, KW_TRI1 = 240, 
    KW_TRIAND = 241, KW_TRIOR = 242, KW_TRIREG = 243, KW_TYPE = 244, KW_TYPE_OPTION = 245, 
    KW_TYPEDEF = 246, KW_UNION = 247, KW_UNIQUE = 248, KW_UNIQUE0 = 249, 
    KW_UNSIGNED = 250, KW_UNTIL = 251, KW_UNTIL_WITH = 252, KW_UNTYPED = 253, 
    KW_USE = 254, KW_UWIRE = 255, KW_VAR = 256, KW_VECTORED = 257, KW_VIRTUAL = 258, 
    KW_VOID = 259, KW_WAIT = 260, KW_WAIT_ORDER = 261, KW_WAND = 262, KW_WEAK = 263, 
    KW_WEAK0 = 264, KW_WEAK1 = 265, KW_WHILE = 266, KW_WILDCARD = 267, KW_WIRE = 268, 
    KW_WITH = 269, KW_WITHIN = 270, KW_WOR = 271, KW_XNOR = 272, KW_XOR = 273, 
    EDGE_CONTROL_SPECIFIER = 274, TIME_LITERAL = 275, ANY_BASED_NUMBER = 276, 
    BASED_NUMBER_WITH_SIZE = 277, REAL_NUMBER_WITH_EXP = 278, FIXED_POINT_NUMBER = 279, 
    UNSIGNED_NUMBER = 280, UNBASED_UNSIZED_LITERAL = 281, STRING_LITERAL = 282, 
    C_IDENTIFIER = 283, ESCAPED_IDENTIFIER = 284, SIMPLE_IDENTIFIER = 285, 
    SYSTEM_TF_IDENTIFIER = 286, SEMI = 287, LPAREN = 288, RPAREN = 289, 
    LSQUARE_BR = 290, RSQUARE_BR = 291, LBRACE = 292, RBRACE = 293, APOSTROPHE = 294, 
    APOSTROPHE_LBRACE = 295, SHIFT_LEFT = 296, SHIFT_RIGHT = 297, ARITH_SHIFT_LEFT = 298, 
    ARITH_SHIFT_RIGHT = 299, DOLAR = 300, MOD = 301, NOT = 302, NEG = 303, 
    NAND = 304, NOR = 305, XOR = 306, NXOR = 307, XORN = 308, COMMA = 309, 
    DOT = 310, QUESTIONMARK = 311, COLON = 312, DOUBLE_COLON = 313, EQ = 314, 
    NE = 315, CASE_EQ = 316, CASE_NE = 317, WILDCARD_EQ = 318, WILDCARD_NE = 319, 
    ASSIGN = 320, LT = 321, GT = 322, GE = 323, LE = 324, PLUS_ASSIGN = 325, 
    MINUS_ASSIGN = 326, MUL_ASSIGN = 327, DIV_ASSIGN = 328, MOD_ASSIGN = 329, 
    AND_ASSIGN = 330, OR_ASSIGN = 331, XOR_ASSIGN = 332, SHIFT_LEFT_ASSIGN = 333, 
    SHIFT_RIGHT_ASSIGN = 334, ARITH_SHIFT_LEFT_ASSIGN = 335, ARITH_SHIFT_RIGHT_ASSIGN = 336, 
    PLUS = 337, MINUS = 338, AMPERSAND = 339, AND_LOG = 340, BAR = 341, 
    OR_LOG = 342, BACKSLASH = 343, MUL = 344, DIV = 345, DOUBLESTAR = 346, 
    BI_DIR_ARROW = 347, ARROW = 348, DOUBLE_RIGHT_ARROW = 349, INCR = 350, 
    DECR = 351, DIST_WEIGHT_ASSIGN = 352, OVERLAPPING_IMPL = 353, NONOVERLAPPING_IMPL = 354, 
    IMPLIES = 355, IMPLIES_P = 356, IMPLIES_N = 357, PATH_FULL = 358, HASH_MINUS_HASH = 359, 
    HASH_EQ_HASH = 360, AT = 361, DOUBLE_AT = 362, HASH = 363, DOUBLE_HASH = 364, 
    TRIPLE_AND = 365, ONE_LINE_COMMENT = 366, DOCUMENTATION_COMMENT = 367, 
    BLOCK_COMMENT = 368, WHITE_SPACE = 369, LEVEL_SYMBOL = 370, EDGE_SYMBOL = 371
  };

  enum {
    DOCUMENTATION_CHANNEL = 2
  };

  enum {
    TABLE_MODE = 1
  };

  explicit sv2017Lexer(antlr4::CharStream *input);

  ~sv2017Lexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace mgp_sv
