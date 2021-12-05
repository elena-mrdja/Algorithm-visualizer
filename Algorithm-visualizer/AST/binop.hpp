#include "expression.hpp"
#include "ast.hpp"
#ifndef BINOP_HPP
#define BINOP_HPP

class Addition : public Expression {
public : Addition();
public : ~Addition();
public : double get_value(){
        if (left_exp->get_exp_type() == "bool" or right_exp->get_exp_type() == "bool") {return 0;};
        return left_exp->get_value() + right_exp->get_value();
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class Subtraction : public Expression {
public : Subtraction();
public : ~Subtraction();
public : double get_value(){
        if (left_exp->get_exp_type() == "bool" or right_exp->get_exp_type() == "bool") {return 0;};
        return left_exp->get_value() - right_exp->get_value();
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class Multiplication : public Expression {
public : Multiplication();
public : ~Multiplication();
public : double get_value(){
        if (left_exp->get_exp_type() == "bool" or right_exp->get_exp_type() == "bool") {return 0;};
        return left_exp->get_value() * right_exp->get_value();
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class Division : public Expression {
public : Division();
public : ~Division();
public : double get_value(){
        if (left_exp->get_exp_type() == "bool" or right_exp->get_exp_type() == "bool"  or right_exp->get_value() == 0) return 0;
        return left_exp->get_value() / right_exp->get_value();
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class Mthan : public Expression {
public : Mthan();
public : ~Mthan();
public : double get_value(){
        if (left_exp->get_exp_type() == "bool" or right_exp->get_exp_type() == "bool") return 0;
        if (left_exp->get_value() > right_exp->get_value()) return 1;
        return 0;
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class Lthan : public Expression {
public : Lthan();
public : ~Lthan();
public : double get_value(){
        if (left_exp->get_exp_type() == "bool" or right_exp->get_exp_type() == "bool") return 0;
        if (left_exp->get_value() < right_exp->get_value()) return 1;
        return 0;
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class Leq : public Expression {
public : Leq();
public : ~Leq();
public : double get_value(){
        if (left_exp->get_exp_type() == "bool" or right_exp->get_exp_type() == "bool") return 0;
        if (left_exp->get_value() <= right_exp->get_value()) return 1;
        return 0;
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class Meq : public Expression {
public : Meq();
public : ~Meq();
public : double get_value(){
        if (left_exp->get_exp_type() == "bool" or right_exp->get_exp_type() == "bool") return 0;
        if (left_exp->get_value() >= right_exp->get_value()) return 1;
        return 0;
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class Eqeq : public Expression {
public : Eqeq();
public : ~Eqeq();
public : double get_value(){
        if (left_exp->get_value() == right_exp->get_value()) return 1;
        return 0;
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class AndOp : public Expression {
public : AndOp();
public : ~AndOp();
public : double get_value(){
        if (left_exp->get_value() && right_exp->get_value()) return 1;
        return 0;
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};

class OrOp : public Expression {
public : OrOp();
public : ~OrOp();
public : double get_value(){
        if (left_exp->get_value() || right_exp->get_value()) return 1;
        return 0;
    };
private :
    Expression* left_exp;
    Expression* right_exp;
};


#endif // BINOP_HPP
