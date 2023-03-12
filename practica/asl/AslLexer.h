
// Generated from Asl.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, ASSIGN = 6, PLUS = 7, 
    SUB = 8, MUL = 9, DIV = 10, MOD = 11, LE = 12, LT = 13, GE = 14, GT = 15, 
    EQ = 16, NEQ = 17, AND = 18, OR = 19, NOT = 20, INT = 21, BOOL = 22, 
    FLOAT = 23, CHAR = 24, VAR = 25, IF = 26, THEN = 27, ELSE = 28, ENDIF = 29, 
    FUNC = 30, ENDFUNC = 31, READ = 32, WRITE = 33, ID = 34, INTVAL = 35, 
    FLOATVAL = 36, BOOLVAL = 37, CHARVAL = 38, STRING = 39, COMMENT = 40, 
    WS = 41
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

