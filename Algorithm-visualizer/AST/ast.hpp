#include "AlgoParser.h"
#include <string>
#include "iostream"
#include "iomanip"
#include "sstream"
using namespace std;
using namespace antlr4;
using namespace antlrcpptest;
// IMPORTANT DO NOT DELETE ANY FUNCTION!!! EVEN IF THEY ARE MARKED AS NO NEEDED
struct BinOpExp{
    virtual std::string get_type() = 0;
    virtual std::string get_operation() = 0;
    virtual BinOpExp* get_left_expression() = 0;
    virtual BinOpExp* get_right_expression() = 0;
    virtual std::string get_val_type() = 0;
    virtual std::string get_value() = 0;
};
class SingleOutput : public BinOpExp{
public:
    SingleOutput(AlgoParser::ExpContext* ctx);
    std::string get_value(){return value;}; //returns the value as a string <- IMPORTANT
    std::string get_type(){return "SignleOutput";};
    std::string get_operation(){return "none";}; //no needed
    BinOpExp* get_left_expression(){return nullptr;}; // no needed
    BinOpExp* get_right_expression(){return nullptr;}; //no needed
    std::string get_val_type(){return val_type;}; // returns a type of a single output
                                                   // possible outputs: 'double', 'integer', 'boolean', 'variable'.
private:
    std::string value;
    std::string val_type;
};
class BinOp : public BinOpExp{
public:
    BinOp(AlgoParser::ExpContext* ctx);
    //~BinOp();
    std::string get_operation(){ //returns binOp operation
        switch(operation) {
        case 0: return "+";
        case 1: return "-";
        case 2: return "*";
        case 3: return "/";
        case 4: return "%";
        case 5: return "&&";
        case 6: return "||";
        case 7: return "==";
        case 8: return "!=";
        case 9: return "<";
        case 10: return ">";
        case 11: return "<=";
        case 12: return ">=";
        default: return "unknown binary operation";
        }
    }
    BinOpExp* get_left_expression(){return left_exp;}; //return a node to left expression
    BinOpExp* get_right_expression(){return right_exp;}; // returns a node to right expression
    std::string get_val_type(){return "BinOperation";}; //non necessarry function for binOp
    std::string get_value(); //returns an entire binOp line as a string (ex. output: '( 4.0 + x ) * 5')
    //std::string get_value();
    std::string get_type(){return "BinOp";};
private:
    int operation;
    BinOpExp* left_exp;
    BinOpExp* right_exp;
    bool left_brakets = false;
    bool right_brakets = false;
};

class UnOp : public BinOpExp{
public:
    UnOp(AlgoParser::ExpContext* ctx);
    //~UnOp();
    std::string get_operation(){ //returns binOp operation
        switch(operation) {
        case 0: return "++";
        case 1: return "--";
        default: return "unknown operation";
        }
    }
    BinOpExp* get_left_expression(){return left_exp;}; //return the number to which we add or subtract 1
    std::string get_val_type(){return "UnOperation";};
    std::string get_value();
    std::string get_type(){return "UnOp";};
private:
    int operation;
    BinOpExp* left_exp;
};


class Jump : public BinOpExp{
public:
    Jump(AlgoParser::JumpContext* ctx);
    //~UnOp();
    std::string get_val_type(){
        switch(jumper) {
        case 0: return "Break";
        case 1: return "Continue";
        default: return "unknown operation";
        }
    }
    std::string get_type(){return "Jump";};
private:
    int jumper;
};


class Expression {
public :
    Expression(AlgoParser::ExpContext* ctx);
    Expression();
    //~Expression();
    BinOpExp* get_child(){return child;}; //return a child of expression (for now only binOp or SingleOutputs)
    std::string get_type(){return "Expression";};
private:
    BinOpExp* child;
};

struct AssignDec { //needed to unite statement children
    virtual std::string get_name() = 0;
    virtual Expression* get_value() = 0;
    virtual std::string get_type() = 0;
    virtual std::string get_var_type() = 0;
};
class Declaration : public AssignDec {
public:
    Declaration(AlgoParser::VarDecContext* ctx);
    //~Declaration();
    std::string get_var_type(){ //return type of the variable
        switch(var_type) {
        case 0: return "int";
        case 1: return "double";
        case 2: return "char";
        case 3: return "boolean";
        case 4: return "unknown variable type";
        }
    }
    Expression* get_value(){return value;}; // returns the object of class which corresponds to the value
    std::string get_name(){return name;}; // returns the name of the variable
    //std::string get_array_size(){return array_size;};
    std::string get_type(){return "Declaration";};

private:
    int var_type = 4;
    //std::string array_size;
    std::string name;
    Expression* value; // double for now change later
};
class Assignment : public AssignDec {
public:
    Assignment(AlgoParser::AssignContext* ctx);
    //~Assignment();
    Expression* get_value(){return value;}; // returns the object of class which corresponds to the value
    //Expression* get_index(){return index;};
    //void set_index(Expression* i){index = i;};
    std::string get_name(){return name;}; // returns the name of the variable
    std::string get_type(){return "Assignment";};
    std::string get_var_type(){return "none";}; //assign does not need to return variable type
private:
    std::string name;
    Expression* value; // double for now change later
    //Expression* index;
};
// double x = 2.0;
// x = x + 2
class Statement{
public:
    Statement(AlgoParser::StmtsContext* ctx);
    Statement(){child = nullptr;};
    AssignDec* get_child(){return child;}; //return a child of statement,
                                            //i.e directs to the actual statement (ex. assign, declaration, return, etc.)
    std::string get_type(){return "Statement";};
    //~Statement();
    private :
    AssignDec* child;

};


class AST {
public :
    AST(AlgoParser::BlockContext* ctx/*, pass down cache*/ );
    AST();
    //~Block();
    Statement* get_children(){return children;}
    Statement get_child(int i){return children[i];} //returns a child by index
    int get_size(){return size;} //needed for a for loop
    std::string get_type(){return "Block";};
    //walker function
private:
    Statement* child;
    Statement* children;
    int size;
};



