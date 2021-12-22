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


void MainWindow::on_Visualize_clicked()
{
    int current_x = 300;
    int current_y = 20;

    this->ui->widget_3->setShape(Viewer::Start);
    this->ui->widget_3->compute(current_x, current_y, 300, 60); //any string suffices


    //create a list of structs
    flowchart arr[4] = {{0, "Declare x", 0, 0},
                        {1, "If x = 1", 1, 0},
                        {0, "Assign x", 0, 0},
                        {1, "While x > 10", 3, 0}};

    int c = 0; // counter for num of statements in block

    for (int i = 0; i < 4; i++) {
        //if we have a rectangle
        if (arr[i].chart_shape == 0) {

            //fix x coord
            if (c > 0) {current_x = 460; c --;}
            else {current_x = 300;}

            //fix y coord
            if (arr[i-1].chart_shape == 1){current_y += 125;}
            if (arr[i-1].chart_shape == 0){current_y += 80;}

            //draw
            this->ui->widget_3->setShape(Viewer::Process);
            this->ui->widget_3->compute(current_x, current_y, 300, 60);
        }

        //if we have a diamond
        if (arr[i].chart_shape == 1) {
            current_x = 350;
            c = arr[i].first_block; //will be used for indentation

            //set y
            if (arr[i-1].chart_shape == 1){current_y += 125;}
            if (arr[i-1].chart_shape == 0){current_y += 80;}

            //draw
            this->ui->widget_3->setShape(Viewer::Decision);
            this->ui->widget_3->compute(current_x, current_y, 300, 60);
        }
    }

    //fix x and y
    if(arr[-1].chart_shape == 0) {current_y += 80;}
    else {current_y += 125;}
    current_x = 300;

    //draw end
    this->ui->widget_3->setShape(Viewer::End);
    this->ui->widget_3->compute(current_x, current_y, 300, 60);
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
    this->ui->widget_4->writeOut(QString("Btn"));
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

