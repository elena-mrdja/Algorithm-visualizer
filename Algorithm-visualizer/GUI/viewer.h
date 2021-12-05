#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>


class Viewer : public QWidget
{
    Q_OBJECT
public:
    explicit Viewer(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    //declaring all the shapes we will use
    enum ShapeType {Arrow, UnitLine, Decision, Process, Start};

    void setBackgroundColor(QColor color){mBackgroundColor=color;} //setter function
    QColor backgroudColor() const {return mBackgroundColor; }  //getter, const function so that it doesn't modify the class variables

    void setShape(ShapeType shape){mShape=shape; on_shape_changed();} //declare rhe setter and getter fcts for shapes
    ShapeType shape() const {return mShape; }

    void setScale(float scale) {mScale=scale; repaint();}
    float scale() const {return mScale;}

    void draw_start(const int radius);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QPointF compute_arrow(float t);
    QPointF compute_unitline(float t);
    QPointF compute_decision(float t);
    QPointF compute_process(float t);
    QPointF compute_start(float t);
    void on_shape_changed();
    QPointF compute(float t); //dispatch function based on mShape type
private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;

signals:

};

#endif // VIEWER_H
