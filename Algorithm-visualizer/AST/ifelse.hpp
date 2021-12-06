#include "assignment.hpp"
#include "decision.hpp"
#include "ifrest.hpp"
#include "ast.hpp"
#ifndef IFELSE_HPP
#define IFELSE_HPP

class IfElse : public Decision {
    IfElse();
    ~IfElse();
    //attributes: condition(expression), IfRest
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    void set_else_stmt(IfRest* stmt){else_stmt = stmt;};
    IfRest* get_else_stmt(){return else_stmt;};
    std::string get_subtype(){return "IfElse";};
private:
    Expression* condition;
    IfRest* else_stmt;
};

#endif // IFELSE_HPP
