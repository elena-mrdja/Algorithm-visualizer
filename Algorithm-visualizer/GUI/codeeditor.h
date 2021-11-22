#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QWidget>
#include <QPainter>
#include <QTextBlock>
#include "highlighter.h"

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    CodeEditor(QWidget *parent = nullptr);

    //Methos to paint the line numbers and to have acess to it's width
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    //We need to be able to resize in case the viewer scrolls or the number of lines changes (adding a line at the bottom)
    void resizeEvent(QResizeEvent *event) override;

private slots:
    //Methods to modify the elements of the line number are
    void applyHiglighting();
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);

private:
    QWidget *lineNumberArea;
    Highlighter *highlighter;
};

#endif // CODEEDITOR_H
