#include "ast.hpp"
#include "statement.hpp"
#include "cache.hpp"
#ifndef BLOCK_HPP
#define BLOCK_HPP

//enum var_type {
//    unknown_var_type = 0,
//    string = 1,
//    integer = 2,
//    character = 3,
//    floating_point = 4

//};

//enum un_op {
//    unknown_un_op = 0,
//    negation = 1,
//    plusplus = 2
//    //inverse = 2 (if we add this as a unary operation for number -> -number)
//};

//enum bin_op {
//    unknown_bin_op = 0,
//    conjunction = 1,
//    disjunction = 2,
//    addition = 3,
//    subtraction = 4,
//    multiplication = 5,
//    division = 6,
//    lthan = 7,
//    mthan = 8,
//    leq = 9,
//    meq = 10,
//    eq = 11,
//    eqeq = 12
//};

//enum jump_type {
//    unknown_jump_type = 0,
//    br = 1,
//    cont = 2
//};
//enum expression_type {
//    unknown_expression_type = 0
//};


class Block : public Statement {
protected : Block();
protected : Block(Cache* c){cache = c;}
protected : ~Block();
void extend_statement();
void add_new_statement();
std::string get_subtype(){return "Block";};
void walk();
    //list of statements
private:
    Cache* cache;
    Statement* statements[50]; //Array that will store statements, will drafted methods to expand, add methods, cache code can be repurposed
    int statement_number; // Current number of statements
};

#endif // BLOCK_HPP
