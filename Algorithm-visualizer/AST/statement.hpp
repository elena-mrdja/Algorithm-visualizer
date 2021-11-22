#include "ast.hpp"
#ifndef STATEMENT_HPP
#define STATEMENT_HPP

class Statement : public AST {
protected : Statement();
protected : ~Statement();
std::string get_type(){return "Statement";};
};



#endif // STATEMENT_HPP
