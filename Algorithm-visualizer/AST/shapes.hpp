#ifndef SHAPES_H
#define SHAPES_H

//function that creates struct for a flowchart for each statement
flowchart read_statement(Statement* stmt, int i, list<map<Variable*, ValuesList*>*>* variables);

//function that need to be completed by GUI (for each statement, read it, create a struct and then use it for drawing)
void draw_flowchart(Block* block);


enum chart_shape {
    rectangle = 0,
    diamond = 1,
    circle = 2
};

struct flowchart {
    chart_shape shape;
    string text;
    int first_block; // num of stmts in the first block (if in if and the only block in while)
    int second_block; // num of stmts in else
};



#endif
