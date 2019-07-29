#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include<QPushButton>
#include<QDebug>

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->resize(300,400);

    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);
    b1.setParent(this);  //将btn1 设置为 窗口的子按钮

    b2  = new QPushButton(this);
    b2->setText("我是b2");


    /*
     * 信号和槽
     * connect(谁发出,发出信号名字,谁接收,接收槽名字)
    */

    connect(&b1,QPushButton::pressed,this,QMainWindow::close);

    /*
     * 自定义槽
     * slot 普通函数
     * 槽函数返回值和信号的函数返回值是一样的
     * 槽函数没有返回值
    */
    connect(b2,QPushButton::pressed,this,MyMainWindow::myslot);

    connect(b2,QPushButton::released,b2,QPushButton::hide);

    this->setWindowTitle("我是大哥");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);

    //通过信号和槽切换到子窗口
    connect(&b3,QPushButton::pressed,this,MyMainWindow::changeSubWindow);
    //connect(&w.b4,QPushButton::pressed,this,MyMainWindow::changeMainWindow);

    //切换到主窗口

    //指针需要类型
    void(subWindow::*p1)()= subWindow::changeMianWindow;
    connect(&w,p1,this,MyMainWindow::changeMainWindow);
    void(subWindow::*p2)(int,QString) = subWindow::changeMianWindow;
    connect(&w,p2,this,MyMainWindow::dealMainWindow);

    /*
     * c++ 11标准lambada
     * C++中，一个lambda表达式表示一个可调用的代码单元。
     * 我们可以将其理解为一个未命名的内联函数。
     */
    QPushButton* b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(200,200);
    int a = 10;
    int b = 20;

    connect(b4,&QPushButton::clicked,
        [=](bool isCheck)mutable
        {
            /*
             *[]中是可以放参数的
             * =表示将可以取到的局部变量和成员变量拿到
             */
            b4->setText("试试改改lambda");
            qDebug()<<a<<"---"<<b<<endl;
            a = 30;
            qDebug()<<isCheck<<endl;

        }
    );
}

void MyMainWindow::myslot()
{
    b2->setText("alter by myslots");
}

void MyMainWindow::dealMainWindow(int a,QString str)
{
    qDebug()<<a<<str<<endl;
}
void MyMainWindow::changeSubWindow()
{
    //切换到子窗口
    w.show();
    this->hide();
}

void MyMainWindow::changeMainWindow()
{
   //切换回主窗口
   this->show();
   w.hide();
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}
