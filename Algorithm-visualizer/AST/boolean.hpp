
#include "expression.hpp"
#include "ast.hpp"
#ifndef BOOLEAN_HPP
#define BOOLEAN_HPP

class Boolean : public Expression {
    //not sure if this is necessary but putting
    //it down for now
    Boolean();
    ~Boolean();
    void set_value(bool v){value = v;};
    bool is_true(){return value;};
    std::string get_subtype(){return "Bool";};
private:
    bool value;
};
#endif // BOOLEAN_HPP
