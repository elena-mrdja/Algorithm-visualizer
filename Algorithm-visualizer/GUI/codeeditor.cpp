#include "codeeditor.h"
#include "linenumberarea.h"
#include <iostream>
#include<fstream>
CodeEditor::CodeEditor(QWidget *parent)
{
    lineNumberArea = new LineNumberArea(this);


    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberAreaWidth);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
    //connect(this, &CodeEditor::cursorPositionChanged, this, &CodeEditor::highlightCurrentLine);
    connect(this, &CodeEditor::textChanged, this, &CodeEditor::applyHiglighting);
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(matchParentheses()));
    //connect(this, &CodeEditor::textChanged, this, SLOT(addRightParenthesis()));

    updateLineNumberAreaWidth(0);
    //highlightCurrentLine();
    highlighter = new Highlighter(this->document());
    QPalette p = this->palette();
    p.setColor(QPalette::Active, QPalette::Base, Qt::black);
    this->setPalette(p);
}

void CodeEditor::applyHiglighting()
{
    highlighter->highlightBlock(this->toPlainText());

}

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10){
        max /=10;
        digits++;
    }

    int space = 4 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}

void CodeEditor::updateLineNumberAreaWidth(int /*newBlockCount*/)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    //dy holds the number of pixels, if it is non-zero we call scrol method between 0 and dy.
    //else,
    if (dy) {
        lineNumberArea->scroll(0, dy);
    }
    else {
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
    }

    if (rect.contains(viewport()->rect())) {
        updateLineNumberAreaWidth(0);
    }
}

void CodeEditor::resizeEvent(QResizeEvent *event)
{
    QPlainTextEdit::resizeEvent(event);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if(!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::green).lighter(160);
        QColor textColor = QColor(Qt::black);

        selection.format.setBackground(lineColor);
        selection.format.setForeground(textColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    //We start by creating the painter to paint the background of the widget.
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::black);

    //Getting information on the blocks (i.e. the text lines)
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top()); //Need doc on this line
    int bottom = top + qRound(blockBoundingRect(block).height()); //Need doc on this line as well (qRound??)

    while (block.isValid() && top <=event->rect().bottom()) {

        if(block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::white);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(), Qt::AlignCenter, number);
        }

        //We go to the next block
        block = block.next();
        top = bottom;
        bottom = top + qRound(blockBoundingRect(block).height());
        blockNumber++;
    }
}


//function that takes current state of the text editor and converts it into a file
void CodeEditor::writeOut(QString docText)
{
    //QDir::currentPath()
    std::string const nomFichier("/Users/katia_borisova/Desktop/ANTLR_FILE/score.txt");
    docText = this->toPlainText();
    std::ofstream MyFile(nomFichier);
    if(MyFile)
    {
        MyFile << docText.toStdString();
    } else {std::cout << "Could not read file";}
    MyFile.close();
}

void CodeEditor::readIn()
{
    std::string const nomFichier("/Users/mina_goranovic/Desktop/score.txt");
    std::string myText;
    std::ifstream readFile(nomFichier);

    // Use a while loop together with the getline() function to read the file line by line
    QString doc;
    while (getline (readFile, myText)) {
      // Output the text from the file
        doc.append(QString::fromStdString(myText + "\n"));
      //std::cout << myText;
    }
    this->setPlainText(doc);

    // Close the file
    readFile.close();

}




/* ============================
 * The next section of the file concerns parenthesis matching (highlighting when cursor is before of after a paire of parenthesis
 * TO BE IMPLEMENTED: Functions also recognise {} and [] (side-project)
 * ============================
*/


void CodeEditor::matchParentheses()
{
    bool match = false;
    QList<QTextEdit::ExtraSelection> selections;
    setExtraSelections(selections);

    TextBlockData *data = static_cast<TextBlockData *>(textCursor().block().userData());

    if (data) {
        QVector<ParenthesisInfo *> infos = data->parentheses();

        int pos = textCursor().block().position();
        for (int i = 0; i < infos.size(); ++i) {
            ParenthesisInfo *info = infos.at(i);

            int curPos = textCursor().position() - textCursor().block().position();
            if (info->position == curPos && info->character == '(') {
                if (matchLeftParenthesis(textCursor().block(), i + 1, 0))
                    createParenthesisSelection(pos + info->position);
            } else if (info->position == curPos - 1 && info->character == ')') {
                if (matchRightParenthesis(textCursor().block(), i - 1, 0))
                    createParenthesisSelection(pos + info->position);
            }
        }
    }
}

bool CodeEditor::matchLeftParenthesis(QTextBlock currentBlock, int i, int numLeftParentheses)
{
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    QVector<ParenthesisInfo *> infos = data->parentheses();

    int docPos = currentBlock.position();
    for (; i < infos.size(); ++i) {
        ParenthesisInfo *info = infos.at(i);

        if (info->character == '(') {
            ++numLeftParentheses;
            continue;
        }

        if (info->character == ')' && numLeftParentheses == 0) {
            createParenthesisSelection(docPos + info->position);
            return true;
        } else
            --numLeftParentheses;
    }

    currentBlock = currentBlock.next();
    if (currentBlock.isValid())
        return matchLeftParenthesis(currentBlock, 0, numLeftParentheses);

    return false;
}

bool CodeEditor::matchRightParenthesis(QTextBlock currentBlock, int i, int numRightParentheses)
{
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    QVector<ParenthesisInfo *> parentheses = data->parentheses();

    int docPos = currentBlock.position();
    for (; i > -1 && parentheses.size() > 0; --i) {
        ParenthesisInfo *info = parentheses.at(i);
        if (info->character == ')') {
            ++numRightParentheses;
            continue;
        }
        if (info->character == '(' && numRightParentheses == 0) {
            createParenthesisSelection(docPos + info->position);
            return true;
        } else
            --numRightParentheses;
    }

    currentBlock = currentBlock.previous();
    if (currentBlock.isValid())
        return matchRightParenthesis(currentBlock, 0, numRightParentheses);

    return false;
}

void CodeEditor::createParenthesisSelection(int pos)
{
    QList<QTextEdit::ExtraSelection> selections = extraSelections();

    QTextEdit::ExtraSelection selection;
    QTextCharFormat format = selection.format;
    format.setBackground(Qt::green);
    selection.format = format;

    QTextCursor cursor = textCursor();
    cursor.setPosition(pos);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    selection.cursor = cursor;

    selections.append(selection);

    setExtraSelections(selections);
}

void CodeEditor::addRightParenthesis()
{
    QTextCursor cur = this->textCursor();
    cur.movePosition(QTextCursor::PreviousCharacter,QTextCursor::KeepAnchor,2);

    if(cur.selectedText() == '('){
        const QString match = QString(')');
        std::cout << "Adding the matching p" ;
        this->insertPlainText(match);
     }
}








