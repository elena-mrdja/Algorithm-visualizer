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

//int index;

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


void MainWindow::on_Visualize_clicked()
{
    //JOHN TRYING SOME STUFF
    const int X = 300;
    int Y = 20;
    const int spacing = 80;



    this->ui->widget_3->setShape(Viewer::Start);
    this->ui->widget_3->compute(X, Y); //any string suffices
    Y += processWidth + spacing;


    //create a list of structs
//    flowchart arr[8] = {{0, "Declare x", 0, 0},
//                        {1, "If x > 1", 4, 0},
//                        {0, "Assign z", 0,0},
//                        {1, "If x >2", 2,0},
//                        {1, "If x < 4", 1, 0},
//                        {0, "Assign x", 0, 0},
//                        {0, "Assign y", 0, 0},
//                        {0, "Assign LAST",0,0}};



//    flowchart arr[8] = {
//                        {1, "If x > 1", 7, 0},
//                        {1, "If x >3", 5,0},
//                        {0, "Assign ghj", 0,0},
//                        {1, "If x < 2", 3,0},
//                        {0, "Declar dfghj", 0,0},
//                        {1, "If x > 3", 1,0},
//                        {0, "Assign y", 0,0},
//                        {0, "Declare x", 0, 0}};

//    flowchart arr[5] = {{1, "If x < 2", 3,0},
///*                        {1, "If x hshs,", 2,0},*/
////                        {0, "Assign x", 0,0},
//                         {1, "If y", 1,0},
//                         {0, "Assign hahaha", 0,0},
//                        {0, "ASSIGN LAST", 0,0}};


//    flowchart arr[6] = {{1, "If x >1", 4, 0},
//                        {2, "While jsp", 2, 0},
//                        {0, "ASSIGN while", 0, 0},
//                        {0, "ASSIGN while 2", 0,0},
//                        {0, "ASSIGN if 1", 0,0},
//                        {0, "ASSIGN nothing", 0,0}
//                       };


//    flowchart arr[8] = {{2, "While somth", 4, 0},
//                        {2, "While smth else", 3, 0},
////                        {2, "While False", 2, 0},
//                        {2, "While True", 1, 0},
//                        {0, "Assign HAHAHAH", 0,0},
//                        {0, "Declare lol", 0,0},
//                        {0, "TEST",0,0},
//                        {0, "END TEST", 0,0}
//                       };


//    flowchart arr[4] = {{2, "While A", 3,0},
//                    {2, "While B", 1, 0},
//                    {0, "ASSIGN in B", 0,0},
//                    {0, "ASSIGN in A", 0,0}};

//    flowchart arr[5] = {{2, "While", 4, 0},
//                       {1, "If 1", 2, 0},
//                       {1,"If 2", 1,0},
//                       {0, "STATEMENT 1", 0,0},
//                       {0, "STATEMENT 2", 0,0}};
//    flowchart arr[3] = {{0, "STATEMENT 1", 0, 0},
//                        {0, "STATEMENT 2", 0,0},
//                        {0, "STATEMENT 3", 0, 0}};


    /*THIS FLOWCHART DOESNT WORK */
//    flowchart arr[6] = {{1, "If 1", 1,1},
//                        {1, "If 2", 1,1},
//                        {0, "STATEMENT IF 2", 0,0},
//                        {0, "STATEMENT ELSE 2", 0,0},
//                        {0, "STATEMENT ELSE 1", 0,0}
//                       };

    flowchart arr[3] = {{1, "If 1", 1,1},
                        {0, "STATEMENT IF 1", 0,0},
                        {0, "STATEMENT ELSE 1", 0,0}

    };


//    flowchart arr[12] = {{2, "While 1", 10, 0},
//                         {1, "If 1", 7, 0},
//                         {1, "If 2", 6,0},
//                         {2, "While 2", 2, 0},
//                         {2, "While 3", 1, 0},
//                         {0, "STATEMENT 1", 0,0},
//                         {1, "If 3", 1, 0},
//                         {0, "STATEMENT 2", 0,0},
//                         {0, "STATEMENT 3", 0,0},
//                         {2, "While 4", 1, 0},
//                         {0, "STATEMENT 4",0,0},
//                         {0, "FINAL STATEMENT", 0,0}};


    /*IF THE PROGRAM FAILS TO BUILD MAYBE CHECK THE VALUE BOUDING i
     * IT HAS TO BE THE SAME AS THE NUMBER OF STATEMENTS IN THE ARRAY*/

    int numberStatements = 0; // counter for num of statements in block
    int elseStatements = 0;
    for (int i = 0; i < 3; i++) {
        std::string str = arr[i].text;
        std::cout << "Y = "<< Y << std::endl;

        //if we have a rectangle
        if (arr[i].chart_shape == 0) {
            //draw
            this->ui->widget_3->setShape(Viewer::Process);
            this->ui->widget_3->compute(X, Y, str);
            Y += processWidth;
            this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing);
            Y += spacing;
        }

        //if we have a diamond

        if (arr[i].chart_shape > 0) {
            //Y += spacing;
            elseStatements = arr[i].second_block;
            numberStatements = arr[i].first_block + elseStatements;
            std::cout << "Number of statements:" << numberStatements << std::endl;
            flowchart process_arr[numberStatements+1];

            for (int j = 0;j<numberStatements+1 ;j++ ) {
                if (elseStatements > 0)
                {
                    std::cout << "WE HAVE AND ELSE"<< std::endl;
                    process_arr[j] = arr[j];

                }
                else
                {
                    process_arr[j] = arr[i+j];
                }
            }

            //draw
            this->ui->widget_3->setShape(Viewer::Decision);
            std::cout << "Iteration i=" << i << "Y = " << Y << "Y-40 = " << Y-40 << std::endl;
            int * tmp = this->ui->widget_3->compute(X, Y+20,str, process_arr);
            int ifBlockWidth = tmp[0] -processWidth/2;
            std::cout << "MAIN WINDOW BLOCK WIDTH: " << ifBlockWidth;
            Y+= ifBlockWidth;
            this->ui->widget_3->compute_vertical(X+processLength/2, Y, spacing);
            Y+= spacing;
            i += numberStatements;
            std::cout << i;

        }
    }
    //draw end
    this->ui->widget_3->setShape(Viewer::End);
    this->ui->widget_3->compute(X, Y+500);
}


    //this->ui->widget_3->setShape(Viewer::Start);
    //this->ui->widget_3->compute(300, 20, 300, 60);

    //for (int i = 1; i < 10; i++) {
      //  this->ui->widget_3->compute(300, 20 + i*80, 300, 60);
    //}
    //this->ui->widget_3->setShape(Viewer::Decision);
    //this->ui->widget_3->compute(300, 20, 300, 60);
    //this->ui->widget_4->readIn();
//}


void MainWindow::on_variables_clicked(){}
//{
//    vector<char> order;
//    vector<unordered_map<char, vector<double>>::iterator> vec;

//    unordered_map<char, vector<double>> mapa;
//    mapa['z'].push_back(4);
//    mapa['z'].push_back(5);
//    mapa['x'].push_back(1);
//    mapa['y'].push_back(2);
//    mapa['y'].push_back(3);
//    order.push_back('z');
//    order.push_back('x');
//    order.push_back('y');

//    unordered_map<char, vector<double>> mapa1;
//    mapa1['a'].push_back(4);
//    mapa1['z'].push_back(5.98);
//    mapa1['b'].push_back(11);
//    mapa1['b'].push_back(24);
//    mapa1['b'].push_back(32);


//    vector<unordered_map<char, vector<double>>> ve;
//    ve.push_back(mapa);
//    ve.push_back(mapa1);

//    for(unordered_map<char, vector<double>>::iterator it=mapa.begin();it!=mapa.end();it++)
//    {
//        vec.push_back(it);
//    }

//    if (index == ve.size())
//    {
//        index = 1;
//    }
//    else
//    {
//        index++;
//    }

//    this->ui->widget_4->writeOut(QString("Btn"));
//    this->ui->widget_5->track(ve, index);
//    //this->ui->widget_5->track2(vec);
//}



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

