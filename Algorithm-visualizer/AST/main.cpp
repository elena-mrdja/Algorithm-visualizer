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
    Block block(tree->mainStmt()->block());
    std::cout << block.get_child(1).get_child()->get_value()->get_child()->get_value()<< std::endl;
    //ImageVisitor visitor;
    //Scene scene = visitor.visitFile(tree).as<Scene>();
    //scene.draw();

    return 0;
}
