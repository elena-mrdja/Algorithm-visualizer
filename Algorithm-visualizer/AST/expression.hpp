#include "ast.hpp"
#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

//enum expression_type {
//    unknown_expression_type = 0
//};


class Expression : public AST {
protected : Expression();
protected : Expression(expression_type t) {
        type = t;
    };
    ~Expression();
std::string get_type(){return "Expression";};
virtual bool get_bool_value(); //expressions value is either numerical, true or false
virtual char get_num_value();
private:
    expression_type type = unknown_expression_type;
};

#endif // EXPRESSION_HPP
