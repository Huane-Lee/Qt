#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>

class subWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit subWindow(QWidget *parent = 0);
    ~subWindow();
public:
    QPushButton b4;

signals:
    /*
     * 信号必须有signals关键字来声明
     * 信号没有返回值，但可以有参数
     * 信号就是函数的声明，只需声明、
     */
    void changeMianWindow();
    void changeMianWindow(int,QString);

public slots:
    void dealMianWindow();

};

#endif // SUBWINDOW_H
