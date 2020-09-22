#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPainter>
#include <QPushButton>
#include <QMouseEvent>
//#include <QMessageBox>
#include <QDebug>
GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->resize(1500,1000);
    setMouseTracking(true);

    memset(boolarray,0,28*26*sizeof(int));

    movex=200;//设置初始坐标
    movey=600;

    Vx=5;//设置初始速度
    Vy=-5;//注意是负值

    R=15;//设置球的初始半径
    length=50;//设置板子的半长
    Width=25;//设置板子的宽度
    Bx=750;//设置板子的初始位置

    b1=new QPushButton(this);
    b1->setText("开始游戏");
    b1->move(50,800);
    connect(b1,&QPushButton::released,this,&GameWindow::startGame);

    b2=new QPushButton(this);
    b2->setText("暂停游戏");
    b2->move(50,850);
    connect(b2,&QPushButton::released,this,&GameWindow::stopGame);

    b3=new QPushButton(this);
    b3->setText("退出游戏");
    b3->move(50,900);
    connect(b3,&QPushButton::released,this,&GameWindow::close);

    b4=new QPushButton(this);
    b4->setText("2020");
    b4->move(200,800);
    connect(b4,&QPushButton::released,this,&GameWindow::Egg);
}



GameWindow::~GameWindow()
{
    delete ui;
}


void  GameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); //抗锯齿

    painter.drawLine(QPoint(50,50),QPoint(1450,50));
    painter.drawLine(QPoint(50,50),QPoint(50,750));
    painter.drawLine(QPoint(1450,50),QPoint(1450,750));

    /*QPen pen;
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);*/
    painter.drawLine(QPoint(50,750),QPoint(1450,750));

    for(int i=0;i<28;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(boolarray[i][j]!=0)
            {
                if(boolarray[i][j]==1)
                    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
                else if(boolarray[i][j]==2)
                    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
                painter.drawRect(50*i+50,25*j+50,50,25);
            }
        }
    }


    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    painter.drawRect(Bx-length,750-Width,2*length,Width);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(movex,movey),R,R);
}


void GameWindow::timerEvent(QTimerEvent *event)
{
    int flag=0;

    if(movey+Vy-R<=50)//上边界
    {
        movey=50+R;
        Vy=-Vy;
        flag=1;
    }

    if(movex+Vx+R>=1450)//右边界
    {
        movex=1450-R;
        Vx=-Vx;
        flag=1;
    }

    if(movex+Vx-R<=50)//左边界
    {
        movex=50+R;
        Vx=-Vx;
        flag=1;
    }

    if(movey+Vy+R>=750-Width && movex+Vx-R>=Bx-length &&  movex+Vx+R<=Bx+length)
    {
        movey=750-Width-R;
        Vy=-Vy;
        flag=1;
    }

    if(movey+Vy+R>=750)
    {
         //QMessageBox::information(this, "lose", "You Lose", QMessageBox::Ok);
        movey=750-R;
        Vy=-Vy;
        flag=1;
    }


    if((movey+R-50)/25<26)//碰撞砖块
    {
        if(Vy<0 && boolarray[(movex-50)/50][(movey-R-50)/25]!=0)//下边界
        {

           boolarray[(movex-50)/50][(movey-R-50)/25]--;
           Vy=-Vy;
           flag=1;
        }

        if(Vy>0 && boolarray[(movex-50)/50][(movey+R-50)/25]!=0)//上边界
        {
            boolarray[(movex-50)/50][(movey+R-50)/25]--;
            Vy=-Vy;
            flag=1;
        }

        if(Vx>0 && boolarray[(movex-50+R)/50][(movey-50)/25]!=0)//左边界
        {
            boolarray[(movex-50+R)/50][(movey-50)/25]--;
            Vx=-Vx;
            flag=1;
        }

        if(Vx<0 && boolarray[(movex-50-R)/50][(movey-50)/25]!=0)//右边界
        {
            boolarray[(movex-50-R)/50][(movey-50)/25]--;
            Vx=-Vx;
            flag=1;
        }
    }


    if(flag==0)
    {
        movex+=Vx;
        movey+=Vy;
    }
    update();
}


void GameWindow::startGame()
{
    this->GameTimer = this->startTimer(1);  //每隔1毫秒调动一次定时器
}

void GameWindow::stopGame()
{
    this->killTimer(this->GameTimer);
}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->x()>=0 && event->x()<= 1500 && event->y()>=0 && event->y()<=1000)
    {

       if(event->x()-length<=50)
       {
           Bx=50+length;
       }
       else if(event->x()+length>=1450)
       {
           Bx=1450-length;
       }
       else
       {
           Bx=event->x();
       }
    }
}

void GameWindow::Egg()
{
    for(int i=4;i<=23;i++)
    {
        for(int j=1;j<=14;j++)
        {
            boolarray[i][j]=1;
        }
    }
    boolarray[6][3]=2;
    boolarray[7][3]=2;
    boolarray[8][3]=2;

    boolarray[8][4]=2;
    boolarray[8][5]=2;
    boolarray[8][6]=2;
    boolarray[8][7]=2;

    boolarray[7][7]=2;
    boolarray[6][7]=2;

    boolarray[6][8]=2;
    boolarray[6][9]=2;
    boolarray[6][10]=2;
    boolarray[6][11]=2;

    boolarray[7][11]=2;
    boolarray[8][11]=2;



    for(int j=3;j<=3+8;j++)
        boolarray[10][j]=2;
    boolarray[11][3]=2;
    for(int j=3;j<=3+8;j++)
        boolarray[12][j]=2;
    boolarray[11][3+8]=2;



    boolarray[14][3]=2;
    boolarray[15][3]=2;
    boolarray[16][3]=2;

    boolarray[16][4]=2;
    boolarray[16][5]=2;
    boolarray[16][6]=2;
    boolarray[16][7]=2;

    boolarray[15][7]=2;
    boolarray[14][7]=2;

    boolarray[14][8]=2;
    boolarray[14][9]=2;
    boolarray[14][10]=2;
    boolarray[14][11]=2;

    boolarray[15][11]=2;
    boolarray[16][11]=2;


    for(int j=3;j<=3+8;j++)
        boolarray[18][j]=2;
    boolarray[19][3]=2;
    for(int j=3;j<=3+8;j++)
        boolarray[20][j]=2;
    boolarray[19][3+8]=2;

    for(int j=3;j<=3+8;j++)
        boolarray[22][j]=2;
    boolarray[22][3+8-1]=1;

    update();
}
