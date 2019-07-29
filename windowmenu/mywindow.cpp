#include "mywindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(300,300);
    //菜单栏
    QMenuBar *menbar =new QMenuBar(this);
    //添加菜单
    QMenu* PFile = menbar->addMenu("文件");
    //添加菜单项,添加动作
    QAction* pNew = PFile->addAction("新建");

    connect(pNew,QAction::triggered,
             [=]()
             {
                qDebug()<<"新建成功"<<endl;
             }
            );

    PFile->addSeparator(); //添加分割线

    QAction* pOPen = PFile->addAction("打开");

    //工具栏
    //是菜单栏的快捷方式
   QToolBar* toolBar = addToolBar("toolbar");
   toolBar->addAction(pNew);
   toolBar->move(100,10);


   //状态栏
  QStatusBar* status = this->statusBar();
  QLabel* label =  new QLabel(this);
  label->setText("Normal txt file");
  status->addWidget(label);

  status->addWidget(new QLabel("2",this));

}

MyWindow::~MyWindow()
{

}
