#include <iostream>
#include "ast.hpp"
#include "antlr4-runtime.h"
#include "AlgoParser.h"
#include <string>
using namespace std;
using namespace antlr4;
using namespace antlrcpptest;
SingleOutput::SingleOutput(AlgoParser::ExpContext* ctx){
    if (ctx->integerType()){
        value = ctx->integerType()->INTEGER()->getText();
        val_type = "integer";
    }else if (ctx->doubleType()){
        value = ctx->doubleType()->FLOAT()->getText();
        val_type = "double";
    }else if (ctx -> boolType()){
        value = ctx->boolType()->getText();
        val_type = "boolean";
    }else if (ctx -> variable()){
        value = ctx->variable()->STRING()->getText();
        val_type = "variable";
    }
}
BinOp::BinOp(AlgoParser::ExpContext* ctx){
    AlgoParser::ExpContext* left_node = ctx->exp(0);
    AlgoParser::ExpContext* right_node = ctx->exp(1);
    //BinOpExp* left_exp(left_node);
    //BinOpExp* right_exp(right_node);
    if (left_node->binOp()){
        left_exp = new BinOp(left_node);
    }else if(left_node->LP()){
        left_exp = new BinOp(left_node->exp(0));
        left_brakets = true;
    }else if((left_node->integerType()) || (left_node->doubleType()) || (left_node->boolType())){
        left_exp = new SingleOutput(left_node);
    }else if(left_node->variable()){
        left_exp = new SingleOutput(left_node);
    }else{
        std::cout << "something else" <<std::endl;
    }

    if (right_node->binOp()){
        right_exp = new BinOp(right_node);
    }else if(right_node->LP()){
        right_exp = new BinOp(right_node->exp(0));
        right_brakets = true;
    }else if((right_node->integerType()) || (right_node->doubleType()) || (right_node->boolType())){
        right_exp = new SingleOutput(right_node);
    }else if(right_node->variable()){
        right_exp = new SingleOutput(right_node);
    }else{
            std::cout << "something else" <<std::endl;
     }

    AlgoParser::BinOpContext *i = ctx->binOp();

    if(i->PLUS()){
        operation = 0;
    }else if(i->MINUS()){
        operation = 1;
    }else if(i->TIMES()){
        operation = 2;
    }else if(i->DIV()){
        operation = 3;
    }else if(i->MOD()){
        operation = 4;
    }else if(i->XAND()){
        operation = 5;
    }else if(i->XOR()){
        operation = 6;
    }else if(i->EQQ()){
        operation = 7;
    }else if(i->NOTEQQ()){
        operation = 8;
    }else if(i->LT()){
        operation = 9;
    }else if(i->MT()){
        operation = 10;
    }else if(i->LEQ()){
        operation = 11;
    }else if(i->MEQ()){
        operation = 12;
    }else {
        operation = 13;
    }
}
std::string BinOp::get_value(){
    std::string a = get_left_expression()->get_value();
    std::string op = get_operation();
    std::string b = right_exp->get_value();
    std::string res;

    if (left_brakets){
        if(right_brakets){
            res = "( " + a + " ) " + op + " ( " + b + " )";
        }else{
            res = "( " + a + " ) " + op + " " + b;
        }
    }else{
        if(right_brakets){
            res = a + " " + op + " ( " + b + " )";
        }else{
            res = a + " " + op + " " + b;
        }

    }
    return res;
}


UnOp::UnOp(AlgoParser::ExpContext* ctx){
    AlgoParser::ExpContext* left_node = ctx->exp(0);
    AlgoParser::UnopContext *i = ctx->unop();
    if(i->PLUSPLUS()){
        operation = 0;
    }else if(i->MINUSMINUS()){
        operation = 1;
    }else {
        operation = 2;
    }
}
std::string UnOp::get_value(){
    std::string a = get_left_expression()->get_value();
    std::string op = get_operation();
    std::string res;
    res = a + op;
    return res;
}

Jump::Jump(AlgoParser::JumpContext* ctx){
    if(ctx->CONT()){
        jumper = 0;
    }else if(ctx->BREAK()){
        jumper = 1;
    }else {
        jumper = 2;
    }
}

Expression::Expression(AlgoParser::ExpContext* ctx){
    if (ctx -> binOp()){
        child = new BinOp(ctx);
    }else if (ctx -> exp(0)){
        child = Expression(ctx->exp(0)).get_child();
    }else{
        child = new SingleOutput(ctx);
    }
}
Declaration::Declaration(AlgoParser::VarDecContext* ctx) {

    value = new Expression(ctx->exp(0));
    name = ctx->variable()->STRING()->getText();

    if (ctx->type()->INT()){
        var_type = 0;
    }else if (ctx->type()->DOUBLE()){
        var_type = 1;
    }else if (ctx->type()->CHAR()){
        var_type = 2;
    }else if (ctx->type()->BOOLEAN()){
        var_type = 3;
    }else{
        var_type = 4;
    }

}

Assignment::Assignment(AlgoParser::AssignContext* ctx)
{
    value = new Expression(ctx->exp(0));
    name = ctx->variable()->STRING()->getText();
}

Statement::Statement(AlgoParser::StmtsContext* ctx){
    //AlgoParser::BinOpContext *i = ctx->binOp();
    if(ctx->assign()){
        AlgoParser::AssignContext* node = ctx->assign();
        child = new Assignment(node);
    }else if(ctx->varDec()){
        AlgoParser::VarDecContext* node = ctx->varDec();
        child = new Declaration(node);
    }
}

AST::AST(AlgoParser::BlockContext* ctx) {
    size = 0;
    children = new Statement[size];
    int idx = 0;
    //cache constructor
    for (auto i: ctx->stmts()){
        Statement child(i); // child to cache
        children[idx] = child;
        size++;
        idx++;
    }
}


