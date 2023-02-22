grammar Calc;

prog:  stat+ EOF ;

stat:  expr NEWLINE           # printExpr
    |  ID '=' expr NEWLINE    # assign
    |  NEWLINE                # blank
    ;

expr : LPAR expr RPAR            #parentesis
  | (ADD | SUB) expr          #sign
  | expr (MUL | DIV | MOD) expr  #mult
  | expr (ADD | SUB) expr       #arithmetic
  | ABS LPAR expr RPAR        #abs 
  | MIN LPAR expr COMMA expr RPAR #minmax
  | MAX LPAR expr COMMA expr RPAR #minmax
  | MYSTERY LPAR expr (COMMA expr)* RPAR #mistery
  | INT                    #num 
  | ID                     #id 
  ; 

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
MYSTERY: 'mistery';
ID  :  [a-zA-Z]+ ;       // match identifiers
INT :  [0-9]+ ;          // match integers

NEWLINE: '\r'? '\n' ;    // return newlines to parser (is end-statement signal)
WS  :  [ \t]+ -> skip ;  // toss out whitespace
