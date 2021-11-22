
#include "expression.hpp"
#include "ast.hpp"
#ifndef BINOP_HPP
#define BINOP_HPP

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

class BinOp : public Expression {
    BinOp();
    ~BinOp();
    void set_operation(bin_op op){operation = op;};
    void set_left_expression(Expression* l_e){left_exp = l_e;};
    void set_right_expression(Expression* r_e){right_exp = r_e;};
    std::string get_operation(){
        switch(operation) {
        case 0: return "unknown binary operation";
        case 1: return "conjunction";
        case 2: return "disjunction";
        case 3: return "addition";
        case 4: return "substraction";
        case 5: return "multiplication";
        case 6: return "division";
        case 7: return "lthan";
        case 8: return "mthan";
        case 9: return "leq";
        case 10: return "meq";
        case 11: return "eq";
        case 12: return "eqeq";
        }
    }
    Expression* get_left_expression(){return left_exp;};
    Expression* get_right_expression(){return right_exp;};
    std::string get_subtype(){return "BinOp";};
private:
    bin_op operation = unknown_bin_op;
    Expression* left_exp;
    Expression* right_exp;
};

#endif // BINOP_HPP
