#ifndef VIEWER_H
#define VIEWER_H
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QtGui>
#include <QPaintEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <Qt>

QT_BEGIN_NAMESPACE
namespace Ui { class Viewer; }
QT_END_NAMESPACE

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


    //useless tho, cuz start is always the same, no need for radius nor any computation..Delete this after telling Elena
    void draw_start(const int radius); //just defined, never actually coded in .cpp


    void manual_flowchart();

    QGraphicsScene *scene;
    QGraphicsLineItem *horizontal_line;
    QGraphicsLineItem *vertical_line;
    QGraphicsRectItem *rectangle;
    QGraphicsRectItem *diamond;
    QGraphicsEllipseItem *ellipse;
    QGraphicsView *view;
    QGraphicsTextItem *text;
    QGraphicsItem *item;
    QPainter *painter;


public:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
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


protected:
    virtual void WheelEvent(QWheelEvent *event);



signals:

};

#endif // VIEWER_H
