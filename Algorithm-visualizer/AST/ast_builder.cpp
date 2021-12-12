#include "ast_builder.hpp"

//the function that finalizes the building of the AST:
list<Statement> ast(list<string>);
//input: output of team 1 that gives us all the elements we need easily accessible
//output: the AST

string create_ast_from_parse(string pre_ast) {
    //UnOp
    if (pre_ast[1] == '!'){
        Negation ast;
        ast.expression* = pre_ast[0];
    }

    //BinOp
    if (pre_ast[1] == '+'){
        Addition ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '-'){
        Subtraction ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '*'){
        Multiplication ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '/'){
        Division ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '<'){
        Mthan ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '>'){
        Lthan ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '<='){
        Meq ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '>='){
        Leq ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '=='){
        Eqeq ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '&&'){
        AndOp ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }
    if (pre_ast[1] == '||'){
        OrOp ast;
        ast.left_exp* = pre_ast[0];
        ast.right_exp* = pre_ast[2];
    }

    //Variable
    if (pre_ast[0] == ('bool' || 'int' || 'double' || 'char' || 'list' || 'string') ){
        Variable ast;
        ast.name = pre_ast[1];
        ast.value = pre_ast[2];
        ast.type = pre_ast[0]
    }

    //Assignment
    if (pre_ast[0] == 'x'){  //what shoul i put as a condition for assignement???
        Assignment ast;
        ast.var_name = pre_ast[0];
    }
};
