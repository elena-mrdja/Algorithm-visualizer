#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>

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
    this->ui->widget_3->setShape(Viewer::Start);
    //for (int i = 1; i < 10; i++) {
      //  this->ui->widget_3->compute(300, 20 + i*80, 300, 60);
    //}
    this->ui->widget_3->setShape(Viewer::Decision);
    this->ui->widget_3->compute(300, 20, 300, 60);
    this->ui->widget_4->readIn();
}

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

