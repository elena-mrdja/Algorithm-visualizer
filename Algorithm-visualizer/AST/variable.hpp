#include "expression.hpp"
#include "ast.hpp"
#include "expression.hpp"
#ifndef VARIABLE_HPP
#define VARIABLE_HPP

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
    double get_num_value(){
        assert (type ==2 or type == 4);
        return std::stod(current_value);
    };
    bool get_bool_value(){

    };

private:
    std::string name;
    var_type type = unknown_var_type;
    std::string current_value;
};

#endif // VARIABLE_HPP
