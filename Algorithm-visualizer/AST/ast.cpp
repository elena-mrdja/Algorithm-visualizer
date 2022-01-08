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
    }else if (left_node->negation()){
        left_exp = new Negation(left_node->negation());
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
    }else if (right_node->negation()){
        right_exp = new Negation(right_node->negation());
    }else{
            std::cout << "something else" <<std::endl;
     }

    AlgoParser::BinOpContext *i = ctx->binOp();

    if(i->PLUS()){
        operation = addition;
    }else if(i->MINUS()){
        operation = subtraction;
    }else if(i->TIMES()){
        operation = multiplication;
    }else if(i->DIV()){
        operation = division;
    }else if(i->MOD()){
        operation = modulo;
    }else if(i->XAND()){
        operation = conj;
    }else if(i->XOR()){
        operation = disj;
    }else if(i->EQQ()){
        operation = eqeq;
    }else if(i->NOTEQQ()){
        operation = noteq;
    }else if(i->LT()){
        operation = lthan;
    }else if(i->MT()){
        operation = mthan;
    }else if(i->LEQ()){
        operation = leq;
    }else if(i->MEQ()){
        operation = meq;
    }else {
        operation = unknown_op;
    }
}
std::string BinOp::get_text(){
    std::string a = get_left_expression()->get_text();
    std::string op = get_operation();
    std::string b = right_exp->get_text();
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
    std::string left_node = ctx->exp(0)->variable()->getText();
    AlgoParser::UnopContext *i = ctx->unop();
    if(i->PLUSPLUS()){
        operation = 0;
    }else if(i->MINUSMINUS()){
        operation = 1;
    }else {
        operation = 2;
    }
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
    }else if (ctx->negation()){
        child = new Negation(ctx->negation());
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
    }else if(ctx->returnStmt()){
        AlgoParser::ReturnStmtContext* node = ctx->returnStmt();
        child = new Return(node);
    }else if(ctx->print()){
        AlgoParser::PrintContext* node = ctx->print();
        child = new Print(node);
    }
}

Block::Block(AlgoParser::BlockContext* ctx) {
    size = ctx->children.size();
    children = new Statement[size];
    int idx = 0;
    //cache constructor
    for (auto i: ctx->stmts()){
         Statement child(i); // child to cache
         children[idx] = child;
         idx++;
    }
}

WhileStmt::WhileStmt(AlgoParser::WhileStmtContext* ctx){
   condition = new Expression(ctx->exp());
   block_stmt = new Block(ctx->block());
}



Return::Return(AlgoParser::ReturnStmtContext* ctx){
    AlgoParser::ExpContext* node = ctx->exp();
    value = new Expression(node);
}

Print::Print(AlgoParser::PrintContext* ctx){
    AlgoParser::ExpContext* node = ctx->exp();
    value = new Expression(node);
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

IfElse::IfElse(AlgoParser::IfelseContext* ctx){

    condition = new Expression(ctx->exp());
    block = new Block(ctx->block());
    if (ctx->ifrest()){
        else_stmt = new IfRest(ctx->ifrest());
    }else{
        else_stmt = nullptr;
    }

}

IfRest::IfRest(AlgoParser::IfrestContext* ctx){
    block = new Block(ctx->block());


}



ValuesList::ValuesList(Value* h, Value* t){
    head = h;
    tail = t;
};

ValuesList::ValuesList(){
    head = new Value();
    tail = head;
}

Value* ValuesList::get_head(){return head;};
Value* ValuesList::get_tail(){return tail;};

void ValuesList::set_head(Value* h){head = h;};
void ValuesList::set_tail(Value* t){tail = t;};
bool ValuesList::is_empty(){return head == nullptr;};
void ValuesList::add_value(Value* v){
    if (is_empty()){
        head = v;
        tail = v;
    }
    else {
        tail->next = v;
        v->prev = tail;
        tail = v;
    }
};


//variable tracking
Cache::Cache(int number){
    num_lines = number;
}

void fill_while_block(Block* block, Expression* condition, Cache* cache, int while_condition_line);
void fill_declaration(Statement dec, Cache* cache, int current_line);
void fill_assignment(Statement assign, Cache* cache, int current_line);
void fill_ifelse(Statement ifelse, Cache* cache, int if_condition_line);
void fill_unop(Statement ifelse, Cache* cache, int if_condition_line);

void fill_statement(Statement stmt, Cache* cache, int current_line){
    switch (stmt.get_stmt_type()){
    case declaration : fill_declaration(stmt, cache, current_line);
    case assignment : fill_assignment(stmt, cache, current_line);
    case ifelse : fill_ifelse(stmt, cache, current_line);
    case ifrest : cout << "error: ifelse";
    case while_loop : fill_while_block(stmt.get_block(), stmt.get_condition(), cache, current_line);
    case unop : fill_unop(stmt, cache, current_line);
    };
};

void fill_while_block(Block* block, Expression* condition, Cache* cache, int while_condition_line){
    //Block : the block of the while statement
    //while_condition_line : the number of the line while(condition)
    int n = block->get_size();
    while (condition->get_value(cache, while_condition_line)) {
        for (int i = 1; i <= n; i++) {
            fill_statement(block->get_child(while_condition_line + i), cache, while_condition_line + i);
        };
    };
};

void fill_declaration(Statement dec, Cache* cache, int declaration_line){
    Value* value = new Value;
    value->value = dec.get_expression()->get_value(cache, declaration_line);
    cache->get_map()[declaration_line][dec.get_name()]->add_value(value);
};

void fill_assignment(Statement assign, Cache* cache, int assignment_line){
    Value* value = new Value;
    value->value = assign.get_expression()->get_value(cache, assignment_line);
    cache->get_map()[assignment_line][assign.get_name()]->add_value(value);
};

void fill_ifelse(Statement ifelse, Cache* cache, int if_condition_line){
    Expression* condition = ifelse.get_condition();
    if (condition->get_value(cache, if_condition_line)){
        int n = ifelse.get_block()->get_size();
        for (int i = 1; i <= n; i++){
            fill_statement(ifelse.get_block()->get_child(i - 1), cache, if_condition_line + i);
        };
    }
    else {
        if (ifelse.get_ifrest() != nullptr) {
            int n = ifelse.get_block()->get_size();
            int m = ifelse.get_ifrest()->get_block()->get_size();
            for (int i = 1; i <= m; i++) {
                fill_statement(ifelse.get_ifrest()->get_block()->get_child(i - 1), cache, if_condition_line + n + i);
            }
        }
    }
};

void fill_unop(Statement unop, Cache* cache, int current_line){
    Value* value = new Value;
    value->value = unop.get_expression()->get_value(cache, current_line);
    cache->get_map()[current_line][unop.get_name()]->add_value(value);
}



void fill_cache(Block* ast, Cache* cache){
    int current_line = 0;
    int n = ast->get_size();
    while (current_line < n){
        //with our constraints, the first line has to be a declaration
        int next_line = current_line + ast->get_child(current_line).get_jump_length();
        fill_statement(ast->get_child(current_line), cache, current_line);
        //next_line : in case of stmts with no blocks, the line increases by only 1
        cache->get_map()[next_line] = cache->get_map()[current_line];
        current_line = next_line;
    };
};


flowchart read_statement(Statement stmt, int line_num, Cache* cache){
    //returns a flowchart corresponding to the given statement
    //this function is supposed to be used within the walker i will keep the line of the statement being read
    //(so, if stmt is in the 20th line, i = 20)
    stmt_type st_type = stmt.get_stmt_type();
    flowchart chart;
    if (st_type == declaration){
        chart.shape = rectangle;
        chart.text = "Declare " + stmt.get_child()->get_name();
        chart.color = red;
        return chart;
    }
    if(st_type == assignment){
        chart.shape = rectangle;
        chart.text = "Assign " + stmt.get_name();
        /*Value* value = new Value;
        value->value = stmt.get_child()->get_expression()->get_value(cache, line_num);
        cache->get_map()[line_num][stmt.get_child()->get_name()]->add_value(value);*/
        chart.color = red;
        return chart;
    };
    if(st_type == ifelse){
        chart.shape = diamond;
        chart.text = stmt.get_condition()->get_text();
        chart.first_block = stmt.get_block()->get_flowchart_size();
        if (stmt.get_ifrest()->get_block() == nullptr) {
            chart.second_block = 0;
        }
        else chart.second_block = 1;
        if (stmt.get_condition()->get_value(cache, line_num)) chart.color = green;
        else chart.color = red;
        return chart;
    };
    if (st_type == ifrest) {
        chart.shape = diamond;
        chart.text = "Else";
        chart.color = red;
        chart.first_block = stmt.get_block()->get_flowchart_size();
    };
    if(st_type == while_loop){
        chart.shape = diamond;
        chart.text = stmt.get_condition()->get_text();
        chart.first_block = stmt.get_block()->get_flowchart_size();
        if (stmt.get_condition()->get_value(cache, line_num)) chart.color = green;
        else chart.color = red;
        return chart;

    };
    if(st_type == unop){
        chart.shape = rectangle;
        chart.text = "Assign" + stmt.get_name();
        chart.color = red;
        return chart;
    }
    return chart;
};

flowchart l[MAX_LINES] = {};

void draw_flowchart(AST* ast, Cache* cache){
    int n = ast->get_size();
    for (int i = 0; i < n; i++){
        flowchart chart = read_statement(ast->get_child(i), i, cache);
        l[i] = chart;

    };
};
