#include "ast.hpp"
#include "antlr4-runtime.h"
#include "expression.hpp"
#include "AlgoParser.h"
#include "statement.hpp"
#include "type.hpp"
#include <string>
#ifndef DECLARATION_HPP
#define DECLARATION_HPP

namespace antlrcpptest {

class Declaration : public Statement {
public:
    Declaration(AlgoParser::StmtsContext* ctx);
    ~Declaration();
    //void set_var_type(var_type t){type = t;};
    std::string get_var_type(){
        switch(var_type) {
        case 0: return "int";
        case 1: return "double";
        case 2: return "char";
        case 3: return "boolean";
        case 4: return "unknown variable type";
        }
    }
    char get_value(){return value;};
    void set_value(char v){value = v;};
    Expression* get_name(){return name;};
    std::string get_subtype(){return "Declaration";};

private:
    int var_type = 4;
    char name;
    Expression* value;
};

}

#endif // DECLARATION_HPP
