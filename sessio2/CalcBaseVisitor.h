
// Generated from Calc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "CalcVisitor.h"


/**
 * This class provides an empty implementation of CalcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CalcBaseVisitor : public CalcVisitor {
public:

  virtual std::any visitProg(CalcParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintExpr(CalcParser::PrintExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(CalcParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlank(CalcParser::BlankContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParentesis(CalcParser::ParentesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMistery(CalcParser::MisteryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbs(CalcParser::AbsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMult(CalcParser::MultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNum(CalcParser::NumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSign(CalcParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMinmax(CalcParser::MinmaxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic(CalcParser::ArithmeticContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId(CalcParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }


};

