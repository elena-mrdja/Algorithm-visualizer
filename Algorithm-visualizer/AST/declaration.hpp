#include "ast.hpp"
#include "statement.hpp"
#include "cache.hpp"
#ifndef DECLARATION_HPP
#define DECLARATION_HPP


//enum var_type {
//    unknown_var_type = 0,
//    string = 1,
//    integer = 2,
//    character = 3,
//    floating_point = 4

//};

//enum un_op {
//    unknown_un_op = 0,
//    negation = 1,
//    plusplus = 2
//    //inverse = 2 (if we add this as a unary operation for number -> -number)
//};

//enum bin_op {
//    unknown_bin_op = 0,
//    conjunction = 1,
//    disjunction = 2,
//    addition = 3,
//    subtraction = 4,
//    multiplication = 5,
//    division = 6,
//    lthan = 7,
//    mthan = 8,
//    leq = 9,
//    meq = 10,
//    eq = 11,
//    eqeq = 12
//};

//enum jump_type {
//    unknown_jump_type = 0,
//    br = 1,
//    cont = 2
//};
//enum expression_type {
//    unknown_expression_type = 0
//};


class Declaration : public Statement {
public:
    Declaration();
    Declaration(Cache* c){cache = c;};
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
    Cache* cache;
    //int x = 7, bool y = False
    //attributes:
    //name + value of the variable or Variable + sth
};

#endif // DECLARATION_HPP
