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

class VariableExplorer : public QGraphicsView
{
public:
    VariableExplorer(QWidget *parent = nullptr);

    void set_background();

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsView *view;
    QGraphicsItem *item;
    QPainter *painter;
    QGraphicsTextItem *text;

protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // VARIABLEEXPLORER_H
