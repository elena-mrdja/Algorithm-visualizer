#include "variableexplorer.h"

VariableExplorer::VariableExplorer(QWidget *parent) : QGraphicsView(parent)
{
    set_background();
    Y_current = 0;
    Y_next = 0;


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

void VariableExplorer::track(vector<vector<pair<vector<string>,vector<int>>>> list, int index)
{


    const int X = 5;
    string words="";
    int X_add;

    vector<pair<vector<string>,vector<int>>> map = list[index];
    int size_map = map.size();


    words = words + "The state of all vairbales declared so far at line " + std::to_string(index+1) + " is: \n";
    Y_next += 20;

    int size_pair = map[0].second.size();
    if (size_pair == 1) {
        X_add = 18*index*index;
        for(int i = 0; i < size_map; i++){
            words = words + map[i].first[0] + " = "  + to_string(map[i].second[0]) + "\n";
            Y_next += 20;
        }
    }
    if (size_pair > 1) {
        X_add = 840;
        for(int j = 0; j < size_pair; j++){
            for (int i = 0; i < size_map; i ++){
                words = words + map[i].first[0] + " = "  + to_string(map[i].second[j]) + "\n";
                Y_next += 20;
            }
        }
      }


    Y_next += 15;
    words = words + "____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" + "\n";

    QString word = QString::fromStdString(words);
    auto text = this->createText2(word, X, Y_current);

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

QGraphicsSimpleTextItem* VariableExplorer::createText2(QString str, int x, int y)
{
    auto text = new QGraphicsSimpleTextItem(str);
    text->setBrush(QBrush(Qt::white));
    text->setPen(QPen(QPen(Qt::white)));
    QFontMetrics font = QFontMetrics(text->font());
    text->setPos(x,y);
    return text;
}
