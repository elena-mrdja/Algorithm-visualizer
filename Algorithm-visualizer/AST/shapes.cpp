#include "shapes.hpp"
#include "ast_classes.hpp"

//function that creates struct for a flowchart for each statement
flowchart read_statement(Statement* stmt, int i, list<map<Variable*, ValuesList*>*>* variables){
    //returns a flowchart corresponding to the given statement
    //this function is supposed to be used within the walker i will keep the line of the statement being read
    //(so, if stmt is in the 20th line, i = 20)
    subtypes stmt_type = stmt->get_subtype();
    flowchart chart;
    if (stmt_type == declaration){
        chart.shape = rectangle;
        chart.text = "Declare " + stmt->get_variable()->get_name();
        Value var;
        var.value = stmt->get_variable()->get_value();
        //variables[i][stmt->get_variable()].add_value(var);
        return chart;
    }
    if(stmt_type == assignment){
        chart.shape = rectangle;
        chart.text = "Assign " + stmt->get_name();
        return chart;
    };
    if(stmt_type == ifelse){
        chart.shape = diamond;
        chart.text = stmt->get_condition()->get_text();
        chart.first_block = stmt->block_stmt->num_statements();
        chart.second_block = stmt->else_stmt->num_stmt;
        return chart;
    };
    if(stmt_type == while_loop){
        chart.shape = diamond;
        chart.text = stmt->get_condition()->get_text();
        chart.first_block = stmt->block_stmt->num_statements();
        return chart;
    };
    return chart;
};

//function that need to be completed by GUI (for each statement, read it, create a struct and then use it for drawing)
void draw_flowchart(Block* block){
    int n = block->num_statements();
    list<map<Variable*, ValuesList*>*>* variables = new list<map<Variable*, ValuesList*>*>[n];
    //this list has to be initialized to have pointers to maps for each line
    list<Statement*>::iterator i;
    int j = 1;
    for (i = block->get_statements()->begin(); i != block->get_statements()->end();i++){
        flowchart chart = read_statement(*i, j, variables);
        j++;
    };
};
