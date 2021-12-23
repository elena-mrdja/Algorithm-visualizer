#ifndef TEST_FLOWCHART_HPP
#define TEST_FLOWCHART_HPP
#include "test_flowchart.hpp"
#include "viewer.h"
#include <string>
#include <iostream>
using namespace std;

enum chart_shape {
    rectangle = 0,
    diamond = 1,
    circle = 2
    };

struct flowchart {
    int chart_shape;
    string text;
    int first_block; // num of stmts in the first block (if in if and the only block in while)
    int second_block; // num of stmts in else
};

flowchart one = {0, "Declare x"};
flowchart two = {1, "If x = 1", 1};
flowchart three = {0, "Assign x"};
flowchart four = {1, "While x > 10", 3};



#endif // TEST_FLOWCHARTS_HPP
