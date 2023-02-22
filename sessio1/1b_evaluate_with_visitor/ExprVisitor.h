
// Generated from Expr.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual std::any visitS(ExprParser::SContext *context) = 0;

    virtual std::any visitParentesis(ExprParser::ParentesisContext *context) = 0;

    virtual std::any visitAbs(ExprParser::AbsContext *context) = 0;

    virtual std::any visitMin(ExprParser::MinContext *context) = 0;

    virtual std::any visitMult(ExprParser::MultContext *context) = 0;

    virtual std::any visitMax(ExprParser::MaxContext *context) = 0;

    virtual std::any visitNum(ExprParser::NumContext *context) = 0;

    virtual std::any visitSign(ExprParser::SignContext *context) = 0;

    virtual std::any visitArithmetic(ExprParser::ArithmeticContext *context) = 0;


};

