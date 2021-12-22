#include "viewer.h"
#include "math.h"
#include <QPaintEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QLabel>
#include <iostream>
#include <QFontMetrics>



Viewer::Viewer(QWidget *parent) : QWidget(parent), mBackgroundColor(0,0,255),mShapeColor(255,255,255),mShape(Process)
{
    on_shape_changed();

    set_background();

    //manual_flowchart();

    //scene = new QGraphicsScene(this);
    //view = new QGraphicsView(this);
    //view->setScene(scene);
    //QBrush redbrush(Qt::red);
    //QPen blackpen(Qt::black);
    //ellipse = scene ->addEllipse(10,10,100,100,blackpen, redbrush);
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
            mBackgroundColor = Qt::black;
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

void Viewer::compute(double x, double y, double l, double w)
{
    switch (mShape) {
        case Horizontal:
        return compute_horizontal(x, y, l, w);
            break;

        case Vertical:
            //mBackgroundColor = Qt::green;
            return compute_vertical(x, y, l, w);
            break;

        case Start:
            return compute_start(x, y, l, w);
                break;

        case Process:
            //mBackgroundColor = Qt::blue;
            return compute_process(x, y, l, w);
            break;

        case Decision:
            //mBackgroundColor = Qt::yellow;
            return compute_decision(x, y, l, w);
            break;

        case End:
            //mBackgroundColor = Qt::yellow;
            return compute_end(x, y, l, w);
            break;

        default:
          break;
        }
}

void Viewer::compute_vertical(double x, double y, double l, double w)
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    vertical_line = scene ->addLine(x, y, l, w);
    //10,10,100,100
}


void Viewer::compute_horizontal(double x, double y, double l, double w)
{
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    horizontal_line = scene ->addLine(x, y, l, w);
    //10,10,100,100
}

void Viewer::compute_start(double x, double y, double l, double w)
{
    QString words;
    bool value = 1; // The variable value will actually be passed to the function as argument (it tells us if it's END or START)
    if (value)
    {
        words = "START";
    }
    else words = "END";


    /*float cos_t = cos(t);
    float sin_t = sin(t);
    float x = cos_t;
    float y = sin_t;
    return QPointF(x,y);*/
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);

    auto text = this->createText(words, x,y,l,w);
    ellipse = scene ->addEllipse(x, y, l, w,blackpen, redbrush);
    //scene->addItem(ellipse);
    scene->addItem(text);
}


void Viewer::compute_decision(double x, double y, double l, double w)
{
    QString words;

    //QString(str);
    QString condition = "x > 0"; // The variable condition will actually be passed to the function as argument (condition gotten from backend)
    bool value = 1; // The variable value will actually be passed to the function as argument (it tells us if it's IF or WHILE)
    if (value)
    {
        words = "if " + condition;
    }
    else words = "while " + condition;

    x += 50;
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    diamond = scene->addRect(x, y, 100, 100,blackpen, redbrush);
    auto text = this->createText(words, x,y,100,100);
    diamond->setTransformOriginPoint(QPoint(x + w/2, y + l/2));
    diamond->setRotation(45);
    if (diamond->rotation() == 45) {
        diamond->setPos(-56, -42);
    }



    scene->addItem(text);
    //diamond -> setRotation(45);
    //0,0,100,100
}

void Viewer::compute_process(double x, double y, double l, double w)
{
    QString words;

    QString varName = "x "; // The variable condition will actually be passed to the function as argument (var name gotten from backend)
    bool value = 1; // The variable value will actually be passed to the function as argument (it tells us if it's DECLARE or ASSIGN)
    if (value)
    {
        words = "DECLARE " + varName;
    }
    else words = "ASSIGN " + varName;

    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    rectangle = scene ->addRect(x, y, l, w, blackpen, redbrush);
    auto text = this->createText(words, x,y,l,w);
    scene->addItem(ellipse);
    scene->addItem(text);
    //20,20,100,100
}


void Viewer::compute_end(double x, double y, double l, double w)
{
    QString words;
    bool value = 0; // The variable value will actually be passed to the function as argument (it tells us if it's END or START)
    if (value)
    {
        words = "START";
    }
    else words = "END";


    /*float cos_t = cos(t);
    float sin_t = sin(t);
    float x = cos_t;
    float y = sin_t;
    return QPointF(x,y);*/
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);

    auto text = this->createText(words, x,y,l,w);
    ellipse = scene ->addEllipse(x, y, l, w,blackpen, redbrush);
    //scene->addItem(ellipse);
    scene->addItem(text);
}


void Viewer::paintEvent(QPaintEvent *event) //draw function
{
    QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing,true);

    painter.setBrush(mBackgroundColor); // blue backgroundh
    //painter.setPen(mShapeColor);
    painter.drawRect(this->rect()); // white line around

    QPoint center = this->rect().center();

}


//scrollable Viewer cell
//problem is that the scroll line appears right next to the shapes and does not take the whole Viewer cell area
//another weird thing is that it always cut in half the last element which idk why happens
void Viewer::WheelEvent(QWheelEvent *event)
{
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    if (event->angleDelta().y() > 0)
    {
        item->setTransform(QTransform::fromScale(scaleFactor, scaleFactor), true);

    }
    else
    {
        item->setTransform(QTransform::fromScale(1/scaleFactor, 1/scaleFactor), true);
    }

}





//function that makes manual_flowchart (u can delete once we don't need it anymore)
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



    //this seems like cool idea to center string into shapes, but I still don't quite understand how it works
    //painter->drawText(item->boundingRect(), Qt::AlignCenter, QString::number(3));
    //QFont numberFont = QFont("Helvetica [Cronyx]", 20);
    //painter->setFont(numberFont);

    text = scene->addText(".", QFont("Arial", 30)); // if u remove this line, the whole flowchart will be f***ed up cuz coordinates change if it is not here????? I have no idea why it happens
    //text->setPos(350, -300);
    ellipse = scene->addEllipse(320, -300, 300, 60, outlinePen, whiteBrush);

    //Mina trying out stuff, don't deletebe before consulting her!
    //scene -> addItem(ellipse);
    //QGraphicsTextItem *text = scene->addText("Start");
    //text->setPos(320,-300);

    //draw elements with add_____(x,y,w,h,pen,brush)
    for(int i = 0; i < 2; i++){
        rectangle = scene->addRect(320, -220+80*i, 300, 60, outlinePen, whiteBrush);

    diamond = scene->addRect(320, - 60, 150, 150, outlinePen, whiteBrush);
    diamond->setRotation(+45); //and yes obv the moment you rotate the whole coordinate system is untrackable.. (or at least I couldn't find any logic behing it
    //so it is brute forced to work.... :)
    diamond->setPos(200, -255);
    for(int j = 0; j < 5; j++) {
        rectangle = scene->addRect(480, 150+80*j, 300, 60, outlinePen, whiteBrush); //indentation works well

    }
    for(int z = 0; z < 6; z++) {
    {
        rectangle = scene->addRect(320, 550+80*z, 300, 60, outlinePen, whiteBrush);
    }

    ellipse = scene->addEllipse(320, 1030, 300, 60, outlinePen, whiteBrush);

}}}



void Viewer::set_background()
{

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);
    view->setScene(scene);

    //the background of scene and shapes
    scene->setBackgroundBrush(Qt::black);


    QBrush greenBrush(Qt::green);
    QBrush whiteBrush(Qt::white);
    QBrush blackBrush(Qt::black);
    QPen outlinePen(Qt::lightGray);
    QPen black_pen(Qt::black);
    outlinePen.setWidth(2);

    rectangle = scene->addRect(0, 1000, 100, 20, black_pen, blackBrush);
    rectangle = scene->addRect(10000, 0, 100, 20, black_pen, blackBrush);
    rectangle = scene->addRect(10000, 10000, 100, 20, black_pen, blackBrush);
    rectangle = scene->addRect(0, 0, 100, 20, black_pen, blackBrush);
}

QGraphicsSimpleTextItem* Viewer::createText(QString str, int x, int y, int w, int l)
{
    auto text = new QGraphicsSimpleTextItem(str);
    text->setBrush(QBrush(Qt::white));
    text->setPen(QPen(QPen(Qt::white)));
    QFontMetrics font = QFontMetrics(text->font());
    int length = font.horizontalAdvance(str);
    int height = font.height();
    text->setPos(x + w/2 - length/2,y + l/2 - height/2);
    return text;
}






