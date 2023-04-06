
// Generated from Expr.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  ExprParser : public antlr4::Parser {
public:
  enum {
    MUL = 1, DIV = 2, ADD = 3, SUB = 4, MOD = 5, LPAR = 6, RPAR = 7, ABS = 8, 
    MIN = 9, MAX = 10, COMMA = 11, INT = 12, WS = 13
  };

  enum {
    RuleS = 0, RuleE = 1
  };

  explicit ExprParser(antlr4::TokenStream *input);

  ExprParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ExprParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class SContext;
  class EContext; 

  class  SContext : public antlr4::ParserRuleContext {
  public:
    SContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EContext *e();
    antlr4::tree::TerminalNode *EOF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SContext* s();

  class  EContext : public antlr4::ParserRuleContext {
  public:
    EContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EContext() = default;
    void copyFrom(EContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParentesisContext : public EContext {
  public:
    ParentesisContext(EContext *ctx);

    antlr4::tree::TerminalNode *LPAR();
    EContext *e();
    antlr4::tree::TerminalNode *RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AbsContext : public EContext {
  public:
    AbsContext(EContext *ctx);

    antlr4::tree::TerminalNode *ABS();
    antlr4::tree::TerminalNode *LPAR();
    EContext *e();
    antlr4::tree::TerminalNode *RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MinContext : public EContext {
  public:
    MinContext(EContext *ctx);

    antlr4::tree::TerminalNode *MIN();
    antlr4::tree::TerminalNode *LPAR();
    std::vector<EContext *> e();
    EContext* e(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultContext : public EContext {
  public:
    MultContext(EContext *ctx);

    std::vector<EContext *> e();
    EContext* e(size_t i);
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MaxContext : public EContext {
  public:
    MaxContext(EContext *ctx);

    antlr4::tree::TerminalNode *MAX();
    antlr4::tree::TerminalNode *LPAR();
    std::vector<EContext *> e();
    EContext* e(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumContext : public EContext {
  public:
    NumContext(EContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SignContext : public EContext {
  public:
    SignContext(EContext *ctx);

    EContext *e();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArithmeticContext : public EContext {
  public:
    ArithmeticContext(EContext *ctx);

    std::vector<EContext *> e();
    EContext* e(size_t i);
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EContext* e();
  EContext* e(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool eSempred(EContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

