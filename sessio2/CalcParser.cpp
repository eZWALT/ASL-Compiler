
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
      "", "'='", "'('", "')'", "'*'", "'+'", "'-'", "'%'", "'/'", "'abs'", 
      "'min'", "'max'", "','", "'mistery'"
    },
    std::vector<std::string>{
      "", "", "LPAR", "RPAR", "MUL", "ADD", "SUB", "MOD", "DIV", "ABS", 
      "MIN", "MAX", "COMMA", "MYSTERY", "ID", "INT", "NEWLINE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,17,78,2,0,7,0,2,1,7,1,2,2,7,2,1,0,4,0,8,8,0,11,0,12,0,9,1,0,1,0,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,23,8,1,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,56,8,2,10,2,12,2,59,9,2,1,2,1,2,1,2,
  	1,2,3,2,65,8,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,73,8,2,10,2,12,2,76,9,2,1,
  	2,0,1,4,3,0,2,4,0,2,1,0,5,6,2,0,4,4,7,8,87,0,7,1,0,0,0,2,22,1,0,0,0,4,
  	64,1,0,0,0,6,8,3,2,1,0,7,6,1,0,0,0,8,9,1,0,0,0,9,7,1,0,0,0,9,10,1,0,0,
  	0,10,11,1,0,0,0,11,12,5,0,0,1,12,1,1,0,0,0,13,14,3,4,2,0,14,15,5,16,0,
  	0,15,23,1,0,0,0,16,17,5,14,0,0,17,18,5,1,0,0,18,19,3,4,2,0,19,20,5,16,
  	0,0,20,23,1,0,0,0,21,23,5,16,0,0,22,13,1,0,0,0,22,16,1,0,0,0,22,21,1,
  	0,0,0,23,3,1,0,0,0,24,25,6,2,-1,0,25,26,5,2,0,0,26,27,3,4,2,0,27,28,5,
  	3,0,0,28,65,1,0,0,0,29,30,7,0,0,0,30,65,3,4,2,9,31,32,5,9,0,0,32,33,5,
  	2,0,0,33,34,3,4,2,0,34,35,5,3,0,0,35,65,1,0,0,0,36,37,5,10,0,0,37,38,
  	5,2,0,0,38,39,3,4,2,0,39,40,5,12,0,0,40,41,3,4,2,0,41,42,5,3,0,0,42,65,
  	1,0,0,0,43,44,5,11,0,0,44,45,5,2,0,0,45,46,3,4,2,0,46,47,5,12,0,0,47,
  	48,3,4,2,0,48,49,5,3,0,0,49,65,1,0,0,0,50,51,5,13,0,0,51,52,5,2,0,0,52,
  	57,3,4,2,0,53,54,5,12,0,0,54,56,3,4,2,0,55,53,1,0,0,0,56,59,1,0,0,0,57,
  	55,1,0,0,0,57,58,1,0,0,0,58,60,1,0,0,0,59,57,1,0,0,0,60,61,5,3,0,0,61,
  	65,1,0,0,0,62,65,5,15,0,0,63,65,5,14,0,0,64,24,1,0,0,0,64,29,1,0,0,0,
  	64,31,1,0,0,0,64,36,1,0,0,0,64,43,1,0,0,0,64,50,1,0,0,0,64,62,1,0,0,0,
  	64,63,1,0,0,0,65,74,1,0,0,0,66,67,10,8,0,0,67,68,7,1,0,0,68,73,3,4,2,
  	9,69,70,10,7,0,0,70,71,7,0,0,0,71,73,3,4,2,8,72,66,1,0,0,0,72,69,1,0,
  	0,0,73,76,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,5,1,0,0,0,76,74,1,0,
  	0,0,6,9,22,57,64,72,74
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
      ((1ULL << _la) & 126564) != 0);
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
    setState(22);
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
      _localctx = _tracker.createInstance<CalcParser::BlankContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(21);
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
    setState(64);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcParser::LPAR: {
        _localctx = _tracker.createInstance<ParentesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(25);
        match(CalcParser::LPAR);
        setState(26);
        expr(0);
        setState(27);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::ADD:
      case CalcParser::SUB: {
        _localctx = _tracker.createInstance<SignContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(29);
        _la = _input->LA(1);
        if (!(_la == CalcParser::ADD

        || _la == CalcParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(30);
        expr(9);
        break;
      }

      case CalcParser::ABS: {
        _localctx = _tracker.createInstance<AbsContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(31);
        match(CalcParser::ABS);
        setState(32);
        match(CalcParser::LPAR);
        setState(33);
        expr(0);
        setState(34);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::MIN: {
        _localctx = _tracker.createInstance<MinmaxContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(36);
        match(CalcParser::MIN);
        setState(37);
        match(CalcParser::LPAR);
        setState(38);
        expr(0);
        setState(39);
        match(CalcParser::COMMA);
        setState(40);
        expr(0);
        setState(41);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::MAX: {
        _localctx = _tracker.createInstance<MinmaxContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(43);
        match(CalcParser::MAX);
        setState(44);
        match(CalcParser::LPAR);
        setState(45);
        expr(0);
        setState(46);
        match(CalcParser::COMMA);
        setState(47);
        expr(0);
        setState(48);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::MYSTERY: {
        _localctx = _tracker.createInstance<MisteryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(50);
        match(CalcParser::MYSTERY);
        setState(51);
        match(CalcParser::LPAR);
        setState(52);
        expr(0);
        setState(57);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CalcParser::COMMA) {
          setState(53);
          match(CalcParser::COMMA);
          setState(54);
          expr(0);
          setState(59);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(60);
        match(CalcParser::RPAR);
        break;
      }

      case CalcParser::INT: {
        _localctx = _tracker.createInstance<NumContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(62);
        match(CalcParser::INT);
        break;
      }

      case CalcParser::ID: {
        _localctx = _tracker.createInstance<IdContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(63);
        match(CalcParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(74);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(72);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(66);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(67);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 400) != 0)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(68);
          expr(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(69);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(70);
          _la = _input->LA(1);
          if (!(_la == CalcParser::ADD

          || _la == CalcParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(71);
          expr(8);
          break;
        }

        default:
          break;
        } 
      }
      setState(76);
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
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

void CalcParser::initialize() {
  ::antlr4::internal::call_once(calcParserOnceFlag, calcParserInitialize);
}
