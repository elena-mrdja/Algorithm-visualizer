#include "assignment.hpp"
#include "AlgoParser.h"

using namespace antlr4;

namespace antlrcpptest{
    Assignment::Assignment(AlgoParser::StmtsContext* ctx)
    {
     if (ctx->children.size() == 7){
         value = Assignment(*(ctx->exp(5)));
         length = Assignment(*(ctx->exp(2)));
         name = Assignment(*(ctx->exp(0)));
     } else {
         name = Assignment(*(ctx->exp(0)));
         value = Assignment(*(ctx->exp(2)));
     }
    }
}
