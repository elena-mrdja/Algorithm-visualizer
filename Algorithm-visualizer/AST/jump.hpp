#include "statement.hpp"
#include "ast.hpp"
#ifndef JUMP_HPP
#define JUMP_HPP

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


class Jump : public Statement {
    Jump();
    Jump(char value);
    ~Jump();
    void set_value(jump_type v){value = v;};
    std::string get_value(){
        switch(value) {
        case 0: return "unknown jump type";
        case 1: return "break";
        case 2: return "continue";
        }
  };
    std::string get_subtype(){return "Jump";};
private:
    jump_type value = unknown_jump_type;
};


#endif // JUMP_HPP
