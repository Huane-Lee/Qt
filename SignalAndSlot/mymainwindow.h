#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include "subwindow.h"
namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

private:
    Ui::MyMainWindow *ui;

private:
    QPushButton b1;
    QPushButton* b2;
    QPushButton b3;

    subWindow w;
public slots:
    /*
     * 槽函数 和信号的参数类型和返回值类型是一样的。
     */

    void myslot();
    void changeSubWindow();
    void changeMainWindow();
    void dealMainWindow(int a,QString str);

};

#endif // MYMAINWINDOW_H
