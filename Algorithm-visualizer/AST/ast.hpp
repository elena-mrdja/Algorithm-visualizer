#ifndef AST_H
#define AST_H

#include <string>
#include <iostream>
#include <QAbstractItemModel>

using namespace std;

enum var_type {
    unknown_var_type = 0,
    string = 1,
    integer = 2,
    character = 3,
    floating_point = 4

};

enum un_op {
    unknown_un_op = 0,
    negation = 1,
    plusplus = 2
    //inverse = 2 (if we add this as a unary operation for number -> -number)
};

enum bin_op {
    unknown_bin_op = 0,
    conjunction = 1,
    disjunction = 2,
    addition = 3,
    subtraction = 4,
    multiplication = 5,
    division = 6,
    lthan = 7,
    mthan = 8,
    leq = 9,
    meq = 10,
    eq = 11,
    eqeq = 12
};

enum jump_type {
    unknown_jump_type = 0,
    br = 1,
    cont = 2

};
enum expression_type {
    unknown_expression_type = 0

};

//AST CLASS

class AST {
protected : AST();
protected : ~AST();
virtual std::string get_type() = 0; // Statement or Expression   (this is an abstract method which will be defined in subclasses Statement
//and Expression and inherited by every other subclass below)
virtual std::string get_subtype() = 0; // Block, Declaration, UnOp, BinOp, ...
//(this is an abstract method which will be defined in subclasses Block, Declaration, ...)
// Cache to track changes to variables
std::map<char, char> variables;
private:

};

#endif
