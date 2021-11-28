#include "statement.hpp"
#include "expression.hpp"
#include "ast.hpp"
#ifndef PRINT_HPP
#define PRINT_HPP

class Print : public Statement {
    Print();
    ~Print();
    void set_exp(Expression* e){exp = e;};
    Expression* get_exp(){return exp;};
    std::string get_subtype(){return "Print";};
private:
    Expression* exp;
};

#endif // PRINT_HPP
