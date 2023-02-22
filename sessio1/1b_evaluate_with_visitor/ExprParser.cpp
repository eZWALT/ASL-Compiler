
// Generated from Expr.g4 by ANTLR 4.11.1


#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ExprParserStaticData final {
  ExprParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExprParserStaticData(const ExprParserStaticData&) = delete;
  ExprParserStaticData(ExprParserStaticData&&) = delete;
  ExprParserStaticData& operator=(const ExprParserStaticData&) = delete;
  ExprParserStaticData& operator=(ExprParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag exprParserOnceFlag;
ExprParserStaticData *exprParserStaticData = nullptr;

void exprParserInitialize() {
  assert(exprParserStaticData == nullptr);
  auto staticData = std::make_unique<ExprParserStaticData>(
    std::vector<std::string>{
      "s", "e"
    },
    std::vector<std::string>{
      "", "'*'", "'/'", "'+'", "'-'", "'%'", "'('", "')'", "'abs'", "'min'", 
      "'max'", "','"
    },
    std::vector<std::string>{
      "", "MUL", "DIV", "ADD", "SUB", "MOD", "LPAR", "RPAR", "ABS", "MIN", 
      "MAX", "COMMA", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,13,48,2,0,7,0,2,1,7,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,3,1,35,8,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,43,8,1,10,1,12,1,46,9,1,
  	1,1,0,1,2,2,0,2,0,2,1,0,3,4,2,0,1,2,5,5,52,0,4,1,0,0,0,2,34,1,0,0,0,4,
  	5,3,2,1,0,5,6,5,0,0,1,6,1,1,0,0,0,7,8,6,1,-1,0,8,9,5,6,0,0,9,10,3,2,1,
  	0,10,11,5,7,0,0,11,35,1,0,0,0,12,13,7,0,0,0,13,35,3,2,1,7,14,15,5,8,0,
  	0,15,16,5,6,0,0,16,17,3,2,1,0,17,18,5,7,0,0,18,35,1,0,0,0,19,20,5,9,0,
  	0,20,21,5,6,0,0,21,22,3,2,1,0,22,23,5,11,0,0,23,24,3,2,1,0,24,25,5,7,
  	0,0,25,35,1,0,0,0,26,27,5,10,0,0,27,28,5,6,0,0,28,29,3,2,1,0,29,30,5,
  	11,0,0,30,31,3,2,1,0,31,32,5,7,0,0,32,35,1,0,0,0,33,35,5,12,0,0,34,7,
  	1,0,0,0,34,12,1,0,0,0,34,14,1,0,0,0,34,19,1,0,0,0,34,26,1,0,0,0,34,33,
  	1,0,0,0,35,44,1,0,0,0,36,37,10,6,0,0,37,38,7,1,0,0,38,43,3,2,1,7,39,40,
  	10,5,0,0,40,41,7,0,0,0,41,43,3,2,1,6,42,36,1,0,0,0,42,39,1,0,0,0,43,46,
  	1,0,0,0,44,42,1,0,0,0,44,45,1,0,0,0,45,3,1,0,0,0,46,44,1,0,0,0,3,34,42,
  	44
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  exprParserStaticData = staticData.release();
}

}

ExprParser::ExprParser(TokenStream *input) : ExprParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ExprParser::ExprParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ExprParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *exprParserStaticData->atn, exprParserStaticData->decisionToDFA, exprParserStaticData->sharedContextCache, options);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

const atn::ATN& ExprParser::getATN() const {
  return *exprParserStaticData->atn;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return exprParserStaticData->ruleNames;
}

const dfa::Vocabulary& ExprParser::getVocabulary() const {
  return exprParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExprParser::getSerializedATN() const {
  return exprParserStaticData->serializedATN;
}


//----------------- SContext ------------------------------------------------------------------

ExprParser::SContext::SContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::EContext* ExprParser::SContext::e() {
  return getRuleContext<ExprParser::EContext>(0);
}

tree::TerminalNode* ExprParser::SContext::EOF() {
  return getToken(ExprParser::EOF, 0);
}


size_t ExprParser::SContext::getRuleIndex() const {
  return ExprParser::RuleS;
}


std::any ExprParser::SContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitS(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SContext* ExprParser::s() {
  SContext *_localctx = _tracker.createInstance<SContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    e(0);
    setState(5);
    match(ExprParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EContext ------------------------------------------------------------------

ExprParser::EContext::EContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::EContext::getRuleIndex() const {
  return ExprParser::RuleE;
}

void ExprParser::EContext::copyFrom(EContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParentesisContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ParentesisContext::LPAR() {
  return getToken(ExprParser::LPAR, 0);
}

ExprParser::EContext* ExprParser::ParentesisContext::e() {
  return getRuleContext<ExprParser::EContext>(0);
}

tree::TerminalNode* ExprParser::ParentesisContext::RPAR() {
  return getToken(ExprParser::RPAR, 0);
}

ExprParser::ParentesisContext::ParentesisContext(EContext *ctx) { copyFrom(ctx); }


std::any ExprParser::ParentesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParentesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AbsContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::AbsContext::ABS() {
  return getToken(ExprParser::ABS, 0);
}

tree::TerminalNode* ExprParser::AbsContext::LPAR() {
  return getToken(ExprParser::LPAR, 0);
}

ExprParser::EContext* ExprParser::AbsContext::e() {
  return getRuleContext<ExprParser::EContext>(0);
}

tree::TerminalNode* ExprParser::AbsContext::RPAR() {
  return getToken(ExprParser::RPAR, 0);
}

ExprParser::AbsContext::AbsContext(EContext *ctx) { copyFrom(ctx); }


std::any ExprParser::AbsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAbs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::MinContext::MIN() {
  return getToken(ExprParser::MIN, 0);
}

tree::TerminalNode* ExprParser::MinContext::LPAR() {
  return getToken(ExprParser::LPAR, 0);
}

std::vector<ExprParser::EContext *> ExprParser::MinContext::e() {
  return getRuleContexts<ExprParser::EContext>();
}

ExprParser::EContext* ExprParser::MinContext::e(size_t i) {
  return getRuleContext<ExprParser::EContext>(i);
}

tree::TerminalNode* ExprParser::MinContext::COMMA() {
  return getToken(ExprParser::COMMA, 0);
}

tree::TerminalNode* ExprParser::MinContext::RPAR() {
  return getToken(ExprParser::RPAR, 0);
}

ExprParser::MinContext::MinContext(EContext *ctx) { copyFrom(ctx); }


std::any ExprParser::MinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<ExprParser::EContext *> ExprParser::MultContext::e() {
  return getRuleContexts<ExprParser::EContext>();
}

ExprParser::EContext* ExprParser::MultContext::e(size_t i) {
  return getRuleContext<ExprParser::EContext>(i);
}

tree::TerminalNode* ExprParser::MultContext::MUL() {
  return getToken(ExprParser::MUL, 0);
}

tree::TerminalNode* ExprParser::MultContext::DIV() {
  return getToken(ExprParser::DIV, 0);
}

tree::TerminalNode* ExprParser::MultContext::MOD() {
  return getToken(ExprParser::MOD, 0);
}

ExprParser::MultContext::MultContext(EContext *ctx) { copyFrom(ctx); }


std::any ExprParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MaxContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::MaxContext::MAX() {
  return getToken(ExprParser::MAX, 0);
}

tree::TerminalNode* ExprParser::MaxContext::LPAR() {
  return getToken(ExprParser::LPAR, 0);
}

std::vector<ExprParser::EContext *> ExprParser::MaxContext::e() {
  return getRuleContexts<ExprParser::EContext>();
}

ExprParser::EContext* ExprParser::MaxContext::e(size_t i) {
  return getRuleContext<ExprParser::EContext>(i);
}

tree::TerminalNode* ExprParser::MaxContext::COMMA() {
  return getToken(ExprParser::COMMA, 0);
}

tree::TerminalNode* ExprParser::MaxContext::RPAR() {
  return getToken(ExprParser::RPAR, 0);
}

ExprParser::MaxContext::MaxContext(EContext *ctx) { copyFrom(ctx); }


std::any ExprParser::MaxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMax(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::NumContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::NumContext::NumContext(EContext *ctx) { copyFrom(ctx); }


std::any ExprParser::NumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitNum(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignContext ------------------------------------------------------------------

ExprParser::EContext* ExprParser::SignContext::e() {
  return getRuleContext<ExprParser::EContext>(0);
}

tree::TerminalNode* ExprParser::SignContext::ADD() {
  return getToken(ExprParser::ADD, 0);
}

tree::TerminalNode* ExprParser::SignContext::SUB() {
  return getToken(ExprParser::SUB, 0);
}

ExprParser::SignContext::SignContext(EContext *ctx) { copyFrom(ctx); }


std::any ExprParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<ExprParser::EContext *> ExprParser::ArithmeticContext::e() {
  return getRuleContexts<ExprParser::EContext>();
}

ExprParser::EContext* ExprParser::ArithmeticContext::e(size_t i) {
  return getRuleContext<ExprParser::EContext>(i);
}

tree::TerminalNode* ExprParser::ArithmeticContext::ADD() {
  return getToken(ExprParser::ADD, 0);
}

tree::TerminalNode* ExprParser::ArithmeticContext::SUB() {
  return getToken(ExprParser::SUB, 0);
}

ExprParser::ArithmeticContext::ArithmeticContext(EContext *ctx) { copyFrom(ctx); }


std::any ExprParser::ArithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArithmetic(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::EContext* ExprParser::e() {
   return e(0);
}

ExprParser::EContext* ExprParser::e(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::EContext *_localctx = _tracker.createInstance<EContext>(_ctx, parentState);
  ExprParser::EContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ExprParser::RuleE, precedence);

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
    setState(34);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::LPAR: {
        _localctx = _tracker.createInstance<ParentesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(8);
        match(ExprParser::LPAR);
        setState(9);
        e(0);
        setState(10);
        match(ExprParser::RPAR);
        break;
      }

      case ExprParser::ADD:
      case ExprParser::SUB: {
        _localctx = _tracker.createInstance<SignContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(12);
        _la = _input->LA(1);
        if (!(_la == ExprParser::ADD

        || _la == ExprParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(13);
        e(7);
        break;
      }

      case ExprParser::ABS: {
        _localctx = _tracker.createInstance<AbsContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(14);
        match(ExprParser::ABS);
        setState(15);
        match(ExprParser::LPAR);
        setState(16);
        e(0);
        setState(17);
        match(ExprParser::RPAR);
        break;
      }

      case ExprParser::MIN: {
        _localctx = _tracker.createInstance<MinContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(19);
        match(ExprParser::MIN);
        setState(20);
        match(ExprParser::LPAR);
        setState(21);
        e(0);
        setState(22);
        match(ExprParser::COMMA);
        setState(23);
        e(0);
        setState(24);
        match(ExprParser::RPAR);
        break;
      }

      case ExprParser::MAX: {
        _localctx = _tracker.createInstance<MaxContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(26);
        match(ExprParser::MAX);
        setState(27);
        match(ExprParser::LPAR);
        setState(28);
        e(0);
        setState(29);
        match(ExprParser::COMMA);
        setState(30);
        e(0);
        setState(31);
        match(ExprParser::RPAR);
        break;
      }

      case ExprParser::INT: {
        _localctx = _tracker.createInstance<NumContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(33);
        match(ExprParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(44);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(42);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<EContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleE);
          setState(36);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(37);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 38) != 0)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(38);
          e(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<EContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleE);
          setState(39);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(40);
          _la = _input->LA(1);
          if (!(_la == ExprParser::ADD

          || _la == ExprParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(41);
          e(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(46);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return eSempred(antlrcpp::downCast<EContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::eSempred(EContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void ExprParser::initialize() {
  ::antlr4::internal::call_once(exprParserOnceFlag, exprParserInitialize);
}
