//////////////////////////////////////////////////////////////////////
//
//    TypeCheckVisitor - Walk the parser tree to do the semantic
//                       typecheck for the Asl programming language
//
//    Copyright (C) 2017-2023  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "TypeCheckVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr       & Types,
                                   SymTable       & Symbols,
                                   TreeDecoration & Decorations,
                                   SemErrors      & Errors) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId TypeCheckVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void TypeCheckVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    visit(ctxFunc);
  }
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  // Symbols.print();
  TypesMgr::TypeId tf = getTypeDecor(ctx);
  //std::cout << "Reported type of function is " << Types.to_string(tf) << std::endl;

  setCurrentFunctionTy(tf);

  visit(ctx->statements());
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitType(AslParser::TypeContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  //std::cout << "### left expression is type " << Types.to_string(t1) << std::endl;
  //std::cout << "### right value is type " << Types.to_string(t2) << '\n' << std::endl;
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.copyableTypes(t1, t2)))
    Errors.incompatibleAssignment(ctx->ASSIGN()); 
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  
  for (auto& ct : ctx->statements()) visit(ct);

  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReturn(AslParser::ReturnContext *ctx) {
  DEBUG_ENTER();
  if (ctx->expr()){
    visit(ctx->expr());
    TypesMgr::TypeId t = getTypeDecor(ctx->expr());

    //std::cout << "Return type is " << Types.to_string(t) << " and function type is " << Types.to_string(getCurrentFunctionTy()) << std::endl;

    if ((not Types.isErrorTy(t)) and (not Types.equalTypes(getCurrentFunctionTy(), t))) 
      Errors.incompatibleReturn(ctx->RETURN());  }
  
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  
  visit(ctx->statements());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();

    //Getting the function ID
  visit(ctx->ident());
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());

  //Checking if the function is not a function or has an terror type
  if((not Types.isFunctionTy(t)) and (not Types.isErrorTy(t))){
    Errors.isNotCallable(ctx->ident());
  } 
  else if(not Types.isErrorTy(t)){
    //Checking for number of arguments mismatch 
    int NumArgs = ctx->expr().size();
    std::size_t NumParameters = Types.getNumOfParameters(t);
    if((std::size_t) NumArgs != NumParameters) Errors.numberOfParameters(ctx->ident());

    //Checking for a mismatch in the types of the parameters given by the call
    //It may happen that an integer value is given to feed a float parameter anyway, but no any other type mismatch is correct
    auto types = Types.getFuncParamsTypes(t);
    for(unsigned int i = 0; i < types.size(); ++i){


      if(not Types.equalTypes( getTypeDecor(visit(ctx->expr(i))), types[i] )){
        if(not (Types.isFloatTy(types[i]) and Types.isIntegerTy( getTypeDecor(visit(ctx->expr(i))))))  Errors.incompatibleParameter(ctx->expr(i),i+1,ctx);
      } 
    }
  }


  putIsLValueDecor(ctx,false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

/*
antlrcpp::Any TypeCheckVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}*/

antlrcpp::Any TypeCheckVisitor::visitSimpleIdent(AslParser::SimpleIdentContext *ctx){
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArrayIdent(AslParser::ArrayIdentContext *ctx){
  DEBUG_ENTER();
  visit(ctx->ident());
  visit(ctx->expr());

  TypesMgr::TypeId texp = getTypeDecor(ctx->expr());
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());

  if (not Types.isErrorTy(texp) && not Types.isIntegerTy(texp))
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());

  if (not Types.isErrorTy(t) && not Types.isArrayTy(t)){
    Errors.nonArrayInArrayAccess(ctx);
    putTypeDecor(ctx, Types.createErrorTy());  
  } else {
    // IDENT [ EXPR ]
    putTypeDecor(ctx, Types.getArrayElemType(t));

  }

  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();

  return 0;

}

antlrcpp::Any TypeCheckVisitor::visitCall(AslParser::CallContext *ctx)
{
  DEBUG_ENTER();

  //Getting the function ID
  visit(ctx->ident());
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());
  TypesMgr::TypeId tRet;

  //Checking if the function is callable or not (maybe it was parsed correctly but it isn't a function at all like juan(a,b,c) ... )
  if(not Types.isFunctionTy(t)){
    Errors.isNotCallable(ctx->ident());
  } 
  else{
    //Checking for number of arguments mismatch 
    int NumArgs = ctx->expr().size();
    std::size_t NumParameters = Types.getNumOfParameters(t);
    if((std::size_t) NumArgs != NumParameters) Errors.numberOfParameters(ctx->ident());

    //Checking for a mismatch in the types of the parameters given by the call
    //It may happen that an integer value is given to feed a float parameter anyway, but no any other type mismatch is correct
    auto types = Types.getFuncParamsTypes(t);
    for(unsigned int i = 0; i < types.size(); ++i){


      if(not Types.equalTypes( getTypeDecor(visit(ctx->expr(i))), types[i] )){
        if(not (Types.isFloatTy(types[i]) and Types.isIntegerTy( getTypeDecor(visit(ctx->expr(i))))))  Errors.incompatibleParameter(ctx->expr(i),i+1,ctx);
      } 
    }
  }




  //If the type of the function is error, then this call is gonna be decorated as terror, otherwise is decorated with it's return type
  if (Types.isErrorTy(t)){
    tRet = Types.createErrorTy();
    putTypeDecor(ctx, tRet);
  }
  else if(Types.isVoidFunction(t)){
    tRet = Types.createErrorTy();
    putTypeDecor(ctx,tRet);
    Errors.isNotFunction(ctx->ident());
  }
  else {
    tRet = Symbols.getType(ctx->ident()->getText());
    putTypeDecor(ctx, Types.getFuncReturnType(tRet));
  }

  putIsLValueDecor(ctx,false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArray(AslParser::ArrayContext *ctx)
{
  DEBUG_ENTER();
  visit(ctx->ident());
  visit(ctx->expr());

  TypesMgr::TypeId texp = getTypeDecor(ctx->expr());
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());

  if (not Types.isErrorTy(texp) && not Types.isIntegerTy(texp))
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());

  if (not Types.isErrorTy(t) && not Types.isArrayTy(t)){
    Errors.nonArrayInArrayAccess(ctx);
    putTypeDecor(ctx, Types.createErrorTy());  
  } else {

    putTypeDecor(ctx, Types.getArrayElemType(t));

  }

  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();

  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitParen(AslParser::ParenContext *ctx)
{
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t = getTypeDecor(ctx->expr());

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));



  if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
    Errors.incompatibleOperator(ctx->op);

  // Module operation (%) can only be applied to integer operands. The expected behaviour for negative operands is the same than in C++.
  if ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2) || not Types.isIntegerTy(t1)) and (ctx->MOD()))
    Errors.incompatibleOperator(ctx->op);


  TypesMgr::TypeId r;

  if (Types.isFloatTy(t1) || Types.isFloatTy(t2)) r = Types.createFloatTy();
  else r = Types.createIntegerTy();

  putTypeDecor(ctx, r);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitUnary(AslParser::UnaryContext *ctx)
{
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t = getTypeDecor(ctx->expr());


  if (not Types.isErrorTy(t)){
    if (not Types.isNumericTy(t) && (ctx->PLUS() || ctx->SUB()))
      Errors.incompatibleOperator(ctx->op);
    else if (not Types.isBooleanTy(t) && ctx->NOT())
      Errors.incompatibleOperator(ctx->op);
  }

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitLogic(AslParser::LogicContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  if ((not Types.isErrorTy(t1) and (not Types.isBooleanTy(t1))) or
      (not Types.isErrorTy(t2) and (not Types.isBooleanTy(t2))))
        Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string oper = ctx->op->getText();
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t;

  if (ctx->INTVAL()) t = Types.createIntegerTy();
  else if (ctx->FLOATVAL()) t = Types.createFloatTy();
  else if (ctx->CHARVAL()) t = Types.createCharacterTy();
  else if (ctx->BOOLVAL()) t = Types.createBooleanTy();

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  std::string ident = ctx->getText();
  if (Symbols.findInStack(ident) == -1) {
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, true);
  }
  else {
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }
  DEBUG_EXIT();
  return 0;
}


// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
