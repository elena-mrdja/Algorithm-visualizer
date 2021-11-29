#include "print.hpp"

using namespace antlr4;

namespace antlrcpptest {
    Print::Print(AlgoParser::StmtsContext* ctx)) {
        value = Print(*(ctx->exp()));
    };
};

