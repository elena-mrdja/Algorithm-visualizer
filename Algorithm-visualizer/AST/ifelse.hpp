#include "assignment.hpp"
#include "decision.hpp"
#include "ifrest.hpp"
#include "ast.hpp"
#ifndef IFELSE_HPP
#define IFELSE_HPP

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


class IfElse : public Decision {
    IfElse();
    ~IfElse();
    //attributes: condition(expression), IfRest
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    void set_else_stmt(IfRest* stmt){else_stmt = stmt;};
    IfRest* get_else_stmt(){return else_stmt;};
    std::string get_subtype(){return "IfElse";};
private:
    Expression* condition;
    IfRest* else_stmt;
};

#endif // IFELSE_HPP
