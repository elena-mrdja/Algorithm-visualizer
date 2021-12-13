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
    this->ui->widget_3->setShape(Viewer::Process);
    this->ui->widget_3->compute(300, 20, 300, 60);
    this->ui->widget_4->readIn();
}

void MainWindow::on_variables_clicked()
{
    this->ui->widget_4->writeOut(QString("Btn"));
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

