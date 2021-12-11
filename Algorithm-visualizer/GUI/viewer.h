#ifndef VIEWER_H
#define VIEWER_H

#include "mainwindow.h"
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include <QPaintEvent>
#include <QPainter>
#include <Qt>

class Viewer : public QWidget
{
    Q_OBJECT
public:
    explicit Viewer(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    //declaring all the shapes we will use
    enum ShapeType {Vertical, Horizontal, Decision, Process, Start};

    void setBackgroundColor(QColor color){mBackgroundColor=color;} //setter function
    QColor backgroudColor() const {return mBackgroundColor; }  //getter, const function so that it doesn't modify the class variables

    void setShape(ShapeType shape){mShape=shape; on_shape_changed();} //declare rhe setter and getter fcts for shapes
    ShapeType shape() const {return mShape; }

    void setScale(float scale) {mScale=scale; repaint();}
    float scale() const {return mScale;}

    void draw_start(const int radius);

public:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    QGraphicsScene *scene;
    QGraphicsLineItem *horizontal_line;
    QGraphicsLineItem *vertical_line;
    QGraphicsRectItem *rectangle;
    QGraphicsRectItem *diamond;
    QGraphicsEllipseItem *ellipse;
    QGraphicsView *view;

    //Ui::MainWindow *ui;
    //Ui::Viewer *ui;

public:
    void compute_start();
    void compute_horizontal();
    void compute_vertical();
    void compute_decision();
    void compute_process();
    void on_shape_changed();
    void compute(); //dispatch function based on mShape type
private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;

signals:

};

#endif // VIEWER_H
