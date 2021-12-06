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
    std::string get_subtype(){return "Number";};
    double get_value(){return std::stod(value);}; //returns the double of the value
    //we keep all the values as doubles for simplicity because we don't want
    //some random internal clash of types to happen
private:
    var_type type;
    std::string value;
};

#endif // NUMBER_HPP
