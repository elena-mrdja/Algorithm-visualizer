#include "ast.hpp"
#include "statement.hpp"
#include "variable.hpp"
#include "block.hpp"
#ifndef DECLARATION_HPP
#define DECLARATION_HPP

class Declaration : public Statement {
public:
    Declaration();
    ~Declaration();
    void set_variable(Variable var){variable = var;};
    char get_value(){return value;};
    void set_value(char v){value = v;};
    Variable get_variable(){return variable;};
    std::string get_subtype(){return "Declaration";};
  //void add_variable_to_list(){Block variables; variables.insert({variable, value});};
private:
    Variable variable;
    char value;
};

#endif // DECLARATION_HPP
