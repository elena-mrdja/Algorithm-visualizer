#ifndef AST_CLASSES_HPP
#define AST_CLASSES_HPP
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace std;

//CACHE
class Cache {
public:
    Cache();
    ~Cache();
};

//AST
class AST {
public :
    AST();
    ~AST();
    virtual string get_type() = 0; // Statement or Expression
    virtual string get_subtype() = 0; // Block, Declaration, UnOp, BinOp, ...
};

//BLOCK
class Block : public AST{
public :
    Block();
    ~Block();
    string get_type(){return "Block";};
    list<Statement> statements; // list of statements in the block
    Cache variables;
    Block* parent_block; //nullptr if it is the program block
};

//STATEMENT
class Statement : public AST {
public :
    Statement();
    ~Statement();
    string get_type(){return "Statement";};
    Block* block; //reference to its block (to be able to access Cache)
};


//EXPRESSION
enum exp_type {
    boolean = 0,
    number = 1 //always a double

};

class Expression : public AST {
public :
    Expression();
    ~Expression();
    string get_type(){return "Expression";};
    virtual double get_value() = 0;
    virtual exp_type get_exp_type() = 0;
};


//UNARY OPERATION
class Negation : public Expression {
public :
    Negation();
    ~Negation();
    string get_subtype(){return "UnOp";};
    exp_type get_exp_type(){return boolean;};
    Expression* get_expression(){return expression;};
    void set_expression(Expression* exp){expression = exp;};
    double get_value(){
        if (expression->get_value() != 0) return 0;
        return 1;
    };
private :
    Expression* expression;
};

//BINARY OPERATIONS
class BinOp : public Expression {
public :
    BinOp();
    ~BinOp();
    string get_subtype(){return "BinOp";};
    void set_left_exp(Expression* exp){left_exp = exp;};
    void set_right_exp(Expression* exp){right_exp = exp;};
    Expression* get_left_exp(){return left_exp;};
    Expression* get_right_exp(){return right_exp;};
    Expression* left_exp;
    Expression* right_exp;
};

class Addition : public BinOp {
public :
    Addition();
    ~Addition();
    public : double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean) {return 0;};
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        return left_exp->get_value() + right_exp->get_value();
    };
    exp_type get_exp_type(){return number;};
};

class Subtraction : public BinOp {
public :
    Subtraction();
    ~Subtraction();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        return left_exp->get_value() - right_exp->get_value();
    };
    exp_type get_exp_type(){return number;};
};

class Multiplication : public BinOp {
public :
    Multiplication();
    ~Multiplication();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        return left_exp->get_value() * right_exp->get_value();
    };
    exp_type get_exp_type(){return number;};
};

class Division : public BinOp {
public :
    Division();
    ~Division();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (right_exp->get_value() == 0)
        {
            cout << "Division by zero";
            return 0;
        };
        return left_exp->get_value() / right_exp->get_value();
    };
    exp_type get_exp_type(){return number;};
};

class Mthan : public BinOp {
public :
    Mthan();
    ~Mthan();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (left_exp->get_value() > right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
};

class Lthan : public BinOp {
public :
    Lthan();
    ~Lthan();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (left_exp->get_value() < right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
};

class Leq : public BinOp {
public :
    Leq();
    ~Leq();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (left_exp->get_value() <= right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
};

class Meq : public BinOp {
public :
    Meq();
    ~Meq();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (left_exp->get_value() >= right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
};

class Eqeq : public BinOp {
public :
    Eqeq();
    ~Eqeq();
    double get_value(){
        if (left_exp->get_value() == right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
};

class AndOp : public BinOp {
public :
    AndOp();
    ~AndOp();
    double get_value(){
        if (left_exp->get_value() && right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
};

class OrOp : public BinOp {
public :
    OrOp();
    ~OrOp();
    double get_value(){
        if (left_exp->get_value() || right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
};

class Variable : public Expression {
public :
    Variable();
    ~Variable();
    void set_name(std::string n){name = n;};
    void set_value(bool val){
        if (val) value = 1;
        else value = 0;
        type = boolean;
    };
    void set_value(double val){
        value = val;
        type = number;
    };
    std::string get_name(){return name;};
    double get_value(){return value;};
    exp_type get_exp_type(){return type;};
    string get_subtype(){return "Variable";};
protected:
    std::string name;
    double value = 0;
    exp_type type;
};

/*
//STATEMENT
class Statement : public AST {
protected : Statement();
protected : ~Statement();
std::string get_type(){return "Statement";};
};
*/

class Block : public AST{
public :
    Block();
   ~Block();
    string get_type(){return "Block";};
protected:
    list<Statement> statements; // list of statements in the block
    std::map<char, char> variables; //this is the Cache and will be changed
    Block* parent_block; //nullptr if it is the program block
};

class Declaration : public Statement {
public:
    Declaration();
    ~Declaration();
    void set_variable(Variable var){variable = var;};
    double get_value(){return variable.get_value();};
    void set_value(double v){variable.set_value(v);};
    void set_value(bool v){variable.set_value(v);};
    Variable get_variable(){return variable;};
    std::string get_subtype(){return "Declaration";};
  //void add_variable_to_list(){Block variables; variables.insert({variable, value});};
protected:
    Variable variable;
};

class Assignment : public Statement {
public:
    Assignment();
    ~Assignment();
    string get_name(){return var_name;};
    void set_name(string n){var_name = n;};
    string get_subtype(){return "Assignment";};
protected:
    //the Assigment is of form Variable = Expression
    //the value of the expression is supposed to be added straight to the Cache and not kept in this object
    //When we do the walker/variable tracking maybe we will need to add another argument
    //in this object that keeps Variable/Expression.
    string var_name; //at this point we know that the variable is in Cache
};

class Return : public Statement {
    Return();
    ~Return();
    void set_exp(Expression* e){exp = e;};
    Expression* get_exp(){return exp;};
    string get_subtype(){return "Return";};
private:
    Expression* exp;
};

//DECISIONS
class Decision : public Statement {
public :
    Decision();
    ~Decision();
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    string get_subtype(){return "Decision";};
    double get_value(){
        if (condition->get_value()) return 1;
        return 0;
    };
    bool is_true(){
        if (get_value() == 1) return true;
        return false;
    };
protected:
    Expression* condition;
};

class IfRest : public Statement {
public:
   IfRest();
   ~IfRest();
   Block* get_block_stmt(){return block_stmt;};
   void set_block_stmt(Block* stmt){block_stmt = stmt;};
   string get_subtype(){return "IfRest";};
protected:
    Block* block_stmt;
};

class IfElse : public Decision {
public:
    IfElse();
    ~IfElse();
    //attributes: condition(expression), IfRest
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    void set_else_stmt(IfRest* stmt){else_stmt = stmt;};
    IfRest* get_else_stmt(){return else_stmt;};
    std::string get_subtype(){return "IfElse";};
protected:
    IfRest* else_stmt;
};

class While : public Decision {
public:
    While();
    ~While();
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    Block* get_block_stmt(){return block_stmt;};
    void set_block_stmt(Block* stmt){block_stmt = stmt;};
    std::string get_subtype(){return "While";};
protected:
    Expression* condition;
    Block* block_stmt;
};

#endif // AST_CLASSES_HPP
