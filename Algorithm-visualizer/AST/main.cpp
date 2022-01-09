#include <iostream>

#include "antlr4-runtime.h"
#include "AlgoLexer.h"
#include "AlgoParser.h"
#include "ast.hpp"
#include <string>

using namespace std;
using namespace antlr4;
using namespace antlrcpptest;

int main(int argc, const char* argv[]) {
    cout << "testing" <<endl;
    std::ifstream stream;
    stream.open("example2.cpp"); // testing file

    ANTLRInputStream input(stream);

    AlgoLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    for (auto token : tokens.getTokens()) {
      std::cout << token->toString() << std::endl;
    }

    AlgoParser parser(&tokens);
    AlgoParser::FileContext *tree = parser.file();

    std::cout << tree->toStringTree(&parser) << std::endl;
    Block ast(tree->mainStmt()->block());
    //cout << "testing" << std::endl;
    Declaration dec = Declaration(tree->mainStmt()->block()->stmts(0)->varDec());
    //cout << "testing" << std::endl;
    cout <<ast.get_child(2).get_type() << " here" << endl;
    return 0;
}
