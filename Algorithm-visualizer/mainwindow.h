#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:


<<<<<<< HEAD
=======
    void on_variables_clicked();

>>>>>>> 1c751daf5e26e44ccf99f7bae28e97308783d66f
    void on_Visualize_clicked();

private:
    Ui::MainWindow *ui;

};



#endif // MAINWINDOW_H






