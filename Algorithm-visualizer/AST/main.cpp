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
    stream.open("example11.cpp"); // testing file

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
    Cache* cache = new Cache(ast.get_size());
    fill_cache(&ast, cache);
    cout << "cache filled" << cache << endl;
    draw_flowchart(&ast, cache);
    cout<<"test"<<endl;
    //Declaration dec = Declaration(tree->mainStmt()->block()->stmts(0)->varDec());
    //Expression exp = Expression(tree->mainStmt()->block()->stmts(1)->assign()->exp(0));
    return 0;
}