#include "expression.hpp"
#include "statement.hpp"
#include "variable.hpp"
#include "ast.hpp"
#ifndef UNOP_HPP
#define UNOP_HPP

//enum un_op {
//    unknown_un_op = 0,
//    negation = 1,
//    plusplus = 2
//    //inverse = 3 (if we add this as a unary operation for number -> -number)
//};


class Negation : public Expression {
public : Negation();
public : ~Negation();
public : double get_value(){return !(expression->get_value());};
private :
    Expression* expression;
};


class PlusPlus : public Statement {
public : PlusPlus();
public : ~PlusPlus();
public : double get_value(){
        if (var->get_exp_type() == "bool") return 0;
        return var->get_value() + 1;
    };
private :
    Variable* var;
};







class UnOp : public Expression {
    UnOp();
    ~UnOp();
    void set_operation(un_op op){operation = op;};
    void set_expression(Expression* e){expression = e;};
    un_op get_operation(){return operation;};
    Expression* get_expression(){return expression;};
    std::string get_subtype(){return "UnOp";};
private:
    un_op operation = unknown_un_op;
    Expression* expression;
};
#endif // UNOP_HPP
