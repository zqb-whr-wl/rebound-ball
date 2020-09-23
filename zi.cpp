#include "zi.h"
#include<QPainter>
#include<QMouseEvent>

zi::zi(QWidget *parent) : QWidget(parent)
{
    memset(brick,0,28*26*sizeof(int));
    setMouseTracking(true);
    a1.setText("设置完成");
    resize(l,w);
    a1.setParent(this);
    a1.setGeometry(200,850,120,50);
    a1.setStyleSheet("color:blue;font: bold 20px;background-color: yellow;");
    connect(&a1,&QPushButton::clicked,this,
            [=](){
        emit misignal();
    });
}
void zi::mouseMoveEvent(QMouseEvent *event)
{
    if(event->x()<rb&&event->x()>lb&&event->y()>ob&&event->y()<bb-3*bw)
    {
        ex=(event->x()-lb)/bl;
        ey=(event->y()-ob)/bw;
    }
    update();
}
void  zi::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->x()<rb&&event->x()>lb&&event->y()>ob&&event->y()<bb-3*bw)
    {
        ex1=(event->x()-lb)/bl;
        ey1=(event->y()-ob)/bw;
    }
    if(brick[ex1][ey1]==0)
        brick[ex1][ey1]=1;
    else if(brick[ex1][ey1]==1)
        brick[ex1][ey1]=2;
    else if(brick[ex1][ey1]==2)
        brick[ex1][ey1]=3;
    else if(brick[ex1][ey1]==3)
        brick[ex1][ey1]=-1;
    else if(brick[ex1][ey1]==-1)
        brick[ex1][ey1]=0;
    update();

}
void  zi::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/new/prefix1/2.png"));
    painter.drawRect(ex*bl+lb,ey*bw+ob,bl,bw);

    painter.setRenderHint(QPainter::Antialiasing, true); //抗锯齿

    painter.drawLine(QPoint(lb,ob),QPoint(rb,ob));
    painter.drawLine(QPoint(lb,ob),QPoint(lb,bb));
    painter.drawLine(QPoint(rb,ob),QPoint(rb,bb));
    /*QPen pen;
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);*/
    painter.drawLine(QPoint(lb,bb),QPoint(rb,bb));
    for(int i=0;i<28;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(brick[i][j]!=0)
            {
                if(brick[i][j]==1)
                    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
                else if(brick[i][j]==2)
                    painter.setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
                else if(brick[i][j]==3)
                    painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
                else if(brick[i][j]==-1)
                    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
                painter.drawRect(bl*i+lb,bw*j+ob,bl,bw);
            }
        }
    }

}
