#ifndef EXPRESSION_TEMPLATE_H
#define EXPRESSION_TEMPLATE_H
#include "ast.hpp"

template <typename T> class Expression : public AST{
protected : Expression();
    ~Expression();
std::string get_type(){return "Expression";};
T get_value() = 0;
};

#endif // EXPRESSION_TEMPLATE_H
