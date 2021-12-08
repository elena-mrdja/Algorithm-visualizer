#include "shapes.hpp"

//the function that will be called by the graphics:
list<list<string>> chart(list<Statement>);
//input: an AST
//output: list of lists of strings:
/*
 [[Shape, String to copy-paste into the shape, (optional, for while and if): Number of statements in the block]]
*/

//during this fuction we also have to build the linked list for
//variable tracking! it is IMPERATIVE NOW that we define WHERE we will keep this list!
