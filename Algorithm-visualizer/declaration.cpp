#include "declaration.hpp"

using namespace antlr4;

namespace antlrcpptest{
    Declaration::Declaration(AlgoParser::StmtsContext* ctx) {
        name = Declaration(*(ctx->exp(1)));
        value = Declaration(*(ctx->exp(3)));

        if (ctx->Declaration()->INT()){
            var_type = 0;
        }else if (ctx->Declaration()->DOUBLE()){
            var_type = 1;
        }else if (ctx->Declaration()->CHAR()){
            var_type = 2;
        }else if (ctx->Declaration()->BOOLEAN()){
            var_type = 3;
        }else{
            var_type = 4;
        }

    }
};
