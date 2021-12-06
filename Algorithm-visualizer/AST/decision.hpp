#include "expression.hpp"
#include "statement.hpp"
#ifndef DECISION_H
#define DECISION_H


class Decision {
public : Decision();
public : ~Decision();
public : void set_condition(Expression* c){condition = c;};
public : string get_subtype(){return "Decision";};
public : double get_value(){
        if (condition->get_value()) return 1;
        return 0;
    };
private:
    Expression* condition;
};

#endif // DECISION_H
