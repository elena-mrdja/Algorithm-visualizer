#include "statement.hpp"
#include "expression.hpp"
#include "AlgoParser.h"
#include "ast.hpp"
#include <string>
#ifndef PRINT_HPP
#define PRINT_HPP

namespace antlrcpptest {

class Print : public Statement {
    Print(AlgoParser::StmtsContext* ctx);
    ~Print();
    void set_exp(Expression* e){value = e;};
    Expression* get_exp(){return value;};
    std::string get_subtype(){return "Print";};
private:
    Expression* value;
};

};

#endif // PRINT_HPP
