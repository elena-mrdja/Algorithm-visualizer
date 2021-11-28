#include "ast.hpp"
#include "block.hpp"
#ifndef STATEMENT_HPP
#define STATEMENT_HPP

class Statement : public AST {
protected : Statement();
protected : ~Statement();
    std::string get_type(){return "Statement";};
Block* block; //reference to the block the statement is in: we want to be able to access the variables
};


#endif // STATEMENT_HPP
