#include "ast.hpp"
#include "statement.hpp"
#ifndef BLOCK_HPP
#define BLOCK_HPP

class Block : public AST{
protected : Block();
protected : ~Block();
std::string get_type(){return "Block";};
public:
list<Statement> statements; // list of statements in the block
std::map<char, char> variables;
Block* parent_block; //nullptr if it is the program block
};

#endif // BLOCK_HPP
