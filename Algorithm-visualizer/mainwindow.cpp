#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem> //for scrollable widgets
#include <QGraphicsScene> //for scrollable widgets
#include <QtGui> //for scrollable widgets
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow ui;


    //this can be added for including a photo in varcell scrollable
    //QGraphicsItem *item;
    //QGraphicsScene *scene;
    //ui->graphicsView->setScene(scene);
    //scene->addItem(item);

