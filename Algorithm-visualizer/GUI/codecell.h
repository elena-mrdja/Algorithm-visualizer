#ifndef CODECELL_H
#define CODECELL_H

#include <QPlainTextEdit>
#include <QWidget>
#include <QPainter>
#include <QTextBlock>

class CodeCell : public QPlainTextEdit
{
    Q_OBJECT
public:
    CodeCell(QWidget *parent = nullptr);

signals:

};

#endif // CODECELL_H
