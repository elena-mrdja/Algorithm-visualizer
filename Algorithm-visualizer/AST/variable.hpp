#ifndef VARIABLE_HPP
#define VARIABLE_HPP
#include "expression.hpp"

class Variable : public Expression {
public : Variable();
public : ~Variable();
public : void set_name(std::string n){name = n;};
public : void set_value(bool val){
        if (val) value = 1;
        else value = 0;
        type = "bool";
    };
public : void set_value(double val){
        value = val;
        type = "double";
    };
public : std::string get_name(){return name;};
public : double get_value(){return value;};
public : std::string get_exp_type(){return type;};
public : string get_type(){return "Variable";};
private:
    std::string name;
    double value = 0;
    std::string type;
};

#endif // VARIABLE_HPP
