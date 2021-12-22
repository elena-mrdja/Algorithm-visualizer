#ifndef TEST_FLOWCHART_HPP
#define TEST_FLOWCHART_HPP
#include <string>
#include <iostream>
using namespace std;


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

#endif // AST_CLASSES_HPP
