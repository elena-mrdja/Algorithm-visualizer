#include "variableexplorer.h"
#include "AST/ast.hpp"

VariableExplorer::VariableExplorer(QWidget *parent) : QGraphicsView(parent)
{
    set_background();

    counter_ll = 0;
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



/*void VariableExplorer::track(std::unordered_map<char, std::vector<double>> mp, std::vector<char> order, int index)
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

string VariableExplorer::track(int index)
{
    Cache* cache;
    map<string, ValuesList*>* pointers = cache->get_map();

    string one_line ="";

   one_line = one_line + "Line: " + std::to_string(index +1) + "\n";

   //int sizeMap = static_cast<int>(pointers[index].size());

   auto it = pointers[index].begin();


   while(it != pointers[index].end()) {

       do {
           one_line += it->first + " = ";
           one_line += it->second[counter_ll].get_value() + '\n';
           counter_ll ++;}
       while (it->second[counter_ll-1].tail->next != nullptr);

       counter_ll = 0;
       it ++;
   }
   return one_line;
}





/*string words="";
vector<pair<char, double>> written;

for(int i=0;i<index;i++)
{
    unordered_map mp = mp_pointers[i];
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

/*void VariableExplorer::track2(vector<unordered_map<char, vector<double>>::iterator> v);
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
