#include "expression.hpp"
#include "ast.hpp"
#ifndef VARIABLE_HPP
#define VARIABLE_HPP


class Variable : public Expression {
    Variable();
    ~Variable();
    void set_name(char n){name = n;};
    void set_type(var_type t){type = t;};
    std::string get_name(){return name;};
    var_type get_var_type(){return type;};
    std::string get_subtype(){return "Variable";};

private:
    std::string name;
    var_type type = unknown_var_type;
};

#endif // VARIABLE_HPP
