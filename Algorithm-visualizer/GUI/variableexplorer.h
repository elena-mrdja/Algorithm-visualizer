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
#include <unordered_map>
#include <map>
#include <vector>
#include <utility>

using namespace std;

class VariableExplorer : public QGraphicsView
{
public:
    VariableExplorer(QWidget *parent = nullptr);

    void set_background();

    int Y_current;
    int Y_next;

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsView *view;
    QGraphicsItem *item;
    QPainter *painter;
    QGraphicsTextItem *text;

    void track(vector<vector<pair<vector<string>,vector<int>>>> list, int index);
    //void track2(vector<map<char, vector<double>>::iterator> v);
protected:
    QGraphicsSimpleTextItem* createText2(QString str, int x, int y, int w, int l);
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // VARIABLEEXPLORER_H
