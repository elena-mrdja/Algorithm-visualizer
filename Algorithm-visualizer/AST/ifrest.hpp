#include "block.hpp"
#include "ast.hpp"
#ifndef IFREST_H
#define IFREST_H

class IfRest : public Statement {
public:
   IfRest();
   ~IfRest();
   Block* get_block_stmt(){return block_stmt;};
   void set_block_stmt(Block* stmt){block_stmt = stmt;};
   std::string get_subtype(){return "IfRest";};
private:
    Block* block_stmt;
};

#endif // IFREST_H
