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
    AST ast(tree->mainStmt()->block());
    Declaration dec = Declaration(tree->mainStmt()->block()->stmts(0)->varDec());
    AssignDec assdec = AssignDec();
    cout << assdec.get_type() << endl;
    std::cout <<ast.get_child(0).get_type()<< std::endl;
    //ImageVisitor visitor;
    //Scene scene = visitor.visitFile(tree).as<Scene>();
    //scene.draw();

    return 0;
}
