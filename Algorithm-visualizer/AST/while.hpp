#include "decision.hpp"
#include "block.hpp"
#include "ast.hpp"
#ifndef WHILE_HPP
#define WHILE_HPP

class While : public Decision {
public:
    While();
    ~While();
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    Block* get_block_stmt(){return block_stmt;};
    void set_block_stmt(Block* stmt){block_stmt = stmt;};
    std::string get_subtype(){return "While";};
    //attributes: condition, block
private:
    Expression* condition;
    Block* block_stmt;
};

#endif // WHILE_HPP
