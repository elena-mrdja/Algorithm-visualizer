#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <string>
using namespace std;

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

struct flowchart {
    int chart_shape;
    string text;
    int first_block; // num of stmts in the first block (if in if and the only block in while)
    int second_block; // num of stmts in else
};


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
    const int L = 300;
    const int W = 60;
    const int spacing = 40;
    int indentation = 220;
    int nbIndents = 0;


    this->ui->widget_3->setShape(Viewer::Start);
    this->ui->widget_3->compute(X, Y, L, W); //any string suffices
    Y += W + spacing;


    //create a list of structs
    flowchart arr[8] = {{0, "Declare x", 0, 0},
                        {1, "If x > 1", 2, 0},
                        {0, "Assign x", 0,0},
                        {0, "Assign x", 0,0},
                        {2, "While x >1",2,0}};
//                        {0, "Assign x", 0, 0},
//                        {0, "Assign x", 1, 0},
//                        {0, "Assign y", 0, 0}};

    int c = 0; // counter for num of statements in block

    for (int i = 0; i < 8; i++) {
        std::string str = arr[i].text;
        if (c > 0) {nbIndents += 1; c --;}
        //if we have a rectangle
        if (arr[i].chart_shape == 0) {

            //indentation
            if (arr[i-1].chart_shape == 2){
                Y += spacing;
            }
            //draw
            this->ui->widget_3->setShape(Viewer::Process);
            this->ui->widget_3->compute(X + nbIndents * indentation, Y, L, W, str);
            if(nbIndents == 0){this->ui->widget_3->compute_vertical(X+L/2, Y+W,X+L/2, Y+W+spacing);}
            //if (nbIndents > 0) {nbIndents --;}
        }

        //if we have a diamond
        if (arr[i].chart_shape > 0) {
            Y += spacing;
            if(arr[i].chart_shape == 1){
                c = arr[i].first_block; //will be used for indentation
            }

            //draw
            this->ui->widget_3->setShape(Viewer::Decision);
            this->ui->widget_3->compute(X+ nbIndents * indentation, Y, L, W, str);
        }
        Y += W + spacing;
        if (nbIndents > 0) {nbIndents --;}
    }
    //draw end
    this->ui->widget_3->setShape(Viewer::End);
    this->ui->widget_3->compute(X, Y, L, W);
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


void MainWindow::on_variables_clicked()
{
    vector<char> order;
    vector<unordered_map<char, vector<double>>::iterator> vec;

    unordered_map<char, vector<double>> mapa;
    mapa['z'].push_back(4);
    mapa['z'].push_back(5);
    mapa['x'].push_back(1);
    mapa['y'].push_back(2);
    mapa['y'].push_back(3);
    order.push_back('z');
    order.push_back('x');
    order.push_back('y');

    for(unordered_map<char, vector<double>>::iterator it=mapa.begin();it!=mapa.end();it++)
    {
        vec.push_back(it);
    }

    this->ui->widget_4->writeOut(QString("Btn"));
    this->ui->widget_5->track(mapa, order, 3);
    //this->ui->widget_5->track2(vec);
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

