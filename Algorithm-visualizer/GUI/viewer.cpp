#include "viewer.h"
#include "math.h"
#include <QPaintEvent>
#include <QPainter>
#include <QGraphicsView>


//why is here not the place where u define the color for the background color of viewer cell
Viewer::Viewer(QWidget *parent) : QWidget(parent),mBackgroundColor(0, 0, 0),mShapeColor(188, 211, 231),mShape(Process)
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

void Viewer::manual_flowchart()
{
    //manually made flowchart:

    //setting up the scene..
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);
    view->setScene(scene);

    //the background of scene and shapes
    scene->setBackgroundBrush(Qt::black);



    //QBrush greenBrush(Qt::green);
    QBrush whiteBrush(Qt::red);
    QPen outlinePen(Qt::lightGray);
    outlinePen.setWidth(2);


    // movable text (do we need it at all?)
    //text->setFlag(QGraphicsItem::ItemIsMovable);


    //position text(it fails every time, it doesn't work nice, we need to find other solution
    //text->setPos(350, -300);



    //this seems like cool idea to center string into shapes, but I still don't quite understand how it works
    //painter->drawText(item->boundingRect(), Qt::AlignCenter, QString::number(3));
    //QFont numberFont = QFont("Helvetica [Cronyx]", 20);
    //painter->setFont(numberFont);



    //draw elements with add_____(x,y,w,h,pen,brush)
    ellipse = scene->addEllipse(320, -300, 300, 60, outlinePen, whiteBrush);
    text = scene->addText(".", QFont("Arial", 30)); // if u remove this line, the whole flowchart will be f***ed up cuz coordinates change if it is not here????? I have no idea why it happens
    rectangle = scene->addRect(320, -220, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(320, -140, 300, 60, outlinePen, whiteBrush);
    diamond = scene->addRect(320, - 60, 150, 150, outlinePen, whiteBrush);
    diamond->setRotation(+45); //and yes obv the moment you rotate the whole coordinate system is untrackable.. (or at least I couldn't find any logic behing it
    //so it is brute forced to work.... :)
    diamond->setPos(200, -255);
    rectangle = scene->addRect(480, 150, 300, 60, outlinePen, whiteBrush); //indentation works well and it is easy
    rectangle = scene->addRect(480, 230, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(480, 310, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(480,390, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(480,470, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(320, 550, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(320, 630, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(320, 710, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(320, 790, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(320, 870, 300, 60, outlinePen, whiteBrush);
    rectangle = scene->addRect(320, 950, 300, 60, outlinePen, whiteBrush);
    ellipse = scene->addEllipse(320, 1030, 300, 60, outlinePen, whiteBrush);

}

void Viewer::on_shape_changed()
{
    switch (mShape) {

        //why is this color the one to influence viewer cell background color??? -Cuz Process is default shape
        case Process:
            mScale =4;
            mIntervalLength = 4*M_PI;
            mStepCount = 256;
            mBackgroundColor = Qt::black;
            break;


        case Decision:
            mScale =40;
            mIntervalLength = 2*M_PI;
            mStepCount = 256;
            mBackgroundColor = Qt::yellow;
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


//scrollable Viewer cell
//problem is that the scroll line appears right next to the shapes and does not take the whole Viewer cell area
//another weird thing is that it always cut in half the last element which idk why happens
void Viewer::WheelEvent(QWheelEvent *event)
{
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    if (event->delta() > 0)
    {
        item->setTransform(QTransform::fromScale(scaleFactor, scaleFactor), true);

    }
    else
    {
        item->setTransform(QTransform::fromScale(1/scaleFactor, 1/scaleFactor), true);
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

    //someone would say useless line, but if u delete it the viewer area is cut somehow, very weird..
    painter.drawRect(this->rect()); // white line around

    QPoint center = this->rect().center(); //i guess this line centers the point which influences the coordinate system later on for coordinates

}
