
// Generated from Calc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "CalcParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CalcParser.
 */
class  CalcVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CalcParser.
   */
    virtual std::any visitProg(CalcParser::ProgContext *context) = 0;

    virtual std::any visitPrintExpr(CalcParser::PrintExprContext *context) = 0;

    virtual std::any visitAssign(CalcParser::AssignContext *context) = 0;

    virtual std::any visitBlank(CalcParser::BlankContext *context) = 0;

    virtual std::any visitParentesis(CalcParser::ParentesisContext *context) = 0;

    virtual std::any visitMistery(CalcParser::MisteryContext *context) = 0;

    virtual std::any visitAbs(CalcParser::AbsContext *context) = 0;

    virtual std::any visitMult(CalcParser::MultContext *context) = 0;

    virtual std::any visitNum(CalcParser::NumContext *context) = 0;

    virtual std::any visitSign(CalcParser::SignContext *context) = 0;

    virtual std::any visitMinmax(CalcParser::MinmaxContext *context) = 0;

    virtual std::any visitArithmetic(CalcParser::ArithmeticContext *context) = 0;

    virtual std::any visitId(CalcParser::IdContext *context) = 0;


};

