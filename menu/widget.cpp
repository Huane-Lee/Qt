#include "widget.h"
#include<QMenu>
#include<QMenuBar>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //菜单
    QMenu* fileName;
    fileName= QMenuBar().addMenu(QString::fromLocal8Bit("文件"));


}

Widget::~Widget()
{

}
