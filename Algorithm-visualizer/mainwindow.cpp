#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

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





// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QGraphicsItem> //for scrollable widgets
// #include <QGraphicsScene> //for scrollable widgets
// #include <QtGui> //for scrollable widgets
// #include "ui_mainwindow.h"

// QT_BEGIN_NAMESPACE
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Ui::MainWindow ui;


//     //this can be added for including a photo in varcell scrollable
//     //QGraphicsItem *item;
//     //QGraphicsScene *scene;
//     //ui->graphicsView->setScene(scene);
//     //scene->addItem(item);

/* John : I commented the file because it seemed like a maniuplation mistake turned it into the header file for the class
MainWindow, below is the old version of the mainwindow.cpp (with class implementation rather than declaration) */

//#include "mainwindow.h"
//#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}


 //the following comm is if u want picture in the scrollable widget
    //QImage image("path to the pciture");
    //item = new QGraphicsPixmapItem (QPixmap::fromImage(image));
    //scene = new QGraphicsScene(this); //it does make a problem with QgraphicsScene that is "not defined"?




