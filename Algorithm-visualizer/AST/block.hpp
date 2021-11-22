#include "ast.hpp"
#include "statement.hpp"
#ifndef BLOCK_HPP
#define BLOCK_HPP

class Block : public Statement {
protected : Block();
protected : ~Block();
std::string get_subtype(){return "Block";};
    //list of statements
};

#endif // BLOCK_HPP
