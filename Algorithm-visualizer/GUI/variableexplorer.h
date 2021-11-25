#ifndef VARIABLEEXPLORER_H
#define VARIABLEEXPLORER_H

#include <QGraphicsView>
#include <QWidget>

class VariableExplorer : public QGraphicsView
{
public:
    VariableExplorer(QWidget *parent = nullptr);

protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // VARIABLEEXPLORER_H
