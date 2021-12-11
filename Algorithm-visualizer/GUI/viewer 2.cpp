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
        case Arrow:
            mScale =50;
            mIntervalLength = 2*M_PI;
            mStepCount = 128;
            mBackgroundColor = Qt::blue;
            break;

        case UnitLine:
            mScale =50;
            mIntervalLength = 1;
            mStepCount = 128;
            mBackgroundColor = Qt::green;
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

        case Start:
            mScale = 40;
            mIntervalLength = 2*M_PI;
            mStepCount = 256;
            mBackgroundColor = Qt::white;
            break;


        default:
          break;
        }
}

QPointF Viewer::compute(float t)
{
    switch (mShape) {
        case Arrow:
        return compute_arrow(t);
            break;

        case UnitLine:
            //mBackgroundColor = Qt::green;
            return compute_unitline(t);
            break;

        case Process:
            //mBackgroundColor = Qt::blue;
            return compute_process(t);
            break;

        case Decision:
            //mBackgroundColor = Qt::yellow;
            return compute_decision(t);
            break;

        case Start:
            //mBackgroundCOlor = Qt::white;
            return compute_start(t);
            break;


        default:
          break;
        }
    return QPointF(0,0);
}

QPointF Viewer::compute_arrow(float t)
{
    return QPointF(1/cosh(t), t-tanh(t));   //X,Y
}

QPointF Viewer::compute_unitline(float t)
{
    return QPointF(t,0);   //X,Y
}

QPointF Viewer::compute_decision(float t)
{
    return QPointF(
                    (t-4),  //X
                    (2*t*t*t - 24*t*t + 96*t - 128)  //Y
        );
}

QPointF Viewer::compute_process(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2*cos_t*cos_t*cos_t;
    float y=2*sin_t*sin_t*sin_t;
    return QPointF(x,y);
}

QPointF Viewer::compute_start(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = cos_t;
    float y = sin_t;
    return QPointF(x,y);

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
