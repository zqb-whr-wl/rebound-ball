#include "jieshu.h"

jieshu::jieshu(QWidget *parent) : QWidget(parent)
{
    this->resize(700,300);
    setWindowTitle("结束");
    ok.setParent(this);
    ok.setGeometry(300,170,100,60);
    okk.setStyleSheet("font: bold 30px;");
    okk.resize(350,100);
    okk.setParent(this);
    okk.move(200,50);

    connect(&ok,&QPushButton::clicked,this,
            [=]()
        {
        emit mesignal();
        });

}
