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

int *Viewer::compute(double x, double y,std::string str, flowchart *process_arr)
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

int *Viewer::compute_vertical(double x, double y, double lenght)
{
    QBrush redbrush(Qt::white);
    QPen whitepen(Qt::white);
    vertical_line = scene ->addLine(x, y, x, y+lenght, whitepen);
    return 0;
}


int *Viewer::compute_horizontal(double x, double y, double length)
{
    QBrush redbrush(Qt::red);
    QPen whitepen(Qt::white);
    horizontal_line = scene ->addLine(x, y, x+length, y, whitepen);
    return 0;
}

int *Viewer::compute_start(double x, double y, std::string str)
{
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    auto text = this->createText(words, x,y,processLength,processWidth);
    ellipse = scene ->addEllipse(x, y, processLength, processWidth,blackpen, redbrush);
    compute_vertical(x + processLength/2 ,y+processWidth,spacing);
    scene->addItem(text);

    return 0;
}


int *Viewer::compute_decision(double x, double y, std::string str, flowchart *process_arr)
{
    if (str.find("If") != std::string::npos) //|| str.find("Else") != std::string::npos)
    {
        if(process_arr[0].second_block >0){
            int ifStatements = process_arr[0].first_block;
            int elseStatements = process_arr[0].second_block;
            //int totalStatemens = ifStatements + elseStatements;
            flowchart if_arr[ifStatements+1];
            for(int i = 0; i < ifStatements+1; i++){
                if_arr[i] = process_arr[i];
                std::cout << "If arr" << if_arr->text << std::endl;
            }
            flowchart else_arr[elseStatements+1];
            else_arr[0] = process_arr[0];
            for(int i = 1; i < elseStatements+1; i++){
                else_arr[i] = process_arr[i+ifStatements];
                std::cout << "Else arr" << else_arr->text << std::endl;

            }
            int *tmp = compute_if(x,y, str, if_arr);
            int ifBlockWidth = tmp[0] +100 + 20;
            int ifElseSpacing = 40 + processWidth/2;
            compute_vertical(x+150, y + ifBlockWidth-50, ifElseSpacing);
            std::cout << "If block width: "<< ifBlockWidth <<std::endl;
            int *tmp1 = compute_else(x, y+ifBlockWidth+ifElseSpacing-10, "Else", else_arr); //+ 120;
            int elseBlockWidth = tmp1[0] + 120;
            std::cout << "VIEWER: elseBlockWidth: " << elseBlockWidth << std::endl;
            int blockWidth = ifBlockWidth-20 + ifElseSpacing + elseBlockWidth;
            std::cout << "VIEWER BLOCK WIDTH: " << blockWidth << std::endl;
            int results[2] = {blockWidth, tmp[1]};

            return results;
        }
        else
        {
            return compute_if(x,y, str, process_arr);
        }
    }
    else if (str.find("While") != std::string::npos)
    {
        return compute_while(x,y, str, process_arr);
    }

}

int *Viewer::compute_if(double x, double y, std::string str, flowchart *if_arr)
{
    //USEFUL VARIABLES
    int numberStatements = if_arr[0].first_block;

    int x_bottom_diamond = x  + processLength/2;
    int y_bottom_diamond = y  + squareSize;
    int x_right_diamond = x + 100 + decisionLength;
    int y_right_diamond = y + 20 + decisionWidth/2;

    int y_pos = y_bottom_diamond;

    int newNumberStatements = 0;
    int numberProcess = 0;
    int numberWhile = 0;
    int numberIf = 1;

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
        std::cout << "Text at location i:" << if_arr[i].text;

        if(if_arr[i+1].chart_shape > 0){nextShapeWidth = decisionWidth;}
        else if (if_arr[i+1].chart_shape == 0){nextShapeWidth = processWidth;}

        compute_vertical(x_bottom_diamond, y_pos , spacing + nextShapeWidth/2);
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
                int *tmp_if = compute(x_bottom_diamond + 20+indentation - 100, y_pos, statementString, while_arr);
                numberIf+= tmp_if[1];
                returnV = tmp_if[0] + decisionWidth/2;
                compute_vertical(x_bottom_diamond, y_pos, returnV);
                y_pos+= returnV;
            }
            else if (if_arr[i].chart_shape == 2)
            {
                int *tmp_while = compute(x_bottom_diamond +20+ indentation -100, y_pos, statementString, while_arr);
                int line_length = tmp_while[0];
                compute_vertical(x_bottom_diamond, y_pos+30, line_length);
                numberWhile+= tmp_while[1];
                y_pos += line_length+30;
            }
            i += newNumberStatements;
        }
    }
    int results[2] = {y_pos - y_bottom_diamond + 30, numberIf};
    return results;
}

int *Viewer::compute_else(double x, double y, std::string str, flowchart *else_arr)
{
    //USEFUL VARIABLES
    int numberStatements = else_arr[0].second_block;

    int x_bottom_diamond = x  + processLength/2;
    int y_bottom_diamond = y  + squareSize - 10;
    int x_right_diamond = x + 100 + decisionLength;
    int y_right_diamond = y + 20 + decisionWidth/2;

    int y_pos = y_bottom_diamond;

    int newNumberStatements = 0;
    int numberProcess = 0;
    int numberWhile = 0;
    int numberIf = 1;

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
        std::cout << "Text at location i:" << else_arr[i].text;

        if(else_arr[i+1].chart_shape > 0){nextShapeWidth = decisionWidth;}
        else if (else_arr[i+1].chart_shape == 0){nextShapeWidth = processWidth;}

        compute_vertical(x_bottom_diamond, y_pos+10 , -10+ spacing + nextShapeWidth/2);
        y_pos += spacing+ nextShapeWidth/2;
        compute_horizontal(x_bottom_diamond, y_pos, indentation);
        y_pos += 20 - 50;


        std::string statementString = else_arr[i].text;

        if (else_arr[i].chart_shape == 0)
        {
            setShape(Process);
            compute(x_bottom_diamond + indentation, y_pos, statementString);
            numberProcess++;
            y_pos += processWidth/2;
        }
        else if (else_arr[i].chart_shape > 0)
        {
            setShape(Decision);
            newNumberStatements = else_arr[i].first_block;
            flowchart while_arr[newNumberStatements+1];
            for (int j = 0;j<newNumberStatements+1 ;j++ )
            {
                while_arr[j] = else_arr[i+j];
            }
            if (else_arr[i].chart_shape == 1)
               {
                int *tmp_if = compute(x_bottom_diamond + 20+indentation - 100, y_pos, statementString, while_arr);
                numberIf+= tmp_if[1];
                returnV = tmp_if[0] + decisionWidth/2;
                compute_vertical(x_bottom_diamond, y_pos, returnV);
                y_pos+= returnV;
            }
            else if (else_arr[i].chart_shape == 2)
            {
                int *tmp_while = compute(x_bottom_diamond +20+ indentation -100, y_pos, statementString, while_arr);
                int line_length = tmp_while[0];
                compute_vertical(x_bottom_diamond, y_pos+30, line_length);
                numberWhile+= tmp_while[1];
                y_pos += line_length+30;
            }
            i += newNumberStatements;
        }
    }
    int results[2] = {y_pos - y_bottom_diamond + 30, numberIf};
    return results;
}

int *Viewer::compute_while(double x, double y, std::string str, flowchart *while_arr)
{
    //USEFUL VARIABLES
    int numberStatements = while_arr[0].first_block;

    int x_bottom_diamond = x + processLength/2;
    int y_bottom_diamond = y +squareSize;
    int x_right_diamond = x + 100 + squareSize + 20;
    int y_right_diamond = y + decisionLength/2 - 40;
    int y_pos = y_bottom_diamond;

    int newNumberStatements = 0;
    int numberProcess = 0;
    int numberWhile = 1;
    int numberIf = 0;

    int returnIf = 0;
    int returnWhile = 0;
    int loopsStatements = 0;
    //END VARIABLES

    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    diamond = scene->addRect(x+100, y-20, squareSize, squareSize,blackpen, redbrush);
    auto text = this->createText(words, x+100,y-20,squareSize,squareSize);
    diamond->setTransformOriginPoint(QPoint(x+100+squareSize/2, y-20+squareSize/2));
    diamond->setRotation(45);
    scene->addItem(text);

    for (int i = 1; i < numberStatements+1; i++)
    {
        std::string statementString = while_arr[i].text;

        compute_vertical(x_bottom_diamond, y_bottom_diamond, spacing);
        y_pos += spacing;

        if (while_arr[i].chart_shape == 0)
        {
            setShape(Process);
            compute(x, y_pos, statementString);
            numberProcess++;
            y_pos += processWidth;
            if(i == numberStatements){compute_vertical(x_bottom_diamond, y_pos, spacing/2);}
            else{compute_vertical(x_bottom_diamond, y_pos, spacing);}

        }
        else if (while_arr[i].chart_shape >0)
        {
            setShape(Decision);
            newNumberStatements = while_arr[i].first_block;
            loopsStatements += newNumberStatements;
            flowchart process_arr[newNumberStatements+1];
            for (int j = 0;j<newNumberStatements+1 ;j++ ){
                process_arr[j] = while_arr[i+j];
            }
            if (while_arr[i].chart_shape ==1)
            {
                int * tmp_if = compute(x, y_pos+40, statementString, process_arr);
                returnIf = tmp_if[0] + decisionWidth ;
                numberIf = tmp_if[1];
                y_pos += returnIf -40;
                compute_vertical(x_bottom_diamond, y_pos, spacing);
            }
            else if (while_arr[i].chart_shape == 2)
            {   int * tmp = compute(x, y_pos+40, statementString, process_arr);
                returnWhile = tmp[0]+ decisionWidth/2;
                numberWhile += tmp[1] ;
                y_pos += returnWhile - 40;
                compute_vertical(x_bottom_diamond, y_pos+spacing/2, spacing/2);

            }
            i += newNumberStatements;

        }
    }
    compute_horizontal(x_right_diamond, y_right_diamond, whileLine*numberWhile + ((100 + indentation+processWidth/2) * numberIf));

    int line_length =  decisionWidth/2 + ((numberStatements - loopsStatements) * spacing) + (numberProcess * processWidth) + spacing/2  + returnIf + returnWhile ;
    compute_vertical(x_right_diamond +whileLine*numberWhile + ((100 + indentation+processWidth/2) * numberIf), y_right_diamond, line_length);
    compute_horizontal(x_bottom_diamond, y_right_diamond + line_length, whileLine*numberWhile + ((100 + indentation+processWidth/2) * numberIf) + decisionLength/2);
    compute_vertical(x_bottom_diamond, y_right_diamond+line_length, -(numberWhile * spacing/2));
    int results[2] = {line_length, numberWhile};

    return results;
}

int *Viewer::compute_process(double x, double y,std::string str)
{
    int spacing = 40;
    QString words = QString::fromStdString(str);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    rectangle = scene ->addRect(x, y, processLength, processWidth, blackpen, redbrush);
    auto text = this->createText(words, x,y,processLength,processWidth);
    scene->addItem(text);
    return 0;//processWidth/2;
}


int *Viewer::compute_end(double x, double y, std::string str)
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






