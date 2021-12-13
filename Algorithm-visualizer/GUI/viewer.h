#ifndef VIEWER_H
#define VIEWER_H

#include "mainwindow.h"
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include <QPaintEvent>
#include <QGraphicsItem>
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

    void manual_flowchart();
    void set_background();

public:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    QGraphicsScene *scene;
    QGraphicsLineItem *horizontal_line;
    QGraphicsLineItem *vertical_line;
    QGraphicsRectItem *rectangle;
    QGraphicsRectItem *diamond;
    QGraphicsEllipseItem *ellipse;
    QGraphicsView *view;
    QGraphicsItem *item;
    QPainter *painter;
    QGraphicsTextItem *text;

    //Ui::MainWindow *ui;
    //Ui::Viewer *ui;


    void compute_start(double x, double y, double l, double w);
    void compute_horizontal(double x, double y, double l, double w);
    void compute_vertical(double x, double y, double l, double w);
    void compute_decision(double x, double y, double l, double w);
    void compute_process(double x, double y, double l, double w);
    void on_shape_changed();
    void compute(double x, double y, double l , double w); //dispatch function based on mShape type

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;


protected:
    virtual void WheelEvent(QWheelEvent *event);
    QGraphicsSimpleTextItem* createText(QString str, int x, int y, int w, int l);

signals:

};

#endif // VIEWER_H
