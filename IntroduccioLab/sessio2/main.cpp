
#include "antlr4-runtime.h"
#include "CalcLexer.h"
#include "CalcParser.h"
#include "CalcBaseVisitor.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdio>     // fopen
#include <cstdlib>    // EXIT_FAILURE, EXIT_SUCCESS

// using namespace std;
// using namespace antlr4;
// using namespace antlrcpp;


//////////////////////////////////////////////////////////////////////
// Sample "calculator" (implemented with a visitor)
class Calculator : public CalcBaseVisitor {
public:
  // "memory" for the calculator; variable/value pairs go here
  std::map<std::string, int> memory;

  // stat : expr NEWLINE
  antlrcpp::Any visitPrintExpr(CalcParser::PrintExprContext *ctx) {
    int value = std::any_cast<int>(visit(ctx->expr()));         // evaluate the expr child
    std::cout << value << std::endl;        // print the result
    return 0;                               // return dummy value
  }

  // stat : ID '=' expr NEWLINE
  antlrcpp::Any visitAssign(CalcParser::AssignContext *ctx) {
    std::string id = ctx->ID()->getText();  // id is left-hand side of '='
    int value = std::any_cast<int>(visit(ctx->expr()));         // compute value of expression on right
    memory[id] = value;                     // store it in the memory
    return 0;                               // return dummy value
  }

  antlrcpp::Any visitParentesis(CalcParser::ParentesisContext *ctx){
    return std::any_cast<int>(visit(ctx->expr()));
  }

  antlrcpp::Any visitSign(CalcParser::SignContext *ctx){
    int num = std::any_cast<int>(ctx->expr());
    if(ctx->ADD()) return num;
    else return - num;
  }

  antlrcpp::Any visitNum(CalcParser::NumContext *ctx){
    return std::stoi(ctx->INT()->getText());
  }
  
  antlrcpp::Any visitMinmax(CalcParser::MinmaxContext *ctx){
    int left = std::any_cast<int>(visit(ctx->expr(0)));
    int right= std::any_cast<int>(visit(ctx->expr(1)));
    if(ctx->MAX()) return std::max(left,right); 
    else return std::min(left,right);
  }

  antlrcpp::Any visitAbs(CalcParser::AbsContext * ctx){
    return std::abs(std::any_cast<int>(visit(ctx->expr())));
  }

  antlrcpp::Any visitArithmetic(CalcParser::ArithmeticContext *ctx){
    int n1 = std::any_cast<int>(visit(ctx->expr(0)));
    int n2 = std::any_cast<int>(visit(ctx->expr(1)));
    if(ctx->ADD()) return n1 + n2;
    else return n1 - n2;
  }

  antlrcpp::Any visitMult(CalcParser::MultContext *ctx){
    int n1 = std::any_cast<int>(visit(ctx->expr(0)));
    int n2 = std::any_cast<int>(visit(ctx->expr(1)));
    if(ctx->MUL()) return n1 * n2;
    else if(ctx->MOD()) return n1%n2;
    else return n1/n2;
  }
  
  antlrcpp::Any visitId(CalcParser::IdContext *ctx){
    std::string key = ctx->ID()->getText();
    if(memory.find(key) != memory.end()) return memory[key];
    else{
      std::cerr << "identifier not found, try again declaring a new variable with name " << key << std::endl; 
    }
    return 0;
  }

  antlrcpp::Any visitMistery(CalcParser::MisteryContext *ctx){
    int visente = 0;
    for(auto & context: ctx->expr()){
        int x = std::any_cast<int>(visit(context));
        visente += x*x;
    }
    return visente;
  }

  antlrcpp::Any visitFactorial(CalcParser::FactorialContext *ctx){
    int value = std::any_cast<int>(visit(ctx->expr()));
    int visente = 1;
    for(int i = value; i > 0; i--){
       visente = visente * i;
    }

    return visente;
  }

  antlrcpp::Any visitIf(CalcParser::IfContext *ctx){
    int evaluate = std::any_cast<int>(visit(ctx->expr()));
    //If the evaluation of the expression is different from zero, then it's a true and the statements below are executed
    if(evaluate != 0){
      visit(ctx->stat());
    }
    return NULL;
  }
  antlrcpp::Any visitIfelse(CalcParser::IfelseContext *ctx){
    int evaluate = std::any_cast<int>(visit(ctx->expr()));
    //If the evaluation of the expression is different from zero, then it's a true and the statements below are executed
    if(evaluate != 0) visit(ctx->stat(0));
    else visit(ctx->stat(1));
    return NULL;
  }

  antlrcpp::Any visitWhile(CalcParser::WhileContext *ctx){
    int condition = std::any_cast<int>(visit(ctx->expr()));
    while(condition != 0){
      visit(ctx->stat());
      condition = std::any_cast<int>(visit(ctx->expr()));
    }
    return NULL;
  }

  antlrcpp::Any visitEquality(CalcParser::EqualityContext *ctx){
    int a = std::any_cast<int>(visit(ctx->expr(0)));
    int b = std::any_cast<int>(visit(ctx->expr(1)));

    if(ctx->EQ()){
      if(a == b) return 1;
      else return 0;
    }
    else{
      if(a == b) return 0;
      else return 1;
    }

  }

    antlrcpp::Any visitComparision(CalcParser::ComparisionContext *ctx){
    int a = std::any_cast<int>(visit(ctx->expr(0)));
    int b = std::any_cast<int>(visit(ctx->expr(1)));

    if(ctx->LESS()){
      if(a < b) return 1;
      else return 0;
    }
    else if(ctx->GRT()){
      if(a > b) return 1;
      else return 0;
    }
    else if(ctx->LE()){
      if(a <= b) return 1;
      else return 0;
    }
    else{
      if(a >= b) return 1;
      else return 0;
    }

  }

 
};

// Sample "calculator" (implemented with a visitor)
//////////////////////////////////////////////////////////////////////


int main(int argc, const char* argv[]) {
  // check the correct use of the program
  if (argc > 2) {
    std::cout << "Usage: ./main [<file>]" << std::endl;
    return EXIT_FAILURE;
  }
  if (argc == 2 and not std::fopen(argv[1], "r")) {
    std::cout << "No such file: " << argv[1] << std::endl;
    return EXIT_FAILURE;
  }

  // open input file (or std::cin) and create a character stream
  antlr4::ANTLRInputStream input;
  if (argc == 2) {  // reads from <file>
    std::ifstream stream;
    stream.open(argv[1]);
    input = antlr4::ANTLRInputStream(stream);
  }
  else {            // reads fron std::cin
    input = antlr4::ANTLRInputStream(std::cin);
  }

  // create a lexer that consumes the character stream and produce a token stream
  CalcLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  // create a parser that consumes the token stream, and parses it.
  CalcParser parser(&tokens);

  // call the parser and get the parse tree. prog is the initial rule
  antlr4::tree::ParseTree *tree = parser.prog();

  // check for lexical or syntactical errors
  if (lexer.getNumberOfSyntaxErrors() > 0 or
      parser.getNumberOfSyntaxErrors() > 0) {
    std::cout << "Lexical and/or syntactical errors have been found." << std::endl;
    return EXIT_FAILURE;
  }
  
  // print the parse tree (for debugging purposes)
  std::cout << tree->toStringTree(&parser) << std::endl;

  ////////////////////////////////////////////////////////////////////

  // Create a visitor that will execute the statements
  Calculator calc;

  // Traverse the tree using this Calculator visitor
  calc.visit(tree);

  return EXIT_SUCCESS;
}
 
