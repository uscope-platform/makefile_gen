
// Generated from /home/fils/git/makefilegen_v2/grammars/vhdlParser.g4 by ANTLR 4.9.2


#include "vhdlParserListener.h"
#include "vhdlParserVisitor.h"

#include "vhdlParser.h"


using namespace antlrcpp;
using namespace mgp_vh;
using namespace antlr4;

vhdlParser::vhdlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

vhdlParser::~vhdlParser() {
  delete _interpreter;
}

std::string vhdlParser::getGrammarFileName() const {
  return "vhdlParser.g4";
}

const std::vector<std::string>& vhdlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& vhdlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Any_keywordContext ------------------------------------------------------------------

vhdlParser::Any_keywordContext::Any_keywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_PROCESS() {
  return getToken(vhdlParser::KW_PROCESS, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_CONTEXT() {
  return getToken(vhdlParser::KW_CONTEXT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_POSTPONED() {
  return getToken(vhdlParser::KW_POSTPONED, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_LINKAGE() {
  return getToken(vhdlParser::KW_LINKAGE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_COMPONENT() {
  return getToken(vhdlParser::KW_COMPONENT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ABS() {
  return getToken(vhdlParser::KW_ABS, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_DEFAULT() {
  return getToken(vhdlParser::KW_DEFAULT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_THEN() {
  return getToken(vhdlParser::KW_THEN, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_BLOCK() {
  return getToken(vhdlParser::KW_BLOCK, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_REM() {
  return getToken(vhdlParser::KW_REM, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_INERTIAL() {
  return getToken(vhdlParser::KW_INERTIAL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_NEXT() {
  return getToken(vhdlParser::KW_NEXT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ENTITY() {
  return getToken(vhdlParser::KW_ENTITY, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ON() {
  return getToken(vhdlParser::KW_ON, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_GROUP() {
  return getToken(vhdlParser::KW_GROUP, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_XNOR() {
  return getToken(vhdlParser::KW_XNOR, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_FILE() {
  return getToken(vhdlParser::KW_FILE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_PURE() {
  return getToken(vhdlParser::KW_PURE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_GUARDED() {
  return getToken(vhdlParser::KW_GUARDED, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_GENERIC() {
  return getToken(vhdlParser::KW_GENERIC, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_RANGE() {
  return getToken(vhdlParser::KW_RANGE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ELSE() {
  return getToken(vhdlParser::KW_ELSE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_USE() {
  return getToken(vhdlParser::KW_USE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SHARED() {
  return getToken(vhdlParser::KW_SHARED, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_MOD() {
  return getToken(vhdlParser::KW_MOD, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_LOOP() {
  return getToken(vhdlParser::KW_LOOP, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_RECORD() {
  return getToken(vhdlParser::KW_RECORD, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SIGNAL() {
  return getToken(vhdlParser::KW_SIGNAL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_REJECT() {
  return getToken(vhdlParser::KW_REJECT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_BEGIN() {
  return getToken(vhdlParser::KW_BEGIN, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SLA() {
  return getToken(vhdlParser::KW_SLA, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_DISCONNECT() {
  return getToken(vhdlParser::KW_DISCONNECT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_OF() {
  return getToken(vhdlParser::KW_OF, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_PROCEDURE() {
  return getToken(vhdlParser::KW_PROCEDURE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SRL() {
  return getToken(vhdlParser::KW_SRL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_VUNIT() {
  return getToken(vhdlParser::KW_VUNIT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ATTRIBUTE() {
  return getToken(vhdlParser::KW_ATTRIBUTE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_VARIABLE() {
  return getToken(vhdlParser::KW_VARIABLE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_PROPERTY() {
  return getToken(vhdlParser::KW_PROPERTY, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_UNAFFECTED() {
  return getToken(vhdlParser::KW_UNAFFECTED, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_XOR() {
  return getToken(vhdlParser::KW_XOR, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_REGISTER() {
  return getToken(vhdlParser::KW_REGISTER, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SUBTYPE() {
  return getToken(vhdlParser::KW_SUBTYPE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_TO() {
  return getToken(vhdlParser::KW_TO, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_NEW() {
  return getToken(vhdlParser::KW_NEW, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_REPORT() {
  return getToken(vhdlParser::KW_REPORT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_CONSTANT() {
  return getToken(vhdlParser::KW_CONSTANT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_BUFFER() {
  return getToken(vhdlParser::KW_BUFFER, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_BODY() {
  return getToken(vhdlParser::KW_BODY, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_AFTER() {
  return getToken(vhdlParser::KW_AFTER, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_TRANSPORT() {
  return getToken(vhdlParser::KW_TRANSPORT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_FUNCTION() {
  return getToken(vhdlParser::KW_FUNCTION, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SELECT() {
  return getToken(vhdlParser::KW_SELECT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_OR() {
  return getToken(vhdlParser::KW_OR, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_LIBRARY() {
  return getToken(vhdlParser::KW_LIBRARY, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ELSIF() {
  return getToken(vhdlParser::KW_ELSIF, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SLL() {
  return getToken(vhdlParser::KW_SLL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_MAP() {
  return getToken(vhdlParser::KW_MAP, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SRA() {
  return getToken(vhdlParser::KW_SRA, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_PROTECTED() {
  return getToken(vhdlParser::KW_PROTECTED, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_DOWNTO() {
  return getToken(vhdlParser::KW_DOWNTO, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_LABEL() {
  return getToken(vhdlParser::KW_LABEL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ALL() {
  return getToken(vhdlParser::KW_ALL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ALIAS() {
  return getToken(vhdlParser::KW_ALIAS, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_GENERATE() {
  return getToken(vhdlParser::KW_GENERATE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_NOR() {
  return getToken(vhdlParser::KW_NOR, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_IN() {
  return getToken(vhdlParser::KW_IN, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_RELEASE() {
  return getToken(vhdlParser::KW_RELEASE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_EXIT() {
  return getToken(vhdlParser::KW_EXIT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_RETURN() {
  return getToken(vhdlParser::KW_RETURN, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_WITH() {
  return getToken(vhdlParser::KW_WITH, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_UNTIL() {
  return getToken(vhdlParser::KW_UNTIL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_AND() {
  return getToken(vhdlParser::KW_AND, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_INOUT() {
  return getToken(vhdlParser::KW_INOUT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_WAIT() {
  return getToken(vhdlParser::KW_WAIT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_NAND() {
  return getToken(vhdlParser::KW_NAND, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ARRAY() {
  return getToken(vhdlParser::KW_ARRAY, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_FORCE() {
  return getToken(vhdlParser::KW_FORCE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_WHILE() {
  return getToken(vhdlParser::KW_WHILE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_IMPURE() {
  return getToken(vhdlParser::KW_IMPURE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_PACKAGE() {
  return getToken(vhdlParser::KW_PACKAGE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_UNITS() {
  return getToken(vhdlParser::KW_UNITS, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ASSERT() {
  return getToken(vhdlParser::KW_ASSERT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_PARAMETER() {
  return getToken(vhdlParser::KW_PARAMETER, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SEVERITY() {
  return getToken(vhdlParser::KW_SEVERITY, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_LITERAL() {
  return getToken(vhdlParser::KW_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_FOR() {
  return getToken(vhdlParser::KW_FOR, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ROR() {
  return getToken(vhdlParser::KW_ROR, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_IF() {
  return getToken(vhdlParser::KW_IF, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_OUT() {
  return getToken(vhdlParser::KW_OUT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ROL() {
  return getToken(vhdlParser::KW_ROL, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_SEQUENCE() {
  return getToken(vhdlParser::KW_SEQUENCE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_OTHERS() {
  return getToken(vhdlParser::KW_OTHERS, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_TYPE() {
  return getToken(vhdlParser::KW_TYPE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_CASE() {
  return getToken(vhdlParser::KW_CASE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_NOT() {
  return getToken(vhdlParser::KW_NOT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_CONFIGURATION() {
  return getToken(vhdlParser::KW_CONFIGURATION, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_OPEN() {
  return getToken(vhdlParser::KW_OPEN, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ARCHITECTURE() {
  return getToken(vhdlParser::KW_ARCHITECTURE, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_BUS() {
  return getToken(vhdlParser::KW_BUS, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_ACCESS() {
  return getToken(vhdlParser::KW_ACCESS, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_WHEN() {
  return getToken(vhdlParser::KW_WHEN, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_PORT() {
  return getToken(vhdlParser::KW_PORT, 0);
}

tree::TerminalNode* vhdlParser::Any_keywordContext::KW_NULL() {
  return getToken(vhdlParser::KW_NULL, 0);
}


size_t vhdlParser::Any_keywordContext::getRuleIndex() const {
  return vhdlParser::RuleAny_keyword;
}

void vhdlParser::Any_keywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_keyword(this);
}

void vhdlParser::Any_keywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_keyword(this);
}


antlrcpp::Any vhdlParser::Any_keywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAny_keyword(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Any_keywordContext* vhdlParser::any_keyword() {
  Any_keywordContext *_localctx = _tracker.createInstance<Any_keywordContext>(_ctx, getState());
  enterRule(_localctx, 0, vhdlParser::RuleAny_keyword);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(514);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_PROCESS)
      | (1ULL << vhdlParser::KW_CONTEXT)
      | (1ULL << vhdlParser::KW_POSTPONED)
      | (1ULL << vhdlParser::KW_LINKAGE)
      | (1ULL << vhdlParser::KW_COMPONENT)
      | (1ULL << vhdlParser::KW_ABS)
      | (1ULL << vhdlParser::KW_DEFAULT)
      | (1ULL << vhdlParser::KW_THEN)
      | (1ULL << vhdlParser::KW_BLOCK)
      | (1ULL << vhdlParser::KW_REM)
      | (1ULL << vhdlParser::KW_INERTIAL)
      | (1ULL << vhdlParser::KW_NEXT)
      | (1ULL << vhdlParser::KW_ENTITY)
      | (1ULL << vhdlParser::KW_ON)
      | (1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_XNOR)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_GUARDED)
      | (1ULL << vhdlParser::KW_GENERIC)
      | (1ULL << vhdlParser::KW_RANGE)
      | (1ULL << vhdlParser::KW_ELSE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_MOD)
      | (1ULL << vhdlParser::KW_LOOP)
      | (1ULL << vhdlParser::KW_RECORD)
      | (1ULL << vhdlParser::KW_SIGNAL)
      | (1ULL << vhdlParser::KW_REJECT)
      | (1ULL << vhdlParser::KW_BEGIN)
      | (1ULL << vhdlParser::KW_SLA)
      | (1ULL << vhdlParser::KW_DISCONNECT)
      | (1ULL << vhdlParser::KW_OF)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_SRL)
      | (1ULL << vhdlParser::KW_VUNIT)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_PROPERTY)
      | (1ULL << vhdlParser::KW_UNAFFECTED)
      | (1ULL << vhdlParser::KW_XOR)
      | (1ULL << vhdlParser::KW_REGISTER)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_TO)
      | (1ULL << vhdlParser::KW_NEW)
      | (1ULL << vhdlParser::KW_REPORT)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_BUFFER)
      | (1ULL << vhdlParser::KW_BODY)
      | (1ULL << vhdlParser::KW_AFTER)
      | (1ULL << vhdlParser::KW_TRANSPORT)
      | (1ULL << vhdlParser::KW_FUNCTION)
      | (1ULL << vhdlParser::KW_END)
      | (1ULL << vhdlParser::KW_SELECT)
      | (1ULL << vhdlParser::KW_OR)
      | (1ULL << vhdlParser::KW_LIBRARY)
      | (1ULL << vhdlParser::KW_ELSIF)
      | (1ULL << vhdlParser::KW_SLL)
      | (1ULL << vhdlParser::KW_MAP)
      | (1ULL << vhdlParser::KW_SRA)
      | (1ULL << vhdlParser::KW_PROTECTED)
      | (1ULL << vhdlParser::KW_DOWNTO)
      | (1ULL << vhdlParser::KW_LABEL))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (vhdlParser::KW_ALL - 64))
      | (1ULL << (vhdlParser::KW_ALIAS - 64))
      | (1ULL << (vhdlParser::KW_GENERATE - 64))
      | (1ULL << (vhdlParser::KW_NOR - 64))
      | (1ULL << (vhdlParser::KW_IN - 64))
      | (1ULL << (vhdlParser::KW_RELEASE - 64))
      | (1ULL << (vhdlParser::KW_EXIT - 64))
      | (1ULL << (vhdlParser::KW_RETURN - 64))
      | (1ULL << (vhdlParser::KW_WITH - 64))
      | (1ULL << (vhdlParser::KW_UNTIL - 64))
      | (1ULL << (vhdlParser::KW_AND - 64))
      | (1ULL << (vhdlParser::KW_INOUT - 64))
      | (1ULL << (vhdlParser::KW_WAIT - 64))
      | (1ULL << (vhdlParser::KW_NAND - 64))
      | (1ULL << (vhdlParser::KW_ARRAY - 64))
      | (1ULL << (vhdlParser::KW_FORCE - 64))
      | (1ULL << (vhdlParser::KW_WHILE - 64))
      | (1ULL << (vhdlParser::KW_IMPURE - 64))
      | (1ULL << (vhdlParser::KW_PACKAGE - 64))
      | (1ULL << (vhdlParser::KW_UNITS - 64))
      | (1ULL << (vhdlParser::KW_ASSERT - 64))
      | (1ULL << (vhdlParser::KW_PARAMETER - 64))
      | (1ULL << (vhdlParser::KW_SEVERITY - 64))
      | (1ULL << (vhdlParser::KW_LITERAL - 64))
      | (1ULL << (vhdlParser::KW_FOR - 64))
      | (1ULL << (vhdlParser::KW_ROR - 64))
      | (1ULL << (vhdlParser::KW_IF - 64))
      | (1ULL << (vhdlParser::KW_OUT - 64))
      | (1ULL << (vhdlParser::KW_ROL - 64))
      | (1ULL << (vhdlParser::KW_IS - 64))
      | (1ULL << (vhdlParser::KW_SEQUENCE - 64))
      | (1ULL << (vhdlParser::KW_OTHERS - 64))
      | (1ULL << (vhdlParser::KW_TYPE - 64))
      | (1ULL << (vhdlParser::KW_CASE - 64))
      | (1ULL << (vhdlParser::KW_NOT - 64))
      | (1ULL << (vhdlParser::KW_CONFIGURATION - 64))
      | (1ULL << (vhdlParser::KW_OPEN - 64))
      | (1ULL << (vhdlParser::KW_ARCHITECTURE - 64))
      | (1ULL << (vhdlParser::KW_BUS - 64))
      | (1ULL << (vhdlParser::KW_ACCESS - 64))
      | (1ULL << (vhdlParser::KW_WHEN - 64))
      | (1ULL << (vhdlParser::KW_PORT - 64))
      | (1ULL << (vhdlParser::KW_NULL - 64)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Name_literalContext ------------------------------------------------------------------

vhdlParser::Name_literalContext::Name_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Name_literalContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

vhdlParser::Operator_symbolContext* vhdlParser::Name_literalContext::operator_symbol() {
  return getRuleContext<vhdlParser::Operator_symbolContext>(0);
}

tree::TerminalNode* vhdlParser::Name_literalContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}


size_t vhdlParser::Name_literalContext::getRuleIndex() const {
  return vhdlParser::RuleName_literal;
}

void vhdlParser::Name_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName_literal(this);
}

void vhdlParser::Name_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName_literal(this);
}


antlrcpp::Any vhdlParser::Name_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitName_literal(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Name_literalContext* vhdlParser::name_literal() {
  Name_literalContext *_localctx = _tracker.createInstance<Name_literalContext>(_ctx, getState());
  enterRule(_localctx, 2, vhdlParser::RuleName_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(519);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(516);
        identifier();
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(517);
        operator_symbol();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(518);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

vhdlParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Name_literalContext* vhdlParser::NameContext::name_literal() {
  return getRuleContext<vhdlParser::Name_literalContext>(0);
}

vhdlParser::External_nameContext* vhdlParser::NameContext::external_name() {
  return getRuleContext<vhdlParser::External_nameContext>(0);
}

vhdlParser::NameContext* vhdlParser::NameContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

vhdlParser::Name_slice_partContext* vhdlParser::NameContext::name_slice_part() {
  return getRuleContext<vhdlParser::Name_slice_partContext>(0);
}

vhdlParser::Name_attribute_partContext* vhdlParser::NameContext::name_attribute_part() {
  return getRuleContext<vhdlParser::Name_attribute_partContext>(0);
}

vhdlParser::Association_listContext* vhdlParser::NameContext::association_list() {
  return getRuleContext<vhdlParser::Association_listContext>(0);
}

tree::TerminalNode* vhdlParser::NameContext::DOT() {
  return getToken(vhdlParser::DOT, 0);
}

vhdlParser::SuffixContext* vhdlParser::NameContext::suffix() {
  return getRuleContext<vhdlParser::SuffixContext>(0);
}


size_t vhdlParser::NameContext::getRuleIndex() const {
  return vhdlParser::RuleName;
}

void vhdlParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void vhdlParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}


antlrcpp::Any vhdlParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}


vhdlParser::NameContext* vhdlParser::name() {
   return name(0);
}

vhdlParser::NameContext* vhdlParser::name(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  vhdlParser::NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, parentState);
  vhdlParser::NameContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, vhdlParser::RuleName, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(524);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL: {
        setState(522);
        name_literal();
        break;
      }

      case vhdlParser::SHIFT_LEFT: {
        setState(523);
        external_name();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(536);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<NameContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleName);
        setState(526);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(532);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          setState(527);
          name_slice_part();
          break;
        }

        case 2: {
          setState(528);
          name_attribute_part();
          break;
        }

        case 3: {
          setState(529);
          association_list();
          break;
        }

        case 4: {
          setState(530);
          match(vhdlParser::DOT);
          setState(531);
          suffix();
          break;
        }

        default:
          break;
        } 
      }
      setState(538);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Name_slice_partContext ------------------------------------------------------------------

vhdlParser::Name_slice_partContext::Name_slice_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Name_slice_partContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Explicit_rangeContext* vhdlParser::Name_slice_partContext::explicit_range() {
  return getRuleContext<vhdlParser::Explicit_rangeContext>(0);
}

tree::TerminalNode* vhdlParser::Name_slice_partContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Name_slice_partContext::getRuleIndex() const {
  return vhdlParser::RuleName_slice_part;
}

void vhdlParser::Name_slice_partContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName_slice_part(this);
}

void vhdlParser::Name_slice_partContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName_slice_part(this);
}


antlrcpp::Any vhdlParser::Name_slice_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitName_slice_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Name_slice_partContext* vhdlParser::name_slice_part() {
  Name_slice_partContext *_localctx = _tracker.createInstance<Name_slice_partContext>(_ctx, getState());
  enterRule(_localctx, 6, vhdlParser::RuleName_slice_part);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(539);
    match(vhdlParser::LPAREN);
    setState(540);
    explicit_range();
    setState(541);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Name_attribute_partContext ------------------------------------------------------------------

vhdlParser::Name_attribute_partContext::Name_attribute_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Name_attribute_partContext::APOSTROPHE() {
  return getToken(vhdlParser::APOSTROPHE, 0);
}

vhdlParser::Attribute_designatorContext* vhdlParser::Name_attribute_partContext::attribute_designator() {
  return getRuleContext<vhdlParser::Attribute_designatorContext>(0);
}

vhdlParser::SignatureContext* vhdlParser::Name_attribute_partContext::signature() {
  return getRuleContext<vhdlParser::SignatureContext>(0);
}


size_t vhdlParser::Name_attribute_partContext::getRuleIndex() const {
  return vhdlParser::RuleName_attribute_part;
}

void vhdlParser::Name_attribute_partContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName_attribute_part(this);
}

void vhdlParser::Name_attribute_partContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName_attribute_part(this);
}


antlrcpp::Any vhdlParser::Name_attribute_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitName_attribute_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Name_attribute_partContext* vhdlParser::name_attribute_part() {
  Name_attribute_partContext *_localctx = _tracker.createInstance<Name_attribute_partContext>(_ctx, getState());
  enterRule(_localctx, 8, vhdlParser::RuleName_attribute_part);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(544);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LSQUARE_BR) {
      setState(543);
      signature();
    }
    setState(546);
    match(vhdlParser::APOSTROPHE);
    setState(547);
    attribute_designator();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attribute_nameContext ------------------------------------------------------------------

vhdlParser::Attribute_nameContext::Attribute_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Attribute_nameContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

vhdlParser::Name_attribute_partContext* vhdlParser::Attribute_nameContext::name_attribute_part() {
  return getRuleContext<vhdlParser::Name_attribute_partContext>(0);
}


size_t vhdlParser::Attribute_nameContext::getRuleIndex() const {
  return vhdlParser::RuleAttribute_name;
}

void vhdlParser::Attribute_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute_name(this);
}

void vhdlParser::Attribute_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute_name(this);
}


antlrcpp::Any vhdlParser::Attribute_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAttribute_name(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Attribute_nameContext* vhdlParser::attribute_name() {
  Attribute_nameContext *_localctx = _tracker.createInstance<Attribute_nameContext>(_ctx, getState());
  enterRule(_localctx, 10, vhdlParser::RuleAttribute_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(549);
    name(0);
    setState(550);
    name_attribute_part();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuffixContext ------------------------------------------------------------------

vhdlParser::SuffixContext::SuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Name_literalContext* vhdlParser::SuffixContext::name_literal() {
  return getRuleContext<vhdlParser::Name_literalContext>(0);
}

tree::TerminalNode* vhdlParser::SuffixContext::KW_ALL() {
  return getToken(vhdlParser::KW_ALL, 0);
}


size_t vhdlParser::SuffixContext::getRuleIndex() const {
  return vhdlParser::RuleSuffix;
}

void vhdlParser::SuffixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuffix(this);
}

void vhdlParser::SuffixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuffix(this);
}


antlrcpp::Any vhdlParser::SuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSuffix(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::SuffixContext* vhdlParser::suffix() {
  SuffixContext *_localctx = _tracker.createInstance<SuffixContext>(_ctx, getState());
  enterRule(_localctx, 12, vhdlParser::RuleSuffix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(554);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(552);
        name_literal();
        break;
      }

      case vhdlParser::KW_ALL: {
        enterOuterAlt(_localctx, 2);
        setState(553);
        match(vhdlParser::KW_ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Explicit_rangeContext ------------------------------------------------------------------

vhdlParser::Explicit_rangeContext::Explicit_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Simple_expressionContext *> vhdlParser::Explicit_rangeContext::simple_expression() {
  return getRuleContexts<vhdlParser::Simple_expressionContext>();
}

vhdlParser::Simple_expressionContext* vhdlParser::Explicit_rangeContext::simple_expression(size_t i) {
  return getRuleContext<vhdlParser::Simple_expressionContext>(i);
}

vhdlParser::DirectionContext* vhdlParser::Explicit_rangeContext::direction() {
  return getRuleContext<vhdlParser::DirectionContext>(0);
}


size_t vhdlParser::Explicit_rangeContext::getRuleIndex() const {
  return vhdlParser::RuleExplicit_range;
}

void vhdlParser::Explicit_rangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicit_range(this);
}

void vhdlParser::Explicit_rangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicit_range(this);
}


antlrcpp::Any vhdlParser::Explicit_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitExplicit_range(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Explicit_rangeContext* vhdlParser::explicit_range() {
  Explicit_rangeContext *_localctx = _tracker.createInstance<Explicit_rangeContext>(_ctx, getState());
  enterRule(_localctx, 14, vhdlParser::RuleExplicit_range);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(556);
    simple_expression(0);
    setState(557);
    direction();
    setState(558);
    simple_expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_nameContext ------------------------------------------------------------------

vhdlParser::Selected_nameContext::Selected_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Selected_nameContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Selected_nameContext::DOT() {
  return getTokens(vhdlParser::DOT);
}

tree::TerminalNode* vhdlParser::Selected_nameContext::DOT(size_t i) {
  return getToken(vhdlParser::DOT, i);
}

std::vector<vhdlParser::SuffixContext *> vhdlParser::Selected_nameContext::suffix() {
  return getRuleContexts<vhdlParser::SuffixContext>();
}

vhdlParser::SuffixContext* vhdlParser::Selected_nameContext::suffix(size_t i) {
  return getRuleContext<vhdlParser::SuffixContext>(i);
}


size_t vhdlParser::Selected_nameContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_name;
}

void vhdlParser::Selected_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelected_name(this);
}

void vhdlParser::Selected_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelected_name(this);
}


antlrcpp::Any vhdlParser::Selected_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSelected_name(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_nameContext* vhdlParser::selected_name() {
  Selected_nameContext *_localctx = _tracker.createInstance<Selected_nameContext>(_ctx, getState());
  enterRule(_localctx, 16, vhdlParser::RuleSelected_name);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(560);
    identifier();
    setState(565);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::DOT) {
      setState(561);
      match(vhdlParser::DOT);
      setState(562);
      suffix();
      setState(567);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_declarationContext ------------------------------------------------------------------

vhdlParser::Entity_declarationContext::Entity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Entity_declarationContext::KW_ENTITY() {
  return getTokens(vhdlParser::KW_ENTITY);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::KW_ENTITY(size_t i) {
  return getToken(vhdlParser::KW_ENTITY, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Entity_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Entity_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Generic_clauseContext* vhdlParser::Entity_declarationContext::generic_clause() {
  return getRuleContext<vhdlParser::Generic_clauseContext>(0);
}

vhdlParser::Port_clauseContext* vhdlParser::Entity_declarationContext::port_clause() {
  return getRuleContext<vhdlParser::Port_clauseContext>(0);
}

std::vector<vhdlParser::Entity_declarative_itemContext *> vhdlParser::Entity_declarationContext::entity_declarative_item() {
  return getRuleContexts<vhdlParser::Entity_declarative_itemContext>();
}

vhdlParser::Entity_declarative_itemContext* vhdlParser::Entity_declarationContext::entity_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Entity_declarative_itemContext>(i);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::KW_BEGIN() {
  return getToken(vhdlParser::KW_BEGIN, 0);
}

std::vector<vhdlParser::Entity_statementContext *> vhdlParser::Entity_declarationContext::entity_statement() {
  return getRuleContexts<vhdlParser::Entity_statementContext>();
}

vhdlParser::Entity_statementContext* vhdlParser::Entity_declarationContext::entity_statement(size_t i) {
  return getRuleContext<vhdlParser::Entity_statementContext>(i);
}


size_t vhdlParser::Entity_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_declaration;
}

void vhdlParser::Entity_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_declaration(this);
}

void vhdlParser::Entity_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_declaration(this);
}


antlrcpp::Any vhdlParser::Entity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_declarationContext* vhdlParser::entity_declaration() {
  Entity_declarationContext *_localctx = _tracker.createInstance<Entity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 18, vhdlParser::RuleEntity_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    match(vhdlParser::KW_ENTITY);
    setState(569);
    identifier();
    setState(570);
    match(vhdlParser::KW_IS);
    setState(572);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(571);
      generic_clause();
    }
    setState(575);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PORT) {
      setState(574);
      port_clause();
    }
    setState(580);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_SIGNAL)
      | (1ULL << vhdlParser::KW_DISCONNECT)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
      | (1ULL << (vhdlParser::KW_IMPURE - 65))
      | (1ULL << (vhdlParser::KW_PACKAGE - 65))
      | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
      setState(577);
      entity_declarative_item();
      setState(582);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(590);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_BEGIN) {
      setState(583);
      match(vhdlParser::KW_BEGIN);
      setState(587);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == vhdlParser::KW_PROCESS

      || _la == vhdlParser::KW_POSTPONED || ((((_la - 84) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 84)) & ((1ULL << (vhdlParser::KW_ASSERT - 84))
        | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 84))
        | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 84))
        | (1ULL << (vhdlParser::CHARACTER_LITERAL - 84))
        | (1ULL << (vhdlParser::STRING_LITERAL - 84))
        | (1ULL << (vhdlParser::SHIFT_LEFT - 84)))) != 0)) {
        setState(584);
        entity_statement();
        setState(589);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(592);
    match(vhdlParser::KW_END);
    setState(594);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_ENTITY) {
      setState(593);
      match(vhdlParser::KW_ENTITY);
    }
    setState(597);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(596);
      identifier();
    }
    setState(599);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Entity_declarative_itemContext::Entity_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Signal_declarationContext* vhdlParser::Entity_declarative_itemContext::signal_declaration() {
  return getRuleContext<vhdlParser::Signal_declarationContext>(0);
}

vhdlParser::Process_declarative_itemContext* vhdlParser::Entity_declarative_itemContext::process_declarative_item() {
  return getRuleContext<vhdlParser::Process_declarative_itemContext>(0);
}

vhdlParser::Disconnection_specificationContext* vhdlParser::Entity_declarative_itemContext::disconnection_specification() {
  return getRuleContext<vhdlParser::Disconnection_specificationContext>(0);
}


size_t vhdlParser::Entity_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_declarative_item;
}

void vhdlParser::Entity_declarative_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_declarative_item(this);
}

void vhdlParser::Entity_declarative_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_declarative_item(this);
}


antlrcpp::Any vhdlParser::Entity_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_declarative_itemContext* vhdlParser::entity_declarative_item() {
  Entity_declarative_itemContext *_localctx = _tracker.createInstance<Entity_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 20, vhdlParser::RuleEntity_declarative_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(604);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_SIGNAL: {
        enterOuterAlt(_localctx, 1);
        setState(601);
        signal_declaration();
        break;
      }

      case vhdlParser::KW_GROUP:
      case vhdlParser::KW_FILE:
      case vhdlParser::KW_PURE:
      case vhdlParser::KW_USE:
      case vhdlParser::KW_SHARED:
      case vhdlParser::KW_PROCEDURE:
      case vhdlParser::KW_ATTRIBUTE:
      case vhdlParser::KW_VARIABLE:
      case vhdlParser::KW_SUBTYPE:
      case vhdlParser::KW_CONSTANT:
      case vhdlParser::KW_FUNCTION:
      case vhdlParser::KW_ALIAS:
      case vhdlParser::KW_IMPURE:
      case vhdlParser::KW_PACKAGE:
      case vhdlParser::KW_TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(602);
        process_declarative_item();
        break;
      }

      case vhdlParser::KW_DISCONNECT: {
        enterOuterAlt(_localctx, 3);
        setState(603);
        disconnection_specification();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_statementContext ------------------------------------------------------------------

vhdlParser::Entity_statementContext::Entity_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Concurrent_assertion_statementContext* vhdlParser::Entity_statementContext::concurrent_assertion_statement() {
  return getRuleContext<vhdlParser::Concurrent_assertion_statementContext>(0);
}

vhdlParser::Concurrent_procedure_call_statementContext* vhdlParser::Entity_statementContext::concurrent_procedure_call_statement() {
  return getRuleContext<vhdlParser::Concurrent_procedure_call_statementContext>(0);
}

vhdlParser::Process_statementContext* vhdlParser::Entity_statementContext::process_statement() {
  return getRuleContext<vhdlParser::Process_statementContext>(0);
}

vhdlParser::LabelContext* vhdlParser::Entity_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_statementContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}


size_t vhdlParser::Entity_statementContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_statement;
}

void vhdlParser::Entity_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_statement(this);
}

void vhdlParser::Entity_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_statement(this);
}


antlrcpp::Any vhdlParser::Entity_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_statementContext* vhdlParser::entity_statement() {
  Entity_statementContext *_localctx = _tracker.createInstance<Entity_statementContext>(_ctx, getState());
  enterRule(_localctx, 22, vhdlParser::RuleEntity_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(609);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(606);
      label();
      setState(607);
      match(vhdlParser::COLON);
      break;
    }

    default:
      break;
    }
    setState(614);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(611);
      concurrent_assertion_statement();
      break;
    }

    case 2: {
      setState(612);
      concurrent_procedure_call_statement();
      break;
    }

    case 3: {
      setState(613);
      process_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Architecture_bodyContext ------------------------------------------------------------------

vhdlParser::Architecture_bodyContext::Architecture_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Architecture_bodyContext::KW_ARCHITECTURE() {
  return getTokens(vhdlParser::KW_ARCHITECTURE);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::KW_ARCHITECTURE(size_t i) {
  return getToken(vhdlParser::KW_ARCHITECTURE, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Architecture_bodyContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Architecture_bodyContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::KW_OF() {
  return getToken(vhdlParser::KW_OF, 0);
}

vhdlParser::NameContext* vhdlParser::Architecture_bodyContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::KW_BEGIN() {
  return getToken(vhdlParser::KW_BEGIN, 0);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<vhdlParser::Block_declarative_itemContext *> vhdlParser::Architecture_bodyContext::block_declarative_item() {
  return getRuleContexts<vhdlParser::Block_declarative_itemContext>();
}

vhdlParser::Block_declarative_itemContext* vhdlParser::Architecture_bodyContext::block_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Block_declarative_itemContext>(i);
}

std::vector<vhdlParser::Concurrent_statementContext *> vhdlParser::Architecture_bodyContext::concurrent_statement() {
  return getRuleContexts<vhdlParser::Concurrent_statementContext>();
}

vhdlParser::Concurrent_statementContext* vhdlParser::Architecture_bodyContext::concurrent_statement(size_t i) {
  return getRuleContext<vhdlParser::Concurrent_statementContext>(i);
}


size_t vhdlParser::Architecture_bodyContext::getRuleIndex() const {
  return vhdlParser::RuleArchitecture_body;
}

void vhdlParser::Architecture_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArchitecture_body(this);
}

void vhdlParser::Architecture_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArchitecture_body(this);
}


antlrcpp::Any vhdlParser::Architecture_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitArchitecture_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Architecture_bodyContext* vhdlParser::architecture_body() {
  Architecture_bodyContext *_localctx = _tracker.createInstance<Architecture_bodyContext>(_ctx, getState());
  enterRule(_localctx, 24, vhdlParser::RuleArchitecture_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(616);
    match(vhdlParser::KW_ARCHITECTURE);
    setState(617);
    identifier();
    setState(618);
    match(vhdlParser::KW_OF);
    setState(619);
    name(0);
    setState(620);
    match(vhdlParser::KW_IS);
    setState(624);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_COMPONENT)
      | (1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_SIGNAL)
      | (1ULL << vhdlParser::KW_DISCONNECT)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
      | (1ULL << (vhdlParser::KW_IMPURE - 65))
      | (1ULL << (vhdlParser::KW_PACKAGE - 65))
      | (1ULL << (vhdlParser::KW_FOR - 65))
      | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
      setState(621);
      block_declarative_item();
      setState(626);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(627);
    match(vhdlParser::KW_BEGIN);
    setState(631);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::KW_PROCESS

    || _la == vhdlParser::KW_POSTPONED || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (vhdlParser::KW_WITH - 72))
      | (1ULL << (vhdlParser::KW_ASSERT - 72))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 72))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 72))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 72))
      | (1ULL << (vhdlParser::STRING_LITERAL - 72))
      | (1ULL << (vhdlParser::LPAREN - 72))
      | (1ULL << (vhdlParser::SHIFT_LEFT - 72)))) != 0)) {
      setState(628);
      concurrent_statement();
      setState(633);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(634);
    match(vhdlParser::KW_END);
    setState(636);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_ARCHITECTURE) {
      setState(635);
      match(vhdlParser::KW_ARCHITECTURE);
    }
    setState(639);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(638);
      identifier();
    }
    setState(641);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Block_declarative_itemContext::Block_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_declarative_itemContext* vhdlParser::Block_declarative_itemContext::entity_declarative_item() {
  return getRuleContext<vhdlParser::Entity_declarative_itemContext>(0);
}

vhdlParser::Component_declarationContext* vhdlParser::Block_declarative_itemContext::component_declaration() {
  return getRuleContext<vhdlParser::Component_declarationContext>(0);
}

vhdlParser::Configuration_specificationContext* vhdlParser::Block_declarative_itemContext::configuration_specification() {
  return getRuleContext<vhdlParser::Configuration_specificationContext>(0);
}


size_t vhdlParser::Block_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_declarative_item;
}

void vhdlParser::Block_declarative_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_declarative_item(this);
}

void vhdlParser::Block_declarative_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_declarative_item(this);
}


antlrcpp::Any vhdlParser::Block_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitBlock_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_declarative_itemContext* vhdlParser::block_declarative_item() {
  Block_declarative_itemContext *_localctx = _tracker.createInstance<Block_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 26, vhdlParser::RuleBlock_declarative_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(646);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_GROUP:
      case vhdlParser::KW_FILE:
      case vhdlParser::KW_PURE:
      case vhdlParser::KW_USE:
      case vhdlParser::KW_SHARED:
      case vhdlParser::KW_SIGNAL:
      case vhdlParser::KW_DISCONNECT:
      case vhdlParser::KW_PROCEDURE:
      case vhdlParser::KW_ATTRIBUTE:
      case vhdlParser::KW_VARIABLE:
      case vhdlParser::KW_SUBTYPE:
      case vhdlParser::KW_CONSTANT:
      case vhdlParser::KW_FUNCTION:
      case vhdlParser::KW_ALIAS:
      case vhdlParser::KW_IMPURE:
      case vhdlParser::KW_PACKAGE:
      case vhdlParser::KW_TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(643);
        entity_declarative_item();
        break;
      }

      case vhdlParser::KW_COMPONENT: {
        enterOuterAlt(_localctx, 2);
        setState(644);
        component_declaration();
        break;
      }

      case vhdlParser::KW_FOR: {
        enterOuterAlt(_localctx, 3);
        setState(645);
        configuration_specification();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_declarationContext ------------------------------------------------------------------

vhdlParser::Configuration_declarationContext::Configuration_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Configuration_declarationContext::KW_CONFIGURATION() {
  return getTokens(vhdlParser::KW_CONFIGURATION);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::KW_CONFIGURATION(size_t i) {
  return getToken(vhdlParser::KW_CONFIGURATION, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Configuration_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Configuration_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::KW_OF() {
  return getToken(vhdlParser::KW_OF, 0);
}

vhdlParser::NameContext* vhdlParser::Configuration_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::Block_configurationContext* vhdlParser::Configuration_declarationContext::block_configuration() {
  return getRuleContext<vhdlParser::Block_configurationContext>(0);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Configuration_declarationContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}

std::vector<vhdlParser::Configuration_declarative_itemContext *> vhdlParser::Configuration_declarationContext::configuration_declarative_item() {
  return getRuleContexts<vhdlParser::Configuration_declarative_itemContext>();
}

vhdlParser::Configuration_declarative_itemContext* vhdlParser::Configuration_declarationContext::configuration_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Configuration_declarative_itemContext>(i);
}

std::vector<vhdlParser::Verification_unit_binding_indicationContext *> vhdlParser::Configuration_declarationContext::verification_unit_binding_indication() {
  return getRuleContexts<vhdlParser::Verification_unit_binding_indicationContext>();
}

vhdlParser::Verification_unit_binding_indicationContext* vhdlParser::Configuration_declarationContext::verification_unit_binding_indication(size_t i) {
  return getRuleContext<vhdlParser::Verification_unit_binding_indicationContext>(i);
}


size_t vhdlParser::Configuration_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_declaration;
}

void vhdlParser::Configuration_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfiguration_declaration(this);
}

void vhdlParser::Configuration_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfiguration_declaration(this);
}


antlrcpp::Any vhdlParser::Configuration_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConfiguration_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_declarationContext* vhdlParser::configuration_declaration() {
  Configuration_declarationContext *_localctx = _tracker.createInstance<Configuration_declarationContext>(_ctx, getState());
  enterRule(_localctx, 28, vhdlParser::RuleConfiguration_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(648);
    match(vhdlParser::KW_CONFIGURATION);
    setState(649);
    identifier();
    setState(650);
    match(vhdlParser::KW_OF);
    setState(651);
    name(0);
    setState(652);
    match(vhdlParser::KW_IS);
    setState(656);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(653);
        configuration_declarative_item(); 
      }
      setState(658);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(664);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::KW_USE) {
      setState(659);
      verification_unit_binding_indication();
      setState(660);
      match(vhdlParser::SEMI);
      setState(666);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(667);
    block_configuration();
    setState(668);
    match(vhdlParser::KW_END);
    setState(670);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_CONFIGURATION) {
      setState(669);
      match(vhdlParser::KW_CONFIGURATION);
    }
    setState(673);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(672);
      identifier();
    }
    setState(675);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Configuration_declarative_itemContext::Configuration_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Use_clauseContext* vhdlParser::Configuration_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Configuration_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Configuration_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}


size_t vhdlParser::Configuration_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_declarative_item;
}

void vhdlParser::Configuration_declarative_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfiguration_declarative_item(this);
}

void vhdlParser::Configuration_declarative_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfiguration_declarative_item(this);
}


antlrcpp::Any vhdlParser::Configuration_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConfiguration_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_declarative_itemContext* vhdlParser::configuration_declarative_item() {
  Configuration_declarative_itemContext *_localctx = _tracker.createInstance<Configuration_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 30, vhdlParser::RuleConfiguration_declarative_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(680);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_USE: {
        enterOuterAlt(_localctx, 1);
        setState(677);
        use_clause();
        break;
      }

      case vhdlParser::KW_ATTRIBUTE: {
        enterOuterAlt(_localctx, 2);
        setState(678);
        attribute_specification();
        break;
      }

      case vhdlParser::KW_GROUP: {
        enterOuterAlt(_localctx, 3);
        setState(679);
        group_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_configurationContext ------------------------------------------------------------------

vhdlParser::Block_configurationContext::Block_configurationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Block_configurationContext::KW_FOR() {
  return getTokens(vhdlParser::KW_FOR);
}

tree::TerminalNode* vhdlParser::Block_configurationContext::KW_FOR(size_t i) {
  return getToken(vhdlParser::KW_FOR, i);
}

vhdlParser::Block_specificationContext* vhdlParser::Block_configurationContext::block_specification() {
  return getRuleContext<vhdlParser::Block_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Block_configurationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Block_configurationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<vhdlParser::Use_clauseContext *> vhdlParser::Block_configurationContext::use_clause() {
  return getRuleContexts<vhdlParser::Use_clauseContext>();
}

vhdlParser::Use_clauseContext* vhdlParser::Block_configurationContext::use_clause(size_t i) {
  return getRuleContext<vhdlParser::Use_clauseContext>(i);
}

std::vector<vhdlParser::Configuration_itemContext *> vhdlParser::Block_configurationContext::configuration_item() {
  return getRuleContexts<vhdlParser::Configuration_itemContext>();
}

vhdlParser::Configuration_itemContext* vhdlParser::Block_configurationContext::configuration_item(size_t i) {
  return getRuleContext<vhdlParser::Configuration_itemContext>(i);
}


size_t vhdlParser::Block_configurationContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_configuration;
}

void vhdlParser::Block_configurationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_configuration(this);
}

void vhdlParser::Block_configurationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_configuration(this);
}


antlrcpp::Any vhdlParser::Block_configurationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitBlock_configuration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_configurationContext* vhdlParser::block_configuration() {
  Block_configurationContext *_localctx = _tracker.createInstance<Block_configurationContext>(_ctx, getState());
  enterRule(_localctx, 32, vhdlParser::RuleBlock_configuration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(682);
    match(vhdlParser::KW_FOR);
    setState(683);
    block_specification();
    setState(687);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::KW_USE) {
      setState(684);
      use_clause();
      setState(689);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(693);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::KW_FOR) {
      setState(690);
      configuration_item();
      setState(695);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(696);
    match(vhdlParser::KW_END);
    setState(697);
    match(vhdlParser::KW_FOR);
    setState(698);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_specificationContext ------------------------------------------------------------------

vhdlParser::Block_specificationContext::Block_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::LabelContext* vhdlParser::Block_specificationContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}

tree::TerminalNode* vhdlParser::Block_specificationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Generate_specificationContext* vhdlParser::Block_specificationContext::generate_specification() {
  return getRuleContext<vhdlParser::Generate_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Block_specificationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Block_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_specification;
}

void vhdlParser::Block_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_specification(this);
}

void vhdlParser::Block_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_specification(this);
}


antlrcpp::Any vhdlParser::Block_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitBlock_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_specificationContext* vhdlParser::block_specification() {
  Block_specificationContext *_localctx = _tracker.createInstance<Block_specificationContext>(_ctx, getState());
  enterRule(_localctx, 34, vhdlParser::RuleBlock_specification);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    label();
    setState(705);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(701);
      match(vhdlParser::LPAREN);
      setState(702);
      generate_specification();
      setState(703);
      match(vhdlParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generate_specificationContext ------------------------------------------------------------------

vhdlParser::Generate_specificationContext::Generate_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Discrete_rangeContext* vhdlParser::Generate_specificationContext::discrete_range() {
  return getRuleContext<vhdlParser::Discrete_rangeContext>(0);
}

vhdlParser::ExpressionContext* vhdlParser::Generate_specificationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

vhdlParser::LabelContext* vhdlParser::Generate_specificationContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::Generate_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleGenerate_specification;
}

void vhdlParser::Generate_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenerate_specification(this);
}

void vhdlParser::Generate_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenerate_specification(this);
}


antlrcpp::Any vhdlParser::Generate_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGenerate_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generate_specificationContext* vhdlParser::generate_specification() {
  Generate_specificationContext *_localctx = _tracker.createInstance<Generate_specificationContext>(_ctx, getState());
  enterRule(_localctx, 36, vhdlParser::RuleGenerate_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(710);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(707);
      discrete_range();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(708);
      expression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(709);
      label();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_itemContext ------------------------------------------------------------------

vhdlParser::Configuration_itemContext::Configuration_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Block_configurationContext* vhdlParser::Configuration_itemContext::block_configuration() {
  return getRuleContext<vhdlParser::Block_configurationContext>(0);
}

vhdlParser::Component_configurationContext* vhdlParser::Configuration_itemContext::component_configuration() {
  return getRuleContext<vhdlParser::Component_configurationContext>(0);
}


size_t vhdlParser::Configuration_itemContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_item;
}

void vhdlParser::Configuration_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfiguration_item(this);
}

void vhdlParser::Configuration_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfiguration_item(this);
}


antlrcpp::Any vhdlParser::Configuration_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConfiguration_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_itemContext* vhdlParser::configuration_item() {
  Configuration_itemContext *_localctx = _tracker.createInstance<Configuration_itemContext>(_ctx, getState());
  enterRule(_localctx, 38, vhdlParser::RuleConfiguration_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(714);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(712);
      block_configuration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(713);
      component_configuration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_configurationContext ------------------------------------------------------------------

vhdlParser::Component_configurationContext::Component_configurationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Component_configurationContext::KW_FOR() {
  return getTokens(vhdlParser::KW_FOR);
}

tree::TerminalNode* vhdlParser::Component_configurationContext::KW_FOR(size_t i) {
  return getToken(vhdlParser::KW_FOR, i);
}

vhdlParser::Component_specificationContext* vhdlParser::Component_configurationContext::component_specification() {
  return getRuleContext<vhdlParser::Component_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Component_configurationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Component_configurationContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Component_configurationContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}

vhdlParser::Binding_indicationContext* vhdlParser::Component_configurationContext::binding_indication() {
  return getRuleContext<vhdlParser::Binding_indicationContext>(0);
}

std::vector<vhdlParser::Verification_unit_binding_indicationContext *> vhdlParser::Component_configurationContext::verification_unit_binding_indication() {
  return getRuleContexts<vhdlParser::Verification_unit_binding_indicationContext>();
}

vhdlParser::Verification_unit_binding_indicationContext* vhdlParser::Component_configurationContext::verification_unit_binding_indication(size_t i) {
  return getRuleContext<vhdlParser::Verification_unit_binding_indicationContext>(i);
}

vhdlParser::Block_configurationContext* vhdlParser::Component_configurationContext::block_configuration() {
  return getRuleContext<vhdlParser::Block_configurationContext>(0);
}


size_t vhdlParser::Component_configurationContext::getRuleIndex() const {
  return vhdlParser::RuleComponent_configuration;
}

void vhdlParser::Component_configurationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_configuration(this);
}

void vhdlParser::Component_configurationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_configuration(this);
}


antlrcpp::Any vhdlParser::Component_configurationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitComponent_configuration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Component_configurationContext* vhdlParser::component_configuration() {
  Component_configurationContext *_localctx = _tracker.createInstance<Component_configurationContext>(_ctx, getState());
  enterRule(_localctx, 40, vhdlParser::RuleComponent_configuration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(716);
    match(vhdlParser::KW_FOR);
    setState(717);
    component_specification();
    setState(721);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(718);
      binding_indication();
      setState(719);
      match(vhdlParser::SEMI);
      break;
    }

    default:
      break;
    }
    setState(728);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::KW_USE) {
      setState(723);
      verification_unit_binding_indication();
      setState(724);
      match(vhdlParser::SEMI);
      setState(730);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(732);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_FOR) {
      setState(731);
      block_configuration();
    }
    setState(734);
    match(vhdlParser::KW_END);
    setState(735);
    match(vhdlParser::KW_FOR);
    setState(736);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_declarationContext ------------------------------------------------------------------

vhdlParser::Subprogram_declarationContext::Subprogram_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_specificationContext* vhdlParser::Subprogram_declarationContext::subprogram_specification() {
  return getRuleContext<vhdlParser::Subprogram_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Subprogram_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_declaration;
}

void vhdlParser::Subprogram_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_declaration(this);
}

void vhdlParser::Subprogram_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_declaration(this);
}


antlrcpp::Any vhdlParser::Subprogram_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSubprogram_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_declarationContext* vhdlParser::subprogram_declaration() {
  Subprogram_declarationContext *_localctx = _tracker.createInstance<Subprogram_declarationContext>(_ctx, getState());
  enterRule(_localctx, 42, vhdlParser::RuleSubprogram_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(738);
    subprogram_specification();
    setState(739);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_specificationContext ------------------------------------------------------------------

vhdlParser::Subprogram_specificationContext::Subprogram_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Procedure_specificationContext* vhdlParser::Subprogram_specificationContext::procedure_specification() {
  return getRuleContext<vhdlParser::Procedure_specificationContext>(0);
}

vhdlParser::Function_specificationContext* vhdlParser::Subprogram_specificationContext::function_specification() {
  return getRuleContext<vhdlParser::Function_specificationContext>(0);
}


size_t vhdlParser::Subprogram_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_specification;
}

void vhdlParser::Subprogram_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_specification(this);
}

void vhdlParser::Subprogram_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_specification(this);
}


antlrcpp::Any vhdlParser::Subprogram_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSubprogram_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_specificationContext* vhdlParser::subprogram_specification() {
  Subprogram_specificationContext *_localctx = _tracker.createInstance<Subprogram_specificationContext>(_ctx, getState());
  enterRule(_localctx, 44, vhdlParser::RuleSubprogram_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(743);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_PROCEDURE: {
        enterOuterAlt(_localctx, 1);
        setState(741);
        procedure_specification();
        break;
      }

      case vhdlParser::KW_PURE:
      case vhdlParser::KW_FUNCTION:
      case vhdlParser::KW_IMPURE: {
        enterOuterAlt(_localctx, 2);
        setState(742);
        function_specification();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedure_specificationContext ------------------------------------------------------------------

vhdlParser::Procedure_specificationContext::Procedure_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Procedure_specificationContext::KW_PROCEDURE() {
  return getToken(vhdlParser::KW_PROCEDURE, 0);
}

vhdlParser::DesignatorContext* vhdlParser::Procedure_specificationContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}

vhdlParser::Subprogram_headerContext* vhdlParser::Procedure_specificationContext::subprogram_header() {
  return getRuleContext<vhdlParser::Subprogram_headerContext>(0);
}

tree::TerminalNode* vhdlParser::Procedure_specificationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Formal_parameter_listContext* vhdlParser::Procedure_specificationContext::formal_parameter_list() {
  return getRuleContext<vhdlParser::Formal_parameter_listContext>(0);
}

tree::TerminalNode* vhdlParser::Procedure_specificationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Procedure_specificationContext::KW_PARAMETER() {
  return getToken(vhdlParser::KW_PARAMETER, 0);
}


size_t vhdlParser::Procedure_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleProcedure_specification;
}

void vhdlParser::Procedure_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedure_specification(this);
}

void vhdlParser::Procedure_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedure_specification(this);
}


antlrcpp::Any vhdlParser::Procedure_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProcedure_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedure_specificationContext* vhdlParser::procedure_specification() {
  Procedure_specificationContext *_localctx = _tracker.createInstance<Procedure_specificationContext>(_ctx, getState());
  enterRule(_localctx, 46, vhdlParser::RuleProcedure_specification);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(745);
    match(vhdlParser::KW_PROCEDURE);
    setState(746);
    designator();
    setState(748);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(747);
      subprogram_header();
    }
    setState(757);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PARAMETER

    || _la == vhdlParser::LPAREN) {
      setState(751);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_PARAMETER) {
        setState(750);
        match(vhdlParser::KW_PARAMETER);
      }
      setState(753);
      match(vhdlParser::LPAREN);
      setState(754);
      formal_parameter_list();
      setState(755);
      match(vhdlParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_specificationContext ------------------------------------------------------------------

vhdlParser::Function_specificationContext::Function_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Function_specificationContext::KW_FUNCTION() {
  return getToken(vhdlParser::KW_FUNCTION, 0);
}

vhdlParser::DesignatorContext* vhdlParser::Function_specificationContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::KW_RETURN() {
  return getToken(vhdlParser::KW_RETURN, 0);
}

vhdlParser::Type_markContext* vhdlParser::Function_specificationContext::type_mark() {
  return getRuleContext<vhdlParser::Type_markContext>(0);
}

vhdlParser::Subprogram_headerContext* vhdlParser::Function_specificationContext::subprogram_header() {
  return getRuleContext<vhdlParser::Subprogram_headerContext>(0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Formal_parameter_listContext* vhdlParser::Function_specificationContext::formal_parameter_list() {
  return getRuleContext<vhdlParser::Formal_parameter_listContext>(0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::KW_PURE() {
  return getToken(vhdlParser::KW_PURE, 0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::KW_IMPURE() {
  return getToken(vhdlParser::KW_IMPURE, 0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::KW_PARAMETER() {
  return getToken(vhdlParser::KW_PARAMETER, 0);
}


size_t vhdlParser::Function_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleFunction_specification;
}

void vhdlParser::Function_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_specification(this);
}

void vhdlParser::Function_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_specification(this);
}


antlrcpp::Any vhdlParser::Function_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFunction_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Function_specificationContext* vhdlParser::function_specification() {
  Function_specificationContext *_localctx = _tracker.createInstance<Function_specificationContext>(_ctx, getState());
  enterRule(_localctx, 48, vhdlParser::RuleFunction_specification);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(760);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PURE

    || _la == vhdlParser::KW_IMPURE) {
      setState(759);
      _la = _input->LA(1);
      if (!(_la == vhdlParser::KW_PURE

      || _la == vhdlParser::KW_IMPURE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(762);
    match(vhdlParser::KW_FUNCTION);
    setState(763);
    designator();
    setState(765);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(764);
      subprogram_header();
    }
    setState(774);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PARAMETER

    || _la == vhdlParser::LPAREN) {
      setState(768);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_PARAMETER) {
        setState(767);
        match(vhdlParser::KW_PARAMETER);
      }
      setState(770);
      match(vhdlParser::LPAREN);
      setState(771);
      formal_parameter_list();
      setState(772);
      match(vhdlParser::RPAREN);
    }
    setState(776);
    match(vhdlParser::KW_RETURN);
    setState(777);
    type_mark();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_headerContext ------------------------------------------------------------------

vhdlParser::Subprogram_headerContext::Subprogram_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Subprogram_headerContext::KW_GENERIC() {
  return getToken(vhdlParser::KW_GENERIC, 0);
}

tree::TerminalNode* vhdlParser::Subprogram_headerContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Generic_listContext* vhdlParser::Subprogram_headerContext::generic_list() {
  return getRuleContext<vhdlParser::Generic_listContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_headerContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Subprogram_headerContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}


size_t vhdlParser::Subprogram_headerContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_header;
}

void vhdlParser::Subprogram_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_header(this);
}

void vhdlParser::Subprogram_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_header(this);
}


antlrcpp::Any vhdlParser::Subprogram_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSubprogram_header(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_headerContext* vhdlParser::subprogram_header() {
  Subprogram_headerContext *_localctx = _tracker.createInstance<Subprogram_headerContext>(_ctx, getState());
  enterRule(_localctx, 50, vhdlParser::RuleSubprogram_header);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(779);
    match(vhdlParser::KW_GENERIC);
    setState(780);
    match(vhdlParser::LPAREN);
    setState(781);
    generic_list();
    setState(782);
    match(vhdlParser::RPAREN);
    setState(784);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(783);
      generic_map_aspect();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

vhdlParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::DesignatorContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

vhdlParser::Operator_symbolContext* vhdlParser::DesignatorContext::operator_symbol() {
  return getRuleContext<vhdlParser::Operator_symbolContext>(0);
}


size_t vhdlParser::DesignatorContext::getRuleIndex() const {
  return vhdlParser::RuleDesignator;
}

void vhdlParser::DesignatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignator(this);
}

void vhdlParser::DesignatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignator(this);
}


antlrcpp::Any vhdlParser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::DesignatorContext* vhdlParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 52, vhdlParser::RuleDesignator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(788);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(786);
        identifier();
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(787);
        operator_symbol();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_symbolContext ------------------------------------------------------------------

vhdlParser::Operator_symbolContext::Operator_symbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Operator_symbolContext::STRING_LITERAL() {
  return getToken(vhdlParser::STRING_LITERAL, 0);
}


size_t vhdlParser::Operator_symbolContext::getRuleIndex() const {
  return vhdlParser::RuleOperator_symbol;
}

void vhdlParser::Operator_symbolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_symbol(this);
}

void vhdlParser::Operator_symbolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_symbol(this);
}


antlrcpp::Any vhdlParser::Operator_symbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitOperator_symbol(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Operator_symbolContext* vhdlParser::operator_symbol() {
  Operator_symbolContext *_localctx = _tracker.createInstance<Operator_symbolContext>(_ctx, getState());
  enterRule(_localctx, 54, vhdlParser::RuleOperator_symbol);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(790);
    match(vhdlParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_parameter_listContext ------------------------------------------------------------------

vhdlParser::Formal_parameter_listContext::Formal_parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_listContext* vhdlParser::Formal_parameter_listContext::interface_list() {
  return getRuleContext<vhdlParser::Interface_listContext>(0);
}


size_t vhdlParser::Formal_parameter_listContext::getRuleIndex() const {
  return vhdlParser::RuleFormal_parameter_list;
}

void vhdlParser::Formal_parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormal_parameter_list(this);
}

void vhdlParser::Formal_parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormal_parameter_list(this);
}


antlrcpp::Any vhdlParser::Formal_parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFormal_parameter_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Formal_parameter_listContext* vhdlParser::formal_parameter_list() {
  Formal_parameter_listContext *_localctx = _tracker.createInstance<Formal_parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 56, vhdlParser::RuleFormal_parameter_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(792);
    interface_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_bodyContext ------------------------------------------------------------------

vhdlParser::Subprogram_bodyContext::Subprogram_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_specificationContext* vhdlParser::Subprogram_bodyContext::subprogram_specification() {
  return getRuleContext<vhdlParser::Subprogram_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_bodyContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Subprogram_bodyContext::KW_BEGIN() {
  return getToken(vhdlParser::KW_BEGIN, 0);
}

tree::TerminalNode* vhdlParser::Subprogram_bodyContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Subprogram_bodyContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<vhdlParser::Process_declarative_itemContext *> vhdlParser::Subprogram_bodyContext::process_declarative_item() {
  return getRuleContexts<vhdlParser::Process_declarative_itemContext>();
}

vhdlParser::Process_declarative_itemContext* vhdlParser::Subprogram_bodyContext::process_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Process_declarative_itemContext>(i);
}

std::vector<vhdlParser::Sequential_statementContext *> vhdlParser::Subprogram_bodyContext::sequential_statement() {
  return getRuleContexts<vhdlParser::Sequential_statementContext>();
}

vhdlParser::Sequential_statementContext* vhdlParser::Subprogram_bodyContext::sequential_statement(size_t i) {
  return getRuleContext<vhdlParser::Sequential_statementContext>(i);
}

vhdlParser::Subprogram_kindContext* vhdlParser::Subprogram_bodyContext::subprogram_kind() {
  return getRuleContext<vhdlParser::Subprogram_kindContext>(0);
}

vhdlParser::DesignatorContext* vhdlParser::Subprogram_bodyContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}


size_t vhdlParser::Subprogram_bodyContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_body;
}

void vhdlParser::Subprogram_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_body(this);
}

void vhdlParser::Subprogram_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_body(this);
}


antlrcpp::Any vhdlParser::Subprogram_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSubprogram_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::subprogram_body() {
  Subprogram_bodyContext *_localctx = _tracker.createInstance<Subprogram_bodyContext>(_ctx, getState());
  enterRule(_localctx, 58, vhdlParser::RuleSubprogram_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(794);
    subprogram_specification();
    setState(795);
    match(vhdlParser::KW_IS);
    setState(799);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
      | (1ULL << (vhdlParser::KW_IMPURE - 65))
      | (1ULL << (vhdlParser::KW_PACKAGE - 65))
      | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
      setState(796);
      process_declarative_item();
      setState(801);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(802);
    match(vhdlParser::KW_BEGIN);
    setState(806);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_NEXT)
      | (1ULL << vhdlParser::KW_LOOP)
      | (1ULL << vhdlParser::KW_REPORT))) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & ((1ULL << (vhdlParser::KW_EXIT - 70))
      | (1ULL << (vhdlParser::KW_RETURN - 70))
      | (1ULL << (vhdlParser::KW_WITH - 70))
      | (1ULL << (vhdlParser::KW_WAIT - 70))
      | (1ULL << (vhdlParser::KW_WHILE - 70))
      | (1ULL << (vhdlParser::KW_ASSERT - 70))
      | (1ULL << (vhdlParser::KW_FOR - 70))
      | (1ULL << (vhdlParser::KW_IF - 70))
      | (1ULL << (vhdlParser::KW_CASE - 70))
      | (1ULL << (vhdlParser::KW_NULL - 70))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 70))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 70))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 70))
      | (1ULL << (vhdlParser::STRING_LITERAL - 70))
      | (1ULL << (vhdlParser::LPAREN - 70))
      | (1ULL << (vhdlParser::SHIFT_LEFT - 70)))) != 0)) {
      setState(803);
      sequential_statement();
      setState(808);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(809);
    match(vhdlParser::KW_END);
    setState(811);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PROCEDURE

    || _la == vhdlParser::KW_FUNCTION) {
      setState(810);
      subprogram_kind();
    }
    setState(814);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 107) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 107)) & ((1ULL << (vhdlParser::BASIC_IDENTIFIER - 107))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 107))
      | (1ULL << (vhdlParser::STRING_LITERAL - 107)))) != 0)) {
      setState(813);
      designator();
    }
    setState(816);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_kindContext ------------------------------------------------------------------

vhdlParser::Subprogram_kindContext::Subprogram_kindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Subprogram_kindContext::KW_PROCEDURE() {
  return getToken(vhdlParser::KW_PROCEDURE, 0);
}

tree::TerminalNode* vhdlParser::Subprogram_kindContext::KW_FUNCTION() {
  return getToken(vhdlParser::KW_FUNCTION, 0);
}


size_t vhdlParser::Subprogram_kindContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_kind;
}

void vhdlParser::Subprogram_kindContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_kind(this);
}

void vhdlParser::Subprogram_kindContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_kind(this);
}


antlrcpp::Any vhdlParser::Subprogram_kindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSubprogram_kind(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_kindContext* vhdlParser::subprogram_kind() {
  Subprogram_kindContext *_localctx = _tracker.createInstance<Subprogram_kindContext>(_ctx, getState());
  enterRule(_localctx, 60, vhdlParser::RuleSubprogram_kind);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(818);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::KW_PROCEDURE

    || _la == vhdlParser::KW_FUNCTION)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_instantiation_declarationContext ------------------------------------------------------------------

vhdlParser::Subprogram_instantiation_declarationContext::Subprogram_instantiation_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_kindContext* vhdlParser::Subprogram_instantiation_declarationContext::subprogram_kind() {
  return getRuleContext<vhdlParser::Subprogram_kindContext>(0);
}

vhdlParser::DesignatorContext* vhdlParser::Subprogram_instantiation_declarationContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_instantiation_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Subprogram_instantiation_declarationContext::KW_NEW() {
  return getToken(vhdlParser::KW_NEW, 0);
}

vhdlParser::NameContext* vhdlParser::Subprogram_instantiation_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_instantiation_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::SignatureContext* vhdlParser::Subprogram_instantiation_declarationContext::signature() {
  return getRuleContext<vhdlParser::SignatureContext>(0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Subprogram_instantiation_declarationContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}


size_t vhdlParser::Subprogram_instantiation_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_instantiation_declaration;
}

void vhdlParser::Subprogram_instantiation_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_instantiation_declaration(this);
}

void vhdlParser::Subprogram_instantiation_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_instantiation_declaration(this);
}


antlrcpp::Any vhdlParser::Subprogram_instantiation_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSubprogram_instantiation_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_instantiation_declarationContext* vhdlParser::subprogram_instantiation_declaration() {
  Subprogram_instantiation_declarationContext *_localctx = _tracker.createInstance<Subprogram_instantiation_declarationContext>(_ctx, getState());
  enterRule(_localctx, 62, vhdlParser::RuleSubprogram_instantiation_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(820);
    subprogram_kind();
    setState(821);
    designator();
    setState(822);
    match(vhdlParser::KW_IS);
    setState(823);
    match(vhdlParser::KW_NEW);
    setState(824);
    name(0);
    setState(826);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LSQUARE_BR) {
      setState(825);
      signature();
    }
    setState(829);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(828);
      generic_map_aspect();
    }
    setState(831);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignatureContext ------------------------------------------------------------------

vhdlParser::SignatureContext::SignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::SignatureContext::LSQUARE_BR() {
  return getToken(vhdlParser::LSQUARE_BR, 0);
}

tree::TerminalNode* vhdlParser::SignatureContext::RSQUARE_BR() {
  return getToken(vhdlParser::RSQUARE_BR, 0);
}

std::vector<vhdlParser::Type_markContext *> vhdlParser::SignatureContext::type_mark() {
  return getRuleContexts<vhdlParser::Type_markContext>();
}

vhdlParser::Type_markContext* vhdlParser::SignatureContext::type_mark(size_t i) {
  return getRuleContext<vhdlParser::Type_markContext>(i);
}

tree::TerminalNode* vhdlParser::SignatureContext::KW_RETURN() {
  return getToken(vhdlParser::KW_RETURN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::SignatureContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::SignatureContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::SignatureContext::getRuleIndex() const {
  return vhdlParser::RuleSignature;
}

void vhdlParser::SignatureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignature(this);
}

void vhdlParser::SignatureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignature(this);
}


antlrcpp::Any vhdlParser::SignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSignature(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::SignatureContext* vhdlParser::signature() {
  SignatureContext *_localctx = _tracker.createInstance<SignatureContext>(_ctx, getState());
  enterRule(_localctx, 64, vhdlParser::RuleSignature);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(833);
    match(vhdlParser::LSQUARE_BR);
    setState(842);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 107) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 107)) & ((1ULL << (vhdlParser::BASIC_IDENTIFIER - 107))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 107))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 107))
      | (1ULL << (vhdlParser::STRING_LITERAL - 107))
      | (1ULL << (vhdlParser::SHIFT_LEFT - 107)))) != 0)) {
      setState(834);
      type_mark();
      setState(839);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == vhdlParser::COMMA) {
        setState(835);
        match(vhdlParser::COMMA);
        setState(836);
        type_mark();
        setState(841);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(846);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_RETURN) {
      setState(844);
      match(vhdlParser::KW_RETURN);
      setState(845);
      type_mark();
    }
    setState(848);
    match(vhdlParser::RSQUARE_BR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_declarationContext ------------------------------------------------------------------

vhdlParser::Package_declarationContext::Package_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Package_declarationContext::KW_PACKAGE() {
  return getTokens(vhdlParser::KW_PACKAGE);
}

tree::TerminalNode* vhdlParser::Package_declarationContext::KW_PACKAGE(size_t i) {
  return getToken(vhdlParser::KW_PACKAGE, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Package_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Package_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Package_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Package_declarationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Package_declarationContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Package_declarationContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}

vhdlParser::Generic_clauseContext* vhdlParser::Package_declarationContext::generic_clause() {
  return getRuleContext<vhdlParser::Generic_clauseContext>(0);
}

std::vector<vhdlParser::Package_declarative_itemContext *> vhdlParser::Package_declarationContext::package_declarative_item() {
  return getRuleContexts<vhdlParser::Package_declarative_itemContext>();
}

vhdlParser::Package_declarative_itemContext* vhdlParser::Package_declarationContext::package_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Package_declarative_itemContext>(i);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Package_declarationContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}


size_t vhdlParser::Package_declarationContext::getRuleIndex() const {
  return vhdlParser::RulePackage_declaration;
}

void vhdlParser::Package_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackage_declaration(this);
}

void vhdlParser::Package_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackage_declaration(this);
}


antlrcpp::Any vhdlParser::Package_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPackage_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_declarationContext* vhdlParser::package_declaration() {
  Package_declarationContext *_localctx = _tracker.createInstance<Package_declarationContext>(_ctx, getState());
  enterRule(_localctx, 66, vhdlParser::RulePackage_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(850);
    match(vhdlParser::KW_PACKAGE);
    setState(851);
    identifier();
    setState(852);
    match(vhdlParser::KW_IS);
    setState(859);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(853);
      generic_clause();
      setState(857);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_GENERIC) {
        setState(854);
        generic_map_aspect();
        setState(855);
        match(vhdlParser::SEMI);
      }
    }
    setState(864);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_COMPONENT)
      | (1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_SIGNAL)
      | (1ULL << vhdlParser::KW_DISCONNECT)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
      | (1ULL << (vhdlParser::KW_IMPURE - 65))
      | (1ULL << (vhdlParser::KW_PACKAGE - 65))
      | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
      setState(861);
      package_declarative_item();
      setState(866);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(867);
    match(vhdlParser::KW_END);
    setState(869);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PACKAGE) {
      setState(868);
      match(vhdlParser::KW_PACKAGE);
    }
    setState(872);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(871);
      identifier();
    }
    setState(874);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Package_declarative_itemContext::Package_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Process_or_package_declarative_itemContext* vhdlParser::Package_declarative_itemContext::process_or_package_declarative_item() {
  return getRuleContext<vhdlParser::Process_or_package_declarative_itemContext>(0);
}

vhdlParser::Signal_declarationContext* vhdlParser::Package_declarative_itemContext::signal_declaration() {
  return getRuleContext<vhdlParser::Signal_declarationContext>(0);
}

vhdlParser::Component_declarationContext* vhdlParser::Package_declarative_itemContext::component_declaration() {
  return getRuleContext<vhdlParser::Component_declarationContext>(0);
}

vhdlParser::Disconnection_specificationContext* vhdlParser::Package_declarative_itemContext::disconnection_specification() {
  return getRuleContext<vhdlParser::Disconnection_specificationContext>(0);
}


size_t vhdlParser::Package_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RulePackage_declarative_item;
}

void vhdlParser::Package_declarative_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackage_declarative_item(this);
}

void vhdlParser::Package_declarative_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackage_declarative_item(this);
}


antlrcpp::Any vhdlParser::Package_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPackage_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_declarative_itemContext* vhdlParser::package_declarative_item() {
  Package_declarative_itemContext *_localctx = _tracker.createInstance<Package_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 68, vhdlParser::RulePackage_declarative_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(880);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_GROUP:
      case vhdlParser::KW_FILE:
      case vhdlParser::KW_PURE:
      case vhdlParser::KW_USE:
      case vhdlParser::KW_SHARED:
      case vhdlParser::KW_PROCEDURE:
      case vhdlParser::KW_ATTRIBUTE:
      case vhdlParser::KW_VARIABLE:
      case vhdlParser::KW_SUBTYPE:
      case vhdlParser::KW_CONSTANT:
      case vhdlParser::KW_FUNCTION:
      case vhdlParser::KW_ALIAS:
      case vhdlParser::KW_IMPURE:
      case vhdlParser::KW_PACKAGE:
      case vhdlParser::KW_TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(876);
        process_or_package_declarative_item();
        break;
      }

      case vhdlParser::KW_SIGNAL: {
        enterOuterAlt(_localctx, 2);
        setState(877);
        signal_declaration();
        break;
      }

      case vhdlParser::KW_COMPONENT: {
        enterOuterAlt(_localctx, 3);
        setState(878);
        component_declaration();
        break;
      }

      case vhdlParser::KW_DISCONNECT: {
        enterOuterAlt(_localctx, 4);
        setState(879);
        disconnection_specification();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_bodyContext ------------------------------------------------------------------

vhdlParser::Package_bodyContext::Package_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Package_bodyContext::KW_PACKAGE() {
  return getTokens(vhdlParser::KW_PACKAGE);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::KW_PACKAGE(size_t i) {
  return getToken(vhdlParser::KW_PACKAGE, i);
}

std::vector<tree::TerminalNode *> vhdlParser::Package_bodyContext::KW_BODY() {
  return getTokens(vhdlParser::KW_BODY);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::KW_BODY(size_t i) {
  return getToken(vhdlParser::KW_BODY, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Package_bodyContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Package_bodyContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<vhdlParser::Process_declarative_itemContext *> vhdlParser::Package_bodyContext::process_declarative_item() {
  return getRuleContexts<vhdlParser::Process_declarative_itemContext>();
}

vhdlParser::Process_declarative_itemContext* vhdlParser::Package_bodyContext::process_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Process_declarative_itemContext>(i);
}


size_t vhdlParser::Package_bodyContext::getRuleIndex() const {
  return vhdlParser::RulePackage_body;
}

void vhdlParser::Package_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackage_body(this);
}

void vhdlParser::Package_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackage_body(this);
}


antlrcpp::Any vhdlParser::Package_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPackage_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_bodyContext* vhdlParser::package_body() {
  Package_bodyContext *_localctx = _tracker.createInstance<Package_bodyContext>(_ctx, getState());
  enterRule(_localctx, 70, vhdlParser::RulePackage_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(882);
    match(vhdlParser::KW_PACKAGE);
    setState(883);
    match(vhdlParser::KW_BODY);
    setState(884);
    identifier();
    setState(885);
    match(vhdlParser::KW_IS);
    setState(889);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
      | (1ULL << (vhdlParser::KW_IMPURE - 65))
      | (1ULL << (vhdlParser::KW_PACKAGE - 65))
      | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
      setState(886);
      process_declarative_item();
      setState(891);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(892);
    match(vhdlParser::KW_END);
    setState(895);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PACKAGE) {
      setState(893);
      match(vhdlParser::KW_PACKAGE);
      setState(894);
      match(vhdlParser::KW_BODY);
    }
    setState(898);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(897);
      identifier();
    }
    setState(900);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_instantiation_declarationContext ------------------------------------------------------------------

vhdlParser::Package_instantiation_declarationContext::Package_instantiation_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Package_instantiation_declarationContext::KW_PACKAGE() {
  return getToken(vhdlParser::KW_PACKAGE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Package_instantiation_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Package_instantiation_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Package_instantiation_declarationContext::KW_NEW() {
  return getToken(vhdlParser::KW_NEW, 0);
}

vhdlParser::NameContext* vhdlParser::Package_instantiation_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Package_instantiation_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Package_instantiation_declarationContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}


size_t vhdlParser::Package_instantiation_declarationContext::getRuleIndex() const {
  return vhdlParser::RulePackage_instantiation_declaration;
}

void vhdlParser::Package_instantiation_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackage_instantiation_declaration(this);
}

void vhdlParser::Package_instantiation_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackage_instantiation_declaration(this);
}


antlrcpp::Any vhdlParser::Package_instantiation_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPackage_instantiation_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_instantiation_declarationContext* vhdlParser::package_instantiation_declaration() {
  Package_instantiation_declarationContext *_localctx = _tracker.createInstance<Package_instantiation_declarationContext>(_ctx, getState());
  enterRule(_localctx, 72, vhdlParser::RulePackage_instantiation_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(902);
    match(vhdlParser::KW_PACKAGE);
    setState(903);
    identifier();
    setState(904);
    match(vhdlParser::KW_IS);
    setState(905);
    match(vhdlParser::KW_NEW);
    setState(906);
    name(0);
    setState(908);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(907);
      generic_map_aspect();
    }
    setState(910);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scalar_type_definitionContext ------------------------------------------------------------------

vhdlParser::Scalar_type_definitionContext::Scalar_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Enumeration_type_definitionContext* vhdlParser::Scalar_type_definitionContext::enumeration_type_definition() {
  return getRuleContext<vhdlParser::Enumeration_type_definitionContext>(0);
}

vhdlParser::Integer_type_definitionContext* vhdlParser::Scalar_type_definitionContext::integer_type_definition() {
  return getRuleContext<vhdlParser::Integer_type_definitionContext>(0);
}

vhdlParser::Floating_type_definitionContext* vhdlParser::Scalar_type_definitionContext::floating_type_definition() {
  return getRuleContext<vhdlParser::Floating_type_definitionContext>(0);
}

vhdlParser::Physical_type_definitionContext* vhdlParser::Scalar_type_definitionContext::physical_type_definition() {
  return getRuleContext<vhdlParser::Physical_type_definitionContext>(0);
}


size_t vhdlParser::Scalar_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleScalar_type_definition;
}

void vhdlParser::Scalar_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScalar_type_definition(this);
}

void vhdlParser::Scalar_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScalar_type_definition(this);
}


antlrcpp::Any vhdlParser::Scalar_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitScalar_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Scalar_type_definitionContext* vhdlParser::scalar_type_definition() {
  Scalar_type_definitionContext *_localctx = _tracker.createInstance<Scalar_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 74, vhdlParser::RuleScalar_type_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(916);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(912);
      enumeration_type_definition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(913);
      integer_type_definition();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(914);
      floating_type_definition();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(915);
      physical_type_definition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Range_constraintContext ------------------------------------------------------------------

vhdlParser::Range_constraintContext::Range_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Range_constraintContext::KW_RANGE() {
  return getToken(vhdlParser::KW_RANGE, 0);
}

vhdlParser::RangeContext* vhdlParser::Range_constraintContext::range() {
  return getRuleContext<vhdlParser::RangeContext>(0);
}


size_t vhdlParser::Range_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleRange_constraint;
}

void vhdlParser::Range_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRange_constraint(this);
}

void vhdlParser::Range_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRange_constraint(this);
}


antlrcpp::Any vhdlParser::Range_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRange_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Range_constraintContext* vhdlParser::range_constraint() {
  Range_constraintContext *_localctx = _tracker.createInstance<Range_constraintContext>(_ctx, getState());
  enterRule(_localctx, 76, vhdlParser::RuleRange_constraint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(918);
    match(vhdlParser::KW_RANGE);
    setState(919);
    range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

vhdlParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Attribute_nameContext* vhdlParser::RangeContext::attribute_name() {
  return getRuleContext<vhdlParser::Attribute_nameContext>(0);
}

vhdlParser::Explicit_rangeContext* vhdlParser::RangeContext::explicit_range() {
  return getRuleContext<vhdlParser::Explicit_rangeContext>(0);
}


size_t vhdlParser::RangeContext::getRuleIndex() const {
  return vhdlParser::RuleRange;
}

void vhdlParser::RangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRange(this);
}

void vhdlParser::RangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRange(this);
}


antlrcpp::Any vhdlParser::RangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRange(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::RangeContext* vhdlParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 78, vhdlParser::RuleRange);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(923);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(921);
      attribute_name();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(922);
      explicit_range();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectionContext ------------------------------------------------------------------

vhdlParser::DirectionContext::DirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::DirectionContext::KW_TO() {
  return getToken(vhdlParser::KW_TO, 0);
}

tree::TerminalNode* vhdlParser::DirectionContext::KW_DOWNTO() {
  return getToken(vhdlParser::KW_DOWNTO, 0);
}


size_t vhdlParser::DirectionContext::getRuleIndex() const {
  return vhdlParser::RuleDirection;
}

void vhdlParser::DirectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirection(this);
}

void vhdlParser::DirectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirection(this);
}


antlrcpp::Any vhdlParser::DirectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitDirection(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::DirectionContext* vhdlParser::direction() {
  DirectionContext *_localctx = _tracker.createInstance<DirectionContext>(_ctx, getState());
  enterRule(_localctx, 80, vhdlParser::RuleDirection);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(925);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::KW_TO

    || _la == vhdlParser::KW_DOWNTO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enumeration_type_definitionContext ------------------------------------------------------------------

vhdlParser::Enumeration_type_definitionContext::Enumeration_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Enumeration_type_definitionContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Enumeration_literalContext *> vhdlParser::Enumeration_type_definitionContext::enumeration_literal() {
  return getRuleContexts<vhdlParser::Enumeration_literalContext>();
}

vhdlParser::Enumeration_literalContext* vhdlParser::Enumeration_type_definitionContext::enumeration_literal(size_t i) {
  return getRuleContext<vhdlParser::Enumeration_literalContext>(i);
}

tree::TerminalNode* vhdlParser::Enumeration_type_definitionContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Enumeration_type_definitionContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Enumeration_type_definitionContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Enumeration_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleEnumeration_type_definition;
}

void vhdlParser::Enumeration_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumeration_type_definition(this);
}

void vhdlParser::Enumeration_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumeration_type_definition(this);
}


antlrcpp::Any vhdlParser::Enumeration_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEnumeration_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Enumeration_type_definitionContext* vhdlParser::enumeration_type_definition() {
  Enumeration_type_definitionContext *_localctx = _tracker.createInstance<Enumeration_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 82, vhdlParser::RuleEnumeration_type_definition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(927);
    match(vhdlParser::LPAREN);
    setState(928);
    enumeration_literal();
    setState(933);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(929);
      match(vhdlParser::COMMA);
      setState(930);
      enumeration_literal();
      setState(935);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(936);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enumeration_literalContext ------------------------------------------------------------------

vhdlParser::Enumeration_literalContext::Enumeration_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Enumeration_literalContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Enumeration_literalContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}


size_t vhdlParser::Enumeration_literalContext::getRuleIndex() const {
  return vhdlParser::RuleEnumeration_literal;
}

void vhdlParser::Enumeration_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumeration_literal(this);
}

void vhdlParser::Enumeration_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumeration_literal(this);
}


antlrcpp::Any vhdlParser::Enumeration_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEnumeration_literal(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Enumeration_literalContext* vhdlParser::enumeration_literal() {
  Enumeration_literalContext *_localctx = _tracker.createInstance<Enumeration_literalContext>(_ctx, getState());
  enterRule(_localctx, 84, vhdlParser::RuleEnumeration_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(940);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(938);
        identifier();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(939);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Integer_type_definitionContext ------------------------------------------------------------------

vhdlParser::Integer_type_definitionContext::Integer_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Range_constraintContext* vhdlParser::Integer_type_definitionContext::range_constraint() {
  return getRuleContext<vhdlParser::Range_constraintContext>(0);
}


size_t vhdlParser::Integer_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleInteger_type_definition;
}

void vhdlParser::Integer_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_type_definition(this);
}

void vhdlParser::Integer_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_type_definition(this);
}


antlrcpp::Any vhdlParser::Integer_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInteger_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Integer_type_definitionContext* vhdlParser::integer_type_definition() {
  Integer_type_definitionContext *_localctx = _tracker.createInstance<Integer_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 86, vhdlParser::RuleInteger_type_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(942);
    range_constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Physical_type_definitionContext ------------------------------------------------------------------

vhdlParser::Physical_type_definitionContext::Physical_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Range_constraintContext* vhdlParser::Physical_type_definitionContext::range_constraint() {
  return getRuleContext<vhdlParser::Range_constraintContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Physical_type_definitionContext::KW_UNITS() {
  return getTokens(vhdlParser::KW_UNITS);
}

tree::TerminalNode* vhdlParser::Physical_type_definitionContext::KW_UNITS(size_t i) {
  return getToken(vhdlParser::KW_UNITS, i);
}

vhdlParser::Primary_unit_declarationContext* vhdlParser::Physical_type_definitionContext::primary_unit_declaration() {
  return getRuleContext<vhdlParser::Primary_unit_declarationContext>(0);
}

tree::TerminalNode* vhdlParser::Physical_type_definitionContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

std::vector<vhdlParser::Secondary_unit_declarationContext *> vhdlParser::Physical_type_definitionContext::secondary_unit_declaration() {
  return getRuleContexts<vhdlParser::Secondary_unit_declarationContext>();
}

vhdlParser::Secondary_unit_declarationContext* vhdlParser::Physical_type_definitionContext::secondary_unit_declaration(size_t i) {
  return getRuleContext<vhdlParser::Secondary_unit_declarationContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Physical_type_definitionContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Physical_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RulePhysical_type_definition;
}

void vhdlParser::Physical_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhysical_type_definition(this);
}

void vhdlParser::Physical_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhysical_type_definition(this);
}


antlrcpp::Any vhdlParser::Physical_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPhysical_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Physical_type_definitionContext* vhdlParser::physical_type_definition() {
  Physical_type_definitionContext *_localctx = _tracker.createInstance<Physical_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 88, vhdlParser::RulePhysical_type_definition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(944);
    range_constraint();
    setState(945);
    match(vhdlParser::KW_UNITS);
    setState(946);
    primary_unit_declaration();
    setState(950);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(947);
      secondary_unit_declaration();
      setState(952);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(953);
    match(vhdlParser::KW_END);
    setState(954);
    match(vhdlParser::KW_UNITS);
    setState(956);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(955);
      identifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_unit_declarationContext ------------------------------------------------------------------

vhdlParser::Primary_unit_declarationContext::Primary_unit_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Primary_unit_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Primary_unit_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Primary_unit_declarationContext::getRuleIndex() const {
  return vhdlParser::RulePrimary_unit_declaration;
}

void vhdlParser::Primary_unit_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary_unit_declaration(this);
}

void vhdlParser::Primary_unit_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary_unit_declaration(this);
}


antlrcpp::Any vhdlParser::Primary_unit_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPrimary_unit_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Primary_unit_declarationContext* vhdlParser::primary_unit_declaration() {
  Primary_unit_declarationContext *_localctx = _tracker.createInstance<Primary_unit_declarationContext>(_ctx, getState());
  enterRule(_localctx, 90, vhdlParser::RulePrimary_unit_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(958);
    identifier();
    setState(959);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Secondary_unit_declarationContext ------------------------------------------------------------------

vhdlParser::Secondary_unit_declarationContext::Secondary_unit_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Secondary_unit_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Secondary_unit_declarationContext::EQ() {
  return getToken(vhdlParser::EQ, 0);
}

vhdlParser::Physical_literalContext* vhdlParser::Secondary_unit_declarationContext::physical_literal() {
  return getRuleContext<vhdlParser::Physical_literalContext>(0);
}

tree::TerminalNode* vhdlParser::Secondary_unit_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Secondary_unit_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSecondary_unit_declaration;
}

void vhdlParser::Secondary_unit_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondary_unit_declaration(this);
}

void vhdlParser::Secondary_unit_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondary_unit_declaration(this);
}


antlrcpp::Any vhdlParser::Secondary_unit_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSecondary_unit_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Secondary_unit_declarationContext* vhdlParser::secondary_unit_declaration() {
  Secondary_unit_declarationContext *_localctx = _tracker.createInstance<Secondary_unit_declarationContext>(_ctx, getState());
  enterRule(_localctx, 92, vhdlParser::RuleSecondary_unit_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(961);
    identifier();
    setState(962);
    match(vhdlParser::EQ);
    setState(963);
    physical_literal();
    setState(964);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Floating_type_definitionContext ------------------------------------------------------------------

vhdlParser::Floating_type_definitionContext::Floating_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Range_constraintContext* vhdlParser::Floating_type_definitionContext::range_constraint() {
  return getRuleContext<vhdlParser::Range_constraintContext>(0);
}


size_t vhdlParser::Floating_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleFloating_type_definition;
}

void vhdlParser::Floating_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloating_type_definition(this);
}

void vhdlParser::Floating_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloating_type_definition(this);
}


antlrcpp::Any vhdlParser::Floating_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFloating_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Floating_type_definitionContext* vhdlParser::floating_type_definition() {
  Floating_type_definitionContext *_localctx = _tracker.createInstance<Floating_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 94, vhdlParser::RuleFloating_type_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(966);
    range_constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Composite_type_definitionContext ------------------------------------------------------------------

vhdlParser::Composite_type_definitionContext::Composite_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Array_type_definitionContext* vhdlParser::Composite_type_definitionContext::array_type_definition() {
  return getRuleContext<vhdlParser::Array_type_definitionContext>(0);
}

vhdlParser::Record_type_definitionContext* vhdlParser::Composite_type_definitionContext::record_type_definition() {
  return getRuleContext<vhdlParser::Record_type_definitionContext>(0);
}


size_t vhdlParser::Composite_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleComposite_type_definition;
}

void vhdlParser::Composite_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComposite_type_definition(this);
}

void vhdlParser::Composite_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComposite_type_definition(this);
}


antlrcpp::Any vhdlParser::Composite_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitComposite_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Composite_type_definitionContext* vhdlParser::composite_type_definition() {
  Composite_type_definitionContext *_localctx = _tracker.createInstance<Composite_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 96, vhdlParser::RuleComposite_type_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(970);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_ARRAY: {
        enterOuterAlt(_localctx, 1);
        setState(968);
        array_type_definition();
        break;
      }

      case vhdlParser::KW_RECORD: {
        enterOuterAlt(_localctx, 2);
        setState(969);
        record_type_definition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_type_definitionContext ------------------------------------------------------------------

vhdlParser::Array_type_definitionContext::Array_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Unbounded_array_definitionContext* vhdlParser::Array_type_definitionContext::unbounded_array_definition() {
  return getRuleContext<vhdlParser::Unbounded_array_definitionContext>(0);
}

vhdlParser::Constrained_array_definitionContext* vhdlParser::Array_type_definitionContext::constrained_array_definition() {
  return getRuleContext<vhdlParser::Constrained_array_definitionContext>(0);
}


size_t vhdlParser::Array_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleArray_type_definition;
}

void vhdlParser::Array_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_type_definition(this);
}

void vhdlParser::Array_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_type_definition(this);
}


antlrcpp::Any vhdlParser::Array_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitArray_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Array_type_definitionContext* vhdlParser::array_type_definition() {
  Array_type_definitionContext *_localctx = _tracker.createInstance<Array_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 98, vhdlParser::RuleArray_type_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(974);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(972);
      unbounded_array_definition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(973);
      constrained_array_definition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unbounded_array_definitionContext ------------------------------------------------------------------

vhdlParser::Unbounded_array_definitionContext::Unbounded_array_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Unbounded_array_definitionContext::KW_ARRAY() {
  return getToken(vhdlParser::KW_ARRAY, 0);
}

tree::TerminalNode* vhdlParser::Unbounded_array_definitionContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Index_subtype_definitionContext *> vhdlParser::Unbounded_array_definitionContext::index_subtype_definition() {
  return getRuleContexts<vhdlParser::Index_subtype_definitionContext>();
}

vhdlParser::Index_subtype_definitionContext* vhdlParser::Unbounded_array_definitionContext::index_subtype_definition(size_t i) {
  return getRuleContext<vhdlParser::Index_subtype_definitionContext>(i);
}

tree::TerminalNode* vhdlParser::Unbounded_array_definitionContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Unbounded_array_definitionContext::KW_OF() {
  return getToken(vhdlParser::KW_OF, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Unbounded_array_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Unbounded_array_definitionContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Unbounded_array_definitionContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Unbounded_array_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleUnbounded_array_definition;
}

void vhdlParser::Unbounded_array_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnbounded_array_definition(this);
}

void vhdlParser::Unbounded_array_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnbounded_array_definition(this);
}


antlrcpp::Any vhdlParser::Unbounded_array_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitUnbounded_array_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Unbounded_array_definitionContext* vhdlParser::unbounded_array_definition() {
  Unbounded_array_definitionContext *_localctx = _tracker.createInstance<Unbounded_array_definitionContext>(_ctx, getState());
  enterRule(_localctx, 100, vhdlParser::RuleUnbounded_array_definition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(976);
    match(vhdlParser::KW_ARRAY);
    setState(977);
    match(vhdlParser::LPAREN);
    setState(978);
    index_subtype_definition();
    setState(983);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(979);
      match(vhdlParser::COMMA);
      setState(980);
      index_subtype_definition();
      setState(985);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(986);
    match(vhdlParser::RPAREN);
    setState(987);
    match(vhdlParser::KW_OF);
    setState(988);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constrained_array_definitionContext ------------------------------------------------------------------

vhdlParser::Constrained_array_definitionContext::Constrained_array_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Constrained_array_definitionContext::KW_ARRAY() {
  return getToken(vhdlParser::KW_ARRAY, 0);
}

vhdlParser::Index_constraintContext* vhdlParser::Constrained_array_definitionContext::index_constraint() {
  return getRuleContext<vhdlParser::Index_constraintContext>(0);
}

tree::TerminalNode* vhdlParser::Constrained_array_definitionContext::KW_OF() {
  return getToken(vhdlParser::KW_OF, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Constrained_array_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Constrained_array_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleConstrained_array_definition;
}

void vhdlParser::Constrained_array_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstrained_array_definition(this);
}

void vhdlParser::Constrained_array_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstrained_array_definition(this);
}


antlrcpp::Any vhdlParser::Constrained_array_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConstrained_array_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Constrained_array_definitionContext* vhdlParser::constrained_array_definition() {
  Constrained_array_definitionContext *_localctx = _tracker.createInstance<Constrained_array_definitionContext>(_ctx, getState());
  enterRule(_localctx, 102, vhdlParser::RuleConstrained_array_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(990);
    match(vhdlParser::KW_ARRAY);
    setState(991);
    index_constraint();
    setState(992);
    match(vhdlParser::KW_OF);
    setState(993);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_subtype_definitionContext ------------------------------------------------------------------

vhdlParser::Index_subtype_definitionContext::Index_subtype_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Type_markContext* vhdlParser::Index_subtype_definitionContext::type_mark() {
  return getRuleContext<vhdlParser::Type_markContext>(0);
}

tree::TerminalNode* vhdlParser::Index_subtype_definitionContext::KW_RANGE() {
  return getToken(vhdlParser::KW_RANGE, 0);
}

tree::TerminalNode* vhdlParser::Index_subtype_definitionContext::BOX() {
  return getToken(vhdlParser::BOX, 0);
}


size_t vhdlParser::Index_subtype_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleIndex_subtype_definition;
}

void vhdlParser::Index_subtype_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex_subtype_definition(this);
}

void vhdlParser::Index_subtype_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex_subtype_definition(this);
}


antlrcpp::Any vhdlParser::Index_subtype_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitIndex_subtype_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Index_subtype_definitionContext* vhdlParser::index_subtype_definition() {
  Index_subtype_definitionContext *_localctx = _tracker.createInstance<Index_subtype_definitionContext>(_ctx, getState());
  enterRule(_localctx, 104, vhdlParser::RuleIndex_subtype_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(995);
    type_mark();
    setState(996);
    match(vhdlParser::KW_RANGE);
    setState(997);
    match(vhdlParser::BOX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_constraintContext ------------------------------------------------------------------

vhdlParser::Array_constraintContext::Array_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Index_constraintContext* vhdlParser::Array_constraintContext::index_constraint() {
  return getRuleContext<vhdlParser::Index_constraintContext>(0);
}

vhdlParser::Array_element_constraintContext* vhdlParser::Array_constraintContext::array_element_constraint() {
  return getRuleContext<vhdlParser::Array_element_constraintContext>(0);
}

tree::TerminalNode* vhdlParser::Array_constraintContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

tree::TerminalNode* vhdlParser::Array_constraintContext::KW_OPEN() {
  return getToken(vhdlParser::KW_OPEN, 0);
}

tree::TerminalNode* vhdlParser::Array_constraintContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Array_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleArray_constraint;
}

void vhdlParser::Array_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_constraint(this);
}

void vhdlParser::Array_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_constraint(this);
}


antlrcpp::Any vhdlParser::Array_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitArray_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Array_constraintContext* vhdlParser::array_constraint() {
  Array_constraintContext *_localctx = _tracker.createInstance<Array_constraintContext>(_ctx, getState());
  enterRule(_localctx, 106, vhdlParser::RuleArray_constraint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1009);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(999);
      index_constraint();
      setState(1001);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
      case 1: {
        setState(1000);
        array_element_constraint();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1003);
      match(vhdlParser::LPAREN);
      setState(1004);
      match(vhdlParser::KW_OPEN);
      setState(1005);
      match(vhdlParser::RPAREN);
      setState(1007);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
      case 1: {
        setState(1006);
        array_element_constraint();
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_element_constraintContext ------------------------------------------------------------------

vhdlParser::Array_element_constraintContext::Array_element_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Element_constraintContext* vhdlParser::Array_element_constraintContext::element_constraint() {
  return getRuleContext<vhdlParser::Element_constraintContext>(0);
}


size_t vhdlParser::Array_element_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleArray_element_constraint;
}

void vhdlParser::Array_element_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_element_constraint(this);
}

void vhdlParser::Array_element_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_element_constraint(this);
}


antlrcpp::Any vhdlParser::Array_element_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitArray_element_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Array_element_constraintContext* vhdlParser::array_element_constraint() {
  Array_element_constraintContext *_localctx = _tracker.createInstance<Array_element_constraintContext>(_ctx, getState());
  enterRule(_localctx, 108, vhdlParser::RuleArray_element_constraint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1011);
    element_constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_constraintContext ------------------------------------------------------------------

vhdlParser::Index_constraintContext::Index_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Index_constraintContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Discrete_rangeContext *> vhdlParser::Index_constraintContext::discrete_range() {
  return getRuleContexts<vhdlParser::Discrete_rangeContext>();
}

vhdlParser::Discrete_rangeContext* vhdlParser::Index_constraintContext::discrete_range(size_t i) {
  return getRuleContext<vhdlParser::Discrete_rangeContext>(i);
}

tree::TerminalNode* vhdlParser::Index_constraintContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Index_constraintContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Index_constraintContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Index_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleIndex_constraint;
}

void vhdlParser::Index_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex_constraint(this);
}

void vhdlParser::Index_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex_constraint(this);
}


antlrcpp::Any vhdlParser::Index_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitIndex_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Index_constraintContext* vhdlParser::index_constraint() {
  Index_constraintContext *_localctx = _tracker.createInstance<Index_constraintContext>(_ctx, getState());
  enterRule(_localctx, 110, vhdlParser::RuleIndex_constraint);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1013);
    match(vhdlParser::LPAREN);
    setState(1014);
    discrete_range();
    setState(1019);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1015);
      match(vhdlParser::COMMA);
      setState(1016);
      discrete_range();
      setState(1021);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1022);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Discrete_rangeContext ------------------------------------------------------------------

vhdlParser::Discrete_rangeContext::Discrete_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subtype_indicationContext* vhdlParser::Discrete_rangeContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

vhdlParser::RangeContext* vhdlParser::Discrete_rangeContext::range() {
  return getRuleContext<vhdlParser::RangeContext>(0);
}


size_t vhdlParser::Discrete_rangeContext::getRuleIndex() const {
  return vhdlParser::RuleDiscrete_range;
}

void vhdlParser::Discrete_rangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiscrete_range(this);
}

void vhdlParser::Discrete_rangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiscrete_range(this);
}


antlrcpp::Any vhdlParser::Discrete_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitDiscrete_range(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Discrete_rangeContext* vhdlParser::discrete_range() {
  Discrete_rangeContext *_localctx = _tracker.createInstance<Discrete_rangeContext>(_ctx, getState());
  enterRule(_localctx, 112, vhdlParser::RuleDiscrete_range);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1026);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1024);
      subtype_indication();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1025);
      range();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_type_definitionContext ------------------------------------------------------------------

vhdlParser::Record_type_definitionContext::Record_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Record_type_definitionContext::KW_RECORD() {
  return getTokens(vhdlParser::KW_RECORD);
}

tree::TerminalNode* vhdlParser::Record_type_definitionContext::KW_RECORD(size_t i) {
  return getToken(vhdlParser::KW_RECORD, i);
}

tree::TerminalNode* vhdlParser::Record_type_definitionContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

std::vector<vhdlParser::Element_declarationContext *> vhdlParser::Record_type_definitionContext::element_declaration() {
  return getRuleContexts<vhdlParser::Element_declarationContext>();
}

vhdlParser::Element_declarationContext* vhdlParser::Record_type_definitionContext::element_declaration(size_t i) {
  return getRuleContext<vhdlParser::Element_declarationContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Record_type_definitionContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Record_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleRecord_type_definition;
}

void vhdlParser::Record_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecord_type_definition(this);
}

void vhdlParser::Record_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecord_type_definition(this);
}


antlrcpp::Any vhdlParser::Record_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRecord_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Record_type_definitionContext* vhdlParser::record_type_definition() {
  Record_type_definitionContext *_localctx = _tracker.createInstance<Record_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 114, vhdlParser::RuleRecord_type_definition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1028);
    match(vhdlParser::KW_RECORD);
    setState(1030); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1029);
      element_declaration();
      setState(1032); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER);
    setState(1034);
    match(vhdlParser::KW_END);
    setState(1035);
    match(vhdlParser::KW_RECORD);
    setState(1037);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1036);
      identifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_declarationContext ------------------------------------------------------------------

vhdlParser::Element_declarationContext::Element_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Element_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Element_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Element_subtype_definitionContext* vhdlParser::Element_declarationContext::element_subtype_definition() {
  return getRuleContext<vhdlParser::Element_subtype_definitionContext>(0);
}

tree::TerminalNode* vhdlParser::Element_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Element_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleElement_declaration;
}

void vhdlParser::Element_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_declaration(this);
}

void vhdlParser::Element_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_declaration(this);
}


antlrcpp::Any vhdlParser::Element_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitElement_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_declarationContext* vhdlParser::element_declaration() {
  Element_declarationContext *_localctx = _tracker.createInstance<Element_declarationContext>(_ctx, getState());
  enterRule(_localctx, 116, vhdlParser::RuleElement_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1039);
    identifier_list();
    setState(1040);
    match(vhdlParser::COLON);
    setState(1041);
    element_subtype_definition();
    setState(1042);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_listContext ------------------------------------------------------------------

vhdlParser::Identifier_listContext::Identifier_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Identifier_listContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Identifier_listContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Identifier_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Identifier_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Identifier_listContext::getRuleIndex() const {
  return vhdlParser::RuleIdentifier_list;
}

void vhdlParser::Identifier_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_list(this);
}

void vhdlParser::Identifier_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_list(this);
}


antlrcpp::Any vhdlParser::Identifier_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Identifier_listContext* vhdlParser::identifier_list() {
  Identifier_listContext *_localctx = _tracker.createInstance<Identifier_listContext>(_ctx, getState());
  enterRule(_localctx, 118, vhdlParser::RuleIdentifier_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1044);
    identifier();
    setState(1049);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1045);
      match(vhdlParser::COMMA);
      setState(1046);
      identifier();
      setState(1051);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_subtype_definitionContext ------------------------------------------------------------------

vhdlParser::Element_subtype_definitionContext::Element_subtype_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subtype_indicationContext* vhdlParser::Element_subtype_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Element_subtype_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleElement_subtype_definition;
}

void vhdlParser::Element_subtype_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_subtype_definition(this);
}

void vhdlParser::Element_subtype_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_subtype_definition(this);
}


antlrcpp::Any vhdlParser::Element_subtype_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitElement_subtype_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_subtype_definitionContext* vhdlParser::element_subtype_definition() {
  Element_subtype_definitionContext *_localctx = _tracker.createInstance<Element_subtype_definitionContext>(_ctx, getState());
  enterRule(_localctx, 120, vhdlParser::RuleElement_subtype_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1052);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_constraintContext ------------------------------------------------------------------

vhdlParser::Record_constraintContext::Record_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Record_constraintContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Record_element_constraintContext *> vhdlParser::Record_constraintContext::record_element_constraint() {
  return getRuleContexts<vhdlParser::Record_element_constraintContext>();
}

vhdlParser::Record_element_constraintContext* vhdlParser::Record_constraintContext::record_element_constraint(size_t i) {
  return getRuleContext<vhdlParser::Record_element_constraintContext>(i);
}

tree::TerminalNode* vhdlParser::Record_constraintContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Record_constraintContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Record_constraintContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Record_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleRecord_constraint;
}

void vhdlParser::Record_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecord_constraint(this);
}

void vhdlParser::Record_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecord_constraint(this);
}


antlrcpp::Any vhdlParser::Record_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRecord_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Record_constraintContext* vhdlParser::record_constraint() {
  Record_constraintContext *_localctx = _tracker.createInstance<Record_constraintContext>(_ctx, getState());
  enterRule(_localctx, 122, vhdlParser::RuleRecord_constraint);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1054);
    match(vhdlParser::LPAREN);
    setState(1055);
    record_element_constraint();
    setState(1060);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1056);
      match(vhdlParser::COMMA);
      setState(1057);
      record_element_constraint();
      setState(1062);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1063);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_element_constraintContext ------------------------------------------------------------------

vhdlParser::Record_element_constraintContext::Record_element_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Record_element_constraintContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

vhdlParser::Element_constraintContext* vhdlParser::Record_element_constraintContext::element_constraint() {
  return getRuleContext<vhdlParser::Element_constraintContext>(0);
}


size_t vhdlParser::Record_element_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleRecord_element_constraint;
}

void vhdlParser::Record_element_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecord_element_constraint(this);
}

void vhdlParser::Record_element_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecord_element_constraint(this);
}


antlrcpp::Any vhdlParser::Record_element_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRecord_element_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Record_element_constraintContext* vhdlParser::record_element_constraint() {
  Record_element_constraintContext *_localctx = _tracker.createInstance<Record_element_constraintContext>(_ctx, getState());
  enterRule(_localctx, 124, vhdlParser::RuleRecord_element_constraint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1065);
    identifier();
    setState(1066);
    element_constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Access_type_definitionContext ------------------------------------------------------------------

vhdlParser::Access_type_definitionContext::Access_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Access_type_definitionContext::KW_ACCESS() {
  return getToken(vhdlParser::KW_ACCESS, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Access_type_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Access_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleAccess_type_definition;
}

void vhdlParser::Access_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccess_type_definition(this);
}

void vhdlParser::Access_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccess_type_definition(this);
}


antlrcpp::Any vhdlParser::Access_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAccess_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Access_type_definitionContext* vhdlParser::access_type_definition() {
  Access_type_definitionContext *_localctx = _tracker.createInstance<Access_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 126, vhdlParser::RuleAccess_type_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1068);
    match(vhdlParser::KW_ACCESS);
    setState(1069);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Incomplete_type_declarationContext ------------------------------------------------------------------

vhdlParser::Incomplete_type_declarationContext::Incomplete_type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Incomplete_type_declarationContext::KW_TYPE() {
  return getToken(vhdlParser::KW_TYPE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Incomplete_type_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Incomplete_type_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Incomplete_type_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleIncomplete_type_declaration;
}

void vhdlParser::Incomplete_type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIncomplete_type_declaration(this);
}

void vhdlParser::Incomplete_type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIncomplete_type_declaration(this);
}


antlrcpp::Any vhdlParser::Incomplete_type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitIncomplete_type_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Incomplete_type_declarationContext* vhdlParser::incomplete_type_declaration() {
  Incomplete_type_declarationContext *_localctx = _tracker.createInstance<Incomplete_type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 128, vhdlParser::RuleIncomplete_type_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1071);
    match(vhdlParser::KW_TYPE);
    setState(1072);
    identifier();
    setState(1073);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- File_type_definitionContext ------------------------------------------------------------------

vhdlParser::File_type_definitionContext::File_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::File_type_definitionContext::KW_FILE() {
  return getToken(vhdlParser::KW_FILE, 0);
}

tree::TerminalNode* vhdlParser::File_type_definitionContext::KW_OF() {
  return getToken(vhdlParser::KW_OF, 0);
}

vhdlParser::Type_markContext* vhdlParser::File_type_definitionContext::type_mark() {
  return getRuleContext<vhdlParser::Type_markContext>(0);
}


size_t vhdlParser::File_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleFile_type_definition;
}

void vhdlParser::File_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile_type_definition(this);
}

void vhdlParser::File_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile_type_definition(this);
}


antlrcpp::Any vhdlParser::File_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFile_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::File_type_definitionContext* vhdlParser::file_type_definition() {
  File_type_definitionContext *_localctx = _tracker.createInstance<File_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 130, vhdlParser::RuleFile_type_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1075);
    match(vhdlParser::KW_FILE);
    setState(1076);
    match(vhdlParser::KW_OF);
    setState(1077);
    type_mark();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Protected_type_definitionContext ------------------------------------------------------------------

vhdlParser::Protected_type_definitionContext::Protected_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Protected_type_declarationContext* vhdlParser::Protected_type_definitionContext::protected_type_declaration() {
  return getRuleContext<vhdlParser::Protected_type_declarationContext>(0);
}

vhdlParser::Protected_type_bodyContext* vhdlParser::Protected_type_definitionContext::protected_type_body() {
  return getRuleContext<vhdlParser::Protected_type_bodyContext>(0);
}


size_t vhdlParser::Protected_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleProtected_type_definition;
}

void vhdlParser::Protected_type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProtected_type_definition(this);
}

void vhdlParser::Protected_type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProtected_type_definition(this);
}


antlrcpp::Any vhdlParser::Protected_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProtected_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Protected_type_definitionContext* vhdlParser::protected_type_definition() {
  Protected_type_definitionContext *_localctx = _tracker.createInstance<Protected_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 132, vhdlParser::RuleProtected_type_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1081);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1079);
      protected_type_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1080);
      protected_type_body();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Protected_type_declarationContext ------------------------------------------------------------------

vhdlParser::Protected_type_declarationContext::Protected_type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Protected_type_declarationContext::KW_PROTECTED() {
  return getTokens(vhdlParser::KW_PROTECTED);
}

tree::TerminalNode* vhdlParser::Protected_type_declarationContext::KW_PROTECTED(size_t i) {
  return getToken(vhdlParser::KW_PROTECTED, i);
}

tree::TerminalNode* vhdlParser::Protected_type_declarationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

std::vector<vhdlParser::Protected_type_declarative_itemContext *> vhdlParser::Protected_type_declarationContext::protected_type_declarative_item() {
  return getRuleContexts<vhdlParser::Protected_type_declarative_itemContext>();
}

vhdlParser::Protected_type_declarative_itemContext* vhdlParser::Protected_type_declarationContext::protected_type_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Protected_type_declarative_itemContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Protected_type_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Protected_type_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleProtected_type_declaration;
}

void vhdlParser::Protected_type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProtected_type_declaration(this);
}

void vhdlParser::Protected_type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProtected_type_declaration(this);
}


antlrcpp::Any vhdlParser::Protected_type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProtected_type_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Protected_type_declarationContext* vhdlParser::protected_type_declaration() {
  Protected_type_declarationContext *_localctx = _tracker.createInstance<Protected_type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 134, vhdlParser::RuleProtected_type_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1083);
    match(vhdlParser::KW_PROTECTED);
    setState(1087);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 18) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 18)) & ((1ULL << (vhdlParser::KW_PURE - 18))
      | (1ULL << (vhdlParser::KW_USE - 18))
      | (1ULL << (vhdlParser::KW_PROCEDURE - 18))
      | (1ULL << (vhdlParser::KW_ATTRIBUTE - 18))
      | (1ULL << (vhdlParser::KW_FUNCTION - 18))
      | (1ULL << (vhdlParser::KW_IMPURE - 18)))) != 0)) {
      setState(1084);
      protected_type_declarative_item();
      setState(1089);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1090);
    match(vhdlParser::KW_END);
    setState(1091);
    match(vhdlParser::KW_PROTECTED);
    setState(1093);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1092);
      identifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Protected_type_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Protected_type_declarative_itemContext::Protected_type_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Protected_type_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Subprogram_instantiation_declarationContext* vhdlParser::Protected_type_declarative_itemContext::subprogram_instantiation_declaration() {
  return getRuleContext<vhdlParser::Subprogram_instantiation_declarationContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Protected_type_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Protected_type_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}


size_t vhdlParser::Protected_type_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleProtected_type_declarative_item;
}

void vhdlParser::Protected_type_declarative_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProtected_type_declarative_item(this);
}

void vhdlParser::Protected_type_declarative_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProtected_type_declarative_item(this);
}


antlrcpp::Any vhdlParser::Protected_type_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProtected_type_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Protected_type_declarative_itemContext* vhdlParser::protected_type_declarative_item() {
  Protected_type_declarative_itemContext *_localctx = _tracker.createInstance<Protected_type_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 136, vhdlParser::RuleProtected_type_declarative_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1099);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1095);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1096);
      subprogram_instantiation_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1097);
      attribute_specification();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1098);
      use_clause();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Protected_type_bodyContext ------------------------------------------------------------------

vhdlParser::Protected_type_bodyContext::Protected_type_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Protected_type_bodyContext::KW_PROTECTED() {
  return getTokens(vhdlParser::KW_PROTECTED);
}

tree::TerminalNode* vhdlParser::Protected_type_bodyContext::KW_PROTECTED(size_t i) {
  return getToken(vhdlParser::KW_PROTECTED, i);
}

std::vector<tree::TerminalNode *> vhdlParser::Protected_type_bodyContext::KW_BODY() {
  return getTokens(vhdlParser::KW_BODY);
}

tree::TerminalNode* vhdlParser::Protected_type_bodyContext::KW_BODY(size_t i) {
  return getToken(vhdlParser::KW_BODY, i);
}

tree::TerminalNode* vhdlParser::Protected_type_bodyContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

std::vector<vhdlParser::Process_declarative_itemContext *> vhdlParser::Protected_type_bodyContext::process_declarative_item() {
  return getRuleContexts<vhdlParser::Process_declarative_itemContext>();
}

vhdlParser::Process_declarative_itemContext* vhdlParser::Protected_type_bodyContext::process_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Process_declarative_itemContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Protected_type_bodyContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Protected_type_bodyContext::getRuleIndex() const {
  return vhdlParser::RuleProtected_type_body;
}

void vhdlParser::Protected_type_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProtected_type_body(this);
}

void vhdlParser::Protected_type_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProtected_type_body(this);
}


antlrcpp::Any vhdlParser::Protected_type_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProtected_type_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Protected_type_bodyContext* vhdlParser::protected_type_body() {
  Protected_type_bodyContext *_localctx = _tracker.createInstance<Protected_type_bodyContext>(_ctx, getState());
  enterRule(_localctx, 138, vhdlParser::RuleProtected_type_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1101);
    match(vhdlParser::KW_PROTECTED);
    setState(1102);
    match(vhdlParser::KW_BODY);
    setState(1106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
      | (1ULL << (vhdlParser::KW_IMPURE - 65))
      | (1ULL << (vhdlParser::KW_PACKAGE - 65))
      | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
      setState(1103);
      process_declarative_item();
      setState(1108);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1109);
    match(vhdlParser::KW_END);
    setState(1110);
    match(vhdlParser::KW_PROTECTED);
    setState(1111);
    match(vhdlParser::KW_BODY);
    setState(1113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1112);
      identifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declarationContext ------------------------------------------------------------------

vhdlParser::Type_declarationContext::Type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Full_type_declarationContext* vhdlParser::Type_declarationContext::full_type_declaration() {
  return getRuleContext<vhdlParser::Full_type_declarationContext>(0);
}

vhdlParser::Incomplete_type_declarationContext* vhdlParser::Type_declarationContext::incomplete_type_declaration() {
  return getRuleContext<vhdlParser::Incomplete_type_declarationContext>(0);
}


size_t vhdlParser::Type_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleType_declaration;
}

void vhdlParser::Type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_declaration(this);
}

void vhdlParser::Type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_declaration(this);
}


antlrcpp::Any vhdlParser::Type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitType_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Type_declarationContext* vhdlParser::type_declaration() {
  Type_declarationContext *_localctx = _tracker.createInstance<Type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 140, vhdlParser::RuleType_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1115);
      full_type_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1116);
      incomplete_type_declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Full_type_declarationContext ------------------------------------------------------------------

vhdlParser::Full_type_declarationContext::Full_type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Full_type_declarationContext::KW_TYPE() {
  return getToken(vhdlParser::KW_TYPE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Full_type_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Full_type_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::Type_definitionContext* vhdlParser::Full_type_declarationContext::type_definition() {
  return getRuleContext<vhdlParser::Type_definitionContext>(0);
}

tree::TerminalNode* vhdlParser::Full_type_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Full_type_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleFull_type_declaration;
}

void vhdlParser::Full_type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFull_type_declaration(this);
}

void vhdlParser::Full_type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFull_type_declaration(this);
}


antlrcpp::Any vhdlParser::Full_type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFull_type_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Full_type_declarationContext* vhdlParser::full_type_declaration() {
  Full_type_declarationContext *_localctx = _tracker.createInstance<Full_type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 142, vhdlParser::RuleFull_type_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1119);
    match(vhdlParser::KW_TYPE);
    setState(1120);
    identifier();
    setState(1121);
    match(vhdlParser::KW_IS);
    setState(1122);
    type_definition();
    setState(1123);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_definitionContext ------------------------------------------------------------------

vhdlParser::Type_definitionContext::Type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Scalar_type_definitionContext* vhdlParser::Type_definitionContext::scalar_type_definition() {
  return getRuleContext<vhdlParser::Scalar_type_definitionContext>(0);
}

vhdlParser::Composite_type_definitionContext* vhdlParser::Type_definitionContext::composite_type_definition() {
  return getRuleContext<vhdlParser::Composite_type_definitionContext>(0);
}

vhdlParser::Access_type_definitionContext* vhdlParser::Type_definitionContext::access_type_definition() {
  return getRuleContext<vhdlParser::Access_type_definitionContext>(0);
}

vhdlParser::File_type_definitionContext* vhdlParser::Type_definitionContext::file_type_definition() {
  return getRuleContext<vhdlParser::File_type_definitionContext>(0);
}

vhdlParser::Protected_type_definitionContext* vhdlParser::Type_definitionContext::protected_type_definition() {
  return getRuleContext<vhdlParser::Protected_type_definitionContext>(0);
}


size_t vhdlParser::Type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleType_definition;
}

void vhdlParser::Type_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_definition(this);
}

void vhdlParser::Type_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_definition(this);
}


antlrcpp::Any vhdlParser::Type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitType_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Type_definitionContext* vhdlParser::type_definition() {
  Type_definitionContext *_localctx = _tracker.createInstance<Type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 144, vhdlParser::RuleType_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1130);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_RANGE:
      case vhdlParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(1125);
        scalar_type_definition();
        break;
      }

      case vhdlParser::KW_RECORD:
      case vhdlParser::KW_ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(1126);
        composite_type_definition();
        break;
      }

      case vhdlParser::KW_ACCESS: {
        enterOuterAlt(_localctx, 3);
        setState(1127);
        access_type_definition();
        break;
      }

      case vhdlParser::KW_FILE: {
        enterOuterAlt(_localctx, 4);
        setState(1128);
        file_type_definition();
        break;
      }

      case vhdlParser::KW_PROTECTED: {
        enterOuterAlt(_localctx, 5);
        setState(1129);
        protected_type_definition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subtype_declarationContext ------------------------------------------------------------------

vhdlParser::Subtype_declarationContext::Subtype_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Subtype_declarationContext::KW_SUBTYPE() {
  return getToken(vhdlParser::KW_SUBTYPE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Subtype_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Subtype_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Subtype_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Subtype_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Subtype_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSubtype_declaration;
}

void vhdlParser::Subtype_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubtype_declaration(this);
}

void vhdlParser::Subtype_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubtype_declaration(this);
}


antlrcpp::Any vhdlParser::Subtype_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSubtype_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subtype_declarationContext* vhdlParser::subtype_declaration() {
  Subtype_declarationContext *_localctx = _tracker.createInstance<Subtype_declarationContext>(_ctx, getState());
  enterRule(_localctx, 146, vhdlParser::RuleSubtype_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1132);
    match(vhdlParser::KW_SUBTYPE);
    setState(1133);
    identifier();
    setState(1134);
    match(vhdlParser::KW_IS);
    setState(1135);
    subtype_indication();
    setState(1136);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subtype_indicationContext ------------------------------------------------------------------

vhdlParser::Subtype_indicationContext::Subtype_indicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Type_markContext* vhdlParser::Subtype_indicationContext::type_mark() {
  return getRuleContext<vhdlParser::Type_markContext>(0);
}

vhdlParser::Resolution_indicationContext* vhdlParser::Subtype_indicationContext::resolution_indication() {
  return getRuleContext<vhdlParser::Resolution_indicationContext>(0);
}

vhdlParser::ConstraintContext* vhdlParser::Subtype_indicationContext::constraint() {
  return getRuleContext<vhdlParser::ConstraintContext>(0);
}


size_t vhdlParser::Subtype_indicationContext::getRuleIndex() const {
  return vhdlParser::RuleSubtype_indication;
}

void vhdlParser::Subtype_indicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubtype_indication(this);
}

void vhdlParser::Subtype_indicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubtype_indication(this);
}


antlrcpp::Any vhdlParser::Subtype_indicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSubtype_indication(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subtype_indicationContext* vhdlParser::subtype_indication() {
  Subtype_indicationContext *_localctx = _tracker.createInstance<Subtype_indicationContext>(_ctx, getState());
  enterRule(_localctx, 148, vhdlParser::RuleSubtype_indication);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1139);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      setState(1138);
      resolution_indication();
      break;
    }

    default:
      break;
    }
    setState(1141);
    type_mark();
    setState(1143);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
    case 1: {
      setState(1142);
      constraint();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Resolution_indicationContext ------------------------------------------------------------------

vhdlParser::Resolution_indicationContext::Resolution_indicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Resolution_indicationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Resolution_indicationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Element_resolutionContext* vhdlParser::Resolution_indicationContext::element_resolution() {
  return getRuleContext<vhdlParser::Element_resolutionContext>(0);
}

tree::TerminalNode* vhdlParser::Resolution_indicationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Resolution_indicationContext::getRuleIndex() const {
  return vhdlParser::RuleResolution_indication;
}

void vhdlParser::Resolution_indicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResolution_indication(this);
}

void vhdlParser::Resolution_indicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResolution_indication(this);
}


antlrcpp::Any vhdlParser::Resolution_indicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitResolution_indication(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Resolution_indicationContext* vhdlParser::resolution_indication() {
  Resolution_indicationContext *_localctx = _tracker.createInstance<Resolution_indicationContext>(_ctx, getState());
  enterRule(_localctx, 150, vhdlParser::RuleResolution_indication);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::SHIFT_LEFT: {
        enterOuterAlt(_localctx, 1);
        setState(1145);
        name(0);
        break;
      }

      case vhdlParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(1146);
        match(vhdlParser::LPAREN);
        setState(1147);
        element_resolution();
        setState(1148);
        match(vhdlParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_resolutionContext ------------------------------------------------------------------

vhdlParser::Element_resolutionContext::Element_resolutionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Array_element_resolutionContext* vhdlParser::Element_resolutionContext::array_element_resolution() {
  return getRuleContext<vhdlParser::Array_element_resolutionContext>(0);
}

vhdlParser::Record_resolutionContext* vhdlParser::Element_resolutionContext::record_resolution() {
  return getRuleContext<vhdlParser::Record_resolutionContext>(0);
}


size_t vhdlParser::Element_resolutionContext::getRuleIndex() const {
  return vhdlParser::RuleElement_resolution;
}

void vhdlParser::Element_resolutionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_resolution(this);
}

void vhdlParser::Element_resolutionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_resolution(this);
}


antlrcpp::Any vhdlParser::Element_resolutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitElement_resolution(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_resolutionContext* vhdlParser::element_resolution() {
  Element_resolutionContext *_localctx = _tracker.createInstance<Element_resolutionContext>(_ctx, getState());
  enterRule(_localctx, 152, vhdlParser::RuleElement_resolution);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1152);
      array_element_resolution();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1153);
      record_resolution();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_element_resolutionContext ------------------------------------------------------------------

vhdlParser::Array_element_resolutionContext::Array_element_resolutionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Resolution_indicationContext* vhdlParser::Array_element_resolutionContext::resolution_indication() {
  return getRuleContext<vhdlParser::Resolution_indicationContext>(0);
}


size_t vhdlParser::Array_element_resolutionContext::getRuleIndex() const {
  return vhdlParser::RuleArray_element_resolution;
}

void vhdlParser::Array_element_resolutionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_element_resolution(this);
}

void vhdlParser::Array_element_resolutionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_element_resolution(this);
}


antlrcpp::Any vhdlParser::Array_element_resolutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitArray_element_resolution(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Array_element_resolutionContext* vhdlParser::array_element_resolution() {
  Array_element_resolutionContext *_localctx = _tracker.createInstance<Array_element_resolutionContext>(_ctx, getState());
  enterRule(_localctx, 154, vhdlParser::RuleArray_element_resolution);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1156);
    resolution_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_resolutionContext ------------------------------------------------------------------

vhdlParser::Record_resolutionContext::Record_resolutionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Record_element_resolutionContext *> vhdlParser::Record_resolutionContext::record_element_resolution() {
  return getRuleContexts<vhdlParser::Record_element_resolutionContext>();
}

vhdlParser::Record_element_resolutionContext* vhdlParser::Record_resolutionContext::record_element_resolution(size_t i) {
  return getRuleContext<vhdlParser::Record_element_resolutionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Record_resolutionContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Record_resolutionContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Record_resolutionContext::getRuleIndex() const {
  return vhdlParser::RuleRecord_resolution;
}

void vhdlParser::Record_resolutionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecord_resolution(this);
}

void vhdlParser::Record_resolutionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecord_resolution(this);
}


antlrcpp::Any vhdlParser::Record_resolutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRecord_resolution(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Record_resolutionContext* vhdlParser::record_resolution() {
  Record_resolutionContext *_localctx = _tracker.createInstance<Record_resolutionContext>(_ctx, getState());
  enterRule(_localctx, 156, vhdlParser::RuleRecord_resolution);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1158);
    record_element_resolution();
    setState(1163);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1159);
      match(vhdlParser::COMMA);
      setState(1160);
      record_element_resolution();
      setState(1165);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_element_resolutionContext ------------------------------------------------------------------

vhdlParser::Record_element_resolutionContext::Record_element_resolutionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Record_element_resolutionContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

vhdlParser::Resolution_indicationContext* vhdlParser::Record_element_resolutionContext::resolution_indication() {
  return getRuleContext<vhdlParser::Resolution_indicationContext>(0);
}


size_t vhdlParser::Record_element_resolutionContext::getRuleIndex() const {
  return vhdlParser::RuleRecord_element_resolution;
}

void vhdlParser::Record_element_resolutionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecord_element_resolution(this);
}

void vhdlParser::Record_element_resolutionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecord_element_resolution(this);
}


antlrcpp::Any vhdlParser::Record_element_resolutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRecord_element_resolution(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Record_element_resolutionContext* vhdlParser::record_element_resolution() {
  Record_element_resolutionContext *_localctx = _tracker.createInstance<Record_element_resolutionContext>(_ctx, getState());
  enterRule(_localctx, 158, vhdlParser::RuleRecord_element_resolution);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1166);
    identifier();
    setState(1167);
    resolution_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_markContext ------------------------------------------------------------------

vhdlParser::Type_markContext::Type_markContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Type_markContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::Type_markContext::getRuleIndex() const {
  return vhdlParser::RuleType_mark;
}

void vhdlParser::Type_markContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_mark(this);
}

void vhdlParser::Type_markContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_mark(this);
}


antlrcpp::Any vhdlParser::Type_markContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitType_mark(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Type_markContext* vhdlParser::type_mark() {
  Type_markContext *_localctx = _tracker.createInstance<Type_markContext>(_ctx, getState());
  enterRule(_localctx, 160, vhdlParser::RuleType_mark);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1169);
    name(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintContext ------------------------------------------------------------------

vhdlParser::ConstraintContext::ConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Range_constraintContext* vhdlParser::ConstraintContext::range_constraint() {
  return getRuleContext<vhdlParser::Range_constraintContext>(0);
}

vhdlParser::Element_constraintContext* vhdlParser::ConstraintContext::element_constraint() {
  return getRuleContext<vhdlParser::Element_constraintContext>(0);
}


size_t vhdlParser::ConstraintContext::getRuleIndex() const {
  return vhdlParser::RuleConstraint;
}

void vhdlParser::ConstraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraint(this);
}

void vhdlParser::ConstraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraint(this);
}


antlrcpp::Any vhdlParser::ConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConstraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ConstraintContext* vhdlParser::constraint() {
  ConstraintContext *_localctx = _tracker.createInstance<ConstraintContext>(_ctx, getState());
  enterRule(_localctx, 162, vhdlParser::RuleConstraint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_RANGE: {
        enterOuterAlt(_localctx, 1);
        setState(1171);
        range_constraint();
        break;
      }

      case vhdlParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(1172);
        element_constraint();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_constraintContext ------------------------------------------------------------------

vhdlParser::Element_constraintContext::Element_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Array_constraintContext* vhdlParser::Element_constraintContext::array_constraint() {
  return getRuleContext<vhdlParser::Array_constraintContext>(0);
}

vhdlParser::Record_constraintContext* vhdlParser::Element_constraintContext::record_constraint() {
  return getRuleContext<vhdlParser::Record_constraintContext>(0);
}


size_t vhdlParser::Element_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleElement_constraint;
}

void vhdlParser::Element_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_constraint(this);
}

void vhdlParser::Element_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_constraint(this);
}


antlrcpp::Any vhdlParser::Element_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitElement_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_constraintContext* vhdlParser::element_constraint() {
  Element_constraintContext *_localctx = _tracker.createInstance<Element_constraintContext>(_ctx, getState());
  enterRule(_localctx, 164, vhdlParser::RuleElement_constraint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1175);
      array_constraint();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1176);
      record_constraint();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_declarationContext ------------------------------------------------------------------

vhdlParser::Object_declarationContext::Object_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Constant_declarationContext* vhdlParser::Object_declarationContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Signal_declarationContext* vhdlParser::Object_declarationContext::signal_declaration() {
  return getRuleContext<vhdlParser::Signal_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Object_declarationContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Object_declarationContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}


size_t vhdlParser::Object_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleObject_declaration;
}

void vhdlParser::Object_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject_declaration(this);
}

void vhdlParser::Object_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject_declaration(this);
}


antlrcpp::Any vhdlParser::Object_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitObject_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Object_declarationContext* vhdlParser::object_declaration() {
  Object_declarationContext *_localctx = _tracker.createInstance<Object_declarationContext>(_ctx, getState());
  enterRule(_localctx, 166, vhdlParser::RuleObject_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1183);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_CONSTANT: {
        enterOuterAlt(_localctx, 1);
        setState(1179);
        constant_declaration();
        break;
      }

      case vhdlParser::KW_SIGNAL: {
        enterOuterAlt(_localctx, 2);
        setState(1180);
        signal_declaration();
        break;
      }

      case vhdlParser::KW_SHARED:
      case vhdlParser::KW_VARIABLE: {
        enterOuterAlt(_localctx, 3);
        setState(1181);
        variable_declaration();
        break;
      }

      case vhdlParser::KW_FILE: {
        enterOuterAlt(_localctx, 4);
        setState(1182);
        file_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_declarationContext ------------------------------------------------------------------

vhdlParser::Constant_declarationContext::Constant_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Constant_declarationContext::KW_CONSTANT() {
  return getToken(vhdlParser::KW_CONSTANT, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Constant_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Constant_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Constant_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Constant_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Constant_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Constant_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Constant_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleConstant_declaration;
}

void vhdlParser::Constant_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant_declaration(this);
}

void vhdlParser::Constant_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant_declaration(this);
}


antlrcpp::Any vhdlParser::Constant_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConstant_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Constant_declarationContext* vhdlParser::constant_declaration() {
  Constant_declarationContext *_localctx = _tracker.createInstance<Constant_declarationContext>(_ctx, getState());
  enterRule(_localctx, 168, vhdlParser::RuleConstant_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1185);
    match(vhdlParser::KW_CONSTANT);
    setState(1186);
    identifier_list();
    setState(1187);
    match(vhdlParser::COLON);
    setState(1188);
    subtype_indication();
    setState(1191);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1189);
      match(vhdlParser::VARASGN);
      setState(1190);
      expression(0);
    }
    setState(1193);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_declarationContext ------------------------------------------------------------------

vhdlParser::Signal_declarationContext::Signal_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Signal_declarationContext::KW_SIGNAL() {
  return getToken(vhdlParser::KW_SIGNAL, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Signal_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Signal_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Signal_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Signal_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Signal_kindContext* vhdlParser::Signal_declarationContext::signal_kind() {
  return getRuleContext<vhdlParser::Signal_kindContext>(0);
}

tree::TerminalNode* vhdlParser::Signal_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Signal_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Signal_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_declaration;
}

void vhdlParser::Signal_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignal_declaration(this);
}

void vhdlParser::Signal_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignal_declaration(this);
}


antlrcpp::Any vhdlParser::Signal_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSignal_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_declarationContext* vhdlParser::signal_declaration() {
  Signal_declarationContext *_localctx = _tracker.createInstance<Signal_declarationContext>(_ctx, getState());
  enterRule(_localctx, 170, vhdlParser::RuleSignal_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1195);
    match(vhdlParser::KW_SIGNAL);
    setState(1196);
    identifier_list();
    setState(1197);
    match(vhdlParser::COLON);
    setState(1198);
    subtype_indication();
    setState(1200);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_REGISTER

    || _la == vhdlParser::KW_BUS) {
      setState(1199);
      signal_kind();
    }
    setState(1204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1202);
      match(vhdlParser::VARASGN);
      setState(1203);
      expression(0);
    }
    setState(1206);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_kindContext ------------------------------------------------------------------

vhdlParser::Signal_kindContext::Signal_kindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Signal_kindContext::KW_REGISTER() {
  return getToken(vhdlParser::KW_REGISTER, 0);
}

tree::TerminalNode* vhdlParser::Signal_kindContext::KW_BUS() {
  return getToken(vhdlParser::KW_BUS, 0);
}


size_t vhdlParser::Signal_kindContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_kind;
}

void vhdlParser::Signal_kindContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignal_kind(this);
}

void vhdlParser::Signal_kindContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignal_kind(this);
}


antlrcpp::Any vhdlParser::Signal_kindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSignal_kind(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_kindContext* vhdlParser::signal_kind() {
  Signal_kindContext *_localctx = _tracker.createInstance<Signal_kindContext>(_ctx, getState());
  enterRule(_localctx, 172, vhdlParser::RuleSignal_kind);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1208);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::KW_REGISTER

    || _la == vhdlParser::KW_BUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declarationContext ------------------------------------------------------------------

vhdlParser::Variable_declarationContext::Variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::KW_VARIABLE() {
  return getToken(vhdlParser::KW_VARIABLE, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Variable_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Variable_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::KW_SHARED() {
  return getToken(vhdlParser::KW_SHARED, 0);
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Variable_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Variable_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleVariable_declaration;
}

void vhdlParser::Variable_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_declaration(this);
}

void vhdlParser::Variable_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_declaration(this);
}


antlrcpp::Any vhdlParser::Variable_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitVariable_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Variable_declarationContext* vhdlParser::variable_declaration() {
  Variable_declarationContext *_localctx = _tracker.createInstance<Variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 174, vhdlParser::RuleVariable_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1211);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_SHARED) {
      setState(1210);
      match(vhdlParser::KW_SHARED);
    }
    setState(1213);
    match(vhdlParser::KW_VARIABLE);
    setState(1214);
    identifier_list();
    setState(1215);
    match(vhdlParser::COLON);
    setState(1216);
    subtype_indication();
    setState(1219);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1217);
      match(vhdlParser::VARASGN);
      setState(1218);
      expression(0);
    }
    setState(1221);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- File_declarationContext ------------------------------------------------------------------

vhdlParser::File_declarationContext::File_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::File_declarationContext::KW_FILE() {
  return getToken(vhdlParser::KW_FILE, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::File_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::File_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::File_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::File_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::File_open_informationContext* vhdlParser::File_declarationContext::file_open_information() {
  return getRuleContext<vhdlParser::File_open_informationContext>(0);
}


size_t vhdlParser::File_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleFile_declaration;
}

void vhdlParser::File_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile_declaration(this);
}

void vhdlParser::File_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile_declaration(this);
}


antlrcpp::Any vhdlParser::File_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFile_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::File_declarationContext* vhdlParser::file_declaration() {
  File_declarationContext *_localctx = _tracker.createInstance<File_declarationContext>(_ctx, getState());
  enterRule(_localctx, 176, vhdlParser::RuleFile_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1223);
    match(vhdlParser::KW_FILE);
    setState(1224);
    identifier_list();
    setState(1225);
    match(vhdlParser::COLON);
    setState(1226);
    subtype_indication();
    setState(1228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IS

    || _la == vhdlParser::KW_OPEN) {
      setState(1227);
      file_open_information();
    }
    setState(1230);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- File_open_informationContext ------------------------------------------------------------------

vhdlParser::File_open_informationContext::File_open_informationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::File_open_informationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::File_logical_nameContext* vhdlParser::File_open_informationContext::file_logical_name() {
  return getRuleContext<vhdlParser::File_logical_nameContext>(0);
}

tree::TerminalNode* vhdlParser::File_open_informationContext::KW_OPEN() {
  return getToken(vhdlParser::KW_OPEN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::File_open_informationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::File_open_informationContext::KW_IN() {
  return getToken(vhdlParser::KW_IN, 0);
}

tree::TerminalNode* vhdlParser::File_open_informationContext::KW_OUT() {
  return getToken(vhdlParser::KW_OUT, 0);
}


size_t vhdlParser::File_open_informationContext::getRuleIndex() const {
  return vhdlParser::RuleFile_open_information;
}

void vhdlParser::File_open_informationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile_open_information(this);
}

void vhdlParser::File_open_informationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile_open_information(this);
}


antlrcpp::Any vhdlParser::File_open_informationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFile_open_information(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::File_open_informationContext* vhdlParser::file_open_information() {
  File_open_informationContext *_localctx = _tracker.createInstance<File_open_informationContext>(_ctx, getState());
  enterRule(_localctx, 178, vhdlParser::RuleFile_open_information);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_OPEN) {
      setState(1232);
      match(vhdlParser::KW_OPEN);
      setState(1233);
      expression(0);
    }
    setState(1236);
    match(vhdlParser::KW_IS);
    setState(1238);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IN

    || _la == vhdlParser::KW_OUT) {
      setState(1237);
      _la = _input->LA(1);
      if (!(_la == vhdlParser::KW_IN

      || _la == vhdlParser::KW_OUT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1240);
    file_logical_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- File_logical_nameContext ------------------------------------------------------------------

vhdlParser::File_logical_nameContext::File_logical_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::ExpressionContext* vhdlParser::File_logical_nameContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::File_logical_nameContext::getRuleIndex() const {
  return vhdlParser::RuleFile_logical_name;
}

void vhdlParser::File_logical_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile_logical_name(this);
}

void vhdlParser::File_logical_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile_logical_name(this);
}


antlrcpp::Any vhdlParser::File_logical_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFile_logical_name(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::File_logical_nameContext* vhdlParser::file_logical_name() {
  File_logical_nameContext *_localctx = _tracker.createInstance<File_logical_nameContext>(_ctx, getState());
  enterRule(_localctx, 180, vhdlParser::RuleFile_logical_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1242);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_declarationContext::Interface_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_object_declarationContext* vhdlParser::Interface_declarationContext::interface_object_declaration() {
  return getRuleContext<vhdlParser::Interface_object_declarationContext>(0);
}

vhdlParser::Interface_type_declarationContext* vhdlParser::Interface_declarationContext::interface_type_declaration() {
  return getRuleContext<vhdlParser::Interface_type_declarationContext>(0);
}

vhdlParser::Interface_subprogram_declarationContext* vhdlParser::Interface_declarationContext::interface_subprogram_declaration() {
  return getRuleContext<vhdlParser::Interface_subprogram_declarationContext>(0);
}

vhdlParser::Interface_package_declarationContext* vhdlParser::Interface_declarationContext::interface_package_declaration() {
  return getRuleContext<vhdlParser::Interface_package_declarationContext>(0);
}


size_t vhdlParser::Interface_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_declaration;
}

void vhdlParser::Interface_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_declaration(this);
}

void vhdlParser::Interface_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_declarationContext* vhdlParser::interface_declaration() {
  Interface_declarationContext *_localctx = _tracker.createInstance<Interface_declarationContext>(_ctx, getState());
  enterRule(_localctx, 182, vhdlParser::RuleInterface_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1248);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_FILE:
      case vhdlParser::KW_SIGNAL:
      case vhdlParser::KW_VARIABLE:
      case vhdlParser::KW_CONSTANT:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1244);
        interface_object_declaration();
        break;
      }

      case vhdlParser::KW_TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(1245);
        interface_type_declaration();
        break;
      }

      case vhdlParser::KW_PURE:
      case vhdlParser::KW_PROCEDURE:
      case vhdlParser::KW_FUNCTION:
      case vhdlParser::KW_IMPURE: {
        enterOuterAlt(_localctx, 3);
        setState(1246);
        interface_subprogram_declaration();
        break;
      }

      case vhdlParser::KW_PACKAGE: {
        enterOuterAlt(_localctx, 4);
        setState(1247);
        interface_package_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_object_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_object_declarationContext::Interface_object_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_constant_declarationContext* vhdlParser::Interface_object_declarationContext::interface_constant_declaration() {
  return getRuleContext<vhdlParser::Interface_constant_declarationContext>(0);
}

vhdlParser::Interface_signal_declarationContext* vhdlParser::Interface_object_declarationContext::interface_signal_declaration() {
  return getRuleContext<vhdlParser::Interface_signal_declarationContext>(0);
}

vhdlParser::Interface_variable_declarationContext* vhdlParser::Interface_object_declarationContext::interface_variable_declaration() {
  return getRuleContext<vhdlParser::Interface_variable_declarationContext>(0);
}

vhdlParser::Interface_file_declarationContext* vhdlParser::Interface_object_declarationContext::interface_file_declaration() {
  return getRuleContext<vhdlParser::Interface_file_declarationContext>(0);
}


size_t vhdlParser::Interface_object_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_object_declaration;
}

void vhdlParser::Interface_object_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_object_declaration(this);
}

void vhdlParser::Interface_object_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_object_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_object_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_object_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_object_declarationContext* vhdlParser::interface_object_declaration() {
  Interface_object_declarationContext *_localctx = _tracker.createInstance<Interface_object_declarationContext>(_ctx, getState());
  enterRule(_localctx, 184, vhdlParser::RuleInterface_object_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1254);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_CONSTANT: {
        enterOuterAlt(_localctx, 1);
        setState(1250);
        interface_constant_declaration();
        break;
      }

      case vhdlParser::KW_SIGNAL:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(1251);
        interface_signal_declaration();
        break;
      }

      case vhdlParser::KW_VARIABLE: {
        enterOuterAlt(_localctx, 3);
        setState(1252);
        interface_variable_declaration();
        break;
      }

      case vhdlParser::KW_FILE: {
        enterOuterAlt(_localctx, 4);
        setState(1253);
        interface_file_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_constant_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_constant_declarationContext::Interface_constant_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_constant_declarationContext::KW_CONSTANT() {
  return getToken(vhdlParser::KW_CONSTANT, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_constant_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_constant_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_constant_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_constant_declarationContext::KW_IN() {
  return getToken(vhdlParser::KW_IN, 0);
}

tree::TerminalNode* vhdlParser::Interface_constant_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Interface_constant_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Interface_constant_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_constant_declaration;
}

void vhdlParser::Interface_constant_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_constant_declaration(this);
}

void vhdlParser::Interface_constant_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_constant_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_constant_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_constant_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_constant_declarationContext* vhdlParser::interface_constant_declaration() {
  Interface_constant_declarationContext *_localctx = _tracker.createInstance<Interface_constant_declarationContext>(_ctx, getState());
  enterRule(_localctx, 186, vhdlParser::RuleInterface_constant_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1256);
    match(vhdlParser::KW_CONSTANT);
    setState(1257);
    identifier_list();
    setState(1258);
    match(vhdlParser::COLON);
    setState(1260);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IN) {
      setState(1259);
      match(vhdlParser::KW_IN);
    }
    setState(1262);
    subtype_indication();
    setState(1265);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1263);
      match(vhdlParser::VARASGN);
      setState(1264);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_signal_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_signal_declarationContext::Interface_signal_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_signal_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_signal_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::KW_SIGNAL() {
  return getToken(vhdlParser::KW_SIGNAL, 0);
}

vhdlParser::Signal_modeContext* vhdlParser::Interface_signal_declarationContext::signal_mode() {
  return getRuleContext<vhdlParser::Signal_modeContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::KW_BUS() {
  return getToken(vhdlParser::KW_BUS, 0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Interface_signal_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Interface_signal_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_signal_declaration;
}

void vhdlParser::Interface_signal_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_signal_declaration(this);
}

void vhdlParser::Interface_signal_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_signal_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_signal_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_signal_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_signal_declarationContext* vhdlParser::interface_signal_declaration() {
  Interface_signal_declarationContext *_localctx = _tracker.createInstance<Interface_signal_declarationContext>(_ctx, getState());
  enterRule(_localctx, 188, vhdlParser::RuleInterface_signal_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1268);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_SIGNAL) {
      setState(1267);
      match(vhdlParser::KW_SIGNAL);
    }
    setState(1270);
    identifier_list();
    setState(1271);
    match(vhdlParser::COLON);
    setState(1273);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_LINKAGE

    || _la == vhdlParser::KW_BUFFER || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (vhdlParser::KW_IN - 68))
      | (1ULL << (vhdlParser::KW_INOUT - 68))
      | (1ULL << (vhdlParser::KW_OUT - 68)))) != 0)) {
      setState(1272);
      signal_mode();
    }
    setState(1275);
    subtype_indication();
    setState(1277);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_BUS) {
      setState(1276);
      match(vhdlParser::KW_BUS);
    }
    setState(1281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1279);
      match(vhdlParser::VARASGN);
      setState(1280);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_variable_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_variable_declarationContext::Interface_variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_variable_declarationContext::KW_VARIABLE() {
  return getToken(vhdlParser::KW_VARIABLE, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_variable_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_variable_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_variable_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

vhdlParser::Signal_modeContext* vhdlParser::Interface_variable_declarationContext::signal_mode() {
  return getRuleContext<vhdlParser::Signal_modeContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_variable_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Interface_variable_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Interface_variable_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_variable_declaration;
}

void vhdlParser::Interface_variable_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_variable_declaration(this);
}

void vhdlParser::Interface_variable_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_variable_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_variable_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_variable_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_variable_declarationContext* vhdlParser::interface_variable_declaration() {
  Interface_variable_declarationContext *_localctx = _tracker.createInstance<Interface_variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 190, vhdlParser::RuleInterface_variable_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1283);
    match(vhdlParser::KW_VARIABLE);
    setState(1284);
    identifier_list();
    setState(1285);
    match(vhdlParser::COLON);
    setState(1287);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_LINKAGE

    || _la == vhdlParser::KW_BUFFER || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (vhdlParser::KW_IN - 68))
      | (1ULL << (vhdlParser::KW_INOUT - 68))
      | (1ULL << (vhdlParser::KW_OUT - 68)))) != 0)) {
      setState(1286);
      signal_mode();
    }
    setState(1289);
    subtype_indication();
    setState(1292);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1290);
      match(vhdlParser::VARASGN);
      setState(1291);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_file_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_file_declarationContext::Interface_file_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_file_declarationContext::KW_FILE() {
  return getToken(vhdlParser::KW_FILE, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_file_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_file_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_file_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Interface_file_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_file_declaration;
}

void vhdlParser::Interface_file_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_file_declaration(this);
}

void vhdlParser::Interface_file_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_file_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_file_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_file_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_file_declarationContext* vhdlParser::interface_file_declaration() {
  Interface_file_declarationContext *_localctx = _tracker.createInstance<Interface_file_declarationContext>(_ctx, getState());
  enterRule(_localctx, 192, vhdlParser::RuleInterface_file_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1294);
    match(vhdlParser::KW_FILE);
    setState(1295);
    identifier_list();
    setState(1296);
    match(vhdlParser::COLON);
    setState(1297);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_modeContext ------------------------------------------------------------------

vhdlParser::Signal_modeContext::Signal_modeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Signal_modeContext::KW_IN() {
  return getToken(vhdlParser::KW_IN, 0);
}

tree::TerminalNode* vhdlParser::Signal_modeContext::KW_OUT() {
  return getToken(vhdlParser::KW_OUT, 0);
}

tree::TerminalNode* vhdlParser::Signal_modeContext::KW_INOUT() {
  return getToken(vhdlParser::KW_INOUT, 0);
}

tree::TerminalNode* vhdlParser::Signal_modeContext::KW_BUFFER() {
  return getToken(vhdlParser::KW_BUFFER, 0);
}

tree::TerminalNode* vhdlParser::Signal_modeContext::KW_LINKAGE() {
  return getToken(vhdlParser::KW_LINKAGE, 0);
}


size_t vhdlParser::Signal_modeContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_mode;
}

void vhdlParser::Signal_modeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignal_mode(this);
}

void vhdlParser::Signal_modeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignal_mode(this);
}


antlrcpp::Any vhdlParser::Signal_modeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSignal_mode(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_modeContext* vhdlParser::signal_mode() {
  Signal_modeContext *_localctx = _tracker.createInstance<Signal_modeContext>(_ctx, getState());
  enterRule(_localctx, 194, vhdlParser::RuleSignal_mode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1299);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::KW_LINKAGE

    || _la == vhdlParser::KW_BUFFER || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (vhdlParser::KW_IN - 68))
      | (1ULL << (vhdlParser::KW_INOUT - 68))
      | (1ULL << (vhdlParser::KW_OUT - 68)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_type_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_type_declarationContext::Interface_type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_incomplete_type_declarationContext* vhdlParser::Interface_type_declarationContext::interface_incomplete_type_declaration() {
  return getRuleContext<vhdlParser::Interface_incomplete_type_declarationContext>(0);
}


size_t vhdlParser::Interface_type_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_type_declaration;
}

void vhdlParser::Interface_type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_type_declaration(this);
}

void vhdlParser::Interface_type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_type_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_type_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_type_declarationContext* vhdlParser::interface_type_declaration() {
  Interface_type_declarationContext *_localctx = _tracker.createInstance<Interface_type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 196, vhdlParser::RuleInterface_type_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1301);
    interface_incomplete_type_declaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_incomplete_type_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_incomplete_type_declarationContext::Interface_incomplete_type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_incomplete_type_declarationContext::KW_TYPE() {
  return getToken(vhdlParser::KW_TYPE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Interface_incomplete_type_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Interface_incomplete_type_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_incomplete_type_declaration;
}

void vhdlParser::Interface_incomplete_type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_incomplete_type_declaration(this);
}

void vhdlParser::Interface_incomplete_type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_incomplete_type_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_incomplete_type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_incomplete_type_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_incomplete_type_declarationContext* vhdlParser::interface_incomplete_type_declaration() {
  Interface_incomplete_type_declarationContext *_localctx = _tracker.createInstance<Interface_incomplete_type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 198, vhdlParser::RuleInterface_incomplete_type_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1303);
    match(vhdlParser::KW_TYPE);
    setState(1304);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_subprogram_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_subprogram_declarationContext::Interface_subprogram_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_subprogram_specificationContext* vhdlParser::Interface_subprogram_declarationContext::interface_subprogram_specification() {
  return getRuleContext<vhdlParser::Interface_subprogram_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_subprogram_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::Interface_subprogram_defaultContext* vhdlParser::Interface_subprogram_declarationContext::interface_subprogram_default() {
  return getRuleContext<vhdlParser::Interface_subprogram_defaultContext>(0);
}


size_t vhdlParser::Interface_subprogram_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_subprogram_declaration;
}

void vhdlParser::Interface_subprogram_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_subprogram_declaration(this);
}

void vhdlParser::Interface_subprogram_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_subprogram_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_subprogram_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_subprogram_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_subprogram_declarationContext* vhdlParser::interface_subprogram_declaration() {
  Interface_subprogram_declarationContext *_localctx = _tracker.createInstance<Interface_subprogram_declarationContext>(_ctx, getState());
  enterRule(_localctx, 200, vhdlParser::RuleInterface_subprogram_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1306);
    interface_subprogram_specification();
    setState(1309);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IS) {
      setState(1307);
      match(vhdlParser::KW_IS);
      setState(1308);
      interface_subprogram_default();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_subprogram_specificationContext ------------------------------------------------------------------

vhdlParser::Interface_subprogram_specificationContext::Interface_subprogram_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_procedure_specificationContext* vhdlParser::Interface_subprogram_specificationContext::interface_procedure_specification() {
  return getRuleContext<vhdlParser::Interface_procedure_specificationContext>(0);
}

vhdlParser::Interface_function_specificationContext* vhdlParser::Interface_subprogram_specificationContext::interface_function_specification() {
  return getRuleContext<vhdlParser::Interface_function_specificationContext>(0);
}


size_t vhdlParser::Interface_subprogram_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_subprogram_specification;
}

void vhdlParser::Interface_subprogram_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_subprogram_specification(this);
}

void vhdlParser::Interface_subprogram_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_subprogram_specification(this);
}


antlrcpp::Any vhdlParser::Interface_subprogram_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_subprogram_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_subprogram_specificationContext* vhdlParser::interface_subprogram_specification() {
  Interface_subprogram_specificationContext *_localctx = _tracker.createInstance<Interface_subprogram_specificationContext>(_ctx, getState());
  enterRule(_localctx, 202, vhdlParser::RuleInterface_subprogram_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1313);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_PROCEDURE: {
        enterOuterAlt(_localctx, 1);
        setState(1311);
        interface_procedure_specification();
        break;
      }

      case vhdlParser::KW_PURE:
      case vhdlParser::KW_FUNCTION:
      case vhdlParser::KW_IMPURE: {
        enterOuterAlt(_localctx, 2);
        setState(1312);
        interface_function_specification();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_procedure_specificationContext ------------------------------------------------------------------

vhdlParser::Interface_procedure_specificationContext::Interface_procedure_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_procedure_specificationContext::KW_PROCEDURE() {
  return getToken(vhdlParser::KW_PROCEDURE, 0);
}

vhdlParser::DesignatorContext* vhdlParser::Interface_procedure_specificationContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_procedure_specificationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Formal_parameter_listContext* vhdlParser::Interface_procedure_specificationContext::formal_parameter_list() {
  return getRuleContext<vhdlParser::Formal_parameter_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_procedure_specificationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Interface_procedure_specificationContext::KW_PARAMETER() {
  return getToken(vhdlParser::KW_PARAMETER, 0);
}


size_t vhdlParser::Interface_procedure_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_procedure_specification;
}

void vhdlParser::Interface_procedure_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_procedure_specification(this);
}

void vhdlParser::Interface_procedure_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_procedure_specification(this);
}


antlrcpp::Any vhdlParser::Interface_procedure_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_procedure_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_procedure_specificationContext* vhdlParser::interface_procedure_specification() {
  Interface_procedure_specificationContext *_localctx = _tracker.createInstance<Interface_procedure_specificationContext>(_ctx, getState());
  enterRule(_localctx, 204, vhdlParser::RuleInterface_procedure_specification);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1315);
    match(vhdlParser::KW_PROCEDURE);
    setState(1316);
    designator();
    setState(1324);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PARAMETER

    || _la == vhdlParser::LPAREN) {
      setState(1318);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_PARAMETER) {
        setState(1317);
        match(vhdlParser::KW_PARAMETER);
      }
      setState(1320);
      match(vhdlParser::LPAREN);
      setState(1321);
      formal_parameter_list();
      setState(1322);
      match(vhdlParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_function_specificationContext ------------------------------------------------------------------

vhdlParser::Interface_function_specificationContext::Interface_function_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_function_specificationContext::KW_FUNCTION() {
  return getToken(vhdlParser::KW_FUNCTION, 0);
}

vhdlParser::DesignatorContext* vhdlParser::Interface_function_specificationContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_function_specificationContext::KW_RETURN() {
  return getToken(vhdlParser::KW_RETURN, 0);
}

vhdlParser::Type_markContext* vhdlParser::Interface_function_specificationContext::type_mark() {
  return getRuleContext<vhdlParser::Type_markContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_function_specificationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Formal_parameter_listContext* vhdlParser::Interface_function_specificationContext::formal_parameter_list() {
  return getRuleContext<vhdlParser::Formal_parameter_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_function_specificationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Interface_function_specificationContext::KW_PURE() {
  return getToken(vhdlParser::KW_PURE, 0);
}

tree::TerminalNode* vhdlParser::Interface_function_specificationContext::KW_IMPURE() {
  return getToken(vhdlParser::KW_IMPURE, 0);
}

tree::TerminalNode* vhdlParser::Interface_function_specificationContext::KW_PARAMETER() {
  return getToken(vhdlParser::KW_PARAMETER, 0);
}


size_t vhdlParser::Interface_function_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_function_specification;
}

void vhdlParser::Interface_function_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_function_specification(this);
}

void vhdlParser::Interface_function_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_function_specification(this);
}


antlrcpp::Any vhdlParser::Interface_function_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_function_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_function_specificationContext* vhdlParser::interface_function_specification() {
  Interface_function_specificationContext *_localctx = _tracker.createInstance<Interface_function_specificationContext>(_ctx, getState());
  enterRule(_localctx, 206, vhdlParser::RuleInterface_function_specification);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1327);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PURE

    || _la == vhdlParser::KW_IMPURE) {
      setState(1326);
      _la = _input->LA(1);
      if (!(_la == vhdlParser::KW_PURE

      || _la == vhdlParser::KW_IMPURE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1329);
    match(vhdlParser::KW_FUNCTION);
    setState(1330);
    designator();
    setState(1338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PARAMETER

    || _la == vhdlParser::LPAREN) {
      setState(1332);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_PARAMETER) {
        setState(1331);
        match(vhdlParser::KW_PARAMETER);
      }
      setState(1334);
      match(vhdlParser::LPAREN);
      setState(1335);
      formal_parameter_list();
      setState(1336);
      match(vhdlParser::RPAREN);
    }
    setState(1340);
    match(vhdlParser::KW_RETURN);
    setState(1341);
    type_mark();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_subprogram_defaultContext ------------------------------------------------------------------

vhdlParser::Interface_subprogram_defaultContext::Interface_subprogram_defaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Interface_subprogram_defaultContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_subprogram_defaultContext::BOX() {
  return getToken(vhdlParser::BOX, 0);
}


size_t vhdlParser::Interface_subprogram_defaultContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_subprogram_default;
}

void vhdlParser::Interface_subprogram_defaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_subprogram_default(this);
}

void vhdlParser::Interface_subprogram_defaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_subprogram_default(this);
}


antlrcpp::Any vhdlParser::Interface_subprogram_defaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_subprogram_default(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_subprogram_defaultContext* vhdlParser::interface_subprogram_default() {
  Interface_subprogram_defaultContext *_localctx = _tracker.createInstance<Interface_subprogram_defaultContext>(_ctx, getState());
  enterRule(_localctx, 208, vhdlParser::RuleInterface_subprogram_default);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::SHIFT_LEFT: {
        enterOuterAlt(_localctx, 1);
        setState(1343);
        name(0);
        break;
      }

      case vhdlParser::BOX: {
        enterOuterAlt(_localctx, 2);
        setState(1344);
        match(vhdlParser::BOX);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_package_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_package_declarationContext::Interface_package_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_package_declarationContext::KW_PACKAGE() {
  return getToken(vhdlParser::KW_PACKAGE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Interface_package_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_package_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Interface_package_declarationContext::KW_NEW() {
  return getToken(vhdlParser::KW_NEW, 0);
}

vhdlParser::NameContext* vhdlParser::Interface_package_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

vhdlParser::Interface_package_generic_map_aspectContext* vhdlParser::Interface_package_declarationContext::interface_package_generic_map_aspect() {
  return getRuleContext<vhdlParser::Interface_package_generic_map_aspectContext>(0);
}


size_t vhdlParser::Interface_package_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_package_declaration;
}

void vhdlParser::Interface_package_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_package_declaration(this);
}

void vhdlParser::Interface_package_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_package_declaration(this);
}


antlrcpp::Any vhdlParser::Interface_package_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_package_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_package_declarationContext* vhdlParser::interface_package_declaration() {
  Interface_package_declarationContext *_localctx = _tracker.createInstance<Interface_package_declarationContext>(_ctx, getState());
  enterRule(_localctx, 210, vhdlParser::RuleInterface_package_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1347);
    match(vhdlParser::KW_PACKAGE);
    setState(1348);
    identifier();
    setState(1349);
    match(vhdlParser::KW_IS);
    setState(1350);
    match(vhdlParser::KW_NEW);
    setState(1351);
    name(0);
    setState(1352);
    interface_package_generic_map_aspect();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_package_generic_map_aspectContext ------------------------------------------------------------------

vhdlParser::Interface_package_generic_map_aspectContext::Interface_package_generic_map_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Interface_package_generic_map_aspectContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_package_generic_map_aspectContext::KW_GENERIC() {
  return getToken(vhdlParser::KW_GENERIC, 0);
}

tree::TerminalNode* vhdlParser::Interface_package_generic_map_aspectContext::KW_MAP() {
  return getToken(vhdlParser::KW_MAP, 0);
}

tree::TerminalNode* vhdlParser::Interface_package_generic_map_aspectContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

tree::TerminalNode* vhdlParser::Interface_package_generic_map_aspectContext::BOX() {
  return getToken(vhdlParser::BOX, 0);
}

tree::TerminalNode* vhdlParser::Interface_package_generic_map_aspectContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Interface_package_generic_map_aspectContext::KW_DEFAULT() {
  return getToken(vhdlParser::KW_DEFAULT, 0);
}


size_t vhdlParser::Interface_package_generic_map_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_package_generic_map_aspect;
}

void vhdlParser::Interface_package_generic_map_aspectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_package_generic_map_aspect(this);
}

void vhdlParser::Interface_package_generic_map_aspectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_package_generic_map_aspect(this);
}


antlrcpp::Any vhdlParser::Interface_package_generic_map_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_package_generic_map_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_package_generic_map_aspectContext* vhdlParser::interface_package_generic_map_aspect() {
  Interface_package_generic_map_aspectContext *_localctx = _tracker.createInstance<Interface_package_generic_map_aspectContext>(_ctx, getState());
  enterRule(_localctx, 212, vhdlParser::RuleInterface_package_generic_map_aspect);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 124, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1354);
      generic_map_aspect();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1355);
      match(vhdlParser::KW_GENERIC);
      setState(1356);
      match(vhdlParser::KW_MAP);
      setState(1357);
      match(vhdlParser::LPAREN);
      setState(1358);
      match(vhdlParser::BOX);
      setState(1359);
      match(vhdlParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1360);
      match(vhdlParser::KW_GENERIC);
      setState(1361);
      match(vhdlParser::KW_MAP);
      setState(1362);
      match(vhdlParser::LPAREN);
      setState(1363);
      match(vhdlParser::KW_DEFAULT);
      setState(1364);
      match(vhdlParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_listContext ------------------------------------------------------------------

vhdlParser::Interface_listContext::Interface_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Interface_elementContext *> vhdlParser::Interface_listContext::interface_element() {
  return getRuleContexts<vhdlParser::Interface_elementContext>();
}

vhdlParser::Interface_elementContext* vhdlParser::Interface_listContext::interface_element(size_t i) {
  return getRuleContext<vhdlParser::Interface_elementContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Interface_listContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Interface_listContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}


size_t vhdlParser::Interface_listContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_list;
}

void vhdlParser::Interface_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_list(this);
}

void vhdlParser::Interface_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_list(this);
}


antlrcpp::Any vhdlParser::Interface_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_listContext* vhdlParser::interface_list() {
  Interface_listContext *_localctx = _tracker.createInstance<Interface_listContext>(_ctx, getState());
  enterRule(_localctx, 214, vhdlParser::RuleInterface_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1367);
    interface_element();
    setState(1372);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::SEMI) {
      setState(1368);
      match(vhdlParser::SEMI);
      setState(1369);
      interface_element();
      setState(1374);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_elementContext ------------------------------------------------------------------

vhdlParser::Interface_elementContext::Interface_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_declarationContext* vhdlParser::Interface_elementContext::interface_declaration() {
  return getRuleContext<vhdlParser::Interface_declarationContext>(0);
}


size_t vhdlParser::Interface_elementContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_element;
}

void vhdlParser::Interface_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface_element(this);
}

void vhdlParser::Interface_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface_element(this);
}


antlrcpp::Any vhdlParser::Interface_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInterface_element(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_elementContext* vhdlParser::interface_element() {
  Interface_elementContext *_localctx = _tracker.createInstance<Interface_elementContext>(_ctx, getState());
  enterRule(_localctx, 216, vhdlParser::RuleInterface_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1375);
    interface_declaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generic_clauseContext ------------------------------------------------------------------

vhdlParser::Generic_clauseContext::Generic_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Generic_clauseContext::KW_GENERIC() {
  return getToken(vhdlParser::KW_GENERIC, 0);
}

tree::TerminalNode* vhdlParser::Generic_clauseContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Generic_listContext* vhdlParser::Generic_clauseContext::generic_list() {
  return getRuleContext<vhdlParser::Generic_listContext>(0);
}

tree::TerminalNode* vhdlParser::Generic_clauseContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Generic_clauseContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Generic_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleGeneric_clause;
}

void vhdlParser::Generic_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneric_clause(this);
}

void vhdlParser::Generic_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneric_clause(this);
}


antlrcpp::Any vhdlParser::Generic_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGeneric_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generic_clauseContext* vhdlParser::generic_clause() {
  Generic_clauseContext *_localctx = _tracker.createInstance<Generic_clauseContext>(_ctx, getState());
  enterRule(_localctx, 218, vhdlParser::RuleGeneric_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1377);
    match(vhdlParser::KW_GENERIC);
    setState(1378);
    match(vhdlParser::LPAREN);
    setState(1379);
    generic_list();
    setState(1380);
    match(vhdlParser::RPAREN);
    setState(1381);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generic_listContext ------------------------------------------------------------------

vhdlParser::Generic_listContext::Generic_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_listContext* vhdlParser::Generic_listContext::interface_list() {
  return getRuleContext<vhdlParser::Interface_listContext>(0);
}


size_t vhdlParser::Generic_listContext::getRuleIndex() const {
  return vhdlParser::RuleGeneric_list;
}

void vhdlParser::Generic_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneric_list(this);
}

void vhdlParser::Generic_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneric_list(this);
}


antlrcpp::Any vhdlParser::Generic_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGeneric_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generic_listContext* vhdlParser::generic_list() {
  Generic_listContext *_localctx = _tracker.createInstance<Generic_listContext>(_ctx, getState());
  enterRule(_localctx, 220, vhdlParser::RuleGeneric_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1383);
    interface_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Port_clauseContext ------------------------------------------------------------------

vhdlParser::Port_clauseContext::Port_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Port_clauseContext::KW_PORT() {
  return getToken(vhdlParser::KW_PORT, 0);
}

tree::TerminalNode* vhdlParser::Port_clauseContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Port_listContext* vhdlParser::Port_clauseContext::port_list() {
  return getRuleContext<vhdlParser::Port_listContext>(0);
}

tree::TerminalNode* vhdlParser::Port_clauseContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Port_clauseContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Port_clauseContext::getRuleIndex() const {
  return vhdlParser::RulePort_clause;
}

void vhdlParser::Port_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPort_clause(this);
}

void vhdlParser::Port_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPort_clause(this);
}


antlrcpp::Any vhdlParser::Port_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPort_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Port_clauseContext* vhdlParser::port_clause() {
  Port_clauseContext *_localctx = _tracker.createInstance<Port_clauseContext>(_ctx, getState());
  enterRule(_localctx, 222, vhdlParser::RulePort_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1385);
    match(vhdlParser::KW_PORT);
    setState(1386);
    match(vhdlParser::LPAREN);
    setState(1387);
    port_list();
    setState(1388);
    match(vhdlParser::RPAREN);
    setState(1389);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Port_listContext ------------------------------------------------------------------

vhdlParser::Port_listContext::Port_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_listContext* vhdlParser::Port_listContext::interface_list() {
  return getRuleContext<vhdlParser::Interface_listContext>(0);
}


size_t vhdlParser::Port_listContext::getRuleIndex() const {
  return vhdlParser::RulePort_list;
}

void vhdlParser::Port_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPort_list(this);
}

void vhdlParser::Port_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPort_list(this);
}


antlrcpp::Any vhdlParser::Port_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPort_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Port_listContext* vhdlParser::port_list() {
  Port_listContext *_localctx = _tracker.createInstance<Port_listContext>(_ctx, getState());
  enterRule(_localctx, 224, vhdlParser::RulePort_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1391);
    interface_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Association_listContext ------------------------------------------------------------------

vhdlParser::Association_listContext::Association_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Association_listContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Association_elementContext *> vhdlParser::Association_listContext::association_element() {
  return getRuleContexts<vhdlParser::Association_elementContext>();
}

vhdlParser::Association_elementContext* vhdlParser::Association_listContext::association_element(size_t i) {
  return getRuleContext<vhdlParser::Association_elementContext>(i);
}

tree::TerminalNode* vhdlParser::Association_listContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Association_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Association_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Association_listContext::getRuleIndex() const {
  return vhdlParser::RuleAssociation_list;
}

void vhdlParser::Association_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssociation_list(this);
}

void vhdlParser::Association_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssociation_list(this);
}


antlrcpp::Any vhdlParser::Association_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAssociation_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Association_listContext* vhdlParser::association_list() {
  Association_listContext *_localctx = _tracker.createInstance<Association_listContext>(_ctx, getState());
  enterRule(_localctx, 226, vhdlParser::RuleAssociation_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1393);
    match(vhdlParser::LPAREN);
    setState(1394);
    association_element();
    setState(1399);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1395);
      match(vhdlParser::COMMA);
      setState(1396);
      association_element();
      setState(1401);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1402);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Association_elementContext ------------------------------------------------------------------

vhdlParser::Association_elementContext::Association_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Actual_partContext* vhdlParser::Association_elementContext::actual_part() {
  return getRuleContext<vhdlParser::Actual_partContext>(0);
}

vhdlParser::Formal_partContext* vhdlParser::Association_elementContext::formal_part() {
  return getRuleContext<vhdlParser::Formal_partContext>(0);
}

tree::TerminalNode* vhdlParser::Association_elementContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}


size_t vhdlParser::Association_elementContext::getRuleIndex() const {
  return vhdlParser::RuleAssociation_element;
}

void vhdlParser::Association_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssociation_element(this);
}

void vhdlParser::Association_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssociation_element(this);
}


antlrcpp::Any vhdlParser::Association_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAssociation_element(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Association_elementContext* vhdlParser::association_element() {
  Association_elementContext *_localctx = _tracker.createInstance<Association_elementContext>(_ctx, getState());
  enterRule(_localctx, 228, vhdlParser::RuleAssociation_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1407);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx)) {
    case 1: {
      setState(1404);
      formal_part();
      setState(1405);
      match(vhdlParser::ARROW);
      break;
    }

    default:
      break;
    }
    setState(1409);
    actual_part();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_partContext ------------------------------------------------------------------

vhdlParser::Formal_partContext::Formal_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Formal_partContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Formal_partContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

tree::TerminalNode* vhdlParser::Formal_partContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

tree::TerminalNode* vhdlParser::Formal_partContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Formal_partContext::getRuleIndex() const {
  return vhdlParser::RuleFormal_part;
}

void vhdlParser::Formal_partContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormal_part(this);
}

void vhdlParser::Formal_partContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormal_part(this);
}


antlrcpp::Any vhdlParser::Formal_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFormal_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Formal_partContext* vhdlParser::formal_part() {
  Formal_partContext *_localctx = _tracker.createInstance<Formal_partContext>(_ctx, getState());
  enterRule(_localctx, 230, vhdlParser::RuleFormal_part);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1411);
    name(0);
    setState(1416);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(1412);
      match(vhdlParser::LPAREN);
      setState(1413);
      name(0);
      setState(1414);
      match(vhdlParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Actual_partContext ------------------------------------------------------------------

vhdlParser::Actual_partContext::Actual_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Actual_partContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Actual_partContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Actual_designatorContext* vhdlParser::Actual_partContext::actual_designator() {
  return getRuleContext<vhdlParser::Actual_designatorContext>(0);
}

tree::TerminalNode* vhdlParser::Actual_partContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Actual_partContext::getRuleIndex() const {
  return vhdlParser::RuleActual_part;
}

void vhdlParser::Actual_partContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActual_part(this);
}

void vhdlParser::Actual_partContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActual_part(this);
}


antlrcpp::Any vhdlParser::Actual_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitActual_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Actual_partContext* vhdlParser::actual_part() {
  Actual_partContext *_localctx = _tracker.createInstance<Actual_partContext>(_ctx, getState());
  enterRule(_localctx, 232, vhdlParser::RuleActual_part);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1424);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 129, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1418);
      name(0);
      setState(1419);
      match(vhdlParser::LPAREN);
      setState(1420);
      actual_designator();
      setState(1421);
      match(vhdlParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1423);
      actual_designator();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Actual_designatorContext ------------------------------------------------------------------

vhdlParser::Actual_designatorContext::Actual_designatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::ExpressionContext* vhdlParser::Actual_designatorContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Actual_designatorContext::KW_INERTIAL() {
  return getToken(vhdlParser::KW_INERTIAL, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Actual_designatorContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Actual_designatorContext::KW_OPEN() {
  return getToken(vhdlParser::KW_OPEN, 0);
}


size_t vhdlParser::Actual_designatorContext::getRuleIndex() const {
  return vhdlParser::RuleActual_designator;
}

void vhdlParser::Actual_designatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActual_designator(this);
}

void vhdlParser::Actual_designatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActual_designator(this);
}


antlrcpp::Any vhdlParser::Actual_designatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitActual_designator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Actual_designatorContext* vhdlParser::actual_designator() {
  Actual_designatorContext *_localctx = _tracker.createInstance<Actual_designatorContext>(_ctx, getState());
  enterRule(_localctx, 234, vhdlParser::RuleActual_designator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1432);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1427);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_INERTIAL) {
        setState(1426);
        match(vhdlParser::KW_INERTIAL);
      }
      setState(1429);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1430);
      subtype_indication();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1431);
      match(vhdlParser::KW_OPEN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generic_map_aspectContext ------------------------------------------------------------------

vhdlParser::Generic_map_aspectContext::Generic_map_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Generic_map_aspectContext::KW_GENERIC() {
  return getToken(vhdlParser::KW_GENERIC, 0);
}

tree::TerminalNode* vhdlParser::Generic_map_aspectContext::KW_MAP() {
  return getToken(vhdlParser::KW_MAP, 0);
}

vhdlParser::Association_listContext* vhdlParser::Generic_map_aspectContext::association_list() {
  return getRuleContext<vhdlParser::Association_listContext>(0);
}


size_t vhdlParser::Generic_map_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleGeneric_map_aspect;
}

void vhdlParser::Generic_map_aspectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneric_map_aspect(this);
}

void vhdlParser::Generic_map_aspectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneric_map_aspect(this);
}


antlrcpp::Any vhdlParser::Generic_map_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGeneric_map_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::generic_map_aspect() {
  Generic_map_aspectContext *_localctx = _tracker.createInstance<Generic_map_aspectContext>(_ctx, getState());
  enterRule(_localctx, 236, vhdlParser::RuleGeneric_map_aspect);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1434);
    match(vhdlParser::KW_GENERIC);
    setState(1435);
    match(vhdlParser::KW_MAP);
    setState(1436);
    association_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Port_map_aspectContext ------------------------------------------------------------------

vhdlParser::Port_map_aspectContext::Port_map_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Port_map_aspectContext::KW_PORT() {
  return getToken(vhdlParser::KW_PORT, 0);
}

tree::TerminalNode* vhdlParser::Port_map_aspectContext::KW_MAP() {
  return getToken(vhdlParser::KW_MAP, 0);
}

vhdlParser::Association_listContext* vhdlParser::Port_map_aspectContext::association_list() {
  return getRuleContext<vhdlParser::Association_listContext>(0);
}


size_t vhdlParser::Port_map_aspectContext::getRuleIndex() const {
  return vhdlParser::RulePort_map_aspect;
}

void vhdlParser::Port_map_aspectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPort_map_aspect(this);
}

void vhdlParser::Port_map_aspectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPort_map_aspect(this);
}


antlrcpp::Any vhdlParser::Port_map_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPort_map_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Port_map_aspectContext* vhdlParser::port_map_aspect() {
  Port_map_aspectContext *_localctx = _tracker.createInstance<Port_map_aspectContext>(_ctx, getState());
  enterRule(_localctx, 238, vhdlParser::RulePort_map_aspect);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1438);
    match(vhdlParser::KW_PORT);
    setState(1439);
    match(vhdlParser::KW_MAP);
    setState(1440);
    association_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alias_declarationContext ------------------------------------------------------------------

vhdlParser::Alias_declarationContext::Alias_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Alias_declarationContext::KW_ALIAS() {
  return getToken(vhdlParser::KW_ALIAS, 0);
}

vhdlParser::Alias_designatorContext* vhdlParser::Alias_declarationContext::alias_designator() {
  return getRuleContext<vhdlParser::Alias_designatorContext>(0);
}

tree::TerminalNode* vhdlParser::Alias_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::NameContext* vhdlParser::Alias_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Alias_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Alias_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Alias_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

vhdlParser::SignatureContext* vhdlParser::Alias_declarationContext::signature() {
  return getRuleContext<vhdlParser::SignatureContext>(0);
}


size_t vhdlParser::Alias_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleAlias_declaration;
}

void vhdlParser::Alias_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlias_declaration(this);
}

void vhdlParser::Alias_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlias_declaration(this);
}


antlrcpp::Any vhdlParser::Alias_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAlias_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Alias_declarationContext* vhdlParser::alias_declaration() {
  Alias_declarationContext *_localctx = _tracker.createInstance<Alias_declarationContext>(_ctx, getState());
  enterRule(_localctx, 240, vhdlParser::RuleAlias_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1442);
    match(vhdlParser::KW_ALIAS);
    setState(1443);
    alias_designator();
    setState(1446);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::COLON) {
      setState(1444);
      match(vhdlParser::COLON);
      setState(1445);
      subtype_indication();
    }
    setState(1448);
    match(vhdlParser::KW_IS);
    setState(1449);
    name(0);
    setState(1451);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LSQUARE_BR) {
      setState(1450);
      signature();
    }
    setState(1453);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alias_designatorContext ------------------------------------------------------------------

vhdlParser::Alias_designatorContext::Alias_designatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Alias_designatorContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Alias_designatorContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}

vhdlParser::Operator_symbolContext* vhdlParser::Alias_designatorContext::operator_symbol() {
  return getRuleContext<vhdlParser::Operator_symbolContext>(0);
}


size_t vhdlParser::Alias_designatorContext::getRuleIndex() const {
  return vhdlParser::RuleAlias_designator;
}

void vhdlParser::Alias_designatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlias_designator(this);
}

void vhdlParser::Alias_designatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlias_designator(this);
}


antlrcpp::Any vhdlParser::Alias_designatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAlias_designator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Alias_designatorContext* vhdlParser::alias_designator() {
  Alias_designatorContext *_localctx = _tracker.createInstance<Alias_designatorContext>(_ctx, getState());
  enterRule(_localctx, 242, vhdlParser::RuleAlias_designator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1458);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1455);
        identifier();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1456);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1457);
        operator_symbol();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attribute_declarationContext ------------------------------------------------------------------

vhdlParser::Attribute_declarationContext::Attribute_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Attribute_declarationContext::KW_ATTRIBUTE() {
  return getToken(vhdlParser::KW_ATTRIBUTE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Attribute_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Type_markContext* vhdlParser::Attribute_declarationContext::type_mark() {
  return getRuleContext<vhdlParser::Type_markContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Attribute_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleAttribute_declaration;
}

void vhdlParser::Attribute_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute_declaration(this);
}

void vhdlParser::Attribute_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute_declaration(this);
}


antlrcpp::Any vhdlParser::Attribute_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAttribute_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Attribute_declarationContext* vhdlParser::attribute_declaration() {
  Attribute_declarationContext *_localctx = _tracker.createInstance<Attribute_declarationContext>(_ctx, getState());
  enterRule(_localctx, 244, vhdlParser::RuleAttribute_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1460);
    match(vhdlParser::KW_ATTRIBUTE);
    setState(1461);
    identifier();
    setState(1462);
    match(vhdlParser::COLON);
    setState(1463);
    type_mark();
    setState(1464);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_declarationContext ------------------------------------------------------------------

vhdlParser::Component_declarationContext::Component_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Component_declarationContext::KW_COMPONENT() {
  return getTokens(vhdlParser::KW_COMPONENT);
}

tree::TerminalNode* vhdlParser::Component_declarationContext::KW_COMPONENT(size_t i) {
  return getToken(vhdlParser::KW_COMPONENT, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Component_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Component_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Component_declarationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Component_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Component_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::Generic_clauseContext* vhdlParser::Component_declarationContext::generic_clause() {
  return getRuleContext<vhdlParser::Generic_clauseContext>(0);
}

vhdlParser::Port_clauseContext* vhdlParser::Component_declarationContext::port_clause() {
  return getRuleContext<vhdlParser::Port_clauseContext>(0);
}


size_t vhdlParser::Component_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleComponent_declaration;
}

void vhdlParser::Component_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_declaration(this);
}

void vhdlParser::Component_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_declaration(this);
}


antlrcpp::Any vhdlParser::Component_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitComponent_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Component_declarationContext* vhdlParser::component_declaration() {
  Component_declarationContext *_localctx = _tracker.createInstance<Component_declarationContext>(_ctx, getState());
  enterRule(_localctx, 246, vhdlParser::RuleComponent_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1466);
    match(vhdlParser::KW_COMPONENT);
    setState(1467);
    identifier();
    setState(1469);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IS) {
      setState(1468);
      match(vhdlParser::KW_IS);
    }
    setState(1472);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(1471);
      generic_clause();
    }
    setState(1475);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PORT) {
      setState(1474);
      port_clause();
    }
    setState(1477);
    match(vhdlParser::KW_END);
    setState(1478);
    match(vhdlParser::KW_COMPONENT);
    setState(1480);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1479);
      identifier();
    }
    setState(1482);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_template_declarationContext ------------------------------------------------------------------

vhdlParser::Group_template_declarationContext::Group_template_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::KW_GROUP() {
  return getToken(vhdlParser::KW_GROUP, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Group_template_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Entity_class_entry_listContext* vhdlParser::Group_template_declarationContext::entity_class_entry_list() {
  return getRuleContext<vhdlParser::Entity_class_entry_listContext>(0);
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Group_template_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleGroup_template_declaration;
}

void vhdlParser::Group_template_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroup_template_declaration(this);
}

void vhdlParser::Group_template_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroup_template_declaration(this);
}


antlrcpp::Any vhdlParser::Group_template_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGroup_template_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Group_template_declarationContext* vhdlParser::group_template_declaration() {
  Group_template_declarationContext *_localctx = _tracker.createInstance<Group_template_declarationContext>(_ctx, getState());
  enterRule(_localctx, 248, vhdlParser::RuleGroup_template_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1484);
    match(vhdlParser::KW_GROUP);
    setState(1485);
    identifier();
    setState(1486);
    match(vhdlParser::KW_IS);
    setState(1487);
    match(vhdlParser::LPAREN);
    setState(1488);
    entity_class_entry_list();
    setState(1489);
    match(vhdlParser::RPAREN);
    setState(1490);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_class_entry_listContext ------------------------------------------------------------------

vhdlParser::Entity_class_entry_listContext::Entity_class_entry_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Entity_class_entryContext *> vhdlParser::Entity_class_entry_listContext::entity_class_entry() {
  return getRuleContexts<vhdlParser::Entity_class_entryContext>();
}

vhdlParser::Entity_class_entryContext* vhdlParser::Entity_class_entry_listContext::entity_class_entry(size_t i) {
  return getRuleContext<vhdlParser::Entity_class_entryContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Entity_class_entry_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Entity_class_entry_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Entity_class_entry_listContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_class_entry_list;
}

void vhdlParser::Entity_class_entry_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_class_entry_list(this);
}

void vhdlParser::Entity_class_entry_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_class_entry_list(this);
}


antlrcpp::Any vhdlParser::Entity_class_entry_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_class_entry_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_class_entry_listContext* vhdlParser::entity_class_entry_list() {
  Entity_class_entry_listContext *_localctx = _tracker.createInstance<Entity_class_entry_listContext>(_ctx, getState());
  enterRule(_localctx, 250, vhdlParser::RuleEntity_class_entry_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1492);
    entity_class_entry();
    setState(1497);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1493);
      match(vhdlParser::COMMA);
      setState(1494);
      entity_class_entry();
      setState(1499);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_class_entryContext ------------------------------------------------------------------

vhdlParser::Entity_class_entryContext::Entity_class_entryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_classContext* vhdlParser::Entity_class_entryContext::entity_class() {
  return getRuleContext<vhdlParser::Entity_classContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_class_entryContext::BOX() {
  return getToken(vhdlParser::BOX, 0);
}


size_t vhdlParser::Entity_class_entryContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_class_entry;
}

void vhdlParser::Entity_class_entryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_class_entry(this);
}

void vhdlParser::Entity_class_entryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_class_entry(this);
}


antlrcpp::Any vhdlParser::Entity_class_entryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_class_entry(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_class_entryContext* vhdlParser::entity_class_entry() {
  Entity_class_entryContext *_localctx = _tracker.createInstance<Entity_class_entryContext>(_ctx, getState());
  enterRule(_localctx, 252, vhdlParser::RuleEntity_class_entry);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1500);
    entity_class();
    setState(1502);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BOX) {
      setState(1501);
      match(vhdlParser::BOX);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_declarationContext ------------------------------------------------------------------

vhdlParser::Group_declarationContext::Group_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Group_declarationContext::KW_GROUP() {
  return getToken(vhdlParser::KW_GROUP, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Group_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Group_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::NameContext* vhdlParser::Group_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Group_declarationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Group_constituent_listContext* vhdlParser::Group_declarationContext::group_constituent_list() {
  return getRuleContext<vhdlParser::Group_constituent_listContext>(0);
}

tree::TerminalNode* vhdlParser::Group_declarationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Group_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Group_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleGroup_declaration;
}

void vhdlParser::Group_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroup_declaration(this);
}

void vhdlParser::Group_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroup_declaration(this);
}


antlrcpp::Any vhdlParser::Group_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGroup_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Group_declarationContext* vhdlParser::group_declaration() {
  Group_declarationContext *_localctx = _tracker.createInstance<Group_declarationContext>(_ctx, getState());
  enterRule(_localctx, 254, vhdlParser::RuleGroup_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1504);
    match(vhdlParser::KW_GROUP);
    setState(1505);
    identifier();
    setState(1506);
    match(vhdlParser::COLON);
    setState(1507);
    name(0);
    setState(1508);
    match(vhdlParser::LPAREN);
    setState(1509);
    group_constituent_list();
    setState(1510);
    match(vhdlParser::RPAREN);
    setState(1511);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_constituent_listContext ------------------------------------------------------------------

vhdlParser::Group_constituent_listContext::Group_constituent_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Group_constituentContext *> vhdlParser::Group_constituent_listContext::group_constituent() {
  return getRuleContexts<vhdlParser::Group_constituentContext>();
}

vhdlParser::Group_constituentContext* vhdlParser::Group_constituent_listContext::group_constituent(size_t i) {
  return getRuleContext<vhdlParser::Group_constituentContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Group_constituent_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Group_constituent_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Group_constituent_listContext::getRuleIndex() const {
  return vhdlParser::RuleGroup_constituent_list;
}

void vhdlParser::Group_constituent_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroup_constituent_list(this);
}

void vhdlParser::Group_constituent_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroup_constituent_list(this);
}


antlrcpp::Any vhdlParser::Group_constituent_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGroup_constituent_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Group_constituent_listContext* vhdlParser::group_constituent_list() {
  Group_constituent_listContext *_localctx = _tracker.createInstance<Group_constituent_listContext>(_ctx, getState());
  enterRule(_localctx, 256, vhdlParser::RuleGroup_constituent_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1513);
    group_constituent();
    setState(1518);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1514);
      match(vhdlParser::COMMA);
      setState(1515);
      group_constituent();
      setState(1520);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_constituentContext ------------------------------------------------------------------

vhdlParser::Group_constituentContext::Group_constituentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Group_constituentContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::Group_constituentContext::getRuleIndex() const {
  return vhdlParser::RuleGroup_constituent;
}

void vhdlParser::Group_constituentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroup_constituent(this);
}

void vhdlParser::Group_constituentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroup_constituent(this);
}


antlrcpp::Any vhdlParser::Group_constituentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGroup_constituent(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Group_constituentContext* vhdlParser::group_constituent() {
  Group_constituentContext *_localctx = _tracker.createInstance<Group_constituentContext>(_ctx, getState());
  enterRule(_localctx, 258, vhdlParser::RuleGroup_constituent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1521);
    name(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attribute_specificationContext ------------------------------------------------------------------

vhdlParser::Attribute_specificationContext::Attribute_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Attribute_specificationContext::KW_ATTRIBUTE() {
  return getToken(vhdlParser::KW_ATTRIBUTE, 0);
}

vhdlParser::Attribute_designatorContext* vhdlParser::Attribute_specificationContext::attribute_designator() {
  return getRuleContext<vhdlParser::Attribute_designatorContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_specificationContext::KW_OF() {
  return getToken(vhdlParser::KW_OF, 0);
}

vhdlParser::Entity_specificationContext* vhdlParser::Attribute_specificationContext::entity_specification() {
  return getRuleContext<vhdlParser::Entity_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_specificationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Attribute_specificationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_specificationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Attribute_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleAttribute_specification;
}

void vhdlParser::Attribute_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute_specification(this);
}

void vhdlParser::Attribute_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute_specification(this);
}


antlrcpp::Any vhdlParser::Attribute_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAttribute_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Attribute_specificationContext* vhdlParser::attribute_specification() {
  Attribute_specificationContext *_localctx = _tracker.createInstance<Attribute_specificationContext>(_ctx, getState());
  enterRule(_localctx, 260, vhdlParser::RuleAttribute_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1523);
    match(vhdlParser::KW_ATTRIBUTE);
    setState(1524);
    attribute_designator();
    setState(1525);
    match(vhdlParser::KW_OF);
    setState(1526);
    entity_specification();
    setState(1527);
    match(vhdlParser::KW_IS);
    setState(1528);
    expression(0);
    setState(1529);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_specificationContext ------------------------------------------------------------------

vhdlParser::Entity_specificationContext::Entity_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_name_listContext* vhdlParser::Entity_specificationContext::entity_name_list() {
  return getRuleContext<vhdlParser::Entity_name_listContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_specificationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Entity_classContext* vhdlParser::Entity_specificationContext::entity_class() {
  return getRuleContext<vhdlParser::Entity_classContext>(0);
}


size_t vhdlParser::Entity_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_specification;
}

void vhdlParser::Entity_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_specification(this);
}

void vhdlParser::Entity_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_specification(this);
}


antlrcpp::Any vhdlParser::Entity_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_specificationContext* vhdlParser::entity_specification() {
  Entity_specificationContext *_localctx = _tracker.createInstance<Entity_specificationContext>(_ctx, getState());
  enterRule(_localctx, 262, vhdlParser::RuleEntity_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1531);
    entity_name_list();
    setState(1532);
    match(vhdlParser::COLON);
    setState(1533);
    entity_class();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_classContext ------------------------------------------------------------------

vhdlParser::Entity_classContext::Entity_classContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_ENTITY() {
  return getToken(vhdlParser::KW_ENTITY, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_ARCHITECTURE() {
  return getToken(vhdlParser::KW_ARCHITECTURE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_CONFIGURATION() {
  return getToken(vhdlParser::KW_CONFIGURATION, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_PROCEDURE() {
  return getToken(vhdlParser::KW_PROCEDURE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_FUNCTION() {
  return getToken(vhdlParser::KW_FUNCTION, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_PACKAGE() {
  return getToken(vhdlParser::KW_PACKAGE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_TYPE() {
  return getToken(vhdlParser::KW_TYPE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_SUBTYPE() {
  return getToken(vhdlParser::KW_SUBTYPE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_CONSTANT() {
  return getToken(vhdlParser::KW_CONSTANT, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_SIGNAL() {
  return getToken(vhdlParser::KW_SIGNAL, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_VARIABLE() {
  return getToken(vhdlParser::KW_VARIABLE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_COMPONENT() {
  return getToken(vhdlParser::KW_COMPONENT, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_LABEL() {
  return getToken(vhdlParser::KW_LABEL, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_LITERAL() {
  return getToken(vhdlParser::KW_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_UNITS() {
  return getToken(vhdlParser::KW_UNITS, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_GROUP() {
  return getToken(vhdlParser::KW_GROUP, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_FILE() {
  return getToken(vhdlParser::KW_FILE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_PROPERTY() {
  return getToken(vhdlParser::KW_PROPERTY, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::KW_SEQUENCE() {
  return getToken(vhdlParser::KW_SEQUENCE, 0);
}


size_t vhdlParser::Entity_classContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_class;
}

void vhdlParser::Entity_classContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_class(this);
}

void vhdlParser::Entity_classContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_class(this);
}


antlrcpp::Any vhdlParser::Entity_classContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_class(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_classContext* vhdlParser::entity_class() {
  Entity_classContext *_localctx = _tracker.createInstance<Entity_classContext>(_ctx, getState());
  enterRule(_localctx, 264, vhdlParser::RuleEntity_class);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1535);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_COMPONENT)
      | (1ULL << vhdlParser::KW_ENTITY)
      | (1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_SIGNAL)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_PROPERTY)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION)
      | (1ULL << vhdlParser::KW_LABEL))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (vhdlParser::KW_PACKAGE - 82))
      | (1ULL << (vhdlParser::KW_UNITS - 82))
      | (1ULL << (vhdlParser::KW_LITERAL - 82))
      | (1ULL << (vhdlParser::KW_SEQUENCE - 82))
      | (1ULL << (vhdlParser::KW_TYPE - 82))
      | (1ULL << (vhdlParser::KW_CONFIGURATION - 82))
      | (1ULL << (vhdlParser::KW_ARCHITECTURE - 82)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_name_listContext ------------------------------------------------------------------

vhdlParser::Entity_name_listContext::Entity_name_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Entity_designatorContext *> vhdlParser::Entity_name_listContext::entity_designator() {
  return getRuleContexts<vhdlParser::Entity_designatorContext>();
}

vhdlParser::Entity_designatorContext* vhdlParser::Entity_name_listContext::entity_designator(size_t i) {
  return getRuleContext<vhdlParser::Entity_designatorContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Entity_name_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Entity_name_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::Entity_name_listContext::KW_OTHERS() {
  return getToken(vhdlParser::KW_OTHERS, 0);
}

tree::TerminalNode* vhdlParser::Entity_name_listContext::KW_ALL() {
  return getToken(vhdlParser::KW_ALL, 0);
}


size_t vhdlParser::Entity_name_listContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_name_list;
}

void vhdlParser::Entity_name_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_name_list(this);
}

void vhdlParser::Entity_name_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_name_list(this);
}


antlrcpp::Any vhdlParser::Entity_name_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_name_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_name_listContext* vhdlParser::entity_name_list() {
  Entity_name_listContext *_localctx = _tracker.createInstance<Entity_name_listContext>(_ctx, getState());
  enterRule(_localctx, 266, vhdlParser::RuleEntity_name_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1547);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(1537);
        entity_designator();
        setState(1542);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(1538);
          match(vhdlParser::COMMA);
          setState(1539);
          entity_designator();
          setState(1544);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::KW_OTHERS: {
        enterOuterAlt(_localctx, 2);
        setState(1545);
        match(vhdlParser::KW_OTHERS);
        break;
      }

      case vhdlParser::KW_ALL: {
        enterOuterAlt(_localctx, 3);
        setState(1546);
        match(vhdlParser::KW_ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_designatorContext ------------------------------------------------------------------

vhdlParser::Entity_designatorContext::Entity_designatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_tagContext* vhdlParser::Entity_designatorContext::entity_tag() {
  return getRuleContext<vhdlParser::Entity_tagContext>(0);
}

vhdlParser::SignatureContext* vhdlParser::Entity_designatorContext::signature() {
  return getRuleContext<vhdlParser::SignatureContext>(0);
}


size_t vhdlParser::Entity_designatorContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_designator;
}

void vhdlParser::Entity_designatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_designator(this);
}

void vhdlParser::Entity_designatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_designator(this);
}


antlrcpp::Any vhdlParser::Entity_designatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_designator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_designatorContext* vhdlParser::entity_designator() {
  Entity_designatorContext *_localctx = _tracker.createInstance<Entity_designatorContext>(_ctx, getState());
  enterRule(_localctx, 268, vhdlParser::RuleEntity_designator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1549);
    entity_tag();
    setState(1551);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LSQUARE_BR) {
      setState(1550);
      signature();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_tagContext ------------------------------------------------------------------

vhdlParser::Entity_tagContext::Entity_tagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Entity_tagContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_tagContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}

vhdlParser::Operator_symbolContext* vhdlParser::Entity_tagContext::operator_symbol() {
  return getRuleContext<vhdlParser::Operator_symbolContext>(0);
}


size_t vhdlParser::Entity_tagContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_tag;
}

void vhdlParser::Entity_tagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_tag(this);
}

void vhdlParser::Entity_tagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_tag(this);
}


antlrcpp::Any vhdlParser::Entity_tagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_tag(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_tagContext* vhdlParser::entity_tag() {
  Entity_tagContext *_localctx = _tracker.createInstance<Entity_tagContext>(_ctx, getState());
  enterRule(_localctx, 270, vhdlParser::RuleEntity_tag);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1556);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1553);
        identifier();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1554);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1555);
        operator_symbol();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_specificationContext ------------------------------------------------------------------

vhdlParser::Configuration_specificationContext::Configuration_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Simple_configuration_specificationContext* vhdlParser::Configuration_specificationContext::simple_configuration_specification() {
  return getRuleContext<vhdlParser::Simple_configuration_specificationContext>(0);
}

vhdlParser::Compound_configuration_specificationContext* vhdlParser::Configuration_specificationContext::compound_configuration_specification() {
  return getRuleContext<vhdlParser::Compound_configuration_specificationContext>(0);
}


size_t vhdlParser::Configuration_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_specification;
}

void vhdlParser::Configuration_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfiguration_specification(this);
}

void vhdlParser::Configuration_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfiguration_specification(this);
}


antlrcpp::Any vhdlParser::Configuration_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConfiguration_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_specificationContext* vhdlParser::configuration_specification() {
  Configuration_specificationContext *_localctx = _tracker.createInstance<Configuration_specificationContext>(_ctx, getState());
  enterRule(_localctx, 272, vhdlParser::RuleConfiguration_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1560);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 146, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1558);
      simple_configuration_specification();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1559);
      compound_configuration_specification();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_configuration_specificationContext ------------------------------------------------------------------

vhdlParser::Simple_configuration_specificationContext::Simple_configuration_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Simple_configuration_specificationContext::KW_FOR() {
  return getTokens(vhdlParser::KW_FOR);
}

tree::TerminalNode* vhdlParser::Simple_configuration_specificationContext::KW_FOR(size_t i) {
  return getToken(vhdlParser::KW_FOR, i);
}

vhdlParser::Component_specificationContext* vhdlParser::Simple_configuration_specificationContext::component_specification() {
  return getRuleContext<vhdlParser::Component_specificationContext>(0);
}

vhdlParser::Binding_indicationContext* vhdlParser::Simple_configuration_specificationContext::binding_indication() {
  return getRuleContext<vhdlParser::Binding_indicationContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Simple_configuration_specificationContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Simple_configuration_specificationContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}

tree::TerminalNode* vhdlParser::Simple_configuration_specificationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}


size_t vhdlParser::Simple_configuration_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_configuration_specification;
}

void vhdlParser::Simple_configuration_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_configuration_specification(this);
}

void vhdlParser::Simple_configuration_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_configuration_specification(this);
}


antlrcpp::Any vhdlParser::Simple_configuration_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSimple_configuration_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_configuration_specificationContext* vhdlParser::simple_configuration_specification() {
  Simple_configuration_specificationContext *_localctx = _tracker.createInstance<Simple_configuration_specificationContext>(_ctx, getState());
  enterRule(_localctx, 274, vhdlParser::RuleSimple_configuration_specification);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1562);
    match(vhdlParser::KW_FOR);
    setState(1563);
    component_specification();
    setState(1564);
    binding_indication();
    setState(1565);
    match(vhdlParser::SEMI);
    setState(1569);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_END) {
      setState(1566);
      match(vhdlParser::KW_END);
      setState(1567);
      match(vhdlParser::KW_FOR);
      setState(1568);
      match(vhdlParser::SEMI);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_configuration_specificationContext ------------------------------------------------------------------

vhdlParser::Compound_configuration_specificationContext::Compound_configuration_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Compound_configuration_specificationContext::KW_FOR() {
  return getTokens(vhdlParser::KW_FOR);
}

tree::TerminalNode* vhdlParser::Compound_configuration_specificationContext::KW_FOR(size_t i) {
  return getToken(vhdlParser::KW_FOR, i);
}

vhdlParser::Component_specificationContext* vhdlParser::Compound_configuration_specificationContext::component_specification() {
  return getRuleContext<vhdlParser::Component_specificationContext>(0);
}

vhdlParser::Binding_indicationContext* vhdlParser::Compound_configuration_specificationContext::binding_indication() {
  return getRuleContext<vhdlParser::Binding_indicationContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Compound_configuration_specificationContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Compound_configuration_specificationContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}

tree::TerminalNode* vhdlParser::Compound_configuration_specificationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

std::vector<vhdlParser::Verification_unit_binding_indicationContext *> vhdlParser::Compound_configuration_specificationContext::verification_unit_binding_indication() {
  return getRuleContexts<vhdlParser::Verification_unit_binding_indicationContext>();
}

vhdlParser::Verification_unit_binding_indicationContext* vhdlParser::Compound_configuration_specificationContext::verification_unit_binding_indication(size_t i) {
  return getRuleContext<vhdlParser::Verification_unit_binding_indicationContext>(i);
}


size_t vhdlParser::Compound_configuration_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleCompound_configuration_specification;
}

void vhdlParser::Compound_configuration_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_configuration_specification(this);
}

void vhdlParser::Compound_configuration_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_configuration_specification(this);
}


antlrcpp::Any vhdlParser::Compound_configuration_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitCompound_configuration_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Compound_configuration_specificationContext* vhdlParser::compound_configuration_specification() {
  Compound_configuration_specificationContext *_localctx = _tracker.createInstance<Compound_configuration_specificationContext>(_ctx, getState());
  enterRule(_localctx, 276, vhdlParser::RuleCompound_configuration_specification);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1571);
    match(vhdlParser::KW_FOR);
    setState(1572);
    component_specification();
    setState(1573);
    binding_indication();
    setState(1574);
    match(vhdlParser::SEMI);
    setState(1578); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1575);
      verification_unit_binding_indication();
      setState(1576);
      match(vhdlParser::SEMI);
      setState(1580); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::KW_USE);
    setState(1582);
    match(vhdlParser::KW_END);
    setState(1583);
    match(vhdlParser::KW_FOR);
    setState(1584);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_specificationContext ------------------------------------------------------------------

vhdlParser::Component_specificationContext::Component_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Instantiation_listContext* vhdlParser::Component_specificationContext::instantiation_list() {
  return getRuleContext<vhdlParser::Instantiation_listContext>(0);
}

tree::TerminalNode* vhdlParser::Component_specificationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::NameContext* vhdlParser::Component_specificationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::Component_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleComponent_specification;
}

void vhdlParser::Component_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_specification(this);
}

void vhdlParser::Component_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_specification(this);
}


antlrcpp::Any vhdlParser::Component_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitComponent_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Component_specificationContext* vhdlParser::component_specification() {
  Component_specificationContext *_localctx = _tracker.createInstance<Component_specificationContext>(_ctx, getState());
  enterRule(_localctx, 278, vhdlParser::RuleComponent_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1586);
    instantiation_list();
    setState(1587);
    match(vhdlParser::COLON);
    setState(1588);
    name(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Instantiation_listContext ------------------------------------------------------------------

vhdlParser::Instantiation_listContext::Instantiation_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::LabelContext *> vhdlParser::Instantiation_listContext::label() {
  return getRuleContexts<vhdlParser::LabelContext>();
}

vhdlParser::LabelContext* vhdlParser::Instantiation_listContext::label(size_t i) {
  return getRuleContext<vhdlParser::LabelContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Instantiation_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Instantiation_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::Instantiation_listContext::KW_OTHERS() {
  return getToken(vhdlParser::KW_OTHERS, 0);
}

tree::TerminalNode* vhdlParser::Instantiation_listContext::KW_ALL() {
  return getToken(vhdlParser::KW_ALL, 0);
}


size_t vhdlParser::Instantiation_listContext::getRuleIndex() const {
  return vhdlParser::RuleInstantiation_list;
}

void vhdlParser::Instantiation_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstantiation_list(this);
}

void vhdlParser::Instantiation_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstantiation_list(this);
}


antlrcpp::Any vhdlParser::Instantiation_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInstantiation_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Instantiation_listContext* vhdlParser::instantiation_list() {
  Instantiation_listContext *_localctx = _tracker.createInstance<Instantiation_listContext>(_ctx, getState());
  enterRule(_localctx, 280, vhdlParser::RuleInstantiation_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1600);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1590);
        label();
        setState(1595);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(1591);
          match(vhdlParser::COMMA);
          setState(1592);
          label();
          setState(1597);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::KW_OTHERS: {
        enterOuterAlt(_localctx, 2);
        setState(1598);
        match(vhdlParser::KW_OTHERS);
        break;
      }

      case vhdlParser::KW_ALL: {
        enterOuterAlt(_localctx, 3);
        setState(1599);
        match(vhdlParser::KW_ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binding_indicationContext ------------------------------------------------------------------

vhdlParser::Binding_indicationContext::Binding_indicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Binding_indicationContext::KW_USE() {
  return getToken(vhdlParser::KW_USE, 0);
}

vhdlParser::Entity_aspectContext* vhdlParser::Binding_indicationContext::entity_aspect() {
  return getRuleContext<vhdlParser::Entity_aspectContext>(0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Binding_indicationContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}

vhdlParser::Port_map_aspectContext* vhdlParser::Binding_indicationContext::port_map_aspect() {
  return getRuleContext<vhdlParser::Port_map_aspectContext>(0);
}


size_t vhdlParser::Binding_indicationContext::getRuleIndex() const {
  return vhdlParser::RuleBinding_indication;
}

void vhdlParser::Binding_indicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinding_indication(this);
}

void vhdlParser::Binding_indicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinding_indication(this);
}


antlrcpp::Any vhdlParser::Binding_indicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitBinding_indication(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Binding_indicationContext* vhdlParser::binding_indication() {
  Binding_indicationContext *_localctx = _tracker.createInstance<Binding_indicationContext>(_ctx, getState());
  enterRule(_localctx, 282, vhdlParser::RuleBinding_indication);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1604);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_USE) {
      setState(1602);
      match(vhdlParser::KW_USE);
      setState(1603);
      entity_aspect();
    }
    setState(1607);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(1606);
      generic_map_aspect();
    }
    setState(1610);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PORT) {
      setState(1609);
      port_map_aspect();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_aspectContext ------------------------------------------------------------------

vhdlParser::Entity_aspectContext::Entity_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::KW_ENTITY() {
  return getToken(vhdlParser::KW_ENTITY, 0);
}

vhdlParser::NameContext* vhdlParser::Entity_aspectContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Entity_aspectContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::KW_CONFIGURATION() {
  return getToken(vhdlParser::KW_CONFIGURATION, 0);
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::KW_OPEN() {
  return getToken(vhdlParser::KW_OPEN, 0);
}


size_t vhdlParser::Entity_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_aspect;
}

void vhdlParser::Entity_aspectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_aspect(this);
}

void vhdlParser::Entity_aspectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_aspect(this);
}


antlrcpp::Any vhdlParser::Entity_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitEntity_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_aspectContext* vhdlParser::entity_aspect() {
  Entity_aspectContext *_localctx = _tracker.createInstance<Entity_aspectContext>(_ctx, getState());
  enterRule(_localctx, 284, vhdlParser::RuleEntity_aspect);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1623);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_ENTITY: {
        enterOuterAlt(_localctx, 1);
        setState(1612);
        match(vhdlParser::KW_ENTITY);
        setState(1613);
        name(0);
        setState(1618);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::LPAREN) {
          setState(1614);
          match(vhdlParser::LPAREN);
          setState(1615);
          identifier();
          setState(1616);
          match(vhdlParser::RPAREN);
        }
        break;
      }

      case vhdlParser::KW_CONFIGURATION: {
        enterOuterAlt(_localctx, 2);
        setState(1620);
        match(vhdlParser::KW_CONFIGURATION);
        setState(1621);
        name(0);
        break;
      }

      case vhdlParser::KW_OPEN: {
        enterOuterAlt(_localctx, 3);
        setState(1622);
        match(vhdlParser::KW_OPEN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Verification_unit_binding_indicationContext ------------------------------------------------------------------

vhdlParser::Verification_unit_binding_indicationContext::Verification_unit_binding_indicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Verification_unit_binding_indicationContext::KW_USE() {
  return getToken(vhdlParser::KW_USE, 0);
}

tree::TerminalNode* vhdlParser::Verification_unit_binding_indicationContext::KW_VUNIT() {
  return getToken(vhdlParser::KW_VUNIT, 0);
}

vhdlParser::Verification_unit_listContext* vhdlParser::Verification_unit_binding_indicationContext::verification_unit_list() {
  return getRuleContext<vhdlParser::Verification_unit_listContext>(0);
}


size_t vhdlParser::Verification_unit_binding_indicationContext::getRuleIndex() const {
  return vhdlParser::RuleVerification_unit_binding_indication;
}

void vhdlParser::Verification_unit_binding_indicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVerification_unit_binding_indication(this);
}

void vhdlParser::Verification_unit_binding_indicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVerification_unit_binding_indication(this);
}


antlrcpp::Any vhdlParser::Verification_unit_binding_indicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitVerification_unit_binding_indication(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Verification_unit_binding_indicationContext* vhdlParser::verification_unit_binding_indication() {
  Verification_unit_binding_indicationContext *_localctx = _tracker.createInstance<Verification_unit_binding_indicationContext>(_ctx, getState());
  enterRule(_localctx, 286, vhdlParser::RuleVerification_unit_binding_indication);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1625);
    match(vhdlParser::KW_USE);
    setState(1626);
    match(vhdlParser::KW_VUNIT);
    setState(1627);
    verification_unit_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Verification_unit_listContext ------------------------------------------------------------------

vhdlParser::Verification_unit_listContext::Verification_unit_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Verification_unit_listContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Verification_unit_listContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Verification_unit_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Verification_unit_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Verification_unit_listContext::getRuleIndex() const {
  return vhdlParser::RuleVerification_unit_list;
}

void vhdlParser::Verification_unit_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVerification_unit_list(this);
}

void vhdlParser::Verification_unit_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVerification_unit_list(this);
}


antlrcpp::Any vhdlParser::Verification_unit_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitVerification_unit_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Verification_unit_listContext* vhdlParser::verification_unit_list() {
  Verification_unit_listContext *_localctx = _tracker.createInstance<Verification_unit_listContext>(_ctx, getState());
  enterRule(_localctx, 288, vhdlParser::RuleVerification_unit_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1629);
    name(0);
    setState(1634);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1630);
      match(vhdlParser::COMMA);
      setState(1631);
      name(0);
      setState(1636);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Disconnection_specificationContext ------------------------------------------------------------------

vhdlParser::Disconnection_specificationContext::Disconnection_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Disconnection_specificationContext::KW_DISCONNECT() {
  return getToken(vhdlParser::KW_DISCONNECT, 0);
}

vhdlParser::Guarded_signal_specificationContext* vhdlParser::Disconnection_specificationContext::guarded_signal_specification() {
  return getRuleContext<vhdlParser::Guarded_signal_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Disconnection_specificationContext::KW_AFTER() {
  return getToken(vhdlParser::KW_AFTER, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Disconnection_specificationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Disconnection_specificationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Disconnection_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleDisconnection_specification;
}

void vhdlParser::Disconnection_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDisconnection_specification(this);
}

void vhdlParser::Disconnection_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDisconnection_specification(this);
}


antlrcpp::Any vhdlParser::Disconnection_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitDisconnection_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Disconnection_specificationContext* vhdlParser::disconnection_specification() {
  Disconnection_specificationContext *_localctx = _tracker.createInstance<Disconnection_specificationContext>(_ctx, getState());
  enterRule(_localctx, 290, vhdlParser::RuleDisconnection_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1637);
    match(vhdlParser::KW_DISCONNECT);
    setState(1638);
    guarded_signal_specification();
    setState(1639);
    match(vhdlParser::KW_AFTER);
    setState(1640);
    expression(0);
    setState(1641);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Guarded_signal_specificationContext ------------------------------------------------------------------

vhdlParser::Guarded_signal_specificationContext::Guarded_signal_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Signal_listContext* vhdlParser::Guarded_signal_specificationContext::signal_list() {
  return getRuleContext<vhdlParser::Signal_listContext>(0);
}

tree::TerminalNode* vhdlParser::Guarded_signal_specificationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Type_markContext* vhdlParser::Guarded_signal_specificationContext::type_mark() {
  return getRuleContext<vhdlParser::Type_markContext>(0);
}


size_t vhdlParser::Guarded_signal_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleGuarded_signal_specification;
}

void vhdlParser::Guarded_signal_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGuarded_signal_specification(this);
}

void vhdlParser::Guarded_signal_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGuarded_signal_specification(this);
}


antlrcpp::Any vhdlParser::Guarded_signal_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGuarded_signal_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Guarded_signal_specificationContext* vhdlParser::guarded_signal_specification() {
  Guarded_signal_specificationContext *_localctx = _tracker.createInstance<Guarded_signal_specificationContext>(_ctx, getState());
  enterRule(_localctx, 292, vhdlParser::RuleGuarded_signal_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1643);
    signal_list();
    setState(1644);
    match(vhdlParser::COLON);
    setState(1645);
    type_mark();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_listContext ------------------------------------------------------------------

vhdlParser::Signal_listContext::Signal_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Signal_listContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Signal_listContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Signal_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Signal_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::Signal_listContext::KW_OTHERS() {
  return getToken(vhdlParser::KW_OTHERS, 0);
}

tree::TerminalNode* vhdlParser::Signal_listContext::KW_ALL() {
  return getToken(vhdlParser::KW_ALL, 0);
}


size_t vhdlParser::Signal_listContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_list;
}

void vhdlParser::Signal_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignal_list(this);
}

void vhdlParser::Signal_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignal_list(this);
}


antlrcpp::Any vhdlParser::Signal_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSignal_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_listContext* vhdlParser::signal_list() {
  Signal_listContext *_localctx = _tracker.createInstance<Signal_listContext>(_ctx, getState());
  enterRule(_localctx, 294, vhdlParser::RuleSignal_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1657);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::SHIFT_LEFT: {
        enterOuterAlt(_localctx, 1);
        setState(1647);
        name(0);
        setState(1652);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(1648);
          match(vhdlParser::COMMA);
          setState(1649);
          name(0);
          setState(1654);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::KW_OTHERS: {
        enterOuterAlt(_localctx, 2);
        setState(1655);
        match(vhdlParser::KW_OTHERS);
        break;
      }

      case vhdlParser::KW_ALL: {
        enterOuterAlt(_localctx, 3);
        setState(1656);
        match(vhdlParser::KW_ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attribute_designatorContext ------------------------------------------------------------------

vhdlParser::Attribute_designatorContext::Attribute_designatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Attribute_designatorContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

vhdlParser::Any_keywordContext* vhdlParser::Attribute_designatorContext::any_keyword() {
  return getRuleContext<vhdlParser::Any_keywordContext>(0);
}


size_t vhdlParser::Attribute_designatorContext::getRuleIndex() const {
  return vhdlParser::RuleAttribute_designator;
}

void vhdlParser::Attribute_designatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute_designator(this);
}

void vhdlParser::Attribute_designatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute_designator(this);
}


antlrcpp::Any vhdlParser::Attribute_designatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAttribute_designator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Attribute_designatorContext* vhdlParser::attribute_designator() {
  Attribute_designatorContext *_localctx = _tracker.createInstance<Attribute_designatorContext>(_ctx, getState());
  enterRule(_localctx, 296, vhdlParser::RuleAttribute_designator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1661);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1659);
        identifier();
        break;
      }

      case vhdlParser::KW_PROCESS:
      case vhdlParser::KW_CONTEXT:
      case vhdlParser::KW_POSTPONED:
      case vhdlParser::KW_LINKAGE:
      case vhdlParser::KW_COMPONENT:
      case vhdlParser::KW_ABS:
      case vhdlParser::KW_DEFAULT:
      case vhdlParser::KW_THEN:
      case vhdlParser::KW_BLOCK:
      case vhdlParser::KW_REM:
      case vhdlParser::KW_INERTIAL:
      case vhdlParser::KW_NEXT:
      case vhdlParser::KW_ENTITY:
      case vhdlParser::KW_ON:
      case vhdlParser::KW_GROUP:
      case vhdlParser::KW_XNOR:
      case vhdlParser::KW_FILE:
      case vhdlParser::KW_PURE:
      case vhdlParser::KW_GUARDED:
      case vhdlParser::KW_GENERIC:
      case vhdlParser::KW_RANGE:
      case vhdlParser::KW_ELSE:
      case vhdlParser::KW_USE:
      case vhdlParser::KW_SHARED:
      case vhdlParser::KW_MOD:
      case vhdlParser::KW_LOOP:
      case vhdlParser::KW_RECORD:
      case vhdlParser::KW_SIGNAL:
      case vhdlParser::KW_REJECT:
      case vhdlParser::KW_BEGIN:
      case vhdlParser::KW_SLA:
      case vhdlParser::KW_DISCONNECT:
      case vhdlParser::KW_OF:
      case vhdlParser::KW_PROCEDURE:
      case vhdlParser::KW_SRL:
      case vhdlParser::KW_VUNIT:
      case vhdlParser::KW_ATTRIBUTE:
      case vhdlParser::KW_VARIABLE:
      case vhdlParser::KW_PROPERTY:
      case vhdlParser::KW_UNAFFECTED:
      case vhdlParser::KW_XOR:
      case vhdlParser::KW_REGISTER:
      case vhdlParser::KW_SUBTYPE:
      case vhdlParser::KW_TO:
      case vhdlParser::KW_NEW:
      case vhdlParser::KW_REPORT:
      case vhdlParser::KW_CONSTANT:
      case vhdlParser::KW_BUFFER:
      case vhdlParser::KW_BODY:
      case vhdlParser::KW_AFTER:
      case vhdlParser::KW_TRANSPORT:
      case vhdlParser::KW_FUNCTION:
      case vhdlParser::KW_END:
      case vhdlParser::KW_SELECT:
      case vhdlParser::KW_OR:
      case vhdlParser::KW_LIBRARY:
      case vhdlParser::KW_ELSIF:
      case vhdlParser::KW_SLL:
      case vhdlParser::KW_MAP:
      case vhdlParser::KW_SRA:
      case vhdlParser::KW_PROTECTED:
      case vhdlParser::KW_DOWNTO:
      case vhdlParser::KW_LABEL:
      case vhdlParser::KW_ALL:
      case vhdlParser::KW_ALIAS:
      case vhdlParser::KW_GENERATE:
      case vhdlParser::KW_NOR:
      case vhdlParser::KW_IN:
      case vhdlParser::KW_RELEASE:
      case vhdlParser::KW_EXIT:
      case vhdlParser::KW_RETURN:
      case vhdlParser::KW_WITH:
      case vhdlParser::KW_UNTIL:
      case vhdlParser::KW_AND:
      case vhdlParser::KW_INOUT:
      case vhdlParser::KW_WAIT:
      case vhdlParser::KW_NAND:
      case vhdlParser::KW_ARRAY:
      case vhdlParser::KW_FORCE:
      case vhdlParser::KW_WHILE:
      case vhdlParser::KW_IMPURE:
      case vhdlParser::KW_PACKAGE:
      case vhdlParser::KW_UNITS:
      case vhdlParser::KW_ASSERT:
      case vhdlParser::KW_PARAMETER:
      case vhdlParser::KW_SEVERITY:
      case vhdlParser::KW_LITERAL:
      case vhdlParser::KW_FOR:
      case vhdlParser::KW_ROR:
      case vhdlParser::KW_IF:
      case vhdlParser::KW_OUT:
      case vhdlParser::KW_ROL:
      case vhdlParser::KW_IS:
      case vhdlParser::KW_SEQUENCE:
      case vhdlParser::KW_OTHERS:
      case vhdlParser::KW_TYPE:
      case vhdlParser::KW_CASE:
      case vhdlParser::KW_NOT:
      case vhdlParser::KW_CONFIGURATION:
      case vhdlParser::KW_OPEN:
      case vhdlParser::KW_ARCHITECTURE:
      case vhdlParser::KW_BUS:
      case vhdlParser::KW_ACCESS:
      case vhdlParser::KW_WHEN:
      case vhdlParser::KW_PORT:
      case vhdlParser::KW_NULL: {
        enterOuterAlt(_localctx, 2);
        setState(1660);
        any_keyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- External_nameContext ------------------------------------------------------------------

vhdlParser::External_nameContext::External_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::External_nameContext::SHIFT_LEFT() {
  return getToken(vhdlParser::SHIFT_LEFT, 0);
}

vhdlParser::External_pathnameContext* vhdlParser::External_nameContext::external_pathname() {
  return getRuleContext<vhdlParser::External_pathnameContext>(0);
}

tree::TerminalNode* vhdlParser::External_nameContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::External_nameContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::External_nameContext::SHIFT_RIGHT() {
  return getToken(vhdlParser::SHIFT_RIGHT, 0);
}

tree::TerminalNode* vhdlParser::External_nameContext::KW_VARIABLE() {
  return getToken(vhdlParser::KW_VARIABLE, 0);
}

tree::TerminalNode* vhdlParser::External_nameContext::KW_CONSTANT() {
  return getToken(vhdlParser::KW_CONSTANT, 0);
}

tree::TerminalNode* vhdlParser::External_nameContext::KW_SIGNAL() {
  return getToken(vhdlParser::KW_SIGNAL, 0);
}


size_t vhdlParser::External_nameContext::getRuleIndex() const {
  return vhdlParser::RuleExternal_name;
}

void vhdlParser::External_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternal_name(this);
}

void vhdlParser::External_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternal_name(this);
}


antlrcpp::Any vhdlParser::External_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitExternal_name(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::External_nameContext* vhdlParser::external_name() {
  External_nameContext *_localctx = _tracker.createInstance<External_nameContext>(_ctx, getState());
  enterRule(_localctx, 298, vhdlParser::RuleExternal_name);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1663);
    match(vhdlParser::SHIFT_LEFT);
    setState(1664);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_SIGNAL)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_CONSTANT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1665);
    external_pathname();
    setState(1666);
    match(vhdlParser::COLON);
    setState(1667);
    subtype_indication();
    setState(1668);
    match(vhdlParser::SHIFT_RIGHT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- External_pathnameContext ------------------------------------------------------------------

vhdlParser::External_pathnameContext::External_pathnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Package_pathnameContext* vhdlParser::External_pathnameContext::package_pathname() {
  return getRuleContext<vhdlParser::Package_pathnameContext>(0);
}

vhdlParser::Absolute_pathnameContext* vhdlParser::External_pathnameContext::absolute_pathname() {
  return getRuleContext<vhdlParser::Absolute_pathnameContext>(0);
}

vhdlParser::Relative_pathnameContext* vhdlParser::External_pathnameContext::relative_pathname() {
  return getRuleContext<vhdlParser::Relative_pathnameContext>(0);
}


size_t vhdlParser::External_pathnameContext::getRuleIndex() const {
  return vhdlParser::RuleExternal_pathname;
}

void vhdlParser::External_pathnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternal_pathname(this);
}

void vhdlParser::External_pathnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternal_pathname(this);
}


antlrcpp::Any vhdlParser::External_pathnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitExternal_pathname(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::External_pathnameContext* vhdlParser::external_pathname() {
  External_pathnameContext *_localctx = _tracker.createInstance<External_pathnameContext>(_ctx, getState());
  enterRule(_localctx, 300, vhdlParser::RuleExternal_pathname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1673);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::AT: {
        enterOuterAlt(_localctx, 1);
        setState(1670);
        package_pathname();
        break;
      }

      case vhdlParser::DOT: {
        enterOuterAlt(_localctx, 2);
        setState(1671);
        absolute_pathname();
        break;
      }

      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::UP: {
        enterOuterAlt(_localctx, 3);
        setState(1672);
        relative_pathname();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_pathnameContext ------------------------------------------------------------------

vhdlParser::Package_pathnameContext::Package_pathnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Package_pathnameContext::AT() {
  return getToken(vhdlParser::AT, 0);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Package_pathnameContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Package_pathnameContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Package_pathnameContext::DOT() {
  return getTokens(vhdlParser::DOT);
}

tree::TerminalNode* vhdlParser::Package_pathnameContext::DOT(size_t i) {
  return getToken(vhdlParser::DOT, i);
}


size_t vhdlParser::Package_pathnameContext::getRuleIndex() const {
  return vhdlParser::RulePackage_pathname;
}

void vhdlParser::Package_pathnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackage_pathname(this);
}

void vhdlParser::Package_pathnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackage_pathname(this);
}


antlrcpp::Any vhdlParser::Package_pathnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPackage_pathname(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_pathnameContext* vhdlParser::package_pathname() {
  Package_pathnameContext *_localctx = _tracker.createInstance<Package_pathnameContext>(_ctx, getState());
  enterRule(_localctx, 302, vhdlParser::RulePackage_pathname);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1675);
    match(vhdlParser::AT);
    setState(1676);
    identifier();
    setState(1677);
    match(vhdlParser::DOT);
    setState(1678);
    identifier();
    setState(1679);
    match(vhdlParser::DOT);
    setState(1680);
    identifier();
    setState(1685);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::DOT) {
      setState(1681);
      match(vhdlParser::DOT);
      setState(1682);
      identifier();
      setState(1687);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Absolute_pathnameContext ------------------------------------------------------------------

vhdlParser::Absolute_pathnameContext::Absolute_pathnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Absolute_pathnameContext::DOT() {
  return getToken(vhdlParser::DOT, 0);
}

vhdlParser::Partial_pathnameContext* vhdlParser::Absolute_pathnameContext::partial_pathname() {
  return getRuleContext<vhdlParser::Partial_pathnameContext>(0);
}


size_t vhdlParser::Absolute_pathnameContext::getRuleIndex() const {
  return vhdlParser::RuleAbsolute_pathname;
}

void vhdlParser::Absolute_pathnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbsolute_pathname(this);
}

void vhdlParser::Absolute_pathnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbsolute_pathname(this);
}


antlrcpp::Any vhdlParser::Absolute_pathnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAbsolute_pathname(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Absolute_pathnameContext* vhdlParser::absolute_pathname() {
  Absolute_pathnameContext *_localctx = _tracker.createInstance<Absolute_pathnameContext>(_ctx, getState());
  enterRule(_localctx, 304, vhdlParser::RuleAbsolute_pathname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1688);
    match(vhdlParser::DOT);
    setState(1689);
    partial_pathname();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relative_pathnameContext ------------------------------------------------------------------

vhdlParser::Relative_pathnameContext::Relative_pathnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Partial_pathnameContext* vhdlParser::Relative_pathnameContext::partial_pathname() {
  return getRuleContext<vhdlParser::Partial_pathnameContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Relative_pathnameContext::UP() {
  return getTokens(vhdlParser::UP);
}

tree::TerminalNode* vhdlParser::Relative_pathnameContext::UP(size_t i) {
  return getToken(vhdlParser::UP, i);
}

std::vector<tree::TerminalNode *> vhdlParser::Relative_pathnameContext::DOT() {
  return getTokens(vhdlParser::DOT);
}

tree::TerminalNode* vhdlParser::Relative_pathnameContext::DOT(size_t i) {
  return getToken(vhdlParser::DOT, i);
}


size_t vhdlParser::Relative_pathnameContext::getRuleIndex() const {
  return vhdlParser::RuleRelative_pathname;
}

void vhdlParser::Relative_pathnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelative_pathname(this);
}

void vhdlParser::Relative_pathnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelative_pathname(this);
}


antlrcpp::Any vhdlParser::Relative_pathnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRelative_pathname(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Relative_pathnameContext* vhdlParser::relative_pathname() {
  Relative_pathnameContext *_localctx = _tracker.createInstance<Relative_pathnameContext>(_ctx, getState());
  enterRule(_localctx, 306, vhdlParser::RuleRelative_pathname);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1695);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::UP) {
      setState(1691);
      match(vhdlParser::UP);
      setState(1692);
      match(vhdlParser::DOT);
      setState(1697);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1698);
    partial_pathname();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Partial_pathnameContext ------------------------------------------------------------------

vhdlParser::Partial_pathnameContext::Partial_pathnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Partial_pathnameContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

std::vector<vhdlParser::Pathname_elementContext *> vhdlParser::Partial_pathnameContext::pathname_element() {
  return getRuleContexts<vhdlParser::Pathname_elementContext>();
}

vhdlParser::Pathname_elementContext* vhdlParser::Partial_pathnameContext::pathname_element(size_t i) {
  return getRuleContext<vhdlParser::Pathname_elementContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Partial_pathnameContext::DOT() {
  return getTokens(vhdlParser::DOT);
}

tree::TerminalNode* vhdlParser::Partial_pathnameContext::DOT(size_t i) {
  return getToken(vhdlParser::DOT, i);
}


size_t vhdlParser::Partial_pathnameContext::getRuleIndex() const {
  return vhdlParser::RulePartial_pathname;
}

void vhdlParser::Partial_pathnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPartial_pathname(this);
}

void vhdlParser::Partial_pathnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPartial_pathname(this);
}


antlrcpp::Any vhdlParser::Partial_pathnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPartial_pathname(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Partial_pathnameContext* vhdlParser::partial_pathname() {
  Partial_pathnameContext *_localctx = _tracker.createInstance<Partial_pathnameContext>(_ctx, getState());
  enterRule(_localctx, 308, vhdlParser::RulePartial_pathname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1705);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1700);
        pathname_element();
        setState(1701);
        match(vhdlParser::DOT); 
      }
      setState(1707);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx);
    }
    setState(1708);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pathname_elementContext ------------------------------------------------------------------

vhdlParser::Pathname_elementContext::Pathname_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::LabelContext* vhdlParser::Pathname_elementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}

tree::TerminalNode* vhdlParser::Pathname_elementContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Pathname_elementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Pathname_elementContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Pathname_elementContext::getRuleIndex() const {
  return vhdlParser::RulePathname_element;
}

void vhdlParser::Pathname_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathname_element(this);
}

void vhdlParser::Pathname_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathname_element(this);
}


antlrcpp::Any vhdlParser::Pathname_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPathname_element(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Pathname_elementContext* vhdlParser::pathname_element() {
  Pathname_elementContext *_localctx = _tracker.createInstance<Pathname_elementContext>(_ctx, getState());
  enterRule(_localctx, 310, vhdlParser::RulePathname_element);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1710);
    label();
    setState(1715);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(1711);
      match(vhdlParser::LPAREN);
      setState(1712);
      expression(0);
      setState(1713);
      match(vhdlParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

vhdlParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::ExpressionContext::COND_OP() {
  return getToken(vhdlParser::COND_OP, 0);
}

vhdlParser::PrimaryContext* vhdlParser::ExpressionContext::primary() {
  return getRuleContext<vhdlParser::PrimaryContext>(0);
}

vhdlParser::Simple_expressionContext* vhdlParser::ExpressionContext::simple_expression() {
  return getRuleContext<vhdlParser::Simple_expressionContext>(0);
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::ExpressionContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

vhdlParser::Shift_operatorContext* vhdlParser::ExpressionContext::shift_operator() {
  return getRuleContext<vhdlParser::Shift_operatorContext>(0);
}

vhdlParser::Relational_operatorContext* vhdlParser::ExpressionContext::relational_operator() {
  return getRuleContext<vhdlParser::Relational_operatorContext>(0);
}

vhdlParser::Logical_operatorContext* vhdlParser::ExpressionContext::logical_operator() {
  return getRuleContext<vhdlParser::Logical_operatorContext>(0);
}


size_t vhdlParser::ExpressionContext::getRuleIndex() const {
  return vhdlParser::RuleExpression;
}

void vhdlParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void vhdlParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any vhdlParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


vhdlParser::ExpressionContext* vhdlParser::expression() {
   return expression(0);
}

vhdlParser::ExpressionContext* vhdlParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  vhdlParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  vhdlParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 312;
  enterRecursionRule(_localctx, 312, vhdlParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1721);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::COND_OP: {
        setState(1718);
        match(vhdlParser::COND_OP);
        setState(1719);
        primary();
        break;
      }

      case vhdlParser::KW_ABS:
      case vhdlParser::KW_XNOR:
      case vhdlParser::KW_XOR:
      case vhdlParser::KW_NEW:
      case vhdlParser::KW_OR:
      case vhdlParser::KW_NOR:
      case vhdlParser::KW_AND:
      case vhdlParser::KW_NAND:
      case vhdlParser::KW_NOT:
      case vhdlParser::KW_NULL:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::DECIMAL_LITERAL:
      case vhdlParser::BASED_LITERAL:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::BIT_STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::SHIFT_LEFT:
      case vhdlParser::PLUS:
      case vhdlParser::MINUS: {
        setState(1720);
        simple_expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(1737);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 167, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1735);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1723);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1724);
          shift_operator();
          setState(1725);
          expression(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1727);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1728);
          relational_operator();
          setState(1729);
          expression(3);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1731);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1732);
          logical_operator();
          setState(1733);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(1739);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 167, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

vhdlParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::PrimaryContext *> vhdlParser::Simple_expressionContext::primary() {
  return getRuleContexts<vhdlParser::PrimaryContext>();
}

vhdlParser::PrimaryContext* vhdlParser::Simple_expressionContext::primary(size_t i) {
  return getRuleContext<vhdlParser::PrimaryContext>(i);
}

tree::TerminalNode* vhdlParser::Simple_expressionContext::DOUBLESTAR() {
  return getToken(vhdlParser::DOUBLESTAR, 0);
}

std::vector<vhdlParser::Simple_expressionContext *> vhdlParser::Simple_expressionContext::simple_expression() {
  return getRuleContexts<vhdlParser::Simple_expressionContext>();
}

vhdlParser::Simple_expressionContext* vhdlParser::Simple_expressionContext::simple_expression(size_t i) {
  return getRuleContext<vhdlParser::Simple_expressionContext>(i);
}

tree::TerminalNode* vhdlParser::Simple_expressionContext::KW_ABS() {
  return getToken(vhdlParser::KW_ABS, 0);
}

tree::TerminalNode* vhdlParser::Simple_expressionContext::KW_NOT() {
  return getToken(vhdlParser::KW_NOT, 0);
}

vhdlParser::Logical_operatorContext* vhdlParser::Simple_expressionContext::logical_operator() {
  return getRuleContext<vhdlParser::Logical_operatorContext>(0);
}

vhdlParser::SignContext* vhdlParser::Simple_expressionContext::sign() {
  return getRuleContext<vhdlParser::SignContext>(0);
}

vhdlParser::Multiplying_operatorContext* vhdlParser::Simple_expressionContext::multiplying_operator() {
  return getRuleContext<vhdlParser::Multiplying_operatorContext>(0);
}

vhdlParser::Adding_operatorContext* vhdlParser::Simple_expressionContext::adding_operator() {
  return getRuleContext<vhdlParser::Adding_operatorContext>(0);
}


size_t vhdlParser::Simple_expressionContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_expression;
}

void vhdlParser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void vhdlParser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


antlrcpp::Any vhdlParser::Simple_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSimple_expression(this);
  else
    return visitor->visitChildren(this);
}


vhdlParser::Simple_expressionContext* vhdlParser::simple_expression() {
   return simple_expression(0);
}

vhdlParser::Simple_expressionContext* vhdlParser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  vhdlParser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  vhdlParser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 314;
  enterRecursionRule(_localctx, 314, vhdlParser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1755);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_NEW:
      case vhdlParser::KW_NULL:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::DECIMAL_LITERAL:
      case vhdlParser::BASED_LITERAL:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::BIT_STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::SHIFT_LEFT: {
        setState(1741);
        primary();
        setState(1744);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx)) {
        case 1: {
          setState(1742);
          match(vhdlParser::DOUBLESTAR);
          setState(1743);
          primary();
          break;
        }

        default:
          break;
        }
        break;
      }

      case vhdlParser::KW_ABS:
      case vhdlParser::KW_XNOR:
      case vhdlParser::KW_XOR:
      case vhdlParser::KW_OR:
      case vhdlParser::KW_NOR:
      case vhdlParser::KW_AND:
      case vhdlParser::KW_NAND:
      case vhdlParser::KW_NOT: {
        setState(1749);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case vhdlParser::KW_ABS: {
            setState(1746);
            match(vhdlParser::KW_ABS);
            break;
          }

          case vhdlParser::KW_NOT: {
            setState(1747);
            match(vhdlParser::KW_NOT);
            break;
          }

          case vhdlParser::KW_XNOR:
          case vhdlParser::KW_XOR:
          case vhdlParser::KW_OR:
          case vhdlParser::KW_NOR:
          case vhdlParser::KW_AND:
          case vhdlParser::KW_NAND: {
            setState(1748);
            logical_operator();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(1751);
        simple_expression(4);
        break;
      }

      case vhdlParser::PLUS:
      case vhdlParser::MINUS: {
        setState(1752);
        sign();
        setState(1753);
        simple_expression(2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(1767);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1765);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(1757);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1758);
          multiplying_operator();
          setState(1759);
          simple_expression(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(1761);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1762);
          adding_operator();
          setState(1763);
          simple_expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(1769);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

vhdlParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Numeric_literalContext* vhdlParser::PrimaryContext::numeric_literal() {
  return getRuleContext<vhdlParser::Numeric_literalContext>(0);
}

tree::TerminalNode* vhdlParser::PrimaryContext::BIT_STRING_LITERAL() {
  return getToken(vhdlParser::BIT_STRING_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::PrimaryContext::KW_NULL() {
  return getToken(vhdlParser::KW_NULL, 0);
}

vhdlParser::AllocatorContext* vhdlParser::PrimaryContext::allocator() {
  return getRuleContext<vhdlParser::AllocatorContext>(0);
}

vhdlParser::AggregateContext* vhdlParser::PrimaryContext::aggregate() {
  return getRuleContext<vhdlParser::AggregateContext>(0);
}

vhdlParser::Qualified_expressionContext* vhdlParser::PrimaryContext::qualified_expression() {
  return getRuleContext<vhdlParser::Qualified_expressionContext>(0);
}


size_t vhdlParser::PrimaryContext::getRuleIndex() const {
  return vhdlParser::RulePrimary;
}

void vhdlParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void vhdlParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


antlrcpp::Any vhdlParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::PrimaryContext* vhdlParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 316, vhdlParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1776);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 173, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1770);
      numeric_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1771);
      match(vhdlParser::BIT_STRING_LITERAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1772);
      match(vhdlParser::KW_NULL);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1773);
      allocator();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1774);
      aggregate();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1775);
      qualified_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_operatorContext ------------------------------------------------------------------

vhdlParser::Logical_operatorContext::Logical_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::KW_AND() {
  return getToken(vhdlParser::KW_AND, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::KW_OR() {
  return getToken(vhdlParser::KW_OR, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::KW_NAND() {
  return getToken(vhdlParser::KW_NAND, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::KW_NOR() {
  return getToken(vhdlParser::KW_NOR, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::KW_XOR() {
  return getToken(vhdlParser::KW_XOR, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::KW_XNOR() {
  return getToken(vhdlParser::KW_XNOR, 0);
}


size_t vhdlParser::Logical_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleLogical_operator;
}

void vhdlParser::Logical_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_operator(this);
}

void vhdlParser::Logical_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_operator(this);
}


antlrcpp::Any vhdlParser::Logical_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitLogical_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Logical_operatorContext* vhdlParser::logical_operator() {
  Logical_operatorContext *_localctx = _tracker.createInstance<Logical_operatorContext>(_ctx, getState());
  enterRule(_localctx, 318, vhdlParser::RuleLogical_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1778);
    _la = _input->LA(1);
    if (!(((((_la - 16) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 16)) & ((1ULL << (vhdlParser::KW_XNOR - 16))
      | (1ULL << (vhdlParser::KW_XOR - 16))
      | (1ULL << (vhdlParser::KW_OR - 16))
      | (1ULL << (vhdlParser::KW_NOR - 16))
      | (1ULL << (vhdlParser::KW_AND - 16))
      | (1ULL << (vhdlParser::KW_NAND - 16)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relational_operatorContext ------------------------------------------------------------------

vhdlParser::Relational_operatorContext::Relational_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::EQ() {
  return getToken(vhdlParser::EQ, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::NE() {
  return getToken(vhdlParser::NE, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::LT() {
  return getToken(vhdlParser::LT, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::GT() {
  return getToken(vhdlParser::GT, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::GE() {
  return getToken(vhdlParser::GE, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::EQ_MATCH() {
  return getToken(vhdlParser::EQ_MATCH, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::NE_MATCH() {
  return getToken(vhdlParser::NE_MATCH, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::LT_MATCH() {
  return getToken(vhdlParser::LT_MATCH, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::LE_MATCH() {
  return getToken(vhdlParser::LE_MATCH, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::GT_MATCH() {
  return getToken(vhdlParser::GT_MATCH, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::GE_MATCH() {
  return getToken(vhdlParser::GE_MATCH, 0);
}


size_t vhdlParser::Relational_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleRelational_operator;
}

void vhdlParser::Relational_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational_operator(this);
}

void vhdlParser::Relational_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational_operator(this);
}


antlrcpp::Any vhdlParser::Relational_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitRelational_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Relational_operatorContext* vhdlParser::relational_operator() {
  Relational_operatorContext *_localctx = _tracker.createInstance<Relational_operatorContext>(_ctx, getState());
  enterRule(_localctx, 320, vhdlParser::RuleRelational_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1780);
    _la = _input->LA(1);
    if (!(((((_la - 139) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 139)) & ((1ULL << (vhdlParser::EQ - 139))
      | (1ULL << (vhdlParser::NE - 139))
      | (1ULL << (vhdlParser::LT - 139))
      | (1ULL << (vhdlParser::GT - 139))
      | (1ULL << (vhdlParser::GE - 139))
      | (1ULL << (vhdlParser::EQ_MATCH - 139))
      | (1ULL << (vhdlParser::NE_MATCH - 139))
      | (1ULL << (vhdlParser::LT_MATCH - 139))
      | (1ULL << (vhdlParser::LE_MATCH - 139))
      | (1ULL << (vhdlParser::GT_MATCH - 139))
      | (1ULL << (vhdlParser::GE_MATCH - 139))
      | (1ULL << (vhdlParser::CONASGN - 139)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Shift_operatorContext ------------------------------------------------------------------

vhdlParser::Shift_operatorContext::Shift_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::KW_SLL() {
  return getToken(vhdlParser::KW_SLL, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::KW_SRL() {
  return getToken(vhdlParser::KW_SRL, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::KW_SLA() {
  return getToken(vhdlParser::KW_SLA, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::KW_SRA() {
  return getToken(vhdlParser::KW_SRA, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::KW_ROL() {
  return getToken(vhdlParser::KW_ROL, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::KW_ROR() {
  return getToken(vhdlParser::KW_ROR, 0);
}


size_t vhdlParser::Shift_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleShift_operator;
}

void vhdlParser::Shift_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShift_operator(this);
}

void vhdlParser::Shift_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShift_operator(this);
}


antlrcpp::Any vhdlParser::Shift_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitShift_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Shift_operatorContext* vhdlParser::shift_operator() {
  Shift_operatorContext *_localctx = _tracker.createInstance<Shift_operatorContext>(_ctx, getState());
  enterRule(_localctx, 322, vhdlParser::RuleShift_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1782);
    _la = _input->LA(1);
    if (!(((((_la - 31) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 31)) & ((1ULL << (vhdlParser::KW_SLA - 31))
      | (1ULL << (vhdlParser::KW_SRL - 31))
      | (1ULL << (vhdlParser::KW_SLL - 31))
      | (1ULL << (vhdlParser::KW_SRA - 31))
      | (1ULL << (vhdlParser::KW_ROR - 31))
      | (1ULL << (vhdlParser::KW_ROL - 31)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Adding_operatorContext ------------------------------------------------------------------

vhdlParser::Adding_operatorContext::Adding_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Adding_operatorContext::PLUS() {
  return getToken(vhdlParser::PLUS, 0);
}

tree::TerminalNode* vhdlParser::Adding_operatorContext::MINUS() {
  return getToken(vhdlParser::MINUS, 0);
}

tree::TerminalNode* vhdlParser::Adding_operatorContext::AMPERSAND() {
  return getToken(vhdlParser::AMPERSAND, 0);
}


size_t vhdlParser::Adding_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleAdding_operator;
}

void vhdlParser::Adding_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdding_operator(this);
}

void vhdlParser::Adding_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdding_operator(this);
}


antlrcpp::Any vhdlParser::Adding_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAdding_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Adding_operatorContext* vhdlParser::adding_operator() {
  Adding_operatorContext *_localctx = _tracker.createInstance<Adding_operatorContext>(_ctx, getState());
  enterRule(_localctx, 324, vhdlParser::RuleAdding_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1784);
    _la = _input->LA(1);
    if (!(((((_la - 150) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 150)) & ((1ULL << (vhdlParser::PLUS - 150))
      | (1ULL << (vhdlParser::MINUS - 150))
      | (1ULL << (vhdlParser::AMPERSAND - 150)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

vhdlParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::SignContext::PLUS() {
  return getToken(vhdlParser::PLUS, 0);
}

tree::TerminalNode* vhdlParser::SignContext::MINUS() {
  return getToken(vhdlParser::MINUS, 0);
}


size_t vhdlParser::SignContext::getRuleIndex() const {
  return vhdlParser::RuleSign;
}

void vhdlParser::SignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSign(this);
}

void vhdlParser::SignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSign(this);
}


antlrcpp::Any vhdlParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::SignContext* vhdlParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 326, vhdlParser::RuleSign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1786);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::PLUS

    || _la == vhdlParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Multiplying_operatorContext ------------------------------------------------------------------

vhdlParser::Multiplying_operatorContext::Multiplying_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Multiplying_operatorContext::MUL() {
  return getToken(vhdlParser::MUL, 0);
}

tree::TerminalNode* vhdlParser::Multiplying_operatorContext::DIV() {
  return getToken(vhdlParser::DIV, 0);
}

tree::TerminalNode* vhdlParser::Multiplying_operatorContext::KW_MOD() {
  return getToken(vhdlParser::KW_MOD, 0);
}

tree::TerminalNode* vhdlParser::Multiplying_operatorContext::KW_REM() {
  return getToken(vhdlParser::KW_REM, 0);
}


size_t vhdlParser::Multiplying_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleMultiplying_operator;
}

void vhdlParser::Multiplying_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplying_operator(this);
}

void vhdlParser::Multiplying_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplying_operator(this);
}


antlrcpp::Any vhdlParser::Multiplying_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitMultiplying_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Multiplying_operatorContext* vhdlParser::multiplying_operator() {
  Multiplying_operatorContext *_localctx = _tracker.createInstance<Multiplying_operatorContext>(_ctx, getState());
  enterRule(_localctx, 328, vhdlParser::RuleMultiplying_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1788);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::KW_REM

    || _la == vhdlParser::KW_MOD || _la == vhdlParser::MUL

    || _la == vhdlParser::DIV)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Miscellaneous_operatorContext ------------------------------------------------------------------

vhdlParser::Miscellaneous_operatorContext::Miscellaneous_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Miscellaneous_operatorContext::DOUBLESTAR() {
  return getToken(vhdlParser::DOUBLESTAR, 0);
}

tree::TerminalNode* vhdlParser::Miscellaneous_operatorContext::KW_ABS() {
  return getToken(vhdlParser::KW_ABS, 0);
}

tree::TerminalNode* vhdlParser::Miscellaneous_operatorContext::KW_NOT() {
  return getToken(vhdlParser::KW_NOT, 0);
}


size_t vhdlParser::Miscellaneous_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleMiscellaneous_operator;
}

void vhdlParser::Miscellaneous_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMiscellaneous_operator(this);
}

void vhdlParser::Miscellaneous_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMiscellaneous_operator(this);
}


antlrcpp::Any vhdlParser::Miscellaneous_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitMiscellaneous_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Miscellaneous_operatorContext* vhdlParser::miscellaneous_operator() {
  Miscellaneous_operatorContext *_localctx = _tracker.createInstance<Miscellaneous_operatorContext>(_ctx, getState());
  enterRule(_localctx, 330, vhdlParser::RuleMiscellaneous_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1790);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::KW_ABS || _la == vhdlParser::KW_NOT

    || _la == vhdlParser::DOUBLESTAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Numeric_literalContext ------------------------------------------------------------------

vhdlParser::Numeric_literalContext::Numeric_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Numeric_literalContext::DECIMAL_LITERAL() {
  return getToken(vhdlParser::DECIMAL_LITERAL, 0);
}

vhdlParser::NameContext* vhdlParser::Numeric_literalContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Numeric_literalContext::BASED_LITERAL() {
  return getToken(vhdlParser::BASED_LITERAL, 0);
}


size_t vhdlParser::Numeric_literalContext::getRuleIndex() const {
  return vhdlParser::RuleNumeric_literal;
}

void vhdlParser::Numeric_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumeric_literal(this);
}

void vhdlParser::Numeric_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumeric_literal(this);
}


antlrcpp::Any vhdlParser::Numeric_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitNumeric_literal(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Numeric_literalContext* vhdlParser::numeric_literal() {
  Numeric_literalContext *_localctx = _tracker.createInstance<Numeric_literalContext>(_ctx, getState());
  enterRule(_localctx, 332, vhdlParser::RuleNumeric_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1801);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::DECIMAL_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(1792);
        match(vhdlParser::DECIMAL_LITERAL);
        setState(1794);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 174, _ctx)) {
        case 1: {
          setState(1793);
          name(0);
          break;
        }

        default:
          break;
        }
        break;
      }

      case vhdlParser::BASED_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1796);
        match(vhdlParser::BASED_LITERAL);
        setState(1798);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 175, _ctx)) {
        case 1: {
          setState(1797);
          name(0);
          break;
        }

        default:
          break;
        }
        break;
      }

      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::SHIFT_LEFT: {
        enterOuterAlt(_localctx, 3);
        setState(1800);
        name(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Physical_literalContext ------------------------------------------------------------------

vhdlParser::Physical_literalContext::Physical_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Physical_literalContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Physical_literalContext::DECIMAL_LITERAL() {
  return getToken(vhdlParser::DECIMAL_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::Physical_literalContext::BASED_LITERAL() {
  return getToken(vhdlParser::BASED_LITERAL, 0);
}


size_t vhdlParser::Physical_literalContext::getRuleIndex() const {
  return vhdlParser::RulePhysical_literal;
}

void vhdlParser::Physical_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhysical_literal(this);
}

void vhdlParser::Physical_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhysical_literal(this);
}


antlrcpp::Any vhdlParser::Physical_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPhysical_literal(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Physical_literalContext* vhdlParser::physical_literal() {
  Physical_literalContext *_localctx = _tracker.createInstance<Physical_literalContext>(_ctx, getState());
  enterRule(_localctx, 334, vhdlParser::RulePhysical_literal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1804);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::DECIMAL_LITERAL

    || _la == vhdlParser::BASED_LITERAL) {
      setState(1803);
      _la = _input->LA(1);
      if (!(_la == vhdlParser::DECIMAL_LITERAL

      || _la == vhdlParser::BASED_LITERAL)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1806);
    name(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggregateContext ------------------------------------------------------------------

vhdlParser::AggregateContext::AggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::AggregateContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Element_associationContext *> vhdlParser::AggregateContext::element_association() {
  return getRuleContexts<vhdlParser::Element_associationContext>();
}

vhdlParser::Element_associationContext* vhdlParser::AggregateContext::element_association(size_t i) {
  return getRuleContext<vhdlParser::Element_associationContext>(i);
}

tree::TerminalNode* vhdlParser::AggregateContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::AggregateContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::AggregateContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::AggregateContext::getRuleIndex() const {
  return vhdlParser::RuleAggregate;
}

void vhdlParser::AggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate(this);
}

void vhdlParser::AggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate(this);
}


antlrcpp::Any vhdlParser::AggregateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAggregate(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::AggregateContext* vhdlParser::aggregate() {
  AggregateContext *_localctx = _tracker.createInstance<AggregateContext>(_ctx, getState());
  enterRule(_localctx, 336, vhdlParser::RuleAggregate);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1808);
    match(vhdlParser::LPAREN);
    setState(1809);
    element_association();
    setState(1814);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1810);
      match(vhdlParser::COMMA);
      setState(1811);
      element_association();
      setState(1816);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1817);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_associationContext ------------------------------------------------------------------

vhdlParser::Element_associationContext::Element_associationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::ExpressionContext* vhdlParser::Element_associationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

vhdlParser::ChoicesContext* vhdlParser::Element_associationContext::choices() {
  return getRuleContext<vhdlParser::ChoicesContext>(0);
}

tree::TerminalNode* vhdlParser::Element_associationContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}


size_t vhdlParser::Element_associationContext::getRuleIndex() const {
  return vhdlParser::RuleElement_association;
}

void vhdlParser::Element_associationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_association(this);
}

void vhdlParser::Element_associationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_association(this);
}


antlrcpp::Any vhdlParser::Element_associationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitElement_association(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_associationContext* vhdlParser::element_association() {
  Element_associationContext *_localctx = _tracker.createInstance<Element_associationContext>(_ctx, getState());
  enterRule(_localctx, 338, vhdlParser::RuleElement_association);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1822);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 179, _ctx)) {
    case 1: {
      setState(1819);
      choices();
      setState(1820);
      match(vhdlParser::ARROW);
      break;
    }

    default:
      break;
    }
    setState(1824);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChoicesContext ------------------------------------------------------------------

vhdlParser::ChoicesContext::ChoicesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::ChoiceContext *> vhdlParser::ChoicesContext::choice() {
  return getRuleContexts<vhdlParser::ChoiceContext>();
}

vhdlParser::ChoiceContext* vhdlParser::ChoicesContext::choice(size_t i) {
  return getRuleContext<vhdlParser::ChoiceContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::ChoicesContext::BAR() {
  return getTokens(vhdlParser::BAR);
}

tree::TerminalNode* vhdlParser::ChoicesContext::BAR(size_t i) {
  return getToken(vhdlParser::BAR, i);
}


size_t vhdlParser::ChoicesContext::getRuleIndex() const {
  return vhdlParser::RuleChoices;
}

void vhdlParser::ChoicesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChoices(this);
}

void vhdlParser::ChoicesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChoices(this);
}


antlrcpp::Any vhdlParser::ChoicesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitChoices(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ChoicesContext* vhdlParser::choices() {
  ChoicesContext *_localctx = _tracker.createInstance<ChoicesContext>(_ctx, getState());
  enterRule(_localctx, 340, vhdlParser::RuleChoices);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1826);
    choice();
    setState(1831);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::BAR) {
      setState(1827);
      match(vhdlParser::BAR);
      setState(1828);
      choice();
      setState(1833);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChoiceContext ------------------------------------------------------------------

vhdlParser::ChoiceContext::ChoiceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Discrete_rangeContext* vhdlParser::ChoiceContext::discrete_range() {
  return getRuleContext<vhdlParser::Discrete_rangeContext>(0);
}

vhdlParser::Simple_expressionContext* vhdlParser::ChoiceContext::simple_expression() {
  return getRuleContext<vhdlParser::Simple_expressionContext>(0);
}

tree::TerminalNode* vhdlParser::ChoiceContext::KW_OTHERS() {
  return getToken(vhdlParser::KW_OTHERS, 0);
}


size_t vhdlParser::ChoiceContext::getRuleIndex() const {
  return vhdlParser::RuleChoice;
}

void vhdlParser::ChoiceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChoice(this);
}

void vhdlParser::ChoiceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChoice(this);
}


antlrcpp::Any vhdlParser::ChoiceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitChoice(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ChoiceContext* vhdlParser::choice() {
  ChoiceContext *_localctx = _tracker.createInstance<ChoiceContext>(_ctx, getState());
  enterRule(_localctx, 342, vhdlParser::RuleChoice);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1837);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 181, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1834);
      discrete_range();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1835);
      simple_expression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1836);
      match(vhdlParser::KW_OTHERS);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_expressionContext ------------------------------------------------------------------

vhdlParser::Qualified_expressionContext::Qualified_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Type_markContext* vhdlParser::Qualified_expressionContext::type_mark() {
  return getRuleContext<vhdlParser::Type_markContext>(0);
}

tree::TerminalNode* vhdlParser::Qualified_expressionContext::APOSTROPHE() {
  return getToken(vhdlParser::APOSTROPHE, 0);
}

vhdlParser::AggregateContext* vhdlParser::Qualified_expressionContext::aggregate() {
  return getRuleContext<vhdlParser::AggregateContext>(0);
}


size_t vhdlParser::Qualified_expressionContext::getRuleIndex() const {
  return vhdlParser::RuleQualified_expression;
}

void vhdlParser::Qualified_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualified_expression(this);
}

void vhdlParser::Qualified_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualified_expression(this);
}


antlrcpp::Any vhdlParser::Qualified_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitQualified_expression(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Qualified_expressionContext* vhdlParser::qualified_expression() {
  Qualified_expressionContext *_localctx = _tracker.createInstance<Qualified_expressionContext>(_ctx, getState());
  enterRule(_localctx, 344, vhdlParser::RuleQualified_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1839);
    type_mark();
    setState(1840);
    match(vhdlParser::APOSTROPHE);
    setState(1841);
    aggregate();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AllocatorContext ------------------------------------------------------------------

vhdlParser::AllocatorContext::AllocatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::AllocatorContext::KW_NEW() {
  return getToken(vhdlParser::KW_NEW, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::AllocatorContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

vhdlParser::Qualified_expressionContext* vhdlParser::AllocatorContext::qualified_expression() {
  return getRuleContext<vhdlParser::Qualified_expressionContext>(0);
}


size_t vhdlParser::AllocatorContext::getRuleIndex() const {
  return vhdlParser::RuleAllocator;
}

void vhdlParser::AllocatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAllocator(this);
}

void vhdlParser::AllocatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAllocator(this);
}


antlrcpp::Any vhdlParser::AllocatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAllocator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::AllocatorContext* vhdlParser::allocator() {
  AllocatorContext *_localctx = _tracker.createInstance<AllocatorContext>(_ctx, getState());
  enterRule(_localctx, 346, vhdlParser::RuleAllocator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1843);
    match(vhdlParser::KW_NEW);
    setState(1846);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 182, _ctx)) {
    case 1: {
      setState(1844);
      subtype_indication();
      break;
    }

    case 2: {
      setState(1845);
      qualified_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sequence_of_statementsContext ------------------------------------------------------------------

vhdlParser::Sequence_of_statementsContext::Sequence_of_statementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Sequential_statementContext *> vhdlParser::Sequence_of_statementsContext::sequential_statement() {
  return getRuleContexts<vhdlParser::Sequential_statementContext>();
}

vhdlParser::Sequential_statementContext* vhdlParser::Sequence_of_statementsContext::sequential_statement(size_t i) {
  return getRuleContext<vhdlParser::Sequential_statementContext>(i);
}


size_t vhdlParser::Sequence_of_statementsContext::getRuleIndex() const {
  return vhdlParser::RuleSequence_of_statements;
}

void vhdlParser::Sequence_of_statementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequence_of_statements(this);
}

void vhdlParser::Sequence_of_statementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequence_of_statements(this);
}


antlrcpp::Any vhdlParser::Sequence_of_statementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSequence_of_statements(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Sequence_of_statementsContext* vhdlParser::sequence_of_statements() {
  Sequence_of_statementsContext *_localctx = _tracker.createInstance<Sequence_of_statementsContext>(_ctx, getState());
  enterRule(_localctx, 348, vhdlParser::RuleSequence_of_statements);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1851);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 183, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1848);
        sequential_statement(); 
      }
      setState(1853);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 183, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sequential_statementContext ------------------------------------------------------------------

vhdlParser::Sequential_statementContext::Sequential_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Wait_statementContext* vhdlParser::Sequential_statementContext::wait_statement() {
  return getRuleContext<vhdlParser::Wait_statementContext>(0);
}

vhdlParser::Assertion_statementContext* vhdlParser::Sequential_statementContext::assertion_statement() {
  return getRuleContext<vhdlParser::Assertion_statementContext>(0);
}

vhdlParser::Report_statementContext* vhdlParser::Sequential_statementContext::report_statement() {
  return getRuleContext<vhdlParser::Report_statementContext>(0);
}

vhdlParser::Signal_assignment_statementContext* vhdlParser::Sequential_statementContext::signal_assignment_statement() {
  return getRuleContext<vhdlParser::Signal_assignment_statementContext>(0);
}

vhdlParser::Variable_assignment_statementContext* vhdlParser::Sequential_statementContext::variable_assignment_statement() {
  return getRuleContext<vhdlParser::Variable_assignment_statementContext>(0);
}

vhdlParser::Procedure_call_statementContext* vhdlParser::Sequential_statementContext::procedure_call_statement() {
  return getRuleContext<vhdlParser::Procedure_call_statementContext>(0);
}

vhdlParser::If_statementContext* vhdlParser::Sequential_statementContext::if_statement() {
  return getRuleContext<vhdlParser::If_statementContext>(0);
}

vhdlParser::Case_statementContext* vhdlParser::Sequential_statementContext::case_statement() {
  return getRuleContext<vhdlParser::Case_statementContext>(0);
}

vhdlParser::Loop_statementContext* vhdlParser::Sequential_statementContext::loop_statement() {
  return getRuleContext<vhdlParser::Loop_statementContext>(0);
}

vhdlParser::Next_statementContext* vhdlParser::Sequential_statementContext::next_statement() {
  return getRuleContext<vhdlParser::Next_statementContext>(0);
}

vhdlParser::Exit_statementContext* vhdlParser::Sequential_statementContext::exit_statement() {
  return getRuleContext<vhdlParser::Exit_statementContext>(0);
}

vhdlParser::Return_statementContext* vhdlParser::Sequential_statementContext::return_statement() {
  return getRuleContext<vhdlParser::Return_statementContext>(0);
}

vhdlParser::Null_statementContext* vhdlParser::Sequential_statementContext::null_statement() {
  return getRuleContext<vhdlParser::Null_statementContext>(0);
}

vhdlParser::LabelContext* vhdlParser::Sequential_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}

tree::TerminalNode* vhdlParser::Sequential_statementContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}


size_t vhdlParser::Sequential_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSequential_statement;
}

void vhdlParser::Sequential_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequential_statement(this);
}

void vhdlParser::Sequential_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequential_statement(this);
}


antlrcpp::Any vhdlParser::Sequential_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSequential_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Sequential_statementContext* vhdlParser::sequential_statement() {
  Sequential_statementContext *_localctx = _tracker.createInstance<Sequential_statementContext>(_ctx, getState());
  enterRule(_localctx, 350, vhdlParser::RuleSequential_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1857);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 184, _ctx)) {
    case 1: {
      setState(1854);
      label();
      setState(1855);
      match(vhdlParser::COLON);
      break;
    }

    default:
      break;
    }
    setState(1872);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 185, _ctx)) {
    case 1: {
      setState(1859);
      wait_statement();
      break;
    }

    case 2: {
      setState(1860);
      assertion_statement();
      break;
    }

    case 3: {
      setState(1861);
      report_statement();
      break;
    }

    case 4: {
      setState(1862);
      signal_assignment_statement();
      break;
    }

    case 5: {
      setState(1863);
      variable_assignment_statement();
      break;
    }

    case 6: {
      setState(1864);
      procedure_call_statement();
      break;
    }

    case 7: {
      setState(1865);
      if_statement();
      break;
    }

    case 8: {
      setState(1866);
      case_statement();
      break;
    }

    case 9: {
      setState(1867);
      loop_statement();
      break;
    }

    case 10: {
      setState(1868);
      next_statement();
      break;
    }

    case 11: {
      setState(1869);
      exit_statement();
      break;
    }

    case 12: {
      setState(1870);
      return_statement();
      break;
    }

    case 13: {
      setState(1871);
      null_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Wait_statementContext ------------------------------------------------------------------

vhdlParser::Wait_statementContext::Wait_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Wait_statementContext::KW_WAIT() {
  return getToken(vhdlParser::KW_WAIT, 0);
}

tree::TerminalNode* vhdlParser::Wait_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Sensitivity_clauseContext* vhdlParser::Wait_statementContext::sensitivity_clause() {
  return getRuleContext<vhdlParser::Sensitivity_clauseContext>(0);
}

vhdlParser::Condition_clauseContext* vhdlParser::Wait_statementContext::condition_clause() {
  return getRuleContext<vhdlParser::Condition_clauseContext>(0);
}

vhdlParser::Timeout_clauseContext* vhdlParser::Wait_statementContext::timeout_clause() {
  return getRuleContext<vhdlParser::Timeout_clauseContext>(0);
}


size_t vhdlParser::Wait_statementContext::getRuleIndex() const {
  return vhdlParser::RuleWait_statement;
}

void vhdlParser::Wait_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWait_statement(this);
}

void vhdlParser::Wait_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWait_statement(this);
}


antlrcpp::Any vhdlParser::Wait_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitWait_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Wait_statementContext* vhdlParser::wait_statement() {
  Wait_statementContext *_localctx = _tracker.createInstance<Wait_statementContext>(_ctx, getState());
  enterRule(_localctx, 352, vhdlParser::RuleWait_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1874);
    match(vhdlParser::KW_WAIT);
    setState(1876);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_ON) {
      setState(1875);
      sensitivity_clause();
    }
    setState(1879);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_UNTIL) {
      setState(1878);
      condition_clause();
    }
    setState(1882);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_FOR) {
      setState(1881);
      timeout_clause();
    }
    setState(1884);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sensitivity_clauseContext ------------------------------------------------------------------

vhdlParser::Sensitivity_clauseContext::Sensitivity_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Sensitivity_clauseContext::KW_ON() {
  return getToken(vhdlParser::KW_ON, 0);
}

vhdlParser::Sensitivity_listContext* vhdlParser::Sensitivity_clauseContext::sensitivity_list() {
  return getRuleContext<vhdlParser::Sensitivity_listContext>(0);
}


size_t vhdlParser::Sensitivity_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleSensitivity_clause;
}

void vhdlParser::Sensitivity_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSensitivity_clause(this);
}

void vhdlParser::Sensitivity_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSensitivity_clause(this);
}


antlrcpp::Any vhdlParser::Sensitivity_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSensitivity_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Sensitivity_clauseContext* vhdlParser::sensitivity_clause() {
  Sensitivity_clauseContext *_localctx = _tracker.createInstance<Sensitivity_clauseContext>(_ctx, getState());
  enterRule(_localctx, 354, vhdlParser::RuleSensitivity_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1886);
    match(vhdlParser::KW_ON);
    setState(1887);
    sensitivity_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sensitivity_listContext ------------------------------------------------------------------

vhdlParser::Sensitivity_listContext::Sensitivity_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Sensitivity_listContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Sensitivity_listContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Sensitivity_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Sensitivity_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Sensitivity_listContext::getRuleIndex() const {
  return vhdlParser::RuleSensitivity_list;
}

void vhdlParser::Sensitivity_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSensitivity_list(this);
}

void vhdlParser::Sensitivity_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSensitivity_list(this);
}


antlrcpp::Any vhdlParser::Sensitivity_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSensitivity_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Sensitivity_listContext* vhdlParser::sensitivity_list() {
  Sensitivity_listContext *_localctx = _tracker.createInstance<Sensitivity_listContext>(_ctx, getState());
  enterRule(_localctx, 356, vhdlParser::RuleSensitivity_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1889);
    name(0);
    setState(1894);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1890);
      match(vhdlParser::COMMA);
      setState(1891);
      name(0);
      setState(1896);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_clauseContext ------------------------------------------------------------------

vhdlParser::Condition_clauseContext::Condition_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Condition_clauseContext::KW_UNTIL() {
  return getToken(vhdlParser::KW_UNTIL, 0);
}

vhdlParser::ConditionContext* vhdlParser::Condition_clauseContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}


size_t vhdlParser::Condition_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleCondition_clause;
}

void vhdlParser::Condition_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition_clause(this);
}

void vhdlParser::Condition_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition_clause(this);
}


antlrcpp::Any vhdlParser::Condition_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitCondition_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Condition_clauseContext* vhdlParser::condition_clause() {
  Condition_clauseContext *_localctx = _tracker.createInstance<Condition_clauseContext>(_ctx, getState());
  enterRule(_localctx, 358, vhdlParser::RuleCondition_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1897);
    match(vhdlParser::KW_UNTIL);
    setState(1898);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

vhdlParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::ExpressionContext* vhdlParser::ConditionContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::ConditionContext::getRuleIndex() const {
  return vhdlParser::RuleCondition;
}

void vhdlParser::ConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition(this);
}

void vhdlParser::ConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition(this);
}


antlrcpp::Any vhdlParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ConditionContext* vhdlParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 360, vhdlParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1900);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Timeout_clauseContext ------------------------------------------------------------------

vhdlParser::Timeout_clauseContext::Timeout_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Timeout_clauseContext::KW_FOR() {
  return getToken(vhdlParser::KW_FOR, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Timeout_clauseContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Timeout_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleTimeout_clause;
}

void vhdlParser::Timeout_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeout_clause(this);
}

void vhdlParser::Timeout_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeout_clause(this);
}


antlrcpp::Any vhdlParser::Timeout_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitTimeout_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Timeout_clauseContext* vhdlParser::timeout_clause() {
  Timeout_clauseContext *_localctx = _tracker.createInstance<Timeout_clauseContext>(_ctx, getState());
  enterRule(_localctx, 362, vhdlParser::RuleTimeout_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1902);
    match(vhdlParser::KW_FOR);
    setState(1903);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assertion_statementContext ------------------------------------------------------------------

vhdlParser::Assertion_statementContext::Assertion_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::AssertionContext* vhdlParser::Assertion_statementContext::assertion() {
  return getRuleContext<vhdlParser::AssertionContext>(0);
}

tree::TerminalNode* vhdlParser::Assertion_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Assertion_statementContext::getRuleIndex() const {
  return vhdlParser::RuleAssertion_statement;
}

void vhdlParser::Assertion_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssertion_statement(this);
}

void vhdlParser::Assertion_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssertion_statement(this);
}


antlrcpp::Any vhdlParser::Assertion_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAssertion_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Assertion_statementContext* vhdlParser::assertion_statement() {
  Assertion_statementContext *_localctx = _tracker.createInstance<Assertion_statementContext>(_ctx, getState());
  enterRule(_localctx, 364, vhdlParser::RuleAssertion_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1905);
    assertion();
    setState(1906);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssertionContext ------------------------------------------------------------------

vhdlParser::AssertionContext::AssertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::AssertionContext::KW_ASSERT() {
  return getToken(vhdlParser::KW_ASSERT, 0);
}

vhdlParser::ConditionContext* vhdlParser::AssertionContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}

tree::TerminalNode* vhdlParser::AssertionContext::KW_REPORT() {
  return getToken(vhdlParser::KW_REPORT, 0);
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::AssertionContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::AssertionContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

tree::TerminalNode* vhdlParser::AssertionContext::KW_SEVERITY() {
  return getToken(vhdlParser::KW_SEVERITY, 0);
}


size_t vhdlParser::AssertionContext::getRuleIndex() const {
  return vhdlParser::RuleAssertion;
}

void vhdlParser::AssertionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssertion(this);
}

void vhdlParser::AssertionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssertion(this);
}


antlrcpp::Any vhdlParser::AssertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitAssertion(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::AssertionContext* vhdlParser::assertion() {
  AssertionContext *_localctx = _tracker.createInstance<AssertionContext>(_ctx, getState());
  enterRule(_localctx, 366, vhdlParser::RuleAssertion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1908);
    match(vhdlParser::KW_ASSERT);
    setState(1909);
    condition();
    setState(1912);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_REPORT) {
      setState(1910);
      match(vhdlParser::KW_REPORT);
      setState(1911);
      expression(0);
    }
    setState(1916);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_SEVERITY) {
      setState(1914);
      match(vhdlParser::KW_SEVERITY);
      setState(1915);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Report_statementContext ------------------------------------------------------------------

vhdlParser::Report_statementContext::Report_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Report_statementContext::KW_REPORT() {
  return getToken(vhdlParser::KW_REPORT, 0);
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Report_statementContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Report_statementContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

tree::TerminalNode* vhdlParser::Report_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Report_statementContext::KW_SEVERITY() {
  return getToken(vhdlParser::KW_SEVERITY, 0);
}


size_t vhdlParser::Report_statementContext::getRuleIndex() const {
  return vhdlParser::RuleReport_statement;
}

void vhdlParser::Report_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReport_statement(this);
}

void vhdlParser::Report_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReport_statement(this);
}


antlrcpp::Any vhdlParser::Report_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitReport_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Report_statementContext* vhdlParser::report_statement() {
  Report_statementContext *_localctx = _tracker.createInstance<Report_statementContext>(_ctx, getState());
  enterRule(_localctx, 368, vhdlParser::RuleReport_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1918);
    match(vhdlParser::KW_REPORT);
    setState(1919);
    expression(0);
    setState(1922);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_SEVERITY) {
      setState(1920);
      match(vhdlParser::KW_SEVERITY);
      setState(1921);
      expression(0);
    }
    setState(1924);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_assignment_statementContext ------------------------------------------------------------------

vhdlParser::Signal_assignment_statementContext::Signal_assignment_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Simple_signal_assignmentContext* vhdlParser::Signal_assignment_statementContext::simple_signal_assignment() {
  return getRuleContext<vhdlParser::Simple_signal_assignmentContext>(0);
}

vhdlParser::Conditional_signal_assignmentContext* vhdlParser::Signal_assignment_statementContext::conditional_signal_assignment() {
  return getRuleContext<vhdlParser::Conditional_signal_assignmentContext>(0);
}

vhdlParser::Selected_signal_assignmentContext* vhdlParser::Signal_assignment_statementContext::selected_signal_assignment() {
  return getRuleContext<vhdlParser::Selected_signal_assignmentContext>(0);
}


size_t vhdlParser::Signal_assignment_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_assignment_statement;
}

void vhdlParser::Signal_assignment_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignal_assignment_statement(this);
}

void vhdlParser::Signal_assignment_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignal_assignment_statement(this);
}


antlrcpp::Any vhdlParser::Signal_assignment_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSignal_assignment_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_assignment_statementContext* vhdlParser::signal_assignment_statement() {
  Signal_assignment_statementContext *_localctx = _tracker.createInstance<Signal_assignment_statementContext>(_ctx, getState());
  enterRule(_localctx, 370, vhdlParser::RuleSignal_assignment_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1929);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 193, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1926);
      simple_signal_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1927);
      conditional_signal_assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1928);
      selected_signal_assignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_signal_assignmentContext::Simple_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Simple_waveform_assignmentContext* vhdlParser::Simple_signal_assignmentContext::simple_waveform_assignment() {
  return getRuleContext<vhdlParser::Simple_waveform_assignmentContext>(0);
}

vhdlParser::Simple_force_assignmentContext* vhdlParser::Simple_signal_assignmentContext::simple_force_assignment() {
  return getRuleContext<vhdlParser::Simple_force_assignmentContext>(0);
}

vhdlParser::Simple_release_assignmentContext* vhdlParser::Simple_signal_assignmentContext::simple_release_assignment() {
  return getRuleContext<vhdlParser::Simple_release_assignmentContext>(0);
}


size_t vhdlParser::Simple_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_signal_assignment;
}

void vhdlParser::Simple_signal_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_signal_assignment(this);
}

void vhdlParser::Simple_signal_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_signal_assignment(this);
}


antlrcpp::Any vhdlParser::Simple_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSimple_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_signal_assignmentContext* vhdlParser::simple_signal_assignment() {
  Simple_signal_assignmentContext *_localctx = _tracker.createInstance<Simple_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 372, vhdlParser::RuleSimple_signal_assignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1934);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 194, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1931);
      simple_waveform_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1932);
      simple_force_assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1933);
      simple_release_assignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_waveform_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_waveform_assignmentContext::Simple_waveform_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Simple_waveform_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_waveform_assignmentContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

vhdlParser::WaveformContext* vhdlParser::Simple_waveform_assignmentContext::waveform() {
  return getRuleContext<vhdlParser::WaveformContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_waveform_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Delay_mechanismContext* vhdlParser::Simple_waveform_assignmentContext::delay_mechanism() {
  return getRuleContext<vhdlParser::Delay_mechanismContext>(0);
}


size_t vhdlParser::Simple_waveform_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_waveform_assignment;
}

void vhdlParser::Simple_waveform_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_waveform_assignment(this);
}

void vhdlParser::Simple_waveform_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_waveform_assignment(this);
}


antlrcpp::Any vhdlParser::Simple_waveform_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSimple_waveform_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_waveform_assignmentContext* vhdlParser::simple_waveform_assignment() {
  Simple_waveform_assignmentContext *_localctx = _tracker.createInstance<Simple_waveform_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 374, vhdlParser::RuleSimple_waveform_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1936);
    target();
    setState(1937);
    match(vhdlParser::CONASGN);
    setState(1939);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_INERTIAL)
      | (1ULL << vhdlParser::KW_REJECT)
      | (1ULL << vhdlParser::KW_TRANSPORT))) != 0)) {
      setState(1938);
      delay_mechanism();
    }
    setState(1941);
    waveform();
    setState(1942);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_force_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_force_assignmentContext::Simple_force_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Simple_force_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_force_assignmentContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

tree::TerminalNode* vhdlParser::Simple_force_assignmentContext::KW_FORCE() {
  return getToken(vhdlParser::KW_FORCE, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Simple_force_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_force_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Force_modeContext* vhdlParser::Simple_force_assignmentContext::force_mode() {
  return getRuleContext<vhdlParser::Force_modeContext>(0);
}


size_t vhdlParser::Simple_force_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_force_assignment;
}

void vhdlParser::Simple_force_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_force_assignment(this);
}

void vhdlParser::Simple_force_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_force_assignment(this);
}


antlrcpp::Any vhdlParser::Simple_force_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSimple_force_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_force_assignmentContext* vhdlParser::simple_force_assignment() {
  Simple_force_assignmentContext *_localctx = _tracker.createInstance<Simple_force_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 376, vhdlParser::RuleSimple_force_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1944);
    target();
    setState(1945);
    match(vhdlParser::CONASGN);
    setState(1946);
    match(vhdlParser::KW_FORCE);
    setState(1948);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IN

    || _la == vhdlParser::KW_OUT) {
      setState(1947);
      force_mode();
    }
    setState(1950);
    expression(0);
    setState(1951);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_release_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_release_assignmentContext::Simple_release_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Simple_release_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_release_assignmentContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

tree::TerminalNode* vhdlParser::Simple_release_assignmentContext::KW_RELEASE() {
  return getToken(vhdlParser::KW_RELEASE, 0);
}

tree::TerminalNode* vhdlParser::Simple_release_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Force_modeContext* vhdlParser::Simple_release_assignmentContext::force_mode() {
  return getRuleContext<vhdlParser::Force_modeContext>(0);
}


size_t vhdlParser::Simple_release_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_release_assignment;
}

void vhdlParser::Simple_release_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_release_assignment(this);
}

void vhdlParser::Simple_release_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_release_assignment(this);
}


antlrcpp::Any vhdlParser::Simple_release_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSimple_release_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_release_assignmentContext* vhdlParser::simple_release_assignment() {
  Simple_release_assignmentContext *_localctx = _tracker.createInstance<Simple_release_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 378, vhdlParser::RuleSimple_release_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1953);
    target();
    setState(1954);
    match(vhdlParser::CONASGN);
    setState(1955);
    match(vhdlParser::KW_RELEASE);
    setState(1957);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IN

    || _la == vhdlParser::KW_OUT) {
      setState(1956);
      force_mode();
    }
    setState(1959);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Force_modeContext ------------------------------------------------------------------

vhdlParser::Force_modeContext::Force_modeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Force_modeContext::KW_IN() {
  return getToken(vhdlParser::KW_IN, 0);
}

tree::TerminalNode* vhdlParser::Force_modeContext::KW_OUT() {
  return getToken(vhdlParser::KW_OUT, 0);
}


size_t vhdlParser::Force_modeContext::getRuleIndex() const {
  return vhdlParser::RuleForce_mode;
}

void vhdlParser::Force_modeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForce_mode(this);
}

void vhdlParser::Force_modeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForce_mode(this);
}


antlrcpp::Any vhdlParser::Force_modeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitForce_mode(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Force_modeContext* vhdlParser::force_mode() {
  Force_modeContext *_localctx = _tracker.createInstance<Force_modeContext>(_ctx, getState());
  enterRule(_localctx, 380, vhdlParser::RuleForce_mode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1961);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::KW_IN

    || _la == vhdlParser::KW_OUT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Delay_mechanismContext ------------------------------------------------------------------

vhdlParser::Delay_mechanismContext::Delay_mechanismContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Delay_mechanismContext::KW_TRANSPORT() {
  return getToken(vhdlParser::KW_TRANSPORT, 0);
}

tree::TerminalNode* vhdlParser::Delay_mechanismContext::KW_INERTIAL() {
  return getToken(vhdlParser::KW_INERTIAL, 0);
}

tree::TerminalNode* vhdlParser::Delay_mechanismContext::KW_REJECT() {
  return getToken(vhdlParser::KW_REJECT, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Delay_mechanismContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Delay_mechanismContext::getRuleIndex() const {
  return vhdlParser::RuleDelay_mechanism;
}

void vhdlParser::Delay_mechanismContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelay_mechanism(this);
}

void vhdlParser::Delay_mechanismContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelay_mechanism(this);
}


antlrcpp::Any vhdlParser::Delay_mechanismContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitDelay_mechanism(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Delay_mechanismContext* vhdlParser::delay_mechanism() {
  Delay_mechanismContext *_localctx = _tracker.createInstance<Delay_mechanismContext>(_ctx, getState());
  enterRule(_localctx, 382, vhdlParser::RuleDelay_mechanism);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1969);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_TRANSPORT: {
        enterOuterAlt(_localctx, 1);
        setState(1963);
        match(vhdlParser::KW_TRANSPORT);
        break;
      }

      case vhdlParser::KW_INERTIAL:
      case vhdlParser::KW_REJECT: {
        enterOuterAlt(_localctx, 2);
        setState(1966);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::KW_REJECT) {
          setState(1964);
          match(vhdlParser::KW_REJECT);
          setState(1965);
          expression(0);
        }
        setState(1968);
        match(vhdlParser::KW_INERTIAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetContext ------------------------------------------------------------------

vhdlParser::TargetContext::TargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::TargetContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

vhdlParser::AggregateContext* vhdlParser::TargetContext::aggregate() {
  return getRuleContext<vhdlParser::AggregateContext>(0);
}


size_t vhdlParser::TargetContext::getRuleIndex() const {
  return vhdlParser::RuleTarget;
}

void vhdlParser::TargetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTarget(this);
}

void vhdlParser::TargetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTarget(this);
}


antlrcpp::Any vhdlParser::TargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitTarget(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::TargetContext* vhdlParser::target() {
  TargetContext *_localctx = _tracker.createInstance<TargetContext>(_ctx, getState());
  enterRule(_localctx, 384, vhdlParser::RuleTarget);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1973);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::SHIFT_LEFT: {
        enterOuterAlt(_localctx, 1);
        setState(1971);
        name(0);
        break;
      }

      case vhdlParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(1972);
        aggregate();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WaveformContext ------------------------------------------------------------------

vhdlParser::WaveformContext::WaveformContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Waveform_elementContext *> vhdlParser::WaveformContext::waveform_element() {
  return getRuleContexts<vhdlParser::Waveform_elementContext>();
}

vhdlParser::Waveform_elementContext* vhdlParser::WaveformContext::waveform_element(size_t i) {
  return getRuleContext<vhdlParser::Waveform_elementContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::WaveformContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::WaveformContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::WaveformContext::KW_UNAFFECTED() {
  return getToken(vhdlParser::KW_UNAFFECTED, 0);
}


size_t vhdlParser::WaveformContext::getRuleIndex() const {
  return vhdlParser::RuleWaveform;
}

void vhdlParser::WaveformContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWaveform(this);
}

void vhdlParser::WaveformContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWaveform(this);
}


antlrcpp::Any vhdlParser::WaveformContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitWaveform(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::WaveformContext* vhdlParser::waveform() {
  WaveformContext *_localctx = _tracker.createInstance<WaveformContext>(_ctx, getState());
  enterRule(_localctx, 386, vhdlParser::RuleWaveform);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1984);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_ABS:
      case vhdlParser::KW_XNOR:
      case vhdlParser::KW_XOR:
      case vhdlParser::KW_NEW:
      case vhdlParser::KW_OR:
      case vhdlParser::KW_NOR:
      case vhdlParser::KW_AND:
      case vhdlParser::KW_NAND:
      case vhdlParser::KW_NOT:
      case vhdlParser::KW_NULL:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::DECIMAL_LITERAL:
      case vhdlParser::BASED_LITERAL:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::BIT_STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::SHIFT_LEFT:
      case vhdlParser::PLUS:
      case vhdlParser::MINUS:
      case vhdlParser::COND_OP: {
        enterOuterAlt(_localctx, 1);
        setState(1975);
        waveform_element();
        setState(1980);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(1976);
          match(vhdlParser::COMMA);
          setState(1977);
          waveform_element();
          setState(1982);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::KW_UNAFFECTED: {
        enterOuterAlt(_localctx, 2);
        setState(1983);
        match(vhdlParser::KW_UNAFFECTED);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Waveform_elementContext ------------------------------------------------------------------

vhdlParser::Waveform_elementContext::Waveform_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Waveform_elementContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Waveform_elementContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

tree::TerminalNode* vhdlParser::Waveform_elementContext::KW_AFTER() {
  return getToken(vhdlParser::KW_AFTER, 0);
}

tree::TerminalNode* vhdlParser::Waveform_elementContext::KW_NULL() {
  return getToken(vhdlParser::KW_NULL, 0);
}


size_t vhdlParser::Waveform_elementContext::getRuleIndex() const {
  return vhdlParser::RuleWaveform_element;
}

void vhdlParser::Waveform_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWaveform_element(this);
}

void vhdlParser::Waveform_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWaveform_element(this);
}


antlrcpp::Any vhdlParser::Waveform_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitWaveform_element(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Waveform_elementContext* vhdlParser::waveform_element() {
  Waveform_elementContext *_localctx = _tracker.createInstance<Waveform_elementContext>(_ctx, getState());
  enterRule(_localctx, 388, vhdlParser::RuleWaveform_element);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1996);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 205, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1986);
      expression(0);
      setState(1989);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_AFTER) {
        setState(1987);
        match(vhdlParser::KW_AFTER);
        setState(1988);
        expression(0);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1991);
      match(vhdlParser::KW_NULL);
      setState(1994);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_AFTER) {
        setState(1992);
        match(vhdlParser::KW_AFTER);
        setState(1993);
        expression(0);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Conditional_signal_assignmentContext::Conditional_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Conditional_waveform_assignmentContext* vhdlParser::Conditional_signal_assignmentContext::conditional_waveform_assignment() {
  return getRuleContext<vhdlParser::Conditional_waveform_assignmentContext>(0);
}

vhdlParser::Conditional_force_assignmentContext* vhdlParser::Conditional_signal_assignmentContext::conditional_force_assignment() {
  return getRuleContext<vhdlParser::Conditional_force_assignmentContext>(0);
}


size_t vhdlParser::Conditional_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_signal_assignment;
}

void vhdlParser::Conditional_signal_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional_signal_assignment(this);
}

void vhdlParser::Conditional_signal_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional_signal_assignment(this);
}


antlrcpp::Any vhdlParser::Conditional_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConditional_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_signal_assignmentContext* vhdlParser::conditional_signal_assignment() {
  Conditional_signal_assignmentContext *_localctx = _tracker.createInstance<Conditional_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 390, vhdlParser::RuleConditional_signal_assignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2000);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 206, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1998);
      conditional_waveform_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1999);
      conditional_force_assignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_waveform_assignmentContext ------------------------------------------------------------------

vhdlParser::Conditional_waveform_assignmentContext::Conditional_waveform_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Conditional_waveform_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_waveform_assignmentContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

vhdlParser::Conditional_waveformsContext* vhdlParser::Conditional_waveform_assignmentContext::conditional_waveforms() {
  return getRuleContext<vhdlParser::Conditional_waveformsContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_waveform_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Delay_mechanismContext* vhdlParser::Conditional_waveform_assignmentContext::delay_mechanism() {
  return getRuleContext<vhdlParser::Delay_mechanismContext>(0);
}


size_t vhdlParser::Conditional_waveform_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_waveform_assignment;
}

void vhdlParser::Conditional_waveform_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional_waveform_assignment(this);
}

void vhdlParser::Conditional_waveform_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional_waveform_assignment(this);
}


antlrcpp::Any vhdlParser::Conditional_waveform_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConditional_waveform_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_waveform_assignmentContext* vhdlParser::conditional_waveform_assignment() {
  Conditional_waveform_assignmentContext *_localctx = _tracker.createInstance<Conditional_waveform_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 392, vhdlParser::RuleConditional_waveform_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2002);
    target();
    setState(2003);
    match(vhdlParser::CONASGN);
    setState(2005);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_INERTIAL)
      | (1ULL << vhdlParser::KW_REJECT)
      | (1ULL << vhdlParser::KW_TRANSPORT))) != 0)) {
      setState(2004);
      delay_mechanism();
    }
    setState(2007);
    conditional_waveforms();
    setState(2008);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_waveformsContext ------------------------------------------------------------------

vhdlParser::Conditional_waveformsContext::Conditional_waveformsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::WaveformContext *> vhdlParser::Conditional_waveformsContext::waveform() {
  return getRuleContexts<vhdlParser::WaveformContext>();
}

vhdlParser::WaveformContext* vhdlParser::Conditional_waveformsContext::waveform(size_t i) {
  return getRuleContext<vhdlParser::WaveformContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Conditional_waveformsContext::KW_WHEN() {
  return getTokens(vhdlParser::KW_WHEN);
}

tree::TerminalNode* vhdlParser::Conditional_waveformsContext::KW_WHEN(size_t i) {
  return getToken(vhdlParser::KW_WHEN, i);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::Conditional_waveformsContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::Conditional_waveformsContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Conditional_waveformsContext::KW_ELSE() {
  return getTokens(vhdlParser::KW_ELSE);
}

tree::TerminalNode* vhdlParser::Conditional_waveformsContext::KW_ELSE(size_t i) {
  return getToken(vhdlParser::KW_ELSE, i);
}


size_t vhdlParser::Conditional_waveformsContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_waveforms;
}

void vhdlParser::Conditional_waveformsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional_waveforms(this);
}

void vhdlParser::Conditional_waveformsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional_waveforms(this);
}


antlrcpp::Any vhdlParser::Conditional_waveformsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConditional_waveforms(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_waveformsContext* vhdlParser::conditional_waveforms() {
  Conditional_waveformsContext *_localctx = _tracker.createInstance<Conditional_waveformsContext>(_ctx, getState());
  enterRule(_localctx, 394, vhdlParser::RuleConditional_waveforms);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2010);
    waveform();
    setState(2011);
    match(vhdlParser::KW_WHEN);
    setState(2012);
    condition();
    setState(2020);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 208, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2013);
        match(vhdlParser::KW_ELSE);
        setState(2014);
        waveform();
        setState(2015);
        match(vhdlParser::KW_WHEN);
        setState(2016);
        condition(); 
      }
      setState(2022);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 208, _ctx);
    }
    setState(2026);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 209, _ctx)) {
    case 1: {
      setState(2023);
      match(vhdlParser::KW_ELSE);
      setState(2024);
      waveform();
      break;
    }

    case 2: {
      setState(2025);

      if (!(_input->LA(1) != KW_ELSE)) throw FailedPredicateException(this, "_input->LA(1) != KW_ELSE");
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_force_assignmentContext ------------------------------------------------------------------

vhdlParser::Conditional_force_assignmentContext::Conditional_force_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Conditional_force_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_force_assignmentContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

tree::TerminalNode* vhdlParser::Conditional_force_assignmentContext::KW_FORCE() {
  return getToken(vhdlParser::KW_FORCE, 0);
}

vhdlParser::Conditional_expressionsContext* vhdlParser::Conditional_force_assignmentContext::conditional_expressions() {
  return getRuleContext<vhdlParser::Conditional_expressionsContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_force_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Force_modeContext* vhdlParser::Conditional_force_assignmentContext::force_mode() {
  return getRuleContext<vhdlParser::Force_modeContext>(0);
}


size_t vhdlParser::Conditional_force_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_force_assignment;
}

void vhdlParser::Conditional_force_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional_force_assignment(this);
}

void vhdlParser::Conditional_force_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional_force_assignment(this);
}


antlrcpp::Any vhdlParser::Conditional_force_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConditional_force_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_force_assignmentContext* vhdlParser::conditional_force_assignment() {
  Conditional_force_assignmentContext *_localctx = _tracker.createInstance<Conditional_force_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 396, vhdlParser::RuleConditional_force_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2028);
    target();
    setState(2029);
    match(vhdlParser::CONASGN);
    setState(2030);
    match(vhdlParser::KW_FORCE);
    setState(2032);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IN

    || _la == vhdlParser::KW_OUT) {
      setState(2031);
      force_mode();
    }
    setState(2034);
    conditional_expressions();
    setState(2035);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_expressionsContext ------------------------------------------------------------------

vhdlParser::Conditional_expressionsContext::Conditional_expressionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Conditional_expressionsContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Conditional_expressionsContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Conditional_expressionsContext::KW_WHEN() {
  return getTokens(vhdlParser::KW_WHEN);
}

tree::TerminalNode* vhdlParser::Conditional_expressionsContext::KW_WHEN(size_t i) {
  return getToken(vhdlParser::KW_WHEN, i);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::Conditional_expressionsContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::Conditional_expressionsContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Conditional_expressionsContext::KW_ELSE() {
  return getTokens(vhdlParser::KW_ELSE);
}

tree::TerminalNode* vhdlParser::Conditional_expressionsContext::KW_ELSE(size_t i) {
  return getToken(vhdlParser::KW_ELSE, i);
}


size_t vhdlParser::Conditional_expressionsContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_expressions;
}

void vhdlParser::Conditional_expressionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional_expressions(this);
}

void vhdlParser::Conditional_expressionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional_expressions(this);
}


antlrcpp::Any vhdlParser::Conditional_expressionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConditional_expressions(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_expressionsContext* vhdlParser::conditional_expressions() {
  Conditional_expressionsContext *_localctx = _tracker.createInstance<Conditional_expressionsContext>(_ctx, getState());
  enterRule(_localctx, 398, vhdlParser::RuleConditional_expressions);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2037);
    expression(0);
    setState(2038);
    match(vhdlParser::KW_WHEN);
    setState(2039);
    condition();
    setState(2047);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 211, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2040);
        match(vhdlParser::KW_ELSE);
        setState(2041);
        expression(0);
        setState(2042);
        match(vhdlParser::KW_WHEN);
        setState(2043);
        condition(); 
      }
      setState(2049);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 211, _ctx);
    }
    setState(2053);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 212, _ctx)) {
    case 1: {
      setState(2050);
      match(vhdlParser::KW_ELSE);
      setState(2051);
      expression(0);
      break;
    }

    case 2: {
      setState(2052);

      if (!(_input->LA(1) != KW_ELSE)) throw FailedPredicateException(this, "_input->LA(1) != KW_ELSE");
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Selected_signal_assignmentContext::Selected_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Selected_waveform_assignmentContext* vhdlParser::Selected_signal_assignmentContext::selected_waveform_assignment() {
  return getRuleContext<vhdlParser::Selected_waveform_assignmentContext>(0);
}

vhdlParser::Selected_force_assignmentContext* vhdlParser::Selected_signal_assignmentContext::selected_force_assignment() {
  return getRuleContext<vhdlParser::Selected_force_assignmentContext>(0);
}


size_t vhdlParser::Selected_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_signal_assignment;
}

void vhdlParser::Selected_signal_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelected_signal_assignment(this);
}

void vhdlParser::Selected_signal_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelected_signal_assignment(this);
}


antlrcpp::Any vhdlParser::Selected_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSelected_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_signal_assignmentContext* vhdlParser::selected_signal_assignment() {
  Selected_signal_assignmentContext *_localctx = _tracker.createInstance<Selected_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 400, vhdlParser::RuleSelected_signal_assignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2057);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 213, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2055);
      selected_waveform_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2056);
      selected_force_assignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_waveform_assignmentContext ------------------------------------------------------------------

vhdlParser::Selected_waveform_assignmentContext::Selected_waveform_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Selected_waveform_assignmentContext::KW_WITH() {
  return getToken(vhdlParser::KW_WITH, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Selected_waveform_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_waveform_assignmentContext::KW_SELECT() {
  return getToken(vhdlParser::KW_SELECT, 0);
}

vhdlParser::TargetContext* vhdlParser::Selected_waveform_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_waveform_assignmentContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

vhdlParser::Selected_waveformsContext* vhdlParser::Selected_waveform_assignmentContext::selected_waveforms() {
  return getRuleContext<vhdlParser::Selected_waveformsContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_waveform_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Selected_waveform_assignmentContext::QUESTIONMARK() {
  return getToken(vhdlParser::QUESTIONMARK, 0);
}

vhdlParser::Delay_mechanismContext* vhdlParser::Selected_waveform_assignmentContext::delay_mechanism() {
  return getRuleContext<vhdlParser::Delay_mechanismContext>(0);
}


size_t vhdlParser::Selected_waveform_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_waveform_assignment;
}

void vhdlParser::Selected_waveform_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelected_waveform_assignment(this);
}

void vhdlParser::Selected_waveform_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelected_waveform_assignment(this);
}


antlrcpp::Any vhdlParser::Selected_waveform_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSelected_waveform_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_waveform_assignmentContext* vhdlParser::selected_waveform_assignment() {
  Selected_waveform_assignmentContext *_localctx = _tracker.createInstance<Selected_waveform_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 402, vhdlParser::RuleSelected_waveform_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2059);
    match(vhdlParser::KW_WITH);
    setState(2060);
    expression(0);
    setState(2061);
    match(vhdlParser::KW_SELECT);
    setState(2063);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::QUESTIONMARK) {
      setState(2062);
      match(vhdlParser::QUESTIONMARK);
    }
    setState(2065);
    target();
    setState(2066);
    match(vhdlParser::CONASGN);
    setState(2068);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_INERTIAL)
      | (1ULL << vhdlParser::KW_REJECT)
      | (1ULL << vhdlParser::KW_TRANSPORT))) != 0)) {
      setState(2067);
      delay_mechanism();
    }
    setState(2070);
    selected_waveforms();
    setState(2071);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_waveformsContext ------------------------------------------------------------------

vhdlParser::Selected_waveformsContext::Selected_waveformsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::WaveformContext *> vhdlParser::Selected_waveformsContext::waveform() {
  return getRuleContexts<vhdlParser::WaveformContext>();
}

vhdlParser::WaveformContext* vhdlParser::Selected_waveformsContext::waveform(size_t i) {
  return getRuleContext<vhdlParser::WaveformContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Selected_waveformsContext::KW_WHEN() {
  return getTokens(vhdlParser::KW_WHEN);
}

tree::TerminalNode* vhdlParser::Selected_waveformsContext::KW_WHEN(size_t i) {
  return getToken(vhdlParser::KW_WHEN, i);
}

std::vector<vhdlParser::ChoicesContext *> vhdlParser::Selected_waveformsContext::choices() {
  return getRuleContexts<vhdlParser::ChoicesContext>();
}

vhdlParser::ChoicesContext* vhdlParser::Selected_waveformsContext::choices(size_t i) {
  return getRuleContext<vhdlParser::ChoicesContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Selected_waveformsContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Selected_waveformsContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Selected_waveformsContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_waveforms;
}

void vhdlParser::Selected_waveformsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelected_waveforms(this);
}

void vhdlParser::Selected_waveformsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelected_waveforms(this);
}


antlrcpp::Any vhdlParser::Selected_waveformsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSelected_waveforms(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_waveformsContext* vhdlParser::selected_waveforms() {
  Selected_waveformsContext *_localctx = _tracker.createInstance<Selected_waveformsContext>(_ctx, getState());
  enterRule(_localctx, 404, vhdlParser::RuleSelected_waveforms);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2073);
    waveform();
    setState(2074);
    match(vhdlParser::KW_WHEN);
    setState(2075);
    choices();
    setState(2083);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(2076);
      match(vhdlParser::COMMA);
      setState(2077);
      waveform();
      setState(2078);
      match(vhdlParser::KW_WHEN);
      setState(2079);
      choices();
      setState(2085);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_force_assignmentContext ------------------------------------------------------------------

vhdlParser::Selected_force_assignmentContext::Selected_force_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Selected_force_assignmentContext::KW_WITH() {
  return getToken(vhdlParser::KW_WITH, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Selected_force_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_force_assignmentContext::KW_SELECT() {
  return getToken(vhdlParser::KW_SELECT, 0);
}

vhdlParser::TargetContext* vhdlParser::Selected_force_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_force_assignmentContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

tree::TerminalNode* vhdlParser::Selected_force_assignmentContext::KW_FORCE() {
  return getToken(vhdlParser::KW_FORCE, 0);
}

vhdlParser::Selected_expressionsContext* vhdlParser::Selected_force_assignmentContext::selected_expressions() {
  return getRuleContext<vhdlParser::Selected_expressionsContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_force_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Selected_force_assignmentContext::QUESTIONMARK() {
  return getToken(vhdlParser::QUESTIONMARK, 0);
}

vhdlParser::Force_modeContext* vhdlParser::Selected_force_assignmentContext::force_mode() {
  return getRuleContext<vhdlParser::Force_modeContext>(0);
}


size_t vhdlParser::Selected_force_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_force_assignment;
}

void vhdlParser::Selected_force_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelected_force_assignment(this);
}

void vhdlParser::Selected_force_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelected_force_assignment(this);
}


antlrcpp::Any vhdlParser::Selected_force_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSelected_force_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_force_assignmentContext* vhdlParser::selected_force_assignment() {
  Selected_force_assignmentContext *_localctx = _tracker.createInstance<Selected_force_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 406, vhdlParser::RuleSelected_force_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2086);
    match(vhdlParser::KW_WITH);
    setState(2087);
    expression(0);
    setState(2088);
    match(vhdlParser::KW_SELECT);
    setState(2090);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::QUESTIONMARK) {
      setState(2089);
      match(vhdlParser::QUESTIONMARK);
    }
    setState(2092);
    target();
    setState(2093);
    match(vhdlParser::CONASGN);
    setState(2094);
    match(vhdlParser::KW_FORCE);
    setState(2096);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IN

    || _la == vhdlParser::KW_OUT) {
      setState(2095);
      force_mode();
    }
    setState(2098);
    selected_expressions();
    setState(2099);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_expressionsContext ------------------------------------------------------------------

vhdlParser::Selected_expressionsContext::Selected_expressionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Selected_expressionsContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Selected_expressionsContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Selected_expressionsContext::KW_WHEN() {
  return getTokens(vhdlParser::KW_WHEN);
}

tree::TerminalNode* vhdlParser::Selected_expressionsContext::KW_WHEN(size_t i) {
  return getToken(vhdlParser::KW_WHEN, i);
}

std::vector<vhdlParser::ChoicesContext *> vhdlParser::Selected_expressionsContext::choices() {
  return getRuleContexts<vhdlParser::ChoicesContext>();
}

vhdlParser::ChoicesContext* vhdlParser::Selected_expressionsContext::choices(size_t i) {
  return getRuleContext<vhdlParser::ChoicesContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Selected_expressionsContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Selected_expressionsContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Selected_expressionsContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_expressions;
}

void vhdlParser::Selected_expressionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelected_expressions(this);
}

void vhdlParser::Selected_expressionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelected_expressions(this);
}


antlrcpp::Any vhdlParser::Selected_expressionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSelected_expressions(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_expressionsContext* vhdlParser::selected_expressions() {
  Selected_expressionsContext *_localctx = _tracker.createInstance<Selected_expressionsContext>(_ctx, getState());
  enterRule(_localctx, 408, vhdlParser::RuleSelected_expressions);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2101);
    expression(0);
    setState(2102);
    match(vhdlParser::KW_WHEN);
    setState(2103);
    choices();
    setState(2111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(2104);
      match(vhdlParser::COMMA);
      setState(2105);
      expression(0);
      setState(2106);
      match(vhdlParser::KW_WHEN);
      setState(2107);
      choices();
      setState(2113);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_assignment_statementContext ------------------------------------------------------------------

vhdlParser::Variable_assignment_statementContext::Variable_assignment_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Simple_variable_assignmentContext* vhdlParser::Variable_assignment_statementContext::simple_variable_assignment() {
  return getRuleContext<vhdlParser::Simple_variable_assignmentContext>(0);
}

vhdlParser::Conditional_variable_assignmentContext* vhdlParser::Variable_assignment_statementContext::conditional_variable_assignment() {
  return getRuleContext<vhdlParser::Conditional_variable_assignmentContext>(0);
}

vhdlParser::Selected_variable_assignmentContext* vhdlParser::Variable_assignment_statementContext::selected_variable_assignment() {
  return getRuleContext<vhdlParser::Selected_variable_assignmentContext>(0);
}


size_t vhdlParser::Variable_assignment_statementContext::getRuleIndex() const {
  return vhdlParser::RuleVariable_assignment_statement;
}

void vhdlParser::Variable_assignment_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_assignment_statement(this);
}

void vhdlParser::Variable_assignment_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_assignment_statement(this);
}


antlrcpp::Any vhdlParser::Variable_assignment_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitVariable_assignment_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Variable_assignment_statementContext* vhdlParser::variable_assignment_statement() {
  Variable_assignment_statementContext *_localctx = _tracker.createInstance<Variable_assignment_statementContext>(_ctx, getState());
  enterRule(_localctx, 410, vhdlParser::RuleVariable_assignment_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 220, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2114);
      simple_variable_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2115);
      conditional_variable_assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2116);
      selected_variable_assignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_variable_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_variable_assignmentContext::Simple_variable_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Simple_variable_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_variable_assignmentContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Simple_variable_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_variable_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Simple_variable_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_variable_assignment;
}

void vhdlParser::Simple_variable_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_variable_assignment(this);
}

void vhdlParser::Simple_variable_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_variable_assignment(this);
}


antlrcpp::Any vhdlParser::Simple_variable_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSimple_variable_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_variable_assignmentContext* vhdlParser::simple_variable_assignment() {
  Simple_variable_assignmentContext *_localctx = _tracker.createInstance<Simple_variable_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 412, vhdlParser::RuleSimple_variable_assignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2119);
    target();
    setState(2120);
    match(vhdlParser::VARASGN);
    setState(2121);
    expression(0);
    setState(2122);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_variable_assignmentContext ------------------------------------------------------------------

vhdlParser::Conditional_variable_assignmentContext::Conditional_variable_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Conditional_variable_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_variable_assignmentContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::Conditional_expressionsContext* vhdlParser::Conditional_variable_assignmentContext::conditional_expressions() {
  return getRuleContext<vhdlParser::Conditional_expressionsContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_variable_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Conditional_variable_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_variable_assignment;
}

void vhdlParser::Conditional_variable_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional_variable_assignment(this);
}

void vhdlParser::Conditional_variable_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional_variable_assignment(this);
}


antlrcpp::Any vhdlParser::Conditional_variable_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConditional_variable_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_variable_assignmentContext* vhdlParser::conditional_variable_assignment() {
  Conditional_variable_assignmentContext *_localctx = _tracker.createInstance<Conditional_variable_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 414, vhdlParser::RuleConditional_variable_assignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2124);
    target();
    setState(2125);
    match(vhdlParser::VARASGN);
    setState(2126);
    conditional_expressions();
    setState(2127);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_variable_assignmentContext ------------------------------------------------------------------

vhdlParser::Selected_variable_assignmentContext::Selected_variable_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Selected_variable_assignmentContext::KW_WITH() {
  return getToken(vhdlParser::KW_WITH, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Selected_variable_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_variable_assignmentContext::KW_SELECT() {
  return getToken(vhdlParser::KW_SELECT, 0);
}

vhdlParser::TargetContext* vhdlParser::Selected_variable_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_variable_assignmentContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::Selected_expressionsContext* vhdlParser::Selected_variable_assignmentContext::selected_expressions() {
  return getRuleContext<vhdlParser::Selected_expressionsContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_variable_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Selected_variable_assignmentContext::QUESTIONMARK() {
  return getToken(vhdlParser::QUESTIONMARK, 0);
}


size_t vhdlParser::Selected_variable_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_variable_assignment;
}

void vhdlParser::Selected_variable_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelected_variable_assignment(this);
}

void vhdlParser::Selected_variable_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelected_variable_assignment(this);
}


antlrcpp::Any vhdlParser::Selected_variable_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSelected_variable_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_variable_assignmentContext* vhdlParser::selected_variable_assignment() {
  Selected_variable_assignmentContext *_localctx = _tracker.createInstance<Selected_variable_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 416, vhdlParser::RuleSelected_variable_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2129);
    match(vhdlParser::KW_WITH);
    setState(2130);
    expression(0);
    setState(2131);
    match(vhdlParser::KW_SELECT);
    setState(2133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::QUESTIONMARK) {
      setState(2132);
      match(vhdlParser::QUESTIONMARK);
    }
    setState(2135);
    target();
    setState(2136);
    match(vhdlParser::VARASGN);
    setState(2137);
    selected_expressions();
    setState(2138);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedure_call_statementContext ------------------------------------------------------------------

vhdlParser::Procedure_call_statementContext::Procedure_call_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Procedure_callContext* vhdlParser::Procedure_call_statementContext::procedure_call() {
  return getRuleContext<vhdlParser::Procedure_callContext>(0);
}

tree::TerminalNode* vhdlParser::Procedure_call_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Procedure_call_statementContext::getRuleIndex() const {
  return vhdlParser::RuleProcedure_call_statement;
}

void vhdlParser::Procedure_call_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedure_call_statement(this);
}

void vhdlParser::Procedure_call_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedure_call_statement(this);
}


antlrcpp::Any vhdlParser::Procedure_call_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProcedure_call_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedure_call_statementContext* vhdlParser::procedure_call_statement() {
  Procedure_call_statementContext *_localctx = _tracker.createInstance<Procedure_call_statementContext>(_ctx, getState());
  enterRule(_localctx, 418, vhdlParser::RuleProcedure_call_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2140);
    procedure_call();
    setState(2141);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedure_callContext ------------------------------------------------------------------

vhdlParser::Procedure_callContext::Procedure_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Procedure_callContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::Procedure_callContext::getRuleIndex() const {
  return vhdlParser::RuleProcedure_call;
}

void vhdlParser::Procedure_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedure_call(this);
}

void vhdlParser::Procedure_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedure_call(this);
}


antlrcpp::Any vhdlParser::Procedure_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProcedure_call(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedure_callContext* vhdlParser::procedure_call() {
  Procedure_callContext *_localctx = _tracker.createInstance<Procedure_callContext>(_ctx, getState());
  enterRule(_localctx, 420, vhdlParser::RuleProcedure_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2143);
    name(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

vhdlParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::If_statementContext::KW_IF() {
  return getTokens(vhdlParser::KW_IF);
}

tree::TerminalNode* vhdlParser::If_statementContext::KW_IF(size_t i) {
  return getToken(vhdlParser::KW_IF, i);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::If_statementContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::If_statementContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::If_statementContext::KW_THEN() {
  return getTokens(vhdlParser::KW_THEN);
}

tree::TerminalNode* vhdlParser::If_statementContext::KW_THEN(size_t i) {
  return getToken(vhdlParser::KW_THEN, i);
}

std::vector<vhdlParser::Sequence_of_statementsContext *> vhdlParser::If_statementContext::sequence_of_statements() {
  return getRuleContexts<vhdlParser::Sequence_of_statementsContext>();
}

vhdlParser::Sequence_of_statementsContext* vhdlParser::If_statementContext::sequence_of_statements(size_t i) {
  return getRuleContext<vhdlParser::Sequence_of_statementsContext>(i);
}

tree::TerminalNode* vhdlParser::If_statementContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::If_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::If_statementContext::KW_ELSE() {
  return getToken(vhdlParser::KW_ELSE, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::If_statementContext::KW_ELSIF() {
  return getTokens(vhdlParser::KW_ELSIF);
}

tree::TerminalNode* vhdlParser::If_statementContext::KW_ELSIF(size_t i) {
  return getToken(vhdlParser::KW_ELSIF, i);
}

vhdlParser::LabelContext* vhdlParser::If_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::If_statementContext::getRuleIndex() const {
  return vhdlParser::RuleIf_statement;
}

void vhdlParser::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}

void vhdlParser::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}


antlrcpp::Any vhdlParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::If_statementContext* vhdlParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 422, vhdlParser::RuleIf_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2145);
    match(vhdlParser::KW_IF);
    setState(2146);
    condition();
    setState(2147);
    match(vhdlParser::KW_THEN);
    setState(2148);
    sequence_of_statements();
    setState(2156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 222, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2149);
        match(vhdlParser::KW_ELSIF);
        setState(2150);
        condition();
        setState(2151);
        match(vhdlParser::KW_THEN);
        setState(2152);
        sequence_of_statements(); 
      }
      setState(2158);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 222, _ctx);
    }
    setState(2163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 223, _ctx)) {
    case 1: {
      setState(2159);
      match(vhdlParser::KW_ELSE);
      setState(2160);
      sequence_of_statements();
      break;
    }

    case 2: {
      break;
    }

    case 3: {
      setState(2162);

      if (!(_input->LA(1) != KW_ELSE)) throw FailedPredicateException(this, "_input->LA(1) != KW_ELSE");
      break;
    }

    default:
      break;
    }
    setState(2165);
    match(vhdlParser::KW_END);
    setState(2166);
    match(vhdlParser::KW_IF);
    setState(2168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2167);
      label();
    }
    setState(2170);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_statementContext ------------------------------------------------------------------

vhdlParser::Case_statementContext::Case_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Case_statementContext::KW_CASE() {
  return getTokens(vhdlParser::KW_CASE);
}

tree::TerminalNode* vhdlParser::Case_statementContext::KW_CASE(size_t i) {
  return getToken(vhdlParser::KW_CASE, i);
}

vhdlParser::ExpressionContext* vhdlParser::Case_statementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Case_statementContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

tree::TerminalNode* vhdlParser::Case_statementContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Case_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Case_statementContext::QUESTIONMARK() {
  return getTokens(vhdlParser::QUESTIONMARK);
}

tree::TerminalNode* vhdlParser::Case_statementContext::QUESTIONMARK(size_t i) {
  return getToken(vhdlParser::QUESTIONMARK, i);
}

std::vector<vhdlParser::Case_statement_alternativeContext *> vhdlParser::Case_statementContext::case_statement_alternative() {
  return getRuleContexts<vhdlParser::Case_statement_alternativeContext>();
}

vhdlParser::Case_statement_alternativeContext* vhdlParser::Case_statementContext::case_statement_alternative(size_t i) {
  return getRuleContext<vhdlParser::Case_statement_alternativeContext>(i);
}

vhdlParser::LabelContext* vhdlParser::Case_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::Case_statementContext::getRuleIndex() const {
  return vhdlParser::RuleCase_statement;
}

void vhdlParser::Case_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_statement(this);
}

void vhdlParser::Case_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_statement(this);
}


antlrcpp::Any vhdlParser::Case_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitCase_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Case_statementContext* vhdlParser::case_statement() {
  Case_statementContext *_localctx = _tracker.createInstance<Case_statementContext>(_ctx, getState());
  enterRule(_localctx, 424, vhdlParser::RuleCase_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2172);
    match(vhdlParser::KW_CASE);
    setState(2174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::QUESTIONMARK) {
      setState(2173);
      match(vhdlParser::QUESTIONMARK);
    }
    setState(2176);
    expression(0);
    setState(2177);
    match(vhdlParser::KW_IS);
    setState(2179); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2178);
      case_statement_alternative();
      setState(2181); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::KW_WHEN);
    setState(2183);
    match(vhdlParser::KW_END);
    setState(2184);
    match(vhdlParser::KW_CASE);
    setState(2186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::QUESTIONMARK) {
      setState(2185);
      match(vhdlParser::QUESTIONMARK);
    }
    setState(2189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2188);
      label();
    }
    setState(2191);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_statement_alternativeContext ------------------------------------------------------------------

vhdlParser::Case_statement_alternativeContext::Case_statement_alternativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Case_statement_alternativeContext::KW_WHEN() {
  return getToken(vhdlParser::KW_WHEN, 0);
}

vhdlParser::ChoicesContext* vhdlParser::Case_statement_alternativeContext::choices() {
  return getRuleContext<vhdlParser::ChoicesContext>(0);
}

tree::TerminalNode* vhdlParser::Case_statement_alternativeContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}

vhdlParser::Sequence_of_statementsContext* vhdlParser::Case_statement_alternativeContext::sequence_of_statements() {
  return getRuleContext<vhdlParser::Sequence_of_statementsContext>(0);
}


size_t vhdlParser::Case_statement_alternativeContext::getRuleIndex() const {
  return vhdlParser::RuleCase_statement_alternative;
}

void vhdlParser::Case_statement_alternativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_statement_alternative(this);
}

void vhdlParser::Case_statement_alternativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_statement_alternative(this);
}


antlrcpp::Any vhdlParser::Case_statement_alternativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitCase_statement_alternative(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Case_statement_alternativeContext* vhdlParser::case_statement_alternative() {
  Case_statement_alternativeContext *_localctx = _tracker.createInstance<Case_statement_alternativeContext>(_ctx, getState());
  enterRule(_localctx, 426, vhdlParser::RuleCase_statement_alternative);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2193);
    match(vhdlParser::KW_WHEN);
    setState(2194);
    choices();
    setState(2195);
    match(vhdlParser::ARROW);
    setState(2196);
    sequence_of_statements();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Loop_statementContext ------------------------------------------------------------------

vhdlParser::Loop_statementContext::Loop_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Loop_statementContext::KW_LOOP() {
  return getTokens(vhdlParser::KW_LOOP);
}

tree::TerminalNode* vhdlParser::Loop_statementContext::KW_LOOP(size_t i) {
  return getToken(vhdlParser::KW_LOOP, i);
}

vhdlParser::Sequence_of_statementsContext* vhdlParser::Loop_statementContext::sequence_of_statements() {
  return getRuleContext<vhdlParser::Sequence_of_statementsContext>(0);
}

tree::TerminalNode* vhdlParser::Loop_statementContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Loop_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Iteration_schemeContext* vhdlParser::Loop_statementContext::iteration_scheme() {
  return getRuleContext<vhdlParser::Iteration_schemeContext>(0);
}

vhdlParser::LabelContext* vhdlParser::Loop_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::Loop_statementContext::getRuleIndex() const {
  return vhdlParser::RuleLoop_statement;
}

void vhdlParser::Loop_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoop_statement(this);
}

void vhdlParser::Loop_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoop_statement(this);
}


antlrcpp::Any vhdlParser::Loop_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitLoop_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Loop_statementContext* vhdlParser::loop_statement() {
  Loop_statementContext *_localctx = _tracker.createInstance<Loop_statementContext>(_ctx, getState());
  enterRule(_localctx, 428, vhdlParser::RuleLoop_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2199);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_WHILE

    || _la == vhdlParser::KW_FOR) {
      setState(2198);
      iteration_scheme();
    }
    setState(2201);
    match(vhdlParser::KW_LOOP);
    setState(2202);
    sequence_of_statements();
    setState(2203);
    match(vhdlParser::KW_END);
    setState(2204);
    match(vhdlParser::KW_LOOP);
    setState(2206);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2205);
      label();
    }
    setState(2208);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Iteration_schemeContext ------------------------------------------------------------------

vhdlParser::Iteration_schemeContext::Iteration_schemeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Iteration_schemeContext::KW_WHILE() {
  return getToken(vhdlParser::KW_WHILE, 0);
}

vhdlParser::ConditionContext* vhdlParser::Iteration_schemeContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}

tree::TerminalNode* vhdlParser::Iteration_schemeContext::KW_FOR() {
  return getToken(vhdlParser::KW_FOR, 0);
}

vhdlParser::Parameter_specificationContext* vhdlParser::Iteration_schemeContext::parameter_specification() {
  return getRuleContext<vhdlParser::Parameter_specificationContext>(0);
}


size_t vhdlParser::Iteration_schemeContext::getRuleIndex() const {
  return vhdlParser::RuleIteration_scheme;
}

void vhdlParser::Iteration_schemeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIteration_scheme(this);
}

void vhdlParser::Iteration_schemeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIteration_scheme(this);
}


antlrcpp::Any vhdlParser::Iteration_schemeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitIteration_scheme(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Iteration_schemeContext* vhdlParser::iteration_scheme() {
  Iteration_schemeContext *_localctx = _tracker.createInstance<Iteration_schemeContext>(_ctx, getState());
  enterRule(_localctx, 430, vhdlParser::RuleIteration_scheme);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2214);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(2210);
        match(vhdlParser::KW_WHILE);
        setState(2211);
        condition();
        break;
      }

      case vhdlParser::KW_FOR: {
        enterOuterAlt(_localctx, 2);
        setState(2212);
        match(vhdlParser::KW_FOR);
        setState(2213);
        parameter_specification();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_specificationContext ------------------------------------------------------------------

vhdlParser::Parameter_specificationContext::Parameter_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Parameter_specificationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Parameter_specificationContext::KW_IN() {
  return getToken(vhdlParser::KW_IN, 0);
}

vhdlParser::Discrete_rangeContext* vhdlParser::Parameter_specificationContext::discrete_range() {
  return getRuleContext<vhdlParser::Discrete_rangeContext>(0);
}


size_t vhdlParser::Parameter_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleParameter_specification;
}

void vhdlParser::Parameter_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_specification(this);
}

void vhdlParser::Parameter_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_specification(this);
}


antlrcpp::Any vhdlParser::Parameter_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitParameter_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Parameter_specificationContext* vhdlParser::parameter_specification() {
  Parameter_specificationContext *_localctx = _tracker.createInstance<Parameter_specificationContext>(_ctx, getState());
  enterRule(_localctx, 432, vhdlParser::RuleParameter_specification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2216);
    identifier();
    setState(2217);
    match(vhdlParser::KW_IN);
    setState(2218);
    discrete_range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Next_statementContext ------------------------------------------------------------------

vhdlParser::Next_statementContext::Next_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Next_statementContext::KW_NEXT() {
  return getToken(vhdlParser::KW_NEXT, 0);
}

tree::TerminalNode* vhdlParser::Next_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::LabelContext* vhdlParser::Next_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}

tree::TerminalNode* vhdlParser::Next_statementContext::KW_WHEN() {
  return getToken(vhdlParser::KW_WHEN, 0);
}

vhdlParser::ConditionContext* vhdlParser::Next_statementContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}


size_t vhdlParser::Next_statementContext::getRuleIndex() const {
  return vhdlParser::RuleNext_statement;
}

void vhdlParser::Next_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNext_statement(this);
}

void vhdlParser::Next_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNext_statement(this);
}


antlrcpp::Any vhdlParser::Next_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitNext_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Next_statementContext* vhdlParser::next_statement() {
  Next_statementContext *_localctx = _tracker.createInstance<Next_statementContext>(_ctx, getState());
  enterRule(_localctx, 434, vhdlParser::RuleNext_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2220);
    match(vhdlParser::KW_NEXT);
    setState(2222);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2221);
      label();
    }
    setState(2226);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_WHEN) {
      setState(2224);
      match(vhdlParser::KW_WHEN);
      setState(2225);
      condition();
    }
    setState(2228);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Exit_statementContext ------------------------------------------------------------------

vhdlParser::Exit_statementContext::Exit_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Exit_statementContext::KW_EXIT() {
  return getToken(vhdlParser::KW_EXIT, 0);
}

tree::TerminalNode* vhdlParser::Exit_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::LabelContext* vhdlParser::Exit_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}

tree::TerminalNode* vhdlParser::Exit_statementContext::KW_WHEN() {
  return getToken(vhdlParser::KW_WHEN, 0);
}

vhdlParser::ConditionContext* vhdlParser::Exit_statementContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}


size_t vhdlParser::Exit_statementContext::getRuleIndex() const {
  return vhdlParser::RuleExit_statement;
}

void vhdlParser::Exit_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExit_statement(this);
}

void vhdlParser::Exit_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExit_statement(this);
}


antlrcpp::Any vhdlParser::Exit_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitExit_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Exit_statementContext* vhdlParser::exit_statement() {
  Exit_statementContext *_localctx = _tracker.createInstance<Exit_statementContext>(_ctx, getState());
  enterRule(_localctx, 436, vhdlParser::RuleExit_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2230);
    match(vhdlParser::KW_EXIT);
    setState(2232);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2231);
      label();
    }
    setState(2236);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_WHEN) {
      setState(2234);
      match(vhdlParser::KW_WHEN);
      setState(2235);
      condition();
    }
    setState(2238);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

vhdlParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Return_statementContext::KW_RETURN() {
  return getToken(vhdlParser::KW_RETURN, 0);
}

tree::TerminalNode* vhdlParser::Return_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Return_statementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Return_statementContext::getRuleIndex() const {
  return vhdlParser::RuleReturn_statement;
}

void vhdlParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}

void vhdlParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}


antlrcpp::Any vhdlParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Return_statementContext* vhdlParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 438, vhdlParser::RuleReturn_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2240);
    match(vhdlParser::KW_RETURN);
    setState(2242);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_ABS)
      | (1ULL << vhdlParser::KW_XNOR)
      | (1ULL << vhdlParser::KW_XOR)
      | (1ULL << vhdlParser::KW_NEW)
      | (1ULL << vhdlParser::KW_OR))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (vhdlParser::KW_NOR - 67))
      | (1ULL << (vhdlParser::KW_AND - 67))
      | (1ULL << (vhdlParser::KW_NAND - 67))
      | (1ULL << (vhdlParser::KW_NOT - 67))
      | (1ULL << (vhdlParser::KW_NULL - 67))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 67))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 67))
      | (1ULL << (vhdlParser::DECIMAL_LITERAL - 67))
      | (1ULL << (vhdlParser::BASED_LITERAL - 67))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 67))
      | (1ULL << (vhdlParser::STRING_LITERAL - 67))
      | (1ULL << (vhdlParser::BIT_STRING_LITERAL - 67))
      | (1ULL << (vhdlParser::LPAREN - 67)))) != 0) || ((((_la - 131) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 131)) & ((1ULL << (vhdlParser::SHIFT_LEFT - 131))
      | (1ULL << (vhdlParser::PLUS - 131))
      | (1ULL << (vhdlParser::MINUS - 131))
      | (1ULL << (vhdlParser::COND_OP - 131)))) != 0)) {
      setState(2241);
      expression(0);
    }
    setState(2244);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Null_statementContext ------------------------------------------------------------------

vhdlParser::Null_statementContext::Null_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Null_statementContext::KW_NULL() {
  return getToken(vhdlParser::KW_NULL, 0);
}

tree::TerminalNode* vhdlParser::Null_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Null_statementContext::getRuleIndex() const {
  return vhdlParser::RuleNull_statement;
}

void vhdlParser::Null_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNull_statement(this);
}

void vhdlParser::Null_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNull_statement(this);
}


antlrcpp::Any vhdlParser::Null_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitNull_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Null_statementContext* vhdlParser::null_statement() {
  Null_statementContext *_localctx = _tracker.createInstance<Null_statementContext>(_ctx, getState());
  enterRule(_localctx, 440, vhdlParser::RuleNull_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2246);
    match(vhdlParser::KW_NULL);
    setState(2247);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_statement_with_optional_labelContext ------------------------------------------------------------------

vhdlParser::Concurrent_statement_with_optional_labelContext::Concurrent_statement_with_optional_labelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Process_statementContext* vhdlParser::Concurrent_statement_with_optional_labelContext::process_statement() {
  return getRuleContext<vhdlParser::Process_statementContext>(0);
}

vhdlParser::Concurrent_procedure_call_statementContext* vhdlParser::Concurrent_statement_with_optional_labelContext::concurrent_procedure_call_statement() {
  return getRuleContext<vhdlParser::Concurrent_procedure_call_statementContext>(0);
}

vhdlParser::Concurrent_assertion_statementContext* vhdlParser::Concurrent_statement_with_optional_labelContext::concurrent_assertion_statement() {
  return getRuleContext<vhdlParser::Concurrent_assertion_statementContext>(0);
}

vhdlParser::Concurrent_signal_assignment_statementContext* vhdlParser::Concurrent_statement_with_optional_labelContext::concurrent_signal_assignment_statement() {
  return getRuleContext<vhdlParser::Concurrent_signal_assignment_statementContext>(0);
}


size_t vhdlParser::Concurrent_statement_with_optional_labelContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_statement_with_optional_label;
}

void vhdlParser::Concurrent_statement_with_optional_labelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrent_statement_with_optional_label(this);
}

void vhdlParser::Concurrent_statement_with_optional_labelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrent_statement_with_optional_label(this);
}


antlrcpp::Any vhdlParser::Concurrent_statement_with_optional_labelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConcurrent_statement_with_optional_label(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_statement_with_optional_labelContext* vhdlParser::concurrent_statement_with_optional_label() {
  Concurrent_statement_with_optional_labelContext *_localctx = _tracker.createInstance<Concurrent_statement_with_optional_labelContext>(_ctx, getState());
  enterRule(_localctx, 442, vhdlParser::RuleConcurrent_statement_with_optional_label);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 237, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2249);
      process_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2250);
      concurrent_procedure_call_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2251);
      concurrent_assertion_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2252);
      concurrent_signal_assignment_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_statementContext ------------------------------------------------------------------

vhdlParser::Concurrent_statementContext::Concurrent_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::LabelContext* vhdlParser::Concurrent_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_statementContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Block_statementContext* vhdlParser::Concurrent_statementContext::block_statement() {
  return getRuleContext<vhdlParser::Block_statementContext>(0);
}

vhdlParser::Component_instantiation_statementContext* vhdlParser::Concurrent_statementContext::component_instantiation_statement() {
  return getRuleContext<vhdlParser::Component_instantiation_statementContext>(0);
}

vhdlParser::Generate_statementContext* vhdlParser::Concurrent_statementContext::generate_statement() {
  return getRuleContext<vhdlParser::Generate_statementContext>(0);
}

vhdlParser::Concurrent_statement_with_optional_labelContext* vhdlParser::Concurrent_statementContext::concurrent_statement_with_optional_label() {
  return getRuleContext<vhdlParser::Concurrent_statement_with_optional_labelContext>(0);
}


size_t vhdlParser::Concurrent_statementContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_statement;
}

void vhdlParser::Concurrent_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrent_statement(this);
}

void vhdlParser::Concurrent_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrent_statement(this);
}


antlrcpp::Any vhdlParser::Concurrent_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConcurrent_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_statementContext* vhdlParser::concurrent_statement() {
  Concurrent_statementContext *_localctx = _tracker.createInstance<Concurrent_statementContext>(_ctx, getState());
  enterRule(_localctx, 444, vhdlParser::RuleConcurrent_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2264);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 239, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2255);
      label();
      setState(2256);
      match(vhdlParser::COLON);
      setState(2261);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 238, _ctx)) {
      case 1: {
        setState(2257);
        block_statement();
        break;
      }

      case 2: {
        setState(2258);
        component_instantiation_statement();
        break;
      }

      case 3: {
        setState(2259);
        generate_statement();
        break;
      }

      case 4: {
        setState(2260);
        concurrent_statement_with_optional_label();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2263);
      concurrent_statement_with_optional_label();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_statementContext ------------------------------------------------------------------

vhdlParser::Block_statementContext::Block_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Block_statementContext::KW_BLOCK() {
  return getTokens(vhdlParser::KW_BLOCK);
}

tree::TerminalNode* vhdlParser::Block_statementContext::KW_BLOCK(size_t i) {
  return getToken(vhdlParser::KW_BLOCK, i);
}

vhdlParser::Block_headerContext* vhdlParser::Block_statementContext::block_header() {
  return getRuleContext<vhdlParser::Block_headerContext>(0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::KW_BEGIN() {
  return getToken(vhdlParser::KW_BEGIN, 0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::ConditionContext* vhdlParser::Block_statementContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

std::vector<vhdlParser::Block_declarative_itemContext *> vhdlParser::Block_statementContext::block_declarative_item() {
  return getRuleContexts<vhdlParser::Block_declarative_itemContext>();
}

vhdlParser::Block_declarative_itemContext* vhdlParser::Block_statementContext::block_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Block_declarative_itemContext>(i);
}

std::vector<vhdlParser::Concurrent_statementContext *> vhdlParser::Block_statementContext::concurrent_statement() {
  return getRuleContexts<vhdlParser::Concurrent_statementContext>();
}

vhdlParser::Concurrent_statementContext* vhdlParser::Block_statementContext::concurrent_statement(size_t i) {
  return getRuleContext<vhdlParser::Concurrent_statementContext>(i);
}

vhdlParser::LabelContext* vhdlParser::Block_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::Block_statementContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_statement;
}

void vhdlParser::Block_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_statement(this);
}

void vhdlParser::Block_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_statement(this);
}


antlrcpp::Any vhdlParser::Block_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitBlock_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_statementContext* vhdlParser::block_statement() {
  Block_statementContext *_localctx = _tracker.createInstance<Block_statementContext>(_ctx, getState());
  enterRule(_localctx, 446, vhdlParser::RuleBlock_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2266);
    match(vhdlParser::KW_BLOCK);
    setState(2271);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(2267);
      match(vhdlParser::LPAREN);
      setState(2268);
      condition();
      setState(2269);
      match(vhdlParser::RPAREN);
    }
    setState(2274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IS) {
      setState(2273);
      match(vhdlParser::KW_IS);
    }
    setState(2276);
    block_header();
    setState(2280);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_COMPONENT)
      | (1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_SIGNAL)
      | (1ULL << vhdlParser::KW_DISCONNECT)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
      | (1ULL << (vhdlParser::KW_IMPURE - 65))
      | (1ULL << (vhdlParser::KW_PACKAGE - 65))
      | (1ULL << (vhdlParser::KW_FOR - 65))
      | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
      setState(2277);
      block_declarative_item();
      setState(2282);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2283);
    match(vhdlParser::KW_BEGIN);
    setState(2287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::KW_PROCESS

    || _la == vhdlParser::KW_POSTPONED || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (vhdlParser::KW_WITH - 72))
      | (1ULL << (vhdlParser::KW_ASSERT - 72))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 72))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 72))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 72))
      | (1ULL << (vhdlParser::STRING_LITERAL - 72))
      | (1ULL << (vhdlParser::LPAREN - 72))
      | (1ULL << (vhdlParser::SHIFT_LEFT - 72)))) != 0)) {
      setState(2284);
      concurrent_statement();
      setState(2289);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2290);
    match(vhdlParser::KW_END);
    setState(2291);
    match(vhdlParser::KW_BLOCK);
    setState(2293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2292);
      label();
    }
    setState(2295);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_headerContext ------------------------------------------------------------------

vhdlParser::Block_headerContext::Block_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Generic_clauseContext* vhdlParser::Block_headerContext::generic_clause() {
  return getRuleContext<vhdlParser::Generic_clauseContext>(0);
}

vhdlParser::Port_clauseContext* vhdlParser::Block_headerContext::port_clause() {
  return getRuleContext<vhdlParser::Port_clauseContext>(0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Block_headerContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Block_headerContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Block_headerContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}

vhdlParser::Port_map_aspectContext* vhdlParser::Block_headerContext::port_map_aspect() {
  return getRuleContext<vhdlParser::Port_map_aspectContext>(0);
}


size_t vhdlParser::Block_headerContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_header;
}

void vhdlParser::Block_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_header(this);
}

void vhdlParser::Block_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_header(this);
}


antlrcpp::Any vhdlParser::Block_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitBlock_header(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_headerContext* vhdlParser::block_header() {
  Block_headerContext *_localctx = _tracker.createInstance<Block_headerContext>(_ctx, getState());
  enterRule(_localctx, 448, vhdlParser::RuleBlock_header);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2303);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(2297);
      generic_clause();
      setState(2301);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_GENERIC) {
        setState(2298);
        generic_map_aspect();
        setState(2299);
        match(vhdlParser::SEMI);
      }
    }
    setState(2311);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PORT) {
      setState(2305);
      port_clause();
      setState(2309);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::KW_PORT) {
        setState(2306);
        port_map_aspect();
        setState(2307);
        match(vhdlParser::SEMI);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_statementContext ------------------------------------------------------------------

vhdlParser::Process_statementContext::Process_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Process_statementContext::KW_PROCESS() {
  return getTokens(vhdlParser::KW_PROCESS);
}

tree::TerminalNode* vhdlParser::Process_statementContext::KW_PROCESS(size_t i) {
  return getToken(vhdlParser::KW_PROCESS, i);
}

tree::TerminalNode* vhdlParser::Process_statementContext::KW_BEGIN() {
  return getToken(vhdlParser::KW_BEGIN, 0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Process_statementContext::KW_POSTPONED() {
  return getTokens(vhdlParser::KW_POSTPONED);
}

tree::TerminalNode* vhdlParser::Process_statementContext::KW_POSTPONED(size_t i) {
  return getToken(vhdlParser::KW_POSTPONED, i);
}

tree::TerminalNode* vhdlParser::Process_statementContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Process_sensitivity_listContext* vhdlParser::Process_statementContext::process_sensitivity_list() {
  return getRuleContext<vhdlParser::Process_sensitivity_listContext>(0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

std::vector<vhdlParser::Process_declarative_itemContext *> vhdlParser::Process_statementContext::process_declarative_item() {
  return getRuleContexts<vhdlParser::Process_declarative_itemContext>();
}

vhdlParser::Process_declarative_itemContext* vhdlParser::Process_statementContext::process_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Process_declarative_itemContext>(i);
}

std::vector<vhdlParser::Sequential_statementContext *> vhdlParser::Process_statementContext::sequential_statement() {
  return getRuleContexts<vhdlParser::Sequential_statementContext>();
}

vhdlParser::Sequential_statementContext* vhdlParser::Process_statementContext::sequential_statement(size_t i) {
  return getRuleContext<vhdlParser::Sequential_statementContext>(i);
}

vhdlParser::LabelContext* vhdlParser::Process_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::Process_statementContext::getRuleIndex() const {
  return vhdlParser::RuleProcess_statement;
}

void vhdlParser::Process_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcess_statement(this);
}

void vhdlParser::Process_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcess_statement(this);
}


antlrcpp::Any vhdlParser::Process_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProcess_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Process_statementContext* vhdlParser::process_statement() {
  Process_statementContext *_localctx = _tracker.createInstance<Process_statementContext>(_ctx, getState());
  enterRule(_localctx, 450, vhdlParser::RuleProcess_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2314);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_POSTPONED) {
      setState(2313);
      match(vhdlParser::KW_POSTPONED);
    }
    setState(2316);
    match(vhdlParser::KW_PROCESS);
    setState(2321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(2317);
      match(vhdlParser::LPAREN);
      setState(2318);
      process_sensitivity_list();
      setState(2319);
      match(vhdlParser::RPAREN);
    }
    setState(2324);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_IS) {
      setState(2323);
      match(vhdlParser::KW_IS);
    }
    setState(2329);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_GROUP)
      | (1ULL << vhdlParser::KW_FILE)
      | (1ULL << vhdlParser::KW_PURE)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_SHARED)
      | (1ULL << vhdlParser::KW_PROCEDURE)
      | (1ULL << vhdlParser::KW_ATTRIBUTE)
      | (1ULL << vhdlParser::KW_VARIABLE)
      | (1ULL << vhdlParser::KW_SUBTYPE)
      | (1ULL << vhdlParser::KW_CONSTANT)
      | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
      | (1ULL << (vhdlParser::KW_IMPURE - 65))
      | (1ULL << (vhdlParser::KW_PACKAGE - 65))
      | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
      setState(2326);
      process_declarative_item();
      setState(2331);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2332);
    match(vhdlParser::KW_BEGIN);
    setState(2336);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_NEXT)
      | (1ULL << vhdlParser::KW_LOOP)
      | (1ULL << vhdlParser::KW_REPORT))) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & ((1ULL << (vhdlParser::KW_EXIT - 70))
      | (1ULL << (vhdlParser::KW_RETURN - 70))
      | (1ULL << (vhdlParser::KW_WITH - 70))
      | (1ULL << (vhdlParser::KW_WAIT - 70))
      | (1ULL << (vhdlParser::KW_WHILE - 70))
      | (1ULL << (vhdlParser::KW_ASSERT - 70))
      | (1ULL << (vhdlParser::KW_FOR - 70))
      | (1ULL << (vhdlParser::KW_IF - 70))
      | (1ULL << (vhdlParser::KW_CASE - 70))
      | (1ULL << (vhdlParser::KW_NULL - 70))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 70))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 70))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 70))
      | (1ULL << (vhdlParser::STRING_LITERAL - 70))
      | (1ULL << (vhdlParser::LPAREN - 70))
      | (1ULL << (vhdlParser::SHIFT_LEFT - 70)))) != 0)) {
      setState(2333);
      sequential_statement();
      setState(2338);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2339);
    match(vhdlParser::KW_END);
    setState(2341);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_POSTPONED) {
      setState(2340);
      match(vhdlParser::KW_POSTPONED);
    }
    setState(2343);
    match(vhdlParser::KW_PROCESS);
    setState(2345);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2344);
      label();
    }
    setState(2347);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_sensitivity_listContext ------------------------------------------------------------------

vhdlParser::Process_sensitivity_listContext::Process_sensitivity_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Process_sensitivity_listContext::KW_ALL() {
  return getToken(vhdlParser::KW_ALL, 0);
}

vhdlParser::Sensitivity_listContext* vhdlParser::Process_sensitivity_listContext::sensitivity_list() {
  return getRuleContext<vhdlParser::Sensitivity_listContext>(0);
}


size_t vhdlParser::Process_sensitivity_listContext::getRuleIndex() const {
  return vhdlParser::RuleProcess_sensitivity_list;
}

void vhdlParser::Process_sensitivity_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcess_sensitivity_list(this);
}

void vhdlParser::Process_sensitivity_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcess_sensitivity_list(this);
}


antlrcpp::Any vhdlParser::Process_sensitivity_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProcess_sensitivity_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Process_sensitivity_listContext* vhdlParser::process_sensitivity_list() {
  Process_sensitivity_listContext *_localctx = _tracker.createInstance<Process_sensitivity_listContext>(_ctx, getState());
  enterRule(_localctx, 452, vhdlParser::RuleProcess_sensitivity_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2351);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_ALL: {
        enterOuterAlt(_localctx, 1);
        setState(2349);
        match(vhdlParser::KW_ALL);
        break;
      }

      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::SHIFT_LEFT: {
        enterOuterAlt(_localctx, 2);
        setState(2350);
        sensitivity_list();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_or_package_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Process_or_package_declarative_itemContext::Process_or_package_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Subprogram_instantiation_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::subprogram_instantiation_declaration() {
  return getRuleContext<vhdlParser::Subprogram_instantiation_declarationContext>(0);
}

vhdlParser::Package_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::package_declaration() {
  return getRuleContext<vhdlParser::Package_declarationContext>(0);
}

vhdlParser::Package_instantiation_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::package_instantiation_declaration() {
  return getRuleContext<vhdlParser::Package_instantiation_declarationContext>(0);
}

vhdlParser::Type_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::type_declaration() {
  return getRuleContext<vhdlParser::Type_declarationContext>(0);
}

vhdlParser::Subtype_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::subtype_declaration() {
  return getRuleContext<vhdlParser::Subtype_declarationContext>(0);
}

vhdlParser::Constant_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}

vhdlParser::Alias_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::alias_declaration() {
  return getRuleContext<vhdlParser::Alias_declarationContext>(0);
}

vhdlParser::Attribute_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::attribute_declaration() {
  return getRuleContext<vhdlParser::Attribute_declarationContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Process_or_package_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Process_or_package_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Group_template_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::group_template_declaration() {
  return getRuleContext<vhdlParser::Group_template_declarationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Process_or_package_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}


size_t vhdlParser::Process_or_package_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleProcess_or_package_declarative_item;
}

void vhdlParser::Process_or_package_declarative_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcess_or_package_declarative_item(this);
}

void vhdlParser::Process_or_package_declarative_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcess_or_package_declarative_item(this);
}


antlrcpp::Any vhdlParser::Process_or_package_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProcess_or_package_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Process_or_package_declarative_itemContext* vhdlParser::process_or_package_declarative_item() {
  Process_or_package_declarative_itemContext *_localctx = _tracker.createInstance<Process_or_package_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 454, vhdlParser::RuleProcess_or_package_declarative_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2368);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 257, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2353);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2354);
      subprogram_instantiation_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2355);
      package_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2356);
      package_instantiation_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2357);
      type_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(2358);
      subtype_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(2359);
      constant_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(2360);
      variable_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(2361);
      file_declaration();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(2362);
      alias_declaration();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(2363);
      attribute_declaration();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(2364);
      attribute_specification();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(2365);
      use_clause();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(2366);
      group_template_declaration();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(2367);
      group_declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Process_declarative_itemContext::Process_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Process_or_package_declarative_itemContext* vhdlParser::Process_declarative_itemContext::process_or_package_declarative_item() {
  return getRuleContext<vhdlParser::Process_or_package_declarative_itemContext>(0);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::Process_declarative_itemContext::subprogram_body() {
  return getRuleContext<vhdlParser::Subprogram_bodyContext>(0);
}

vhdlParser::Package_bodyContext* vhdlParser::Process_declarative_itemContext::package_body() {
  return getRuleContext<vhdlParser::Package_bodyContext>(0);
}


size_t vhdlParser::Process_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleProcess_declarative_item;
}

void vhdlParser::Process_declarative_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcess_declarative_item(this);
}

void vhdlParser::Process_declarative_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcess_declarative_item(this);
}


antlrcpp::Any vhdlParser::Process_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitProcess_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Process_declarative_itemContext* vhdlParser::process_declarative_item() {
  Process_declarative_itemContext *_localctx = _tracker.createInstance<Process_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 456, vhdlParser::RuleProcess_declarative_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2373);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 258, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2370);
      process_or_package_declarative_item();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2371);
      subprogram_body();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2372);
      package_body();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_procedure_call_statementContext ------------------------------------------------------------------

vhdlParser::Concurrent_procedure_call_statementContext::Concurrent_procedure_call_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Procedure_call_statementContext* vhdlParser::Concurrent_procedure_call_statementContext::procedure_call_statement() {
  return getRuleContext<vhdlParser::Procedure_call_statementContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_procedure_call_statementContext::KW_POSTPONED() {
  return getToken(vhdlParser::KW_POSTPONED, 0);
}


size_t vhdlParser::Concurrent_procedure_call_statementContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_procedure_call_statement;
}

void vhdlParser::Concurrent_procedure_call_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrent_procedure_call_statement(this);
}

void vhdlParser::Concurrent_procedure_call_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrent_procedure_call_statement(this);
}


antlrcpp::Any vhdlParser::Concurrent_procedure_call_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConcurrent_procedure_call_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_procedure_call_statementContext* vhdlParser::concurrent_procedure_call_statement() {
  Concurrent_procedure_call_statementContext *_localctx = _tracker.createInstance<Concurrent_procedure_call_statementContext>(_ctx, getState());
  enterRule(_localctx, 458, vhdlParser::RuleConcurrent_procedure_call_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2376);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_POSTPONED) {
      setState(2375);
      match(vhdlParser::KW_POSTPONED);
    }
    setState(2378);
    procedure_call_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_assertion_statementContext ------------------------------------------------------------------

vhdlParser::Concurrent_assertion_statementContext::Concurrent_assertion_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Assertion_statementContext* vhdlParser::Concurrent_assertion_statementContext::assertion_statement() {
  return getRuleContext<vhdlParser::Assertion_statementContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_assertion_statementContext::KW_POSTPONED() {
  return getToken(vhdlParser::KW_POSTPONED, 0);
}


size_t vhdlParser::Concurrent_assertion_statementContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_assertion_statement;
}

void vhdlParser::Concurrent_assertion_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrent_assertion_statement(this);
}

void vhdlParser::Concurrent_assertion_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrent_assertion_statement(this);
}


antlrcpp::Any vhdlParser::Concurrent_assertion_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConcurrent_assertion_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_assertion_statementContext* vhdlParser::concurrent_assertion_statement() {
  Concurrent_assertion_statementContext *_localctx = _tracker.createInstance<Concurrent_assertion_statementContext>(_ctx, getState());
  enterRule(_localctx, 460, vhdlParser::RuleConcurrent_assertion_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2381);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_POSTPONED) {
      setState(2380);
      match(vhdlParser::KW_POSTPONED);
    }
    setState(2383);
    assertion_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_signal_assignment_statementContext ------------------------------------------------------------------

vhdlParser::Concurrent_signal_assignment_statementContext::Concurrent_signal_assignment_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Concurrent_signal_assignment_anyContext* vhdlParser::Concurrent_signal_assignment_statementContext::concurrent_signal_assignment_any() {
  return getRuleContext<vhdlParser::Concurrent_signal_assignment_anyContext>(0);
}

vhdlParser::Concurrent_selected_signal_assignmentContext* vhdlParser::Concurrent_signal_assignment_statementContext::concurrent_selected_signal_assignment() {
  return getRuleContext<vhdlParser::Concurrent_selected_signal_assignmentContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_signal_assignment_statementContext::KW_POSTPONED() {
  return getToken(vhdlParser::KW_POSTPONED, 0);
}


size_t vhdlParser::Concurrent_signal_assignment_statementContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_signal_assignment_statement;
}

void vhdlParser::Concurrent_signal_assignment_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrent_signal_assignment_statement(this);
}

void vhdlParser::Concurrent_signal_assignment_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrent_signal_assignment_statement(this);
}


antlrcpp::Any vhdlParser::Concurrent_signal_assignment_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConcurrent_signal_assignment_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_signal_assignment_statementContext* vhdlParser::concurrent_signal_assignment_statement() {
  Concurrent_signal_assignment_statementContext *_localctx = _tracker.createInstance<Concurrent_signal_assignment_statementContext>(_ctx, getState());
  enterRule(_localctx, 462, vhdlParser::RuleConcurrent_signal_assignment_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2386);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_POSTPONED) {
      setState(2385);
      match(vhdlParser::KW_POSTPONED);
    }
    setState(2390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::SHIFT_LEFT: {
        setState(2388);
        concurrent_signal_assignment_any();
        break;
      }

      case vhdlParser::KW_WITH: {
        setState(2389);
        concurrent_selected_signal_assignment();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_signal_assignment_anyContext ------------------------------------------------------------------

vhdlParser::Concurrent_signal_assignment_anyContext::Concurrent_signal_assignment_anyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Concurrent_signal_assignment_anyContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_signal_assignment_anyContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

tree::TerminalNode* vhdlParser::Concurrent_signal_assignment_anyContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::WaveformContext* vhdlParser::Concurrent_signal_assignment_anyContext::waveform() {
  return getRuleContext<vhdlParser::WaveformContext>(0);
}

vhdlParser::Conditional_waveformsContext* vhdlParser::Concurrent_signal_assignment_anyContext::conditional_waveforms() {
  return getRuleContext<vhdlParser::Conditional_waveformsContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_signal_assignment_anyContext::KW_GUARDED() {
  return getToken(vhdlParser::KW_GUARDED, 0);
}

vhdlParser::Delay_mechanismContext* vhdlParser::Concurrent_signal_assignment_anyContext::delay_mechanism() {
  return getRuleContext<vhdlParser::Delay_mechanismContext>(0);
}


size_t vhdlParser::Concurrent_signal_assignment_anyContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_signal_assignment_any;
}

void vhdlParser::Concurrent_signal_assignment_anyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrent_signal_assignment_any(this);
}

void vhdlParser::Concurrent_signal_assignment_anyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrent_signal_assignment_any(this);
}


antlrcpp::Any vhdlParser::Concurrent_signal_assignment_anyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConcurrent_signal_assignment_any(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_signal_assignment_anyContext* vhdlParser::concurrent_signal_assignment_any() {
  Concurrent_signal_assignment_anyContext *_localctx = _tracker.createInstance<Concurrent_signal_assignment_anyContext>(_ctx, getState());
  enterRule(_localctx, 464, vhdlParser::RuleConcurrent_signal_assignment_any);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2392);
    target();
    setState(2393);
    match(vhdlParser::CONASGN);
    setState(2395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GUARDED) {
      setState(2394);
      match(vhdlParser::KW_GUARDED);
    }
    setState(2398);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_INERTIAL)
      | (1ULL << vhdlParser::KW_REJECT)
      | (1ULL << vhdlParser::KW_TRANSPORT))) != 0)) {
      setState(2397);
      delay_mechanism();
    }
    setState(2402);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 265, _ctx)) {
    case 1: {
      setState(2400);
      waveform();
      break;
    }

    case 2: {
      setState(2401);
      conditional_waveforms();
      break;
    }

    default:
      break;
    }
    setState(2404);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_selected_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Concurrent_selected_signal_assignmentContext::Concurrent_selected_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::KW_WITH() {
  return getToken(vhdlParser::KW_WITH, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Concurrent_selected_signal_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::KW_SELECT() {
  return getToken(vhdlParser::KW_SELECT, 0);
}

vhdlParser::TargetContext* vhdlParser::Concurrent_selected_signal_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::CONASGN() {
  return getToken(vhdlParser::CONASGN, 0);
}

vhdlParser::Selected_waveformsContext* vhdlParser::Concurrent_selected_signal_assignmentContext::selected_waveforms() {
  return getRuleContext<vhdlParser::Selected_waveformsContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::QUESTIONMARK() {
  return getToken(vhdlParser::QUESTIONMARK, 0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::KW_GUARDED() {
  return getToken(vhdlParser::KW_GUARDED, 0);
}

vhdlParser::Delay_mechanismContext* vhdlParser::Concurrent_selected_signal_assignmentContext::delay_mechanism() {
  return getRuleContext<vhdlParser::Delay_mechanismContext>(0);
}


size_t vhdlParser::Concurrent_selected_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_selected_signal_assignment;
}

void vhdlParser::Concurrent_selected_signal_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrent_selected_signal_assignment(this);
}

void vhdlParser::Concurrent_selected_signal_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrent_selected_signal_assignment(this);
}


antlrcpp::Any vhdlParser::Concurrent_selected_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitConcurrent_selected_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_selected_signal_assignmentContext* vhdlParser::concurrent_selected_signal_assignment() {
  Concurrent_selected_signal_assignmentContext *_localctx = _tracker.createInstance<Concurrent_selected_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 466, vhdlParser::RuleConcurrent_selected_signal_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2406);
    match(vhdlParser::KW_WITH);
    setState(2407);
    expression(0);
    setState(2408);
    match(vhdlParser::KW_SELECT);
    setState(2410);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::QUESTIONMARK) {
      setState(2409);
      match(vhdlParser::QUESTIONMARK);
    }
    setState(2412);
    target();
    setState(2413);
    match(vhdlParser::CONASGN);
    setState(2415);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GUARDED) {
      setState(2414);
      match(vhdlParser::KW_GUARDED);
    }
    setState(2418);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_INERTIAL)
      | (1ULL << vhdlParser::KW_REJECT)
      | (1ULL << vhdlParser::KW_TRANSPORT))) != 0)) {
      setState(2417);
      delay_mechanism();
    }
    setState(2420);
    selected_waveforms();
    setState(2421);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_instantiation_statementContext ------------------------------------------------------------------

vhdlParser::Component_instantiation_statementContext::Component_instantiation_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Instantiated_unitContext* vhdlParser::Component_instantiation_statementContext::instantiated_unit() {
  return getRuleContext<vhdlParser::Instantiated_unitContext>(0);
}

tree::TerminalNode* vhdlParser::Component_instantiation_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Component_instantiation_statementContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}

vhdlParser::Port_map_aspectContext* vhdlParser::Component_instantiation_statementContext::port_map_aspect() {
  return getRuleContext<vhdlParser::Port_map_aspectContext>(0);
}


size_t vhdlParser::Component_instantiation_statementContext::getRuleIndex() const {
  return vhdlParser::RuleComponent_instantiation_statement;
}

void vhdlParser::Component_instantiation_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_instantiation_statement(this);
}

void vhdlParser::Component_instantiation_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_instantiation_statement(this);
}


antlrcpp::Any vhdlParser::Component_instantiation_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitComponent_instantiation_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Component_instantiation_statementContext* vhdlParser::component_instantiation_statement() {
  Component_instantiation_statementContext *_localctx = _tracker.createInstance<Component_instantiation_statementContext>(_ctx, getState());
  enterRule(_localctx, 468, vhdlParser::RuleComponent_instantiation_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2423);
    instantiated_unit();
    setState(2425);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_GENERIC) {
      setState(2424);
      generic_map_aspect();
    }
    setState(2428);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_PORT) {
      setState(2427);
      port_map_aspect();
    }
    setState(2430);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Instantiated_unitContext ------------------------------------------------------------------

vhdlParser::Instantiated_unitContext::Instantiated_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Instantiated_unitContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::KW_COMPONENT() {
  return getToken(vhdlParser::KW_COMPONENT, 0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::KW_ENTITY() {
  return getToken(vhdlParser::KW_ENTITY, 0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Instantiated_unitContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::KW_CONFIGURATION() {
  return getToken(vhdlParser::KW_CONFIGURATION, 0);
}


size_t vhdlParser::Instantiated_unitContext::getRuleIndex() const {
  return vhdlParser::RuleInstantiated_unit;
}

void vhdlParser::Instantiated_unitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstantiated_unit(this);
}

void vhdlParser::Instantiated_unitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstantiated_unit(this);
}


antlrcpp::Any vhdlParser::Instantiated_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitInstantiated_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Instantiated_unitContext* vhdlParser::instantiated_unit() {
  Instantiated_unitContext *_localctx = _tracker.createInstance<Instantiated_unitContext>(_ctx, getState());
  enterRule(_localctx, 470, vhdlParser::RuleInstantiated_unit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2446);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_COMPONENT:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::SHIFT_LEFT: {
        enterOuterAlt(_localctx, 1);
        setState(2433);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::KW_COMPONENT) {
          setState(2432);
          match(vhdlParser::KW_COMPONENT);
        }
        setState(2435);
        name(0);
        break;
      }

      case vhdlParser::KW_ENTITY: {
        enterOuterAlt(_localctx, 2);
        setState(2436);
        match(vhdlParser::KW_ENTITY);
        setState(2437);
        name(0);
        setState(2442);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::LPAREN) {
          setState(2438);
          match(vhdlParser::LPAREN);
          setState(2439);
          identifier();
          setState(2440);
          match(vhdlParser::RPAREN);
        }
        break;
      }

      case vhdlParser::KW_CONFIGURATION: {
        enterOuterAlt(_localctx, 3);
        setState(2444);
        match(vhdlParser::KW_CONFIGURATION);
        setState(2445);
        name(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generate_statementContext ------------------------------------------------------------------

vhdlParser::Generate_statementContext::Generate_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::For_generate_statementContext* vhdlParser::Generate_statementContext::for_generate_statement() {
  return getRuleContext<vhdlParser::For_generate_statementContext>(0);
}

vhdlParser::If_generate_statementContext* vhdlParser::Generate_statementContext::if_generate_statement() {
  return getRuleContext<vhdlParser::If_generate_statementContext>(0);
}

vhdlParser::Case_generate_statementContext* vhdlParser::Generate_statementContext::case_generate_statement() {
  return getRuleContext<vhdlParser::Case_generate_statementContext>(0);
}


size_t vhdlParser::Generate_statementContext::getRuleIndex() const {
  return vhdlParser::RuleGenerate_statement;
}

void vhdlParser::Generate_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenerate_statement(this);
}

void vhdlParser::Generate_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenerate_statement(this);
}


antlrcpp::Any vhdlParser::Generate_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGenerate_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generate_statementContext* vhdlParser::generate_statement() {
  Generate_statementContext *_localctx = _tracker.createInstance<Generate_statementContext>(_ctx, getState());
  enterRule(_localctx, 472, vhdlParser::RuleGenerate_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2451);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_FOR: {
        enterOuterAlt(_localctx, 1);
        setState(2448);
        for_generate_statement();
        break;
      }

      case vhdlParser::KW_IF: {
        enterOuterAlt(_localctx, 2);
        setState(2449);
        if_generate_statement();
        break;
      }

      case vhdlParser::KW_CASE: {
        enterOuterAlt(_localctx, 3);
        setState(2450);
        case_generate_statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_generate_statementContext ------------------------------------------------------------------

vhdlParser::For_generate_statementContext::For_generate_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::For_generate_statementContext::KW_FOR() {
  return getToken(vhdlParser::KW_FOR, 0);
}

vhdlParser::Parameter_specificationContext* vhdlParser::For_generate_statementContext::parameter_specification() {
  return getRuleContext<vhdlParser::Parameter_specificationContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::For_generate_statementContext::KW_GENERATE() {
  return getTokens(vhdlParser::KW_GENERATE);
}

tree::TerminalNode* vhdlParser::For_generate_statementContext::KW_GENERATE(size_t i) {
  return getToken(vhdlParser::KW_GENERATE, i);
}

vhdlParser::Generate_statement_bodyContext* vhdlParser::For_generate_statementContext::generate_statement_body() {
  return getRuleContext<vhdlParser::Generate_statement_bodyContext>(0);
}

tree::TerminalNode* vhdlParser::For_generate_statementContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::For_generate_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::LabelContext* vhdlParser::For_generate_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::For_generate_statementContext::getRuleIndex() const {
  return vhdlParser::RuleFor_generate_statement;
}

void vhdlParser::For_generate_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_generate_statement(this);
}

void vhdlParser::For_generate_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_generate_statement(this);
}


antlrcpp::Any vhdlParser::For_generate_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitFor_generate_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::For_generate_statementContext* vhdlParser::for_generate_statement() {
  For_generate_statementContext *_localctx = _tracker.createInstance<For_generate_statementContext>(_ctx, getState());
  enterRule(_localctx, 474, vhdlParser::RuleFor_generate_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2453);
    match(vhdlParser::KW_FOR);
    setState(2454);
    parameter_specification();
    setState(2455);
    match(vhdlParser::KW_GENERATE);
    setState(2456);
    generate_statement_body();
    setState(2457);
    match(vhdlParser::KW_END);
    setState(2458);
    match(vhdlParser::KW_GENERATE);
    setState(2460);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2459);
      label();
    }
    setState(2462);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_generate_statementContext ------------------------------------------------------------------

vhdlParser::If_generate_statementContext::If_generate_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::KW_IF() {
  return getToken(vhdlParser::KW_IF, 0);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::If_generate_statementContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::If_generate_statementContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::If_generate_statementContext::KW_GENERATE() {
  return getTokens(vhdlParser::KW_GENERATE);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::KW_GENERATE(size_t i) {
  return getToken(vhdlParser::KW_GENERATE, i);
}

std::vector<vhdlParser::Generate_statement_bodyContext *> vhdlParser::If_generate_statementContext::generate_statement_body() {
  return getRuleContexts<vhdlParser::Generate_statement_bodyContext>();
}

vhdlParser::Generate_statement_bodyContext* vhdlParser::If_generate_statementContext::generate_statement_body(size_t i) {
  return getRuleContext<vhdlParser::Generate_statement_bodyContext>(i);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::KW_ELSE() {
  return getToken(vhdlParser::KW_ELSE, 0);
}

std::vector<vhdlParser::LabelContext *> vhdlParser::If_generate_statementContext::label() {
  return getRuleContexts<vhdlParser::LabelContext>();
}

vhdlParser::LabelContext* vhdlParser::If_generate_statementContext::label(size_t i) {
  return getRuleContext<vhdlParser::LabelContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::If_generate_statementContext::COLON() {
  return getTokens(vhdlParser::COLON);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::COLON(size_t i) {
  return getToken(vhdlParser::COLON, i);
}

std::vector<tree::TerminalNode *> vhdlParser::If_generate_statementContext::KW_ELSIF() {
  return getTokens(vhdlParser::KW_ELSIF);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::KW_ELSIF(size_t i) {
  return getToken(vhdlParser::KW_ELSIF, i);
}


size_t vhdlParser::If_generate_statementContext::getRuleIndex() const {
  return vhdlParser::RuleIf_generate_statement;
}

void vhdlParser::If_generate_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_generate_statement(this);
}

void vhdlParser::If_generate_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_generate_statement(this);
}


antlrcpp::Any vhdlParser::If_generate_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitIf_generate_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::If_generate_statementContext* vhdlParser::if_generate_statement() {
  If_generate_statementContext *_localctx = _tracker.createInstance<If_generate_statementContext>(_ctx, getState());
  enterRule(_localctx, 476, vhdlParser::RuleIf_generate_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2464);
    match(vhdlParser::KW_IF);
    setState(2468);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 276, _ctx)) {
    case 1: {
      setState(2465);
      label();
      setState(2466);
      match(vhdlParser::COLON);
      break;
    }

    default:
      break;
    }
    setState(2470);
    condition();
    setState(2471);
    match(vhdlParser::KW_GENERATE);
    setState(2472);
    generate_statement_body();
    setState(2485);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 278, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2473);
        match(vhdlParser::KW_ELSIF);
        setState(2477);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 277, _ctx)) {
        case 1: {
          setState(2474);
          label();
          setState(2475);
          match(vhdlParser::COLON);
          break;
        }

        default:
          break;
        }
        setState(2479);
        condition();
        setState(2480);
        match(vhdlParser::KW_GENERATE);
        setState(2481);
        generate_statement_body(); 
      }
      setState(2487);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 278, _ctx);
    }
    setState(2497);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 280, _ctx)) {
    case 1: {
      setState(2488);
      match(vhdlParser::KW_ELSE);
      setState(2492);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::BASIC_IDENTIFIER

      || _la == vhdlParser::EXTENDED_IDENTIFIER) {
        setState(2489);
        label();
        setState(2490);
        match(vhdlParser::COLON);
      }
      setState(2494);
      match(vhdlParser::KW_GENERATE);
      setState(2495);
      generate_statement_body();
      break;
    }

    case 2: {
      setState(2496);

      if (!(_input->LA(1) != KW_ELSE)) throw FailedPredicateException(this, "_input->LA(1) != KW_ELSE");
      break;
    }

    default:
      break;
    }
    setState(2499);
    match(vhdlParser::KW_END);
    setState(2500);
    match(vhdlParser::KW_GENERATE);
    setState(2502);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2501);
      label();
    }
    setState(2504);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_generate_statementContext ------------------------------------------------------------------

vhdlParser::Case_generate_statementContext::Case_generate_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Case_generate_statementContext::KW_CASE() {
  return getToken(vhdlParser::KW_CASE, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Case_generate_statementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Case_generate_statementContext::KW_GENERATE() {
  return getTokens(vhdlParser::KW_GENERATE);
}

tree::TerminalNode* vhdlParser::Case_generate_statementContext::KW_GENERATE(size_t i) {
  return getToken(vhdlParser::KW_GENERATE, i);
}

tree::TerminalNode* vhdlParser::Case_generate_statementContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Case_generate_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<vhdlParser::Case_generate_alternativeContext *> vhdlParser::Case_generate_statementContext::case_generate_alternative() {
  return getRuleContexts<vhdlParser::Case_generate_alternativeContext>();
}

vhdlParser::Case_generate_alternativeContext* vhdlParser::Case_generate_statementContext::case_generate_alternative(size_t i) {
  return getRuleContext<vhdlParser::Case_generate_alternativeContext>(i);
}

vhdlParser::LabelContext* vhdlParser::Case_generate_statementContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::Case_generate_statementContext::getRuleIndex() const {
  return vhdlParser::RuleCase_generate_statement;
}

void vhdlParser::Case_generate_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_generate_statement(this);
}

void vhdlParser::Case_generate_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_generate_statement(this);
}


antlrcpp::Any vhdlParser::Case_generate_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitCase_generate_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Case_generate_statementContext* vhdlParser::case_generate_statement() {
  Case_generate_statementContext *_localctx = _tracker.createInstance<Case_generate_statementContext>(_ctx, getState());
  enterRule(_localctx, 478, vhdlParser::RuleCase_generate_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2506);
    match(vhdlParser::KW_CASE);
    setState(2507);
    expression(0);
    setState(2508);
    match(vhdlParser::KW_GENERATE);
    setState(2510); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2509);
      case_generate_alternative();
      setState(2512); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::KW_WHEN);
    setState(2514);
    match(vhdlParser::KW_END);
    setState(2515);
    match(vhdlParser::KW_GENERATE);
    setState(2517);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2516);
      label();
    }
    setState(2519);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_generate_alternativeContext ------------------------------------------------------------------

vhdlParser::Case_generate_alternativeContext::Case_generate_alternativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Case_generate_alternativeContext::KW_WHEN() {
  return getToken(vhdlParser::KW_WHEN, 0);
}

vhdlParser::ChoicesContext* vhdlParser::Case_generate_alternativeContext::choices() {
  return getRuleContext<vhdlParser::ChoicesContext>(0);
}

tree::TerminalNode* vhdlParser::Case_generate_alternativeContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}

vhdlParser::Generate_statement_body_with_begin_endContext* vhdlParser::Case_generate_alternativeContext::generate_statement_body_with_begin_end() {
  return getRuleContext<vhdlParser::Generate_statement_body_with_begin_endContext>(0);
}

vhdlParser::LabelContext* vhdlParser::Case_generate_alternativeContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}

tree::TerminalNode* vhdlParser::Case_generate_alternativeContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}


size_t vhdlParser::Case_generate_alternativeContext::getRuleIndex() const {
  return vhdlParser::RuleCase_generate_alternative;
}

void vhdlParser::Case_generate_alternativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_generate_alternative(this);
}

void vhdlParser::Case_generate_alternativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_generate_alternative(this);
}


antlrcpp::Any vhdlParser::Case_generate_alternativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitCase_generate_alternative(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Case_generate_alternativeContext* vhdlParser::case_generate_alternative() {
  Case_generate_alternativeContext *_localctx = _tracker.createInstance<Case_generate_alternativeContext>(_ctx, getState());
  enterRule(_localctx, 480, vhdlParser::RuleCase_generate_alternative);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2521);
    match(vhdlParser::KW_WHEN);
    setState(2525);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 284, _ctx)) {
    case 1: {
      setState(2522);
      label();
      setState(2523);
      match(vhdlParser::COLON);
      break;
    }

    default:
      break;
    }
    setState(2527);
    choices();
    setState(2528);
    match(vhdlParser::ARROW);
    setState(2529);
    generate_statement_body_with_begin_end();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generate_statement_body_with_begin_endContext ------------------------------------------------------------------

vhdlParser::Generate_statement_body_with_begin_endContext::Generate_statement_body_with_begin_endContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Generate_statement_body_with_begin_endContext::KW_BEGIN() {
  return getToken(vhdlParser::KW_BEGIN, 0);
}

tree::TerminalNode* vhdlParser::Generate_statement_body_with_begin_endContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Generate_statement_body_with_begin_endContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<vhdlParser::Block_declarative_itemContext *> vhdlParser::Generate_statement_body_with_begin_endContext::block_declarative_item() {
  return getRuleContexts<vhdlParser::Block_declarative_itemContext>();
}

vhdlParser::Block_declarative_itemContext* vhdlParser::Generate_statement_body_with_begin_endContext::block_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Block_declarative_itemContext>(i);
}

std::vector<vhdlParser::Concurrent_statementContext *> vhdlParser::Generate_statement_body_with_begin_endContext::concurrent_statement() {
  return getRuleContexts<vhdlParser::Concurrent_statementContext>();
}

vhdlParser::Concurrent_statementContext* vhdlParser::Generate_statement_body_with_begin_endContext::concurrent_statement(size_t i) {
  return getRuleContext<vhdlParser::Concurrent_statementContext>(i);
}

vhdlParser::LabelContext* vhdlParser::Generate_statement_body_with_begin_endContext::label() {
  return getRuleContext<vhdlParser::LabelContext>(0);
}


size_t vhdlParser::Generate_statement_body_with_begin_endContext::getRuleIndex() const {
  return vhdlParser::RuleGenerate_statement_body_with_begin_end;
}

void vhdlParser::Generate_statement_body_with_begin_endContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenerate_statement_body_with_begin_end(this);
}

void vhdlParser::Generate_statement_body_with_begin_endContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenerate_statement_body_with_begin_end(this);
}


antlrcpp::Any vhdlParser::Generate_statement_body_with_begin_endContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGenerate_statement_body_with_begin_end(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generate_statement_body_with_begin_endContext* vhdlParser::generate_statement_body_with_begin_end() {
  Generate_statement_body_with_begin_endContext *_localctx = _tracker.createInstance<Generate_statement_body_with_begin_endContext>(_ctx, getState());
  enterRule(_localctx, 482, vhdlParser::RuleGenerate_statement_body_with_begin_end);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2555);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_COMPONENT:
      case vhdlParser::KW_GROUP:
      case vhdlParser::KW_FILE:
      case vhdlParser::KW_PURE:
      case vhdlParser::KW_USE:
      case vhdlParser::KW_SHARED:
      case vhdlParser::KW_SIGNAL:
      case vhdlParser::KW_BEGIN:
      case vhdlParser::KW_DISCONNECT:
      case vhdlParser::KW_PROCEDURE:
      case vhdlParser::KW_ATTRIBUTE:
      case vhdlParser::KW_VARIABLE:
      case vhdlParser::KW_SUBTYPE:
      case vhdlParser::KW_CONSTANT:
      case vhdlParser::KW_FUNCTION:
      case vhdlParser::KW_ALIAS:
      case vhdlParser::KW_IMPURE:
      case vhdlParser::KW_PACKAGE:
      case vhdlParser::KW_FOR:
      case vhdlParser::KW_TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(2534);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << vhdlParser::KW_COMPONENT)
          | (1ULL << vhdlParser::KW_GROUP)
          | (1ULL << vhdlParser::KW_FILE)
          | (1ULL << vhdlParser::KW_PURE)
          | (1ULL << vhdlParser::KW_USE)
          | (1ULL << vhdlParser::KW_SHARED)
          | (1ULL << vhdlParser::KW_SIGNAL)
          | (1ULL << vhdlParser::KW_DISCONNECT)
          | (1ULL << vhdlParser::KW_PROCEDURE)
          | (1ULL << vhdlParser::KW_ATTRIBUTE)
          | (1ULL << vhdlParser::KW_VARIABLE)
          | (1ULL << vhdlParser::KW_SUBTYPE)
          | (1ULL << vhdlParser::KW_CONSTANT)
          | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
          | (1ULL << (vhdlParser::KW_IMPURE - 65))
          | (1ULL << (vhdlParser::KW_PACKAGE - 65))
          | (1ULL << (vhdlParser::KW_FOR - 65))
          | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
          setState(2531);
          block_declarative_item();
          setState(2536);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(2537);
        match(vhdlParser::KW_BEGIN);
        setState(2541);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::KW_PROCESS

        || _la == vhdlParser::KW_POSTPONED || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (vhdlParser::KW_WITH - 72))
          | (1ULL << (vhdlParser::KW_ASSERT - 72))
          | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 72))
          | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 72))
          | (1ULL << (vhdlParser::CHARACTER_LITERAL - 72))
          | (1ULL << (vhdlParser::STRING_LITERAL - 72))
          | (1ULL << (vhdlParser::LPAREN - 72))
          | (1ULL << (vhdlParser::SHIFT_LEFT - 72)))) != 0)) {
          setState(2538);
          concurrent_statement();
          setState(2543);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(2544);
        match(vhdlParser::KW_END);
        setState(2546);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::BASIC_IDENTIFIER

        || _la == vhdlParser::EXTENDED_IDENTIFIER) {
          setState(2545);
          label();
        }
        setState(2548);
        match(vhdlParser::SEMI);
        break;
      }

      case vhdlParser::KW_PROCESS:
      case vhdlParser::KW_POSTPONED:
      case vhdlParser::KW_END:
      case vhdlParser::KW_WITH:
      case vhdlParser::KW_ASSERT:
      case vhdlParser::KW_WHEN:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::SHIFT_LEFT: {
        enterOuterAlt(_localctx, 2);
        setState(2552);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::KW_PROCESS

        || _la == vhdlParser::KW_POSTPONED || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (vhdlParser::KW_WITH - 72))
          | (1ULL << (vhdlParser::KW_ASSERT - 72))
          | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 72))
          | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 72))
          | (1ULL << (vhdlParser::CHARACTER_LITERAL - 72))
          | (1ULL << (vhdlParser::STRING_LITERAL - 72))
          | (1ULL << (vhdlParser::LPAREN - 72))
          | (1ULL << (vhdlParser::SHIFT_LEFT - 72)))) != 0)) {
          setState(2549);
          concurrent_statement();
          setState(2554);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generate_statement_bodyContext ------------------------------------------------------------------

vhdlParser::Generate_statement_bodyContext::Generate_statement_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Generate_statement_bodyContext::KW_BEGIN() {
  return getToken(vhdlParser::KW_BEGIN, 0);
}

std::vector<vhdlParser::Block_declarative_itemContext *> vhdlParser::Generate_statement_bodyContext::block_declarative_item() {
  return getRuleContexts<vhdlParser::Block_declarative_itemContext>();
}

vhdlParser::Block_declarative_itemContext* vhdlParser::Generate_statement_bodyContext::block_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Block_declarative_itemContext>(i);
}

std::vector<vhdlParser::Concurrent_statementContext *> vhdlParser::Generate_statement_bodyContext::concurrent_statement() {
  return getRuleContexts<vhdlParser::Concurrent_statementContext>();
}

vhdlParser::Concurrent_statementContext* vhdlParser::Generate_statement_bodyContext::concurrent_statement(size_t i) {
  return getRuleContext<vhdlParser::Concurrent_statementContext>(i);
}


size_t vhdlParser::Generate_statement_bodyContext::getRuleIndex() const {
  return vhdlParser::RuleGenerate_statement_body;
}

void vhdlParser::Generate_statement_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenerate_statement_body(this);
}

void vhdlParser::Generate_statement_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenerate_statement_body(this);
}


antlrcpp::Any vhdlParser::Generate_statement_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitGenerate_statement_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generate_statement_bodyContext* vhdlParser::generate_statement_body() {
  Generate_statement_bodyContext *_localctx = _tracker.createInstance<Generate_statement_bodyContext>(_ctx, getState());
  enterRule(_localctx, 484, vhdlParser::RuleGenerate_statement_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(2576);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 293, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2560);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << vhdlParser::KW_COMPONENT)
        | (1ULL << vhdlParser::KW_GROUP)
        | (1ULL << vhdlParser::KW_FILE)
        | (1ULL << vhdlParser::KW_PURE)
        | (1ULL << vhdlParser::KW_USE)
        | (1ULL << vhdlParser::KW_SHARED)
        | (1ULL << vhdlParser::KW_SIGNAL)
        | (1ULL << vhdlParser::KW_DISCONNECT)
        | (1ULL << vhdlParser::KW_PROCEDURE)
        | (1ULL << vhdlParser::KW_ATTRIBUTE)
        | (1ULL << vhdlParser::KW_VARIABLE)
        | (1ULL << vhdlParser::KW_SUBTYPE)
        | (1ULL << vhdlParser::KW_CONSTANT)
        | (1ULL << vhdlParser::KW_FUNCTION))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::KW_ALIAS - 65))
        | (1ULL << (vhdlParser::KW_IMPURE - 65))
        | (1ULL << (vhdlParser::KW_PACKAGE - 65))
        | (1ULL << (vhdlParser::KW_FOR - 65))
        | (1ULL << (vhdlParser::KW_TYPE - 65)))) != 0)) {
        setState(2557);
        block_declarative_item();
        setState(2562);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(2563);
      match(vhdlParser::KW_BEGIN);
      setState(2567);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 291, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(2564);
          concurrent_statement(); 
        }
        setState(2569);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 291, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2573);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 292, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(2570);
          concurrent_statement(); 
        }
        setState(2575);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 292, _ctx);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

vhdlParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::LabelContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::LabelContext::getRuleIndex() const {
  return vhdlParser::RuleLabel;
}

void vhdlParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void vhdlParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}


antlrcpp::Any vhdlParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::LabelContext* vhdlParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 486, vhdlParser::RuleLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2578);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Use_clauseContext ------------------------------------------------------------------

vhdlParser::Use_clauseContext::Use_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Use_clauseContext::KW_USE() {
  return getToken(vhdlParser::KW_USE, 0);
}

std::vector<vhdlParser::Selected_nameContext *> vhdlParser::Use_clauseContext::selected_name() {
  return getRuleContexts<vhdlParser::Selected_nameContext>();
}

vhdlParser::Selected_nameContext* vhdlParser::Use_clauseContext::selected_name(size_t i) {
  return getRuleContext<vhdlParser::Selected_nameContext>(i);
}

tree::TerminalNode* vhdlParser::Use_clauseContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Use_clauseContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Use_clauseContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Use_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleUse_clause;
}

void vhdlParser::Use_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUse_clause(this);
}

void vhdlParser::Use_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUse_clause(this);
}


antlrcpp::Any vhdlParser::Use_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitUse_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Use_clauseContext* vhdlParser::use_clause() {
  Use_clauseContext *_localctx = _tracker.createInstance<Use_clauseContext>(_ctx, getState());
  enterRule(_localctx, 488, vhdlParser::RuleUse_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2580);
    match(vhdlParser::KW_USE);
    setState(2581);
    selected_name();
    setState(2586);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(2582);
      match(vhdlParser::COMMA);
      setState(2583);
      selected_name();
      setState(2588);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2589);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Design_fileContext ------------------------------------------------------------------

vhdlParser::Design_fileContext::Design_fileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Design_fileContext::EOF() {
  return getToken(vhdlParser::EOF, 0);
}

std::vector<vhdlParser::Design_unitContext *> vhdlParser::Design_fileContext::design_unit() {
  return getRuleContexts<vhdlParser::Design_unitContext>();
}

vhdlParser::Design_unitContext* vhdlParser::Design_fileContext::design_unit(size_t i) {
  return getRuleContext<vhdlParser::Design_unitContext>(i);
}


size_t vhdlParser::Design_fileContext::getRuleIndex() const {
  return vhdlParser::RuleDesign_file;
}

void vhdlParser::Design_fileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesign_file(this);
}

void vhdlParser::Design_fileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesign_file(this);
}


antlrcpp::Any vhdlParser::Design_fileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitDesign_file(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Design_fileContext* vhdlParser::design_file() {
  Design_fileContext *_localctx = _tracker.createInstance<Design_fileContext>(_ctx, getState());
  enterRule(_localctx, 490, vhdlParser::RuleDesign_file);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2594);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::KW_CONTEXT)
      | (1ULL << vhdlParser::KW_ENTITY)
      | (1ULL << vhdlParser::KW_USE)
      | (1ULL << vhdlParser::KW_LIBRARY))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (vhdlParser::KW_PACKAGE - 82))
      | (1ULL << (vhdlParser::KW_CONFIGURATION - 82))
      | (1ULL << (vhdlParser::KW_ARCHITECTURE - 82)))) != 0)) {
      setState(2591);
      design_unit();
      setState(2596);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2597);
    match(vhdlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Design_unitContext ------------------------------------------------------------------

vhdlParser::Design_unitContext::Design_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Context_clauseContext* vhdlParser::Design_unitContext::context_clause() {
  return getRuleContext<vhdlParser::Context_clauseContext>(0);
}

vhdlParser::Library_unitContext* vhdlParser::Design_unitContext::library_unit() {
  return getRuleContext<vhdlParser::Library_unitContext>(0);
}


size_t vhdlParser::Design_unitContext::getRuleIndex() const {
  return vhdlParser::RuleDesign_unit;
}

void vhdlParser::Design_unitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesign_unit(this);
}

void vhdlParser::Design_unitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesign_unit(this);
}


antlrcpp::Any vhdlParser::Design_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitDesign_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Design_unitContext* vhdlParser::design_unit() {
  Design_unitContext *_localctx = _tracker.createInstance<Design_unitContext>(_ctx, getState());
  enterRule(_localctx, 492, vhdlParser::RuleDesign_unit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2599);
    context_clause();
    setState(2600);
    library_unit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Library_unitContext ------------------------------------------------------------------

vhdlParser::Library_unitContext::Library_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Primary_unitContext* vhdlParser::Library_unitContext::primary_unit() {
  return getRuleContext<vhdlParser::Primary_unitContext>(0);
}

vhdlParser::Secondary_unitContext* vhdlParser::Library_unitContext::secondary_unit() {
  return getRuleContext<vhdlParser::Secondary_unitContext>(0);
}


size_t vhdlParser::Library_unitContext::getRuleIndex() const {
  return vhdlParser::RuleLibrary_unit;
}

void vhdlParser::Library_unitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLibrary_unit(this);
}

void vhdlParser::Library_unitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLibrary_unit(this);
}


antlrcpp::Any vhdlParser::Library_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitLibrary_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Library_unitContext* vhdlParser::library_unit() {
  Library_unitContext *_localctx = _tracker.createInstance<Library_unitContext>(_ctx, getState());
  enterRule(_localctx, 494, vhdlParser::RuleLibrary_unit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2604);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 296, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2602);
      primary_unit();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2603);
      secondary_unit();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_unitContext ------------------------------------------------------------------

vhdlParser::Primary_unitContext::Primary_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_declarationContext* vhdlParser::Primary_unitContext::entity_declaration() {
  return getRuleContext<vhdlParser::Entity_declarationContext>(0);
}

vhdlParser::Configuration_declarationContext* vhdlParser::Primary_unitContext::configuration_declaration() {
  return getRuleContext<vhdlParser::Configuration_declarationContext>(0);
}

vhdlParser::Package_declarationContext* vhdlParser::Primary_unitContext::package_declaration() {
  return getRuleContext<vhdlParser::Package_declarationContext>(0);
}

vhdlParser::Package_instantiation_declarationContext* vhdlParser::Primary_unitContext::package_instantiation_declaration() {
  return getRuleContext<vhdlParser::Package_instantiation_declarationContext>(0);
}

vhdlParser::Context_declarationContext* vhdlParser::Primary_unitContext::context_declaration() {
  return getRuleContext<vhdlParser::Context_declarationContext>(0);
}


size_t vhdlParser::Primary_unitContext::getRuleIndex() const {
  return vhdlParser::RulePrimary_unit;
}

void vhdlParser::Primary_unitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary_unit(this);
}

void vhdlParser::Primary_unitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary_unit(this);
}


antlrcpp::Any vhdlParser::Primary_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitPrimary_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Primary_unitContext* vhdlParser::primary_unit() {
  Primary_unitContext *_localctx = _tracker.createInstance<Primary_unitContext>(_ctx, getState());
  enterRule(_localctx, 496, vhdlParser::RulePrimary_unit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2611);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 297, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2606);
      entity_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2607);
      configuration_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2608);
      package_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2609);
      package_instantiation_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2610);
      context_declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Secondary_unitContext ------------------------------------------------------------------

vhdlParser::Secondary_unitContext::Secondary_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Architecture_bodyContext* vhdlParser::Secondary_unitContext::architecture_body() {
  return getRuleContext<vhdlParser::Architecture_bodyContext>(0);
}

vhdlParser::Package_bodyContext* vhdlParser::Secondary_unitContext::package_body() {
  return getRuleContext<vhdlParser::Package_bodyContext>(0);
}


size_t vhdlParser::Secondary_unitContext::getRuleIndex() const {
  return vhdlParser::RuleSecondary_unit;
}

void vhdlParser::Secondary_unitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondary_unit(this);
}

void vhdlParser::Secondary_unitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondary_unit(this);
}


antlrcpp::Any vhdlParser::Secondary_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitSecondary_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Secondary_unitContext* vhdlParser::secondary_unit() {
  Secondary_unitContext *_localctx = _tracker.createInstance<Secondary_unitContext>(_ctx, getState());
  enterRule(_localctx, 498, vhdlParser::RuleSecondary_unit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2615);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_ARCHITECTURE: {
        enterOuterAlt(_localctx, 1);
        setState(2613);
        architecture_body();
        break;
      }

      case vhdlParser::KW_PACKAGE: {
        enterOuterAlt(_localctx, 2);
        setState(2614);
        package_body();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Library_clauseContext ------------------------------------------------------------------

vhdlParser::Library_clauseContext::Library_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Library_clauseContext::KW_LIBRARY() {
  return getToken(vhdlParser::KW_LIBRARY, 0);
}

vhdlParser::Logical_name_listContext* vhdlParser::Library_clauseContext::logical_name_list() {
  return getRuleContext<vhdlParser::Logical_name_listContext>(0);
}

tree::TerminalNode* vhdlParser::Library_clauseContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Library_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleLibrary_clause;
}

void vhdlParser::Library_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLibrary_clause(this);
}

void vhdlParser::Library_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLibrary_clause(this);
}


antlrcpp::Any vhdlParser::Library_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitLibrary_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Library_clauseContext* vhdlParser::library_clause() {
  Library_clauseContext *_localctx = _tracker.createInstance<Library_clauseContext>(_ctx, getState());
  enterRule(_localctx, 500, vhdlParser::RuleLibrary_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2617);
    match(vhdlParser::KW_LIBRARY);
    setState(2618);
    logical_name_list();
    setState(2619);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_name_listContext ------------------------------------------------------------------

vhdlParser::Logical_name_listContext::Logical_name_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Logical_name_listContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}


size_t vhdlParser::Logical_name_listContext::getRuleIndex() const {
  return vhdlParser::RuleLogical_name_list;
}

void vhdlParser::Logical_name_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_name_list(this);
}

void vhdlParser::Logical_name_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_name_list(this);
}


antlrcpp::Any vhdlParser::Logical_name_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitLogical_name_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Logical_name_listContext* vhdlParser::logical_name_list() {
  Logical_name_listContext *_localctx = _tracker.createInstance<Logical_name_listContext>(_ctx, getState());
  enterRule(_localctx, 502, vhdlParser::RuleLogical_name_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2621);
    identifier_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Context_declarationContext ------------------------------------------------------------------

vhdlParser::Context_declarationContext::Context_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Context_declarationContext::KW_CONTEXT() {
  return getTokens(vhdlParser::KW_CONTEXT);
}

tree::TerminalNode* vhdlParser::Context_declarationContext::KW_CONTEXT(size_t i) {
  return getToken(vhdlParser::KW_CONTEXT, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Context_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Context_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Context_declarationContext::KW_IS() {
  return getToken(vhdlParser::KW_IS, 0);
}

vhdlParser::Context_clauseContext* vhdlParser::Context_declarationContext::context_clause() {
  return getRuleContext<vhdlParser::Context_clauseContext>(0);
}

tree::TerminalNode* vhdlParser::Context_declarationContext::KW_END() {
  return getToken(vhdlParser::KW_END, 0);
}

tree::TerminalNode* vhdlParser::Context_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Context_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleContext_declaration;
}

void vhdlParser::Context_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContext_declaration(this);
}

void vhdlParser::Context_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContext_declaration(this);
}


antlrcpp::Any vhdlParser::Context_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitContext_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Context_declarationContext* vhdlParser::context_declaration() {
  Context_declarationContext *_localctx = _tracker.createInstance<Context_declarationContext>(_ctx, getState());
  enterRule(_localctx, 504, vhdlParser::RuleContext_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2623);
    match(vhdlParser::KW_CONTEXT);
    setState(2624);
    identifier();
    setState(2625);
    match(vhdlParser::KW_IS);
    setState(2626);
    context_clause();
    setState(2627);
    match(vhdlParser::KW_END);
    setState(2629);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::KW_CONTEXT) {
      setState(2628);
      match(vhdlParser::KW_CONTEXT);
    }
    setState(2632);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2631);
      identifier();
    }
    setState(2634);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Context_clauseContext ------------------------------------------------------------------

vhdlParser::Context_clauseContext::Context_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Context_itemContext *> vhdlParser::Context_clauseContext::context_item() {
  return getRuleContexts<vhdlParser::Context_itemContext>();
}

vhdlParser::Context_itemContext* vhdlParser::Context_clauseContext::context_item(size_t i) {
  return getRuleContext<vhdlParser::Context_itemContext>(i);
}


size_t vhdlParser::Context_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleContext_clause;
}

void vhdlParser::Context_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContext_clause(this);
}

void vhdlParser::Context_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContext_clause(this);
}


antlrcpp::Any vhdlParser::Context_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitContext_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Context_clauseContext* vhdlParser::context_clause() {
  Context_clauseContext *_localctx = _tracker.createInstance<Context_clauseContext>(_ctx, getState());
  enterRule(_localctx, 506, vhdlParser::RuleContext_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2639);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 301, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2636);
        context_item(); 
      }
      setState(2641);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 301, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Context_itemContext ------------------------------------------------------------------

vhdlParser::Context_itemContext::Context_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Library_clauseContext* vhdlParser::Context_itemContext::library_clause() {
  return getRuleContext<vhdlParser::Library_clauseContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Context_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Context_referenceContext* vhdlParser::Context_itemContext::context_reference() {
  return getRuleContext<vhdlParser::Context_referenceContext>(0);
}


size_t vhdlParser::Context_itemContext::getRuleIndex() const {
  return vhdlParser::RuleContext_item;
}

void vhdlParser::Context_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContext_item(this);
}

void vhdlParser::Context_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContext_item(this);
}


antlrcpp::Any vhdlParser::Context_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitContext_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Context_itemContext* vhdlParser::context_item() {
  Context_itemContext *_localctx = _tracker.createInstance<Context_itemContext>(_ctx, getState());
  enterRule(_localctx, 508, vhdlParser::RuleContext_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(2645);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::KW_LIBRARY: {
        enterOuterAlt(_localctx, 1);
        setState(2642);
        library_clause();
        break;
      }

      case vhdlParser::KW_USE: {
        enterOuterAlt(_localctx, 2);
        setState(2643);
        use_clause();
        break;
      }

      case vhdlParser::KW_CONTEXT: {
        enterOuterAlt(_localctx, 3);
        setState(2644);
        context_reference();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Context_referenceContext ------------------------------------------------------------------

vhdlParser::Context_referenceContext::Context_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Context_referenceContext::KW_CONTEXT() {
  return getToken(vhdlParser::KW_CONTEXT, 0);
}

std::vector<vhdlParser::Selected_nameContext *> vhdlParser::Context_referenceContext::selected_name() {
  return getRuleContexts<vhdlParser::Selected_nameContext>();
}

vhdlParser::Selected_nameContext* vhdlParser::Context_referenceContext::selected_name(size_t i) {
  return getRuleContext<vhdlParser::Selected_nameContext>(i);
}

tree::TerminalNode* vhdlParser::Context_referenceContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Context_referenceContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Context_referenceContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Context_referenceContext::getRuleIndex() const {
  return vhdlParser::RuleContext_reference;
}

void vhdlParser::Context_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContext_reference(this);
}

void vhdlParser::Context_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContext_reference(this);
}


antlrcpp::Any vhdlParser::Context_referenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitContext_reference(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Context_referenceContext* vhdlParser::context_reference() {
  Context_referenceContext *_localctx = _tracker.createInstance<Context_referenceContext>(_ctx, getState());
  enterRule(_localctx, 510, vhdlParser::RuleContext_reference);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2647);
    match(vhdlParser::KW_CONTEXT);
    setState(2648);
    selected_name();
    setState(2653);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(2649);
      match(vhdlParser::COMMA);
      setState(2650);
      selected_name();
      setState(2655);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2656);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

vhdlParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::IdentifierContext::BASIC_IDENTIFIER() {
  return getToken(vhdlParser::BASIC_IDENTIFIER, 0);
}

tree::TerminalNode* vhdlParser::IdentifierContext::EXTENDED_IDENTIFIER() {
  return getToken(vhdlParser::EXTENDED_IDENTIFIER, 0);
}


size_t vhdlParser::IdentifierContext::getRuleIndex() const {
  return vhdlParser::RuleIdentifier;
}

void vhdlParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void vhdlParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<vhdlParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


antlrcpp::Any vhdlParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::IdentifierContext* vhdlParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 512, vhdlParser::RuleIdentifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2658);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool vhdlParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return nameSempred(dynamic_cast<NameContext *>(context), predicateIndex);
    case 156: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 157: return simple_expressionSempred(dynamic_cast<Simple_expressionContext *>(context), predicateIndex);
    case 197: return conditional_waveformsSempred(dynamic_cast<Conditional_waveformsContext *>(context), predicateIndex);
    case 199: return conditional_expressionsSempred(dynamic_cast<Conditional_expressionsContext *>(context), predicateIndex);
    case 211: return if_statementSempred(dynamic_cast<If_statementContext *>(context), predicateIndex);
    case 238: return if_generate_statementSempred(dynamic_cast<If_generate_statementContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool vhdlParser::nameSempred(NameContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool vhdlParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool vhdlParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool vhdlParser::conditional_waveformsSempred(Conditional_waveformsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return _input->LA(1) != KW_ELSE;

  default:
    break;
  }
  return true;
}

bool vhdlParser::conditional_expressionsSempred(Conditional_expressionsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return _input->LA(1) != KW_ELSE;

  default:
    break;
  }
  return true;
}

bool vhdlParser::if_statementSempred(If_statementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return _input->LA(1) != KW_ELSE;

  default:
    break;
  }
  return true;
}

bool vhdlParser::if_generate_statementSempred(If_generate_statementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return _input->LA(1) != KW_ELSE;

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> vhdlParser::_decisionToDFA;
atn::PredictionContextCache vhdlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN vhdlParser::_atn;
std::vector<uint16_t> vhdlParser::_serializedATN;

std::vector<std::string> vhdlParser::_ruleNames = {
  "any_keyword", "name_literal", "name", "name_slice_part", "name_attribute_part", 
  "attribute_name", "suffix", "explicit_range", "selected_name", "entity_declaration", 
  "entity_declarative_item", "entity_statement", "architecture_body", "block_declarative_item", 
  "configuration_declaration", "configuration_declarative_item", "block_configuration", 
  "block_specification", "generate_specification", "configuration_item", 
  "component_configuration", "subprogram_declaration", "subprogram_specification", 
  "procedure_specification", "function_specification", "subprogram_header", 
  "designator", "operator_symbol", "formal_parameter_list", "subprogram_body", 
  "subprogram_kind", "subprogram_instantiation_declaration", "signature", 
  "package_declaration", "package_declarative_item", "package_body", "package_instantiation_declaration", 
  "scalar_type_definition", "range_constraint", "range", "direction", "enumeration_type_definition", 
  "enumeration_literal", "integer_type_definition", "physical_type_definition", 
  "primary_unit_declaration", "secondary_unit_declaration", "floating_type_definition", 
  "composite_type_definition", "array_type_definition", "unbounded_array_definition", 
  "constrained_array_definition", "index_subtype_definition", "array_constraint", 
  "array_element_constraint", "index_constraint", "discrete_range", "record_type_definition", 
  "element_declaration", "identifier_list", "element_subtype_definition", 
  "record_constraint", "record_element_constraint", "access_type_definition", 
  "incomplete_type_declaration", "file_type_definition", "protected_type_definition", 
  "protected_type_declaration", "protected_type_declarative_item", "protected_type_body", 
  "type_declaration", "full_type_declaration", "type_definition", "subtype_declaration", 
  "subtype_indication", "resolution_indication", "element_resolution", "array_element_resolution", 
  "record_resolution", "record_element_resolution", "type_mark", "constraint", 
  "element_constraint", "object_declaration", "constant_declaration", "signal_declaration", 
  "signal_kind", "variable_declaration", "file_declaration", "file_open_information", 
  "file_logical_name", "interface_declaration", "interface_object_declaration", 
  "interface_constant_declaration", "interface_signal_declaration", "interface_variable_declaration", 
  "interface_file_declaration", "signal_mode", "interface_type_declaration", 
  "interface_incomplete_type_declaration", "interface_subprogram_declaration", 
  "interface_subprogram_specification", "interface_procedure_specification", 
  "interface_function_specification", "interface_subprogram_default", "interface_package_declaration", 
  "interface_package_generic_map_aspect", "interface_list", "interface_element", 
  "generic_clause", "generic_list", "port_clause", "port_list", "association_list", 
  "association_element", "formal_part", "actual_part", "actual_designator", 
  "generic_map_aspect", "port_map_aspect", "alias_declaration", "alias_designator", 
  "attribute_declaration", "component_declaration", "group_template_declaration", 
  "entity_class_entry_list", "entity_class_entry", "group_declaration", 
  "group_constituent_list", "group_constituent", "attribute_specification", 
  "entity_specification", "entity_class", "entity_name_list", "entity_designator", 
  "entity_tag", "configuration_specification", "simple_configuration_specification", 
  "compound_configuration_specification", "component_specification", "instantiation_list", 
  "binding_indication", "entity_aspect", "verification_unit_binding_indication", 
  "verification_unit_list", "disconnection_specification", "guarded_signal_specification", 
  "signal_list", "attribute_designator", "external_name", "external_pathname", 
  "package_pathname", "absolute_pathname", "relative_pathname", "partial_pathname", 
  "pathname_element", "expression", "simple_expression", "primary", "logical_operator", 
  "relational_operator", "shift_operator", "adding_operator", "sign", "multiplying_operator", 
  "miscellaneous_operator", "numeric_literal", "physical_literal", "aggregate", 
  "element_association", "choices", "choice", "qualified_expression", "allocator", 
  "sequence_of_statements", "sequential_statement", "wait_statement", "sensitivity_clause", 
  "sensitivity_list", "condition_clause", "condition", "timeout_clause", 
  "assertion_statement", "assertion", "report_statement", "signal_assignment_statement", 
  "simple_signal_assignment", "simple_waveform_assignment", "simple_force_assignment", 
  "simple_release_assignment", "force_mode", "delay_mechanism", "target", 
  "waveform", "waveform_element", "conditional_signal_assignment", "conditional_waveform_assignment", 
  "conditional_waveforms", "conditional_force_assignment", "conditional_expressions", 
  "selected_signal_assignment", "selected_waveform_assignment", "selected_waveforms", 
  "selected_force_assignment", "selected_expressions", "variable_assignment_statement", 
  "simple_variable_assignment", "conditional_variable_assignment", "selected_variable_assignment", 
  "procedure_call_statement", "procedure_call", "if_statement", "case_statement", 
  "case_statement_alternative", "loop_statement", "iteration_scheme", "parameter_specification", 
  "next_statement", "exit_statement", "return_statement", "null_statement", 
  "concurrent_statement_with_optional_label", "concurrent_statement", "block_statement", 
  "block_header", "process_statement", "process_sensitivity_list", "process_or_package_declarative_item", 
  "process_declarative_item", "concurrent_procedure_call_statement", "concurrent_assertion_statement", 
  "concurrent_signal_assignment_statement", "concurrent_signal_assignment_any", 
  "concurrent_selected_signal_assignment", "component_instantiation_statement", 
  "instantiated_unit", "generate_statement", "for_generate_statement", "if_generate_statement", 
  "case_generate_statement", "case_generate_alternative", "generate_statement_body_with_begin_end", 
  "generate_statement_body", "label", "use_clause", "design_file", "design_unit", 
  "library_unit", "primary_unit", "secondary_unit", "library_clause", "logical_name_list", 
  "context_declaration", "context_clause", "context_item", "context_reference", 
  "identifier"
};

std::vector<std::string> vhdlParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "'\n'", "'\r'", "' '", "'\"'", 
  "'_'", "", "';'", "'('", "')'", "'['", "']'", "'''", "'<<'", "'>>'", "'@'", 
  "'#'", "','", "'.'", "'\u003F'", "':'", "'='", "'/='", "'<'", "'>'", "'>='", 
  "'\u003F='", "'\u003F/='", "'\u003F<'", "'\u003F<='", "'\u003F>'", "'\u003F>='", 
  "'+'", "'-'", "'&'", "'|'", "'\\'", "'*'", "'/'", "'**'", "'<='", "'`'", 
  "'^'", "':='", "'<>'", "'=>'"
};

std::vector<std::string> vhdlParser::_symbolicNames = {
  "", "KW_PROCESS", "KW_CONTEXT", "KW_POSTPONED", "KW_LINKAGE", "KW_COMPONENT", 
  "KW_ABS", "KW_DEFAULT", "KW_THEN", "KW_BLOCK", "KW_REM", "KW_INERTIAL", 
  "KW_NEXT", "KW_ENTITY", "KW_ON", "KW_GROUP", "KW_XNOR", "KW_FILE", "KW_PURE", 
  "KW_GUARDED", "KW_GENERIC", "KW_RANGE", "KW_ELSE", "KW_USE", "KW_SHARED", 
  "KW_MOD", "KW_LOOP", "KW_RECORD", "KW_SIGNAL", "KW_REJECT", "KW_BEGIN", 
  "KW_SLA", "KW_DISCONNECT", "KW_OF", "KW_PROCEDURE", "KW_SRL", "KW_VUNIT", 
  "KW_ATTRIBUTE", "KW_VARIABLE", "KW_PROPERTY", "KW_UNAFFECTED", "KW_XOR", 
  "KW_REGISTER", "KW_SUBTYPE", "KW_TO", "KW_NEW", "KW_REPORT", "KW_CONSTANT", 
  "KW_BUFFER", "KW_BODY", "KW_AFTER", "KW_TRANSPORT", "KW_FUNCTION", "KW_END", 
  "KW_SELECT", "KW_OR", "KW_LIBRARY", "KW_ELSIF", "KW_SLL", "KW_MAP", "KW_SRA", 
  "KW_PROTECTED", "KW_DOWNTO", "KW_LABEL", "KW_ALL", "KW_ALIAS", "KW_GENERATE", 
  "KW_NOR", "KW_IN", "KW_RELEASE", "KW_EXIT", "KW_RETURN", "KW_WITH", "KW_UNTIL", 
  "KW_AND", "KW_INOUT", "KW_WAIT", "KW_NAND", "KW_ARRAY", "KW_FORCE", "KW_WHILE", 
  "KW_IMPURE", "KW_PACKAGE", "KW_UNITS", "KW_ASSERT", "KW_PARAMETER", "KW_SEVERITY", 
  "KW_LITERAL", "KW_FOR", "KW_ROR", "KW_IF", "KW_OUT", "KW_ROL", "KW_IS", 
  "KW_SEQUENCE", "KW_OTHERS", "KW_TYPE", "KW_CASE", "KW_NOT", "KW_CONFIGURATION", 
  "KW_OPEN", "KW_ARCHITECTURE", "KW_BUS", "KW_ACCESS", "KW_WHEN", "KW_PORT", 
  "KW_NULL", "BASIC_IDENTIFIER", "EXTENDED_IDENTIFIER", "DECIMAL_LITERAL", 
  "INTEGER", "BASED_LITERAL", "CHARACTER_LITERAL", "STRING_LITERAL", "BIT_STRING_LITERAL", 
  "COMMENT", "BLOCK_COMMENT", "TAB", "SPACE", "NEWLINE", "CR", "SPACE_CHARACTER", 
  "DBLQUOTE", "UNDERSCORE", "DIGIT", "SEMI", "LPAREN", "RPAREN", "LSQUARE_BR", 
  "RSQUARE_BR", "APOSTROPHE", "SHIFT_LEFT", "SHIFT_RIGHT", "AT", "HASHTAG", 
  "COMMA", "DOT", "QUESTIONMARK", "COLON", "EQ", "NE", "LT", "GT", "GE", 
  "EQ_MATCH", "NE_MATCH", "LT_MATCH", "LE_MATCH", "GT_MATCH", "GE_MATCH", 
  "PLUS", "MINUS", "AMPERSAND", "BAR", "BACKSLASH", "MUL", "DIV", "DOUBLESTAR", 
  "CONASGN", "GRAVE_ACCENT", "UP", "VARASGN", "BOX", "ARROW", "COND_OP"
};

dfa::Vocabulary vhdlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> vhdlParser::_tokenNames;

vhdlParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0xa6, 0xa67, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 
       0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 0x6d, 0x9, 0x6d, 0x4, 0x6e, 
       0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 0x9, 0x70, 0x4, 0x71, 
       0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 0x73, 0x4, 0x74, 
       0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 0x4, 0x77, 
       0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 0x7a, 
       0x9, 0x7a, 0x4, 0x7b, 0x9, 0x7b, 0x4, 0x7c, 0x9, 0x7c, 0x4, 0x7d, 
       0x9, 0x7d, 0x4, 0x7e, 0x9, 0x7e, 0x4, 0x7f, 0x9, 0x7f, 0x4, 0x80, 
       0x9, 0x80, 0x4, 0x81, 0x9, 0x81, 0x4, 0x82, 0x9, 0x82, 0x4, 0x83, 
       0x9, 0x83, 0x4, 0x84, 0x9, 0x84, 0x4, 0x85, 0x9, 0x85, 0x4, 0x86, 
       0x9, 0x86, 0x4, 0x87, 0x9, 0x87, 0x4, 0x88, 0x9, 0x88, 0x4, 0x89, 
       0x9, 0x89, 0x4, 0x8a, 0x9, 0x8a, 0x4, 0x8b, 0x9, 0x8b, 0x4, 0x8c, 
       0x9, 0x8c, 0x4, 0x8d, 0x9, 0x8d, 0x4, 0x8e, 0x9, 0x8e, 0x4, 0x8f, 
       0x9, 0x8f, 0x4, 0x90, 0x9, 0x90, 0x4, 0x91, 0x9, 0x91, 0x4, 0x92, 
       0x9, 0x92, 0x4, 0x93, 0x9, 0x93, 0x4, 0x94, 0x9, 0x94, 0x4, 0x95, 
       0x9, 0x95, 0x4, 0x96, 0x9, 0x96, 0x4, 0x97, 0x9, 0x97, 0x4, 0x98, 
       0x9, 0x98, 0x4, 0x99, 0x9, 0x99, 0x4, 0x9a, 0x9, 0x9a, 0x4, 0x9b, 
       0x9, 0x9b, 0x4, 0x9c, 0x9, 0x9c, 0x4, 0x9d, 0x9, 0x9d, 0x4, 0x9e, 
       0x9, 0x9e, 0x4, 0x9f, 0x9, 0x9f, 0x4, 0xa0, 0x9, 0xa0, 0x4, 0xa1, 
       0x9, 0xa1, 0x4, 0xa2, 0x9, 0xa2, 0x4, 0xa3, 0x9, 0xa3, 0x4, 0xa4, 
       0x9, 0xa4, 0x4, 0xa5, 0x9, 0xa5, 0x4, 0xa6, 0x9, 0xa6, 0x4, 0xa7, 
       0x9, 0xa7, 0x4, 0xa8, 0x9, 0xa8, 0x4, 0xa9, 0x9, 0xa9, 0x4, 0xaa, 
       0x9, 0xaa, 0x4, 0xab, 0x9, 0xab, 0x4, 0xac, 0x9, 0xac, 0x4, 0xad, 
       0x9, 0xad, 0x4, 0xae, 0x9, 0xae, 0x4, 0xaf, 0x9, 0xaf, 0x4, 0xb0, 
       0x9, 0xb0, 0x4, 0xb1, 0x9, 0xb1, 0x4, 0xb2, 0x9, 0xb2, 0x4, 0xb3, 
       0x9, 0xb3, 0x4, 0xb4, 0x9, 0xb4, 0x4, 0xb5, 0x9, 0xb5, 0x4, 0xb6, 
       0x9, 0xb6, 0x4, 0xb7, 0x9, 0xb7, 0x4, 0xb8, 0x9, 0xb8, 0x4, 0xb9, 
       0x9, 0xb9, 0x4, 0xba, 0x9, 0xba, 0x4, 0xbb, 0x9, 0xbb, 0x4, 0xbc, 
       0x9, 0xbc, 0x4, 0xbd, 0x9, 0xbd, 0x4, 0xbe, 0x9, 0xbe, 0x4, 0xbf, 
       0x9, 0xbf, 0x4, 0xc0, 0x9, 0xc0, 0x4, 0xc1, 0x9, 0xc1, 0x4, 0xc2, 
       0x9, 0xc2, 0x4, 0xc3, 0x9, 0xc3, 0x4, 0xc4, 0x9, 0xc4, 0x4, 0xc5, 
       0x9, 0xc5, 0x4, 0xc6, 0x9, 0xc6, 0x4, 0xc7, 0x9, 0xc7, 0x4, 0xc8, 
       0x9, 0xc8, 0x4, 0xc9, 0x9, 0xc9, 0x4, 0xca, 0x9, 0xca, 0x4, 0xcb, 
       0x9, 0xcb, 0x4, 0xcc, 0x9, 0xcc, 0x4, 0xcd, 0x9, 0xcd, 0x4, 0xce, 
       0x9, 0xce, 0x4, 0xcf, 0x9, 0xcf, 0x4, 0xd0, 0x9, 0xd0, 0x4, 0xd1, 
       0x9, 0xd1, 0x4, 0xd2, 0x9, 0xd2, 0x4, 0xd3, 0x9, 0xd3, 0x4, 0xd4, 
       0x9, 0xd4, 0x4, 0xd5, 0x9, 0xd5, 0x4, 0xd6, 0x9, 0xd6, 0x4, 0xd7, 
       0x9, 0xd7, 0x4, 0xd8, 0x9, 0xd8, 0x4, 0xd9, 0x9, 0xd9, 0x4, 0xda, 
       0x9, 0xda, 0x4, 0xdb, 0x9, 0xdb, 0x4, 0xdc, 0x9, 0xdc, 0x4, 0xdd, 
       0x9, 0xdd, 0x4, 0xde, 0x9, 0xde, 0x4, 0xdf, 0x9, 0xdf, 0x4, 0xe0, 
       0x9, 0xe0, 0x4, 0xe1, 0x9, 0xe1, 0x4, 0xe2, 0x9, 0xe2, 0x4, 0xe3, 
       0x9, 0xe3, 0x4, 0xe4, 0x9, 0xe4, 0x4, 0xe5, 0x9, 0xe5, 0x4, 0xe6, 
       0x9, 0xe6, 0x4, 0xe7, 0x9, 0xe7, 0x4, 0xe8, 0x9, 0xe8, 0x4, 0xe9, 
       0x9, 0xe9, 0x4, 0xea, 0x9, 0xea, 0x4, 0xeb, 0x9, 0xeb, 0x4, 0xec, 
       0x9, 0xec, 0x4, 0xed, 0x9, 0xed, 0x4, 0xee, 0x9, 0xee, 0x4, 0xef, 
       0x9, 0xef, 0x4, 0xf0, 0x9, 0xf0, 0x4, 0xf1, 0x9, 0xf1, 0x4, 0xf2, 
       0x9, 0xf2, 0x4, 0xf3, 0x9, 0xf3, 0x4, 0xf4, 0x9, 0xf4, 0x4, 0xf5, 
       0x9, 0xf5, 0x4, 0xf6, 0x9, 0xf6, 0x4, 0xf7, 0x9, 0xf7, 0x4, 0xf8, 
       0x9, 0xf8, 0x4, 0xf9, 0x9, 0xf9, 0x4, 0xfa, 0x9, 0xfa, 0x4, 0xfb, 
       0x9, 0xfb, 0x4, 0xfc, 0x9, 0xfc, 0x4, 0xfd, 0x9, 0xfd, 0x4, 0xfe, 
       0x9, 0xfe, 0x4, 0xff, 0x9, 0xff, 0x4, 0x100, 0x9, 0x100, 0x4, 0x101, 
       0x9, 0x101, 0x4, 0x102, 0x9, 0x102, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x20a, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x5, 0x4, 0x20f, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x217, 0xa, 0x4, 0x7, 0x4, 
       0x219, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x21c, 0xb, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x5, 0x6, 0x223, 0xa, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
       0x3, 0x8, 0x5, 0x8, 0x22d, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x236, 0xa, 0xa, 
       0xc, 0xa, 0xe, 0xa, 0x239, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x5, 0xb, 0x23f, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x242, 0xa, 
       0xb, 0x3, 0xb, 0x7, 0xb, 0x245, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x248, 
       0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x24c, 0xa, 0xb, 0xc, 0xb, 
       0xe, 0xb, 0x24f, 0xb, 0xb, 0x5, 0xb, 0x251, 0xa, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x5, 0xb, 0x255, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x258, 0xa, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x25f, 
       0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x264, 0xa, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x269, 0xa, 0xd, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x271, 
       0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x274, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x7, 0xe, 0x278, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x27b, 0xb, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x5, 0xe, 0x27f, 0xa, 0xe, 0x3, 0xe, 0x5, 0xe, 0x282, 
       0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
       0xf, 0x289, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x291, 0xa, 0x10, 0xc, 0x10, 0xe, 
       0x10, 0x294, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 
       0x299, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x29c, 0xb, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x2a1, 0xa, 0x10, 0x3, 0x10, 0x5, 
       0x10, 0x2a4, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
       0x3, 0x11, 0x5, 0x11, 0x2ab, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x7, 0x12, 0x2b0, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x2b3, 0xb, 
       0x12, 0x3, 0x12, 0x7, 0x12, 0x2b6, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
       0x2b9, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x2c4, 
       0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x2c9, 0xa, 
       0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x2cd, 0xa, 0x15, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x2d4, 0xa, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x2d9, 0xa, 0x16, 
       0xc, 0x16, 0xe, 0x16, 0x2dc, 0xb, 0x16, 0x3, 0x16, 0x5, 0x16, 0x2df, 
       0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x2ea, 0xa, 
       0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x2ef, 0xa, 0x19, 
       0x3, 0x19, 0x5, 0x19, 0x2f2, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x5, 0x19, 0x2f8, 0xa, 0x19, 0x3, 0x1a, 0x5, 0x1a, 
       0x2fb, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x300, 
       0xa, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x303, 0xa, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x309, 0xa, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
       0x3, 0x1b, 0x5, 0x1b, 0x313, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 
       0x1c, 0x317, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x320, 0xa, 0x1f, 0xc, 
       0x1f, 0xe, 0x1f, 0x323, 0xb, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 
       0x327, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x32a, 0xb, 0x1f, 0x3, 0x1f, 
       0x3, 0x1f, 0x5, 0x1f, 0x32e, 0xa, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x331, 
       0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
       0x33d, 0xa, 0x21, 0x3, 0x21, 0x5, 0x21, 0x340, 0xa, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 
       0x348, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x34b, 0xb, 0x22, 0x5, 0x22, 
       0x34d, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x351, 0xa, 0x22, 
       0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x35c, 0xa, 0x23, 0x5, 
       0x23, 0x35e, 0xa, 0x23, 0x3, 0x23, 0x7, 0x23, 0x361, 0xa, 0x23, 0xc, 
       0x23, 0xe, 0x23, 0x364, 0xb, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 
       0x368, 0xa, 0x23, 0x3, 0x23, 0x5, 0x23, 0x36b, 0xa, 0x23, 0x3, 0x23, 
       0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
       0x373, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x7, 0x25, 0x37a, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x37d, 0xb, 
       0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x382, 0xa, 0x25, 
       0x3, 0x25, 0x5, 0x25, 0x385, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 
       0x26, 0x38f, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x397, 0xa, 0x27, 0x3, 0x28, 0x3, 
       0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x39e, 0xa, 0x29, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x7, 0x2b, 0x3a6, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x3a9, 0xb, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x3af, 0xa, 
       0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x7, 0x2e, 0x3b7, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x3ba, 0xb, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x3bf, 0xa, 0x2e, 
       0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
       0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 
       0x5, 0x32, 0x3cd, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x3d1, 
       0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
       0x7, 0x34, 0x3d8, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x3db, 0xb, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 
       0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
       0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x3ec, 0xa, 0x37, 0x3, 
       0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x3f2, 0xa, 0x37, 
       0x5, 0x37, 0x3f4, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x3fc, 0xa, 0x39, 0xc, 0x39, 
       0xe, 0x39, 0x3ff, 0xb, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 
       0x3a, 0x5, 0x3a, 0x405, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x6, 0x3b, 
       0x409, 0xa, 0x3b, 0xd, 0x3b, 0xe, 0x3b, 0x40a, 0x3, 0x3b, 0x3, 0x3b, 
       0x3, 0x3b, 0x5, 0x3b, 0x410, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
       0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 
       0x3d, 0x41a, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x41d, 0xb, 0x3d, 0x3, 
       0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 
       0x3f, 0x425, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x428, 0xb, 0x3f, 0x3, 
       0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 
       0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
       0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 0x5, 
       0x44, 0x43c, 0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x440, 0xa, 
       0x45, 0xc, 0x45, 0xe, 0x45, 0x443, 0xb, 0x45, 0x3, 0x45, 0x3, 0x45, 
       0x3, 0x45, 0x5, 0x45, 0x448, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 
       0x46, 0x3, 0x46, 0x5, 0x46, 0x44e, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 
       0x3, 0x47, 0x7, 0x47, 0x453, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x456, 
       0xb, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 
       0x45c, 0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x460, 0xa, 0x48, 
       0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
       0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 
       0x46d, 0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x5, 0x4c, 0x476, 0xa, 0x4c, 0x3, 0x4c, 
       0x3, 0x4c, 0x5, 0x4c, 0x47a, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 
       0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x5, 0x4d, 0x481, 0xa, 0x4d, 0x3, 0x4e, 
       0x3, 0x4e, 0x5, 0x4e, 0x485, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
       0x50, 0x3, 0x50, 0x3, 0x50, 0x7, 0x50, 0x48c, 0xa, 0x50, 0xc, 0x50, 
       0xe, 0x50, 0x48f, 0xb, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 
       0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x498, 0xa, 0x53, 
       0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x49c, 0xa, 0x54, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x4a2, 0xa, 0x55, 0x3, 0x56, 
       0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 
       0x4aa, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 
       0x57, 0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 0x4b3, 0xa, 0x57, 0x3, 0x57, 
       0x3, 0x57, 0x5, 0x57, 0x4b7, 0xa, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 
       0x58, 0x3, 0x58, 0x3, 0x59, 0x5, 0x59, 0x4be, 0xa, 0x59, 0x3, 0x59, 
       0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 
       0x4c6, 0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 
       0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x4cf, 0xa, 0x5a, 0x3, 0x5a, 
       0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x4d5, 0xa, 0x5b, 0x3, 
       0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x4d9, 0xa, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
       0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 
       0x5, 0x5d, 0x4e3, 0xa, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 
       0x5e, 0x5, 0x5e, 0x4e9, 0xa, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 
       0x3, 0x5f, 0x5, 0x5f, 0x4ef, 0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 
       0x5f, 0x5, 0x5f, 0x4f4, 0xa, 0x5f, 0x3, 0x60, 0x5, 0x60, 0x4f7, 0xa, 
       0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x4fc, 0xa, 0x60, 
       0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x500, 0xa, 0x60, 0x3, 0x60, 0x3, 
       0x60, 0x5, 0x60, 0x504, 0xa, 0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 
       0x3, 0x61, 0x5, 0x61, 0x50a, 0xa, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 
       0x61, 0x5, 0x61, 0x50f, 0xa, 0x61, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 
       0x3, 0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x64, 0x3, 0x64, 
       0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 
       0x5, 0x66, 0x520, 0xa, 0x66, 0x3, 0x67, 0x3, 0x67, 0x5, 0x67, 0x524, 
       0xa, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x5, 0x68, 0x529, 0xa, 
       0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x5, 0x68, 0x52f, 
       0xa, 0x68, 0x3, 0x69, 0x5, 0x69, 0x532, 0xa, 0x69, 0x3, 0x69, 0x3, 
       0x69, 0x3, 0x69, 0x5, 0x69, 0x537, 0xa, 0x69, 0x3, 0x69, 0x3, 0x69, 
       0x3, 0x69, 0x3, 0x69, 0x5, 0x69, 0x53d, 0xa, 0x69, 0x3, 0x69, 0x3, 
       0x69, 0x3, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x5, 0x6a, 0x544, 0xa, 0x6a, 
       0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 
       0x3, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 
       0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 
       0x5, 0x6c, 0x558, 0xa, 0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x7, 
       0x6d, 0x55d, 0xa, 0x6d, 0xc, 0x6d, 0xe, 0x6d, 0x560, 0xb, 0x6d, 0x3, 
       0x6e, 0x3, 0x6e, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 
       0x6f, 0x3, 0x6f, 0x3, 0x70, 0x3, 0x70, 0x3, 0x71, 0x3, 0x71, 0x3, 
       0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x72, 0x3, 0x72, 0x3, 
       0x73, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x7, 0x73, 0x578, 0xa, 0x73, 
       0xc, 0x73, 0xe, 0x73, 0x57b, 0xb, 0x73, 0x3, 0x73, 0x3, 0x73, 0x3, 
       0x74, 0x3, 0x74, 0x3, 0x74, 0x5, 0x74, 0x582, 0xa, 0x74, 0x3, 0x74, 
       0x3, 0x74, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 
       0x5, 0x75, 0x58b, 0xa, 0x75, 0x3, 0x76, 0x3, 0x76, 0x3, 0x76, 0x3, 
       0x76, 0x3, 0x76, 0x3, 0x76, 0x5, 0x76, 0x593, 0xa, 0x76, 0x3, 0x77, 
       0x5, 0x77, 0x596, 0xa, 0x77, 0x3, 0x77, 0x3, 0x77, 0x3, 0x77, 0x5, 
       0x77, 0x59b, 0xa, 0x77, 0x3, 0x78, 0x3, 0x78, 0x3, 0x78, 0x3, 0x78, 
       0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x7a, 0x3, 0x7a, 
       0x3, 0x7a, 0x3, 0x7a, 0x5, 0x7a, 0x5a9, 0xa, 0x7a, 0x3, 0x7a, 0x3, 
       0x7a, 0x3, 0x7a, 0x5, 0x7a, 0x5ae, 0xa, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 
       0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x5, 0x7b, 0x5b5, 0xa, 0x7b, 0x3, 
       0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 
       0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x5, 0x7d, 0x5c0, 0xa, 0x7d, 0x3, 0x7d, 
       0x5, 0x7d, 0x5c3, 0xa, 0x7d, 0x3, 0x7d, 0x5, 0x7d, 0x5c6, 0xa, 0x7d, 
       0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x5, 0x7d, 0x5cb, 0xa, 0x7d, 0x3, 
       0x7d, 0x3, 0x7d, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 
       0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7f, 0x3, 0x7f, 0x3, 
       0x7f, 0x7, 0x7f, 0x5da, 0xa, 0x7f, 0xc, 0x7f, 0xe, 0x7f, 0x5dd, 0xb, 
       0x7f, 0x3, 0x80, 0x3, 0x80, 0x5, 0x80, 0x5e1, 0xa, 0x80, 0x3, 0x81, 
       0x3, 0x81, 0x3, 0x81, 0x3, 0x81, 0x3, 0x81, 0x3, 0x81, 0x3, 0x81, 
       0x3, 0x81, 0x3, 0x81, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x7, 0x82, 
       0x5ef, 0xa, 0x82, 0xc, 0x82, 0xe, 0x82, 0x5f2, 0xb, 0x82, 0x3, 0x83, 
       0x3, 0x83, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 
       0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x85, 0x3, 0x85, 0x3, 0x85, 
       0x3, 0x85, 0x3, 0x86, 0x3, 0x86, 0x3, 0x87, 0x3, 0x87, 0x3, 0x87, 
       0x7, 0x87, 0x607, 0xa, 0x87, 0xc, 0x87, 0xe, 0x87, 0x60a, 0xb, 0x87, 
       0x3, 0x87, 0x3, 0x87, 0x5, 0x87, 0x60e, 0xa, 0x87, 0x3, 0x88, 0x3, 
       0x88, 0x5, 0x88, 0x612, 0xa, 0x88, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 
       0x5, 0x89, 0x617, 0xa, 0x89, 0x3, 0x8a, 0x3, 0x8a, 0x5, 0x8a, 0x61b, 
       0xa, 0x8a, 0x3, 0x8b, 0x3, 0x8b, 0x3, 0x8b, 0x3, 0x8b, 0x3, 0x8b, 
       0x3, 0x8b, 0x3, 0x8b, 0x5, 0x8b, 0x624, 0xa, 0x8b, 0x3, 0x8c, 0x3, 
       0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x6, 
       0x8c, 0x62d, 0xa, 0x8c, 0xd, 0x8c, 0xe, 0x8c, 0x62e, 0x3, 0x8c, 0x3, 
       0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8d, 0x3, 0x8d, 0x3, 0x8d, 0x3, 
       0x8d, 0x3, 0x8e, 0x3, 0x8e, 0x3, 0x8e, 0x7, 0x8e, 0x63c, 0xa, 0x8e, 
       0xc, 0x8e, 0xe, 0x8e, 0x63f, 0xb, 0x8e, 0x3, 0x8e, 0x3, 0x8e, 0x5, 
       0x8e, 0x643, 0xa, 0x8e, 0x3, 0x8f, 0x3, 0x8f, 0x5, 0x8f, 0x647, 0xa, 
       0x8f, 0x3, 0x8f, 0x5, 0x8f, 0x64a, 0xa, 0x8f, 0x3, 0x8f, 0x5, 0x8f, 
       0x64d, 0xa, 0x8f, 0x3, 0x90, 0x3, 0x90, 0x3, 0x90, 0x3, 0x90, 0x3, 
       0x90, 0x3, 0x90, 0x5, 0x90, 0x655, 0xa, 0x90, 0x3, 0x90, 0x3, 0x90, 
       0x3, 0x90, 0x5, 0x90, 0x65a, 0xa, 0x90, 0x3, 0x91, 0x3, 0x91, 0x3, 
       0x91, 0x3, 0x91, 0x3, 0x92, 0x3, 0x92, 0x3, 0x92, 0x7, 0x92, 0x663, 
       0xa, 0x92, 0xc, 0x92, 0xe, 0x92, 0x666, 0xb, 0x92, 0x3, 0x93, 0x3, 
       0x93, 0x3, 0x93, 0x3, 0x93, 0x3, 0x93, 0x3, 0x93, 0x3, 0x94, 0x3, 
       0x94, 0x3, 0x94, 0x3, 0x94, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 0x7, 
       0x95, 0x675, 0xa, 0x95, 0xc, 0x95, 0xe, 0x95, 0x678, 0xb, 0x95, 0x3, 
       0x95, 0x3, 0x95, 0x5, 0x95, 0x67c, 0xa, 0x95, 0x3, 0x96, 0x3, 0x96, 
       0x5, 0x96, 0x680, 0xa, 0x96, 0x3, 0x97, 0x3, 0x97, 0x3, 0x97, 0x3, 
       0x97, 0x3, 0x97, 0x3, 0x97, 0x3, 0x97, 0x3, 0x98, 0x3, 0x98, 0x3, 
       0x98, 0x5, 0x98, 0x68c, 0xa, 0x98, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 
       0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x7, 0x99, 
       0x696, 0xa, 0x99, 0xc, 0x99, 0xe, 0x99, 0x699, 0xb, 0x99, 0x3, 0x9a, 
       0x3, 0x9a, 0x3, 0x9a, 0x3, 0x9b, 0x3, 0x9b, 0x7, 0x9b, 0x6a0, 0xa, 
       0x9b, 0xc, 0x9b, 0xe, 0x9b, 0x6a3, 0xb, 0x9b, 0x3, 0x9b, 0x3, 0x9b, 
       0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x7, 0x9c, 0x6aa, 0xa, 0x9c, 0xc, 
       0x9c, 0xe, 0x9c, 0x6ad, 0xb, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9d, 
       0x3, 0x9d, 0x3, 0x9d, 0x3, 0x9d, 0x3, 0x9d, 0x5, 0x9d, 0x6b6, 0xa, 
       0x9d, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x5, 0x9e, 0x6bc, 
       0xa, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 
       0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 
       0x3, 0x9e, 0x7, 0x9e, 0x6ca, 0xa, 0x9e, 0xc, 0x9e, 0xe, 0x9e, 0x6cd, 
       0xb, 0x9e, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x5, 0x9f, 
       0x6d3, 0xa, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x5, 0x9f, 0x6d8, 
       0xa, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x5, 0x9f, 
       0x6de, 0xa, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x3, 
       0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x7, 0x9f, 0x6e8, 0xa, 0x9f, 
       0xc, 0x9f, 0xe, 0x9f, 0x6eb, 0xb, 0x9f, 0x3, 0xa0, 0x3, 0xa0, 0x3, 
       0xa0, 0x3, 0xa0, 0x3, 0xa0, 0x3, 0xa0, 0x5, 0xa0, 0x6f3, 0xa, 0xa0, 
       0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa3, 0x3, 0xa3, 
       0x3, 0xa4, 0x3, 0xa4, 0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa6, 0x3, 0xa6, 
       0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa8, 0x3, 0xa8, 0x5, 0xa8, 0x705, 0xa, 
       0xa8, 0x3, 0xa8, 0x3, 0xa8, 0x5, 0xa8, 0x709, 0xa, 0xa8, 0x3, 0xa8, 
       0x5, 0xa8, 0x70c, 0xa, 0xa8, 0x3, 0xa9, 0x5, 0xa9, 0x70f, 0xa, 0xa9, 
       0x3, 0xa9, 0x3, 0xa9, 0x3, 0xaa, 0x3, 0xaa, 0x3, 0xaa, 0x3, 0xaa, 
       0x7, 0xaa, 0x717, 0xa, 0xaa, 0xc, 0xaa, 0xe, 0xaa, 0x71a, 0xb, 0xaa, 
       0x3, 0xaa, 0x3, 0xaa, 0x3, 0xab, 0x3, 0xab, 0x3, 0xab, 0x5, 0xab, 
       0x721, 0xa, 0xab, 0x3, 0xab, 0x3, 0xab, 0x3, 0xac, 0x3, 0xac, 0x3, 
       0xac, 0x7, 0xac, 0x728, 0xa, 0xac, 0xc, 0xac, 0xe, 0xac, 0x72b, 0xb, 
       0xac, 0x3, 0xad, 0x3, 0xad, 0x3, 0xad, 0x5, 0xad, 0x730, 0xa, 0xad, 
       0x3, 0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 0xaf, 0x3, 0xaf, 
       0x3, 0xaf, 0x5, 0xaf, 0x739, 0xa, 0xaf, 0x3, 0xb0, 0x7, 0xb0, 0x73c, 
       0xa, 0xb0, 0xc, 0xb0, 0xe, 0xb0, 0x73f, 0xb, 0xb0, 0x3, 0xb1, 0x3, 
       0xb1, 0x3, 0xb1, 0x5, 0xb1, 0x744, 0xa, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 
       0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 
       0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x5, 0xb1, 
       0x753, 0xa, 0xb1, 0x3, 0xb2, 0x3, 0xb2, 0x5, 0xb2, 0x757, 0xa, 0xb2, 
       0x3, 0xb2, 0x5, 0xb2, 0x75a, 0xa, 0xb2, 0x3, 0xb2, 0x5, 0xb2, 0x75d, 
       0xa, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb3, 0x3, 0xb3, 0x3, 0xb3, 
       0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb4, 0x7, 0xb4, 0x767, 0xa, 0xb4, 0xc, 
       0xb4, 0xe, 0xb4, 0x76a, 0xb, 0xb4, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 
       0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb8, 
       0x3, 0xb8, 0x3, 0xb8, 0x3, 0xb9, 0x3, 0xb9, 0x3, 0xb9, 0x3, 0xb9, 
       0x5, 0xb9, 0x77b, 0xa, 0xb9, 0x3, 0xb9, 0x3, 0xb9, 0x5, 0xb9, 0x77f, 
       0xa, 0xb9, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x5, 0xba, 
       0x785, 0xa, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xbb, 0x3, 0xbb, 0x3, 
       0xbb, 0x5, 0xbb, 0x78c, 0xa, 0xbb, 0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 
       0x5, 0xbc, 0x791, 0xa, 0xbc, 0x3, 0xbd, 0x3, 0xbd, 0x3, 0xbd, 0x5, 
       0xbd, 0x796, 0xa, 0xbd, 0x3, 0xbd, 0x3, 0xbd, 0x3, 0xbd, 0x3, 0xbe, 
       0x3, 0xbe, 0x3, 0xbe, 0x3, 0xbe, 0x5, 0xbe, 0x79f, 0xa, 0xbe, 0x3, 
       0xbe, 0x3, 0xbe, 0x3, 0xbe, 0x3, 0xbf, 0x3, 0xbf, 0x3, 0xbf, 0x3, 
       0xbf, 0x5, 0xbf, 0x7a8, 0xa, 0xbf, 0x3, 0xbf, 0x3, 0xbf, 0x3, 0xc0, 
       0x3, 0xc0, 0x3, 0xc1, 0x3, 0xc1, 0x3, 0xc1, 0x5, 0xc1, 0x7b1, 0xa, 
       0xc1, 0x3, 0xc1, 0x5, 0xc1, 0x7b4, 0xa, 0xc1, 0x3, 0xc2, 0x3, 0xc2, 
       0x5, 0xc2, 0x7b8, 0xa, 0xc2, 0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 0x7, 
       0xc3, 0x7bd, 0xa, 0xc3, 0xc, 0xc3, 0xe, 0xc3, 0x7c0, 0xb, 0xc3, 0x3, 
       0xc3, 0x5, 0xc3, 0x7c3, 0xa, 0xc3, 0x3, 0xc4, 0x3, 0xc4, 0x3, 0xc4, 
       0x5, 0xc4, 0x7c8, 0xa, 0xc4, 0x3, 0xc4, 0x3, 0xc4, 0x3, 0xc4, 0x5, 
       0xc4, 0x7cd, 0xa, 0xc4, 0x5, 0xc4, 0x7cf, 0xa, 0xc4, 0x3, 0xc5, 0x3, 
       0xc5, 0x5, 0xc5, 0x7d3, 0xa, 0xc5, 0x3, 0xc6, 0x3, 0xc6, 0x3, 0xc6, 
       0x5, 0xc6, 0x7d8, 0xa, 0xc6, 0x3, 0xc6, 0x3, 0xc6, 0x3, 0xc6, 0x3, 
       0xc7, 0x3, 0xc7, 0x3, 0xc7, 0x3, 0xc7, 0x3, 0xc7, 0x3, 0xc7, 0x3, 
       0xc7, 0x3, 0xc7, 0x7, 0xc7, 0x7e5, 0xa, 0xc7, 0xc, 0xc7, 0xe, 0xc7, 
       0x7e8, 0xb, 0xc7, 0x3, 0xc7, 0x3, 0xc7, 0x3, 0xc7, 0x5, 0xc7, 0x7ed, 
       0xa, 0xc7, 0x3, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 0x5, 0xc8, 
       0x7f3, 0xa, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 0x3, 0xc9, 0x3, 
       0xc9, 0x3, 0xc9, 0x3, 0xc9, 0x3, 0xc9, 0x3, 0xc9, 0x3, 0xc9, 0x3, 
       0xc9, 0x7, 0xc9, 0x800, 0xa, 0xc9, 0xc, 0xc9, 0xe, 0xc9, 0x803, 0xb, 
       0xc9, 0x3, 0xc9, 0x3, 0xc9, 0x3, 0xc9, 0x5, 0xc9, 0x808, 0xa, 0xc9, 
       0x3, 0xca, 0x3, 0xca, 0x5, 0xca, 0x80c, 0xa, 0xca, 0x3, 0xcb, 0x3, 
       0xcb, 0x3, 0xcb, 0x3, 0xcb, 0x5, 0xcb, 0x812, 0xa, 0xcb, 0x3, 0xcb, 
       0x3, 0xcb, 0x3, 0xcb, 0x5, 0xcb, 0x817, 0xa, 0xcb, 0x3, 0xcb, 0x3, 
       0xcb, 0x3, 0xcb, 0x3, 0xcc, 0x3, 0xcc, 0x3, 0xcc, 0x3, 0xcc, 0x3, 
       0xcc, 0x3, 0xcc, 0x3, 0xcc, 0x3, 0xcc, 0x7, 0xcc, 0x824, 0xa, 0xcc, 
       0xc, 0xcc, 0xe, 0xcc, 0x827, 0xb, 0xcc, 0x3, 0xcd, 0x3, 0xcd, 0x3, 
       0xcd, 0x3, 0xcd, 0x5, 0xcd, 0x82d, 0xa, 0xcd, 0x3, 0xcd, 0x3, 0xcd, 
       0x3, 0xcd, 0x3, 0xcd, 0x5, 0xcd, 0x833, 0xa, 0xcd, 0x3, 0xcd, 0x3, 
       0xcd, 0x3, 0xcd, 0x3, 0xce, 0x3, 0xce, 0x3, 0xce, 0x3, 0xce, 0x3, 
       0xce, 0x3, 0xce, 0x3, 0xce, 0x3, 0xce, 0x7, 0xce, 0x840, 0xa, 0xce, 
       0xc, 0xce, 0xe, 0xce, 0x843, 0xb, 0xce, 0x3, 0xcf, 0x3, 0xcf, 0x3, 
       0xcf, 0x5, 0xcf, 0x848, 0xa, 0xcf, 0x3, 0xd0, 0x3, 0xd0, 0x3, 0xd0, 
       0x3, 0xd0, 0x3, 0xd0, 0x3, 0xd1, 0x3, 0xd1, 0x3, 0xd1, 0x3, 0xd1, 
       0x3, 0xd1, 0x3, 0xd2, 0x3, 0xd2, 0x3, 0xd2, 0x3, 0xd2, 0x5, 0xd2, 
       0x858, 0xa, 0xd2, 0x3, 0xd2, 0x3, 0xd2, 0x3, 0xd2, 0x3, 0xd2, 0x3, 
       0xd2, 0x3, 0xd3, 0x3, 0xd3, 0x3, 0xd3, 0x3, 0xd4, 0x3, 0xd4, 0x3, 
       0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 
       0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x7, 0xd5, 0x86d, 0xa, 0xd5, 0xc, 0xd5, 
       0xe, 0xd5, 0x870, 0xb, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 
       0xd5, 0x5, 0xd5, 0x876, 0xa, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 
       0x5, 0xd5, 0x87b, 0xa, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd6, 0x3, 
       0xd6, 0x5, 0xd6, 0x881, 0xa, 0xd6, 0x3, 0xd6, 0x3, 0xd6, 0x3, 0xd6, 
       0x6, 0xd6, 0x886, 0xa, 0xd6, 0xd, 0xd6, 0xe, 0xd6, 0x887, 0x3, 0xd6, 
       0x3, 0xd6, 0x3, 0xd6, 0x5, 0xd6, 0x88d, 0xa, 0xd6, 0x3, 0xd6, 0x5, 
       0xd6, 0x890, 0xa, 0xd6, 0x3, 0xd6, 0x3, 0xd6, 0x3, 0xd7, 0x3, 0xd7, 
       0x3, 0xd7, 0x3, 0xd7, 0x3, 0xd7, 0x3, 0xd8, 0x5, 0xd8, 0x89a, 0xa, 
       0xd8, 0x3, 0xd8, 0x3, 0xd8, 0x3, 0xd8, 0x3, 0xd8, 0x3, 0xd8, 0x5, 
       0xd8, 0x8a1, 0xa, 0xd8, 0x3, 0xd8, 0x3, 0xd8, 0x3, 0xd9, 0x3, 0xd9, 
       0x3, 0xd9, 0x3, 0xd9, 0x5, 0xd9, 0x8a9, 0xa, 0xd9, 0x3, 0xda, 0x3, 
       0xda, 0x3, 0xda, 0x3, 0xda, 0x3, 0xdb, 0x3, 0xdb, 0x5, 0xdb, 0x8b1, 
       0xa, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x5, 0xdb, 0x8b5, 0xa, 0xdb, 0x3, 
       0xdb, 0x3, 0xdb, 0x3, 0xdc, 0x3, 0xdc, 0x5, 0xdc, 0x8bb, 0xa, 0xdc, 
       0x3, 0xdc, 0x3, 0xdc, 0x5, 0xdc, 0x8bf, 0xa, 0xdc, 0x3, 0xdc, 0x3, 
       0xdc, 0x3, 0xdd, 0x3, 0xdd, 0x5, 0xdd, 0x8c5, 0xa, 0xdd, 0x3, 0xdd, 
       0x3, 0xdd, 0x3, 0xde, 0x3, 0xde, 0x3, 0xde, 0x3, 0xdf, 0x3, 0xdf, 
       0x3, 0xdf, 0x3, 0xdf, 0x5, 0xdf, 0x8d0, 0xa, 0xdf, 0x3, 0xe0, 0x3, 
       0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x5, 0xe0, 0x8d8, 
       0xa, 0xe0, 0x3, 0xe0, 0x5, 0xe0, 0x8db, 0xa, 0xe0, 0x3, 0xe1, 0x3, 
       0xe1, 0x3, 0xe1, 0x3, 0xe1, 0x3, 0xe1, 0x5, 0xe1, 0x8e2, 0xa, 0xe1, 
       0x3, 0xe1, 0x5, 0xe1, 0x8e5, 0xa, 0xe1, 0x3, 0xe1, 0x3, 0xe1, 0x7, 
       0xe1, 0x8e9, 0xa, 0xe1, 0xc, 0xe1, 0xe, 0xe1, 0x8ec, 0xb, 0xe1, 0x3, 
       0xe1, 0x3, 0xe1, 0x7, 0xe1, 0x8f0, 0xa, 0xe1, 0xc, 0xe1, 0xe, 0xe1, 
       0x8f3, 0xb, 0xe1, 0x3, 0xe1, 0x3, 0xe1, 0x3, 0xe1, 0x5, 0xe1, 0x8f8, 
       0xa, 0xe1, 0x3, 0xe1, 0x3, 0xe1, 0x3, 0xe2, 0x3, 0xe2, 0x3, 0xe2, 
       0x3, 0xe2, 0x5, 0xe2, 0x900, 0xa, 0xe2, 0x5, 0xe2, 0x902, 0xa, 0xe2, 
       0x3, 0xe2, 0x3, 0xe2, 0x3, 0xe2, 0x3, 0xe2, 0x5, 0xe2, 0x908, 0xa, 
       0xe2, 0x5, 0xe2, 0x90a, 0xa, 0xe2, 0x3, 0xe3, 0x5, 0xe3, 0x90d, 0xa, 
       0xe3, 0x3, 0xe3, 0x3, 0xe3, 0x3, 0xe3, 0x3, 0xe3, 0x3, 0xe3, 0x5, 
       0xe3, 0x914, 0xa, 0xe3, 0x3, 0xe3, 0x5, 0xe3, 0x917, 0xa, 0xe3, 0x3, 
       0xe3, 0x7, 0xe3, 0x91a, 0xa, 0xe3, 0xc, 0xe3, 0xe, 0xe3, 0x91d, 0xb, 
       0xe3, 0x3, 0xe3, 0x3, 0xe3, 0x7, 0xe3, 0x921, 0xa, 0xe3, 0xc, 0xe3, 
       0xe, 0xe3, 0x924, 0xb, 0xe3, 0x3, 0xe3, 0x3, 0xe3, 0x5, 0xe3, 0x928, 
       0xa, 0xe3, 0x3, 0xe3, 0x3, 0xe3, 0x5, 0xe3, 0x92c, 0xa, 0xe3, 0x3, 
       0xe3, 0x3, 0xe3, 0x3, 0xe4, 0x3, 0xe4, 0x5, 0xe4, 0x932, 0xa, 0xe4, 
       0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 
       0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 
       0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe5, 0x5, 0xe5, 0x943, 0xa, 0xe5, 0x3, 
       0xe6, 0x3, 0xe6, 0x3, 0xe6, 0x5, 0xe6, 0x948, 0xa, 0xe6, 0x3, 0xe7, 
       0x5, 0xe7, 0x94b, 0xa, 0xe7, 0x3, 0xe7, 0x3, 0xe7, 0x3, 0xe8, 0x5, 
       0xe8, 0x950, 0xa, 0xe8, 0x3, 0xe8, 0x3, 0xe8, 0x3, 0xe9, 0x5, 0xe9, 
       0x955, 0xa, 0xe9, 0x3, 0xe9, 0x3, 0xe9, 0x5, 0xe9, 0x959, 0xa, 0xe9, 
       0x3, 0xea, 0x3, 0xea, 0x3, 0xea, 0x5, 0xea, 0x95e, 0xa, 0xea, 0x3, 
       0xea, 0x5, 0xea, 0x961, 0xa, 0xea, 0x3, 0xea, 0x3, 0xea, 0x5, 0xea, 
       0x965, 0xa, 0xea, 0x3, 0xea, 0x3, 0xea, 0x3, 0xeb, 0x3, 0xeb, 0x3, 
       0xeb, 0x3, 0xeb, 0x5, 0xeb, 0x96d, 0xa, 0xeb, 0x3, 0xeb, 0x3, 0xeb, 
       0x3, 0xeb, 0x5, 0xeb, 0x972, 0xa, 0xeb, 0x3, 0xeb, 0x5, 0xeb, 0x975, 
       0xa, 0xeb, 0x3, 0xeb, 0x3, 0xeb, 0x3, 0xeb, 0x3, 0xec, 0x3, 0xec, 
       0x5, 0xec, 0x97c, 0xa, 0xec, 0x3, 0xec, 0x5, 0xec, 0x97f, 0xa, 0xec, 
       0x3, 0xec, 0x3, 0xec, 0x3, 0xed, 0x5, 0xed, 0x984, 0xa, 0xed, 0x3, 
       0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 
       0xed, 0x5, 0xed, 0x98d, 0xa, 0xed, 0x3, 0xed, 0x3, 0xed, 0x5, 0xed, 
       0x991, 0xa, 0xed, 0x3, 0xee, 0x3, 0xee, 0x3, 0xee, 0x5, 0xee, 0x996, 
       0xa, 0xee, 0x3, 0xef, 0x3, 0xef, 0x3, 0xef, 0x3, 0xef, 0x3, 0xef, 
       0x3, 0xef, 0x3, 0xef, 0x5, 0xef, 0x99f, 0xa, 0xef, 0x3, 0xef, 0x3, 
       0xef, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x5, 0xf0, 0x9a7, 
       0xa, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 
       0x3, 0xf0, 0x3, 0xf0, 0x5, 0xf0, 0x9b0, 0xa, 0xf0, 0x3, 0xf0, 0x3, 
       0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x7, 0xf0, 0x9b6, 0xa, 0xf0, 0xc, 0xf0, 
       0xe, 0xf0, 0x9b9, 0xb, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 
       0xf0, 0x5, 0xf0, 0x9bf, 0xa, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 
       0x5, 0xf0, 0x9c4, 0xa, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x5, 
       0xf0, 0x9c9, 0xa, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf1, 0x3, 0xf1, 
       0x3, 0xf1, 0x3, 0xf1, 0x6, 0xf1, 0x9d1, 0xa, 0xf1, 0xd, 0xf1, 0xe, 
       0xf1, 0x9d2, 0x3, 0xf1, 0x3, 0xf1, 0x3, 0xf1, 0x5, 0xf1, 0x9d8, 0xa, 
       0xf1, 0x3, 0xf1, 0x3, 0xf1, 0x3, 0xf2, 0x3, 0xf2, 0x3, 0xf2, 0x3, 
       0xf2, 0x5, 0xf2, 0x9e0, 0xa, 0xf2, 0x3, 0xf2, 0x3, 0xf2, 0x3, 0xf2, 
       0x3, 0xf2, 0x3, 0xf3, 0x7, 0xf3, 0x9e7, 0xa, 0xf3, 0xc, 0xf3, 0xe, 
       0xf3, 0x9ea, 0xb, 0xf3, 0x3, 0xf3, 0x3, 0xf3, 0x7, 0xf3, 0x9ee, 0xa, 
       0xf3, 0xc, 0xf3, 0xe, 0xf3, 0x9f1, 0xb, 0xf3, 0x3, 0xf3, 0x3, 0xf3, 
       0x5, 0xf3, 0x9f5, 0xa, 0xf3, 0x3, 0xf3, 0x3, 0xf3, 0x7, 0xf3, 0x9f9, 
       0xa, 0xf3, 0xc, 0xf3, 0xe, 0xf3, 0x9fc, 0xb, 0xf3, 0x5, 0xf3, 0x9fe, 
       0xa, 0xf3, 0x3, 0xf4, 0x7, 0xf4, 0xa01, 0xa, 0xf4, 0xc, 0xf4, 0xe, 
       0xf4, 0xa04, 0xb, 0xf4, 0x3, 0xf4, 0x3, 0xf4, 0x7, 0xf4, 0xa08, 0xa, 
       0xf4, 0xc, 0xf4, 0xe, 0xf4, 0xa0b, 0xb, 0xf4, 0x3, 0xf4, 0x7, 0xf4, 
       0xa0e, 0xa, 0xf4, 0xc, 0xf4, 0xe, 0xf4, 0xa11, 0xb, 0xf4, 0x5, 0xf4, 
       0xa13, 0xa, 0xf4, 0x3, 0xf5, 0x3, 0xf5, 0x3, 0xf6, 0x3, 0xf6, 0x3, 
       0xf6, 0x3, 0xf6, 0x7, 0xf6, 0xa1b, 0xa, 0xf6, 0xc, 0xf6, 0xe, 0xf6, 
       0xa1e, 0xb, 0xf6, 0x3, 0xf6, 0x3, 0xf6, 0x3, 0xf7, 0x7, 0xf7, 0xa23, 
       0xa, 0xf7, 0xc, 0xf7, 0xe, 0xf7, 0xa26, 0xb, 0xf7, 0x3, 0xf7, 0x3, 
       0xf7, 0x3, 0xf8, 0x3, 0xf8, 0x3, 0xf8, 0x3, 0xf9, 0x3, 0xf9, 0x5, 
       0xf9, 0xa2f, 0xa, 0xf9, 0x3, 0xfa, 0x3, 0xfa, 0x3, 0xfa, 0x3, 0xfa, 
       0x3, 0xfa, 0x5, 0xfa, 0xa36, 0xa, 0xfa, 0x3, 0xfb, 0x3, 0xfb, 0x5, 
       0xfb, 0xa3a, 0xa, 0xfb, 0x3, 0xfc, 0x3, 0xfc, 0x3, 0xfc, 0x3, 0xfc, 
       0x3, 0xfd, 0x3, 0xfd, 0x3, 0xfe, 0x3, 0xfe, 0x3, 0xfe, 0x3, 0xfe, 
       0x3, 0xfe, 0x3, 0xfe, 0x5, 0xfe, 0xa48, 0xa, 0xfe, 0x3, 0xfe, 0x5, 
       0xfe, 0xa4b, 0xa, 0xfe, 0x3, 0xfe, 0x3, 0xfe, 0x3, 0xff, 0x7, 0xff, 
       0xa50, 0xa, 0xff, 0xc, 0xff, 0xe, 0xff, 0xa53, 0xb, 0xff, 0x3, 0x100, 
       0x3, 0x100, 0x3, 0x100, 0x5, 0x100, 0xa58, 0xa, 0x100, 0x3, 0x101, 
       0x3, 0x101, 0x3, 0x101, 0x3, 0x101, 0x7, 0x101, 0xa5e, 0xa, 0x101, 
       0xc, 0x101, 0xe, 0x101, 0xa61, 0xb, 0x101, 0x3, 0x101, 0x3, 0x101, 
       0x3, 0x102, 0x3, 0x102, 0x3, 0x102, 0x2, 0x5, 0x6, 0x13a, 0x13c, 
       0x103, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
       0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
       0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 
       0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
       0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 
       0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
       0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 
       0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 
       0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 
       0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 
       0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 
       0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe, 0x100, 0x102, 0x104, 0x106, 0x108, 
       0x10a, 0x10c, 0x10e, 0x110, 0x112, 0x114, 0x116, 0x118, 0x11a, 0x11c, 
       0x11e, 0x120, 0x122, 0x124, 0x126, 0x128, 0x12a, 0x12c, 0x12e, 0x130, 
       0x132, 0x134, 0x136, 0x138, 0x13a, 0x13c, 0x13e, 0x140, 0x142, 0x144, 
       0x146, 0x148, 0x14a, 0x14c, 0x14e, 0x150, 0x152, 0x154, 0x156, 0x158, 
       0x15a, 0x15c, 0x15e, 0x160, 0x162, 0x164, 0x166, 0x168, 0x16a, 0x16c, 
       0x16e, 0x170, 0x172, 0x174, 0x176, 0x178, 0x17a, 0x17c, 0x17e, 0x180, 
       0x182, 0x184, 0x186, 0x188, 0x18a, 0x18c, 0x18e, 0x190, 0x192, 0x194, 
       0x196, 0x198, 0x19a, 0x19c, 0x19e, 0x1a0, 0x1a2, 0x1a4, 0x1a6, 0x1a8, 
       0x1aa, 0x1ac, 0x1ae, 0x1b0, 0x1b2, 0x1b4, 0x1b6, 0x1b8, 0x1ba, 0x1bc, 
       0x1be, 0x1c0, 0x1c2, 0x1c4, 0x1c6, 0x1c8, 0x1ca, 0x1cc, 0x1ce, 0x1d0, 
       0x1d2, 0x1d4, 0x1d6, 0x1d8, 0x1da, 0x1dc, 0x1de, 0x1e0, 0x1e2, 0x1e4, 
       0x1e6, 0x1e8, 0x1ea, 0x1ec, 0x1ee, 0x1f0, 0x1f2, 0x1f4, 0x1f6, 0x1f8, 
       0x1fa, 0x1fc, 0x1fe, 0x200, 0x202, 0x2, 0x14, 0x3, 0x2, 0x3, 0x6c, 
       0x4, 0x2, 0x14, 0x14, 0x53, 0x53, 0x4, 0x2, 0x24, 0x24, 0x36, 0x36, 
       0x4, 0x2, 0x2e, 0x2e, 0x40, 0x40, 0x4, 0x2, 0x2c, 0x2c, 0x68, 0x68, 
       0x4, 0x2, 0x46, 0x46, 0x5d, 0x5d, 0x7, 0x2, 0x6, 0x6, 0x32, 0x32, 
       0x46, 0x46, 0x4d, 0x4d, 0x5d, 0x5d, 0x13, 0x2, 0x7, 0x7, 0xf, 0xf, 
       0x11, 0x11, 0x13, 0x13, 0x1e, 0x1e, 0x24, 0x24, 0x28, 0x29, 0x2d, 
       0x2d, 0x31, 0x31, 0x36, 0x36, 0x41, 0x41, 0x54, 0x55, 0x59, 0x59, 
       0x60, 0x60, 0x62, 0x62, 0x65, 0x65, 0x67, 0x67, 0x5, 0x2, 0x1e, 0x1e, 
       0x28, 0x28, 0x31, 0x31, 0x8, 0x2, 0x12, 0x12, 0x2b, 0x2b, 0x39, 0x39, 
       0x45, 0x45, 0x4c, 0x4c, 0x4f, 0x4f, 0x4, 0x2, 0x8d, 0x97, 0xa0, 0xa0, 
       0x8, 0x2, 0x21, 0x21, 0x25, 0x25, 0x3c, 0x3c, 0x3e, 0x3e, 0x5b, 0x5b, 
       0x5e, 0x5e, 0x3, 0x2, 0x98, 0x9a, 0x3, 0x2, 0x98, 0x99, 0x5, 0x2, 
       0xc, 0xc, 0x1b, 0x1b, 0x9d, 0x9e, 0x5, 0x2, 0x8, 0x8, 0x64, 0x64, 
       0x9f, 0x9f, 0x4, 0x2, 0x6f, 0x6f, 0x71, 0x71, 0x3, 0x2, 0x6d, 0x6e, 
       0x2, 0xae5, 0x2, 0x204, 0x3, 0x2, 0x2, 0x2, 0x4, 0x209, 0x3, 0x2, 
       0x2, 0x2, 0x6, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x21d, 0x3, 0x2, 0x2, 
       0x2, 0xa, 0x222, 0x3, 0x2, 0x2, 0x2, 0xc, 0x227, 0x3, 0x2, 0x2, 0x2, 
       0xe, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x22e, 0x3, 0x2, 0x2, 0x2, 
       0x12, 0x232, 0x3, 0x2, 0x2, 0x2, 0x14, 0x23a, 0x3, 0x2, 0x2, 0x2, 
       0x16, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x18, 0x263, 0x3, 0x2, 0x2, 0x2, 
       0x1a, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x288, 0x3, 0x2, 0x2, 0x2, 
       0x1e, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x20, 0x2aa, 0x3, 0x2, 0x2, 0x2, 
       0x22, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x24, 0x2be, 0x3, 0x2, 0x2, 0x2, 
       0x26, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2cc, 0x3, 0x2, 0x2, 0x2, 
       0x2a, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2e4, 0x3, 0x2, 0x2, 0x2, 
       0x2e, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2eb, 0x3, 0x2, 0x2, 0x2, 
       0x32, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x34, 0x30d, 0x3, 0x2, 0x2, 0x2, 
       0x36, 0x316, 0x3, 0x2, 0x2, 0x2, 0x38, 0x318, 0x3, 0x2, 0x2, 0x2, 
       0x3a, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x31c, 0x3, 0x2, 0x2, 0x2, 
       0x3e, 0x334, 0x3, 0x2, 0x2, 0x2, 0x40, 0x336, 0x3, 0x2, 0x2, 0x2, 
       0x42, 0x343, 0x3, 0x2, 0x2, 0x2, 0x44, 0x354, 0x3, 0x2, 0x2, 0x2, 
       0x46, 0x372, 0x3, 0x2, 0x2, 0x2, 0x48, 0x374, 0x3, 0x2, 0x2, 0x2, 
       0x4a, 0x388, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x396, 0x3, 0x2, 0x2, 0x2, 
       0x4e, 0x398, 0x3, 0x2, 0x2, 0x2, 0x50, 0x39d, 0x3, 0x2, 0x2, 0x2, 
       0x52, 0x39f, 0x3, 0x2, 0x2, 0x2, 0x54, 0x3a1, 0x3, 0x2, 0x2, 0x2, 
       0x56, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x58, 0x3b0, 0x3, 0x2, 0x2, 0x2, 
       0x5a, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x3c0, 0x3, 0x2, 0x2, 0x2, 
       0x5e, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x60, 0x3c8, 0x3, 0x2, 0x2, 0x2, 
       0x62, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x64, 0x3d0, 0x3, 0x2, 0x2, 0x2, 
       0x66, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x68, 0x3e0, 0x3, 0x2, 0x2, 0x2, 
       0x6a, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x3f3, 0x3, 0x2, 0x2, 0x2, 
       0x6e, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x70, 0x3f7, 0x3, 0x2, 0x2, 0x2, 
       0x72, 0x404, 0x3, 0x2, 0x2, 0x2, 0x74, 0x406, 0x3, 0x2, 0x2, 0x2, 
       0x76, 0x411, 0x3, 0x2, 0x2, 0x2, 0x78, 0x416, 0x3, 0x2, 0x2, 0x2, 
       0x7a, 0x41e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x420, 0x3, 0x2, 0x2, 0x2, 
       0x7e, 0x42b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x42e, 0x3, 0x2, 0x2, 0x2, 
       0x82, 0x431, 0x3, 0x2, 0x2, 0x2, 0x84, 0x435, 0x3, 0x2, 0x2, 0x2, 
       0x86, 0x43b, 0x3, 0x2, 0x2, 0x2, 0x88, 0x43d, 0x3, 0x2, 0x2, 0x2, 
       0x8a, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x44f, 0x3, 0x2, 0x2, 0x2, 
       0x8e, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x90, 0x461, 0x3, 0x2, 0x2, 0x2, 
       0x92, 0x46c, 0x3, 0x2, 0x2, 0x2, 0x94, 0x46e, 0x3, 0x2, 0x2, 0x2, 
       0x96, 0x475, 0x3, 0x2, 0x2, 0x2, 0x98, 0x480, 0x3, 0x2, 0x2, 0x2, 
       0x9a, 0x484, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x486, 0x3, 0x2, 0x2, 0x2, 
       0x9e, 0x488, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x490, 0x3, 0x2, 0x2, 0x2, 
       0xa2, 0x493, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x497, 0x3, 0x2, 0x2, 0x2, 
       0xa6, 0x49b, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x4a1, 0x3, 0x2, 0x2, 0x2, 
       0xaa, 0x4a3, 0x3, 0x2, 0x2, 0x2, 0xac, 0x4ad, 0x3, 0x2, 0x2, 0x2, 
       0xae, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x4bd, 0x3, 0x2, 0x2, 0x2, 
       0xb2, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x4d4, 0x3, 0x2, 0x2, 0x2, 
       0xb6, 0x4dc, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x4e2, 0x3, 0x2, 0x2, 0x2, 
       0xba, 0x4e8, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x4ea, 0x3, 0x2, 0x2, 0x2, 
       0xbe, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x505, 0x3, 0x2, 0x2, 0x2, 
       0xc2, 0x510, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x515, 0x3, 0x2, 0x2, 0x2, 
       0xc6, 0x517, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x519, 0x3, 0x2, 0x2, 0x2, 
       0xca, 0x51c, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x523, 0x3, 0x2, 0x2, 0x2, 
       0xce, 0x525, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x531, 0x3, 0x2, 0x2, 0x2, 
       0xd2, 0x543, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x545, 0x3, 0x2, 0x2, 0x2, 
       0xd6, 0x557, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x559, 0x3, 0x2, 0x2, 0x2, 
       0xda, 0x561, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x563, 0x3, 0x2, 0x2, 0x2, 
       0xde, 0x569, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x56b, 0x3, 0x2, 0x2, 0x2, 
       0xe2, 0x571, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x573, 0x3, 0x2, 0x2, 0x2, 
       0xe6, 0x581, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x585, 0x3, 0x2, 0x2, 0x2, 
       0xea, 0x592, 0x3, 0x2, 0x2, 0x2, 0xec, 0x59a, 0x3, 0x2, 0x2, 0x2, 
       0xee, 0x59c, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x5a0, 0x3, 0x2, 0x2, 0x2, 
       0xf2, 0x5a4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x5b4, 0x3, 0x2, 0x2, 0x2, 
       0xf6, 0x5b6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x5bc, 0x3, 0x2, 0x2, 0x2, 
       0xfa, 0x5ce, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x5d6, 0x3, 0x2, 0x2, 0x2, 
       0xfe, 0x5de, 0x3, 0x2, 0x2, 0x2, 0x100, 0x5e2, 0x3, 0x2, 0x2, 0x2, 
       0x102, 0x5eb, 0x3, 0x2, 0x2, 0x2, 0x104, 0x5f3, 0x3, 0x2, 0x2, 0x2, 
       0x106, 0x5f5, 0x3, 0x2, 0x2, 0x2, 0x108, 0x5fd, 0x3, 0x2, 0x2, 0x2, 
       0x10a, 0x601, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x60d, 0x3, 0x2, 0x2, 0x2, 
       0x10e, 0x60f, 0x3, 0x2, 0x2, 0x2, 0x110, 0x616, 0x3, 0x2, 0x2, 0x2, 
       0x112, 0x61a, 0x3, 0x2, 0x2, 0x2, 0x114, 0x61c, 0x3, 0x2, 0x2, 0x2, 
       0x116, 0x625, 0x3, 0x2, 0x2, 0x2, 0x118, 0x634, 0x3, 0x2, 0x2, 0x2, 
       0x11a, 0x642, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x646, 0x3, 0x2, 0x2, 0x2, 
       0x11e, 0x659, 0x3, 0x2, 0x2, 0x2, 0x120, 0x65b, 0x3, 0x2, 0x2, 0x2, 
       0x122, 0x65f, 0x3, 0x2, 0x2, 0x2, 0x124, 0x667, 0x3, 0x2, 0x2, 0x2, 
       0x126, 0x66d, 0x3, 0x2, 0x2, 0x2, 0x128, 0x67b, 0x3, 0x2, 0x2, 0x2, 
       0x12a, 0x67f, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x681, 0x3, 0x2, 0x2, 0x2, 
       0x12e, 0x68b, 0x3, 0x2, 0x2, 0x2, 0x130, 0x68d, 0x3, 0x2, 0x2, 0x2, 
       0x132, 0x69a, 0x3, 0x2, 0x2, 0x2, 0x134, 0x6a1, 0x3, 0x2, 0x2, 0x2, 
       0x136, 0x6ab, 0x3, 0x2, 0x2, 0x2, 0x138, 0x6b0, 0x3, 0x2, 0x2, 0x2, 
       0x13a, 0x6bb, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x6dd, 0x3, 0x2, 0x2, 0x2, 
       0x13e, 0x6f2, 0x3, 0x2, 0x2, 0x2, 0x140, 0x6f4, 0x3, 0x2, 0x2, 0x2, 
       0x142, 0x6f6, 0x3, 0x2, 0x2, 0x2, 0x144, 0x6f8, 0x3, 0x2, 0x2, 0x2, 
       0x146, 0x6fa, 0x3, 0x2, 0x2, 0x2, 0x148, 0x6fc, 0x3, 0x2, 0x2, 0x2, 
       0x14a, 0x6fe, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x700, 0x3, 0x2, 0x2, 0x2, 
       0x14e, 0x70b, 0x3, 0x2, 0x2, 0x2, 0x150, 0x70e, 0x3, 0x2, 0x2, 0x2, 
       0x152, 0x712, 0x3, 0x2, 0x2, 0x2, 0x154, 0x720, 0x3, 0x2, 0x2, 0x2, 
       0x156, 0x724, 0x3, 0x2, 0x2, 0x2, 0x158, 0x72f, 0x3, 0x2, 0x2, 0x2, 
       0x15a, 0x731, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x735, 0x3, 0x2, 0x2, 0x2, 
       0x15e, 0x73d, 0x3, 0x2, 0x2, 0x2, 0x160, 0x743, 0x3, 0x2, 0x2, 0x2, 
       0x162, 0x754, 0x3, 0x2, 0x2, 0x2, 0x164, 0x760, 0x3, 0x2, 0x2, 0x2, 
       0x166, 0x763, 0x3, 0x2, 0x2, 0x2, 0x168, 0x76b, 0x3, 0x2, 0x2, 0x2, 
       0x16a, 0x76e, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x770, 0x3, 0x2, 0x2, 0x2, 
       0x16e, 0x773, 0x3, 0x2, 0x2, 0x2, 0x170, 0x776, 0x3, 0x2, 0x2, 0x2, 
       0x172, 0x780, 0x3, 0x2, 0x2, 0x2, 0x174, 0x78b, 0x3, 0x2, 0x2, 0x2, 
       0x176, 0x790, 0x3, 0x2, 0x2, 0x2, 0x178, 0x792, 0x3, 0x2, 0x2, 0x2, 
       0x17a, 0x79a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x7a3, 0x3, 0x2, 0x2, 0x2, 
       0x17e, 0x7ab, 0x3, 0x2, 0x2, 0x2, 0x180, 0x7b3, 0x3, 0x2, 0x2, 0x2, 
       0x182, 0x7b7, 0x3, 0x2, 0x2, 0x2, 0x184, 0x7c2, 0x3, 0x2, 0x2, 0x2, 
       0x186, 0x7ce, 0x3, 0x2, 0x2, 0x2, 0x188, 0x7d2, 0x3, 0x2, 0x2, 0x2, 
       0x18a, 0x7d4, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x7dc, 0x3, 0x2, 0x2, 0x2, 
       0x18e, 0x7ee, 0x3, 0x2, 0x2, 0x2, 0x190, 0x7f7, 0x3, 0x2, 0x2, 0x2, 
       0x192, 0x80b, 0x3, 0x2, 0x2, 0x2, 0x194, 0x80d, 0x3, 0x2, 0x2, 0x2, 
       0x196, 0x81b, 0x3, 0x2, 0x2, 0x2, 0x198, 0x828, 0x3, 0x2, 0x2, 0x2, 
       0x19a, 0x837, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x847, 0x3, 0x2, 0x2, 0x2, 
       0x19e, 0x849, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x84e, 0x3, 0x2, 0x2, 0x2, 
       0x1a2, 0x853, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x85e, 0x3, 0x2, 0x2, 0x2, 
       0x1a6, 0x861, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x863, 0x3, 0x2, 0x2, 0x2, 
       0x1aa, 0x87e, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x893, 0x3, 0x2, 0x2, 0x2, 
       0x1ae, 0x899, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x8a8, 0x3, 0x2, 0x2, 0x2, 
       0x1b2, 0x8aa, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x8ae, 0x3, 0x2, 0x2, 0x2, 
       0x1b6, 0x8b8, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x8c2, 0x3, 0x2, 0x2, 0x2, 
       0x1ba, 0x8c8, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x8cf, 0x3, 0x2, 0x2, 0x2, 
       0x1be, 0x8da, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x8dc, 0x3, 0x2, 0x2, 0x2, 
       0x1c2, 0x901, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x90c, 0x3, 0x2, 0x2, 0x2, 
       0x1c6, 0x931, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x942, 0x3, 0x2, 0x2, 0x2, 
       0x1ca, 0x947, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x94a, 0x3, 0x2, 0x2, 0x2, 
       0x1ce, 0x94f, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x954, 0x3, 0x2, 0x2, 0x2, 
       0x1d2, 0x95a, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x968, 0x3, 0x2, 0x2, 0x2, 
       0x1d6, 0x979, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x990, 0x3, 0x2, 0x2, 0x2, 
       0x1da, 0x995, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x997, 0x3, 0x2, 0x2, 0x2, 
       0x1de, 0x9a2, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x9cc, 0x3, 0x2, 0x2, 0x2, 
       0x1e2, 0x9db, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x9fd, 0x3, 0x2, 0x2, 0x2, 
       0x1e6, 0xa12, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0xa14, 0x3, 0x2, 0x2, 0x2, 
       0x1ea, 0xa16, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0xa24, 0x3, 0x2, 0x2, 0x2, 
       0x1ee, 0xa29, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0xa2e, 0x3, 0x2, 0x2, 0x2, 
       0x1f2, 0xa35, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0xa39, 0x3, 0x2, 0x2, 0x2, 
       0x1f6, 0xa3b, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0xa3f, 0x3, 0x2, 0x2, 0x2, 
       0x1fa, 0xa41, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0xa51, 0x3, 0x2, 0x2, 0x2, 
       0x1fe, 0xa57, 0x3, 0x2, 0x2, 0x2, 0x200, 0xa59, 0x3, 0x2, 0x2, 0x2, 
       0x202, 0xa64, 0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 0x9, 0x2, 0x2, 0x2, 
       0x205, 0x3, 0x3, 0x2, 0x2, 0x2, 0x206, 0x20a, 0x5, 0x202, 0x102, 
       0x2, 0x207, 0x20a, 0x5, 0x38, 0x1d, 0x2, 0x208, 0x20a, 0x7, 0x72, 
       0x2, 0x2, 0x209, 0x206, 0x3, 0x2, 0x2, 0x2, 0x209, 0x207, 0x3, 0x2, 
       0x2, 0x2, 0x209, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x5, 0x3, 0x2, 
       0x2, 0x2, 0x20b, 0x20c, 0x8, 0x4, 0x1, 0x2, 0x20c, 0x20f, 0x5, 0x4, 
       0x3, 0x2, 0x20d, 0x20f, 0x5, 0x12c, 0x97, 0x2, 0x20e, 0x20b, 0x3, 
       0x2, 0x2, 0x2, 0x20e, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x21a, 0x3, 
       0x2, 0x2, 0x2, 0x210, 0x216, 0xc, 0x4, 0x2, 0x2, 0x211, 0x217, 0x5, 
       0x8, 0x5, 0x2, 0x212, 0x217, 0x5, 0xa, 0x6, 0x2, 0x213, 0x217, 0x5, 
       0xe4, 0x73, 0x2, 0x214, 0x215, 0x7, 0x8a, 0x2, 0x2, 0x215, 0x217, 
       0x5, 0xe, 0x8, 0x2, 0x216, 0x211, 0x3, 0x2, 0x2, 0x2, 0x216, 0x212, 
       0x3, 0x2, 0x2, 0x2, 0x216, 0x213, 0x3, 0x2, 0x2, 0x2, 0x216, 0x214, 
       0x3, 0x2, 0x2, 0x2, 0x217, 0x219, 0x3, 0x2, 0x2, 0x2, 0x218, 0x210, 
       0x3, 0x2, 0x2, 0x2, 0x219, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x218, 
       0x3, 0x2, 0x2, 0x2, 0x21a, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x7, 
       0x3, 0x2, 0x2, 0x2, 0x21c, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21e, 
       0x7, 0x80, 0x2, 0x2, 0x21e, 0x21f, 0x5, 0x10, 0x9, 0x2, 0x21f, 0x220, 
       0x7, 0x81, 0x2, 0x2, 0x220, 0x9, 0x3, 0x2, 0x2, 0x2, 0x221, 0x223, 
       0x5, 0x42, 0x22, 0x2, 0x222, 0x221, 0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 
       0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 
       0x7, 0x84, 0x2, 0x2, 0x225, 0x226, 0x5, 0x12a, 0x96, 0x2, 0x226, 
       0xb, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x5, 0x6, 0x4, 0x2, 0x228, 
       0x229, 0x5, 0xa, 0x6, 0x2, 0x229, 0xd, 0x3, 0x2, 0x2, 0x2, 0x22a, 
       0x22d, 0x5, 0x4, 0x3, 0x2, 0x22b, 0x22d, 0x7, 0x42, 0x2, 0x2, 0x22c, 
       0x22a, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22d, 
       0xf, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x5, 0x13c, 0x9f, 0x2, 0x22f, 
       0x230, 0x5, 0x52, 0x2a, 0x2, 0x230, 0x231, 0x5, 0x13c, 0x9f, 0x2, 
       0x231, 0x11, 0x3, 0x2, 0x2, 0x2, 0x232, 0x237, 0x5, 0x202, 0x102, 
       0x2, 0x233, 0x234, 0x7, 0x8a, 0x2, 0x2, 0x234, 0x236, 0x5, 0xe, 0x8, 
       0x2, 0x235, 0x233, 0x3, 0x2, 0x2, 0x2, 0x236, 0x239, 0x3, 0x2, 0x2, 
       0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 0x2, 
       0x2, 0x238, 0x13, 0x3, 0x2, 0x2, 0x2, 0x239, 0x237, 0x3, 0x2, 0x2, 
       0x2, 0x23a, 0x23b, 0x7, 0xf, 0x2, 0x2, 0x23b, 0x23c, 0x5, 0x202, 
       0x102, 0x2, 0x23c, 0x23e, 0x7, 0x5f, 0x2, 0x2, 0x23d, 0x23f, 0x5, 
       0xdc, 0x6f, 0x2, 0x23e, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 
       0x3, 0x2, 0x2, 0x2, 0x23f, 0x241, 0x3, 0x2, 0x2, 0x2, 0x240, 0x242, 
       0x5, 0xe0, 0x71, 0x2, 0x241, 0x240, 0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 
       0x3, 0x2, 0x2, 0x2, 0x242, 0x246, 0x3, 0x2, 0x2, 0x2, 0x243, 0x245, 
       0x5, 0x16, 0xc, 0x2, 0x244, 0x243, 0x3, 0x2, 0x2, 0x2, 0x245, 0x248, 
       0x3, 0x2, 0x2, 0x2, 0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 
       0x3, 0x2, 0x2, 0x2, 0x247, 0x250, 0x3, 0x2, 0x2, 0x2, 0x248, 0x246, 
       0x3, 0x2, 0x2, 0x2, 0x249, 0x24d, 0x7, 0x20, 0x2, 0x2, 0x24a, 0x24c, 
       0x5, 0x18, 0xd, 0x2, 0x24b, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24f, 
       0x3, 0x2, 0x2, 0x2, 0x24d, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 
       0x3, 0x2, 0x2, 0x2, 0x24e, 0x251, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x24d, 
       0x3, 0x2, 0x2, 0x2, 0x250, 0x249, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 
       0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 0x3, 0x2, 0x2, 0x2, 0x252, 0x254, 
       0x7, 0x37, 0x2, 0x2, 0x253, 0x255, 0x7, 0xf, 0x2, 0x2, 0x254, 0x253, 
       0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x3, 0x2, 0x2, 0x2, 0x255, 0x257, 
       0x3, 0x2, 0x2, 0x2, 0x256, 0x258, 0x5, 0x202, 0x102, 0x2, 0x257, 
       0x256, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 0x3, 0x2, 0x2, 0x2, 0x258, 
       0x259, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0x7, 0x7f, 0x2, 0x2, 0x25a, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25f, 0x5, 0xac, 0x57, 0x2, 0x25c, 
       0x25f, 0x5, 0x1ca, 0xe6, 0x2, 0x25d, 0x25f, 0x5, 0x124, 0x93, 0x2, 
       0x25e, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25c, 0x3, 0x2, 0x2, 0x2, 
       0x25e, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x17, 0x3, 0x2, 0x2, 0x2, 
       0x260, 0x261, 0x5, 0x1e8, 0xf5, 0x2, 0x261, 0x262, 0x7, 0x8c, 0x2, 
       0x2, 0x262, 0x264, 0x3, 0x2, 0x2, 0x2, 0x263, 0x260, 0x3, 0x2, 0x2, 
       0x2, 0x263, 0x264, 0x3, 0x2, 0x2, 0x2, 0x264, 0x268, 0x3, 0x2, 0x2, 
       0x2, 0x265, 0x269, 0x5, 0x1ce, 0xe8, 0x2, 0x266, 0x269, 0x5, 0x1cc, 
       0xe7, 0x2, 0x267, 0x269, 0x5, 0x1c4, 0xe3, 0x2, 0x268, 0x265, 0x3, 
       0x2, 0x2, 0x2, 0x268, 0x266, 0x3, 0x2, 0x2, 0x2, 0x268, 0x267, 0x3, 
       0x2, 0x2, 0x2, 0x269, 0x19, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26b, 0x7, 
       0x67, 0x2, 0x2, 0x26b, 0x26c, 0x5, 0x202, 0x102, 0x2, 0x26c, 0x26d, 
       0x7, 0x23, 0x2, 0x2, 0x26d, 0x26e, 0x5, 0x6, 0x4, 0x2, 0x26e, 0x272, 
       0x7, 0x5f, 0x2, 0x2, 0x26f, 0x271, 0x5, 0x1c, 0xf, 0x2, 0x270, 0x26f, 
       0x3, 0x2, 0x2, 0x2, 0x271, 0x274, 0x3, 0x2, 0x2, 0x2, 0x272, 0x270, 
       0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 0x2, 0x2, 0x2, 0x273, 0x275, 
       0x3, 0x2, 0x2, 0x2, 0x274, 0x272, 0x3, 0x2, 0x2, 0x2, 0x275, 0x279, 
       0x7, 0x20, 0x2, 0x2, 0x276, 0x278, 0x5, 0x1be, 0xe0, 0x2, 0x277, 
       0x276, 0x3, 0x2, 0x2, 0x2, 0x278, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x279, 
       0x277, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27a, 
       0x27c, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27c, 
       0x27e, 0x7, 0x37, 0x2, 0x2, 0x27d, 0x27f, 0x7, 0x67, 0x2, 0x2, 0x27e, 
       0x27d, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x27f, 
       0x281, 0x3, 0x2, 0x2, 0x2, 0x280, 0x282, 0x5, 0x202, 0x102, 0x2, 
       0x281, 0x280, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 0x2, 0x2, 0x2, 
       0x282, 0x283, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 0x7, 0x7f, 0x2, 0x2, 
       0x284, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x285, 0x289, 0x5, 0x16, 0xc, 0x2, 
       0x286, 0x289, 0x5, 0xf8, 0x7d, 0x2, 0x287, 0x289, 0x5, 0x112, 0x8a, 
       0x2, 0x288, 0x285, 0x3, 0x2, 0x2, 0x2, 0x288, 0x286, 0x3, 0x2, 0x2, 
       0x2, 0x288, 0x287, 0x3, 0x2, 0x2, 0x2, 0x289, 0x1d, 0x3, 0x2, 0x2, 
       0x2, 0x28a, 0x28b, 0x7, 0x65, 0x2, 0x2, 0x28b, 0x28c, 0x5, 0x202, 
       0x102, 0x2, 0x28c, 0x28d, 0x7, 0x23, 0x2, 0x2, 0x28d, 0x28e, 0x5, 
       0x6, 0x4, 0x2, 0x28e, 0x292, 0x7, 0x5f, 0x2, 0x2, 0x28f, 0x291, 0x5, 
       0x20, 0x11, 0x2, 0x290, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x291, 0x294, 
       0x3, 0x2, 0x2, 0x2, 0x292, 0x290, 0x3, 0x2, 0x2, 0x2, 0x292, 0x293, 
       0x3, 0x2, 0x2, 0x2, 0x293, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x294, 0x292, 
       0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 0x5, 0x120, 0x91, 0x2, 0x296, 0x297, 
       0x7, 0x7f, 0x2, 0x2, 0x297, 0x299, 0x3, 0x2, 0x2, 0x2, 0x298, 0x295, 
       0x3, 0x2, 0x2, 0x2, 0x299, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x298, 
       0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x29d, 
       0x3, 0x2, 0x2, 0x2, 0x29c, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 
       0x5, 0x22, 0x12, 0x2, 0x29e, 0x2a0, 0x7, 0x37, 0x2, 0x2, 0x29f, 0x2a1, 
       0x7, 0x65, 0x2, 0x2, 0x2a0, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a1, 
       0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a4, 
       0x5, 0x202, 0x102, 0x2, 0x2a3, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a3, 
       0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a5, 
       0x2a6, 0x7, 0x7f, 0x2, 0x2, 0x2a6, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
       0x2ab, 0x5, 0x1ea, 0xf6, 0x2, 0x2a8, 0x2ab, 0x5, 0x106, 0x84, 0x2, 
       0x2a9, 0x2ab, 0x5, 0x100, 0x81, 0x2, 0x2aa, 0x2a7, 0x3, 0x2, 0x2, 
       0x2, 0x2aa, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a9, 0x3, 0x2, 0x2, 
       0x2, 0x2ab, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x7, 0x5a, 0x2, 
       0x2, 0x2ad, 0x2b1, 0x5, 0x24, 0x13, 0x2, 0x2ae, 0x2b0, 0x5, 0x1ea, 
       0xf6, 0x2, 0x2af, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b3, 0x3, 0x2, 
       0x2, 0x2, 0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x3, 0x2, 
       0x2, 0x2, 0x2b2, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b1, 0x3, 0x2, 
       0x2, 0x2, 0x2b4, 0x2b6, 0x5, 0x28, 0x15, 0x2, 0x2b5, 0x2b4, 0x3, 
       0x2, 0x2, 0x2, 0x2b6, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b5, 0x3, 
       0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2ba, 0x3, 
       0x2, 0x2, 0x2, 0x2b9, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0x7, 
       0x37, 0x2, 0x2, 0x2bb, 0x2bc, 0x7, 0x5a, 0x2, 0x2, 0x2bc, 0x2bd, 
       0x7, 0x7f, 0x2, 0x2, 0x2bd, 0x23, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2c3, 
       0x5, 0x1e8, 0xf5, 0x2, 0x2bf, 0x2c0, 0x7, 0x80, 0x2, 0x2, 0x2c0, 
       0x2c1, 0x5, 0x26, 0x14, 0x2, 0x2c1, 0x2c2, 0x7, 0x81, 0x2, 0x2, 0x2c2, 
       0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2c3, 
       0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2c5, 
       0x2c9, 0x5, 0x72, 0x3a, 0x2, 0x2c6, 0x2c9, 0x5, 0x13a, 0x9e, 0x2, 
       0x2c7, 0x2c9, 0x5, 0x1e8, 0xf5, 0x2, 0x2c8, 0x2c5, 0x3, 0x2, 0x2, 
       0x2, 0x2c8, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c7, 0x3, 0x2, 0x2, 
       0x2, 0x2c9, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cd, 0x5, 0x22, 0x12, 
       0x2, 0x2cb, 0x2cd, 0x5, 0x2a, 0x16, 0x2, 0x2cc, 0x2ca, 0x3, 0x2, 
       0x2, 0x2, 0x2cc, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x29, 0x3, 0x2, 
       0x2, 0x2, 0x2ce, 0x2cf, 0x7, 0x5a, 0x2, 0x2, 0x2cf, 0x2d3, 0x5, 0x118, 
       0x8d, 0x2, 0x2d0, 0x2d1, 0x5, 0x11c, 0x8f, 0x2, 0x2d1, 0x2d2, 0x7, 
       0x7f, 0x2, 0x2, 0x2d2, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d0, 0x3, 
       0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2da, 0x3, 
       0x2, 0x2, 0x2, 0x2d5, 0x2d6, 0x5, 0x120, 0x91, 0x2, 0x2d6, 0x2d7, 
       0x7, 0x7f, 0x2, 0x2, 0x2d7, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d5, 
       0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2d8, 
       0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2de, 
       0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2df, 
       0x5, 0x22, 0x12, 0x2, 0x2de, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 
       0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e1, 
       0x7, 0x37, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x5a, 0x2, 0x2, 0x2e2, 0x2e3, 
       0x7, 0x7f, 0x2, 0x2, 0x2e3, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 
       0x5, 0x2e, 0x18, 0x2, 0x2e5, 0x2e6, 0x7, 0x7f, 0x2, 0x2, 0x2e6, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2ea, 0x5, 0x30, 0x19, 0x2, 0x2e8, 0x2ea, 
       0x5, 0x32, 0x1a, 0x2, 0x2e9, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2e8, 
       0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ec, 
       0x7, 0x24, 0x2, 0x2, 0x2ec, 0x2ee, 0x5, 0x36, 0x1c, 0x2, 0x2ed, 0x2ef, 
       0x5, 0x34, 0x1b, 0x2, 0x2ee, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 
       0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f2, 
       0x7, 0x57, 0x2, 0x2, 0x2f1, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 
       0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 
       0x7, 0x80, 0x2, 0x2, 0x2f4, 0x2f5, 0x5, 0x3a, 0x1e, 0x2, 0x2f5, 0x2f6, 
       0x7, 0x81, 0x2, 0x2, 0x2f6, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f1, 
       0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fb, 0x9, 0x3, 0x2, 0x2, 0x2fa, 0x2f9, 
       0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fc, 
       0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x7, 0x36, 0x2, 0x2, 0x2fd, 0x2ff, 
       0x5, 0x36, 0x1c, 0x2, 0x2fe, 0x300, 0x5, 0x34, 0x1b, 0x2, 0x2ff, 
       0x2fe, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 0x3, 0x2, 0x2, 0x2, 0x300, 
       0x308, 0x3, 0x2, 0x2, 0x2, 0x301, 0x303, 0x7, 0x57, 0x2, 0x2, 0x302, 
       0x301, 0x3, 0x2, 0x2, 0x2, 0x302, 0x303, 0x3, 0x2, 0x2, 0x2, 0x303, 
       0x304, 0x3, 0x2, 0x2, 0x2, 0x304, 0x305, 0x7, 0x80, 0x2, 0x2, 0x305, 
       0x306, 0x5, 0x3a, 0x1e, 0x2, 0x306, 0x307, 0x7, 0x81, 0x2, 0x2, 0x307, 
       0x309, 0x3, 0x2, 0x2, 0x2, 0x308, 0x302, 0x3, 0x2, 0x2, 0x2, 0x308, 
       0x309, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30a, 
       0x30b, 0x7, 0x49, 0x2, 0x2, 0x30b, 0x30c, 0x5, 0xa2, 0x52, 0x2, 0x30c, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x30e, 0x7, 0x16, 0x2, 0x2, 0x30e, 
       0x30f, 0x7, 0x80, 0x2, 0x2, 0x30f, 0x310, 0x5, 0xde, 0x70, 0x2, 0x310, 
       0x312, 0x7, 0x81, 0x2, 0x2, 0x311, 0x313, 0x5, 0xee, 0x78, 0x2, 0x312, 
       0x311, 0x3, 0x2, 0x2, 0x2, 0x312, 0x313, 0x3, 0x2, 0x2, 0x2, 0x313, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x314, 0x317, 0x5, 0x202, 0x102, 0x2, 0x315, 
       0x317, 0x5, 0x38, 0x1d, 0x2, 0x316, 0x314, 0x3, 0x2, 0x2, 0x2, 0x316, 
       0x315, 0x3, 0x2, 0x2, 0x2, 0x317, 0x37, 0x3, 0x2, 0x2, 0x2, 0x318, 
       0x319, 0x7, 0x73, 0x2, 0x2, 0x319, 0x39, 0x3, 0x2, 0x2, 0x2, 0x31a, 
       0x31b, 0x5, 0xd8, 0x6d, 0x2, 0x31b, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x31c, 
       0x31d, 0x5, 0x2e, 0x18, 0x2, 0x31d, 0x321, 0x7, 0x5f, 0x2, 0x2, 0x31e, 
       0x320, 0x5, 0x1ca, 0xe6, 0x2, 0x31f, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x320, 
       0x323, 0x3, 0x2, 0x2, 0x2, 0x321, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x321, 
       0x322, 0x3, 0x2, 0x2, 0x2, 0x322, 0x324, 0x3, 0x2, 0x2, 0x2, 0x323, 
       0x321, 0x3, 0x2, 0x2, 0x2, 0x324, 0x328, 0x7, 0x20, 0x2, 0x2, 0x325, 
       0x327, 0x5, 0x160, 0xb1, 0x2, 0x326, 0x325, 0x3, 0x2, 0x2, 0x2, 0x327, 
       0x32a, 0x3, 0x2, 0x2, 0x2, 0x328, 0x326, 0x3, 0x2, 0x2, 0x2, 0x328, 
       0x329, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32a, 
       0x328, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32d, 0x7, 0x37, 0x2, 0x2, 0x32c, 
       0x32e, 0x5, 0x3e, 0x20, 0x2, 0x32d, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x32d, 
       0x32e, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x330, 0x3, 0x2, 0x2, 0x2, 0x32f, 
       0x331, 0x5, 0x36, 0x1c, 0x2, 0x330, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x330, 
       0x331, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 0x2, 0x2, 0x332, 
       0x333, 0x7, 0x7f, 0x2, 0x2, 0x333, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x334, 
       0x335, 0x9, 0x4, 0x2, 0x2, 0x335, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x336, 
       0x337, 0x5, 0x3e, 0x20, 0x2, 0x337, 0x338, 0x5, 0x36, 0x1c, 0x2, 
       0x338, 0x339, 0x7, 0x5f, 0x2, 0x2, 0x339, 0x33a, 0x7, 0x2f, 0x2, 
       0x2, 0x33a, 0x33c, 0x5, 0x6, 0x4, 0x2, 0x33b, 0x33d, 0x5, 0x42, 0x22, 
       0x2, 0x33c, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 0x3, 0x2, 0x2, 
       0x2, 0x33d, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x340, 0x5, 0xee, 0x78, 
       0x2, 0x33f, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 0x3, 0x2, 0x2, 
       0x2, 0x340, 0x341, 0x3, 0x2, 0x2, 0x2, 0x341, 0x342, 0x7, 0x7f, 0x2, 
       0x2, 0x342, 0x41, 0x3, 0x2, 0x2, 0x2, 0x343, 0x34c, 0x7, 0x82, 0x2, 
       0x2, 0x344, 0x349, 0x5, 0xa2, 0x52, 0x2, 0x345, 0x346, 0x7, 0x89, 
       0x2, 0x2, 0x346, 0x348, 0x5, 0xa2, 0x52, 0x2, 0x347, 0x345, 0x3, 
       0x2, 0x2, 0x2, 0x348, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x349, 0x347, 0x3, 
       0x2, 0x2, 0x2, 0x349, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34d, 0x3, 
       0x2, 0x2, 0x2, 0x34b, 0x349, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x344, 0x3, 
       0x2, 0x2, 0x2, 0x34c, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x350, 0x3, 
       0x2, 0x2, 0x2, 0x34e, 0x34f, 0x7, 0x49, 0x2, 0x2, 0x34f, 0x351, 0x5, 
       0xa2, 0x52, 0x2, 0x350, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x350, 0x351, 
       0x3, 0x2, 0x2, 0x2, 0x351, 0x352, 0x3, 0x2, 0x2, 0x2, 0x352, 0x353, 
       0x7, 0x83, 0x2, 0x2, 0x353, 0x43, 0x3, 0x2, 0x2, 0x2, 0x354, 0x355, 
       0x7, 0x54, 0x2, 0x2, 0x355, 0x356, 0x5, 0x202, 0x102, 0x2, 0x356, 
       0x35d, 0x7, 0x5f, 0x2, 0x2, 0x357, 0x35b, 0x5, 0xdc, 0x6f, 0x2, 0x358, 
       0x359, 0x5, 0xee, 0x78, 0x2, 0x359, 0x35a, 0x7, 0x7f, 0x2, 0x2, 0x35a, 
       0x35c, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x358, 0x3, 0x2, 0x2, 0x2, 0x35b, 
       0x35c, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35d, 
       0x357, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35e, 
       0x362, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x361, 0x5, 0x46, 0x24, 0x2, 0x360, 
       0x35f, 0x3, 0x2, 0x2, 0x2, 0x361, 0x364, 0x3, 0x2, 0x2, 0x2, 0x362, 
       0x360, 0x3, 0x2, 0x2, 0x2, 0x362, 0x363, 0x3, 0x2, 0x2, 0x2, 0x363, 
       0x365, 0x3, 0x2, 0x2, 0x2, 0x364, 0x362, 0x3, 0x2, 0x2, 0x2, 0x365, 
       0x367, 0x7, 0x37, 0x2, 0x2, 0x366, 0x368, 0x7, 0x54, 0x2, 0x2, 0x367, 
       0x366, 0x3, 0x2, 0x2, 0x2, 0x367, 0x368, 0x3, 0x2, 0x2, 0x2, 0x368, 
       0x36a, 0x3, 0x2, 0x2, 0x2, 0x369, 0x36b, 0x5, 0x202, 0x102, 0x2, 
       0x36a, 0x369, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x36b, 0x3, 0x2, 0x2, 0x2, 
       0x36b, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36d, 0x7, 0x7f, 0x2, 0x2, 
       0x36d, 0x45, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x373, 0x5, 0x1c8, 0xe5, 
       0x2, 0x36f, 0x373, 0x5, 0xac, 0x57, 0x2, 0x370, 0x373, 0x5, 0xf8, 
       0x7d, 0x2, 0x371, 0x373, 0x5, 0x124, 0x93, 0x2, 0x372, 0x36e, 0x3, 
       0x2, 0x2, 0x2, 0x372, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x372, 0x370, 0x3, 
       0x2, 0x2, 0x2, 0x372, 0x371, 0x3, 0x2, 0x2, 0x2, 0x373, 0x47, 0x3, 
       0x2, 0x2, 0x2, 0x374, 0x375, 0x7, 0x54, 0x2, 0x2, 0x375, 0x376, 0x7, 
       0x33, 0x2, 0x2, 0x376, 0x377, 0x5, 0x202, 0x102, 0x2, 0x377, 0x37b, 
       0x7, 0x5f, 0x2, 0x2, 0x378, 0x37a, 0x5, 0x1ca, 0xe6, 0x2, 0x379, 
       0x378, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37b, 
       0x379, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37c, 
       0x37e, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37e, 
       0x381, 0x7, 0x37, 0x2, 0x2, 0x37f, 0x380, 0x7, 0x54, 0x2, 0x2, 0x380, 
       0x382, 0x7, 0x33, 0x2, 0x2, 0x381, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x381, 
       0x382, 0x3, 0x2, 0x2, 0x2, 0x382, 0x384, 0x3, 0x2, 0x2, 0x2, 0x383, 
       0x385, 0x5, 0x202, 0x102, 0x2, 0x384, 0x383, 0x3, 0x2, 0x2, 0x2, 
       0x384, 0x385, 0x3, 0x2, 0x2, 0x2, 0x385, 0x386, 0x3, 0x2, 0x2, 0x2, 
       0x386, 0x387, 0x7, 0x7f, 0x2, 0x2, 0x387, 0x49, 0x3, 0x2, 0x2, 0x2, 
       0x388, 0x389, 0x7, 0x54, 0x2, 0x2, 0x389, 0x38a, 0x5, 0x202, 0x102, 
       0x2, 0x38a, 0x38b, 0x7, 0x5f, 0x2, 0x2, 0x38b, 0x38c, 0x7, 0x2f, 
       0x2, 0x2, 0x38c, 0x38e, 0x5, 0x6, 0x4, 0x2, 0x38d, 0x38f, 0x5, 0xee, 
       0x78, 0x2, 0x38e, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38e, 0x38f, 0x3, 0x2, 
       0x2, 0x2, 0x38f, 0x390, 0x3, 0x2, 0x2, 0x2, 0x390, 0x391, 0x7, 0x7f, 
       0x2, 0x2, 0x391, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x392, 0x397, 0x5, 0x54, 
       0x2b, 0x2, 0x393, 0x397, 0x5, 0x58, 0x2d, 0x2, 0x394, 0x397, 0x5, 
       0x60, 0x31, 0x2, 0x395, 0x397, 0x5, 0x5a, 0x2e, 0x2, 0x396, 0x392, 
       0x3, 0x2, 0x2, 0x2, 0x396, 0x393, 0x3, 0x2, 0x2, 0x2, 0x396, 0x394, 
       0x3, 0x2, 0x2, 0x2, 0x396, 0x395, 0x3, 0x2, 0x2, 0x2, 0x397, 0x4d, 
       0x3, 0x2, 0x2, 0x2, 0x398, 0x399, 0x7, 0x17, 0x2, 0x2, 0x399, 0x39a, 
       0x5, 0x50, 0x29, 0x2, 0x39a, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39e, 
       0x5, 0xc, 0x7, 0x2, 0x39c, 0x39e, 0x5, 0x10, 0x9, 0x2, 0x39d, 0x39b, 
       0x3, 0x2, 0x2, 0x2, 0x39d, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x51, 
       0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a0, 0x9, 0x5, 0x2, 0x2, 0x3a0, 0x53, 
       0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a2, 0x7, 0x80, 0x2, 0x2, 0x3a2, 0x3a7, 
       0x5, 0x56, 0x2c, 0x2, 0x3a3, 0x3a4, 0x7, 0x89, 0x2, 0x2, 0x3a4, 0x3a6, 
       0x5, 0x56, 0x2c, 0x2, 0x3a5, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a9, 
       0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a8, 
       0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3a7, 
       0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ab, 0x7, 0x81, 0x2, 0x2, 0x3ab, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3af, 0x5, 0x202, 0x102, 0x2, 0x3ad, 
       0x3af, 0x7, 0x72, 0x2, 0x2, 0x3ae, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ae, 
       0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x57, 0x3, 0x2, 0x2, 0x2, 0x3b0, 
       0x3b1, 0x5, 0x4e, 0x28, 0x2, 0x3b1, 0x59, 0x3, 0x2, 0x2, 0x2, 0x3b2, 
       0x3b3, 0x5, 0x4e, 0x28, 0x2, 0x3b3, 0x3b4, 0x7, 0x55, 0x2, 0x2, 0x3b4, 
       0x3b8, 0x5, 0x5c, 0x2f, 0x2, 0x3b5, 0x3b7, 0x5, 0x5e, 0x30, 0x2, 
       0x3b6, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3ba, 0x3, 0x2, 0x2, 0x2, 
       0x3b8, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 0x3, 0x2, 0x2, 0x2, 
       0x3b9, 0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3b8, 0x3, 0x2, 0x2, 0x2, 
       0x3bb, 0x3bc, 0x7, 0x37, 0x2, 0x2, 0x3bc, 0x3be, 0x7, 0x55, 0x2, 
       0x2, 0x3bd, 0x3bf, 0x5, 0x202, 0x102, 0x2, 0x3be, 0x3bd, 0x3, 0x2, 
       0x2, 0x2, 0x3be, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x5b, 0x3, 0x2, 
       0x2, 0x2, 0x3c0, 0x3c1, 0x5, 0x202, 0x102, 0x2, 0x3c1, 0x3c2, 0x7, 
       0x7f, 0x2, 0x2, 0x3c2, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c4, 0x5, 
       0x202, 0x102, 0x2, 0x3c4, 0x3c5, 0x7, 0x8d, 0x2, 0x2, 0x3c5, 0x3c6, 
       0x5, 0x150, 0xa9, 0x2, 0x3c6, 0x3c7, 0x7, 0x7f, 0x2, 0x2, 0x3c7, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3c9, 0x5, 0x4e, 0x28, 0x2, 0x3c9, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cd, 0x5, 0x64, 0x33, 0x2, 0x3cb, 
       0x3cd, 0x5, 0x74, 0x3b, 0x2, 0x3cc, 0x3ca, 0x3, 0x2, 0x2, 0x2, 0x3cc, 
       0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x63, 0x3, 0x2, 0x2, 0x2, 0x3ce, 
       0x3d1, 0x5, 0x66, 0x34, 0x2, 0x3cf, 0x3d1, 0x5, 0x68, 0x35, 0x2, 
       0x3d0, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3cf, 0x3, 0x2, 0x2, 0x2, 
       0x3d1, 0x65, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d3, 0x7, 0x50, 0x2, 0x2, 
       0x3d3, 0x3d4, 0x7, 0x80, 0x2, 0x2, 0x3d4, 0x3d9, 0x5, 0x6a, 0x36, 
       0x2, 0x3d5, 0x3d6, 0x7, 0x89, 0x2, 0x2, 0x3d6, 0x3d8, 0x5, 0x6a, 
       0x36, 0x2, 0x3d7, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3db, 0x3, 0x2, 
       0x2, 0x2, 0x3d9, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3da, 0x3, 0x2, 
       0x2, 0x2, 0x3da, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3d9, 0x3, 0x2, 
       0x2, 0x2, 0x3dc, 0x3dd, 0x7, 0x81, 0x2, 0x2, 0x3dd, 0x3de, 0x7, 0x23, 
       0x2, 0x2, 0x3de, 0x3df, 0x5, 0x96, 0x4c, 0x2, 0x3df, 0x67, 0x3, 0x2, 
       0x2, 0x2, 0x3e0, 0x3e1, 0x7, 0x50, 0x2, 0x2, 0x3e1, 0x3e2, 0x5, 0x70, 
       0x39, 0x2, 0x3e2, 0x3e3, 0x7, 0x23, 0x2, 0x2, 0x3e3, 0x3e4, 0x5, 
       0x96, 0x4c, 0x2, 0x3e4, 0x69, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e6, 0x5, 
       0xa2, 0x52, 0x2, 0x3e6, 0x3e7, 0x7, 0x17, 0x2, 0x2, 0x3e7, 0x3e8, 
       0x7, 0xa4, 0x2, 0x2, 0x3e8, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3eb, 
       0x5, 0x70, 0x39, 0x2, 0x3ea, 0x3ec, 0x5, 0x6e, 0x38, 0x2, 0x3eb, 
       0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3ec, 
       0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ee, 0x7, 0x80, 0x2, 0x2, 0x3ee, 
       0x3ef, 0x7, 0x66, 0x2, 0x2, 0x3ef, 0x3f1, 0x7, 0x81, 0x2, 0x2, 0x3f0, 
       0x3f2, 0x5, 0x6e, 0x38, 0x2, 0x3f1, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f1, 
       0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f3, 
       0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3f4, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f6, 0x5, 0xa6, 0x54, 0x2, 0x3f6, 
       0x6f, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f8, 0x7, 0x80, 0x2, 0x2, 0x3f8, 
       0x3fd, 0x5, 0x72, 0x3a, 0x2, 0x3f9, 0x3fa, 0x7, 0x89, 0x2, 0x2, 0x3fa, 
       0x3fc, 0x5, 0x72, 0x3a, 0x2, 0x3fb, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3fc, 
       0x3ff, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x3fd, 
       0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x400, 0x3, 0x2, 0x2, 0x2, 0x3ff, 
       0x3fd, 0x3, 0x2, 0x2, 0x2, 0x400, 0x401, 0x7, 0x81, 0x2, 0x2, 0x401, 
       0x71, 0x3, 0x2, 0x2, 0x2, 0x402, 0x405, 0x5, 0x96, 0x4c, 0x2, 0x403, 
       0x405, 0x5, 0x50, 0x29, 0x2, 0x404, 0x402, 0x3, 0x2, 0x2, 0x2, 0x404, 
       0x403, 0x3, 0x2, 0x2, 0x2, 0x405, 0x73, 0x3, 0x2, 0x2, 0x2, 0x406, 
       0x408, 0x7, 0x1d, 0x2, 0x2, 0x407, 0x409, 0x5, 0x76, 0x3c, 0x2, 0x408, 
       0x407, 0x3, 0x2, 0x2, 0x2, 0x409, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x40a, 
       0x408, 0x3, 0x2, 0x2, 0x2, 0x40a, 0x40b, 0x3, 0x2, 0x2, 0x2, 0x40b, 
       0x40c, 0x3, 0x2, 0x2, 0x2, 0x40c, 0x40d, 0x7, 0x37, 0x2, 0x2, 0x40d, 
       0x40f, 0x7, 0x1d, 0x2, 0x2, 0x40e, 0x410, 0x5, 0x202, 0x102, 0x2, 
       0x40f, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x40f, 0x410, 0x3, 0x2, 0x2, 0x2, 
       0x410, 0x75, 0x3, 0x2, 0x2, 0x2, 0x411, 0x412, 0x5, 0x78, 0x3d, 0x2, 
       0x412, 0x413, 0x7, 0x8c, 0x2, 0x2, 0x413, 0x414, 0x5, 0x7a, 0x3e, 
       0x2, 0x414, 0x415, 0x7, 0x7f, 0x2, 0x2, 0x415, 0x77, 0x3, 0x2, 0x2, 
       0x2, 0x416, 0x41b, 0x5, 0x202, 0x102, 0x2, 0x417, 0x418, 0x7, 0x89, 
       0x2, 0x2, 0x418, 0x41a, 0x5, 0x202, 0x102, 0x2, 0x419, 0x417, 0x3, 
       0x2, 0x2, 0x2, 0x41a, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x419, 0x3, 
       0x2, 0x2, 0x2, 0x41b, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x79, 0x3, 
       0x2, 0x2, 0x2, 0x41d, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41f, 0x5, 
       0x96, 0x4c, 0x2, 0x41f, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x420, 0x421, 0x7, 
       0x80, 0x2, 0x2, 0x421, 0x426, 0x5, 0x7e, 0x40, 0x2, 0x422, 0x423, 
       0x7, 0x89, 0x2, 0x2, 0x423, 0x425, 0x5, 0x7e, 0x40, 0x2, 0x424, 0x422, 
       0x3, 0x2, 0x2, 0x2, 0x425, 0x428, 0x3, 0x2, 0x2, 0x2, 0x426, 0x424, 
       0x3, 0x2, 0x2, 0x2, 0x426, 0x427, 0x3, 0x2, 0x2, 0x2, 0x427, 0x429, 
       0x3, 0x2, 0x2, 0x2, 0x428, 0x426, 0x3, 0x2, 0x2, 0x2, 0x429, 0x42a, 
       0x7, 0x81, 0x2, 0x2, 0x42a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x42b, 0x42c, 
       0x5, 0x202, 0x102, 0x2, 0x42c, 0x42d, 0x5, 0xa6, 0x54, 0x2, 0x42d, 
       0x7f, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42f, 0x7, 0x69, 0x2, 0x2, 0x42f, 
       0x430, 0x5, 0x96, 0x4c, 0x2, 0x430, 0x81, 0x3, 0x2, 0x2, 0x2, 0x431, 
       0x432, 0x7, 0x62, 0x2, 0x2, 0x432, 0x433, 0x5, 0x202, 0x102, 0x2, 
       0x433, 0x434, 0x7, 0x7f, 0x2, 0x2, 0x434, 0x83, 0x3, 0x2, 0x2, 0x2, 
       0x435, 0x436, 0x7, 0x13, 0x2, 0x2, 0x436, 0x437, 0x7, 0x23, 0x2, 
       0x2, 0x437, 0x438, 0x5, 0xa2, 0x52, 0x2, 0x438, 0x85, 0x3, 0x2, 0x2, 
       0x2, 0x439, 0x43c, 0x5, 0x88, 0x45, 0x2, 0x43a, 0x43c, 0x5, 0x8c, 
       0x47, 0x2, 0x43b, 0x439, 0x3, 0x2, 0x2, 0x2, 0x43b, 0x43a, 0x3, 0x2, 
       0x2, 0x2, 0x43c, 0x87, 0x3, 0x2, 0x2, 0x2, 0x43d, 0x441, 0x7, 0x3f, 
       0x2, 0x2, 0x43e, 0x440, 0x5, 0x8a, 0x46, 0x2, 0x43f, 0x43e, 0x3, 
       0x2, 0x2, 0x2, 0x440, 0x443, 0x3, 0x2, 0x2, 0x2, 0x441, 0x43f, 0x3, 
       0x2, 0x2, 0x2, 0x441, 0x442, 0x3, 0x2, 0x2, 0x2, 0x442, 0x444, 0x3, 
       0x2, 0x2, 0x2, 0x443, 0x441, 0x3, 0x2, 0x2, 0x2, 0x444, 0x445, 0x7, 
       0x37, 0x2, 0x2, 0x445, 0x447, 0x7, 0x3f, 0x2, 0x2, 0x446, 0x448, 
       0x5, 0x202, 0x102, 0x2, 0x447, 0x446, 0x3, 0x2, 0x2, 0x2, 0x447, 
       0x448, 0x3, 0x2, 0x2, 0x2, 0x448, 0x89, 0x3, 0x2, 0x2, 0x2, 0x449, 
       0x44e, 0x5, 0x2c, 0x17, 0x2, 0x44a, 0x44e, 0x5, 0x40, 0x21, 0x2, 
       0x44b, 0x44e, 0x5, 0x106, 0x84, 0x2, 0x44c, 0x44e, 0x5, 0x1ea, 0xf6, 
       0x2, 0x44d, 0x449, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x44a, 0x3, 0x2, 0x2, 
       0x2, 0x44d, 0x44b, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x44c, 0x3, 0x2, 0x2, 
       0x2, 0x44e, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x44f, 0x450, 0x7, 0x3f, 0x2, 
       0x2, 0x450, 0x454, 0x7, 0x33, 0x2, 0x2, 0x451, 0x453, 0x5, 0x1ca, 
       0xe6, 0x2, 0x452, 0x451, 0x3, 0x2, 0x2, 0x2, 0x453, 0x456, 0x3, 0x2, 
       0x2, 0x2, 0x454, 0x452, 0x3, 0x2, 0x2, 0x2, 0x454, 0x455, 0x3, 0x2, 
       0x2, 0x2, 0x455, 0x457, 0x3, 0x2, 0x2, 0x2, 0x456, 0x454, 0x3, 0x2, 
       0x2, 0x2, 0x457, 0x458, 0x7, 0x37, 0x2, 0x2, 0x458, 0x459, 0x7, 0x3f, 
       0x2, 0x2, 0x459, 0x45b, 0x7, 0x33, 0x2, 0x2, 0x45a, 0x45c, 0x5, 0x202, 
       0x102, 0x2, 0x45b, 0x45a, 0x3, 0x2, 0x2, 0x2, 0x45b, 0x45c, 0x3, 
       0x2, 0x2, 0x2, 0x45c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x45d, 0x460, 0x5, 
       0x90, 0x49, 0x2, 0x45e, 0x460, 0x5, 0x82, 0x42, 0x2, 0x45f, 0x45d, 
       0x3, 0x2, 0x2, 0x2, 0x45f, 0x45e, 0x3, 0x2, 0x2, 0x2, 0x460, 0x8f, 
       0x3, 0x2, 0x2, 0x2, 0x461, 0x462, 0x7, 0x62, 0x2, 0x2, 0x462, 0x463, 
       0x5, 0x202, 0x102, 0x2, 0x463, 0x464, 0x7, 0x5f, 0x2, 0x2, 0x464, 
       0x465, 0x5, 0x92, 0x4a, 0x2, 0x465, 0x466, 0x7, 0x7f, 0x2, 0x2, 0x466, 
       0x91, 0x3, 0x2, 0x2, 0x2, 0x467, 0x46d, 0x5, 0x4c, 0x27, 0x2, 0x468, 
       0x46d, 0x5, 0x62, 0x32, 0x2, 0x469, 0x46d, 0x5, 0x80, 0x41, 0x2, 
       0x46a, 0x46d, 0x5, 0x84, 0x43, 0x2, 0x46b, 0x46d, 0x5, 0x86, 0x44, 
       0x2, 0x46c, 0x467, 0x3, 0x2, 0x2, 0x2, 0x46c, 0x468, 0x3, 0x2, 0x2, 
       0x2, 0x46c, 0x469, 0x3, 0x2, 0x2, 0x2, 0x46c, 0x46a, 0x3, 0x2, 0x2, 
       0x2, 0x46c, 0x46b, 0x3, 0x2, 0x2, 0x2, 0x46d, 0x93, 0x3, 0x2, 0x2, 
       0x2, 0x46e, 0x46f, 0x7, 0x2d, 0x2, 0x2, 0x46f, 0x470, 0x5, 0x202, 
       0x102, 0x2, 0x470, 0x471, 0x7, 0x5f, 0x2, 0x2, 0x471, 0x472, 0x5, 
       0x96, 0x4c, 0x2, 0x472, 0x473, 0x7, 0x7f, 0x2, 0x2, 0x473, 0x95, 
       0x3, 0x2, 0x2, 0x2, 0x474, 0x476, 0x5, 0x98, 0x4d, 0x2, 0x475, 0x474, 
       0x3, 0x2, 0x2, 0x2, 0x475, 0x476, 0x3, 0x2, 0x2, 0x2, 0x476, 0x477, 
       0x3, 0x2, 0x2, 0x2, 0x477, 0x479, 0x5, 0xa2, 0x52, 0x2, 0x478, 0x47a, 
       0x5, 0xa4, 0x53, 0x2, 0x479, 0x478, 0x3, 0x2, 0x2, 0x2, 0x479, 0x47a, 
       0x3, 0x2, 0x2, 0x2, 0x47a, 0x97, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x481, 
       0x5, 0x6, 0x4, 0x2, 0x47c, 0x47d, 0x7, 0x80, 0x2, 0x2, 0x47d, 0x47e, 
       0x5, 0x9a, 0x4e, 0x2, 0x47e, 0x47f, 0x7, 0x81, 0x2, 0x2, 0x47f, 0x481, 
       0x3, 0x2, 0x2, 0x2, 0x480, 0x47b, 0x3, 0x2, 0x2, 0x2, 0x480, 0x47c, 
       0x3, 0x2, 0x2, 0x2, 0x481, 0x99, 0x3, 0x2, 0x2, 0x2, 0x482, 0x485, 
       0x5, 0x9c, 0x4f, 0x2, 0x483, 0x485, 0x5, 0x9e, 0x50, 0x2, 0x484, 
       0x482, 0x3, 0x2, 0x2, 0x2, 0x484, 0x483, 0x3, 0x2, 0x2, 0x2, 0x485, 
       0x9b, 0x3, 0x2, 0x2, 0x2, 0x486, 0x487, 0x5, 0x98, 0x4d, 0x2, 0x487, 
       0x9d, 0x3, 0x2, 0x2, 0x2, 0x488, 0x48d, 0x5, 0xa0, 0x51, 0x2, 0x489, 
       0x48a, 0x7, 0x89, 0x2, 0x2, 0x48a, 0x48c, 0x5, 0xa0, 0x51, 0x2, 0x48b, 
       0x489, 0x3, 0x2, 0x2, 0x2, 0x48c, 0x48f, 0x3, 0x2, 0x2, 0x2, 0x48d, 
       0x48b, 0x3, 0x2, 0x2, 0x2, 0x48d, 0x48e, 0x3, 0x2, 0x2, 0x2, 0x48e, 
       0x9f, 0x3, 0x2, 0x2, 0x2, 0x48f, 0x48d, 0x3, 0x2, 0x2, 0x2, 0x490, 
       0x491, 0x5, 0x202, 0x102, 0x2, 0x491, 0x492, 0x5, 0x98, 0x4d, 0x2, 
       0x492, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x493, 0x494, 0x5, 0x6, 0x4, 0x2, 
       0x494, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x495, 0x498, 0x5, 0x4e, 0x28, 0x2, 
       0x496, 0x498, 0x5, 0xa6, 0x54, 0x2, 0x497, 0x495, 0x3, 0x2, 0x2, 
       0x2, 0x497, 0x496, 0x3, 0x2, 0x2, 0x2, 0x498, 0xa5, 0x3, 0x2, 0x2, 
       0x2, 0x499, 0x49c, 0x5, 0x6c, 0x37, 0x2, 0x49a, 0x49c, 0x5, 0x7c, 
       0x3f, 0x2, 0x49b, 0x499, 0x3, 0x2, 0x2, 0x2, 0x49b, 0x49a, 0x3, 0x2, 
       0x2, 0x2, 0x49c, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x49d, 0x4a2, 0x5, 0xaa, 
       0x56, 0x2, 0x49e, 0x4a2, 0x5, 0xac, 0x57, 0x2, 0x49f, 0x4a2, 0x5, 
       0xb0, 0x59, 0x2, 0x4a0, 0x4a2, 0x5, 0xb2, 0x5a, 0x2, 0x4a1, 0x49d, 
       0x3, 0x2, 0x2, 0x2, 0x4a1, 0x49e, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x49f, 
       0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0x4a2, 0xa9, 
       0x3, 0x2, 0x2, 0x2, 0x4a3, 0x4a4, 0x7, 0x31, 0x2, 0x2, 0x4a4, 0x4a5, 
       0x5, 0x78, 0x3d, 0x2, 0x4a5, 0x4a6, 0x7, 0x8c, 0x2, 0x2, 0x4a6, 0x4a9, 
       0x5, 0x96, 0x4c, 0x2, 0x4a7, 0x4a8, 0x7, 0xa3, 0x2, 0x2, 0x4a8, 0x4aa, 
       0x5, 0x13a, 0x9e, 0x2, 0x4a9, 0x4a7, 0x3, 0x2, 0x2, 0x2, 0x4a9, 0x4aa, 
       0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4ac, 
       0x7, 0x7f, 0x2, 0x2, 0x4ac, 0xab, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ae, 
       0x7, 0x1e, 0x2, 0x2, 0x4ae, 0x4af, 0x5, 0x78, 0x3d, 0x2, 0x4af, 0x4b0, 
       0x7, 0x8c, 0x2, 0x2, 0x4b0, 0x4b2, 0x5, 0x96, 0x4c, 0x2, 0x4b1, 0x4b3, 
       0x5, 0xae, 0x58, 0x2, 0x4b2, 0x4b1, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b3, 
       0x3, 0x2, 0x2, 0x2, 0x4b3, 0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4b4, 0x4b5, 
       0x7, 0xa3, 0x2, 0x2, 0x4b5, 0x4b7, 0x5, 0x13a, 0x9e, 0x2, 0x4b6, 
       0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4b7, 
       0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4b8, 0x4b9, 0x7, 0x7f, 0x2, 0x2, 0x4b9, 
       0xad, 0x3, 0x2, 0x2, 0x2, 0x4ba, 0x4bb, 0x9, 0x6, 0x2, 0x2, 0x4bb, 
       0xaf, 0x3, 0x2, 0x2, 0x2, 0x4bc, 0x4be, 0x7, 0x1a, 0x2, 0x2, 0x4bd, 
       0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4bd, 0x4be, 0x3, 0x2, 0x2, 0x2, 0x4be, 
       0x4bf, 0x3, 0x2, 0x2, 0x2, 0x4bf, 0x4c0, 0x7, 0x28, 0x2, 0x2, 0x4c0, 
       0x4c1, 0x5, 0x78, 0x3d, 0x2, 0x4c1, 0x4c2, 0x7, 0x8c, 0x2, 0x2, 0x4c2, 
       0x4c5, 0x5, 0x96, 0x4c, 0x2, 0x4c3, 0x4c4, 0x7, 0xa3, 0x2, 0x2, 0x4c4, 
       0x4c6, 0x5, 0x13a, 0x9e, 0x2, 0x4c5, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4c5, 
       0x4c6, 0x3, 0x2, 0x2, 0x2, 0x4c6, 0x4c7, 0x3, 0x2, 0x2, 0x2, 0x4c7, 
       0x4c8, 0x7, 0x7f, 0x2, 0x2, 0x4c8, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x4c9, 
       0x4ca, 0x7, 0x13, 0x2, 0x2, 0x4ca, 0x4cb, 0x5, 0x78, 0x3d, 0x2, 0x4cb, 
       0x4cc, 0x7, 0x8c, 0x2, 0x2, 0x4cc, 0x4ce, 0x5, 0x96, 0x4c, 0x2, 0x4cd, 
       0x4cf, 0x5, 0xb4, 0x5b, 0x2, 0x4ce, 0x4cd, 0x3, 0x2, 0x2, 0x2, 0x4ce, 
       0x4cf, 0x3, 0x2, 0x2, 0x2, 0x4cf, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x4d0, 
       0x4d1, 0x7, 0x7f, 0x2, 0x2, 0x4d1, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x4d2, 
       0x4d3, 0x7, 0x66, 0x2, 0x2, 0x4d3, 0x4d5, 0x5, 0x13a, 0x9e, 0x2, 
       0x4d4, 0x4d2, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d5, 0x3, 0x2, 0x2, 0x2, 
       0x4d5, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4d8, 0x7, 0x5f, 0x2, 0x2, 
       0x4d7, 0x4d9, 0x9, 0x7, 0x2, 0x2, 0x4d8, 0x4d7, 0x3, 0x2, 0x2, 0x2, 
       0x4d8, 0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4da, 0x3, 0x2, 0x2, 0x2, 
       0x4da, 0x4db, 0x5, 0xb6, 0x5c, 0x2, 0x4db, 0xb5, 0x3, 0x2, 0x2, 0x2, 
       0x4dc, 0x4dd, 0x5, 0x13a, 0x9e, 0x2, 0x4dd, 0xb7, 0x3, 0x2, 0x2, 
       0x2, 0x4de, 0x4e3, 0x5, 0xba, 0x5e, 0x2, 0x4df, 0x4e3, 0x5, 0xc6, 
       0x64, 0x2, 0x4e0, 0x4e3, 0x5, 0xca, 0x66, 0x2, 0x4e1, 0x4e3, 0x5, 
       0xd4, 0x6b, 0x2, 0x4e2, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4df, 
       0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4e1, 
       0x3, 0x2, 0x2, 0x2, 0x4e3, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x4e4, 0x4e9, 
       0x5, 0xbc, 0x5f, 0x2, 0x4e5, 0x4e9, 0x5, 0xbe, 0x60, 0x2, 0x4e6, 
       0x4e9, 0x5, 0xc0, 0x61, 0x2, 0x4e7, 0x4e9, 0x5, 0xc2, 0x62, 0x2, 
       0x4e8, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4e5, 0x3, 0x2, 0x2, 0x2, 
       0x4e8, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4e7, 0x3, 0x2, 0x2, 0x2, 
       0x4e9, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x4ea, 0x4eb, 0x7, 0x31, 0x2, 0x2, 
       0x4eb, 0x4ec, 0x5, 0x78, 0x3d, 0x2, 0x4ec, 0x4ee, 0x7, 0x8c, 0x2, 
       0x2, 0x4ed, 0x4ef, 0x7, 0x46, 0x2, 0x2, 0x4ee, 0x4ed, 0x3, 0x2, 0x2, 
       0x2, 0x4ee, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f0, 0x3, 0x2, 0x2, 
       0x2, 0x4f0, 0x4f3, 0x5, 0x96, 0x4c, 0x2, 0x4f1, 0x4f2, 0x7, 0xa3, 
       0x2, 0x2, 0x4f2, 0x4f4, 0x5, 0x13a, 0x9e, 0x2, 0x4f3, 0x4f1, 0x3, 
       0x2, 0x2, 0x2, 0x4f3, 0x4f4, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0xbd, 0x3, 
       0x2, 0x2, 0x2, 0x4f5, 0x4f7, 0x7, 0x1e, 0x2, 0x2, 0x4f6, 0x4f5, 0x3, 
       0x2, 0x2, 0x2, 0x4f6, 0x4f7, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4f8, 0x3, 
       0x2, 0x2, 0x2, 0x4f8, 0x4f9, 0x5, 0x78, 0x3d, 0x2, 0x4f9, 0x4fb, 
       0x7, 0x8c, 0x2, 0x2, 0x4fa, 0x4fc, 0x5, 0xc4, 0x63, 0x2, 0x4fb, 0x4fa, 
       0x3, 0x2, 0x2, 0x2, 0x4fb, 0x4fc, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fd, 
       0x3, 0x2, 0x2, 0x2, 0x4fd, 0x4ff, 0x5, 0x96, 0x4c, 0x2, 0x4fe, 0x500, 
       0x7, 0x68, 0x2, 0x2, 0x4ff, 0x4fe, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x500, 
       0x3, 0x2, 0x2, 0x2, 0x500, 0x503, 0x3, 0x2, 0x2, 0x2, 0x501, 0x502, 
       0x7, 0xa3, 0x2, 0x2, 0x502, 0x504, 0x5, 0x13a, 0x9e, 0x2, 0x503, 
       0x501, 0x3, 0x2, 0x2, 0x2, 0x503, 0x504, 0x3, 0x2, 0x2, 0x2, 0x504, 
       0xbf, 0x3, 0x2, 0x2, 0x2, 0x505, 0x506, 0x7, 0x28, 0x2, 0x2, 0x506, 
       0x507, 0x5, 0x78, 0x3d, 0x2, 0x507, 0x509, 0x7, 0x8c, 0x2, 0x2, 0x508, 
       0x50a, 0x5, 0xc4, 0x63, 0x2, 0x509, 0x508, 0x3, 0x2, 0x2, 0x2, 0x509, 
       0x50a, 0x3, 0x2, 0x2, 0x2, 0x50a, 0x50b, 0x3, 0x2, 0x2, 0x2, 0x50b, 
       0x50e, 0x5, 0x96, 0x4c, 0x2, 0x50c, 0x50d, 0x7, 0xa3, 0x2, 0x2, 0x50d, 
       0x50f, 0x5, 0x13a, 0x9e, 0x2, 0x50e, 0x50c, 0x3, 0x2, 0x2, 0x2, 0x50e, 
       0x50f, 0x3, 0x2, 0x2, 0x2, 0x50f, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x510, 
       0x511, 0x7, 0x13, 0x2, 0x2, 0x511, 0x512, 0x5, 0x78, 0x3d, 0x2, 0x512, 
       0x513, 0x7, 0x8c, 0x2, 0x2, 0x513, 0x514, 0x5, 0x96, 0x4c, 0x2, 0x514, 
       0xc3, 0x3, 0x2, 0x2, 0x2, 0x515, 0x516, 0x9, 0x8, 0x2, 0x2, 0x516, 
       0xc5, 0x3, 0x2, 0x2, 0x2, 0x517, 0x518, 0x5, 0xc8, 0x65, 0x2, 0x518, 
       0xc7, 0x3, 0x2, 0x2, 0x2, 0x519, 0x51a, 0x7, 0x62, 0x2, 0x2, 0x51a, 
       0x51b, 0x5, 0x202, 0x102, 0x2, 0x51b, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x51c, 
       0x51f, 0x5, 0xcc, 0x67, 0x2, 0x51d, 0x51e, 0x7, 0x5f, 0x2, 0x2, 0x51e, 
       0x520, 0x5, 0xd2, 0x6a, 0x2, 0x51f, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x51f, 
       0x520, 0x3, 0x2, 0x2, 0x2, 0x520, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x521, 
       0x524, 0x5, 0xce, 0x68, 0x2, 0x522, 0x524, 0x5, 0xd0, 0x69, 0x2, 
       0x523, 0x521, 0x3, 0x2, 0x2, 0x2, 0x523, 0x522, 0x3, 0x2, 0x2, 0x2, 
       0x524, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x525, 0x526, 0x7, 0x24, 0x2, 0x2, 
       0x526, 0x52e, 0x5, 0x36, 0x1c, 0x2, 0x527, 0x529, 0x7, 0x57, 0x2, 
       0x2, 0x528, 0x527, 0x3, 0x2, 0x2, 0x2, 0x528, 0x529, 0x3, 0x2, 0x2, 
       0x2, 0x529, 0x52a, 0x3, 0x2, 0x2, 0x2, 0x52a, 0x52b, 0x7, 0x80, 0x2, 
       0x2, 0x52b, 0x52c, 0x5, 0x3a, 0x1e, 0x2, 0x52c, 0x52d, 0x7, 0x81, 
       0x2, 0x2, 0x52d, 0x52f, 0x3, 0x2, 0x2, 0x2, 0x52e, 0x528, 0x3, 0x2, 
       0x2, 0x2, 0x52e, 0x52f, 0x3, 0x2, 0x2, 0x2, 0x52f, 0xcf, 0x3, 0x2, 
       0x2, 0x2, 0x530, 0x532, 0x9, 0x3, 0x2, 0x2, 0x531, 0x530, 0x3, 0x2, 
       0x2, 0x2, 0x531, 0x532, 0x3, 0x2, 0x2, 0x2, 0x532, 0x533, 0x3, 0x2, 
       0x2, 0x2, 0x533, 0x534, 0x7, 0x36, 0x2, 0x2, 0x534, 0x53c, 0x5, 0x36, 
       0x1c, 0x2, 0x535, 0x537, 0x7, 0x57, 0x2, 0x2, 0x536, 0x535, 0x3, 
       0x2, 0x2, 0x2, 0x536, 0x537, 0x3, 0x2, 0x2, 0x2, 0x537, 0x538, 0x3, 
       0x2, 0x2, 0x2, 0x538, 0x539, 0x7, 0x80, 0x2, 0x2, 0x539, 0x53a, 0x5, 
       0x3a, 0x1e, 0x2, 0x53a, 0x53b, 0x7, 0x81, 0x2, 0x2, 0x53b, 0x53d, 
       0x3, 0x2, 0x2, 0x2, 0x53c, 0x536, 0x3, 0x2, 0x2, 0x2, 0x53c, 0x53d, 
       0x3, 0x2, 0x2, 0x2, 0x53d, 0x53e, 0x3, 0x2, 0x2, 0x2, 0x53e, 0x53f, 
       0x7, 0x49, 0x2, 0x2, 0x53f, 0x540, 0x5, 0xa2, 0x52, 0x2, 0x540, 0xd1, 
       0x3, 0x2, 0x2, 0x2, 0x541, 0x544, 0x5, 0x6, 0x4, 0x2, 0x542, 0x544, 
       0x7, 0xa4, 0x2, 0x2, 0x543, 0x541, 0x3, 0x2, 0x2, 0x2, 0x543, 0x542, 
       0x3, 0x2, 0x2, 0x2, 0x544, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x545, 0x546, 
       0x7, 0x54, 0x2, 0x2, 0x546, 0x547, 0x5, 0x202, 0x102, 0x2, 0x547, 
       0x548, 0x7, 0x5f, 0x2, 0x2, 0x548, 0x549, 0x7, 0x2f, 0x2, 0x2, 0x549, 
       0x54a, 0x5, 0x6, 0x4, 0x2, 0x54a, 0x54b, 0x5, 0xd6, 0x6c, 0x2, 0x54b, 
       0xd5, 0x3, 0x2, 0x2, 0x2, 0x54c, 0x558, 0x5, 0xee, 0x78, 0x2, 0x54d, 
       0x54e, 0x7, 0x16, 0x2, 0x2, 0x54e, 0x54f, 0x7, 0x3d, 0x2, 0x2, 0x54f, 
       0x550, 0x7, 0x80, 0x2, 0x2, 0x550, 0x551, 0x7, 0xa4, 0x2, 0x2, 0x551, 
       0x558, 0x7, 0x81, 0x2, 0x2, 0x552, 0x553, 0x7, 0x16, 0x2, 0x2, 0x553, 
       0x554, 0x7, 0x3d, 0x2, 0x2, 0x554, 0x555, 0x7, 0x80, 0x2, 0x2, 0x555, 
       0x556, 0x7, 0x9, 0x2, 0x2, 0x556, 0x558, 0x7, 0x81, 0x2, 0x2, 0x557, 
       0x54c, 0x3, 0x2, 0x2, 0x2, 0x557, 0x54d, 0x3, 0x2, 0x2, 0x2, 0x557, 
       0x552, 0x3, 0x2, 0x2, 0x2, 0x558, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x559, 
       0x55e, 0x5, 0xda, 0x6e, 0x2, 0x55a, 0x55b, 0x7, 0x7f, 0x2, 0x2, 0x55b, 
       0x55d, 0x5, 0xda, 0x6e, 0x2, 0x55c, 0x55a, 0x3, 0x2, 0x2, 0x2, 0x55d, 
       0x560, 0x3, 0x2, 0x2, 0x2, 0x55e, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x55e, 
       0x55f, 0x3, 0x2, 0x2, 0x2, 0x55f, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x560, 
       0x55e, 0x3, 0x2, 0x2, 0x2, 0x561, 0x562, 0x5, 0xb8, 0x5d, 0x2, 0x562, 
       0xdb, 0x3, 0x2, 0x2, 0x2, 0x563, 0x564, 0x7, 0x16, 0x2, 0x2, 0x564, 
       0x565, 0x7, 0x80, 0x2, 0x2, 0x565, 0x566, 0x5, 0xde, 0x70, 0x2, 0x566, 
       0x567, 0x7, 0x81, 0x2, 0x2, 0x567, 0x568, 0x7, 0x7f, 0x2, 0x2, 0x568, 
       0xdd, 0x3, 0x2, 0x2, 0x2, 0x569, 0x56a, 0x5, 0xd8, 0x6d, 0x2, 0x56a, 
       0xdf, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x56c, 0x7, 0x6b, 0x2, 0x2, 0x56c, 
       0x56d, 0x7, 0x80, 0x2, 0x2, 0x56d, 0x56e, 0x5, 0xe2, 0x72, 0x2, 0x56e, 
       0x56f, 0x7, 0x81, 0x2, 0x2, 0x56f, 0x570, 0x7, 0x7f, 0x2, 0x2, 0x570, 
       0xe1, 0x3, 0x2, 0x2, 0x2, 0x571, 0x572, 0x5, 0xd8, 0x6d, 0x2, 0x572, 
       0xe3, 0x3, 0x2, 0x2, 0x2, 0x573, 0x574, 0x7, 0x80, 0x2, 0x2, 0x574, 
       0x579, 0x5, 0xe6, 0x74, 0x2, 0x575, 0x576, 0x7, 0x89, 0x2, 0x2, 0x576, 
       0x578, 0x5, 0xe6, 0x74, 0x2, 0x577, 0x575, 0x3, 0x2, 0x2, 0x2, 0x578, 
       0x57b, 0x3, 0x2, 0x2, 0x2, 0x579, 0x577, 0x3, 0x2, 0x2, 0x2, 0x579, 
       0x57a, 0x3, 0x2, 0x2, 0x2, 0x57a, 0x57c, 0x3, 0x2, 0x2, 0x2, 0x57b, 
       0x579, 0x3, 0x2, 0x2, 0x2, 0x57c, 0x57d, 0x7, 0x81, 0x2, 0x2, 0x57d, 
       0xe5, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x57f, 0x5, 0xe8, 0x75, 0x2, 0x57f, 
       0x580, 0x7, 0xa5, 0x2, 0x2, 0x580, 0x582, 0x3, 0x2, 0x2, 0x2, 0x581, 
       0x57e, 0x3, 0x2, 0x2, 0x2, 0x581, 0x582, 0x3, 0x2, 0x2, 0x2, 0x582, 
       0x583, 0x3, 0x2, 0x2, 0x2, 0x583, 0x584, 0x5, 0xea, 0x76, 0x2, 0x584, 
       0xe7, 0x3, 0x2, 0x2, 0x2, 0x585, 0x58a, 0x5, 0x6, 0x4, 0x2, 0x586, 
       0x587, 0x7, 0x80, 0x2, 0x2, 0x587, 0x588, 0x5, 0x6, 0x4, 0x2, 0x588, 
       0x589, 0x7, 0x81, 0x2, 0x2, 0x589, 0x58b, 0x3, 0x2, 0x2, 0x2, 0x58a, 
       0x586, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x58b, 0x3, 0x2, 0x2, 0x2, 0x58b, 
       0xe9, 0x3, 0x2, 0x2, 0x2, 0x58c, 0x58d, 0x5, 0x6, 0x4, 0x2, 0x58d, 
       0x58e, 0x7, 0x80, 0x2, 0x2, 0x58e, 0x58f, 0x5, 0xec, 0x77, 0x2, 0x58f, 
       0x590, 0x7, 0x81, 0x2, 0x2, 0x590, 0x593, 0x3, 0x2, 0x2, 0x2, 0x591, 
       0x593, 0x5, 0xec, 0x77, 0x2, 0x592, 0x58c, 0x3, 0x2, 0x2, 0x2, 0x592, 
       0x591, 0x3, 0x2, 0x2, 0x2, 0x593, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x594, 
       0x596, 0x7, 0xd, 0x2, 0x2, 0x595, 0x594, 0x3, 0x2, 0x2, 0x2, 0x595, 
       0x596, 0x3, 0x2, 0x2, 0x2, 0x596, 0x597, 0x3, 0x2, 0x2, 0x2, 0x597, 
       0x59b, 0x5, 0x13a, 0x9e, 0x2, 0x598, 0x59b, 0x5, 0x96, 0x4c, 0x2, 
       0x599, 0x59b, 0x7, 0x66, 0x2, 0x2, 0x59a, 0x595, 0x3, 0x2, 0x2, 0x2, 
       0x59a, 0x598, 0x3, 0x2, 0x2, 0x2, 0x59a, 0x599, 0x3, 0x2, 0x2, 0x2, 
       0x59b, 0xed, 0x3, 0x2, 0x2, 0x2, 0x59c, 0x59d, 0x7, 0x16, 0x2, 0x2, 
       0x59d, 0x59e, 0x7, 0x3d, 0x2, 0x2, 0x59e, 0x59f, 0x5, 0xe4, 0x73, 
       0x2, 0x59f, 0xef, 0x3, 0x2, 0x2, 0x2, 0x5a0, 0x5a1, 0x7, 0x6b, 0x2, 
       0x2, 0x5a1, 0x5a2, 0x7, 0x3d, 0x2, 0x2, 0x5a2, 0x5a3, 0x5, 0xe4, 
       0x73, 0x2, 0x5a3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x5a4, 0x5a5, 0x7, 0x43, 
       0x2, 0x2, 0x5a5, 0x5a8, 0x5, 0xf4, 0x7b, 0x2, 0x5a6, 0x5a7, 0x7, 
       0x8c, 0x2, 0x2, 0x5a7, 0x5a9, 0x5, 0x96, 0x4c, 0x2, 0x5a8, 0x5a6, 
       0x3, 0x2, 0x2, 0x2, 0x5a8, 0x5a9, 0x3, 0x2, 0x2, 0x2, 0x5a9, 0x5aa, 
       0x3, 0x2, 0x2, 0x2, 0x5aa, 0x5ab, 0x7, 0x5f, 0x2, 0x2, 0x5ab, 0x5ad, 
       0x5, 0x6, 0x4, 0x2, 0x5ac, 0x5ae, 0x5, 0x42, 0x22, 0x2, 0x5ad, 0x5ac, 
       0x3, 0x2, 0x2, 0x2, 0x5ad, 0x5ae, 0x3, 0x2, 0x2, 0x2, 0x5ae, 0x5af, 
       0x3, 0x2, 0x2, 0x2, 0x5af, 0x5b0, 0x7, 0x7f, 0x2, 0x2, 0x5b0, 0xf3, 
       0x3, 0x2, 0x2, 0x2, 0x5b1, 0x5b5, 0x5, 0x202, 0x102, 0x2, 0x5b2, 
       0x5b5, 0x7, 0x72, 0x2, 0x2, 0x5b3, 0x5b5, 0x5, 0x38, 0x1d, 0x2, 0x5b4, 
       0x5b1, 0x3, 0x2, 0x2, 0x2, 0x5b4, 0x5b2, 0x3, 0x2, 0x2, 0x2, 0x5b4, 
       0x5b3, 0x3, 0x2, 0x2, 0x2, 0x5b5, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x5b6, 
       0x5b7, 0x7, 0x27, 0x2, 0x2, 0x5b7, 0x5b8, 0x5, 0x202, 0x102, 0x2, 
       0x5b8, 0x5b9, 0x7, 0x8c, 0x2, 0x2, 0x5b9, 0x5ba, 0x5, 0xa2, 0x52, 
       0x2, 0x5ba, 0x5bb, 0x7, 0x7f, 0x2, 0x2, 0x5bb, 0xf7, 0x3, 0x2, 0x2, 
       0x2, 0x5bc, 0x5bd, 0x7, 0x7, 0x2, 0x2, 0x5bd, 0x5bf, 0x5, 0x202, 
       0x102, 0x2, 0x5be, 0x5c0, 0x7, 0x5f, 0x2, 0x2, 0x5bf, 0x5be, 0x3, 
       0x2, 0x2, 0x2, 0x5bf, 0x5c0, 0x3, 0x2, 0x2, 0x2, 0x5c0, 0x5c2, 0x3, 
       0x2, 0x2, 0x2, 0x5c1, 0x5c3, 0x5, 0xdc, 0x6f, 0x2, 0x5c2, 0x5c1, 
       0x3, 0x2, 0x2, 0x2, 0x5c2, 0x5c3, 0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c5, 
       0x3, 0x2, 0x2, 0x2, 0x5c4, 0x5c6, 0x5, 0xe0, 0x71, 0x2, 0x5c5, 0x5c4, 
       0x3, 0x2, 0x2, 0x2, 0x5c5, 0x5c6, 0x3, 0x2, 0x2, 0x2, 0x5c6, 0x5c7, 
       0x3, 0x2, 0x2, 0x2, 0x5c7, 0x5c8, 0x7, 0x37, 0x2, 0x2, 0x5c8, 0x5ca, 
       0x7, 0x7, 0x2, 0x2, 0x5c9, 0x5cb, 0x5, 0x202, 0x102, 0x2, 0x5ca, 
       0x5c9, 0x3, 0x2, 0x2, 0x2, 0x5ca, 0x5cb, 0x3, 0x2, 0x2, 0x2, 0x5cb, 
       0x5cc, 0x3, 0x2, 0x2, 0x2, 0x5cc, 0x5cd, 0x7, 0x7f, 0x2, 0x2, 0x5cd, 
       0xf9, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5cf, 0x7, 0x11, 0x2, 0x2, 0x5cf, 
       0x5d0, 0x5, 0x202, 0x102, 0x2, 0x5d0, 0x5d1, 0x7, 0x5f, 0x2, 0x2, 
       0x5d1, 0x5d2, 0x7, 0x80, 0x2, 0x2, 0x5d2, 0x5d3, 0x5, 0xfc, 0x7f, 
       0x2, 0x5d3, 0x5d4, 0x7, 0x81, 0x2, 0x2, 0x5d4, 0x5d5, 0x7, 0x7f, 
       0x2, 0x2, 0x5d5, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x5d6, 0x5db, 0x5, 0xfe, 
       0x80, 0x2, 0x5d7, 0x5d8, 0x7, 0x89, 0x2, 0x2, 0x5d8, 0x5da, 0x5, 
       0xfe, 0x80, 0x2, 0x5d9, 0x5d7, 0x3, 0x2, 0x2, 0x2, 0x5da, 0x5dd, 
       0x3, 0x2, 0x2, 0x2, 0x5db, 0x5d9, 0x3, 0x2, 0x2, 0x2, 0x5db, 0x5dc, 
       0x3, 0x2, 0x2, 0x2, 0x5dc, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x5dd, 0x5db, 
       0x3, 0x2, 0x2, 0x2, 0x5de, 0x5e0, 0x5, 0x10a, 0x86, 0x2, 0x5df, 0x5e1, 
       0x7, 0xa4, 0x2, 0x2, 0x5e0, 0x5df, 0x3, 0x2, 0x2, 0x2, 0x5e0, 0x5e1, 
       0x3, 0x2, 0x2, 0x2, 0x5e1, 0xff, 0x3, 0x2, 0x2, 0x2, 0x5e2, 0x5e3, 
       0x7, 0x11, 0x2, 0x2, 0x5e3, 0x5e4, 0x5, 0x202, 0x102, 0x2, 0x5e4, 
       0x5e5, 0x7, 0x8c, 0x2, 0x2, 0x5e5, 0x5e6, 0x5, 0x6, 0x4, 0x2, 0x5e6, 
       0x5e7, 0x7, 0x80, 0x2, 0x2, 0x5e7, 0x5e8, 0x5, 0x102, 0x82, 0x2, 
       0x5e8, 0x5e9, 0x7, 0x81, 0x2, 0x2, 0x5e9, 0x5ea, 0x7, 0x7f, 0x2, 
       0x2, 0x5ea, 0x101, 0x3, 0x2, 0x2, 0x2, 0x5eb, 0x5f0, 0x5, 0x104, 
       0x83, 0x2, 0x5ec, 0x5ed, 0x7, 0x89, 0x2, 0x2, 0x5ed, 0x5ef, 0x5, 
       0x104, 0x83, 0x2, 0x5ee, 0x5ec, 0x3, 0x2, 0x2, 0x2, 0x5ef, 0x5f2, 
       0x3, 0x2, 0x2, 0x2, 0x5f0, 0x5ee, 0x3, 0x2, 0x2, 0x2, 0x5f0, 0x5f1, 
       0x3, 0x2, 0x2, 0x2, 0x5f1, 0x103, 0x3, 0x2, 0x2, 0x2, 0x5f2, 0x5f0, 
       0x3, 0x2, 0x2, 0x2, 0x5f3, 0x5f4, 0x5, 0x6, 0x4, 0x2, 0x5f4, 0x105, 
       0x3, 0x2, 0x2, 0x2, 0x5f5, 0x5f6, 0x7, 0x27, 0x2, 0x2, 0x5f6, 0x5f7, 
       0x5, 0x12a, 0x96, 0x2, 0x5f7, 0x5f8, 0x7, 0x23, 0x2, 0x2, 0x5f8, 
       0x5f9, 0x5, 0x108, 0x85, 0x2, 0x5f9, 0x5fa, 0x7, 0x5f, 0x2, 0x2, 
       0x5fa, 0x5fb, 0x5, 0x13a, 0x9e, 0x2, 0x5fb, 0x5fc, 0x7, 0x7f, 0x2, 
       0x2, 0x5fc, 0x107, 0x3, 0x2, 0x2, 0x2, 0x5fd, 0x5fe, 0x5, 0x10c, 
       0x87, 0x2, 0x5fe, 0x5ff, 0x7, 0x8c, 0x2, 0x2, 0x5ff, 0x600, 0x5, 
       0x10a, 0x86, 0x2, 0x600, 0x109, 0x3, 0x2, 0x2, 0x2, 0x601, 0x602, 
       0x9, 0x9, 0x2, 0x2, 0x602, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x603, 0x608, 
       0x5, 0x10e, 0x88, 0x2, 0x604, 0x605, 0x7, 0x89, 0x2, 0x2, 0x605, 
       0x607, 0x5, 0x10e, 0x88, 0x2, 0x606, 0x604, 0x3, 0x2, 0x2, 0x2, 0x607, 
       0x60a, 0x3, 0x2, 0x2, 0x2, 0x608, 0x606, 0x3, 0x2, 0x2, 0x2, 0x608, 
       0x609, 0x3, 0x2, 0x2, 0x2, 0x609, 0x60e, 0x3, 0x2, 0x2, 0x2, 0x60a, 
       0x608, 0x3, 0x2, 0x2, 0x2, 0x60b, 0x60e, 0x7, 0x61, 0x2, 0x2, 0x60c, 
       0x60e, 0x7, 0x42, 0x2, 0x2, 0x60d, 0x603, 0x3, 0x2, 0x2, 0x2, 0x60d, 
       0x60b, 0x3, 0x2, 0x2, 0x2, 0x60d, 0x60c, 0x3, 0x2, 0x2, 0x2, 0x60e, 
       0x10d, 0x3, 0x2, 0x2, 0x2, 0x60f, 0x611, 0x5, 0x110, 0x89, 0x2, 0x610, 
       0x612, 0x5, 0x42, 0x22, 0x2, 0x611, 0x610, 0x3, 0x2, 0x2, 0x2, 0x611, 
       0x612, 0x3, 0x2, 0x2, 0x2, 0x612, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x613, 
       0x617, 0x5, 0x202, 0x102, 0x2, 0x614, 0x617, 0x7, 0x72, 0x2, 0x2, 
       0x615, 0x617, 0x5, 0x38, 0x1d, 0x2, 0x616, 0x613, 0x3, 0x2, 0x2, 
       0x2, 0x616, 0x614, 0x3, 0x2, 0x2, 0x2, 0x616, 0x615, 0x3, 0x2, 0x2, 
       0x2, 0x617, 0x111, 0x3, 0x2, 0x2, 0x2, 0x618, 0x61b, 0x5, 0x114, 
       0x8b, 0x2, 0x619, 0x61b, 0x5, 0x116, 0x8c, 0x2, 0x61a, 0x618, 0x3, 
       0x2, 0x2, 0x2, 0x61a, 0x619, 0x3, 0x2, 0x2, 0x2, 0x61b, 0x113, 0x3, 
       0x2, 0x2, 0x2, 0x61c, 0x61d, 0x7, 0x5a, 0x2, 0x2, 0x61d, 0x61e, 0x5, 
       0x118, 0x8d, 0x2, 0x61e, 0x61f, 0x5, 0x11c, 0x8f, 0x2, 0x61f, 0x623, 
       0x7, 0x7f, 0x2, 0x2, 0x620, 0x621, 0x7, 0x37, 0x2, 0x2, 0x621, 0x622, 
       0x7, 0x5a, 0x2, 0x2, 0x622, 0x624, 0x7, 0x7f, 0x2, 0x2, 0x623, 0x620, 
       0x3, 0x2, 0x2, 0x2, 0x623, 0x624, 0x3, 0x2, 0x2, 0x2, 0x624, 0x115, 
       0x3, 0x2, 0x2, 0x2, 0x625, 0x626, 0x7, 0x5a, 0x2, 0x2, 0x626, 0x627, 
       0x5, 0x118, 0x8d, 0x2, 0x627, 0x628, 0x5, 0x11c, 0x8f, 0x2, 0x628, 
       0x62c, 0x7, 0x7f, 0x2, 0x2, 0x629, 0x62a, 0x5, 0x120, 0x91, 0x2, 
       0x62a, 0x62b, 0x7, 0x7f, 0x2, 0x2, 0x62b, 0x62d, 0x3, 0x2, 0x2, 0x2, 
       0x62c, 0x629, 0x3, 0x2, 0x2, 0x2, 0x62d, 0x62e, 0x3, 0x2, 0x2, 0x2, 
       0x62e, 0x62c, 0x3, 0x2, 0x2, 0x2, 0x62e, 0x62f, 0x3, 0x2, 0x2, 0x2, 
       0x62f, 0x630, 0x3, 0x2, 0x2, 0x2, 0x630, 0x631, 0x7, 0x37, 0x2, 0x2, 
       0x631, 0x632, 0x7, 0x5a, 0x2, 0x2, 0x632, 0x633, 0x7, 0x7f, 0x2, 
       0x2, 0x633, 0x117, 0x3, 0x2, 0x2, 0x2, 0x634, 0x635, 0x5, 0x11a, 
       0x8e, 0x2, 0x635, 0x636, 0x7, 0x8c, 0x2, 0x2, 0x636, 0x637, 0x5, 
       0x6, 0x4, 0x2, 0x637, 0x119, 0x3, 0x2, 0x2, 0x2, 0x638, 0x63d, 0x5, 
       0x1e8, 0xf5, 0x2, 0x639, 0x63a, 0x7, 0x89, 0x2, 0x2, 0x63a, 0x63c, 
       0x5, 0x1e8, 0xf5, 0x2, 0x63b, 0x639, 0x3, 0x2, 0x2, 0x2, 0x63c, 0x63f, 
       0x3, 0x2, 0x2, 0x2, 0x63d, 0x63b, 0x3, 0x2, 0x2, 0x2, 0x63d, 0x63e, 
       0x3, 0x2, 0x2, 0x2, 0x63e, 0x643, 0x3, 0x2, 0x2, 0x2, 0x63f, 0x63d, 
       0x3, 0x2, 0x2, 0x2, 0x640, 0x643, 0x7, 0x61, 0x2, 0x2, 0x641, 0x643, 
       0x7, 0x42, 0x2, 0x2, 0x642, 0x638, 0x3, 0x2, 0x2, 0x2, 0x642, 0x640, 
       0x3, 0x2, 0x2, 0x2, 0x642, 0x641, 0x3, 0x2, 0x2, 0x2, 0x643, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x644, 0x645, 0x7, 0x19, 0x2, 0x2, 0x645, 0x647, 
       0x5, 0x11e, 0x90, 0x2, 0x646, 0x644, 0x3, 0x2, 0x2, 0x2, 0x646, 0x647, 
       0x3, 0x2, 0x2, 0x2, 0x647, 0x649, 0x3, 0x2, 0x2, 0x2, 0x648, 0x64a, 
       0x5, 0xee, 0x78, 0x2, 0x649, 0x648, 0x3, 0x2, 0x2, 0x2, 0x649, 0x64a, 
       0x3, 0x2, 0x2, 0x2, 0x64a, 0x64c, 0x3, 0x2, 0x2, 0x2, 0x64b, 0x64d, 
       0x5, 0xf0, 0x79, 0x2, 0x64c, 0x64b, 0x3, 0x2, 0x2, 0x2, 0x64c, 0x64d, 
       0x3, 0x2, 0x2, 0x2, 0x64d, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x64e, 0x64f, 
       0x7, 0xf, 0x2, 0x2, 0x64f, 0x654, 0x5, 0x6, 0x4, 0x2, 0x650, 0x651, 
       0x7, 0x80, 0x2, 0x2, 0x651, 0x652, 0x5, 0x202, 0x102, 0x2, 0x652, 
       0x653, 0x7, 0x81, 0x2, 0x2, 0x653, 0x655, 0x3, 0x2, 0x2, 0x2, 0x654, 
       0x650, 0x3, 0x2, 0x2, 0x2, 0x654, 0x655, 0x3, 0x2, 0x2, 0x2, 0x655, 
       0x65a, 0x3, 0x2, 0x2, 0x2, 0x656, 0x657, 0x7, 0x65, 0x2, 0x2, 0x657, 
       0x65a, 0x5, 0x6, 0x4, 0x2, 0x658, 0x65a, 0x7, 0x66, 0x2, 0x2, 0x659, 
       0x64e, 0x3, 0x2, 0x2, 0x2, 0x659, 0x656, 0x3, 0x2, 0x2, 0x2, 0x659, 
       0x658, 0x3, 0x2, 0x2, 0x2, 0x65a, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x65b, 
       0x65c, 0x7, 0x19, 0x2, 0x2, 0x65c, 0x65d, 0x7, 0x26, 0x2, 0x2, 0x65d, 
       0x65e, 0x5, 0x122, 0x92, 0x2, 0x65e, 0x121, 0x3, 0x2, 0x2, 0x2, 0x65f, 
       0x664, 0x5, 0x6, 0x4, 0x2, 0x660, 0x661, 0x7, 0x89, 0x2, 0x2, 0x661, 
       0x663, 0x5, 0x6, 0x4, 0x2, 0x662, 0x660, 0x3, 0x2, 0x2, 0x2, 0x663, 
       0x666, 0x3, 0x2, 0x2, 0x2, 0x664, 0x662, 0x3, 0x2, 0x2, 0x2, 0x664, 
       0x665, 0x3, 0x2, 0x2, 0x2, 0x665, 0x123, 0x3, 0x2, 0x2, 0x2, 0x666, 
       0x664, 0x3, 0x2, 0x2, 0x2, 0x667, 0x668, 0x7, 0x22, 0x2, 0x2, 0x668, 
       0x669, 0x5, 0x126, 0x94, 0x2, 0x669, 0x66a, 0x7, 0x34, 0x2, 0x2, 
       0x66a, 0x66b, 0x5, 0x13a, 0x9e, 0x2, 0x66b, 0x66c, 0x7, 0x7f, 0x2, 
       0x2, 0x66c, 0x125, 0x3, 0x2, 0x2, 0x2, 0x66d, 0x66e, 0x5, 0x128, 
       0x95, 0x2, 0x66e, 0x66f, 0x7, 0x8c, 0x2, 0x2, 0x66f, 0x670, 0x5, 
       0xa2, 0x52, 0x2, 0x670, 0x127, 0x3, 0x2, 0x2, 0x2, 0x671, 0x676, 
       0x5, 0x6, 0x4, 0x2, 0x672, 0x673, 0x7, 0x89, 0x2, 0x2, 0x673, 0x675, 
       0x5, 0x6, 0x4, 0x2, 0x674, 0x672, 0x3, 0x2, 0x2, 0x2, 0x675, 0x678, 
       0x3, 0x2, 0x2, 0x2, 0x676, 0x674, 0x3, 0x2, 0x2, 0x2, 0x676, 0x677, 
       0x3, 0x2, 0x2, 0x2, 0x677, 0x67c, 0x3, 0x2, 0x2, 0x2, 0x678, 0x676, 
       0x3, 0x2, 0x2, 0x2, 0x679, 0x67c, 0x7, 0x61, 0x2, 0x2, 0x67a, 0x67c, 
       0x7, 0x42, 0x2, 0x2, 0x67b, 0x671, 0x3, 0x2, 0x2, 0x2, 0x67b, 0x679, 
       0x3, 0x2, 0x2, 0x2, 0x67b, 0x67a, 0x3, 0x2, 0x2, 0x2, 0x67c, 0x129, 
       0x3, 0x2, 0x2, 0x2, 0x67d, 0x680, 0x5, 0x202, 0x102, 0x2, 0x67e, 
       0x680, 0x5, 0x2, 0x2, 0x2, 0x67f, 0x67d, 0x3, 0x2, 0x2, 0x2, 0x67f, 
       0x67e, 0x3, 0x2, 0x2, 0x2, 0x680, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x681, 
       0x682, 0x7, 0x85, 0x2, 0x2, 0x682, 0x683, 0x9, 0xa, 0x2, 0x2, 0x683, 
       0x684, 0x5, 0x12e, 0x98, 0x2, 0x684, 0x685, 0x7, 0x8c, 0x2, 0x2, 
       0x685, 0x686, 0x5, 0x96, 0x4c, 0x2, 0x686, 0x687, 0x7, 0x86, 0x2, 
       0x2, 0x687, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x688, 0x68c, 0x5, 0x130, 
       0x99, 0x2, 0x689, 0x68c, 0x5, 0x132, 0x9a, 0x2, 0x68a, 0x68c, 0x5, 
       0x134, 0x9b, 0x2, 0x68b, 0x688, 0x3, 0x2, 0x2, 0x2, 0x68b, 0x689, 
       0x3, 0x2, 0x2, 0x2, 0x68b, 0x68a, 0x3, 0x2, 0x2, 0x2, 0x68c, 0x12f, 
       0x3, 0x2, 0x2, 0x2, 0x68d, 0x68e, 0x7, 0x87, 0x2, 0x2, 0x68e, 0x68f, 
       0x5, 0x202, 0x102, 0x2, 0x68f, 0x690, 0x7, 0x8a, 0x2, 0x2, 0x690, 
       0x691, 0x5, 0x202, 0x102, 0x2, 0x691, 0x692, 0x7, 0x8a, 0x2, 0x2, 
       0x692, 0x697, 0x5, 0x202, 0x102, 0x2, 0x693, 0x694, 0x7, 0x8a, 0x2, 
       0x2, 0x694, 0x696, 0x5, 0x202, 0x102, 0x2, 0x695, 0x693, 0x3, 0x2, 
       0x2, 0x2, 0x696, 0x699, 0x3, 0x2, 0x2, 0x2, 0x697, 0x695, 0x3, 0x2, 
       0x2, 0x2, 0x697, 0x698, 0x3, 0x2, 0x2, 0x2, 0x698, 0x131, 0x3, 0x2, 
       0x2, 0x2, 0x699, 0x697, 0x3, 0x2, 0x2, 0x2, 0x69a, 0x69b, 0x7, 0x8a, 
       0x2, 0x2, 0x69b, 0x69c, 0x5, 0x136, 0x9c, 0x2, 0x69c, 0x133, 0x3, 
       0x2, 0x2, 0x2, 0x69d, 0x69e, 0x7, 0xa2, 0x2, 0x2, 0x69e, 0x6a0, 0x7, 
       0x8a, 0x2, 0x2, 0x69f, 0x69d, 0x3, 0x2, 0x2, 0x2, 0x6a0, 0x6a3, 0x3, 
       0x2, 0x2, 0x2, 0x6a1, 0x69f, 0x3, 0x2, 0x2, 0x2, 0x6a1, 0x6a2, 0x3, 
       0x2, 0x2, 0x2, 0x6a2, 0x6a4, 0x3, 0x2, 0x2, 0x2, 0x6a3, 0x6a1, 0x3, 
       0x2, 0x2, 0x2, 0x6a4, 0x6a5, 0x5, 0x136, 0x9c, 0x2, 0x6a5, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x6a6, 0x6a7, 0x5, 0x138, 0x9d, 0x2, 0x6a7, 0x6a8, 
       0x7, 0x8a, 0x2, 0x2, 0x6a8, 0x6aa, 0x3, 0x2, 0x2, 0x2, 0x6a9, 0x6a6, 
       0x3, 0x2, 0x2, 0x2, 0x6aa, 0x6ad, 0x3, 0x2, 0x2, 0x2, 0x6ab, 0x6a9, 
       0x3, 0x2, 0x2, 0x2, 0x6ab, 0x6ac, 0x3, 0x2, 0x2, 0x2, 0x6ac, 0x6ae, 
       0x3, 0x2, 0x2, 0x2, 0x6ad, 0x6ab, 0x3, 0x2, 0x2, 0x2, 0x6ae, 0x6af, 
       0x5, 0x202, 0x102, 0x2, 0x6af, 0x137, 0x3, 0x2, 0x2, 0x2, 0x6b0, 
       0x6b5, 0x5, 0x1e8, 0xf5, 0x2, 0x6b1, 0x6b2, 0x7, 0x80, 0x2, 0x2, 
       0x6b2, 0x6b3, 0x5, 0x13a, 0x9e, 0x2, 0x6b3, 0x6b4, 0x7, 0x81, 0x2, 
       0x2, 0x6b4, 0x6b6, 0x3, 0x2, 0x2, 0x2, 0x6b5, 0x6b1, 0x3, 0x2, 0x2, 
       0x2, 0x6b5, 0x6b6, 0x3, 0x2, 0x2, 0x2, 0x6b6, 0x139, 0x3, 0x2, 0x2, 
       0x2, 0x6b7, 0x6b8, 0x8, 0x9e, 0x1, 0x2, 0x6b8, 0x6b9, 0x7, 0xa6, 
       0x2, 0x2, 0x6b9, 0x6bc, 0x5, 0x13e, 0xa0, 0x2, 0x6ba, 0x6bc, 0x5, 
       0x13c, 0x9f, 0x2, 0x6bb, 0x6b7, 0x3, 0x2, 0x2, 0x2, 0x6bb, 0x6ba, 
       0x3, 0x2, 0x2, 0x2, 0x6bc, 0x6cb, 0x3, 0x2, 0x2, 0x2, 0x6bd, 0x6be, 
       0xc, 0x5, 0x2, 0x2, 0x6be, 0x6bf, 0x5, 0x144, 0xa3, 0x2, 0x6bf, 0x6c0, 
       0x5, 0x13a, 0x9e, 0x6, 0x6c0, 0x6ca, 0x3, 0x2, 0x2, 0x2, 0x6c1, 0x6c2, 
       0xc, 0x4, 0x2, 0x2, 0x6c2, 0x6c3, 0x5, 0x142, 0xa2, 0x2, 0x6c3, 0x6c4, 
       0x5, 0x13a, 0x9e, 0x5, 0x6c4, 0x6ca, 0x3, 0x2, 0x2, 0x2, 0x6c5, 0x6c6, 
       0xc, 0x3, 0x2, 0x2, 0x6c6, 0x6c7, 0x5, 0x140, 0xa1, 0x2, 0x6c7, 0x6c8, 
       0x5, 0x13a, 0x9e, 0x4, 0x6c8, 0x6ca, 0x3, 0x2, 0x2, 0x2, 0x6c9, 0x6bd, 
       0x3, 0x2, 0x2, 0x2, 0x6c9, 0x6c1, 0x3, 0x2, 0x2, 0x2, 0x6c9, 0x6c5, 
       0x3, 0x2, 0x2, 0x2, 0x6ca, 0x6cd, 0x3, 0x2, 0x2, 0x2, 0x6cb, 0x6c9, 
       0x3, 0x2, 0x2, 0x2, 0x6cb, 0x6cc, 0x3, 0x2, 0x2, 0x2, 0x6cc, 0x13b, 
       0x3, 0x2, 0x2, 0x2, 0x6cd, 0x6cb, 0x3, 0x2, 0x2, 0x2, 0x6ce, 0x6cf, 
       0x8, 0x9f, 0x1, 0x2, 0x6cf, 0x6d2, 0x5, 0x13e, 0xa0, 0x2, 0x6d0, 
       0x6d1, 0x7, 0x9f, 0x2, 0x2, 0x6d1, 0x6d3, 0x5, 0x13e, 0xa0, 0x2, 
       0x6d2, 0x6d0, 0x3, 0x2, 0x2, 0x2, 0x6d2, 0x6d3, 0x3, 0x2, 0x2, 0x2, 
       0x6d3, 0x6de, 0x3, 0x2, 0x2, 0x2, 0x6d4, 0x6d8, 0x7, 0x8, 0x2, 0x2, 
       0x6d5, 0x6d8, 0x7, 0x64, 0x2, 0x2, 0x6d6, 0x6d8, 0x5, 0x140, 0xa1, 
       0x2, 0x6d7, 0x6d4, 0x3, 0x2, 0x2, 0x2, 0x6d7, 0x6d5, 0x3, 0x2, 0x2, 
       0x2, 0x6d7, 0x6d6, 0x3, 0x2, 0x2, 0x2, 0x6d8, 0x6d9, 0x3, 0x2, 0x2, 
       0x2, 0x6d9, 0x6de, 0x5, 0x13c, 0x9f, 0x6, 0x6da, 0x6db, 0x5, 0x148, 
       0xa5, 0x2, 0x6db, 0x6dc, 0x5, 0x13c, 0x9f, 0x4, 0x6dc, 0x6de, 0x3, 
       0x2, 0x2, 0x2, 0x6dd, 0x6ce, 0x3, 0x2, 0x2, 0x2, 0x6dd, 0x6d7, 0x3, 
       0x2, 0x2, 0x2, 0x6dd, 0x6da, 0x3, 0x2, 0x2, 0x2, 0x6de, 0x6e9, 0x3, 
       0x2, 0x2, 0x2, 0x6df, 0x6e0, 0xc, 0x5, 0x2, 0x2, 0x6e0, 0x6e1, 0x5, 
       0x14a, 0xa6, 0x2, 0x6e1, 0x6e2, 0x5, 0x13c, 0x9f, 0x6, 0x6e2, 0x6e8, 
       0x3, 0x2, 0x2, 0x2, 0x6e3, 0x6e4, 0xc, 0x3, 0x2, 0x2, 0x6e4, 0x6e5, 
       0x5, 0x146, 0xa4, 0x2, 0x6e5, 0x6e6, 0x5, 0x13c, 0x9f, 0x4, 0x6e6, 
       0x6e8, 0x3, 0x2, 0x2, 0x2, 0x6e7, 0x6df, 0x3, 0x2, 0x2, 0x2, 0x6e7, 
       0x6e3, 0x3, 0x2, 0x2, 0x2, 0x6e8, 0x6eb, 0x3, 0x2, 0x2, 0x2, 0x6e9, 
       0x6e7, 0x3, 0x2, 0x2, 0x2, 0x6e9, 0x6ea, 0x3, 0x2, 0x2, 0x2, 0x6ea, 
       0x13d, 0x3, 0x2, 0x2, 0x2, 0x6eb, 0x6e9, 0x3, 0x2, 0x2, 0x2, 0x6ec, 
       0x6f3, 0x5, 0x14e, 0xa8, 0x2, 0x6ed, 0x6f3, 0x7, 0x74, 0x2, 0x2, 
       0x6ee, 0x6f3, 0x7, 0x6c, 0x2, 0x2, 0x6ef, 0x6f3, 0x5, 0x15c, 0xaf, 
       0x2, 0x6f0, 0x6f3, 0x5, 0x152, 0xaa, 0x2, 0x6f1, 0x6f3, 0x5, 0x15a, 
       0xae, 0x2, 0x6f2, 0x6ec, 0x3, 0x2, 0x2, 0x2, 0x6f2, 0x6ed, 0x3, 0x2, 
       0x2, 0x2, 0x6f2, 0x6ee, 0x3, 0x2, 0x2, 0x2, 0x6f2, 0x6ef, 0x3, 0x2, 
       0x2, 0x2, 0x6f2, 0x6f0, 0x3, 0x2, 0x2, 0x2, 0x6f2, 0x6f1, 0x3, 0x2, 
       0x2, 0x2, 0x6f3, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x6f4, 0x6f5, 0x9, 0xb, 
       0x2, 0x2, 0x6f5, 0x141, 0x3, 0x2, 0x2, 0x2, 0x6f6, 0x6f7, 0x9, 0xc, 
       0x2, 0x2, 0x6f7, 0x143, 0x3, 0x2, 0x2, 0x2, 0x6f8, 0x6f9, 0x9, 0xd, 
       0x2, 0x2, 0x6f9, 0x145, 0x3, 0x2, 0x2, 0x2, 0x6fa, 0x6fb, 0x9, 0xe, 
       0x2, 0x2, 0x6fb, 0x147, 0x3, 0x2, 0x2, 0x2, 0x6fc, 0x6fd, 0x9, 0xf, 
       0x2, 0x2, 0x6fd, 0x149, 0x3, 0x2, 0x2, 0x2, 0x6fe, 0x6ff, 0x9, 0x10, 
       0x2, 0x2, 0x6ff, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x700, 0x701, 0x9, 0x11, 
       0x2, 0x2, 0x701, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x702, 0x704, 0x7, 0x6f, 
       0x2, 0x2, 0x703, 0x705, 0x5, 0x6, 0x4, 0x2, 0x704, 0x703, 0x3, 0x2, 
       0x2, 0x2, 0x704, 0x705, 0x3, 0x2, 0x2, 0x2, 0x705, 0x70c, 0x3, 0x2, 
       0x2, 0x2, 0x706, 0x708, 0x7, 0x71, 0x2, 0x2, 0x707, 0x709, 0x5, 0x6, 
       0x4, 0x2, 0x708, 0x707, 0x3, 0x2, 0x2, 0x2, 0x708, 0x709, 0x3, 0x2, 
       0x2, 0x2, 0x709, 0x70c, 0x3, 0x2, 0x2, 0x2, 0x70a, 0x70c, 0x5, 0x6, 
       0x4, 0x2, 0x70b, 0x702, 0x3, 0x2, 0x2, 0x2, 0x70b, 0x706, 0x3, 0x2, 
       0x2, 0x2, 0x70b, 0x70a, 0x3, 0x2, 0x2, 0x2, 0x70c, 0x14f, 0x3, 0x2, 
       0x2, 0x2, 0x70d, 0x70f, 0x9, 0x12, 0x2, 0x2, 0x70e, 0x70d, 0x3, 0x2, 
       0x2, 0x2, 0x70e, 0x70f, 0x3, 0x2, 0x2, 0x2, 0x70f, 0x710, 0x3, 0x2, 
       0x2, 0x2, 0x710, 0x711, 0x5, 0x6, 0x4, 0x2, 0x711, 0x151, 0x3, 0x2, 
       0x2, 0x2, 0x712, 0x713, 0x7, 0x80, 0x2, 0x2, 0x713, 0x718, 0x5, 0x154, 
       0xab, 0x2, 0x714, 0x715, 0x7, 0x89, 0x2, 0x2, 0x715, 0x717, 0x5, 
       0x154, 0xab, 0x2, 0x716, 0x714, 0x3, 0x2, 0x2, 0x2, 0x717, 0x71a, 
       0x3, 0x2, 0x2, 0x2, 0x718, 0x716, 0x3, 0x2, 0x2, 0x2, 0x718, 0x719, 
       0x3, 0x2, 0x2, 0x2, 0x719, 0x71b, 0x3, 0x2, 0x2, 0x2, 0x71a, 0x718, 
       0x3, 0x2, 0x2, 0x2, 0x71b, 0x71c, 0x7, 0x81, 0x2, 0x2, 0x71c, 0x153, 
       0x3, 0x2, 0x2, 0x2, 0x71d, 0x71e, 0x5, 0x156, 0xac, 0x2, 0x71e, 0x71f, 
       0x7, 0xa5, 0x2, 0x2, 0x71f, 0x721, 0x3, 0x2, 0x2, 0x2, 0x720, 0x71d, 
       0x3, 0x2, 0x2, 0x2, 0x720, 0x721, 0x3, 0x2, 0x2, 0x2, 0x721, 0x722, 
       0x3, 0x2, 0x2, 0x2, 0x722, 0x723, 0x5, 0x13a, 0x9e, 0x2, 0x723, 0x155, 
       0x3, 0x2, 0x2, 0x2, 0x724, 0x729, 0x5, 0x158, 0xad, 0x2, 0x725, 0x726, 
       0x7, 0x9b, 0x2, 0x2, 0x726, 0x728, 0x5, 0x158, 0xad, 0x2, 0x727, 
       0x725, 0x3, 0x2, 0x2, 0x2, 0x728, 0x72b, 0x3, 0x2, 0x2, 0x2, 0x729, 
       0x727, 0x3, 0x2, 0x2, 0x2, 0x729, 0x72a, 0x3, 0x2, 0x2, 0x2, 0x72a, 
       0x157, 0x3, 0x2, 0x2, 0x2, 0x72b, 0x729, 0x3, 0x2, 0x2, 0x2, 0x72c, 
       0x730, 0x5, 0x72, 0x3a, 0x2, 0x72d, 0x730, 0x5, 0x13c, 0x9f, 0x2, 
       0x72e, 0x730, 0x7, 0x61, 0x2, 0x2, 0x72f, 0x72c, 0x3, 0x2, 0x2, 0x2, 
       0x72f, 0x72d, 0x3, 0x2, 0x2, 0x2, 0x72f, 0x72e, 0x3, 0x2, 0x2, 0x2, 
       0x730, 0x159, 0x3, 0x2, 0x2, 0x2, 0x731, 0x732, 0x5, 0xa2, 0x52, 
       0x2, 0x732, 0x733, 0x7, 0x84, 0x2, 0x2, 0x733, 0x734, 0x5, 0x152, 
       0xaa, 0x2, 0x734, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x735, 0x738, 0x7, 0x2f, 
       0x2, 0x2, 0x736, 0x739, 0x5, 0x96, 0x4c, 0x2, 0x737, 0x739, 0x5, 
       0x15a, 0xae, 0x2, 0x738, 0x736, 0x3, 0x2, 0x2, 0x2, 0x738, 0x737, 
       0x3, 0x2, 0x2, 0x2, 0x739, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x73a, 0x73c, 
       0x5, 0x160, 0xb1, 0x2, 0x73b, 0x73a, 0x3, 0x2, 0x2, 0x2, 0x73c, 0x73f, 
       0x3, 0x2, 0x2, 0x2, 0x73d, 0x73b, 0x3, 0x2, 0x2, 0x2, 0x73d, 0x73e, 
       0x3, 0x2, 0x2, 0x2, 0x73e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x73f, 0x73d, 
       0x3, 0x2, 0x2, 0x2, 0x740, 0x741, 0x5, 0x1e8, 0xf5, 0x2, 0x741, 0x742, 
       0x7, 0x8c, 0x2, 0x2, 0x742, 0x744, 0x3, 0x2, 0x2, 0x2, 0x743, 0x740, 
       0x3, 0x2, 0x2, 0x2, 0x743, 0x744, 0x3, 0x2, 0x2, 0x2, 0x744, 0x752, 
       0x3, 0x2, 0x2, 0x2, 0x745, 0x753, 0x5, 0x162, 0xb2, 0x2, 0x746, 0x753, 
       0x5, 0x16e, 0xb8, 0x2, 0x747, 0x753, 0x5, 0x172, 0xba, 0x2, 0x748, 
       0x753, 0x5, 0x174, 0xbb, 0x2, 0x749, 0x753, 0x5, 0x19c, 0xcf, 0x2, 
       0x74a, 0x753, 0x5, 0x1a4, 0xd3, 0x2, 0x74b, 0x753, 0x5, 0x1a8, 0xd5, 
       0x2, 0x74c, 0x753, 0x5, 0x1aa, 0xd6, 0x2, 0x74d, 0x753, 0x5, 0x1ae, 
       0xd8, 0x2, 0x74e, 0x753, 0x5, 0x1b4, 0xdb, 0x2, 0x74f, 0x753, 0x5, 
       0x1b6, 0xdc, 0x2, 0x750, 0x753, 0x5, 0x1b8, 0xdd, 0x2, 0x751, 0x753, 
       0x5, 0x1ba, 0xde, 0x2, 0x752, 0x745, 0x3, 0x2, 0x2, 0x2, 0x752, 0x746, 
       0x3, 0x2, 0x2, 0x2, 0x752, 0x747, 0x3, 0x2, 0x2, 0x2, 0x752, 0x748, 
       0x3, 0x2, 0x2, 0x2, 0x752, 0x749, 0x3, 0x2, 0x2, 0x2, 0x752, 0x74a, 
       0x3, 0x2, 0x2, 0x2, 0x752, 0x74b, 0x3, 0x2, 0x2, 0x2, 0x752, 0x74c, 
       0x3, 0x2, 0x2, 0x2, 0x752, 0x74d, 0x3, 0x2, 0x2, 0x2, 0x752, 0x74e, 
       0x3, 0x2, 0x2, 0x2, 0x752, 0x74f, 0x3, 0x2, 0x2, 0x2, 0x752, 0x750, 
       0x3, 0x2, 0x2, 0x2, 0x752, 0x751, 0x3, 0x2, 0x2, 0x2, 0x753, 0x161, 
       0x3, 0x2, 0x2, 0x2, 0x754, 0x756, 0x7, 0x4e, 0x2, 0x2, 0x755, 0x757, 
       0x5, 0x164, 0xb3, 0x2, 0x756, 0x755, 0x3, 0x2, 0x2, 0x2, 0x756, 0x757, 
       0x3, 0x2, 0x2, 0x2, 0x757, 0x759, 0x3, 0x2, 0x2, 0x2, 0x758, 0x75a, 
       0x5, 0x168, 0xb5, 0x2, 0x759, 0x758, 0x3, 0x2, 0x2, 0x2, 0x759, 0x75a, 
       0x3, 0x2, 0x2, 0x2, 0x75a, 0x75c, 0x3, 0x2, 0x2, 0x2, 0x75b, 0x75d, 
       0x5, 0x16c, 0xb7, 0x2, 0x75c, 0x75b, 0x3, 0x2, 0x2, 0x2, 0x75c, 0x75d, 
       0x3, 0x2, 0x2, 0x2, 0x75d, 0x75e, 0x3, 0x2, 0x2, 0x2, 0x75e, 0x75f, 
       0x7, 0x7f, 0x2, 0x2, 0x75f, 0x163, 0x3, 0x2, 0x2, 0x2, 0x760, 0x761, 
       0x7, 0x10, 0x2, 0x2, 0x761, 0x762, 0x5, 0x166, 0xb4, 0x2, 0x762, 
       0x165, 0x3, 0x2, 0x2, 0x2, 0x763, 0x768, 0x5, 0x6, 0x4, 0x2, 0x764, 
       0x765, 0x7, 0x89, 0x2, 0x2, 0x765, 0x767, 0x5, 0x6, 0x4, 0x2, 0x766, 
       0x764, 0x3, 0x2, 0x2, 0x2, 0x767, 0x76a, 0x3, 0x2, 0x2, 0x2, 0x768, 
       0x766, 0x3, 0x2, 0x2, 0x2, 0x768, 0x769, 0x3, 0x2, 0x2, 0x2, 0x769, 
       0x167, 0x3, 0x2, 0x2, 0x2, 0x76a, 0x768, 0x3, 0x2, 0x2, 0x2, 0x76b, 
       0x76c, 0x7, 0x4b, 0x2, 0x2, 0x76c, 0x76d, 0x5, 0x16a, 0xb6, 0x2, 
       0x76d, 0x169, 0x3, 0x2, 0x2, 0x2, 0x76e, 0x76f, 0x5, 0x13a, 0x9e, 
       0x2, 0x76f, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x770, 0x771, 0x7, 0x5a, 0x2, 
       0x2, 0x771, 0x772, 0x5, 0x13a, 0x9e, 0x2, 0x772, 0x16d, 0x3, 0x2, 
       0x2, 0x2, 0x773, 0x774, 0x5, 0x170, 0xb9, 0x2, 0x774, 0x775, 0x7, 
       0x7f, 0x2, 0x2, 0x775, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x776, 0x777, 0x7, 
       0x56, 0x2, 0x2, 0x777, 0x77a, 0x5, 0x16a, 0xb6, 0x2, 0x778, 0x779, 
       0x7, 0x30, 0x2, 0x2, 0x779, 0x77b, 0x5, 0x13a, 0x9e, 0x2, 0x77a, 
       0x778, 0x3, 0x2, 0x2, 0x2, 0x77a, 0x77b, 0x3, 0x2, 0x2, 0x2, 0x77b, 
       0x77e, 0x3, 0x2, 0x2, 0x2, 0x77c, 0x77d, 0x7, 0x58, 0x2, 0x2, 0x77d, 
       0x77f, 0x5, 0x13a, 0x9e, 0x2, 0x77e, 0x77c, 0x3, 0x2, 0x2, 0x2, 0x77e, 
       0x77f, 0x3, 0x2, 0x2, 0x2, 0x77f, 0x171, 0x3, 0x2, 0x2, 0x2, 0x780, 
       0x781, 0x7, 0x30, 0x2, 0x2, 0x781, 0x784, 0x5, 0x13a, 0x9e, 0x2, 
       0x782, 0x783, 0x7, 0x58, 0x2, 0x2, 0x783, 0x785, 0x5, 0x13a, 0x9e, 
       0x2, 0x784, 0x782, 0x3, 0x2, 0x2, 0x2, 0x784, 0x785, 0x3, 0x2, 0x2, 
       0x2, 0x785, 0x786, 0x3, 0x2, 0x2, 0x2, 0x786, 0x787, 0x7, 0x7f, 0x2, 
       0x2, 0x787, 0x173, 0x3, 0x2, 0x2, 0x2, 0x788, 0x78c, 0x5, 0x176, 
       0xbc, 0x2, 0x789, 0x78c, 0x5, 0x188, 0xc5, 0x2, 0x78a, 0x78c, 0x5, 
       0x192, 0xca, 0x2, 0x78b, 0x788, 0x3, 0x2, 0x2, 0x2, 0x78b, 0x789, 
       0x3, 0x2, 0x2, 0x2, 0x78b, 0x78a, 0x3, 0x2, 0x2, 0x2, 0x78c, 0x175, 
       0x3, 0x2, 0x2, 0x2, 0x78d, 0x791, 0x5, 0x178, 0xbd, 0x2, 0x78e, 0x791, 
       0x5, 0x17a, 0xbe, 0x2, 0x78f, 0x791, 0x5, 0x17c, 0xbf, 0x2, 0x790, 
       0x78d, 0x3, 0x2, 0x2, 0x2, 0x790, 0x78e, 0x3, 0x2, 0x2, 0x2, 0x790, 
       0x78f, 0x3, 0x2, 0x2, 0x2, 0x791, 0x177, 0x3, 0x2, 0x2, 0x2, 0x792, 
       0x793, 0x5, 0x182, 0xc2, 0x2, 0x793, 0x795, 0x7, 0xa0, 0x2, 0x2, 
       0x794, 0x796, 0x5, 0x180, 0xc1, 0x2, 0x795, 0x794, 0x3, 0x2, 0x2, 
       0x2, 0x795, 0x796, 0x3, 0x2, 0x2, 0x2, 0x796, 0x797, 0x3, 0x2, 0x2, 
       0x2, 0x797, 0x798, 0x5, 0x184, 0xc3, 0x2, 0x798, 0x799, 0x7, 0x7f, 
       0x2, 0x2, 0x799, 0x179, 0x3, 0x2, 0x2, 0x2, 0x79a, 0x79b, 0x5, 0x182, 
       0xc2, 0x2, 0x79b, 0x79c, 0x7, 0xa0, 0x2, 0x2, 0x79c, 0x79e, 0x7, 
       0x51, 0x2, 0x2, 0x79d, 0x79f, 0x5, 0x17e, 0xc0, 0x2, 0x79e, 0x79d, 
       0x3, 0x2, 0x2, 0x2, 0x79e, 0x79f, 0x3, 0x2, 0x2, 0x2, 0x79f, 0x7a0, 
       0x3, 0x2, 0x2, 0x2, 0x7a0, 0x7a1, 0x5, 0x13a, 0x9e, 0x2, 0x7a1, 0x7a2, 
       0x7, 0x7f, 0x2, 0x2, 0x7a2, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x7a3, 0x7a4, 
       0x5, 0x182, 0xc2, 0x2, 0x7a4, 0x7a5, 0x7, 0xa0, 0x2, 0x2, 0x7a5, 
       0x7a7, 0x7, 0x47, 0x2, 0x2, 0x7a6, 0x7a8, 0x5, 0x17e, 0xc0, 0x2, 
       0x7a7, 0x7a6, 0x3, 0x2, 0x2, 0x2, 0x7a7, 0x7a8, 0x3, 0x2, 0x2, 0x2, 
       0x7a8, 0x7a9, 0x3, 0x2, 0x2, 0x2, 0x7a9, 0x7aa, 0x7, 0x7f, 0x2, 0x2, 
       0x7aa, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x7ab, 0x7ac, 0x9, 0x7, 0x2, 0x2, 
       0x7ac, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x7ad, 0x7b4, 0x7, 0x35, 0x2, 0x2, 
       0x7ae, 0x7af, 0x7, 0x1f, 0x2, 0x2, 0x7af, 0x7b1, 0x5, 0x13a, 0x9e, 
       0x2, 0x7b0, 0x7ae, 0x3, 0x2, 0x2, 0x2, 0x7b0, 0x7b1, 0x3, 0x2, 0x2, 
       0x2, 0x7b1, 0x7b2, 0x3, 0x2, 0x2, 0x2, 0x7b2, 0x7b4, 0x7, 0xd, 0x2, 
       0x2, 0x7b3, 0x7ad, 0x3, 0x2, 0x2, 0x2, 0x7b3, 0x7b0, 0x3, 0x2, 0x2, 
       0x2, 0x7b4, 0x181, 0x3, 0x2, 0x2, 0x2, 0x7b5, 0x7b8, 0x5, 0x6, 0x4, 
       0x2, 0x7b6, 0x7b8, 0x5, 0x152, 0xaa, 0x2, 0x7b7, 0x7b5, 0x3, 0x2, 
       0x2, 0x2, 0x7b7, 0x7b6, 0x3, 0x2, 0x2, 0x2, 0x7b8, 0x183, 0x3, 0x2, 
       0x2, 0x2, 0x7b9, 0x7be, 0x5, 0x186, 0xc4, 0x2, 0x7ba, 0x7bb, 0x7, 
       0x89, 0x2, 0x2, 0x7bb, 0x7bd, 0x5, 0x186, 0xc4, 0x2, 0x7bc, 0x7ba, 
       0x3, 0x2, 0x2, 0x2, 0x7bd, 0x7c0, 0x3, 0x2, 0x2, 0x2, 0x7be, 0x7bc, 
       0x3, 0x2, 0x2, 0x2, 0x7be, 0x7bf, 0x3, 0x2, 0x2, 0x2, 0x7bf, 0x7c3, 
       0x3, 0x2, 0x2, 0x2, 0x7c0, 0x7be, 0x3, 0x2, 0x2, 0x2, 0x7c1, 0x7c3, 
       0x7, 0x2a, 0x2, 0x2, 0x7c2, 0x7b9, 0x3, 0x2, 0x2, 0x2, 0x7c2, 0x7c1, 
       0x3, 0x2, 0x2, 0x2, 0x7c3, 0x185, 0x3, 0x2, 0x2, 0x2, 0x7c4, 0x7c7, 
       0x5, 0x13a, 0x9e, 0x2, 0x7c5, 0x7c6, 0x7, 0x34, 0x2, 0x2, 0x7c6, 
       0x7c8, 0x5, 0x13a, 0x9e, 0x2, 0x7c7, 0x7c5, 0x3, 0x2, 0x2, 0x2, 0x7c7, 
       0x7c8, 0x3, 0x2, 0x2, 0x2, 0x7c8, 0x7cf, 0x3, 0x2, 0x2, 0x2, 0x7c9, 
       0x7cc, 0x7, 0x6c, 0x2, 0x2, 0x7ca, 0x7cb, 0x7, 0x34, 0x2, 0x2, 0x7cb, 
       0x7cd, 0x5, 0x13a, 0x9e, 0x2, 0x7cc, 0x7ca, 0x3, 0x2, 0x2, 0x2, 0x7cc, 
       0x7cd, 0x3, 0x2, 0x2, 0x2, 0x7cd, 0x7cf, 0x3, 0x2, 0x2, 0x2, 0x7ce, 
       0x7c4, 0x3, 0x2, 0x2, 0x2, 0x7ce, 0x7c9, 0x3, 0x2, 0x2, 0x2, 0x7cf, 
       0x187, 0x3, 0x2, 0x2, 0x2, 0x7d0, 0x7d3, 0x5, 0x18a, 0xc6, 0x2, 0x7d1, 
       0x7d3, 0x5, 0x18e, 0xc8, 0x2, 0x7d2, 0x7d0, 0x3, 0x2, 0x2, 0x2, 0x7d2, 
       0x7d1, 0x3, 0x2, 0x2, 0x2, 0x7d3, 0x189, 0x3, 0x2, 0x2, 0x2, 0x7d4, 
       0x7d5, 0x5, 0x182, 0xc2, 0x2, 0x7d5, 0x7d7, 0x7, 0xa0, 0x2, 0x2, 
       0x7d6, 0x7d8, 0x5, 0x180, 0xc1, 0x2, 0x7d7, 0x7d6, 0x3, 0x2, 0x2, 
       0x2, 0x7d7, 0x7d8, 0x3, 0x2, 0x2, 0x2, 0x7d8, 0x7d9, 0x3, 0x2, 0x2, 
       0x2, 0x7d9, 0x7da, 0x5, 0x18c, 0xc7, 0x2, 0x7da, 0x7db, 0x7, 0x7f, 
       0x2, 0x2, 0x7db, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x7dc, 0x7dd, 0x5, 0x184, 
       0xc3, 0x2, 0x7dd, 0x7de, 0x7, 0x6a, 0x2, 0x2, 0x7de, 0x7e6, 0x5, 
       0x16a, 0xb6, 0x2, 0x7df, 0x7e0, 0x7, 0x18, 0x2, 0x2, 0x7e0, 0x7e1, 
       0x5, 0x184, 0xc3, 0x2, 0x7e1, 0x7e2, 0x7, 0x6a, 0x2, 0x2, 0x7e2, 
       0x7e3, 0x5, 0x16a, 0xb6, 0x2, 0x7e3, 0x7e5, 0x3, 0x2, 0x2, 0x2, 0x7e4, 
       0x7df, 0x3, 0x2, 0x2, 0x2, 0x7e5, 0x7e8, 0x3, 0x2, 0x2, 0x2, 0x7e6, 
       0x7e4, 0x3, 0x2, 0x2, 0x2, 0x7e6, 0x7e7, 0x3, 0x2, 0x2, 0x2, 0x7e7, 
       0x7ec, 0x3, 0x2, 0x2, 0x2, 0x7e8, 0x7e6, 0x3, 0x2, 0x2, 0x2, 0x7e9, 
       0x7ea, 0x7, 0x18, 0x2, 0x2, 0x7ea, 0x7ed, 0x5, 0x184, 0xc3, 0x2, 
       0x7eb, 0x7ed, 0x6, 0xc7, 0x8, 0x2, 0x7ec, 0x7e9, 0x3, 0x2, 0x2, 0x2, 
       0x7ec, 0x7eb, 0x3, 0x2, 0x2, 0x2, 0x7ed, 0x18d, 0x3, 0x2, 0x2, 0x2, 
       0x7ee, 0x7ef, 0x5, 0x182, 0xc2, 0x2, 0x7ef, 0x7f0, 0x7, 0xa0, 0x2, 
       0x2, 0x7f0, 0x7f2, 0x7, 0x51, 0x2, 0x2, 0x7f1, 0x7f3, 0x5, 0x17e, 
       0xc0, 0x2, 0x7f2, 0x7f1, 0x3, 0x2, 0x2, 0x2, 0x7f2, 0x7f3, 0x3, 0x2, 
       0x2, 0x2, 0x7f3, 0x7f4, 0x3, 0x2, 0x2, 0x2, 0x7f4, 0x7f5, 0x5, 0x190, 
       0xc9, 0x2, 0x7f5, 0x7f6, 0x7, 0x7f, 0x2, 0x2, 0x7f6, 0x18f, 0x3, 
       0x2, 0x2, 0x2, 0x7f7, 0x7f8, 0x5, 0x13a, 0x9e, 0x2, 0x7f8, 0x7f9, 
       0x7, 0x6a, 0x2, 0x2, 0x7f9, 0x801, 0x5, 0x16a, 0xb6, 0x2, 0x7fa, 
       0x7fb, 0x7, 0x18, 0x2, 0x2, 0x7fb, 0x7fc, 0x5, 0x13a, 0x9e, 0x2, 
       0x7fc, 0x7fd, 0x7, 0x6a, 0x2, 0x2, 0x7fd, 0x7fe, 0x5, 0x16a, 0xb6, 
       0x2, 0x7fe, 0x800, 0x3, 0x2, 0x2, 0x2, 0x7ff, 0x7fa, 0x3, 0x2, 0x2, 
       0x2, 0x800, 0x803, 0x3, 0x2, 0x2, 0x2, 0x801, 0x7ff, 0x3, 0x2, 0x2, 
       0x2, 0x801, 0x802, 0x3, 0x2, 0x2, 0x2, 0x802, 0x807, 0x3, 0x2, 0x2, 
       0x2, 0x803, 0x801, 0x3, 0x2, 0x2, 0x2, 0x804, 0x805, 0x7, 0x18, 0x2, 
       0x2, 0x805, 0x808, 0x5, 0x13a, 0x9e, 0x2, 0x806, 0x808, 0x6, 0xc9, 
       0x9, 0x2, 0x807, 0x804, 0x3, 0x2, 0x2, 0x2, 0x807, 0x806, 0x3, 0x2, 
       0x2, 0x2, 0x808, 0x191, 0x3, 0x2, 0x2, 0x2, 0x809, 0x80c, 0x5, 0x194, 
       0xcb, 0x2, 0x80a, 0x80c, 0x5, 0x198, 0xcd, 0x2, 0x80b, 0x809, 0x3, 
       0x2, 0x2, 0x2, 0x80b, 0x80a, 0x3, 0x2, 0x2, 0x2, 0x80c, 0x193, 0x3, 
       0x2, 0x2, 0x2, 0x80d, 0x80e, 0x7, 0x4a, 0x2, 0x2, 0x80e, 0x80f, 0x5, 
       0x13a, 0x9e, 0x2, 0x80f, 0x811, 0x7, 0x38, 0x2, 0x2, 0x810, 0x812, 
       0x7, 0x8b, 0x2, 0x2, 0x811, 0x810, 0x3, 0x2, 0x2, 0x2, 0x811, 0x812, 
       0x3, 0x2, 0x2, 0x2, 0x812, 0x813, 0x3, 0x2, 0x2, 0x2, 0x813, 0x814, 
       0x5, 0x182, 0xc2, 0x2, 0x814, 0x816, 0x7, 0xa0, 0x2, 0x2, 0x815, 
       0x817, 0x5, 0x180, 0xc1, 0x2, 0x816, 0x815, 0x3, 0x2, 0x2, 0x2, 0x816, 
       0x817, 0x3, 0x2, 0x2, 0x2, 0x817, 0x818, 0x3, 0x2, 0x2, 0x2, 0x818, 
       0x819, 0x5, 0x196, 0xcc, 0x2, 0x819, 0x81a, 0x7, 0x7f, 0x2, 0x2, 
       0x81a, 0x195, 0x3, 0x2, 0x2, 0x2, 0x81b, 0x81c, 0x5, 0x184, 0xc3, 
       0x2, 0x81c, 0x81d, 0x7, 0x6a, 0x2, 0x2, 0x81d, 0x825, 0x5, 0x156, 
       0xac, 0x2, 0x81e, 0x81f, 0x7, 0x89, 0x2, 0x2, 0x81f, 0x820, 0x5, 
       0x184, 0xc3, 0x2, 0x820, 0x821, 0x7, 0x6a, 0x2, 0x2, 0x821, 0x822, 
       0x5, 0x156, 0xac, 0x2, 0x822, 0x824, 0x3, 0x2, 0x2, 0x2, 0x823, 0x81e, 
       0x3, 0x2, 0x2, 0x2, 0x824, 0x827, 0x3, 0x2, 0x2, 0x2, 0x825, 0x823, 
       0x3, 0x2, 0x2, 0x2, 0x825, 0x826, 0x3, 0x2, 0x2, 0x2, 0x826, 0x197, 
       0x3, 0x2, 0x2, 0x2, 0x827, 0x825, 0x3, 0x2, 0x2, 0x2, 0x828, 0x829, 
       0x7, 0x4a, 0x2, 0x2, 0x829, 0x82a, 0x5, 0x13a, 0x9e, 0x2, 0x82a, 
       0x82c, 0x7, 0x38, 0x2, 0x2, 0x82b, 0x82d, 0x7, 0x8b, 0x2, 0x2, 0x82c, 
       0x82b, 0x3, 0x2, 0x2, 0x2, 0x82c, 0x82d, 0x3, 0x2, 0x2, 0x2, 0x82d, 
       0x82e, 0x3, 0x2, 0x2, 0x2, 0x82e, 0x82f, 0x5, 0x182, 0xc2, 0x2, 0x82f, 
       0x830, 0x7, 0xa0, 0x2, 0x2, 0x830, 0x832, 0x7, 0x51, 0x2, 0x2, 0x831, 
       0x833, 0x5, 0x17e, 0xc0, 0x2, 0x832, 0x831, 0x3, 0x2, 0x2, 0x2, 0x832, 
       0x833, 0x3, 0x2, 0x2, 0x2, 0x833, 0x834, 0x3, 0x2, 0x2, 0x2, 0x834, 
       0x835, 0x5, 0x19a, 0xce, 0x2, 0x835, 0x836, 0x7, 0x7f, 0x2, 0x2, 
       0x836, 0x199, 0x3, 0x2, 0x2, 0x2, 0x837, 0x838, 0x5, 0x13a, 0x9e, 
       0x2, 0x838, 0x839, 0x7, 0x6a, 0x2, 0x2, 0x839, 0x841, 0x5, 0x156, 
       0xac, 0x2, 0x83a, 0x83b, 0x7, 0x89, 0x2, 0x2, 0x83b, 0x83c, 0x5, 
       0x13a, 0x9e, 0x2, 0x83c, 0x83d, 0x7, 0x6a, 0x2, 0x2, 0x83d, 0x83e, 
       0x5, 0x156, 0xac, 0x2, 0x83e, 0x840, 0x3, 0x2, 0x2, 0x2, 0x83f, 0x83a, 
       0x3, 0x2, 0x2, 0x2, 0x840, 0x843, 0x3, 0x2, 0x2, 0x2, 0x841, 0x83f, 
       0x3, 0x2, 0x2, 0x2, 0x841, 0x842, 0x3, 0x2, 0x2, 0x2, 0x842, 0x19b, 
       0x3, 0x2, 0x2, 0x2, 0x843, 0x841, 0x3, 0x2, 0x2, 0x2, 0x844, 0x848, 
       0x5, 0x19e, 0xd0, 0x2, 0x845, 0x848, 0x5, 0x1a0, 0xd1, 0x2, 0x846, 
       0x848, 0x5, 0x1a2, 0xd2, 0x2, 0x847, 0x844, 0x3, 0x2, 0x2, 0x2, 0x847, 
       0x845, 0x3, 0x2, 0x2, 0x2, 0x847, 0x846, 0x3, 0x2, 0x2, 0x2, 0x848, 
       0x19d, 0x3, 0x2, 0x2, 0x2, 0x849, 0x84a, 0x5, 0x182, 0xc2, 0x2, 0x84a, 
       0x84b, 0x7, 0xa3, 0x2, 0x2, 0x84b, 0x84c, 0x5, 0x13a, 0x9e, 0x2, 
       0x84c, 0x84d, 0x7, 0x7f, 0x2, 0x2, 0x84d, 0x19f, 0x3, 0x2, 0x2, 0x2, 
       0x84e, 0x84f, 0x5, 0x182, 0xc2, 0x2, 0x84f, 0x850, 0x7, 0xa3, 0x2, 
       0x2, 0x850, 0x851, 0x5, 0x190, 0xc9, 0x2, 0x851, 0x852, 0x7, 0x7f, 
       0x2, 0x2, 0x852, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x853, 0x854, 0x7, 0x4a, 
       0x2, 0x2, 0x854, 0x855, 0x5, 0x13a, 0x9e, 0x2, 0x855, 0x857, 0x7, 
       0x38, 0x2, 0x2, 0x856, 0x858, 0x7, 0x8b, 0x2, 0x2, 0x857, 0x856, 
       0x3, 0x2, 0x2, 0x2, 0x857, 0x858, 0x3, 0x2, 0x2, 0x2, 0x858, 0x859, 
       0x3, 0x2, 0x2, 0x2, 0x859, 0x85a, 0x5, 0x182, 0xc2, 0x2, 0x85a, 0x85b, 
       0x7, 0xa3, 0x2, 0x2, 0x85b, 0x85c, 0x5, 0x19a, 0xce, 0x2, 0x85c, 
       0x85d, 0x7, 0x7f, 0x2, 0x2, 0x85d, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x85e, 
       0x85f, 0x5, 0x1a6, 0xd4, 0x2, 0x85f, 0x860, 0x7, 0x7f, 0x2, 0x2, 
       0x860, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x861, 0x862, 0x5, 0x6, 0x4, 0x2, 
       0x862, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x863, 0x864, 0x7, 0x5c, 0x2, 0x2, 
       0x864, 0x865, 0x5, 0x16a, 0xb6, 0x2, 0x865, 0x866, 0x7, 0xa, 0x2, 
       0x2, 0x866, 0x86e, 0x5, 0x15e, 0xb0, 0x2, 0x867, 0x868, 0x7, 0x3b, 
       0x2, 0x2, 0x868, 0x869, 0x5, 0x16a, 0xb6, 0x2, 0x869, 0x86a, 0x7, 
       0xa, 0x2, 0x2, 0x86a, 0x86b, 0x5, 0x15e, 0xb0, 0x2, 0x86b, 0x86d, 
       0x3, 0x2, 0x2, 0x2, 0x86c, 0x867, 0x3, 0x2, 0x2, 0x2, 0x86d, 0x870, 
       0x3, 0x2, 0x2, 0x2, 0x86e, 0x86c, 0x3, 0x2, 0x2, 0x2, 0x86e, 0x86f, 
       0x3, 0x2, 0x2, 0x2, 0x86f, 0x875, 0x3, 0x2, 0x2, 0x2, 0x870, 0x86e, 
       0x3, 0x2, 0x2, 0x2, 0x871, 0x872, 0x7, 0x18, 0x2, 0x2, 0x872, 0x876, 
       0x5, 0x15e, 0xb0, 0x2, 0x873, 0x876, 0x3, 0x2, 0x2, 0x2, 0x874, 0x876, 
       0x6, 0xd5, 0xa, 0x2, 0x875, 0x871, 0x3, 0x2, 0x2, 0x2, 0x875, 0x873, 
       0x3, 0x2, 0x2, 0x2, 0x875, 0x874, 0x3, 0x2, 0x2, 0x2, 0x876, 0x877, 
       0x3, 0x2, 0x2, 0x2, 0x877, 0x878, 0x7, 0x37, 0x2, 0x2, 0x878, 0x87a, 
       0x7, 0x5c, 0x2, 0x2, 0x879, 0x87b, 0x5, 0x1e8, 0xf5, 0x2, 0x87a, 
       0x879, 0x3, 0x2, 0x2, 0x2, 0x87a, 0x87b, 0x3, 0x2, 0x2, 0x2, 0x87b, 
       0x87c, 0x3, 0x2, 0x2, 0x2, 0x87c, 0x87d, 0x7, 0x7f, 0x2, 0x2, 0x87d, 
       0x1a9, 0x3, 0x2, 0x2, 0x2, 0x87e, 0x880, 0x7, 0x63, 0x2, 0x2, 0x87f, 
       0x881, 0x7, 0x8b, 0x2, 0x2, 0x880, 0x87f, 0x3, 0x2, 0x2, 0x2, 0x880, 
       0x881, 0x3, 0x2, 0x2, 0x2, 0x881, 0x882, 0x3, 0x2, 0x2, 0x2, 0x882, 
       0x883, 0x5, 0x13a, 0x9e, 0x2, 0x883, 0x885, 0x7, 0x5f, 0x2, 0x2, 
       0x884, 0x886, 0x5, 0x1ac, 0xd7, 0x2, 0x885, 0x884, 0x3, 0x2, 0x2, 
       0x2, 0x886, 0x887, 0x3, 0x2, 0x2, 0x2, 0x887, 0x885, 0x3, 0x2, 0x2, 
       0x2, 0x887, 0x888, 0x3, 0x2, 0x2, 0x2, 0x888, 0x889, 0x3, 0x2, 0x2, 
       0x2, 0x889, 0x88a, 0x7, 0x37, 0x2, 0x2, 0x88a, 0x88c, 0x7, 0x63, 
       0x2, 0x2, 0x88b, 0x88d, 0x7, 0x8b, 0x2, 0x2, 0x88c, 0x88b, 0x3, 0x2, 
       0x2, 0x2, 0x88c, 0x88d, 0x3, 0x2, 0x2, 0x2, 0x88d, 0x88f, 0x3, 0x2, 
       0x2, 0x2, 0x88e, 0x890, 0x5, 0x1e8, 0xf5, 0x2, 0x88f, 0x88e, 0x3, 
       0x2, 0x2, 0x2, 0x88f, 0x890, 0x3, 0x2, 0x2, 0x2, 0x890, 0x891, 0x3, 
       0x2, 0x2, 0x2, 0x891, 0x892, 0x7, 0x7f, 0x2, 0x2, 0x892, 0x1ab, 0x3, 
       0x2, 0x2, 0x2, 0x893, 0x894, 0x7, 0x6a, 0x2, 0x2, 0x894, 0x895, 0x5, 
       0x156, 0xac, 0x2, 0x895, 0x896, 0x7, 0xa5, 0x2, 0x2, 0x896, 0x897, 
       0x5, 0x15e, 0xb0, 0x2, 0x897, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x898, 0x89a, 
       0x5, 0x1b0, 0xd9, 0x2, 0x899, 0x898, 0x3, 0x2, 0x2, 0x2, 0x899, 0x89a, 
       0x3, 0x2, 0x2, 0x2, 0x89a, 0x89b, 0x3, 0x2, 0x2, 0x2, 0x89b, 0x89c, 
       0x7, 0x1c, 0x2, 0x2, 0x89c, 0x89d, 0x5, 0x15e, 0xb0, 0x2, 0x89d, 
       0x89e, 0x7, 0x37, 0x2, 0x2, 0x89e, 0x8a0, 0x7, 0x1c, 0x2, 0x2, 0x89f, 
       0x8a1, 0x5, 0x1e8, 0xf5, 0x2, 0x8a0, 0x89f, 0x3, 0x2, 0x2, 0x2, 0x8a0, 
       0x8a1, 0x3, 0x2, 0x2, 0x2, 0x8a1, 0x8a2, 0x3, 0x2, 0x2, 0x2, 0x8a2, 
       0x8a3, 0x7, 0x7f, 0x2, 0x2, 0x8a3, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x8a4, 
       0x8a5, 0x7, 0x52, 0x2, 0x2, 0x8a5, 0x8a9, 0x5, 0x16a, 0xb6, 0x2, 
       0x8a6, 0x8a7, 0x7, 0x5a, 0x2, 0x2, 0x8a7, 0x8a9, 0x5, 0x1b2, 0xda, 
       0x2, 0x8a8, 0x8a4, 0x3, 0x2, 0x2, 0x2, 0x8a8, 0x8a6, 0x3, 0x2, 0x2, 
       0x2, 0x8a9, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x8aa, 0x8ab, 0x5, 0x202, 
       0x102, 0x2, 0x8ab, 0x8ac, 0x7, 0x46, 0x2, 0x2, 0x8ac, 0x8ad, 0x5, 
       0x72, 0x3a, 0x2, 0x8ad, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x8ae, 0x8b0, 
       0x7, 0xe, 0x2, 0x2, 0x8af, 0x8b1, 0x5, 0x1e8, 0xf5, 0x2, 0x8b0, 0x8af, 
       0x3, 0x2, 0x2, 0x2, 0x8b0, 0x8b1, 0x3, 0x2, 0x2, 0x2, 0x8b1, 0x8b4, 
       0x3, 0x2, 0x2, 0x2, 0x8b2, 0x8b3, 0x7, 0x6a, 0x2, 0x2, 0x8b3, 0x8b5, 
       0x5, 0x16a, 0xb6, 0x2, 0x8b4, 0x8b2, 0x3, 0x2, 0x2, 0x2, 0x8b4, 0x8b5, 
       0x3, 0x2, 0x2, 0x2, 0x8b5, 0x8b6, 0x3, 0x2, 0x2, 0x2, 0x8b6, 0x8b7, 
       0x7, 0x7f, 0x2, 0x2, 0x8b7, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x8b8, 0x8ba, 
       0x7, 0x48, 0x2, 0x2, 0x8b9, 0x8bb, 0x5, 0x1e8, 0xf5, 0x2, 0x8ba, 
       0x8b9, 0x3, 0x2, 0x2, 0x2, 0x8ba, 0x8bb, 0x3, 0x2, 0x2, 0x2, 0x8bb, 
       0x8be, 0x3, 0x2, 0x2, 0x2, 0x8bc, 0x8bd, 0x7, 0x6a, 0x2, 0x2, 0x8bd, 
       0x8bf, 0x5, 0x16a, 0xb6, 0x2, 0x8be, 0x8bc, 0x3, 0x2, 0x2, 0x2, 0x8be, 
       0x8bf, 0x3, 0x2, 0x2, 0x2, 0x8bf, 0x8c0, 0x3, 0x2, 0x2, 0x2, 0x8c0, 
       0x8c1, 0x7, 0x7f, 0x2, 0x2, 0x8c1, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x8c2, 
       0x8c4, 0x7, 0x49, 0x2, 0x2, 0x8c3, 0x8c5, 0x5, 0x13a, 0x9e, 0x2, 
       0x8c4, 0x8c3, 0x3, 0x2, 0x2, 0x2, 0x8c4, 0x8c5, 0x3, 0x2, 0x2, 0x2, 
       0x8c5, 0x8c6, 0x3, 0x2, 0x2, 0x2, 0x8c6, 0x8c7, 0x7, 0x7f, 0x2, 0x2, 
       0x8c7, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x8c8, 0x8c9, 0x7, 0x6c, 0x2, 0x2, 
       0x8c9, 0x8ca, 0x7, 0x7f, 0x2, 0x2, 0x8ca, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
       0x8cb, 0x8d0, 0x5, 0x1c4, 0xe3, 0x2, 0x8cc, 0x8d0, 0x5, 0x1cc, 0xe7, 
       0x2, 0x8cd, 0x8d0, 0x5, 0x1ce, 0xe8, 0x2, 0x8ce, 0x8d0, 0x5, 0x1d0, 
       0xe9, 0x2, 0x8cf, 0x8cb, 0x3, 0x2, 0x2, 0x2, 0x8cf, 0x8cc, 0x3, 0x2, 
       0x2, 0x2, 0x8cf, 0x8cd, 0x3, 0x2, 0x2, 0x2, 0x8cf, 0x8ce, 0x3, 0x2, 
       0x2, 0x2, 0x8d0, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x8d1, 0x8d2, 0x5, 0x1e8, 
       0xf5, 0x2, 0x8d2, 0x8d7, 0x7, 0x8c, 0x2, 0x2, 0x8d3, 0x8d8, 0x5, 
       0x1c0, 0xe1, 0x2, 0x8d4, 0x8d8, 0x5, 0x1d6, 0xec, 0x2, 0x8d5, 0x8d8, 
       0x5, 0x1da, 0xee, 0x2, 0x8d6, 0x8d8, 0x5, 0x1bc, 0xdf, 0x2, 0x8d7, 
       0x8d3, 0x3, 0x2, 0x2, 0x2, 0x8d7, 0x8d4, 0x3, 0x2, 0x2, 0x2, 0x8d7, 
       0x8d5, 0x3, 0x2, 0x2, 0x2, 0x8d7, 0x8d6, 0x3, 0x2, 0x2, 0x2, 0x8d8, 
       0x8db, 0x3, 0x2, 0x2, 0x2, 0x8d9, 0x8db, 0x5, 0x1bc, 0xdf, 0x2, 0x8da, 
       0x8d1, 0x3, 0x2, 0x2, 0x2, 0x8da, 0x8d9, 0x3, 0x2, 0x2, 0x2, 0x8db, 
       0x1bf, 0x3, 0x2, 0x2, 0x2, 0x8dc, 0x8e1, 0x7, 0xb, 0x2, 0x2, 0x8dd, 
       0x8de, 0x7, 0x80, 0x2, 0x2, 0x8de, 0x8df, 0x5, 0x16a, 0xb6, 0x2, 
       0x8df, 0x8e0, 0x7, 0x81, 0x2, 0x2, 0x8e0, 0x8e2, 0x3, 0x2, 0x2, 0x2, 
       0x8e1, 0x8dd, 0x3, 0x2, 0x2, 0x2, 0x8e1, 0x8e2, 0x3, 0x2, 0x2, 0x2, 
       0x8e2, 0x8e4, 0x3, 0x2, 0x2, 0x2, 0x8e3, 0x8e5, 0x7, 0x5f, 0x2, 0x2, 
       0x8e4, 0x8e3, 0x3, 0x2, 0x2, 0x2, 0x8e4, 0x8e5, 0x3, 0x2, 0x2, 0x2, 
       0x8e5, 0x8e6, 0x3, 0x2, 0x2, 0x2, 0x8e6, 0x8ea, 0x5, 0x1c2, 0xe2, 
       0x2, 0x8e7, 0x8e9, 0x5, 0x1c, 0xf, 0x2, 0x8e8, 0x8e7, 0x3, 0x2, 0x2, 
       0x2, 0x8e9, 0x8ec, 0x3, 0x2, 0x2, 0x2, 0x8ea, 0x8e8, 0x3, 0x2, 0x2, 
       0x2, 0x8ea, 0x8eb, 0x3, 0x2, 0x2, 0x2, 0x8eb, 0x8ed, 0x3, 0x2, 0x2, 
       0x2, 0x8ec, 0x8ea, 0x3, 0x2, 0x2, 0x2, 0x8ed, 0x8f1, 0x7, 0x20, 0x2, 
       0x2, 0x8ee, 0x8f0, 0x5, 0x1be, 0xe0, 0x2, 0x8ef, 0x8ee, 0x3, 0x2, 
       0x2, 0x2, 0x8f0, 0x8f3, 0x3, 0x2, 0x2, 0x2, 0x8f1, 0x8ef, 0x3, 0x2, 
       0x2, 0x2, 0x8f1, 0x8f2, 0x3, 0x2, 0x2, 0x2, 0x8f2, 0x8f4, 0x3, 0x2, 
       0x2, 0x2, 0x8f3, 0x8f1, 0x3, 0x2, 0x2, 0x2, 0x8f4, 0x8f5, 0x7, 0x37, 
       0x2, 0x2, 0x8f5, 0x8f7, 0x7, 0xb, 0x2, 0x2, 0x8f6, 0x8f8, 0x5, 0x1e8, 
       0xf5, 0x2, 0x8f7, 0x8f6, 0x3, 0x2, 0x2, 0x2, 0x8f7, 0x8f8, 0x3, 0x2, 
       0x2, 0x2, 0x8f8, 0x8f9, 0x3, 0x2, 0x2, 0x2, 0x8f9, 0x8fa, 0x7, 0x7f, 
       0x2, 0x2, 0x8fa, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x8fb, 0x8ff, 0x5, 0xdc, 
       0x6f, 0x2, 0x8fc, 0x8fd, 0x5, 0xee, 0x78, 0x2, 0x8fd, 0x8fe, 0x7, 
       0x7f, 0x2, 0x2, 0x8fe, 0x900, 0x3, 0x2, 0x2, 0x2, 0x8ff, 0x8fc, 0x3, 
       0x2, 0x2, 0x2, 0x8ff, 0x900, 0x3, 0x2, 0x2, 0x2, 0x900, 0x902, 0x3, 
       0x2, 0x2, 0x2, 0x901, 0x8fb, 0x3, 0x2, 0x2, 0x2, 0x901, 0x902, 0x3, 
       0x2, 0x2, 0x2, 0x902, 0x909, 0x3, 0x2, 0x2, 0x2, 0x903, 0x907, 0x5, 
       0xe0, 0x71, 0x2, 0x904, 0x905, 0x5, 0xf0, 0x79, 0x2, 0x905, 0x906, 
       0x7, 0x7f, 0x2, 0x2, 0x906, 0x908, 0x3, 0x2, 0x2, 0x2, 0x907, 0x904, 
       0x3, 0x2, 0x2, 0x2, 0x907, 0x908, 0x3, 0x2, 0x2, 0x2, 0x908, 0x90a, 
       0x3, 0x2, 0x2, 0x2, 0x909, 0x903, 0x3, 0x2, 0x2, 0x2, 0x909, 0x90a, 
       0x3, 0x2, 0x2, 0x2, 0x90a, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x90b, 0x90d, 
       0x7, 0x5, 0x2, 0x2, 0x90c, 0x90b, 0x3, 0x2, 0x2, 0x2, 0x90c, 0x90d, 
       0x3, 0x2, 0x2, 0x2, 0x90d, 0x90e, 0x3, 0x2, 0x2, 0x2, 0x90e, 0x913, 
       0x7, 0x3, 0x2, 0x2, 0x90f, 0x910, 0x7, 0x80, 0x2, 0x2, 0x910, 0x911, 
       0x5, 0x1c6, 0xe4, 0x2, 0x911, 0x912, 0x7, 0x81, 0x2, 0x2, 0x912, 
       0x914, 0x3, 0x2, 0x2, 0x2, 0x913, 0x90f, 0x3, 0x2, 0x2, 0x2, 0x913, 
       0x914, 0x3, 0x2, 0x2, 0x2, 0x914, 0x916, 0x3, 0x2, 0x2, 0x2, 0x915, 
       0x917, 0x7, 0x5f, 0x2, 0x2, 0x916, 0x915, 0x3, 0x2, 0x2, 0x2, 0x916, 
       0x917, 0x3, 0x2, 0x2, 0x2, 0x917, 0x91b, 0x3, 0x2, 0x2, 0x2, 0x918, 
       0x91a, 0x5, 0x1ca, 0xe6, 0x2, 0x919, 0x918, 0x3, 0x2, 0x2, 0x2, 0x91a, 
       0x91d, 0x3, 0x2, 0x2, 0x2, 0x91b, 0x919, 0x3, 0x2, 0x2, 0x2, 0x91b, 
       0x91c, 0x3, 0x2, 0x2, 0x2, 0x91c, 0x91e, 0x3, 0x2, 0x2, 0x2, 0x91d, 
       0x91b, 0x3, 0x2, 0x2, 0x2, 0x91e, 0x922, 0x7, 0x20, 0x2, 0x2, 0x91f, 
       0x921, 0x5, 0x160, 0xb1, 0x2, 0x920, 0x91f, 0x3, 0x2, 0x2, 0x2, 0x921, 
       0x924, 0x3, 0x2, 0x2, 0x2, 0x922, 0x920, 0x3, 0x2, 0x2, 0x2, 0x922, 
       0x923, 0x3, 0x2, 0x2, 0x2, 0x923, 0x925, 0x3, 0x2, 0x2, 0x2, 0x924, 
       0x922, 0x3, 0x2, 0x2, 0x2, 0x925, 0x927, 0x7, 0x37, 0x2, 0x2, 0x926, 
       0x928, 0x7, 0x5, 0x2, 0x2, 0x927, 0x926, 0x3, 0x2, 0x2, 0x2, 0x927, 
       0x928, 0x3, 0x2, 0x2, 0x2, 0x928, 0x929, 0x3, 0x2, 0x2, 0x2, 0x929, 
       0x92b, 0x7, 0x3, 0x2, 0x2, 0x92a, 0x92c, 0x5, 0x1e8, 0xf5, 0x2, 0x92b, 
       0x92a, 0x3, 0x2, 0x2, 0x2, 0x92b, 0x92c, 0x3, 0x2, 0x2, 0x2, 0x92c, 
       0x92d, 0x3, 0x2, 0x2, 0x2, 0x92d, 0x92e, 0x7, 0x7f, 0x2, 0x2, 0x92e, 
       0x1c5, 0x3, 0x2, 0x2, 0x2, 0x92f, 0x932, 0x7, 0x42, 0x2, 0x2, 0x930, 
       0x932, 0x5, 0x166, 0xb4, 0x2, 0x931, 0x92f, 0x3, 0x2, 0x2, 0x2, 0x931, 
       0x930, 0x3, 0x2, 0x2, 0x2, 0x932, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x933, 
       0x943, 0x5, 0x2c, 0x17, 0x2, 0x934, 0x943, 0x5, 0x40, 0x21, 0x2, 
       0x935, 0x943, 0x5, 0x44, 0x23, 0x2, 0x936, 0x943, 0x5, 0x4a, 0x26, 
       0x2, 0x937, 0x943, 0x5, 0x8e, 0x48, 0x2, 0x938, 0x943, 0x5, 0x94, 
       0x4b, 0x2, 0x939, 0x943, 0x5, 0xaa, 0x56, 0x2, 0x93a, 0x943, 0x5, 
       0xb0, 0x59, 0x2, 0x93b, 0x943, 0x5, 0xb2, 0x5a, 0x2, 0x93c, 0x943, 
       0x5, 0xf2, 0x7a, 0x2, 0x93d, 0x943, 0x5, 0xf6, 0x7c, 0x2, 0x93e, 
       0x943, 0x5, 0x106, 0x84, 0x2, 0x93f, 0x943, 0x5, 0x1ea, 0xf6, 0x2, 
       0x940, 0x943, 0x5, 0xfa, 0x7e, 0x2, 0x941, 0x943, 0x5, 0x100, 0x81, 
       0x2, 0x942, 0x933, 0x3, 0x2, 0x2, 0x2, 0x942, 0x934, 0x3, 0x2, 0x2, 
       0x2, 0x942, 0x935, 0x3, 0x2, 0x2, 0x2, 0x942, 0x936, 0x3, 0x2, 0x2, 
       0x2, 0x942, 0x937, 0x3, 0x2, 0x2, 0x2, 0x942, 0x938, 0x3, 0x2, 0x2, 
       0x2, 0x942, 0x939, 0x3, 0x2, 0x2, 0x2, 0x942, 0x93a, 0x3, 0x2, 0x2, 
       0x2, 0x942, 0x93b, 0x3, 0x2, 0x2, 0x2, 0x942, 0x93c, 0x3, 0x2, 0x2, 
       0x2, 0x942, 0x93d, 0x3, 0x2, 0x2, 0x2, 0x942, 0x93e, 0x3, 0x2, 0x2, 
       0x2, 0x942, 0x93f, 0x3, 0x2, 0x2, 0x2, 0x942, 0x940, 0x3, 0x2, 0x2, 
       0x2, 0x942, 0x941, 0x3, 0x2, 0x2, 0x2, 0x943, 0x1c9, 0x3, 0x2, 0x2, 
       0x2, 0x944, 0x948, 0x5, 0x1c8, 0xe5, 0x2, 0x945, 0x948, 0x5, 0x3c, 
       0x1f, 0x2, 0x946, 0x948, 0x5, 0x48, 0x25, 0x2, 0x947, 0x944, 0x3, 
       0x2, 0x2, 0x2, 0x947, 0x945, 0x3, 0x2, 0x2, 0x2, 0x947, 0x946, 0x3, 
       0x2, 0x2, 0x2, 0x948, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x949, 0x94b, 0x7, 
       0x5, 0x2, 0x2, 0x94a, 0x949, 0x3, 0x2, 0x2, 0x2, 0x94a, 0x94b, 0x3, 
       0x2, 0x2, 0x2, 0x94b, 0x94c, 0x3, 0x2, 0x2, 0x2, 0x94c, 0x94d, 0x5, 
       0x1a4, 0xd3, 0x2, 0x94d, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x94e, 0x950, 
       0x7, 0x5, 0x2, 0x2, 0x94f, 0x94e, 0x3, 0x2, 0x2, 0x2, 0x94f, 0x950, 
       0x3, 0x2, 0x2, 0x2, 0x950, 0x951, 0x3, 0x2, 0x2, 0x2, 0x951, 0x952, 
       0x5, 0x16e, 0xb8, 0x2, 0x952, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x953, 0x955, 
       0x7, 0x5, 0x2, 0x2, 0x954, 0x953, 0x3, 0x2, 0x2, 0x2, 0x954, 0x955, 
       0x3, 0x2, 0x2, 0x2, 0x955, 0x958, 0x3, 0x2, 0x2, 0x2, 0x956, 0x959, 
       0x5, 0x1d2, 0xea, 0x2, 0x957, 0x959, 0x5, 0x1d4, 0xeb, 0x2, 0x958, 
       0x956, 0x3, 0x2, 0x2, 0x2, 0x958, 0x957, 0x3, 0x2, 0x2, 0x2, 0x959, 
       0x1d1, 0x3, 0x2, 0x2, 0x2, 0x95a, 0x95b, 0x5, 0x182, 0xc2, 0x2, 0x95b, 
       0x95d, 0x7, 0xa0, 0x2, 0x2, 0x95c, 0x95e, 0x7, 0x15, 0x2, 0x2, 0x95d, 
       0x95c, 0x3, 0x2, 0x2, 0x2, 0x95d, 0x95e, 0x3, 0x2, 0x2, 0x2, 0x95e, 
       0x960, 0x3, 0x2, 0x2, 0x2, 0x95f, 0x961, 0x5, 0x180, 0xc1, 0x2, 0x960, 
       0x95f, 0x3, 0x2, 0x2, 0x2, 0x960, 0x961, 0x3, 0x2, 0x2, 0x2, 0x961, 
       0x964, 0x3, 0x2, 0x2, 0x2, 0x962, 0x965, 0x5, 0x184, 0xc3, 0x2, 0x963, 
       0x965, 0x5, 0x18c, 0xc7, 0x2, 0x964, 0x962, 0x3, 0x2, 0x2, 0x2, 0x964, 
       0x963, 0x3, 0x2, 0x2, 0x2, 0x965, 0x966, 0x3, 0x2, 0x2, 0x2, 0x966, 
       0x967, 0x7, 0x7f, 0x2, 0x2, 0x967, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x968, 
       0x969, 0x7, 0x4a, 0x2, 0x2, 0x969, 0x96a, 0x5, 0x13a, 0x9e, 0x2, 
       0x96a, 0x96c, 0x7, 0x38, 0x2, 0x2, 0x96b, 0x96d, 0x7, 0x8b, 0x2, 
       0x2, 0x96c, 0x96b, 0x3, 0x2, 0x2, 0x2, 0x96c, 0x96d, 0x3, 0x2, 0x2, 
       0x2, 0x96d, 0x96e, 0x3, 0x2, 0x2, 0x2, 0x96e, 0x96f, 0x5, 0x182, 
       0xc2, 0x2, 0x96f, 0x971, 0x7, 0xa0, 0x2, 0x2, 0x970, 0x972, 0x7, 
       0x15, 0x2, 0x2, 0x971, 0x970, 0x3, 0x2, 0x2, 0x2, 0x971, 0x972, 0x3, 
       0x2, 0x2, 0x2, 0x972, 0x974, 0x3, 0x2, 0x2, 0x2, 0x973, 0x975, 0x5, 
       0x180, 0xc1, 0x2, 0x974, 0x973, 0x3, 0x2, 0x2, 0x2, 0x974, 0x975, 
       0x3, 0x2, 0x2, 0x2, 0x975, 0x976, 0x3, 0x2, 0x2, 0x2, 0x976, 0x977, 
       0x5, 0x196, 0xcc, 0x2, 0x977, 0x978, 0x7, 0x7f, 0x2, 0x2, 0x978, 
       0x1d5, 0x3, 0x2, 0x2, 0x2, 0x979, 0x97b, 0x5, 0x1d8, 0xed, 0x2, 0x97a, 
       0x97c, 0x5, 0xee, 0x78, 0x2, 0x97b, 0x97a, 0x3, 0x2, 0x2, 0x2, 0x97b, 
       0x97c, 0x3, 0x2, 0x2, 0x2, 0x97c, 0x97e, 0x3, 0x2, 0x2, 0x2, 0x97d, 
       0x97f, 0x5, 0xf0, 0x79, 0x2, 0x97e, 0x97d, 0x3, 0x2, 0x2, 0x2, 0x97e, 
       0x97f, 0x3, 0x2, 0x2, 0x2, 0x97f, 0x980, 0x3, 0x2, 0x2, 0x2, 0x980, 
       0x981, 0x7, 0x7f, 0x2, 0x2, 0x981, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x982, 
       0x984, 0x7, 0x7, 0x2, 0x2, 0x983, 0x982, 0x3, 0x2, 0x2, 0x2, 0x983, 
       0x984, 0x3, 0x2, 0x2, 0x2, 0x984, 0x985, 0x3, 0x2, 0x2, 0x2, 0x985, 
       0x991, 0x5, 0x6, 0x4, 0x2, 0x986, 0x987, 0x7, 0xf, 0x2, 0x2, 0x987, 
       0x98c, 0x5, 0x6, 0x4, 0x2, 0x988, 0x989, 0x7, 0x80, 0x2, 0x2, 0x989, 
       0x98a, 0x5, 0x202, 0x102, 0x2, 0x98a, 0x98b, 0x7, 0x81, 0x2, 0x2, 
       0x98b, 0x98d, 0x3, 0x2, 0x2, 0x2, 0x98c, 0x988, 0x3, 0x2, 0x2, 0x2, 
       0x98c, 0x98d, 0x3, 0x2, 0x2, 0x2, 0x98d, 0x991, 0x3, 0x2, 0x2, 0x2, 
       0x98e, 0x98f, 0x7, 0x65, 0x2, 0x2, 0x98f, 0x991, 0x5, 0x6, 0x4, 0x2, 
       0x990, 0x983, 0x3, 0x2, 0x2, 0x2, 0x990, 0x986, 0x3, 0x2, 0x2, 0x2, 
       0x990, 0x98e, 0x3, 0x2, 0x2, 0x2, 0x991, 0x1d9, 0x3, 0x2, 0x2, 0x2, 
       0x992, 0x996, 0x5, 0x1dc, 0xef, 0x2, 0x993, 0x996, 0x5, 0x1de, 0xf0, 
       0x2, 0x994, 0x996, 0x5, 0x1e0, 0xf1, 0x2, 0x995, 0x992, 0x3, 0x2, 
       0x2, 0x2, 0x995, 0x993, 0x3, 0x2, 0x2, 0x2, 0x995, 0x994, 0x3, 0x2, 
       0x2, 0x2, 0x996, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x997, 0x998, 0x7, 0x5a, 
       0x2, 0x2, 0x998, 0x999, 0x5, 0x1b2, 0xda, 0x2, 0x999, 0x99a, 0x7, 
       0x44, 0x2, 0x2, 0x99a, 0x99b, 0x5, 0x1e6, 0xf4, 0x2, 0x99b, 0x99c, 
       0x7, 0x37, 0x2, 0x2, 0x99c, 0x99e, 0x7, 0x44, 0x2, 0x2, 0x99d, 0x99f, 
       0x5, 0x1e8, 0xf5, 0x2, 0x99e, 0x99d, 0x3, 0x2, 0x2, 0x2, 0x99e, 0x99f, 
       0x3, 0x2, 0x2, 0x2, 0x99f, 0x9a0, 0x3, 0x2, 0x2, 0x2, 0x9a0, 0x9a1, 
       0x7, 0x7f, 0x2, 0x2, 0x9a1, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x9a2, 0x9a6, 
       0x7, 0x5c, 0x2, 0x2, 0x9a3, 0x9a4, 0x5, 0x1e8, 0xf5, 0x2, 0x9a4, 
       0x9a5, 0x7, 0x8c, 0x2, 0x2, 0x9a5, 0x9a7, 0x3, 0x2, 0x2, 0x2, 0x9a6, 
       0x9a3, 0x3, 0x2, 0x2, 0x2, 0x9a6, 0x9a7, 0x3, 0x2, 0x2, 0x2, 0x9a7, 
       0x9a8, 0x3, 0x2, 0x2, 0x2, 0x9a8, 0x9a9, 0x5, 0x16a, 0xb6, 0x2, 0x9a9, 
       0x9aa, 0x7, 0x44, 0x2, 0x2, 0x9aa, 0x9b7, 0x5, 0x1e6, 0xf4, 0x2, 
       0x9ab, 0x9af, 0x7, 0x3b, 0x2, 0x2, 0x9ac, 0x9ad, 0x5, 0x1e8, 0xf5, 
       0x2, 0x9ad, 0x9ae, 0x7, 0x8c, 0x2, 0x2, 0x9ae, 0x9b0, 0x3, 0x2, 0x2, 
       0x2, 0x9af, 0x9ac, 0x3, 0x2, 0x2, 0x2, 0x9af, 0x9b0, 0x3, 0x2, 0x2, 
       0x2, 0x9b0, 0x9b1, 0x3, 0x2, 0x2, 0x2, 0x9b1, 0x9b2, 0x5, 0x16a, 
       0xb6, 0x2, 0x9b2, 0x9b3, 0x7, 0x44, 0x2, 0x2, 0x9b3, 0x9b4, 0x5, 
       0x1e6, 0xf4, 0x2, 0x9b4, 0x9b6, 0x3, 0x2, 0x2, 0x2, 0x9b5, 0x9ab, 
       0x3, 0x2, 0x2, 0x2, 0x9b6, 0x9b9, 0x3, 0x2, 0x2, 0x2, 0x9b7, 0x9b5, 
       0x3, 0x2, 0x2, 0x2, 0x9b7, 0x9b8, 0x3, 0x2, 0x2, 0x2, 0x9b8, 0x9c3, 
       0x3, 0x2, 0x2, 0x2, 0x9b9, 0x9b7, 0x3, 0x2, 0x2, 0x2, 0x9ba, 0x9be, 
       0x7, 0x18, 0x2, 0x2, 0x9bb, 0x9bc, 0x5, 0x1e8, 0xf5, 0x2, 0x9bc, 
       0x9bd, 0x7, 0x8c, 0x2, 0x2, 0x9bd, 0x9bf, 0x3, 0x2, 0x2, 0x2, 0x9be, 
       0x9bb, 0x3, 0x2, 0x2, 0x2, 0x9be, 0x9bf, 0x3, 0x2, 0x2, 0x2, 0x9bf, 
       0x9c0, 0x3, 0x2, 0x2, 0x2, 0x9c0, 0x9c1, 0x7, 0x44, 0x2, 0x2, 0x9c1, 
       0x9c4, 0x5, 0x1e6, 0xf4, 0x2, 0x9c2, 0x9c4, 0x6, 0xf0, 0xb, 0x2, 
       0x9c3, 0x9ba, 0x3, 0x2, 0x2, 0x2, 0x9c3, 0x9c2, 0x3, 0x2, 0x2, 0x2, 
       0x9c4, 0x9c5, 0x3, 0x2, 0x2, 0x2, 0x9c5, 0x9c6, 0x7, 0x37, 0x2, 0x2, 
       0x9c6, 0x9c8, 0x7, 0x44, 0x2, 0x2, 0x9c7, 0x9c9, 0x5, 0x1e8, 0xf5, 
       0x2, 0x9c8, 0x9c7, 0x3, 0x2, 0x2, 0x2, 0x9c8, 0x9c9, 0x3, 0x2, 0x2, 
       0x2, 0x9c9, 0x9ca, 0x3, 0x2, 0x2, 0x2, 0x9ca, 0x9cb, 0x7, 0x7f, 0x2, 
       0x2, 0x9cb, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x9cc, 0x9cd, 0x7, 0x63, 0x2, 
       0x2, 0x9cd, 0x9ce, 0x5, 0x13a, 0x9e, 0x2, 0x9ce, 0x9d0, 0x7, 0x44, 
       0x2, 0x2, 0x9cf, 0x9d1, 0x5, 0x1e2, 0xf2, 0x2, 0x9d0, 0x9cf, 0x3, 
       0x2, 0x2, 0x2, 0x9d1, 0x9d2, 0x3, 0x2, 0x2, 0x2, 0x9d2, 0x9d0, 0x3, 
       0x2, 0x2, 0x2, 0x9d2, 0x9d3, 0x3, 0x2, 0x2, 0x2, 0x9d3, 0x9d4, 0x3, 
       0x2, 0x2, 0x2, 0x9d4, 0x9d5, 0x7, 0x37, 0x2, 0x2, 0x9d5, 0x9d7, 0x7, 
       0x44, 0x2, 0x2, 0x9d6, 0x9d8, 0x5, 0x1e8, 0xf5, 0x2, 0x9d7, 0x9d6, 
       0x3, 
  };
  static const uint16_t serializedATNSegment1[] = {
    0x2, 0x2, 0x2, 0x9d7, 0x9d8, 0x3, 0x2, 0x2, 0x2, 0x9d8, 0x9d9, 0x3, 
       0x2, 0x2, 0x2, 0x9d9, 0x9da, 0x7, 0x7f, 0x2, 0x2, 0x9da, 0x1e1, 0x3, 
       0x2, 0x2, 0x2, 0x9db, 0x9df, 0x7, 0x6a, 0x2, 0x2, 0x9dc, 0x9dd, 0x5, 
       0x1e8, 0xf5, 0x2, 0x9dd, 0x9de, 0x7, 0x8c, 0x2, 0x2, 0x9de, 0x9e0, 
       0x3, 0x2, 0x2, 0x2, 0x9df, 0x9dc, 0x3, 0x2, 0x2, 0x2, 0x9df, 0x9e0, 
       0x3, 0x2, 0x2, 0x2, 0x9e0, 0x9e1, 0x3, 0x2, 0x2, 0x2, 0x9e1, 0x9e2, 
       0x5, 0x156, 0xac, 0x2, 0x9e2, 0x9e3, 0x7, 0xa5, 0x2, 0x2, 0x9e3, 
       0x9e4, 0x5, 0x1e4, 0xf3, 0x2, 0x9e4, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x9e5, 
       0x9e7, 0x5, 0x1c, 0xf, 0x2, 0x9e6, 0x9e5, 0x3, 0x2, 0x2, 0x2, 0x9e7, 
       0x9ea, 0x3, 0x2, 0x2, 0x2, 0x9e8, 0x9e6, 0x3, 0x2, 0x2, 0x2, 0x9e8, 
       0x9e9, 0x3, 0x2, 0x2, 0x2, 0x9e9, 0x9eb, 0x3, 0x2, 0x2, 0x2, 0x9ea, 
       0x9e8, 0x3, 0x2, 0x2, 0x2, 0x9eb, 0x9ef, 0x7, 0x20, 0x2, 0x2, 0x9ec, 
       0x9ee, 0x5, 0x1be, 0xe0, 0x2, 0x9ed, 0x9ec, 0x3, 0x2, 0x2, 0x2, 0x9ee, 
       0x9f1, 0x3, 0x2, 0x2, 0x2, 0x9ef, 0x9ed, 0x3, 0x2, 0x2, 0x2, 0x9ef, 
       0x9f0, 0x3, 0x2, 0x2, 0x2, 0x9f0, 0x9f2, 0x3, 0x2, 0x2, 0x2, 0x9f1, 
       0x9ef, 0x3, 0x2, 0x2, 0x2, 0x9f2, 0x9f4, 0x7, 0x37, 0x2, 0x2, 0x9f3, 
       0x9f5, 0x5, 0x1e8, 0xf5, 0x2, 0x9f4, 0x9f3, 0x3, 0x2, 0x2, 0x2, 0x9f4, 
       0x9f5, 0x3, 0x2, 0x2, 0x2, 0x9f5, 0x9f6, 0x3, 0x2, 0x2, 0x2, 0x9f6, 
       0x9fe, 0x7, 0x7f, 0x2, 0x2, 0x9f7, 0x9f9, 0x5, 0x1be, 0xe0, 0x2, 
       0x9f8, 0x9f7, 0x3, 0x2, 0x2, 0x2, 0x9f9, 0x9fc, 0x3, 0x2, 0x2, 0x2, 
       0x9fa, 0x9f8, 0x3, 0x2, 0x2, 0x2, 0x9fa, 0x9fb, 0x3, 0x2, 0x2, 0x2, 
       0x9fb, 0x9fe, 0x3, 0x2, 0x2, 0x2, 0x9fc, 0x9fa, 0x3, 0x2, 0x2, 0x2, 
       0x9fd, 0x9e8, 0x3, 0x2, 0x2, 0x2, 0x9fd, 0x9fa, 0x3, 0x2, 0x2, 0x2, 
       0x9fe, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x9ff, 0xa01, 0x5, 0x1c, 0xf, 0x2, 
       0xa00, 0x9ff, 0x3, 0x2, 0x2, 0x2, 0xa01, 0xa04, 0x3, 0x2, 0x2, 0x2, 
       0xa02, 0xa00, 0x3, 0x2, 0x2, 0x2, 0xa02, 0xa03, 0x3, 0x2, 0x2, 0x2, 
       0xa03, 0xa05, 0x3, 0x2, 0x2, 0x2, 0xa04, 0xa02, 0x3, 0x2, 0x2, 0x2, 
       0xa05, 0xa09, 0x7, 0x20, 0x2, 0x2, 0xa06, 0xa08, 0x5, 0x1be, 0xe0, 
       0x2, 0xa07, 0xa06, 0x3, 0x2, 0x2, 0x2, 0xa08, 0xa0b, 0x3, 0x2, 0x2, 
       0x2, 0xa09, 0xa07, 0x3, 0x2, 0x2, 0x2, 0xa09, 0xa0a, 0x3, 0x2, 0x2, 
       0x2, 0xa0a, 0xa13, 0x3, 0x2, 0x2, 0x2, 0xa0b, 0xa09, 0x3, 0x2, 0x2, 
       0x2, 0xa0c, 0xa0e, 0x5, 0x1be, 0xe0, 0x2, 0xa0d, 0xa0c, 0x3, 0x2, 
       0x2, 0x2, 0xa0e, 0xa11, 0x3, 0x2, 0x2, 0x2, 0xa0f, 0xa0d, 0x3, 0x2, 
       0x2, 0x2, 0xa0f, 0xa10, 0x3, 0x2, 0x2, 0x2, 0xa10, 0xa13, 0x3, 0x2, 
       0x2, 0x2, 0xa11, 0xa0f, 0x3, 0x2, 0x2, 0x2, 0xa12, 0xa02, 0x3, 0x2, 
       0x2, 0x2, 0xa12, 0xa0f, 0x3, 0x2, 0x2, 0x2, 0xa13, 0x1e7, 0x3, 0x2, 
       0x2, 0x2, 0xa14, 0xa15, 0x5, 0x202, 0x102, 0x2, 0xa15, 0x1e9, 0x3, 
       0x2, 0x2, 0x2, 0xa16, 0xa17, 0x7, 0x19, 0x2, 0x2, 0xa17, 0xa1c, 0x5, 
       0x12, 0xa, 0x2, 0xa18, 0xa19, 0x7, 0x89, 0x2, 0x2, 0xa19, 0xa1b, 
       0x5, 0x12, 0xa, 0x2, 0xa1a, 0xa18, 0x3, 0x2, 0x2, 0x2, 0xa1b, 0xa1e, 
       0x3, 0x2, 0x2, 0x2, 0xa1c, 0xa1a, 0x3, 0x2, 0x2, 0x2, 0xa1c, 0xa1d, 
       0x3, 0x2, 0x2, 0x2, 0xa1d, 0xa1f, 0x3, 0x2, 0x2, 0x2, 0xa1e, 0xa1c, 
       0x3, 0x2, 0x2, 0x2, 0xa1f, 0xa20, 0x7, 0x7f, 0x2, 0x2, 0xa20, 0x1eb, 
       0x3, 0x2, 0x2, 0x2, 0xa21, 0xa23, 0x5, 0x1ee, 0xf8, 0x2, 0xa22, 0xa21, 
       0x3, 0x2, 0x2, 0x2, 0xa23, 0xa26, 0x3, 0x2, 0x2, 0x2, 0xa24, 0xa22, 
       0x3, 0x2, 0x2, 0x2, 0xa24, 0xa25, 0x3, 0x2, 0x2, 0x2, 0xa25, 0xa27, 
       0x3, 0x2, 0x2, 0x2, 0xa26, 0xa24, 0x3, 0x2, 0x2, 0x2, 0xa27, 0xa28, 
       0x7, 0x2, 0x2, 0x3, 0xa28, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0xa29, 0xa2a, 
       0x5, 0x1fc, 0xff, 0x2, 0xa2a, 0xa2b, 0x5, 0x1f0, 0xf9, 0x2, 0xa2b, 
       0x1ef, 0x3, 0x2, 0x2, 0x2, 0xa2c, 0xa2f, 0x5, 0x1f2, 0xfa, 0x2, 0xa2d, 
       0xa2f, 0x5, 0x1f4, 0xfb, 0x2, 0xa2e, 0xa2c, 0x3, 0x2, 0x2, 0x2, 0xa2e, 
       0xa2d, 0x3, 0x2, 0x2, 0x2, 0xa2f, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0xa30, 
       0xa36, 0x5, 0x14, 0xb, 0x2, 0xa31, 0xa36, 0x5, 0x1e, 0x10, 0x2, 0xa32, 
       0xa36, 0x5, 0x44, 0x23, 0x2, 0xa33, 0xa36, 0x5, 0x4a, 0x26, 0x2, 
       0xa34, 0xa36, 0x5, 0x1fa, 0xfe, 0x2, 0xa35, 0xa30, 0x3, 0x2, 0x2, 
       0x2, 0xa35, 0xa31, 0x3, 0x2, 0x2, 0x2, 0xa35, 0xa32, 0x3, 0x2, 0x2, 
       0x2, 0xa35, 0xa33, 0x3, 0x2, 0x2, 0x2, 0xa35, 0xa34, 0x3, 0x2, 0x2, 
       0x2, 0xa36, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0xa37, 0xa3a, 0x5, 0x1a, 0xe, 
       0x2, 0xa38, 0xa3a, 0x5, 0x48, 0x25, 0x2, 0xa39, 0xa37, 0x3, 0x2, 
       0x2, 0x2, 0xa39, 0xa38, 0x3, 0x2, 0x2, 0x2, 0xa3a, 0x1f5, 0x3, 0x2, 
       0x2, 0x2, 0xa3b, 0xa3c, 0x7, 0x3a, 0x2, 0x2, 0xa3c, 0xa3d, 0x5, 0x1f8, 
       0xfd, 0x2, 0xa3d, 0xa3e, 0x7, 0x7f, 0x2, 0x2, 0xa3e, 0x1f7, 0x3, 
       0x2, 0x2, 0x2, 0xa3f, 0xa40, 0x5, 0x78, 0x3d, 0x2, 0xa40, 0x1f9, 
       0x3, 0x2, 0x2, 0x2, 0xa41, 0xa42, 0x7, 0x4, 0x2, 0x2, 0xa42, 0xa43, 
       0x5, 0x202, 0x102, 0x2, 0xa43, 0xa44, 0x7, 0x5f, 0x2, 0x2, 0xa44, 
       0xa45, 0x5, 0x1fc, 0xff, 0x2, 0xa45, 0xa47, 0x7, 0x37, 0x2, 0x2, 
       0xa46, 0xa48, 0x7, 0x4, 0x2, 0x2, 0xa47, 0xa46, 0x3, 0x2, 0x2, 0x2, 
       0xa47, 0xa48, 0x3, 0x2, 0x2, 0x2, 0xa48, 0xa4a, 0x3, 0x2, 0x2, 0x2, 
       0xa49, 0xa4b, 0x5, 0x202, 0x102, 0x2, 0xa4a, 0xa49, 0x3, 0x2, 0x2, 
       0x2, 0xa4a, 0xa4b, 0x3, 0x2, 0x2, 0x2, 0xa4b, 0xa4c, 0x3, 0x2, 0x2, 
       0x2, 0xa4c, 0xa4d, 0x7, 0x7f, 0x2, 0x2, 0xa4d, 0x1fb, 0x3, 0x2, 0x2, 
       0x2, 0xa4e, 0xa50, 0x5, 0x1fe, 0x100, 0x2, 0xa4f, 0xa4e, 0x3, 0x2, 
       0x2, 0x2, 0xa50, 0xa53, 0x3, 0x2, 0x2, 0x2, 0xa51, 0xa4f, 0x3, 0x2, 
       0x2, 0x2, 0xa51, 0xa52, 0x3, 0x2, 0x2, 0x2, 0xa52, 0x1fd, 0x3, 0x2, 
       0x2, 0x2, 0xa53, 0xa51, 0x3, 0x2, 0x2, 0x2, 0xa54, 0xa58, 0x5, 0x1f6, 
       0xfc, 0x2, 0xa55, 0xa58, 0x5, 0x1ea, 0xf6, 0x2, 0xa56, 0xa58, 0x5, 
       0x200, 0x101, 0x2, 0xa57, 0xa54, 0x3, 0x2, 0x2, 0x2, 0xa57, 0xa55, 
       0x3, 0x2, 0x2, 0x2, 0xa57, 0xa56, 0x3, 0x2, 0x2, 0x2, 0xa58, 0x1ff, 
       0x3, 0x2, 0x2, 0x2, 0xa59, 0xa5a, 0x7, 0x4, 0x2, 0x2, 0xa5a, 0xa5f, 
       0x5, 0x12, 0xa, 0x2, 0xa5b, 0xa5c, 0x7, 0x89, 0x2, 0x2, 0xa5c, 0xa5e, 
       0x5, 0x12, 0xa, 0x2, 0xa5d, 0xa5b, 0x3, 0x2, 0x2, 0x2, 0xa5e, 0xa61, 
       0x3, 0x2, 0x2, 0x2, 0xa5f, 0xa5d, 0x3, 0x2, 0x2, 0x2, 0xa5f, 0xa60, 
       0x3, 0x2, 0x2, 0x2, 0xa60, 0xa62, 0x3, 0x2, 0x2, 0x2, 0xa61, 0xa5f, 
       0x3, 0x2, 0x2, 0x2, 0xa62, 0xa63, 0x7, 0x7f, 0x2, 0x2, 0xa63, 0x201, 
       0x3, 0x2, 0x2, 0x2, 0xa64, 0xa65, 0x9, 0x13, 0x2, 0x2, 0xa65, 0x203, 
       0x3, 0x2, 0x2, 0x2, 0x132, 0x209, 0x20e, 0x216, 0x21a, 0x222, 0x22c, 
       0x237, 0x23e, 0x241, 0x246, 0x24d, 0x250, 0x254, 0x257, 0x25e, 0x263, 
       0x268, 0x272, 0x279, 0x27e, 0x281, 0x288, 0x292, 0x29a, 0x2a0, 0x2a3, 
       0x2aa, 0x2b1, 0x2b7, 0x2c3, 0x2c8, 0x2cc, 0x2d3, 0x2da, 0x2de, 0x2e9, 
       0x2ee, 0x2f1, 0x2f7, 0x2fa, 0x2ff, 0x302, 0x308, 0x312, 0x316, 0x321, 
       0x328, 0x32d, 0x330, 0x33c, 0x33f, 0x349, 0x34c, 0x350, 0x35b, 0x35d, 
       0x362, 0x367, 0x36a, 0x372, 0x37b, 0x381, 0x384, 0x38e, 0x396, 0x39d, 
       0x3a7, 0x3ae, 0x3b8, 0x3be, 0x3cc, 0x3d0, 0x3d9, 0x3eb, 0x3f1, 0x3f3, 
       0x3fd, 0x404, 0x40a, 0x40f, 0x41b, 0x426, 0x43b, 0x441, 0x447, 0x44d, 
       0x454, 0x45b, 0x45f, 0x46c, 0x475, 0x479, 0x480, 0x484, 0x48d, 0x497, 
       0x49b, 0x4a1, 0x4a9, 0x4b2, 0x4b6, 0x4bd, 0x4c5, 0x4ce, 0x4d4, 0x4d8, 
       0x4e2, 0x4e8, 0x4ee, 0x4f3, 0x4f6, 0x4fb, 0x4ff, 0x503, 0x509, 0x50e, 
       0x51f, 0x523, 0x528, 0x52e, 0x531, 0x536, 0x53c, 0x543, 0x557, 0x55e, 
       0x579, 0x581, 0x58a, 0x592, 0x595, 0x59a, 0x5a8, 0x5ad, 0x5b4, 0x5bf, 
       0x5c2, 0x5c5, 0x5ca, 0x5db, 0x5e0, 0x5f0, 0x608, 0x60d, 0x611, 0x616, 
       0x61a, 0x623, 0x62e, 0x63d, 0x642, 0x646, 0x649, 0x64c, 0x654, 0x659, 
       0x664, 0x676, 0x67b, 0x67f, 0x68b, 0x697, 0x6a1, 0x6ab, 0x6b5, 0x6bb, 
       0x6c9, 0x6cb, 0x6d2, 0x6d7, 0x6dd, 0x6e7, 0x6e9, 0x6f2, 0x704, 0x708, 
       0x70b, 0x70e, 0x718, 0x720, 0x729, 0x72f, 0x738, 0x73d, 0x743, 0x752, 
       0x756, 0x759, 0x75c, 0x768, 0x77a, 0x77e, 0x784, 0x78b, 0x790, 0x795, 
       0x79e, 0x7a7, 0x7b0, 0x7b3, 0x7b7, 0x7be, 0x7c2, 0x7c7, 0x7cc, 0x7ce, 
       0x7d2, 0x7d7, 0x7e6, 0x7ec, 0x7f2, 0x801, 0x807, 0x80b, 0x811, 0x816, 
       0x825, 0x82c, 0x832, 0x841, 0x847, 0x857, 0x86e, 0x875, 0x87a, 0x880, 
       0x887, 0x88c, 0x88f, 0x899, 0x8a0, 0x8a8, 0x8b0, 0x8b4, 0x8ba, 0x8be, 
       0x8c4, 0x8cf, 0x8d7, 0x8da, 0x8e1, 0x8e4, 0x8ea, 0x8f1, 0x8f7, 0x8ff, 
       0x901, 0x907, 0x909, 0x90c, 0x913, 0x916, 0x91b, 0x922, 0x927, 0x92b, 
       0x931, 0x942, 0x947, 0x94a, 0x94f, 0x954, 0x958, 0x95d, 0x960, 0x964, 
       0x96c, 0x971, 0x974, 0x97b, 0x97e, 0x983, 0x98c, 0x990, 0x995, 0x99e, 
       0x9a6, 0x9af, 0x9b7, 0x9be, 0x9c3, 0x9c8, 0x9d2, 0x9d7, 0x9df, 0x9e8, 
       0x9ef, 0x9f4, 0x9fa, 0x9fd, 0xa02, 0xa09, 0xa0f, 0xa12, 0xa1c, 0xa24, 
       0xa2e, 0xa35, 0xa39, 0xa47, 0xa4a, 0xa51, 0xa57, 0xa5f, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));
  _serializedATN.insert(_serializedATN.end(), serializedATNSegment1,
    serializedATNSegment1 + sizeof(serializedATNSegment1) / sizeof(serializedATNSegment1[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

vhdlParser::Initializer vhdlParser::_init;
