#include "viewer.h"
#include "math.h"
#include <QPaintEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QLabel>
#include <iostream>
#include <QFontMetrics>

//GLOBAL VARIABLES

//Process
int const processLength  = 300;
int const processWidth = 60;

//Decision
int const squareSize = 100;

int const decisionLength = sqrt(20000);
int const decisionWidth = sqrt(20000);

//Drawing
int const spacing = 80;
int const whileLine = 150;
int const indentation = 120;


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

int Viewer::compute(double x, double y,std::string str, flowchart *process_arr)
{
    switch (mShape) {
//        case Horizontal:
//        return compute_horizontal(x, y, );
//            break;

//        case Vertical:
//            //mBackgroundColor = Qt::green;
//            return compute_vertical(x, y, l, w);
//            break;

        case Start:
            return compute_start(x, y, str="START");
                break;

        case Process:
            //mBackgroundColor = Qt::blue;
            return compute_process(x, y, str);
            break;

        case Decision:
            //mBackgroundColor = Qt::yellow;
            return compute_decision(x, y,str, process_arr);
            break;

        case End:
            //mBackgroundColor = Qt::yellow;
            return compute_end(x, y, str="END");
            break;

        default:
          break;
        }
}

int Viewer::compute_vertical(double x, double y, double lenght)
{
    QBrush redbrush(Qt::white);
    QPen whitepen(Qt::white);
    vertical_line = scene ->addLine(x, y, x, y+lenght, whitepen);
    return 0;
}


int Viewer::compute_horizontal(double x, double y, double length)
{
    QBrush redbrush(Qt::red);
    QPen whitepen(Qt::white);
    horizontal_line = scene ->addLine(x, y, x+length, y, whitepen);
    return 0;
}

int Viewer::compute_start(double x, double y, std::string str)
{
    int spacing = 40;
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    auto text = this->createText(words, x,y,processLength,processWidth);
    ellipse = scene ->addEllipse(x, y, processLength, processWidth,blackpen, redbrush);
    compute_vertical(x + processLength/2 ,y+processWidth,spacing);
    scene->addItem(text);

    return 0;
}


int Viewer::compute_decision(double x, double y, std::string str, flowchart *process_arr)
{
//    QString words = QString::fromStdString(str);
//    QBrush redbrush(Qt::red);
//    QPen blackpen(Qt::black);
//    y = y-20;
//    x = x +100;
//    diamond = scene->addRect(x, y, decisionLength, decisionWidth,blackpen, redbrush);
//    auto text = this->createText(words, x,y,decisionLength,decisionWidth);
//    diamond->setTransformOriginPoint(QPoint(x+decisionLength/2, y+decisionWidth/2));
//    diamond->setRotation(45);
//    scene->addItem(text);
    if (str.find("If") != std::string::npos)
    {
        return compute_if(x,y, str, process_arr);
    }
    else if (str.find("While") != std::string::npos)
    {
        x = x-100;
        compute_while(x,y, str, process_arr);
    }

}

int Viewer::compute_if(double x, double y, std::string str, flowchart *if_arr)
{
    //USEFUL VARIABLES
    int numberStatements = if_arr[0].first_block;

    int x_bottom_diamond = x  + processLength/2;
    int y_bottom_diamond = y  + squareSize;
    int x_right_diamond = x + 100 + processLength;
    int y_right_diamond = y + 20 + processWidth/2;

    int y_pos = y_bottom_diamond;

    int newNumberStatements = 0;
    int numberProcess = 0;
    int numberWhile = 0;
    int numberIf = 0;

    int returnV = 0;
    int nextShapeWidth = 0;
    //END VARIABLES

    //DRAWING FIRST IF
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    diamond = scene->addRect(x+100, y-20, squareSize, squareSize,blackpen, redbrush);
    auto text = this->createText(words, x+100,y-20,squareSize,squareSize);
    diamond->setTransformOriginPoint(QPoint(x+100+squareSize/2, y-20+squareSize/2));
    diamond->setRotation(45);
    scene->addItem(text);
    for (int i = 1; i < numberStatements+1; i++){

        if(if_arr[i+1].chart_shape > 0){nextShapeWidth = decisionWidth;}
        else if (if_arr[i+1].chart_shape == 0){nextShapeWidth = processWidth;}

        compute_vertical(x_bottom_diamond, y_pos , spacing + nextShapeWidth/2 + returnV);
        y_pos += spacing+ nextShapeWidth/2;
        compute_horizontal(x_bottom_diamond, y_pos, indentation);
        y_pos += 20 - 50;


        std::string statementString = if_arr[i].text;



        if (if_arr[i].chart_shape == 0)
        {
            setShape(Process);
            compute(x_bottom_diamond + indentation, y_pos, statementString);
            numberProcess++;
            y_pos += processWidth/2;
        }
        else if (if_arr[i].chart_shape > 0)
        {
            setShape(Decision);
            newNumberStatements = if_arr[i].first_block;
            flowchart while_arr[newNumberStatements+1];
            for (int j = 0;j<newNumberStatements+1 ;j++ )
            {
                while_arr[j] = if_arr[i+j];
            }
            if (if_arr[i].chart_shape == 1)
               {
                returnV = compute(x_bottom_diamond + indentation - 100, y_pos, statementString, while_arr) + decisionWidth/2;
                numberIf++;
                y_pos+= returnV;
                std::cout << "In for loop, i = " << i << "return of writing the if: " << returnV << std::endl;
            }
            else if (if_arr[i].chart_shape == 2)
            {
                compute(x + indentation, y_pos, statementString, while_arr);
                numberWhile++;
                y_pos += decisionWidth/2;
            }
            i += newNumberStatements;
        }
    }
    compute_vertical(x_bottom_diamond, y_pos - returnV, returnV);
    return y_pos - y_bottom_diamond + 30;
}

int Viewer::compute_while(double x, double y, std::string str, flowchart *while_arr)
{
    //USEFUL VARIABLES
    int numberStatements = while_arr[0].first_block;

    int x_bottom_diamond = x + 100 + processLength/2;
    int y_bottom_diamond = y + 20+ processWidth;
    int x_right_diamond = x + 100 + processLength;
    int y_right_diamond = y + 20 + processWidth/2;

    int y_pos = y_bottom_diamond;

    int newNumberStatements = 0;
    int numberProcess = 0;
    int numberWhile = 0;
    int numberIf = 0;
    //END VARIABLES

    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    diamond = scene->addRect(x+100, y-20, squareSize, squareSize,blackpen, redbrush);
    auto text = this->createText(words, x+100,y-20,squareSize,squareSize);
    diamond->setTransformOriginPoint(QPoint(x+100+squareSize/2, y-20+squareSize/2));
    diamond->setRotation(45);
    scene->addItem(text);

    compute_horizontal(x_bottom_diamond, y_bottom_diamond, spacing);
    y_pos += spacing;

    for (int i = 1; i < numberStatements+1; i++)
    {
        std::string statementString = while_arr[i].text;
        if (while_arr[i].chart_shape == 0)
        {
            setShape(Process);
            compute(x, y + i*spacing, statementString);
            numberProcess++;
            y_pos += processWidth;
            compute_vertical(x_bottom_diamond, y_pos, spacing);
        }
        else if (while_arr[i].chart_shape >0)
        {
            setShape(Decision);
            newNumberStatements = while_arr[i].first_block;
            flowchart while_arr[newNumberStatements+1];
            for (int j = 0;j<newNumberStatements+1 ;j++ ){
                while_arr[j] = while_arr[i+j];
            }
            if (while_arr[i].chart_shape ==1){
                compute(x, y + (i*spacing), statementString, while_arr);
                numberIf++;
                y_pos += decisionWidth;
                compute_vertical(x_bottom_diamond, y_pos, spacing);
                }
                else if (while_arr[i].chart_shape == 2){
                    compute_while(x, y + (i*spacing), statementString, while_arr);
                    numberWhile++;
                    y_pos += decisionWidth;
                    compute_vertical(x_bottom_diamond, y_pos, spacing);
                }
                i += newNumberStatements;
            }
        }
        compute_horizontal(x_right_diamond, y_right_diamond, whileLine*numberWhile + ((indentation+processWidth/2) * numberIf));
        compute_vertical(x_right_diamond +whileLine*numberWhile + ((indentation+processWidth/2) * numberIf), y_right_diamond, (numberStatements+1 * spacing) + (numberProcess * processWidth) + ((numberIf+numberWhile) * decisionWidth));
        compute_horizontal(x_bottom_diamond, y_right_diamond + (numberStatements+1 * spacing) + (numberProcess * processWidth) + ((numberIf+numberWhile) * decisionWidth), whileLine*numberWhile + ((indentation+processWidth/2) * numberIf));
}





//int Viewer::compute_if(double x, double y, std::string str, flowchart *process_arr)
//{
//    int numberIndents = 1;
//    int indentation = 130;
//    int numberStatements = process_arr[0].first_block;
//    const int shapeWidth = 60;
//    const int L = 300;
//    const int W = 60;


//    int x_bottom_diamond = x + l/2; int y_bottom_diamond = y +w+20;

//    int pos = 0;
//    int newNumberStatements = 0;
//    for (int i = 1; i < numberStatements+1; i++){
//        compute_vertical(x_bottom_diamond, y_bottom_diamond,
//                         x_bottom_diamond, y_bottom_diamond + i * (shapeWidth/2 + spacing)
//                         );

//        compute_horizontal(x_bottom_diamond, y_bottom_diamond + (i) * (shapeWidth/2 + spacing),
//                           x_bottom_diamond + indentation, y_bottom_diamond + (i) * (shapeWidth/2 + spacing));
//        std::string str = process_arr[i].text;
//        if(process_arr[i].chart_shape == 0){
//            setShape(Process);
//            pos = compute(x_bottom_diamond + indentation, y_bottom_diamond + i * spacing + (i-1) * shapeWidth/2, L, W, str);
//        }
//        else if (process_arr[i].chart_shape > 0){
//            setShape(Decision);
//            newNumberStatements = process_arr[i].first_block;
//            flowchart if_arr[newNumberStatements+1];
//            for (int j = 0;j<newNumberStatements+1 ;j++ ){
//                    if_arr[j] = process_arr[i+j];
//            }
//            pos = this->compute(x_bottom_diamond, y_bottom_diamond + i * spacing + (i-1) * shapeWidth/2, L, W, str, if_arr) - 30;
//            i += newNumberStatements+1;
//        }
//    }
//    return numberStatements * (spacing + shapeWidth/2) + pos;
//}


//int Viewer::compute_while(double x, double y, std::string str, flowchart *process_arr)
//{
//    const int lineSize = 150;
//    int numberIndents = 1;
//    int indentation = 120;
//    int numberStatements = process_arr[0].first_block;
//    const int shapeWidth = 60;
//    const int L = 300;
//    const int W = 60;
//    int x_right = x+100 + 120;
//    int c = 1;
//    int line = 0;

//    int x_bottom_diamond = x + l/2 + 100; int y_bottom_diamond = y +w+20;
//    compute_vertical(x_bottom_diamond, y_bottom_diamond,
//                     x_bottom_diamond, y_bottom_diamond + (numberStatements+1) * (shapeWidth/2 + spacing) + spacing
//                     );

//    int newNumberStatements = 0;
//    for (int i = 1; i < numberStatements+1; i++){
//        std::string str = process_arr[i].text;
//        if(process_arr[i].chart_shape == 0){
//            setShape(Process);
//            compute(x, y_bottom_diamond + i * spacing + (i-1) * shapeWidth/2, L, W, str);
//        }
//        else if (process_arr[i].chart_shape > 0){
//            c++;
//            setShape(Decision);
//            newNumberStatements = process_arr[i].first_block;
//            flowchart while_arr[newNumberStatements+1];
//            for (int j = 0;j<newNumberStatements+1 ;j++ ){
//                    while_arr[j] = process_arr[i+j];
//            }
//            this->compute(x, y_bottom_diamond + i * spacing + (i-1) * shapeWidth/2, L, W, str, while_arr) ;
//            i += newNumberStatements+1;
//            line += shapeWidth * 1/2 + spacing;

//        }
//  }
//    compute_horizontal(x_right, y + sqrt(2 * pow(100,2)) / 2 - 20,
//                       x_right + c * lineSize ,y + sqrt(2 * pow(l,2)) / 2 - 20);

//    compute_vertical(x_right + c * lineSize, y + sqrt(2 * pow(l,2)) / 2 - 20,
//                     x_right + c * lineSize, y_bottom_diamond + line + numberStatements * (shapeWidth + spacing) + spacing
//                     );

//    compute_horizontal(x_right + c * lineSize, y_bottom_diamond + line + numberStatements * (shapeWidth + spacing) + spacing,
//                       x_bottom_diamond,y_bottom_diamond + line + numberStatements * (shapeWidth + spacing) + spacing
//                       );


//    compute_horizontal(x +l/2, y_bottom_diamond + numberStatements * (shapeWidth + spacing) + (spacing * 1/2),
//                       x_loop, y_bottom_diamond + numberStatements * (shapeWidth + spacing) + (spacing * 1/2));

//}




int Viewer::compute_process(double x, double y,std::string str)
{
    int spacing = 40;
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    rectangle = scene ->addRect(x, y, processLength, processWidth, blackpen, redbrush);
    auto text = this->createText(words, x,y,processLength,processWidth);
    scene->addItem(text);
    return processWidth/2;
}


int Viewer::compute_end(double x, double y, std::string str)
{
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);

    auto text = this->createText(words, x,y,processLength,processWidth);
    ellipse = scene ->addEllipse(x, y,processLength, processWidth,blackpen, redbrush);
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






