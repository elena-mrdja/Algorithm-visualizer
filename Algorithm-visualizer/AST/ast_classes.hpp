#include "ast.hpp"
#include "expression.hpp"
#include "statement.hpp"
#include "unop.hpp"
#include "block.hpp" //used in class Statement
#ifndef AST_CLASSES_HPP
#define AST_CLASSES_HPP



//AST
class AST {
protected : AST();
protected : ~AST();
virtual std::string get_type() = 0; // Statement or Expression   (this is an abstract method which will be defined in subclasses Statement
//and Expression and inherited by every other subclass below)
virtual std::string get_subtype() = 0; // Block, Declaration, UnOp, BinOp, ...
//(this is an abstract method which will be defined in subclasses Block, Declaration, ...)
};







//STATEMENT
class Statement : public AST {
protected : Statement();
protected : ~Statement();
std::string get_type(){return "Statement";};
};








//EXPRESSION
class Expression : public AST {
public : Expression();
public : ~Expression();
std::string get_type(){return "Expression";};
virtual double get_value() = 0;
virtual std::string get_exp_type() = 0;
};







//UNARY OPERATIONS
class Negation : public Expression {
public : Negation();
public : ~Negation();
public : double get_value(){return !(expression->get_value());};
private :
    Expression* expression;
};


class PlusPlus : public Statement {
public : PlusPlus();
public : ~PlusPlus();
public : double get_value(){
        if (var->get_exp_type() == "bool") return 0;
        return var->get_value() + 1;
    };
private :
    Variable* var;
};




#endif // AST_CLASSES_HPP
