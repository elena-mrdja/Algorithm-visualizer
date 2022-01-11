#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <string>
#include<GUI/test_vartrack.hpp>
using namespace std;

//GLOBAL VARIABLES

//Process
int const processLength  = 300;
int const processWidth = 60;

//Decision
int const squareSize = 100;

int const decisionLength = sqrt(20000);
int const decisionWidth = sqrt(20000);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    index = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//test for flowchart
enum chart_shape {
    rectangle = 0,
    diamond = 1,
    circle = 2
    };

//struct flowchart {
//    int chart_shape;
//    string text;
//    int first_block; // num of stmts in the first block (if in if and the only block in while)
//    int second_block; // num of stmts in else
//};




//void MainWindow::on_Visualize_clicked()
//{
//    int current_x = 300;
//    int current_y = 20;

//    this->ui->widget_3->setShape(Viewer::Start);
//    this->ui->widget_3->compute_decision(300, 20, 100, 100); //any string suffices
//    this->ui->widget_3->compute_start(300, 20, 300, 60);
//}


void MainWindow::on_Visualize_clicked()
{
    /*IF THE PROGRAM FAILS TO BUILD MAYBE CHECK THE VALUE BOUDING i
<<<<<<< HEAD
     * IT HAS TO BE THE SAME AS THE NUMBER OF STATEMENTS IN THE test18AY*/

//    flowchart arr[3] = {{0, "Statement 1", 0,0},
//                        {0, "Statement 2", 0,0},
//                        {0, "Statement 2", 0,0}};

//    flowchart arr[3] = {{1, "If n°1", 2,0},
//                        {0, "Statement 1", 0,0},
//                        {0, "Statement 2", 0,0}};

//    flowchart arr[5] = {{1, "If n°1", 2,2},
//                        {0, "Statement 1 in if", 0,0},
//                        {0, "Statement 2 in if", 0,0},
//                        {0, "Statement 1 in else", 0,0},
//                        {0, "Statement 2 in else", 0,0}};

//    flowchart arr[3] = {{2, "While n°1", 2,0},
//                        {0, "Statement 1", 0,0},
//                        {0, "Statement 2", 0,0}};

//    flowchart arr[6] = {{1, "If n°1", 4, 1},
//                        {0, "Statement in if n°1", 0,0},
//                        {1, "If n°2", 1, 1},
//                        {0, "Statement in if n°2", 0,0},
//                        {0, "Statement in else n°2", 0,0},
//                        {0, "Statement in else n°1", 0,0}};


//    flowchart arr[9] = {{1, "If n°1", 4, 4},
//                        {0, "Statement in if n°1", 0,0},
//                        {1, "If n°2", 1, 1},
//                        {0, "Statement in if n°2", 0,0},
//                        {0, "Statement in else n°2", 0,0},
//                        {0, "Statement in else n°1", 0,0},
//                        {1, "If n°3", 1, 1},
//                        {0, "Statement in if n°3", 0,0},
//                        {0, "Statement in else n°3", 0,0}};


//    flowchart arr[6] = {{2, "While n°1", 5, 0},
//                        {0, "Statement 1 in while n°1",0,0},
//                        {2, "While n°2", 2, 0},
//                        {0, "Statement 1 in while n°2", 0,0},
//                        {0, "Statement 2 in while n°2", 0,0},
//                        {0, "Statement 2 in while n°1",0,0}};

//    flowchart arr[12] = {{2, "While n°1", 11, 0},
//                         {0, "Statement 1 in while n°1", 0,0},
//                         {1, "If n°1", 4, 4},
//                         {0, "Statement in if n°1", 0,0},
//                         {1, "If n°2", 1, 1},
//                         {0, "Statement in if n°2", 0,0},
//                         {0, "Statement in else n°2", 0,0},
//                         {0, "Statement in else n°1", 0,0},
//                         {1, "If n°3", 1, 1},
//                         {0, "Statement in if n°3", 0,0},
//                         {0, "Statement in else n°3", 0,0},
//                         {0, "Statement 2 in while n°1", 0,0}};

//    flowchart arr[17] = {{1, "If n°1", 8,8},
//                         {0, "Statement 1 in if n°1", 0,0},
//                         {2, "While n°1", 5, 0},
//                         {0, "Statement 1 in while n°1",0,0},
//                         {1, "If n°2", 1, 1},
//                         {0, "Statement 1 in if n°2", 0,0},
//                         {0, "Statement 2 in else n°2", 0,0},
//                         {0, "Statement 2 in while n°1",0,0},
//                         {0, "Statement 2 in if n°1", 0,0},
//                         {0, "Statement 1 in else n°1", 0,0},
//                         {2, "While n°2", 5, 0},
//                         {0, "Statement 1 in while n°2",0,0},
//                         {1, "If n°2", 1, 1},
//                         {0, "Statement 1 in if n°2", 0,0},
//                         {0, "Statement 2 in else n°2", 0,0},
//                         {0, "Statement 2 in while n°2",0,0},
//                         {0, "Statement 2 in else n°1", 0,0}};

    flowchart arr[17] = {{1, "If n°1", 8,8},
                         {0, "Statement 1 in if n°1", 0,0},
                         {2, "While n°1", 5, 0},
                         {0, "Statement 1 in while n°1",0,0},
                         {2, "While n°2", 2, 0},
                         {0, "Statement 1 in while n°2", 0,0},
                         {0, "Statement 2 in while n°2", 0,0},
                         {0, "Statement 2 in while n°1",0,0},
                         {0, "Statement 2 in if n°1", 0,0},
                         {0, "Statement 1 in else n°1", 0,0},
                         {2, "While n°3", 5, 0},
                         {0, "Statement 1 in while n°3",0,0},
                         {2, "While n°4", 2, 0},
                         {0, "Statement 1 in while n°4", 0,0},
                         {0, "Statement 2 in while n°4", 0,0},
                         {0, "Statement 2 in while n°3",0,0},
                         {0, "Statement 2 in else n°1", 0,0}};


//    flowchart arr[7] = {{1, "If", 2, 4},
//                      {0, "S", 0,0},
//                       {0, "S", 0,0},
//                       {0, "S", 0,0},
//                       {0, "S", 0,0},
//                       {0, "S", 0,0},
//                       {0,"S",0,0}};

     /* IT HAS TO BE THE SAME AS THE NUMBER OF STATEMENTS IN THE test17AY*/
    flowchart test17[6] = {{0, "Declare i", 0,0},
                          {0, "Declare n", 0,0},
                          {0, "Declare multiplication", 0,0},
                          {2, "While i <= 10", 2,0},
                          {0, "Assign multiplication", 0,0},
                          {0, "Asign i", 0,0}};

    flowchart test14[6] = {{0, "Declare a", 0,0},
                          {0, "Declare b", 0,0},
                          {2, "While a != b", 4,0},
                          {1, "If a > b", 1,1},
                          {0, "Asign a", 0,0},
                          {0, "Asign b", 0,0}};

    flowchart test15[9] = {{0, "Declare n", 0,0},
                          {0, "Declare i", 0,0},
                          {0, "Declare prime", 0,0},
                          {1, "If a > b", 1,4},
                          {0, "Asign prime", 0,0},
                          {2, "While a != b", 2,0},
                          {1, "If a > b", 1,0},
                          {0, "Asign prime", 0,0},
                          {0, "Asign i", 0,0}};

    flowchart test18[6] = {{0, "Declare x", 0,0},
                          {0, "Declare n", 0,0},
                          {0, "Declare result", 0,0},
                          {2, "While a != b", 2,0},
                          {0, "Assign result", 1,0},
                          {0, "Asign n", 0,0}};

    flowchart test19[4] = {{2, "While a != b", 3,0},
                                                     {1, "If a > b", 2,0},
                           {0, "lal", 0,0},
                                                     {0, "Asign prime", 0,0}};

    const int X = 300;
    int Y = 20;
    const int spacing = 80;

    int numberStatements = 0; // counter for num of statements in block
    //Specific counters for if and else blocks
    int ifStatements = 0;
    int elseStatements = 0;

    //Drawing the start shape
    this->ui->widget_3->setShape(Viewer::Start);
    this->ui->widget_3->compute(X, Y);
    Y += processWidth + spacing;


    for (int i = 0; i < 9; i++)
    {
        std::string str = test15[i].text;

        //If we have a rectangle
        if (test15[i].chart_shape == 0)
        {
            //Draw
            this->ui->widget_3->setShape(Viewer::Process);
            this->ui->widget_3->compute(X, Y, str);
            Y += processWidth;
            this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing);
            Y += spacing;
        }

        //If we have a diamond
        if (test15[i].chart_shape > 0)
        {
            ifStatements = test15[i].first_block;
            elseStatements = test15[i].second_block; //Initialised to 0 and stays 0 in case of no else or in case of while
            numberStatements = ifStatements + elseStatements;
            //We copy all the statements contained in one decision block to pass them to the computing function

            flowchart process_test19[numberStatements + 1];
            for(int j = 0; j < numberStatements+1; j++)
            {
                process_test19[j] = test15[i+j];
            }

            //Draw
            this->ui->widget_3->setShape(Viewer::Decision);
            //first return value of the function is the width of the block it displays (pointer type to access elements of the test17ay)

            int * tmp = this->ui->widget_3->compute(X, Y+20,str, process_test19);
            int processBlockWidth = 0;
            processBlockWidth = tmp[0];
            Y+= processBlockWidth;

            //Adding the line (and space to Y variable) after we have drawn a block.
            if(test15[i].chart_shape == 1)
            {   Y -= 20;
                this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing);
                Y+= spacing;
            }
            else if(test15[i].chart_shape == 2)
            {


                this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing/2);
                Y+= spacing/2;
            }

            i += numberStatements; // Needed to skip over the statements that were drawn in the block

        }
    }
    //Draw end
    this->ui->widget_3->setShape(Viewer::End);
    this->ui->widget_3->compute(X, Y);
}


void MainWindow::on_variables_clicked()
{
    this->ui->widget_5->track(test15(), index);
    index ++;
}





void MainWindow::on_Done_clicked()
{
    this->ui->widget_4->writeOut(QString("Btn"));
}


void MainWindow::on_Upload_clicked()
{
    this->ui->widget_4->readIn();
}




//void MainWindow::draw_shape(QPaintEvent *)
//{
    //QPainter painter(this);
    //painter.setPen( Qt::green );
    //painter.setBrush( Qt::green );
  //  painter.drawRect(10, 10, 100, 100);
//}

//void MainWindow::draw()
//{ §
  //  update();
//}


void MainWindow::on_pushButton_clicked()
{
    this->ui->widget_3->view->scale(0.7, 0.7);
}


void MainWindow::on_pushButton_2_clicked()
{
    this->ui->widget_3->view->scale(1.4, 1.4);
}


void MainWindow::on_zoomIn_clicked()
{

}

void MainWindow::on_zoomOut_clicked(){}

