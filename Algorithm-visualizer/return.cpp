#include "return.hpp"

using namespace antlr4;

namespace antlrcpptest {
    Return::Return(AlgoParser::StmtsContext* ctx){
        value = Expression(*(ctx->exp()));
    }
};

