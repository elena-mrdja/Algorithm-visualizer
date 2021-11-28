#ifndef BINOP_TEMPLATE_HPP
#define BINOP_TEMPLATE_HPP

#include "expression_template.hpp"

template<typename T> void set_expression(Expression<T>* expression, Expression<T>* e){
    e = expression;
};

class BoolBinOp : public Expression<bool> {
    BoolBinOp();
    ~BoolBinOp();
    void set_operation(bin_op op){operation = op;};
    void set_left_expression(Expression* l_e){left_exp = l_e;};
    void set_right_expression(Expression* r_e){right_exp = r_e;};
private:
    bin_op operation = unknown_bin_op;
    Expression* left_exp;
    Expression* right_exp;
};

/*
class NumBinOp : public Expression<int>, public Expression<double>, public Expression<float> {
    NumBinOp();
    ~NumBinOp();
    void set_operation(bin_op op){operation = op;};
    void set_left_expression(Expression* l_e){left_exp = l_e;};
    void set_right_expression(Expression* r_e){right_exp = r_e;};
private:
    bin_op operation = unknown_bin_op;
    Expression* left_exp;
    Expression* right_exp;
};
*/

#endif // BINOP_TEMPLATE_HPP
