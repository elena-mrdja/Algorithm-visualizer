#ifndef VARCELL_H
#define VARCELL_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>

class VarCell : public QGraphicsView
{
public:
    VarCell(QWidget* parent = 0);

protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // VARCELL_H
