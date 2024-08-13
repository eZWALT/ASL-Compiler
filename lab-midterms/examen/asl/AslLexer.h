
// Generated from Asl.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, ASSIGN = 11, PLUS = 12, SUB = 13, MUL = 14, 
    DIV = 15, MOD = 16, LE = 17, LT = 18, GE = 19, GT = 20, EQ = 21, NEQ = 22, 
    AND = 23, OR = 24, NOT = 25, INT = 26, BOOL = 27, FLOAT = 28, CHAR = 29, 
    ARRAY = 30, OF = 31, VAR = 32, IF = 33, THEN = 34, ELSE = 35, ENDIF = 36, 
    WHILE = 37, DO = 38, ENDWHILE = 39, FUNC = 40, ENDFUNC = 41, READ = 42, 
    WRITE = 43, RETURN = 44, BOOLVAL = 45, ID = 46, INTVAL = 47, FLOATVAL = 48, 
    CHARVAL = 49, STRING = 50, COMMENT = 51, WS = 52
  };

  explicit AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

