
// Generated from Calc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CalcLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, LPAR = 2, RPAR = 3, MUL = 4, ADD = 5, SUB = 6, MOD = 7, DIV = 8, 
    ABS = 9, MIN = 10, MAX = 11, COMMA = 12, MYSTERY = 13, ID = 14, INT = 15, 
    NEWLINE = 16, WS = 17
  };

  explicit CalcLexer(antlr4::CharStream *input);

  ~CalcLexer() override;


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

