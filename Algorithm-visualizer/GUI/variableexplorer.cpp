#include "variableexplorer.h"

VariableExplorer::VariableExplorer(QWidget *parent) : QGraphicsView(parent)
{
    set_background();
    Y_current = -35;
    Y_next = -35;


}

void VariableExplorer::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;

    if (event->angleDelta().y() > 0) {

//        scale(scaleFactor,scaleFactor);

    }

    else {

        scale(1/scaleFactor,1/scaleFactor);
   }

}


void VariableExplorer::set_background()
{

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);
    view->setScene(scene);

    //the background of scene and shapes
    scene->setBackgroundBrush(Qt::black);


    QBrush greenBrush(Qt::green);
    QBrush whiteBrush(Qt::white);
    QBrush blackBrush(Qt::black);
    QPen outlinePen(Qt::lightGray);
    QPen black_pen(Qt::black);
    outlinePen.setWidth(2);

    rectangle = scene->addRect(0, 1000, 100, 20, black_pen, blackBrush);
    rectangle = scene->addRect(10000, 0, 100, 20, black_pen, blackBrush);
    rectangle = scene->addRect(10000, 10000, 100, 20, black_pen, blackBrush);
    rectangle = scene->addRect(0, 0, 100, 20, black_pen, blackBrush);
}



/*void VariableExplorer::track(std::map<char, std::vector<double>> mp, std::vector<char> order, int index)
{
    string words="";
    vector<pair<char, double>> written;
    for(int i=0;i<index;i++)
    {
        written.push_back({order[i], mp[order[i]][mp[order[i]].size()-1]});
        for(int j=0; j<written.size(); j++)
        {
            words = words + written[j].first + "=" + std::to_string(written[j].second);
            //cout<<written[j].first<<"="<<written[j].second;
            if(j!=written.size()-1)
                words = words + "\n" ;
        }
        words = words + "\n" + "_______________"+ "\n";
    }
    QString word = QString::fromStdString(words);
    auto text = this->createText2(word, 0,0,100,100);
    scene->addItem(text);
}*/


//ValueList a ne vector

void VariableExplorer::track(vector<unordered_map<char, vector<double>>> v, int index)
{
    const int X = 50;
    string words="";

    unordered_map<char, vector<double>> map = v[index];
    int size = map.size();

    words = words + "Line: " + std::to_string(index+1) + "\n";
    Y_next += 20;

    for(auto it : map){
        for(int j = 0; j < it.second.size();j++) {
                words = words + it.first + " = " + std::to_string(it.second[j]) + "\n";
                Y_next += 20;
            }
        }
    words = words + "_________________________" + "\n";
    Y_next += 15;

    QString word = QString::fromStdString(words);
    auto text = this->createText2(word, X+42*(index+1),Y_current,100,100);
    scene->addItem(text);
    Y_current = Y_next;
}




/*string words="";
vector<pair<char, double>> written;

for(int i=0;i<index;i++)
{
    map mp = mp_pointers[i];
    written.push_back({order[i], mp[order[i]][mp[order[i]].size()-1]});
    for(int j=0; j<written.size(); j++)
    {
        words = words + written[j].first + "=" + std::to_string(written[j].second);
        //cout<<written[j].first<<"="<<written[j].second;
        if(j!=written.size()-1)
            words = words + "\n" ;
    }
    words = words + "\n" + "_______________"+ "\n";
}
QString word = QString::fromStdString(words);
auto text = this->createText2(word, 0,0,100,100);
scene->addItem(text);*/

/*void VariableExplorer::track2(vector<map<char, vector<double>>::iterator> v);
{
    vector<pair<char, double>> written;
    for (int i=0;i<v.size();i++)
    {
        written.push_back({v[i]->first, v[i]->second[v[i]->second.size()-1]});
        for(int i=0;i<written.size();i++)
        {
            cout<<written[i].first<<"="<<written[i].second;
            if(i!=written.size()-1)
                cout<<", ";
        }
        cout<<"\n";
    }
}*/

QGraphicsSimpleTextItem* VariableExplorer::createText2(QString str, int x, int y, int w, int l)
{
    auto text = new QGraphicsSimpleTextItem(str);
    text->setBrush(QBrush(Qt::white));
    text->setPen(QPen(QPen(Qt::white)));
    QFontMetrics font = QFontMetrics(text->font());
    int length = font.horizontalAdvance(str);
    int height = font.height();
    text->setPos(x + w/2 - length/2,y + l/2 - height/2);
    return text;
}
