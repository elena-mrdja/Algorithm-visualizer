#include "ast_classes.hpp"

flowchart read_statement(Statement* stmt, int i, map<Variable*, ValuesList*>* variables[], int n){
    //stmt: statement to read, i: the line which this statement is in, variables: the cache for tracking, n: lenght variables
    //returns a flowchart corresponding to the given statement
    //this function is supposed to be used within the walker i will keep the line of the statement being read
    //(so, if stmt is in the 20th line, i = 20)
    subtypes stmt_type = stmt->get_subtype();
    flowchart chart;
    if (stmt_type == declaration){
        chart.shape = rectangle;
        chart.text = "Declare " + stmt->get_variable()->get_name();
        Value* var;
        var->value = stmt->get_variable()->get_value();
        for (int j = i; j < n; j++){
            variables[i][i][stmt->get_variable()]->add_value(var);
        }
        return chart;
    }
    if(stmt_type == assignment){
        chart.shape = rectangle;
        chart.text = "Assign " + stmt->get_variable()->get_name();
        Value* var;
        var->value = stmt->get_assign_value();
        ValuesList* var_list;
        var_list->add_value(var);
        variables[i][i][stmt->get_variable()] = var_list;
        return chart;
    }
    return chart;
};

void draw_flowchart(Block* block){
    int n = block->num_statements();
    map<Variable*, ValuesList*>* variables[n];
    //this list has to be initialized to have pointers to maps for each line
    list<Statement*>::iterator i;
    int j = 1;
    for (i = block->get_statements()->begin(); i != block->get_statements()->end();i++){
        flowchart chart = read_statement(*i, j, variables, n);
        j++;
    };
};
