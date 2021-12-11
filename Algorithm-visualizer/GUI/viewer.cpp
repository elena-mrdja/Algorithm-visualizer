#include "viewer.h"
#include "math.h"
#include <QPaintEvent>
#include <QPainter>


Viewer::Viewer(QWidget *parent) : QWidget(parent), mBackgroundColor(0,0,255),mShapeColor(255,255,255),mShape(Process)
{
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

void Viewer::compute()
{
    switch (mShape) {
        case Horizontal:
        return compute_horizontal();
            break;

        case Vertical:
            //mBackgroundColor = Qt::green;
            return compute_vertical();
            break;

        case Start:
            return compute_start();
                break;

        case Process:
            //mBackgroundColor = Qt::blue;
            return compute_process();
            break;

        case Decision:
            //mBackgroundColor = Qt::yellow;
            return compute_decision();
            break;

        default:
          break;
        }
}

void Viewer::compute_vertical()
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    vertical_line = scene ->addLine(10,10,100,100);
}


void Viewer::compute_horizontal()
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    horizontal_line = scene ->addLine(10,10,100,100);
}

void Viewer::compute_start()
{
    /*float cos_t = cos(t);
    float sin_t = sin(t);
    float x = cos_t;
    float y = sin_t;
    return QPointF(x,y);*/
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    ellipse = scene ->addEllipse(10,10,100,100);
}


void Viewer::compute_decision()
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    diamond = scene ->addRect(0,0,100,100);
    //diamond -> setRotation(180);
}

void Viewer::compute_process()
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    rectangle = scene ->addRect(20,20,100,100, blackpen, redbrush);
}

void Viewer::paintEvent(QPaintEvent *event) //draw function
{
    QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing,true);

    painter.setBrush(mBackgroundColor); // blue backgroundh
    //painter.setPen(mShapeColor);
    painter.drawRect(this->rect()); // white line around

    QPoint center = this->rect().center();

    //parametrization of the diamond shape (quesiton for Elena: jel si ovo sve sa tutorijala uzela ili si samakucala? neke stvari ne razumem)
    //QPointF prevPoint = compute(0);
    //QPoint prevPixel;
    //prevPixel.setX(prevPoint.x()*mScale + center.x());
    //prevPixel.setY(prevPoint.y()*mScale + center.y());

    //float step = mIntervalLength/mStepCount;
    //for(float t=0; t< mIntervalLength; t+=step){
        //QPointF point = compute_start(t);

        //QPoint pixel;
        //pixel.setX(point.x()*mScale + center.x());
        //pixel.setY(point.y()*mScale + center.y());

        //painter.drawLine(pixel,prevPixel);
        //prevPixel =pixel;
    //}
}
