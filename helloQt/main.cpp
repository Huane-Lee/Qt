#include<QApplication>
#include<Qwidget> //窗口控件基类
#include<QPushButton>
#include<QString>
int main(int argc,char ** argv)
{
  QApplication app(argc,argv);

  QWidget w;
  w.setWindowTitle("hello Kity");
  //w.show();

  QPushButton b;
  b.setText("你好中国"); //给按钮设置内容


  /*
   *指定父对象
   * 1.setParent
   * 2.构造函数
   *
  */
  b.setParent(&w);
  b.move(100,100);
  w.show();
  app.exec();
  return  0;
}
