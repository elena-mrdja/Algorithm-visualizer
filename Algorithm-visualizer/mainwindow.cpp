#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

    //the following comm is if u want picture in the scrollable widget
    //QImage image("path to the pciture");
    //item = new QGraphicsPixmapItem (QPixmap::fromImage(image));
    //scene = new QGraphicsScene(this); //it does make a problem with QgraphicsScene that is "not defined"?

}
