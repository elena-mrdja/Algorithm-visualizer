#include "block.hpp"

Block::Block()
{

}

void Block::walk(){
    for (int i =0; i<statement_number; i++){
    // statements[i]->evaluate_expression();
    std::cout<<statements[i]; // Dummy line to include in the for loop
    }
}

