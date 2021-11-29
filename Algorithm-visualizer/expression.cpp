#include "expression.hpp"

using namespace antlr4;

namespace antlrcpptest {
    Expression::Expression(AlgoParser::FileContext* ctx) {
        if (Expression(*(ctx->exp(0))) == '-'){
            value = -exp(0);


        integerType| doubleType| boolType| string | LP exp RP| exp binOp exp| unop exp| exp unop | negation | identifier | arrayType | variable;
    };

};
