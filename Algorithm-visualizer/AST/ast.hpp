#include "AlgoParser.h"
#include <string>
#include "iostream"
#include "iomanip"
#include "sstream"
using namespace std;
using namespace antlr4;
using namespace antlrcpptest;
// IMPORTANT DO NOT DELETE ANY FUNCTION!!! EVEN IF THEY ARE MARKED AS NO NEEDED

enum bin_ops {
    addition = 0,
    subtraction = 1,
    multiplication = 2,
    division = 3,
    modulo = 4,
    conj = 5,
    disj = 6,
    eqeq = 7,
    noteq = 8,
    lthan = 9,
    mthan = 10,
    leq = 11,
    meq = 12,
    unknown_op = 13
};

enum variable_type {
    var_int = 0,
    var_double = 1,
    var_bool = 2,
    var_char = 3,
    unknown_var = 4
};

enum exp_type {
    boolean = 0,
    number = 1, //the actual value is always a double
    unknown_exp_type = 2
};


struct BinOpExp{
    virtual std::string get_type() = 0;
    virtual std::string get_operation() = 0;
    virtual BinOpExp* get_left_expression() = 0;
    virtual BinOpExp* get_right_expression() = 0;
    virtual std::string get_val_type() = 0;
    virtual std::string get_text() = 0;
    virtual exp_type get_exp_type();
    virtual double get_value();
    int num_blocks(){return 0;s};
};
class SingleOutput : public BinOpExp{
public:
    SingleOutput(AlgoParser::ExpContext* ctx);
    std::string get_text(){return value;}; //returns the value as a string <- IMPORTANT
    std::string get_type(){return "SignleOutput";};
    std::string get_operation(){return "none";}; //no needed
    BinOpExp* get_left_expression(){return nullptr;}; // no needed
    BinOpExp* get_right_expression(){return nullptr;}; //no needed
    std::string get_val_type(){return val_type;}; // returns a type of a single output
                                                   // possible outputs: 'double', 'integer', 'boolean', 'variable'.
    double get_value(); //returns the actual value of the variable / number as a double
                        //the function isn't implemented right now: we have to deal with Cache access
    int num_blocks(){return 0;};
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
        case addition: return "+";
        case subtraction: return "-";
        case multiplication: return "*";
        case division: return "/";
        case modulo: return "%";
        case conj: return "&&";
        case disj: return "||";
        case eqeq: return "==";
        case noteq: return "!=";
        case lthan: return "<";
        case mthan: return ">";
        case leq: return "<=";
        case meq: return ">=";
        default: return "unknown binary operation";
        }
    };
    exp_type get_exp_type(){
        switch(operation) {
        case addition: return number;
        case subtraction: return number;
        case multiplication: return number;
        case division: return number;
        case modulo: return number;
        case conj: return boolean;
        case disj: return boolean;
        case eqeq: return boolean;
        case noteq: return boolean;
        case lthan: return boolean;
        case mthan: return boolean;
        case leq: return boolean;
        case meq: return boolean;
        default: return unknown_exp_type;
        }
    };
    double get_value(){
            switch(operation) {
            case addition: {
                if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean) {return 0;};
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                return left_exp->get_value() + right_exp->get_value();
            };
            case subtraction: {
                if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                return left_exp->get_value() - right_exp->get_value();
            };
            case multiplication: {
                if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                return left_exp->get_value() * right_exp->get_value();
            };
            case division: {
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
            case modulo: {
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
                return (int)left_exp->get_value() % (int)right_exp->get_value();
            };
            case conj: {
                if (left_exp->get_value() && right_exp->get_value()) return 1;
                return 0;
            };
            case disj: {
                if (left_exp->get_value() || right_exp->get_value()) return 1;
                return 0;
            };
            case eqeq: {
                if (left_exp->get_value() == right_exp->get_value()) return 1;
                return 0;
            };
            case noteq: {
                if (left_exp->get_value() != right_exp->get_value()) return 1;
                return 0;
            };
            case lthan: {
                if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (left_exp->get_value() < right_exp->get_value()) return 1;
                return 0;
            };
            case mthan: {
                if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (left_exp->get_value() > right_exp->get_value()) return 1;
                return 0;
            };
            case leq: {
                if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (left_exp->get_value() <= right_exp->get_value()) return 1;
                return 0;
            };
            case meq: {
                if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (left_exp->get_value() >= right_exp->get_value()) return 1;
                return 0;
            };
            default: return 0;
        }
    };
    BinOpExp* get_left_expression(){return left_exp;}; //return a node to left expression
    BinOpExp* get_right_expression(){return right_exp;}; // returns a node to right expression
    std::string get_val_type(){return "BinOperation";}; //non necessarry function for binOp
    std::string get_text(); //returns an entire binOp line as a string (ex. output: '( 4.0 + x ) * 5')
    //std::string get_value();
    std::string get_type(){return "BinOp";};
private:
    bin_ops operation;
    BinOpExp* left_exp;
    BinOpExp* right_exp;
    bool left_brakets = false;
    bool right_brakets = false;
};

class Expression {
public :
    Expression(AlgoParser::ExpContext* ctx);
    Expression();
    //~Expression();
    BinOpExp* get_child(){return child;}; //return a child of expression (for now only binOp or SingleOutputs)
    std::string get_type(){return "Expression";};
    int num_blocks(){return 0;};
private:
    BinOpExp* child;
};

struct AssignDec { //needed to unite statement children
    virtual std::string get_name() = 0;
    virtual Expression* get_value() = 0;
    virtual std::string get_type() = 0;
    virtual std::string get_var_type() = 0;
    int num_blocks(){return 0;};
};
class Declaration : public AssignDec {
public:
    Declaration(AlgoParser::VarDecContext* ctx);
    //~Declaration();
    std::string get_var_type(){ //return type of the variable
        switch(var_type) {
        case var_int: return "int";
        case var_double: return "double";
        case var_char: return "char";
        case var_bool: return "boolean";
        case unknown_var: return "unknown variable type";
        }
    }
    Expression* get_value(){return value;}; // returns the object of class which corresponds to the value
    std::string get_name(){return name;}; // returns the name of the variable
    //std::string get_array_size(){return array_size;};
    std::string get_type(){return "Declaration";};

private:
    variable_type var_type = unknown_var;
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
    virtual int num_blocks();

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
    int num_blocks(){
        int n = 0;
        //here we have to add walking through the list of statements and adding the blocks
        return n;
    };
    //walker function
private:
    Statement* child;
    Statement* children;
    int size;
};


//below is stuff for the AST walker
enum chart_shape {
    rectangle = 0,
    diamond = 1,
    circle = 2
};

enum chart_type {
    process = 0,
    if_else = 1,
    while_chart = 2
};

struct flowchart {
    chart_shape shape;
    chart_type type;
    string text;
    int first_block; // num of stmts in the first block (if in if and the only block in while)
    int second_block; // num of stmts in else
};



