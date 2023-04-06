
// Generated from Calc.g4 by ANTLR 4.11.1


#include "CalcLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CalcLexerStaticData final {
  CalcLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CalcLexerStaticData(const CalcLexerStaticData&) = delete;
  CalcLexerStaticData(CalcLexerStaticData&&) = delete;
  CalcLexerStaticData& operator=(const CalcLexerStaticData&) = delete;
  CalcLexerStaticData& operator=(CalcLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag calclexerLexerOnceFlag;
CalcLexerStaticData *calclexerLexerStaticData = nullptr;

void calclexerLexerInitialize() {
  assert(calclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<CalcLexerStaticData>(
    std::vector<std::string>{
      "T__0", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "EQ", "NEQ", "LE", 
      "GE", "LESS", "GRT", "LPAR", "RPAR", "MUL", "ADD", "SUB", "MOD", "DIV", 
      "ABS", "MIN", "MAX", "COMMA", "FACTORIAL", "MYSTERY", "ID", "INT", 
      "NEWLINE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,29,162,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,
  	8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,
  	14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,
  	20,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,
  	24,1,24,1,24,1,24,1,24,1,25,4,25,142,8,25,11,25,12,25,143,1,26,4,26,147,
  	8,26,11,26,12,26,148,1,27,3,27,152,8,27,1,27,1,27,1,28,4,28,157,8,28,
  	11,28,12,28,158,1,28,1,28,0,0,29,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,1,0,3,2,0,65,90,97,
  	122,1,0,48,57,2,0,9,9,32,32,165,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,
  	7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,
  	0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,
  	0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,
  	1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,
  	0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,1,59,1,0,0,0,
  	3,61,1,0,0,0,5,64,1,0,0,0,7,69,1,0,0,0,9,74,1,0,0,0,11,80,1,0,0,0,13,
  	86,1,0,0,0,15,89,1,0,0,0,17,92,1,0,0,0,19,95,1,0,0,0,21,98,1,0,0,0,23,
  	100,1,0,0,0,25,102,1,0,0,0,27,104,1,0,0,0,29,106,1,0,0,0,31,108,1,0,0,
  	0,33,110,1,0,0,0,35,112,1,0,0,0,37,114,1,0,0,0,39,116,1,0,0,0,41,120,
  	1,0,0,0,43,124,1,0,0,0,45,128,1,0,0,0,47,130,1,0,0,0,49,132,1,0,0,0,51,
  	141,1,0,0,0,53,146,1,0,0,0,55,151,1,0,0,0,57,156,1,0,0,0,59,60,5,61,0,
  	0,60,2,1,0,0,0,61,62,5,105,0,0,62,63,5,102,0,0,63,4,1,0,0,0,64,65,5,116,
  	0,0,65,66,5,104,0,0,66,67,5,101,0,0,67,68,5,110,0,0,68,6,1,0,0,0,69,70,
  	5,101,0,0,70,71,5,108,0,0,71,72,5,115,0,0,72,73,5,101,0,0,73,8,1,0,0,
  	0,74,75,5,101,0,0,75,76,5,110,0,0,76,77,5,100,0,0,77,78,5,105,0,0,78,
  	79,5,102,0,0,79,10,1,0,0,0,80,81,5,119,0,0,81,82,5,104,0,0,82,83,5,105,
  	0,0,83,84,5,108,0,0,84,85,5,101,0,0,85,12,1,0,0,0,86,87,5,61,0,0,87,88,
  	5,61,0,0,88,14,1,0,0,0,89,90,5,33,0,0,90,91,5,61,0,0,91,16,1,0,0,0,92,
  	93,5,60,0,0,93,94,5,61,0,0,94,18,1,0,0,0,95,96,5,62,0,0,96,97,5,61,0,
  	0,97,20,1,0,0,0,98,99,5,60,0,0,99,22,1,0,0,0,100,101,5,62,0,0,101,24,
  	1,0,0,0,102,103,5,40,0,0,103,26,1,0,0,0,104,105,5,41,0,0,105,28,1,0,0,
  	0,106,107,5,42,0,0,107,30,1,0,0,0,108,109,5,43,0,0,109,32,1,0,0,0,110,
  	111,5,45,0,0,111,34,1,0,0,0,112,113,5,37,0,0,113,36,1,0,0,0,114,115,5,
  	47,0,0,115,38,1,0,0,0,116,117,5,97,0,0,117,118,5,98,0,0,118,119,5,115,
  	0,0,119,40,1,0,0,0,120,121,5,109,0,0,121,122,5,105,0,0,122,123,5,110,
  	0,0,123,42,1,0,0,0,124,125,5,109,0,0,125,126,5,97,0,0,126,127,5,120,0,
  	0,127,44,1,0,0,0,128,129,5,44,0,0,129,46,1,0,0,0,130,131,5,33,0,0,131,
  	48,1,0,0,0,132,133,5,109,0,0,133,134,5,105,0,0,134,135,5,115,0,0,135,
  	136,5,116,0,0,136,137,5,101,0,0,137,138,5,114,0,0,138,139,5,121,0,0,139,
  	50,1,0,0,0,140,142,7,0,0,0,141,140,1,0,0,0,142,143,1,0,0,0,143,141,1,
  	0,0,0,143,144,1,0,0,0,144,52,1,0,0,0,145,147,7,1,0,0,146,145,1,0,0,0,
  	147,148,1,0,0,0,148,146,1,0,0,0,148,149,1,0,0,0,149,54,1,0,0,0,150,152,
  	5,13,0,0,151,150,1,0,0,0,151,152,1,0,0,0,152,153,1,0,0,0,153,154,5,10,
  	0,0,154,56,1,0,0,0,155,157,7,2,0,0,156,155,1,0,0,0,157,158,1,0,0,0,158,
  	156,1,0,0,0,158,159,1,0,0,0,159,160,1,0,0,0,160,161,6,28,0,0,161,58,1,
  	0,0,0,5,0,143,148,151,158,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calclexerLexerStaticData = staticData.release();
}

}

CalcLexer::CalcLexer(CharStream *input) : Lexer(input) {
  CalcLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *calclexerLexerStaticData->atn, calclexerLexerStaticData->decisionToDFA, calclexerLexerStaticData->sharedContextCache);
}

CalcLexer::~CalcLexer() {
  delete _interpreter;
}

std::string CalcLexer::getGrammarFileName() const {
  return "Calc.g4";
}

const std::vector<std::string>& CalcLexer::getRuleNames() const {
  return calclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CalcLexer::getChannelNames() const {
  return calclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CalcLexer::getModeNames() const {
  return calclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CalcLexer::getVocabulary() const {
  return calclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CalcLexer::getSerializedATN() const {
  return calclexerLexerStaticData->serializedATN;
}

const atn::ATN& CalcLexer::getATN() const {
  return *calclexerLexerStaticData->atn;
}




void CalcLexer::initialize() {
  ::antlr4::internal::call_once(calclexerLexerOnceFlag, calclexerLexerInitialize);
}
