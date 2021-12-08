#include "viewer.h"
#include "math.h"
#include "mainwindow.h"
#include <QPaintEvent>
#include <QPainter>
#include <QGraphicsItem>

Viewer::Viewer(QWidget *parent) : QWidget(parent), mBackgroundColor(0,0,255),mShapeColor(255,255,255),mShape(Process)
{
    scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);
    on_shape_changed();
}

QSize Viewer::minimumSizeHint() const
{
    return QSize(100,100);
}
QSize Viewer::sizeHint() const
{
    return QSize(400,200);
}

void Viewer::on_shape_changed()
{
    switch (mShape) {
        case Horizontal:
            mScale =50;
            mIntervalLength = 2*M_PI;
            mStepCount = 128;
            mBackgroundColor = Qt::blue;
            break;

        case Vertical:
            mScale =50;
            mIntervalLength = 1;
            mStepCount = 128;
            mBackgroundColor = Qt::blue;
            break;

        case Process:
            mScale =4;
            mIntervalLength = 4*M_PI;
            mStepCount = 256;
            mBackgroundColor = Qt::blue;
            break;

        case Decision:
            mScale =40;
            mIntervalLength = 2*M_PI;
            mStepCount = 256;
            mBackgroundColor = Qt::blue;
            break;

        default:
          break;
        }
}

void Viewer::compute(float t)
{
    switch (mShape) {
        case Horizontal:
        return compute_horizontal(t);
            break;

        case Vertical:
            //mBackgroundColor = Qt::green;
            return compute_vertical(t);
            break;

        case Process:
            //mBackgroundColor = Qt::blue;
            return compute_process(t);
            break;

        case Decision:
            //mBackgroundColor = Qt::yellow;
            return compute_decision(t);
            break;

        default:
          break;
        }
}

void Viewer::compute_vertical(float t)
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    scene ->addItem(vertical_line);
}

void Viewer::compute_horizontal(float t)
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    scene ->addItem(horizontal_line);
}

void Viewer::compute_decision(float t)
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    scene ->addItem(rectangle);
}

void Viewer::compute_process(float t)
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    diamond->setRotation(180);
    scene ->addItem(diamond);
}

/*void Viewer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();

    compute(0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x()*mScale + center.x());
    prevPixel.setY(prevPoint.y()*mScale + center.y());

    float step = mIntervalLength/mStepCount;
    for(float t=0; t< mIntervalLength; t+=step){
         //compute(t);

        QPoint pixel;
        pixel.setX(point.x()*mScale + center.x());
        pixel.setY(point.y()*mScale + center.y());

        painter.drawLine(pixel,prevPixel);
        prevPixel =pixel;
    }
}
*/

