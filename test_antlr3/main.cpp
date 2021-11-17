#include <iostream>

#include "antlr4-runtime.h"
#include "GraceLexer.h"
#include "GraceParser.h"
//#include "ImageVisitor.h"

//using namespace std;
using namespace antlr4;
using namespace antlrcpptest;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("and_keyword.cpp");

    ANTLRInputStream input(stream);
    
    GraceLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    for (auto token : tokens.getTokens()) {
      std::cout << token->toString() << std::endl;
    }

    GraceParser parser(&tokens);
    tree::ParseTree *tree = parser.statement();

    std::cout << tree->toStringTree(&parser) << std::endl;

    //ImageVisitor visitor;
    //Scene scene = visitor.visitFile(tree).as<Scene>();
    //scene.draw();

    return 0;
}
