lexer grammar AlgoLexer;

// These are all supported lexer sections:

// Lexer file header. Appears at the top of h + cpp files. Use e.g. for copyrights.
@lexer::header {/* lexer header section */}

// Appears before any #include in h + cpp files.
@lexer::preinclude {/* lexer precinclude section */}

// Follows directly after the standard #includes in h + cpp files.
@lexer::postinclude {
/* lexer postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// Directly preceds the lexer class declaration in the h file (e.g. for additional types etc.).
@lexer::context {/* lexer context section */}

// Appears in the public part of the lexer in the h file.
@lexer::members {/* public lexer declarations section */
bool canTestFoo() { return true;}
bool isItFoo() { return true; }
bool isItBar() { return true; }

void myFooLexerAction() { /* do something*/ };
void myBarLexerAction() { /* do something*/ };
}

// Appears in the private part of the lexer in the h file.
@lexer::declarations {/* private lexer declarations/members section */}

// Appears in line with the other class member definitions in the cpp file.
@lexer::definitions {/* lexer definitions section */}

//channels { CommentsChannel, DirectiveChannel }

tokens {
	DUMMY
}
//^^for ANTLR^^

// Lexer rules
WS : [ \r\t\n]+ -> channel(HIDDEN); //white space
INTEGER: Digit+;
Digit: [0-9];
//STR       : [a-z]+; //we should put a wider definition
VAR		  : 'var ' ;
MAIN      : 'main';
PLUS      : '+';
MINUS     : '-';
TIMES     : '*';
DIV       : '/';
MOD		  : '%';
EQ        : '=';
LT        : '<';
MT        : '>';
LEQ       : '<=';
MEQ       : '>=';
TRUE      : 'true';
FALSE     : 'false';
LP        : '(';
RP        : ')';
LCB       : '{';
RCB       : '}';
LSB       : '[';
RSB       : ']';
SEMICOLON : ';';
XOR       : '|';
XAND      : '&';   
EQQ       : '==';
WHILE     : 'while';
IF        : 'if';
ELSE      : 'else';
CONT      : 'continue';
BREAK     : 'break';
PLUSPLUS  : '++';
MINUSMINUS : '--';
QUOTE	  : '"';
RETURN    : 'return';
DOT		  : '.';	

INT: 'int';
CHAR: 'char';
STR: 'str';
DOUBLE: 'double';

// SHould be defined last, so that reserved words stay reserved
// used for str afterwards
ID: LETTER (LETTER | '0'..'9')*;
fragment LETTER : [a-zA-Z\u0080-\uFFFF];

