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

int Viewer::compute(double x, double y, double l, double w, std::string str, flowchart *process_arr)
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
            return compute_start(x, y, l, w, str="START");
                break;

        case Process:
            //mBackgroundColor = Qt::blue;
            return compute_process(x, y, l, w, str);
            break;

        case Decision:
            //mBackgroundColor = Qt::yellow;
            return compute_decision(x, y, 100, 100, str, process_arr);
            break;

        case End:
            //mBackgroundColor = Qt::yellow;
            return compute_end(x, y, l, w, str="END");
            break;

        default:
          break;
        }
}

int Viewer::compute_vertical(double x, double y, double l, double w)
{
    QBrush redbrush(Qt::white);
    QPen whitepen(Qt::white);
    vertical_line = scene ->addLine(x, y, l, w, whitepen);
    //10,10,100,100
    return 0;
}


int Viewer::compute_horizontal(double x, double y, double l, double w)
{
    QBrush redbrush(Qt::red);
    QPen whitepen(Qt::white);
    horizontal_line = scene ->addLine(x, y, l, w, whitepen);
    //10,10,100,100
    return 0;
}

int Viewer::compute_start(double x, double y, double l, double w, std::string str)
{
    int spacing = 40;
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    auto text = this->createText(words, x,y,l,w);
    ellipse = scene ->addEllipse(x, y, l, w,blackpen, redbrush);
    compute_vertical(x + l/2 ,y+w,x + l/2,y + w + spacing);
    scene->addItem(text);

    return 0;
}


int Viewer::compute_decision(double x, double y, double l, double w, std::string str, flowchart *process_arr)
{
    int spacing = 80;
    QString words = QString::fromStdString(str);
    x = x +100;
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    y = y-20;
    diamond = scene->addRect(x, y, w, l,blackpen, redbrush);
    auto text = this->createText(words, x,y,w,l);
    diamond->setTransformOriginPoint(QPoint(x+l/2, y+w/2));
    diamond->setRotation(45);
    scene->addItem(text);
    if (str.find("If") != std::string::npos)
    {
         int posEndIf = compute_if(x,y,l,w,spacing, process_arr);
         //compute_vertical(x+l/2, y+w+20, x+l/2, posEndIf);
    }
//    else if (str.find("While") != std::string::npos)
//    {
//        compute_while(x,y,l,w,spacing, numberStatements, numberLoops);
//    }

}

//{{0, "Declare x", 0, 0},
//{1, "If x > 1", 3, 0},
//{0, "Assign z", 0,0},
//{1, "If x < 2", 1,0},
//{0, "Assign y", 0,0}};


int Viewer::compute_if(double x, double y, double l, double w, int spacing, flowchart *process_arr)
{
    int numberIndents = 1;
    int indentation = 120;
    int numberStatements = process_arr[0].first_block;
    const int shapeWidth = 60;
    const int L = 300;
    const int W = 60;


    int x_bottom_diamond = x + l/2; int y_bottom_diamond = y +w+20;

    //Vertical line going to the end of the if
//    compute_vertical(x_bottom_diamond, y_bottom_diamond,
//                     x_bottom_diamond, y_bottom_diamond + numberStatements * (shapeWidth + spacing));
    //First horizontal line (will always be here)
//    compute_horizontal(x_bottom_diamond, y_bottom_diamond + shapeWidth/2,
//                       x_bottom_diamond + indentation, y_bottom_diamond + shapeWidth/2);

    int newNumberStatements = 0;
    for (int i = 1; i < numberStatements+1; i++){
        compute_vertical(x_bottom_diamond, y_bottom_diamond,
                         x_bottom_diamond, y_bottom_diamond + i * (shapeWidth/2 + spacing)
                         );

        compute_horizontal(x_bottom_diamond, y_bottom_diamond + (i) * (shapeWidth/2 + spacing),
                           x_bottom_diamond + indentation, y_bottom_diamond + (i) * (shapeWidth/2 + spacing));
        std::string str = process_arr[i].text;
        if(process_arr[i].chart_shape == 0){
            setShape(Process);
            compute(x_bottom_diamond + indentation, y_bottom_diamond + i * spacing + (i-1) * shapeWidth/2, L, W, str);
        }
        else if (process_arr[i].chart_shape == 1){
            setShape(Decision);
            newNumberStatements = process_arr[i].first_block;
            std::cout << "In decision inside compute_if"<< newNumberStatements;
            flowchart if_arr[newNumberStatements+1];
            for (int j = 0;j<newNumberStatements+1 ;j++ ){
                    if_arr[j] = process_arr[i+j];
            }
            this->compute(x_bottom_diamond, y_bottom_diamond + i * spacing + (i-1) * shapeWidth/2, L, W, str, if_arr);
            i += newNumberStatements+1;
        }
    }
    //compute_vertical(x_bottom_diamond, y_bottom_diamond,
                    // x_bottom_diamond, y_bottom_diamond + newNumberStatements * spacing + (numberStatements-1) * shapeWidth/2);






//    for (int i = 0;i<numberStatements ; i++) {
//        compute_horizontal(x_bottom_diamond, y_bottom_diamond + shapeWidth/2 + i*(shapeWidth + spacing),
//                           x_bottom_diamond + l/2 +20, y_bottom_diamond + shapeWidth/2 + i*(shapeWidth + spacing));
//    }
    return y_bottom_diamond + newNumberStatements * spacing + (numberStatements-1) * shapeWidth/2;
}








int Viewer::compute_while(double x, double y, double l, double w, int spacing, int numberStatements, int numberLoops)
{
    const int shapeWidth = 60;
    const int line_size = 150;
    int x_bottom_diamond = x + l/2; int y_bottom_diamond = y +w+20;
    compute_vertical(x_bottom_diamond, y_bottom_diamond,
                     x_bottom_diamond, y_bottom_diamond + numberStatements * (shapeWidth + spacing));

    int x_loop = x+l+20 + (numberLoops+1) * line_size;

    compute_horizontal(x +l + 20, y+w/2,
                       x_loop, y+w/2);
    compute_vertical(x_loop, y+w/2,
                     x_loop, y_bottom_diamond + numberStatements * (shapeWidth + spacing) + (spacing * 1/2));



    compute_horizontal(x +l/2, y_bottom_diamond + numberStatements * (shapeWidth + spacing) + (spacing * 1/2),
                       x_loop, y_bottom_diamond + numberStatements * (shapeWidth + spacing) + (spacing * 1/2));

}




int Viewer::compute_process(double x, double y, double l, double w, std::string str)
{
    int spacing = 40;
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    rectangle = scene ->addRect(x, y, l, w, blackpen, redbrush);
    auto text = this->createText(words, x,y,l,w);
    scene->addItem(text);
    return 0;
}


int Viewer::compute_end(double x, double y, double l, double w, std::string str)
{
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);

    auto text = this->createText(words, x,y,l,w);
    ellipse = scene ->addEllipse(x, y, l, w,blackpen, redbrush);
    scene->addItem(text);
    return 0;
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






