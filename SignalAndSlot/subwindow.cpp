#include "subwindow.h"

subWindow::subWindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(300,400);
    this->setWindowTitle("我是小弟");
    b4.setParent(this);
    b4.setText("切换到主窗口");

    connect(&b4,QPushButton::pressed,this,subWindow::dealMianWindow);
    connect(&b4,QPushButton::pressed,this,subWindow::dealMianWindow);

}

void subWindow::dealMianWindow()
{
    emit changeMianWindow(); //发射信号
    emit changeMianWindow(250,"i am ok");
}

subWindow::~subWindow()
{

}

