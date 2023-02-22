grammar Expr;

s : e EOF ;

e : LPAR e RPAR            #parentesis
  | (ADD | SUB) e          #sign
  | e (MUL | DIV | MOD) e  #mult
  | e (ADD | SUB) e        #arithmetic
  | ABS LPAR e RPAR        #abs 
  | MIN LPAR e COMMA e RPAR #min 
  | MAX LPAR e COMMA e RPAR #max  
  | INT                    #num 
  ; 
 

MUL : '*' ;
DIV : '/' ; 
ADD : '+' ;
SUB : '-' ; 
MOD : '%' ;
LPAR: '(' ;
RPAR: ')' ;
ABS: 'abs';
MIN: 'min';
MAX: 'max';
COMMA: ',';


INT : [0-9]+ ;
WS  : [ \t\n]+ -> skip ;
