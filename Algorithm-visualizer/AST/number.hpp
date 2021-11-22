#ifndef NUMBER_HPP
#define NUMBER_HPP
#include "expression.hpp"
#include "ast.hpp"

//enum var_type {
//    unknown_var_type = 0,
//    string = 1,
//    integer = 2,
//    character = 3,
//    floating_point = 4

//};

class Number : Expression {
    Number();
    ~Number();
private:
    var_type type;
    std::string value;
};

#endif // NUMBER_HPP
