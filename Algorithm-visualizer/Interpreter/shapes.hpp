#include "shapes.hpp"
#include "ast_classes.hpp"

enum chart_shape {
    rectangle = 0,
    diamond = 1,
    circle = 2
};

//structure that will be directly used by the GUI team
struct flowchart {
    chart_shape shape;
    string text;
    int first_block; // num of stmts in the first block (if in if and the only block in while)
    int second_block; // num of stmts in else
};


void read_statement(Statement* stmt);  //returns a flowchart corresponding to the given statement





