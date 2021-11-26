#include "expression.hpp"
#include "ast.hpp"
#include "cache.hpp"
#ifndef UNOP_HPP
#define UNOP_HPP

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

class UnOp : public Expression {
    UnOp();
    ~UnOp();
    UnOp(Cache* c){cache = c;};
    void set_operation(un_op op){operation = op;};
    void set_expression(Expression* e){expression = e;};
    un_op get_operation(){return operation;};
    Expression* get_expression(){return expression;};
    std::string get_subtype(){return "UnOp";};
private:
    un_op operation = unknown_un_op;
    Expression* expression;
    Cache* cache;
};
#endif // UNOP_HPP
