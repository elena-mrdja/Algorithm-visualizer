#include "ast.hpp"
#include "statement.hpp"
#include "expression.hpp"
#include "cache.hpp"
#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

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


class Assignment : public Statement {
    public:
    Assignment();
    ~Assignment();
    Assignment(Cache* c){cache = c;};
    Expression* get_value(){return value;};
    void set_value(Expression* v){value= v;}
    std::string get_name(){return name;};
    void set_name(std::string n){name= n;}
    //x = 5; x = y
    std::string get_subtype(){return "Assignment";};
    void add_value(char value);
private:
    std::string name;
    Expression* value;
    Cache* cache;
};
#endif // ASSIGNMENT_HPP
