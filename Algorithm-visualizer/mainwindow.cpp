#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QGraphicsView>


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
    this->ui->widget_3->manual_flowchart(); // but it doesn't work for some reason

    //this->ui->widget_3->setShape(Viewer::Process);
    //this->ui->widget_3->compute();
 }






//void MainWindow::draw_shape(QPaintEvent *)
//{
    //QPainter painter(this);
    //painter.setPen( Qt::green );
    //painter.setBrush( Qt::green );
  //  painter.drawRect(10, 10, 100, 100);
//}

//void MainWindow::draw()
//{
  //  update();
//}


