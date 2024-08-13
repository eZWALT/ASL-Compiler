
// Generated from Calc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CalcLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, IF = 2, THEN = 3, ELSE = 4, ENDIF = 5, WHILE = 6, EQ = 7, 
    NEQ = 8, LE = 9, GE = 10, LESS = 11, GRT = 12, LPAR = 13, RPAR = 14, 
    MUL = 15, ADD = 16, SUB = 17, MOD = 18, DIV = 19, ABS = 20, MIN = 21, 
    MAX = 22, COMMA = 23, FACTORIAL = 24, MYSTERY = 25, ID = 26, INT = 27, 
    NEWLINE = 28, WS = 29
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

