#ifndef VARIABLEEXPLORER_H
#define VARIABLEEXPLORER_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include <QPaintEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <Qt>

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class VariableExplorer : public QGraphicsView
{
public:
    VariableExplorer(QWidget *parent = nullptr);

    void set_background();

    int counter_ll;

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsView *view;
    QGraphicsItem *item;
    QPainter *painter;
    QGraphicsTextItem *text;

    string track(int index);
    QGraphicsSimpleTextItem* createText2(QString str, int x, int y, int w, int l);
protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // VARIABLEEXPLORER_H
