#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    counter=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Visualize_clicked()
{
    this->ui->widget_3->setShape(Viewer::Start);
    //for (int i = 1; i < 10; i++) {
      //  this->ui->widget_3->compute(300, 20 + i*80, 300, 60);
    //}
    this->ui->widget_3->setShape(Viewer::Decision);
    this->ui->widget_3->compute(300, 20, 300, 60);
    this->ui->widget_4->readIn();
}

void MainWindow::on_variables_clicked()
{
    int index;
    counter++;
    vector<char> order;
    vector<unordered_map<char, vector<double>>::iterator> vec;

    unordered_map<char, vector<double>> mapa;
    mapa['z'].push_back(4);
    mapa['z'].push_back(5);
    mapa['x'].push_back(1);
    mapa['y'].push_back(2);
    mapa['y'].push_back(3);
    order.push_back('z');
    order.push_back('x');
    order.push_back('y');



    unordered_map<char, vector<double>> mapa1;
    mapa1['a'].push_back(4);
    mapa1['z'].push_back(5.98);
    mapa1['b'].push_back(11);
    mapa1['b'].push_back(24);
    mapa1['b'].push_back(32);

    vector<unordered_map<char, vector<double>>> ve;
    ve.push_back(mapa);
    ve.push_back(mapa1);

    for(unordered_map<char, vector<double>>::iterator it=mapa.begin();it!=mapa.end();it++)
    {
        vec.push_back(it);
    }

    if (counter==ve.size()+1){
        index=1;
        counter=0;
    }
    else{
        index=counter;
    }

    this->ui->widget_4->writeOut(QString("Btn"));
    this->ui->widget_5->track(ve, index);
    //this->ui->widget_5->track2(vec);
}



//void MainWindow::draw_shape(QPaintEvent *)
//{
    //QPainter painter(this);
    //painter.setPen( Qt::green );
    //painter.setBrush( Qt::green );
  //  painter.drawRect(10, 10, 100, 100);
//}

//void MainWindow::draw()
//{ §
  //  update();
//}

