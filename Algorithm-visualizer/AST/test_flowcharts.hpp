#ifndef TEST_FLOWCHARTS_HPP
#define TEST_FLOWCHARTS_HPP
#include "ast_classes.hpp"

flowchart one;
one.shape = 0;
one.text = "Declare x";

flowchart two;
two.shape = 1;
two.text = "If x = 1";
two.first_block = 1;
two.second_block = 0;

flowchart three;
three.shape = 1;
three.text = "x + 4";

#endif // TEST_FLOWCHARTS_HPP
