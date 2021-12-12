#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene *scene;
    QGraphicsView *view;


public slots:
    void on_Visualize_clicked();



private:
    Ui::MainWindow *ui;
    //QGraphicsScene *scene;
    QGraphicsLineItem *horizontal_line;
    QGraphicsLineItem *vertical_line;
    QGraphicsRectItem *rectangle;
    QGraphicsRectItem *diamond;
    QGraphicsEllipseItem *ellipse;
    //QGraphicsView *view;
    QGraphicsTextItem *text;

};



#endif // MAINWINDOW_H






