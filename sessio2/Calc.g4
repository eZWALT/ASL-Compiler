grammar Calc;

prog:  stat+ EOF ;

stat:  expr NEWLINE           # printExpr
    |  ID '=' expr NEWLINE    # assign
    |  IF expr NEWLINE THEN stat ENDIF #if
    |  IF expr NEWLINE THEN stat ELSE stat ENDIF # ifelse
    |  WHILE expr NEWLINE stat      #while 
    |  NEWLINE                # blank
    ;

expr : 
  expr FACTORIAL             #factorial
  |LPAR expr RPAR            #parentesis
  | (ADD | SUB) expr          #sign
  | expr (MUL | DIV | MOD) expr  #mult
  | expr (ADD | SUB) expr       #arithmetic
  | ABS LPAR expr RPAR        #abs 
  | MIN LPAR expr COMMA expr RPAR #minmax
  | MAX LPAR expr COMMA expr RPAR #minmax
  | MYSTERY LPAR expr (COMMA expr)* RPAR #mistery
  | expr (LESS | LE | GE | GRT) expr #comparision
  | expr (EQ | NEQ) expr        #equality
  | INT                    #num 
  | ID                     #id 
  ; 

IF : 'if' ;
THEN: 'then';
ELSE: 'else';
ENDIF: 'endif';
WHILE: 'while';
EQ: '==';
NEQ:'!=';
LE :  '<=';
GE :  '>=';
LESS: '<';
GRT : '>';

LPAR:  '(' ;
RPAR:  ')' ;
MUL :  '*' ;
ADD :  '+' ;
SUB :  '-' ;
MOD :  '%' ;
DIV :  '/' ;
ABS :  'abs' ;
MIN :  'min' ;
MAX :  'max' ;
COMMA : ',' ;
FACTORIAL: '!' ;
MYSTERY: 'mistery';
ID  :  [a-zA-Z]+ ;       // match identifiers
INT :  [0-9]+ ;          // match integers

NEWLINE: '\r'? '\n' ;    // return newlines to parser (is end-statement signal)
WS  :  [ \t]+ -> skip ;  // toss out whitespace
