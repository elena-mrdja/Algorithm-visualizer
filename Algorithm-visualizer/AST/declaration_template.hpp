#include "ast.hpp"
#include "statement.hpp"
#include "variable.hpp"
#ifndef DECLARATION_HPP
#define DECLARATION_HPP


//enum var_type {
//    unknown_var_type = 0,
//    string = 1,
//    integer = 2,
//    character = 3,
//    floating_point = 4

//};

class Declaration : public Statement {
public:
    Declaration();
    ~Declaration();
    void set_variable(Variable var){variable = var;};
    char get_value(){return value;};
    void set_value(char v){value = v;};
    Variable get_variable(){return variable;};
    std::string get_subtype(){return "Declaration";};
private:
    Variable variable;
    char value;
};

#endif // DECLARATION_HPP
