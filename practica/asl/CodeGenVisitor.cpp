//////////////////////////////////////////////////////////////////////
//
//    CodeGenVisitor - Walk the parser tree to do
//                     the generation of code
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

#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>
#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenVisitor::CodeGenVisitor(TypesMgr       & Types,
                               SymTable       & Symbols,
                               TreeDecoration & Decorations) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId CodeGenVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void CodeGenVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any CodeGenVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  code my_code;
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    subroutine subr = visit(ctxFunc);
    my_code.add_subroutine(subr);
  }
  Symbols.popScope();
  DEBUG_EXIT();
  return my_code;
}

antlrcpp::Any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  subroutine subr(ctx->ID(0)->getText());
  codeCounters.reset();
  std::vector<var> && lvars = visit(ctx->declarations());
  for (auto & onevar : lvars) {
    subr.add_var(onevar);
  }

  if (ctx->basic_type()){
    visit(ctx->basic_type());
    TypesMgr::TypeId t = getTypeDecor(ctx->basic_type());

    subr.add_param("_result", Types.to_string(t), false);
  }

  for (uint i = 1; i < ctx->ID().size(); ++i){
    visit(ctx->type(i-1));
    TypesMgr::TypeId t = getTypeDecor(ctx->type(i-1));

    subr.add_param(ctx->ID(i)->getText(),Types.to_string(t), false); // Podra ser una array (true)
  }

  instructionList && code = visit(ctx->statements());
  code = code || instruction(instruction::RETURN());
  subr.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
  return subr;
}

antlrcpp::Any CodeGenVisitor::visitReturn(AslParser::ReturnContext *ctx){
 DEBUG_ENTER();
  
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string           addr1 = codAtsE.addr;
  instructionList &     code1 = codAtsE.code;

  //ALEX CREC QUE CAL POSARLI : RETURN CODE || INSTRUCTION::NOOP(); i no com estaba abans
  if (not ctx->expr()){
    return code || instruction::NOOP();
  } 

  code = code1 || instruction::LOAD("_result", addr1);

  return code;

  DEBUG_EXIT();
}

antlrcpp::Any CodeGenVisitor::visitCall(AslParser::CallContext *ctx){
  DEBUG_ENTER();
  
  std::string temp = "%"+codeCounters.newTEMP();
  instructionList code;
  auto typesParams = Types.getFuncParamsTypes(getTypeDecor(ctx->ident()));

  code = instruction::PUSH();

  uint i = 0;
  for (auto & exprCtx : ctx->expr()){
    CodeAttribs && codAts = visit(exprCtx);

    std::string addr = codAts.addr;
    instructionList & code1 = codAts.code;
    code = code || code1;

    //type coertion for floats and array parameters load
    TypesMgr::TypeId tparam = getTypeDecor(exprCtx);
    std::string temp = addr;
    if(Types.isFloatTy(typesParams[i]) and Types.isIntegerTy(tparam)){
      temp = "%" + codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp,addr);
      addr = temp;
    }
    else if(Types.isArrayTy(tparam)){
      temp = "%" + codeCounters.newTEMP();
      code = code || instruction::ALOAD(temp, addr);
      addr = temp;
    }

    code = code || instruction::PUSH(addr);
    ++i;
  }

  code = code || instruction::CALL(ctx->ident()->getText());

  for (auto & exprCtx : ctx->expr()){
    code = code || instruction::POP();
  }

  code = code || instruction::POP(temp);
  
  CodeAttribs codAts(temp, "", code);

  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx){
  DEBUG_ENTER();

  instructionList code;

  for (auto & exprCtx : ctx->expr()){
    CodeAttribs && codAts = visit(exprCtx);

    std::string addr = codAts.addr;
    instructionList & code1 = codAts.code;

    code = code || code1 || instruction::PUSH(addr);
  }

  code = code || instruction::CALL(ctx->ident()->getText());

  for (auto & exprCtx : ctx->expr()){
    code = code || instruction::POP();
  }
  
  DEBUG_EXIT();
  return code;
}


antlrcpp::Any CodeGenVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> lvars;

  for (auto & varDeclCtx : ctx->variable_decl()) {
    std::vector<var> manyvar = visit(varDeclCtx);
    for (auto & onevar : manyvar)
      lvars.push_back(onevar);
  }

  DEBUG_EXIT();
  return lvars;
}

antlrcpp::Any CodeGenVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId   t1 = getTypeDecor(ctx->type());
  std::size_t      size = Types.getSizeOfType(t1);
  std::vector<var> lvars;

  for (auto & idCtx : ctx->ID()){
    lvars.push_back( var{idCtx->getText(), Types.to_string(t1), size} );
  }
  DEBUG_EXIT();
  return lvars;
}

antlrcpp::Any CodeGenVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    instructionList && codeS = visit(stCtx);
    code = code || codeS;
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE1 = visit(ctx->left_expr());
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

  CodeAttribs     && codAtsE2 = visit(ctx->expr());
  std::string           addr2 = codAtsE2.addr;
  //std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());

  code = code1 || code2;


  //there are 2 different cases 
  // 1. a = b where those 2 are arrays
  // 2. a[i] = b where a is an array
  if(Types.isArrayTy(tid1) and Types.isArrayTy(tid2)){

    std::string labelSTART = "ArrayCpy" + codeCounters.newLabelWHILE();
    std::string labelEND   = "End" + labelEND;

    //if either one of the arrays is not a local var, then its a paramter (then its a pointer and needs to be loaded)
    if(not Symbols.isLocalVarClass(addr1)){
      std::string R7 = "%" + codeCounters.newTEMP();
      code = code || instruction::LOAD(R7,addr1);
      addr1 = R7;
    }

    if(not Symbols.isLocalVarClass(addr2)){
      std::string R6 = "%" + codeCounters.newTEMP();
      code = code || instruction::LOAD(R6,addr2);
      addr2 = R6;
    }

    //By precondition , if there's a size mismatch is checked on the TypeCheckVisitor
    std::string numElements = std::to_string(Types.getArraySize(tid1) - 1);

    std::string constantOne = "%" + codeCounters.newTEMP();
    std::string constantZero = "%" + codeCounters.newTEMP();
    std::string iTemp = "%" + codeCounters.newTEMP();
    std::string condTemp = "%" + codeCounters.newTEMP();
    std::string elemTemp = "%" + codeCounters.newTEMP();

    /* both arrays adddress are located in addr1(a) and addr2(b)  
              r1 = 0
              r2 = 1
              r3 = n 
       ArrayCpyX:
               si no  0 <= r3 goto ENDARRAYCPYX
               r4 = load( a[r3] )
               store(b[r3], r4)
               r3 = r3 - 1
               goto ARRAYCPYX

       EndArrayCpyX
    */

    code = code || instruction::LOAD(iTemp, numElements)
                || instruction::ILOAD(constantZero, "0")
                || instruction::ILOAD(constantOne, "1" )
                || instruction::LABEL(labelSTART)
                || instruction::LE(condTemp, constantZero, iTemp)
                || instruction::FJUMP(condTemp, labelEND)
                || instruction::LOADX(elemTemp, addr2, iTemp)
                || instruction::XLOAD(addr1, iTemp, elemTemp)
                || instruction::SUB(iTemp, iTemp, constantOne)
                || instruction::UJUMP(labelSTART)
                || instruction::LABEL(labelEND);

  }
  else{

    //float arrray, if the expr is an integer a cast is needed
    if(Types.isFloatTy(tid1) and Types.isIntegerTy(tid2)){

      std::string tempF = "%" + codeCounters.newTEMP();
      code = code || instruction::FLOAT(tempF, addr2);
      addr2 = tempF;
    }

    //code needed to load array[i] = expr (IF ITS AN ARRAY)
    if(Types.isArrayTy(tid1)){
      code = code || instruction::XLOAD(addr1,offs1,addr2);
    }
    //This is NOT an array
    else{
      code = code || instruction::LOAD(addr1,addr2);
    }

  }
  DEBUG_EXIT();

  return code;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;


  if (not ctx->ELSE()){
    instructionList &&   code2 = visit(ctx->statements(0));
    std::string label = codeCounters.newLabelIF();
    std::string labelEndIf = "Endif"+label;
    code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
          code2 || instruction::LABEL(labelEndIf);

  }
  else {
    instructionList &&   code2 = visit(ctx->statements(0));
    instructionList &&   code3 = visit(ctx->statements(1));
    std::string label = codeCounters.newLabelIF();
    std::string lab1 = "If"+label;
    std::string lab2 = "Else"+label;
    code = code1 || instruction::FJUMP(addr1, lab1) || code2 ||
          instruction::UJUMP(lab2) || instruction::LABEL(lab1) ||
          code3 || instruction::LABEL(lab2);

  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx){
  DEBUG_ENTER();

  instructionList code;
  CodeAttribs    && codAtsE = visit(ctx->expr());
  std::string         addr1 = codAtsE.addr;
  instructionList   & code1 = codAtsE.code;
  instructionList  && code2 = visit(ctx->statements());

  std::string         label = codeCounters.newLabelWHILE();
  std::string          lab1 = "While" + label;
  std::string          lab2 = "EndWhile" + label;
  
  code = instruction::LABEL(lab1) || code1 || instruction::FJUMP(addr1, lab2) ||
         code2 || instruction::UJUMP(lab1) || instruction::LABEL(lab2);

  DEBUG_EXIT();
  return code;

}



antlrcpp::Any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAtsE = visit(ctx->left_expr());
  std::string          addr1 = codAtsE.addr;
  // std::string          offs1 = codAtsE.offs;
  instructionList &    code1 = codAtsE.code;
  instructionList &     code = code1;
  // TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  code = code1 || instruction::READI(addr1);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  // std::string         offs1 = codAt1.offs;
  instructionList &   code1 = codAt1.code;
  instructionList &    code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  
  if (Types.isIntegerTy(tid1) || Types.isBooleanTy(tid1))
    code = code1 || instruction::WRITEI(addr1);
  else if (Types.isFloatTy(tid1))
    code = code1 || instruction::WRITEF(addr1);
  else if (Types.isCharacterTy(tid1))
    code = code1 || instruction::WRITEC(addr1);

  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string s = ctx->STRING()->getText();
  code = code || instruction::WRITES(s);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitSimpleIdent(AslParser::SimpleIdentContext *ctx){
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  DEBUG_EXIT();
  return codAts;

}

antlrcpp::Any CodeGenVisitor::visitArray(AslParser::ArrayContext *ctx){
  DEBUG_ENTER();
  CodeAttribs && codAtID = visit(ctx->ident());
  std::string addrID = codAtID.addr;
  instructionList & codeID = codAtID.code;

  CodeAttribs && codAtIdx = visit(ctx->expr());
  std::string addrIdx = codAtIdx.addr;
  instructionList & codeIdx = codAtIdx.code;
  //TypesMgr::TypeId IndexType = getTypeDecor(ctx->expr());

  instructionList && code = codeID || codeIdx;
  std::string value = "%" + codeCounters.newTEMP();

  //now we gotta check if the array load is done in a local var or in the pointer of a function paramter
  if(Symbols.isLocalVarClass(addrID)){
    code = code || instruction::LOADX(value,addrID,addrIdx);
  }
  else if(Symbols.isParameterClass(addrID)){
    std::string temp = "%" + codeCounters.newTEMP();
    code = code || instruction::LOAD(temp,addrID) || instruction::LOADX(value,temp,addrIdx);
  }

  CodeAttribs  codAts(value,"",code);
  DEBUG_EXIT();  
  return codAts;
}


// addrID [offID]
antlrcpp::Any CodeGenVisitor::visitArrayIdent(AslParser::ArrayIdentContext *ctx){
  DEBUG_ENTER();
  
  CodeAttribs && codeAttribID = visit(ctx->ident());
  std::string addrID = codeAttribID.addr;
  std::string offID  = "";
  instructionList & codeID = codeAttribID.code;
  instructionList & code = codeID;

  CodeAttribs && codAtIndex = visit(ctx->expr());
  offID = codAtIndex.addr;
  code = code || codAtIndex.code;

  //if this is a pointer to an array (a function paramter) then a load is needed to have the actual adress of that array
  if(Symbols.isParameterClass(addrID)){
    std::string temp = "%" + codeCounters.newTEMP();
    code = code || instruction::LOAD(temp,addrID);
    addrID = temp;
  }
  
  CodeAttribs codAts(addrID, offID, code);
  DEBUG_EXIT();
  return codAts;

}

antlrcpp::Any CodeGenVisitor::visitParen(AslParser::ParenContext *ctx){
  DEBUG_ENTER();
  CodeAttribs && codeAt = visit(ctx->expr());
  DEBUG_EXIT();
  return codeAt;
}

antlrcpp::Any CodeGenVisitor::visitUnary(AslParser::UnaryContext *ctx){
  DEBUG_ENTER();

  CodeAttribs && codeAt = visit(ctx->expr());

  if (ctx->PLUS()){
    DEBUG_EXIT();
    return codeAt;
  }

  instructionList & codeExpr = codeAt.code;
  std::string addrExpr = codeAt.addr;

  instructionList & code = codeExpr;

  std::string temp = "%"+codeCounters.newTEMP();
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    
  if (ctx->NOT())
    code = code || instruction::NOT(temp, addrExpr);
  else if (ctx->SUB() && Types.isIntegerTy(t1))
    code = code || instruction::NEG(temp, addrExpr);
  else if (ctx->SUB())
    code = code || instruction::FNEG(temp, addrExpr);

  CodeAttribs codAts(temp, "", code);

  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  //std::cout << "Visiting arithmetic of " << ctx->getText() << std::endl;
  //std::cout << "Visiting expr0 of " << ctx->getText() << std::endl;
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  //std::cout << "Exiting expr0 of " << ctx->getText() << std::endl;
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  //std::cout << "Visiting expr1 of " << ctx->getText() << std::endl;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  //std::cout << "Exiting expr1 of " << ctx->getText() << std::endl;
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  TypesMgr::TypeId  t = getTypeDecor(ctx);

  bool isFloat = Types.isFloatTy(t);

  if (isFloat){
    if (not Types.isFloatTy(t1)){
      std::string tempA = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tempA, addr1);
      addr1 = tempA;
    }
    if (not Types.isFloatTy(t2)){
      std::string tempB = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tempB, addr2);
      addr2 = tempB;
    }
  }

  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->MUL()){

      if(not isFloat) code = code || instruction::MUL(temp, addr1, addr2);
      else code = code || instruction::FMUL(temp, addr1, addr2);

  }
  else if (ctx->PLUS()){

    if(not isFloat) code = code || instruction::ADD(temp, addr1, addr2);
    else code = code || instruction::FADD(temp, addr1, addr2);

  }
  else if (ctx->SUB()){

    if(not isFloat) code = code || instruction::SUB(temp, addr1, addr2);
    else code = code || instruction::FSUB(temp, addr1, addr2);

  }    
  else if (ctx->DIV()){

    if(not isFloat) code = code || instruction::DIV(temp, addr1, addr2);
    else code = code || instruction::FDIV(temp, addr1, addr2);

  }
  else if (ctx->MOD()){}

    // CODE FOR MODULAR OPERATION (JP 11)
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  //std::cout << "Exiting arithmetic of " << ctx->getText() << std::endl;
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitLogic(AslParser::LogicContext *ctx){
  DEBUG_ENTER();

  CodeAttribs && codAt1 = visit(ctx->expr(0));
  CodeAttribs && codAt2 = visit(ctx->expr(1));
  instructionList &   code1 = codAt1.code;
  instructionList &   code2 = codAt2.code;
  std::string         addr1 = codAt1.addr;
  std::string         addr2 = codAt2.addr;

  instructionList &&   code = code1 || code2;


  std::string temp = "%"+codeCounters.newTEMP();

  if (ctx->AND())
    code = code || instruction::AND(temp, addr1, addr2);
  else if (ctx->OR())
    code = code || instruction::OR(temp, addr1, addr2);

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;


}

antlrcpp::Any CodeGenVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  // FA FALTA COERCIÓ INT -> FLOAT COM EN EL visitArithmetic
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;

  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;


  instructionList &&   code = code1 || code2;


  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  //TypesMgr::TypeId  t = getTypeDecor(ctx);

  std::string temp1= "%"+codeCounters.newTEMP();
  std::string temp2= "%"+codeCounters.newTEMP();

  if(not Types.isFloatTy(t1) and not Types.isFloatTy(t2)){

      if (ctx->EQ())
        code = code || instruction::EQ(temp1, addr1, addr2);
      else if (ctx->NEQ())
        code = code || instruction::EQ(temp2, addr1, addr2) || instruction::NOT(temp1, temp2);
      else if (ctx->GE())
        code = code || instruction::LT(temp2, addr1, addr2) || instruction::NOT(temp1, temp2);
      else if (ctx->GT())
        code = code || instruction::LE(temp2, addr1, addr2) || instruction::NOT(temp1, temp2);
      else if (ctx->LE())
        code = code || instruction::LE(temp1, addr1, addr2);
      else if (ctx->LT())
        code = code || instruction::LT(temp1, addr1, addr2);
  }
  else{

    std::string addrF1 = addr1;
    std::string addrF2 = addr2;

    if(Types.isFloatTy(t1)){
      addrF1 = "%" + codeCounters.newTEMP();
      code = code || instruction::FLOAT(addrF1, addr1);
    }
    
    if(Types.isFloatTy(t2)){
      addrF2 = "%" + codeCounters.newTEMP();
      code = code || instruction::FLOAT(addrF2, addr2);
    }

      if (ctx->EQ())
        code = code || instruction::FEQ(temp1, addr1, addr2);
      else if (ctx->NEQ())
        code = code || instruction::FEQ(temp2, addr1, addr2) || instruction::NOT(temp1, temp2);
      else if (ctx->GE())
        code = code || instruction::FLT(temp2, addr1, addr2) || instruction::NOT(temp1, temp2);
      else if (ctx->GT())
        code = code || instruction::FLE(temp2, addr1, addr2) || instruction::NOT(temp1, temp2);
      else if (ctx->LE())
        code = code || instruction::FLE(temp1, addr1, addr2);
      else if (ctx->LT())
        code = code || instruction::FLT(temp1, addr1, addr2);


  }
    
  CodeAttribs codAts(temp1, "", code);
  DEBUG_EXIT();
  return codAts;
}


antlrcpp::Any CodeGenVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  
  if (ctx->INTVAL())
    code = instruction::ILOAD(temp, ctx->getText());
  else if (ctx->FLOATVAL())
    code = instruction::FLOAD(temp, ctx->getText());
  else if (ctx->CHARVAL())
    code = instruction::CHLOAD(temp, ctx->getText());
  else if (ctx->BOOLVAL())
  {
    std::string val = ctx->getText();
    int isTrue = val.compare("true");
    isTrue == 0 ? code = instruction::ILOAD(temp, "1") : code = instruction::ILOAD(temp, "0");
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs codAts(ctx->ID()->getText(), "", instructionList());
  DEBUG_EXIT();
  return codAts;
}


// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId CodeGenVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getType(ctx);
}


// Constructors of the class CodeAttribs:
//
CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList & code) :
  addr{addr}, offs{offs}, code{code} {
}

CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList && code) :
  addr{addr}, offs{offs}, code{code} {
}
