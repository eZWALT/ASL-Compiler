
// Generated from Calc.g4 by ANTLR 4.11.1


#include "CalcVisitor.h"

#include "CalcParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CalcParserStaticData final {
  CalcParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CalcParserStaticData(const CalcParserStaticData&) = delete;
  CalcParserStaticData(CalcParserStaticData&&) = delete;
  CalcParserStaticData& operator=(const CalcParserStaticData&) = delete;
  CalcParserStaticData& operator=(CalcParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag calcParserOnceFlag;
CalcParserStaticData *calcParserStaticData = nullptr;

void calcParserInitialize() {
  assert(calcParserStaticData == nullptr);
  auto staticData = std::make_unique<CalcParserStaticData>(
    std::vector<std::string>{
      "prog", "stat", "expr"
    },
    std::vector<std::string>{
      "", "'='", "'if'", "'then'", "'else'", "'endif'", "'while'", "'=='", 
      "'!='", "'<='", "'>='", "'<'", "'>'", "'('", "')'", "'*'", "'+'", 
      "'-'", "'%'", "'/'", "'abs'", "'min'", "'max'", "','", "'!'", "'mistery'"
    },
    std::vector<std::string>{
      "", "", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "EQ", "NEQ", "LE", 
      "GE", "LESS", "GRT", "LPAR", "RPAR", "MUL", "ADD", "SUB", "MOD", "DIV", 
      "ABS", "MIN", "MAX", "COMMA", "FACTORIAL", "MYSTERY", "ID", "INT", 
      "NEWLINE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,29,107,2,0,7,0,2,1,7,1,2,2,7,2,1,0,4,0,8,8,0,11,0,12,0,9,1,0,1,0,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,44,8,1,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,77,8,2,10,2,12,2,80,
  	9,2,1,2,1,2,1,2,1,2,3,2,86,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,5,2,102,8,2,10,2,12,2,105,9,2,1,2,0,1,4,3,0,2,4,0,4,
  	1,0,16,17,2,0,15,15,18,19,1,0,9,12,1,0,7,8,122,0,7,1,0,0,0,2,43,1,0,0,
  	0,4,85,1,0,0,0,6,8,3,2,1,0,7,6,1,0,0,0,8,9,1,0,0,0,9,7,1,0,0,0,9,10,1,
  	0,0,0,10,11,1,0,0,0,11,12,5,0,0,1,12,1,1,0,0,0,13,14,3,4,2,0,14,15,5,
  	28,0,0,15,44,1,0,0,0,16,17,5,26,0,0,17,18,5,1,0,0,18,19,3,4,2,0,19,20,
  	5,28,0,0,20,44,1,0,0,0,21,22,5,2,0,0,22,23,3,4,2,0,23,24,5,28,0,0,24,
  	25,5,3,0,0,25,26,3,2,1,0,26,27,5,5,0,0,27,44,1,0,0,0,28,29,5,2,0,0,29,
  	30,3,4,2,0,30,31,5,28,0,0,31,32,5,3,0,0,32,33,3,2,1,0,33,34,5,4,0,0,34,
  	35,3,2,1,0,35,36,5,5,0,0,36,44,1,0,0,0,37,38,5,6,0,0,38,39,3,4,2,0,39,
  	40,5,28,0,0,40,41,3,2,1,0,41,44,1,0,0,0,42,44,5,28,0,0,43,13,1,0,0,0,
  	43,16,1,0,0,0,43,21,1,0,0,0,43,28,1,0,0,0,43,37,1,0,0,0,43,42,1,0,0,0,
  	44,3,1,0,0,0,45,46,6,2,-1,0,46,47,5,13,0,0,47,48,3,4,2,0,48,49,5,14,0,
  	0,49,86,1,0,0,0,50,51,7,0,0,0,51,86,3,4,2,11,52,53,5,20,0,0,53,54,5,13,
  	0,0,54,55,3,4,2,0,55,56,5,14,0,0,56,86,1,0,0,0,57,58,5,21,0,0,58,59,5,
  	13,0,0,59,60,3,4,2,0,60,61,5,23,0,0,61,62,3,4,2,0,62,63,5,14,0,0,63,86,
  	1,0,0,0,64,65,5,22,0,0,65,66,5,13,0,0,66,67,3,4,2,0,67,68,5,23,0,0,68,
  	69,3,4,2,0,69,70,5,14,0,0,70,86,1,0,0,0,71,72,5,25,0,0,72,73,5,13,0,0,
  	73,78,3,4,2,0,74,75,5,23,0,0,75,77,3,4,2,0,76,74,1,0,0,0,77,80,1,0,0,
  	0,78,76,1,0,0,0,78,79,1,0,0,0,79,81,1,0,0,0,80,78,1,0,0,0,81,82,5,14,
  	0,0,82,86,1,0,0,0,83,86,5,27,0,0,84,86,5,26,0,0,85,45,1,0,0,0,85,50,1,
  	0,0,0,85,52,1,0,0,0,85,57,1,0,0,0,85,64,1,0,0,0,85,71,1,0,0,0,85,83,1,
  	0,0,0,85,84,1,0,0,0,86,103,1,0,0,0,87,88,10,10,0,0,88,89,7,1,0,0,89,102,
  	3,4,2,11,90,91,10,9,0,0,91,92,7,0,0,0,92,102,3,4,2,10,93,94,10,4,0,0,
  	94,95,7,2,0,0,95,102,3,4,2,5,96,97,10,3,0,0,97,98,7,3,0,0,98,102,3,4,
  	2,4,99,100,10,13,0,0,100,102,5,24,0,0,101,87,1,0,0,0,101,90,1,0,0,0,101,
  	93,1,0,0,0,101,96,1,0,0,0,101,99,1,0,0,0,102,105,1,0,0,0,103,101,1,0,
  	0,0,103,104,1,0,0,0,104,5,1,0,0,0,105,103,1,0,0,0,6,9,43,78,85,101,103
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calcParserStaticData = staticData.release();
}

}

CalcParser::CalcParser(TokenStream *input) : CalcParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CalcParser::CalcParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CalcParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *calcParserStaticData->atn, calcParserStaticData->decisionToDFA, calcParserStaticData->sharedContextCache, options);
}

CalcParser::~CalcParser() {
  delete _interpreter;
}

const atn::ATN& CalcParser::getATN() const {
  return *calcParserStaticData->atn;
}

std::string CalcParser::getGrammarFileName() const {
  return "Calc.g4";
}

const std::vector<std::string>& CalcParser::getRuleNames() const {
  return calcParserStaticData->ruleNames;
}

const dfa::Vocabulary& CalcParser::getVocabulary() const {
  return calcParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CalcParser::getSerializedATN() const {
  return calcParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

CalcParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalcParser::ProgContext::EOF() {
  return getToken(CalcParser::EOF, 0);
}

std::vector<CalcParser::StatContext *> CalcParser::ProgContext::stat() {
  return getRuleContexts<CalcParser::StatContext>();
}

CalcParser::StatContext* CalcParser::ProgContext::stat(size_t i) {
  return getRuleContext<CalcParser::StatContext>(i);
}


size_t CalcParser::ProgContext::getRuleIndex() const {
  return CalcParser::RuleProg;
}


std::any CalcParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ProgContext* CalcParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, CalcParser::RuleProg);
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
    setState(7); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(6);
      stat();
      setState(9); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 510861380) != 0);
    setState(11);
    match(CalcParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

CalcParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcParser::StatContext::getRuleIndex() const {
  return CalcParser::RuleStat;
}

void CalcParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlankContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::BlankContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::BlankContext::BlankContext(StatContext *ctx) { copyFrom(ctx); }


std::any CalcParser::BlankContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitBlank(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::WhileContext::WHILE() {
  return getToken(CalcParser::WHILE, 0);
}

CalcParser::ExprContext* CalcParser::WhileContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::WhileContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::StatContext* CalcParser::WhileContext::stat() {
  return getRuleContext<CalcParser::StatContext>(0);
}

CalcParser::WhileContext::WhileContext(StatContext *ctx) { copyFrom(ctx); }


std::any CalcParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IfContext::IF() {
  return getToken(CalcParser::IF, 0);
}

CalcParser::ExprContext* CalcParser::IfContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::IfContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

tree::TerminalNode* CalcParser::IfContext::THEN() {
  return getToken(CalcParser::THEN, 0);
}

CalcParser::StatContext* CalcParser::IfContext::stat() {
  return getRuleContext<CalcParser::StatContext>(0);
}

tree::TerminalNode* CalcParser::IfContext::ENDIF() {
  return getToken(CalcParser::ENDIF, 0);
}

CalcParser::IfContext::IfContext(StatContext *ctx) { copyFrom(ctx); }


std::any CalcParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::PrintExprContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::PrintExprContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::PrintExprContext::PrintExprContext(StatContext *ctx) { copyFrom(ctx); }


std::any CalcParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::AssignContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::ExprContext* CalcParser::AssignContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::AssignContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }


std::any CalcParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfelseContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IfelseContext::IF() {
  return getToken(CalcParser::IF, 0);
}

CalcParser::ExprContext* CalcParser::IfelseContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::IfelseContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

tree::TerminalNode* CalcParser::IfelseContext::THEN() {
  return getToken(CalcParser::THEN, 0);
}

std::vector<CalcParser::StatContext *> CalcParser::IfelseContext::stat() {
  return getRuleContexts<CalcParser::StatContext>();
}

CalcParser::StatContext* CalcParser::IfelseContext::stat(size_t i) {
  return getRuleContext<CalcParser::StatContext>(i);
}

tree::TerminalNode* CalcParser::IfelseContext::ELSE() {
  return getToken(CalcParser::ELSE, 0);
}

tree::TerminalNode* CalcParser::IfelseContext::ENDIF() {
  return getToken(CalcParser::ENDIF, 0);
}

CalcParser::IfelseContext::IfelseContext(StatContext *ctx) { copyFrom(ctx); }


std::any CalcParser::IfelseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitIfelse(this);
  else
    return visitor->visitChildren(this);
}
CalcParser::StatContext* CalcParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, CalcParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(43);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CalcParser::PrintExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(13);
      expr(0);
      setState(14);
      match(CalcParser::NEWLINE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CalcParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(16);
      match(CalcParser::ID);
      setState(17);
      match(CalcParser::T__0);
      setState(18);
      expr(0);
      setState(19);
      match(CalcParser::NEWLINE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CalcParser::IfContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(21);
      match(CalcParser::IF);
      setState(22);
      expr(0);
      setState(23);
      match(CalcParser::NEWLINE);
      setState(24);
      match(CalcParser::THEN);
      setState(25);
      stat();
      setState(26);
      match(CalcParser::ENDIF);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CalcParser::IfelseContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(28);
      match(CalcParser::IF);
      setState(29);
      expr(0);
      setState(30);
      match(CalcParser::NEWLINE);
      setState(31);
      match(CalcParser::THEN);
      setState(32);
      stat();
      setState(33);
      match(CalcParser::ELSE);
      setState(34);
      stat();
      setState(35);
      match(CalcParser::ENDIF);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CalcParser::WhileContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(37);
      match(CalcParser::WHILE);
      setState(38);
      expr(0);
      setState(39);
      match(CalcParser::NEWLINE);
      setState(40);
      stat();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CalcParser::BlankContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(42);
      match(CalcParser::NEWLINE);
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

//----------------- ExprContext ------------------------------------------------------------------

CalcParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcParser::ExprContext::getRuleIndex() const {
  return CalcParser::RuleExpr;
}

void CalcParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParentesisContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::ParentesisContext::LPAR() {
  return getToken(CalcParser::LPAR, 0);
}

CalcParser::ExprContext* CalcParser::ParentesisContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::ParentesisContext::RPAR() {
  return getToken(CalcParser::RPAR, 0);
}

CalcParser::ParentesisContext::ParentesisContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::ParentesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitParentesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MisteryContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::MisteryContext::MYSTERY() {
  return getToken(CalcParser::MYSTERY, 0);
}

tree::TerminalNode* CalcParser::MisteryContext::LPAR() {
  return getToken(CalcParser::LPAR, 0);
}

std::vector<CalcParser::ExprContext *> CalcParser::MisteryContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::MisteryContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::MisteryContext::RPAR() {
  return getToken(CalcParser::RPAR, 0);
}

std::vector<tree::TerminalNode *> CalcParser::MisteryContext::COMMA() {
  return getTokens(CalcParser::COMMA);
}

tree::TerminalNode* CalcParser::MisteryContext::COMMA(size_t i) {
  return getToken(CalcParser::COMMA, i);
}

CalcParser::MisteryContext::MisteryContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::MisteryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitMistery(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AbsContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::AbsContext::ABS() {
  return getToken(CalcParser::ABS, 0);
}

tree::TerminalNode* CalcParser::AbsContext::LPAR() {
  return getToken(CalcParser::LPAR, 0);
}

CalcParser::ExprContext* CalcParser::AbsContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::AbsContext::RPAR() {
  return getToken(CalcParser::RPAR, 0);
}

CalcParser::AbsContext::AbsContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::AbsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitAbs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::MultContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::MultContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::MultContext::MUL() {
  return getToken(CalcParser::MUL, 0);
}

tree::TerminalNode* CalcParser::MultContext::DIV() {
  return getToken(CalcParser::DIV, 0);
}

tree::TerminalNode* CalcParser::MultContext::MOD() {
  return getToken(CalcParser::MOD, 0);
}

CalcParser::MultContext::MultContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::NumContext::INT() {
  return getToken(CalcParser::INT, 0);
}

CalcParser::NumContext::NumContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::NumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitNum(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorialContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::FactorialContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::FactorialContext::FACTORIAL() {
  return getToken(CalcParser::FACTORIAL, 0);
}

CalcParser::FactorialContext::FactorialContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::FactorialContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitFactorial(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::SignContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::SignContext::ADD() {
  return getToken(CalcParser::ADD, 0);
}

tree::TerminalNode* CalcParser::SignContext::SUB() {
  return getToken(CalcParser::SUB, 0);
}

CalcParser::SignContext::SignContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinmaxContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::MinmaxContext::MIN() {
  return getToken(CalcParser::MIN, 0);
}

tree::TerminalNode* CalcParser::MinmaxContext::LPAR() {
  return getToken(CalcParser::LPAR, 0);
}

std::vector<CalcParser::ExprContext *> CalcParser::MinmaxContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::MinmaxContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::MinmaxContext::COMMA() {
  return getToken(CalcParser::COMMA, 0);
}

tree::TerminalNode* CalcParser::MinmaxContext::RPAR() {
  return getToken(CalcParser::RPAR, 0);
}

tree::TerminalNode* CalcParser::MinmaxContext::MAX() {
  return getToken(CalcParser::MAX, 0);
}

CalcParser::MinmaxContext::MinmaxContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::MinmaxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitMinmax(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::ArithmeticContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::ArithmeticContext::ADD() {
  return getToken(CalcParser::ADD, 0);
}

tree::TerminalNode* CalcParser::ArithmeticContext::SUB() {
  return getToken(CalcParser::SUB, 0);
}

CalcParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::ArithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitArithmetic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IdContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::IdContext::IdContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisionContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::ComparisionContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::ComparisionContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::ComparisionContext::LESS() {
  return getToken(CalcParser::LESS, 0);
}

tree::TerminalNode* CalcParser::ComparisionContext::LE() {
  return getToken(CalcParser::LE, 0);
}

tree::TerminalNode* CalcParser::ComparisionContext::GE() {
  return getToken(CalcParser::GE, 0);
}

tree::TerminalNode* CalcParser::ComparisionContext::GRT() {
  return getToken(CalcParser::GRT, 0);
}

CalcParser::ComparisionContext::ComparisionContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::ComparisionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitComparision(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::EqualityContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::EqualityContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::EqualityContext::EQ() {
  return getToken(CalcParser::EQ, 0);
}

tree::TerminalNode* CalcParser::EqualityContext::NEQ() {
  return getToken(CalcParser::NEQ, 0);
}

CalcParser::EqualityContext::EqualityContext(ExprContext *ctx) { copyFrom(ctx); }


std::any CalcParser::EqualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitEquality(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ExprContext* CalcParser::expr() {
   return expr(0);
}

CalcParser::ExprContext* CalcParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalcParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CalcParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CalcParser::RuleExpr, precedence);

    size_t _la = 0;

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
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcParser::LPAR: {
        _localctx = _tracker.createInstance<ParentesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(46);
        match(CalcParser::LPAR);
        setState(47);
        expr(0);
        setState(48);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::ADD:
      case CalcParser::SUB: {
        _localctx = _tracker.createInstance<SignContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(50);
        _la = _input->LA(1);
        if (!(_la == CalcParser::ADD

        || _la == CalcParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(51);
        expr(11);
        break;
      }

      case CalcParser::ABS: {
        _localctx = _tracker.createInstance<AbsContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(52);
        match(CalcParser::ABS);
        setState(53);
        match(CalcParser::LPAR);
        setState(54);
        expr(0);
        setState(55);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::MIN: {
        _localctx = _tracker.createInstance<MinmaxContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(57);
        match(CalcParser::MIN);
        setState(58);
        match(CalcParser::LPAR);
        setState(59);
        expr(0);
        setState(60);
        match(CalcParser::COMMA);
        setState(61);
        expr(0);
        setState(62);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::MAX: {
        _localctx = _tracker.createInstance<MinmaxContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(64);
        match(CalcParser::MAX);
        setState(65);
        match(CalcParser::LPAR);
        setState(66);
        expr(0);
        setState(67);
        match(CalcParser::COMMA);
        setState(68);
        expr(0);
        setState(69);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::MYSTERY: {
        _localctx = _tracker.createInstance<MisteryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(71);
        match(CalcParser::MYSTERY);
        setState(72);
        match(CalcParser::LPAR);
        setState(73);
        expr(0);
        setState(78);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CalcParser::COMMA) {
          setState(74);
          match(CalcParser::COMMA);
          setState(75);
          expr(0);
          setState(80);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(81);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::INT: {
        _localctx = _tracker.createInstance<NumContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(83);
        match(CalcParser::INT);
        break;
      }

      case CalcParser::ID: {
        _localctx = _tracker.createInstance<IdContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(84);
        match(CalcParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(103);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(101);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(87);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(88);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 819200) != 0)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(89);
          expr(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(90);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(91);
          _la = _input->LA(1);
          if (!(_la == CalcParser::ADD

          || _la == CalcParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(92);
          expr(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ComparisionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(93);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(94);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 7680) != 0)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(95);
          expr(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualityContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(96);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(97);
          _la = _input->LA(1);
          if (!(_la == CalcParser::EQ

          || _la == CalcParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(98);
          expr(4);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<FactorialContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(99);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(100);
          match(CalcParser::FACTORIAL);
          break;
        }

        default:
          break;
        } 
      }
      setState(105);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CalcParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalcParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 13);

  default:
    break;
  }
  return true;
}

void CalcParser::initialize() {
  ::antlr4::internal::call_once(calcParserOnceFlag, calcParserInitialize);
}
