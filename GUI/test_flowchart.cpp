#ifndef TEST_FLOWCHART_HPP
#define TEST_FLOWCHART_HPP
#include "test_flowchart.hpp"

flowchart one;
one.shape = 0;
one.text = "Declare x";

flowchart two;
two.shape = 1;
two.text = "If x = 1";
two.first_block = 1;
two.second_block = 0;

flowchart three;
three.shape = 2;
three.text = "x + 4";

#endif // TEST_FLOWCHARTS_HPP
