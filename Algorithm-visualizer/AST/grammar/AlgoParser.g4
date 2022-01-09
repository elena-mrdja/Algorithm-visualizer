parser grammar AlgoParser;

options {
	tokenVocab = AlgoLexer;
}

// These are all supported parser sections:

// Parser file header. Appears at the top in all parser related files. Use e.g. for copyrights.
@parser::header {/* parser/listener/visitor header section */}

// Appears before any #include in h + cpp files.
@parser::preinclude {/* parser precinclude section */}

// Follows directly after the standard #includes in h + cpp files.
@parser::postinclude {
/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// Directly preceeds the parser class declaration in the h file (e.g. for additional types etc.).
@parser::context {/* parser context section */}

// Appears in the private part of the parser in the h file.
// The function bodies could also appear in the definitions section, but I want to maximize
// Java compatibility, so we can also create a Java parser from this grammar.
// Still, some tweaking is necessary after the Java file generation (e.g. bool -> boolean).
@parser::members {
/* public parser declarations/members section */
bool myAction() { return true; }
bool doesItBlend() { return true; }
void cleanUp() {}
void doInit() {}
void doAfter() {}
}

// Appears in the public part of the parser in the h file.
@parser::declarations {/* private parser declarations section */}

// Appears in line with the other class member definitions in the cpp file.
@parser::definitions {/* parser definitions section */}

// Additionally there are similar sections for (base)listener and (base)visitor files.
@parser::listenerpreinclude {/* listener preinclude section */}
@parser::listenerpostinclude {/* listener postinclude section */}
@parser::listenerdeclarations {/* listener public declarations/members section */}
@parser::listenermembers {/* listener private declarations/members section */}
@parser::listenerdefinitions {/* listener definitions section */}

@parser::baselistenerpreinclude {/* base listener preinclude section */}
@parser::baselistenerpostinclude {/* base listener postinclude section */}
@parser::baselistenerdeclarations {/* base listener public declarations/members section */}
@parser::baselistenermembers {/* base listener private declarations/members section */}
@parser::baselistenerdefinitions {/* base listener definitions section */}

@parser::visitorpreinclude {/* visitor preinclude section */}
@parser::visitorpostinclude {/* visitor postinclude section */}
@parser::visitordeclarations {/* visitor public declarations/members section */}
@parser::visitormembers {/* visitor private declarations/members section */}
@parser::visitordefinitions {/* visitor definitions section */}

@parser::basevisitorpreinclude {/* base visitor preinclude section */}
@parser::basevisitorpostinclude {/* base visitor postinclude section */}
@parser::basevisitordeclarations {/* base visitor public declarations/members section */}
@parser::basevisitormembers {/* base visitor private declarations/members section */}
@parser::basevisitordefinitions {/* base visitor definitions section */}
/*
 * Parser Rules
 */
//Stuff to talk:
//in order to create tree we need file which is a collection of statemetns as I understand
//how to we make grammar for double and char
//str type does not exist in C++
//what is unop
// should we add mod to binOp?
// i don't think bool should be in type?!
//any ideas about arrays?



//our grammar
file : (library)* mainStmt (stmts)*;

//statement: stmts | mainStmt;

mainStmt: type MAIN LP RP body = block;

assign: varName=variable (LSB index=exp RSB)? EQ val=exp SEMICOLON;

exp: integerType| doubleType| boolType| string | LP exp RP| exp binOp exp | unop exp| exp unop| negation | identifier | arrayType | variable;

varDec: type varName=variable (LSB arrSize=exp RSB)? (EQ val=exp)? SEMICOLON; 

whileStmt: WHILE LP cond=exp RP body=block;

returnStmt: RETURN val = exp SEMICOLON;

negation: MINUS exp;

//good below
block: LCB stmts* RCB;
stmts: whileStmt | ifelse | returnStmt | print |library | varDec | assign |exp SEMICOLON | jump;

ifelse: IF LP cond = exp RP thn=block ifrest;

ifrest: ELSE ifelse| ELSE thn=block;

boolType: TRUE| FALSE;

doubleType: FLOAT;

integerType: INTEGER;

arrayType : LCB ( exp ( COMMA exp )+ )? RCB;


string: QUOTE STRING QUOTE;

type: INT| STR| CHAR| DOUBLE |BOOLEAN;

binOp:  PLUS
		| MINUS
		| TIMES
		| DIV
		| MOD
		| XOR
        | XAND
		| EQQ
		| NOTEQQ
        | LT
		| MT
        | LEQ
        | MEQ
		;

unop:   PLUSPLUS
		| MINUSMINUS
        ;

identifier: ID;

variable: STRING;

print: STDC LL exp LL STDE SEMICOLON;

jump: CONT | BREAK; 

library: INCLUDE QUOTE variable QUOTE;




 
