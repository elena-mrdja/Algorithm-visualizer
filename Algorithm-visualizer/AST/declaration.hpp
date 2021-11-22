#include "ast.hpp"
#include "statement.hpp"
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
    void set_var_type(var_type t){type = t;};
    std::string get_var_type(){
        switch(type) {
        case 0: return "unknown variable type";
        case 1: return "string";
        case 2: return "integer";
        case 3: return "char";
        case 4: return "floating_point";
        }
    }
    char get_value(){return value;};
    void set_value(char v){value = v;};
    std::string get_subtype(){return "Declaration";};


private:
    var_type type = unknown_var_type;
    char value;
    //int x = 7, bool y = False
    //attributes:
    //name + value of the variable or Variable + sth
};

#endif // DECLARATION_HPP
