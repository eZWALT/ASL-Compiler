
// Generated from Asl.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, PLUS = 9, SUB = 10, MUL = 11, DIV = 12, MOD = 13, POW = 14, 
    LE = 15, LT = 16, GE = 17, GT = 18, EQ = 19, NEQ = 20, AND = 21, OR = 22, 
    NOT = 23, INT = 24, BOOL = 25, FLOAT = 26, CHAR = 27, ARRAY = 28, OF = 29, 
    VAR = 30, IF = 31, THEN = 32, ELSE = 33, ENDIF = 34, WHILE = 35, DO = 36, 
    ENDWHILE = 37, FUNC = 38, ENDFUNC = 39, READ = 40, WRITE = 41, RETURN = 42, 
    MAP = 43, INTO = 44, USING = 45, BOOLVAL = 46, ID = 47, INTVAL = 48, 
    FLOATVAL = 49, CHARVAL = 50, STRING = 51, COMMENT = 52, WS = 53
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

