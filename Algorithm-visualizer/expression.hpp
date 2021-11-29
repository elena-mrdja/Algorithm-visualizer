#include "ast.hpp"
#include "AlgoParser.h"
#include <string>
#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

namespace antlrcpptest {

class Expression : public AST {
public : 
    Expression(AlgoParser::FileContext* ctx);
    ~Expression()
    Expression(expression_type t) {
        type = t;
    };
    ~Expression();
    std::string get_type(){return "Expression";};
private:
    expression_type type = unknown_expression_type;
};

};

#endif // EXPRESSION_HPP

integerType| doubleType| boolType| string | LP exp RP| exp binOp exp| unop exp| exp unop | negation | identifier | arrayType | variable;
