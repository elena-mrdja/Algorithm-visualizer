#include "expression.hpp"
#include "ast.hpp"
#ifndef VARIABLE_HPP
#define VARIABLE_HPP

/* enum var_type {
    unknown_var_type = 0,
    string = 1,
    integer = 2,
    character = 3,
    floating_point = 4

}; */

class Variable : public Expression {
    Variable();
    ~Variable();
    void set_name(char n){name = n;};
    void set_type(var_type t){type = t;};
    std::string get_name(){return name;};
    std::string get_var_type(){
        switch(type) {
        case 0: return "unknown variable type";
        case 1: return "string";
        case 2: return "integer";
        case 3: return "char";
        case 4: return "floating_point";
        }
    }
    std::string get_subtype(){return "Variable";};

private:
    std::string name;
    var_type type = unknown_var_type;
};

#endif // VARIABLE_HPP



Variable x_var;
x_var.set_name('x')
x_var.set_type(integer)
