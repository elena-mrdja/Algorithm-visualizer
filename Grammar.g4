grammar Grammar;

// Parser rule
expr    : '-' expr | expr ( '*' | '/' ) expr | 
          expr ( '+' | '-' ) expr | '(' expr ')' | INT | STR;
program : INT MAIN LP RP block;
block   : LCB stmts RCB;
varDec  :
stmts   : varDec stmts | block stmts | assign stmts | 'print' stmts | while stmts | jump stmts | ifelse stmts | return stmts;
return  : RETURN expr SEMICOLON;
type    : 'int' | 'bool' | 'str' | 'double' | VAR;
assign  : VAR STR EQ expr SEMICOLON | expr PLUSPLUS | expr MINUSMINUS ;
while   : WHILE LP expr RP;
ifelse  : IF LP expr op expr RP block; 
ifrest  : ELSE block | ELSE ifelse;
exp     : VAR | TRUE | FALSE | LP exp RP | exp binop exp | expr;
jump    : CONT | BREAK;
op      : EQQ | LT | MT | LEQ | MEQ;
binop   : XOR | XAND;

// define name of variable
// difference var and varDec

<program> = ‘’’ INT MAIN LP RP <block> ‘’’
<block> = ’’’LCB <stmts> RCB ‘’’
<stmts> = ‘’’ <varDec> <stmts> |<block>  <stmts> |<assign> <stmts> |<print> <stmts> |<while> <stmts> |<jump><stmts>  |<ifelse> <stmts> |<return> <stmts> | ‘’’
<varDec> = ‘’’<type> VAR ASSIGN <exp> SEMICOMMA’’’
<type> = ‘’’ | INT | BOOL | STR | DOUBLE ’’’
<assign> = ‘’’VAR EQ <exp> SEMICOLON’’’
<while> = ‘’’WHILE LP <exp> RP <block>’’’
<ifelse> = ‘’’IF LP <exp> RP <block> <ifrest>’’’
<ifrest> = ’’’|ELSE <block> |ELSE <ifelse> | ‘’’ 
<jump> = ‘’’ | CONT| BREAK ’’’
<return> = ‘’’RETURN <exp> SEMICOLON’’’
<exp> = ‘’’|VAR|TRUE|FALSE|LP <exp> RP|<exp> binop <exp>|<unop> <exp>| <exp> <unop>‘’’


// Lexer rules
INT       : [0-9]+;
STR       : [a-z]+; //we should put a wider definition
VAR       : "var";
MAIN      : "main";
PLUS      : "+";
MINUS     : "-";
TIMES     : "*";
DIV       : "/";
EQ        : "=";
LT        : "<";
MT        : ">";
LEQ       : "<=";
MEQ       : ">=";
TRUE      : "true";
FALSE     : "false";
LP        : "(";
RP        : ")";
LCB       : "{";
RCB       : "}";
LSB       : "[";
RSB       : "]";
SEMICOLON : ";";
XOR       : "|";
XAND      : "&";   
EQQ       : "==";
WHILE     : "while";
IF        : "if";
ELSE      : "else";
CONT      : "continue";
BREAK     : "break";
PLUSPLUS  : "++";
MINUSMINUS : "--";
RETURN    : "return";
BOOL      : "[true|false]";



