#include "type.hpp"

using namespace antlr4;

namespace antlrcpptest{
    Type::Type(AlgoParser::VarDecContext* ctx) {

        if (ctx->type()->CHAR()){
            t = 0;
        }else if (ctx->type()->INT()){
            t = 1;
        }else if (ctx->type()->DOUBLE()){
            t = 2;
        }else if (ctx->type()->BOOLEAN()){
            t = 3;
        }else{
            t = 4;
        }

    };
};

