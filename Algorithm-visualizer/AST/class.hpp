
#include "expression.hpp"
#include "statement.hpp"
#include "ast.hpp"
#ifndef CLASS_HPP
#define CLASS_HPP

class Return : public Statement {
    Return();
    ~Return();
    void set_exp(Expression* e){exp = e;};
    Expression* get_exp(){return exp;};
    std::string get_subtype(){return "Return";};
private:
    Expression* exp;
};

#endif // CLASS_HPP
