#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <string>
#include "AST/ast.hpp"
using namespace std;

//GLOBAL VARIABLES

//Process
int const processLength  = 300;
int const processWidth = 60;

//Decision
int const squareSize = 100;

int const decisionLength = sqrt(20000);
int const decisionWidth = sqrt(20000);

int trackerIndex;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Visualize_clicked()
{
    AST* ast;
    Cache* cache;
    make_chart_list(ast, cache);

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


    for (int i = 0; i < 17; i++)
    {
        std::string str = l[i].text;

        //If we have a rectangle
        if (l[i].chart_shape == 0)
        {
            //Draw
            this->ui->widget_3->setShape(Viewer::Process);
            this->ui->widget_3->compute(X, Y, str);
            Y += processWidth;
            this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing);
            Y += spacing;
        }

        //If we have a diamond
        if (l[i].chart_shape > 0)
        {
            ifStatements = l[i].first_block;
            elseStatements = l[i].second_block; //Initialised to 0 and stays 0 in case of no else or in case of while
            numberStatements = ifStatements + elseStatements;
            //We copy all the statements contained in one decision block to pass them to the computing function

            flowchart process_l[numberStatements + 1];
            for(int j = 0; j < numberStatements+1; j++)
            {
                process_l[j] = l[i+j];
            }

            //Draw
            this->ui->widget_3->setShape(Viewer::Decision);
            //first return value of the function is the width of the block it displays (pointer type to access elements of the lay)

            int * tmp = this->ui->widget_3->compute(X, Y+20,str, process_l);
            int processBlockWidth = 0;
            processBlockWidth = tmp[0];
            Y+= processBlockWidth;

            //Adding the line (and space to Y variable) after we have drawn a block.
            if(l[i].chart_shape == 1)
            {
                this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing);
                Y+= spacing;
            }
            else if(l[i].chart_shape == 2)
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
    string words = ui->widget_5->track(index);
    QString word = QString::fromStdString(words);
    auto text = ui->widget_5->createText2(word, 210,-35,100,100);
    ui->widget_5->scene->addItem(text);
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








//test flowcharts, no need anymore
/*IF THE PROGRAM FAILS TO BUILD MAYBE CHECK THE VALUE BOUDING i
 * IT HAS TO BE THE SAME AS THE NUMBER OF STATEMENTS IN THE lAY*/

//    flowchart l[3] = {{0, "Statement 1", 0,0},
//                        {0, "Statement 2", 0,0},
//                        {0, "Statement 2", 0,0}};

//    flowchart l[3] = {{1, "If n°1", 2,0},
//                        {0, "Statement 1", 0,0},
//                        {0, "Statement 2", 0,0}};

//    flowchart l[5] = {{1, "If n°1", 2,2},
//                        {0, "Statement 1 in if", 0,0},
//                        {0, "Statement 2 in if", 0,0},
//                        {0, "Statement 1 in else", 0,0},
//                        {0, "Statement 2 in else", 0,0}};

//    flowchart l[3] = {{2, "While n°1", 2,0},
//                        {0, "Statement 1", 0,0},
//                        {0, "Statement 2", 0,0}};

//    flowchart l[6] = {{1, "If n°1", 4, 1},
//                        {0, "Statement in if n°1", 0,0},
//                        {1, "If n°2", 1, 1},
//                        {0, "Statement in if n°2", 0,0},
//                        {0, "Statement in else n°2", 0,0},
//                        {0, "Statement in else n°1", 0,0}};


//    flowchart l[9] = {{1, "If n°1", 4, 4},
//                        {0, "Statement in if n°1", 0,0},
//                        {1, "If n°2", 1, 1},
//                        {0, "Statement in if n°2", 0,0},
//                        {0, "Statement in else n°2", 0,0},
//                        {0, "Statement in else n°1", 0,0},
//                        {1, "If n°3", 1, 1},
//                        {0, "Statement in if n°3", 0,0},
//                        {0, "Statement in else n°3", 0,0}};


//    flowchart l[6] = {{2, "While n°1", 5, 0},
//                        {0, "Statement 1 in while n°1",0,0},
//                        {2, "While n°2", 2, 0},
//                        {0, "Statement 1 in while n°2", 0,0},
//                        {0, "Statement 2 in while n°2", 0,0},
//                        {0, "Statement 2 in while n°1",0,0}};

//    flowchart l[12] = {{2, "While n°1", 11, 0},
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

//    flowchart l[17] = {{1, "If n°1", 8,8},
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

//test
//flowchart l[17] = {{1, "If n°1", 8,8},
  //                   {0, "Statement 1 in if n°1", 0,0},
    //                 {2, "While n°1", 5, 0},
      //               {0, "Statement 1 in while n°1",0,0},
        //             {2, "While n°2", 2, 0},
          //           {0, "Statement 1 in while n°2", 0,0},
            //         {0, "Statement 2 in while n°2", 0,0},
              //       {0, "Statement 2 in while n°1",0,0},
                //     {0, "Statement 2 in if n°1", 0,0},
                  //   {0, "Statement 1 in else n°1", 0,0},
                    // {2, "While n°3", 5, 0},
           //          {0, "Statement 1 in while n°3",0,0},
             //        {2, "While n°4", 2, 0},
               //      {0, "Statement 1 in while n°4", 0,0},
                 //    {0, "Statement 2 in while n°4", 0,0},
                   //  {0, "Statement 2 in while n°3",0,0},
                     //{0, "Statement 2 in else n°1", 0,0}};


//test for flowchart
//enum chart_shape {
    //rectangle = 0,
    //diamond = 1,
    //circle = 2
    //};

//struct flowchart {
//    int chart_shape;
//    string text;
//    int first_block; // num of stmts in the first block (if in if and the only block in while)
//    int second_block; // num of stmts in else
//};


//flowchart one = {0, "Declare x"};
//flowchart two = {1, "If x = 1", 1};
//flowchart three = {0, "Assign x"};
//flowchart four = {1, "While x > 10", 3};


//void MainWindow::on_Visualize_clicked()
//{
//    int current_x = 300;
//    int current_y = 20;

//    this->ui->widget_3->setShape(Viewer::Start);
//    this->ui->widget_3->compute_decision(300, 20, 100, 100); //any string suffices
//    this->ui->widget_3->compute_start(300, 20, 300, 60);
//}
