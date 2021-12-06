#include "statement.hpp"
#include "ast.hpp"
#ifndef JUMP_HPP
#define JUMP_HPP

//enum jump_type {
//    unknown_jump_type = 0,
//    br = 1,
//    cont = 2
//};
//enum expression_type {
//    unknown_expression_type = 0
//};


class Jump : public Statement {
    Jump();
    Jump(char value);
    ~Jump();
    void set_value(jump_type v){value = v;};
    std::string get_value(){
        switch(value) {
        case 0: return "unknown jump type";
        case 1: return "break";
        case 2: return "continue";
        }
  };
    std::string get_subtype(){return "Jump";};
private:
    jump_type value = unknown_jump_type;
};


#endif // JUMP_HPP
