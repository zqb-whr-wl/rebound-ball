#include "widget.h"
#include<QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b2.setParent(this);
    setWindowTitle("反弹球");
    b1.setText("开始游戏");
    b2.setText("退出游戏");
    this->resize(1500,1000);
    b1.setGeometry(230,340,240,120);
    b2.setGeometry(1030,340,240,120);
    b1.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    b2.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    connect(&b2,&QPushButton::clicked,this,&Widget::close);
    connect(&b1,&QPushButton::clicked,this,
            [=]()
            {
            this->close();
            o.show();
            });
    connect(&o,&mo::mysignal,this,
            [=]()
            {
                o.close();
                this->show();
           });

}
void Widget::paintEvent(QPaintEvent *)
{
     QPainter p(this);
     p.drawPixmap(rect(),QPixmap(":/new/prefix1/1.png"));
}

Widget::~Widget()
{

}
