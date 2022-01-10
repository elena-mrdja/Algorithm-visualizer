#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <string>
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
     * IT HAS TO BE THE SAME AS THE NUMBER OF STATEMENTS IN THE test17AY*/
    flowchart test17[6] = {{0, "Declare i", 0,0},
                          {0, "Declare n", 0,0},
                          {0, "Declare multiplication", 0,0},
                          {2, "While i <= 10", 2,0},
                          {0, "Assign multiplication", 0,0},
                          {0, "Asign i", 0,0}};

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


    for (int i = 0; i < 6; i++)
    {
        std::string str = test17[i].text;

        //If we have a rectangle
        if (test17[i].chart_shape == 0)
        {
            //Draw
            this->ui->widget_3->setShape(Viewer::Process);
            this->ui->widget_3->compute(X, Y, str);
            Y += processWidth;
            this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing);
            Y += spacing;
        }

        //If we have a diamond
        if (test17[i].chart_shape > 0)
        {
            ifStatements = test17[i].first_block;
            elseStatements = test17[i].second_block; //Initialised to 0 and stays 0 in case of no else or in case of while
            numberStatements = ifStatements + elseStatements;
            //We copy all the statements contained in one decision block to pass them to the computing function

            flowchart process_test17[numberStatements + 1];
            for(int j = 0; j < numberStatements+1; j++)
            {
                process_test17[j] = test17[i+j];
            }

            //Draw
            this->ui->widget_3->setShape(Viewer::Decision);
            //first return value of the function is the width of the block it displays (pointer type to access elements of the test17ay)

            int * tmp = this->ui->widget_3->compute(X, Y+20,str, process_test17);
            int processBlockWidth = 0;
            processBlockWidth = tmp[0];
            Y+= processBlockWidth;

            //Adding the line (and space to Y variable) after we have drawn a block.
            if(test17[i].chart_shape == 1)
            {
                this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing);
                Y+= spacing;
            }
            else if(test17[i].chart_shape == 2)
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

    vector<vector<pair<vector<string>,vector<int>>>> list;


    pair<vector<string>,vector<int>> pair1;
    pair1.first = {"i"};
    pair1.second = {1};

    pair<vector<string>,vector<int>> pair2;
    pair2.first = {"n"};
    pair2.second = {7};



    pair<vector<string>,vector<int>> pair3;
    pair3.first = {"multiplication"};
    pair3.second = {0};

    pair<vector<string>,vector<int>> pair41;
    pair41.first = {"i"};
    pair41.second = {2,3,4,5,6,7,8,9,10,11};

    pair<vector<string>,vector<int>> pair42;
    pair42.first = {"n"};
    pair42.second = {7,14,21,28,35,42,49,56,63,70};

    pair<vector<string>,vector<int>> pair43;
    pair43.first = {"multiplication"};
    pair43.second = {7,14,21,28,35,42,49,56,63,70};


    vector<pair<vector<string>,vector<int>>> vec1;
    vec1 = {pair1};

    vector<pair<vector<string>,vector<int>>> vec2;
    vec2 = {pair1, pair2};


    vector<pair<vector<string>,vector<int>>> vec3;
    vec3 = {pair1, pair2, pair3};

    vector<pair<vector<string>,vector<int>>> vec4;
    vec4 = {pair1, pair2, pair3,pair41, pair42, pair43};

    list = {vec1, vec2, vec3, vec4};

    this->ui->widget_5->track(list, index);
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


//I mean ure doing ifs qwith ......, thats the worst thing i've ever saw
