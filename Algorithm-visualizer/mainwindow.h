#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//protected:
    Ui::MainWindow *ui;
//    QGraphicsScene *scene;
//    QGraphicsLineItem *line;
//    QGraphicsRectItem *rectangle;
//    QBrush redbrush(Qt::red);
//    QPen blackpen(Qt::black);

};
#endif // MAINWINDOW_H
