#include "expression.hpp"
#include "statement.hpp"
#include "ast.hpp"
#ifndef DECISION_HPP
#define DECISION_HPP

class Decision : public Statement {
    Decision();
    ~Decision();
    void set_condition(Expression* c){condition = c;};
    std::string get_subtype(){return "Decision";};
    bool is_true();
private:
    Expression* condition;
};
#endif // DECISION_HPP
