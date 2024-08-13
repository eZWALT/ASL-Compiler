
// Generated from Expr.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual std::any visitS(ExprParser::SContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParentesis(ExprParser::ParentesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbs(ExprParser::AbsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMin(ExprParser::MinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMult(ExprParser::MultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMax(ExprParser::MaxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNum(ExprParser::NumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSign(ExprParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic(ExprParser::ArithmeticContext *ctx) override {
    return visitChildren(ctx);
  }


};

