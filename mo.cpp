#include "mo.h"
#include<QPainter>

mo::mo(QWidget *parent) : QWidget(parent)
{
    this->resize(1500,1000);
    setWindowTitle("反弹球");
    a1.setText("第一关");
    a2.setText("第二关");
    a3.setText("第三关");
    a4.setText("第四关");
    a5.setText("第五关");
    a6.setText("第六关");
    a7.setText("自定义");
    a8.setText("返回");
    a1.setGeometry(200,220,200,100);
    a2.setGeometry(500,220,200,100);
    a3.setGeometry(800,220,200,100);
    a4.setGeometry(1100,220,200,100);
    a5.setGeometry(200,640,200,100);
    a6.setGeometry(500,640,200,100);
    a7.setGeometry(800,640,200,100);
    a8.setGeometry(1100,640,200,100);
    a1.setParent(this);
    a2.setParent(this);
    a3.setParent(this);
    a4.setParent(this);
    a5.setParent(this);
    a6.setParent(this);
    a7.setParent(this);
    a8.setParent(this);
    a1.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a2.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a3.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a4.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a5.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a6.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a7.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a8.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    connect(&a8,&QPushButton::clicked,this,
            [=]()
            {
                emit mysignal();
            });
    connect(&a1,&QPushButton::clicked,this,
            [=]()
            {
        qip.mos=1;
        qip.movex=200;//设置初始坐标
        qip.movey=600;
        qip.Vx=2;//设置初始速度
        qip.Vy=-2;//注意是负值


        for(int i=0;i<28;i++)for(int j=0;j<26;j++)qip.boolarray[i][j]=0;
        qip.boolarray[10][6]=1;
        qip.boolarray[26][6]=1;
                qip.show();
                this->hide();
            });
    connect(&a2,&QPushButton::clicked,this,
            [=]()
            {
        qip.mos=2;
        qip.movex=200;//设置初始坐标
        qip.movey=600;
        qip.Vx=2;//设置初始速度
        qip.Vy=-2;//注意是负值


        for(int i=0;i<28;i++)for(int j=0;j<26;j++)qip.boolarray[i][j]=0;
        for(int i=0;i<15;i++)for(int j=0;j<i;j++){qip.boolarray[i][14-j]=1;qip.boolarray[28-i][14-j]=1;}
        for(int i=8;i<15;i++){qip.boolarray[7][i]=-1;qip.boolarray[21][i]=-1;}
                qip.show();
                this->hide();
            });
    connect(&a3,&QPushButton::clicked,this,
            [=]()
            {
        qip.mos=3;
        qip.movex=200;//设置初始坐标
        qip.movey=600;
        qip.Vx=2;//设置初始速度
        qip.Vy=-2;//注意是负值

        for(int i=0;i<28;i++)for(int j=0;j<26;j++)qip.boolarray[i][j]=0;
         qip.boolarray[11][5]=2;
         qip.boolarray[16][5]=2;
         qip.boolarray[1][5]=1;
         qip.boolarray[6][5]=1;
         qip.boolarray[21][5]=1;
         qip.boolarray[26][5]=1;
         for(int i=10;i<=12;i++){
             qip.boolarray[i][6]=2;
             qip.boolarray[i+5][6]=2;
             qip.boolarray[i-10][6]=1;
             qip.boolarray[i-5][6]=1;
             qip.boolarray[i+10][6]=1;
             qip.boolarray[i+15][6]=1;
         }
         for(int i=7;i<=15;i++)for(int j=6+i/2;j<=21-i/2;j++)qip.boolarray[j][i]=2;
         for(int i=7;i<=15;i++)for(int j=((0>i/2-4)?0:i/2-4);j<=11-i/2;j++)qip.boolarray[j][i]=1;
         for(int i=7;i<=15;i++)for(int j=16+i/2;j<((28<31-i/2)?28:31-i/2);j++)qip.boolarray[j][i]=1;

                qip.show();
                this->hide();
            });
    connect(&a4,&QPushButton::clicked,this,
            [=]()
            {
        qip.mos=4;
        qip.movex=200;//设置初始坐标
        qip.movey=600;
        qip.Vx=2;//设置初始速度
        qip.Vy=-2;//注意是负值

        for(int i=0;i<28;i++)for(int j=0;j<26;j++)qip.boolarray[i][j]=0;
        for(int i=0;i<15;i++)for(int j=0;j<i;j++){qip.boolarray[i][14-j]=i%3+1;qip.boolarray[28-i][14-j]=i%3+1;}
                qip.show();
                this->hide();
            });
    connect(&a5,&QPushButton::clicked,this,
            [=]()
            {
        qip.mos=5;
        qip.movex=200;//设置初始坐标
        qip.movey=600;
        qip.Vx=2;//设置初始速度
        qip.Vy=-2;//注意是负值

        for(int i=0;i<28;i++)for(int j=0;j<26;j++)qip.boolarray[i][j]=0;
        for(int i=0;i<28;i++)for(int j=3;j<12;j++)qip.boolarray[i][j]=1;
        for(int i=3;i<12;i++){
            qip.boolarray[1][i]=3;
            qip.boolarray[6][i]=3;
            qip.boolarray[9][i]=3;
            qip.boolarray[12][i]=3;
            qip.boolarray[15][i]=3;
            qip.boolarray[24][i]=3;
        }
        for(int i=8;i<=10;i++){
            qip.boolarray[i][3]=3;
            qip.boolarray[i+15][3]=3;
        }
        for(int i=13;i<=14;i++)qip.boolarray[i][11]=3;
        for(int i=18;i<=21;i++){
            qip.boolarray[i][3]=3;
            qip.boolarray[i][11]=3;
            qip.boolarray[i][7]=3;
        }
        for(int i=4;i<8;i++){
            qip.boolarray[i-2][2*i-5]=3;
            qip.boolarray[i-2][2*i-4]=3;
            qip.boolarray[i-2][2*i-3]=3;
        }
        for(int i=4;i<7;i++){
            qip.boolarray[18][i]=3;
            qip.boolarray[21][i+4]=3;
        }
        qip.boolarray[8][11]=3;
                qip.show();
                this->hide();
            });
    connect(&a6,&QPushButton::clicked,this,
            [=]()
            {
        qip.mos=6;

        qip.movex=200;//设置初始坐标
        qip.movey=600;
        qip.Vx=2;//设置初始速度
        qip.Vy=-2;//注意是负值


        for(int i=0;i<28;i++)for(int j=0;j<26;j++)qip.boolarray[i][j]=0;
        for(int i=4;i<=23;i++)
        {
            for(int j=1;j<=14;j++)
            {
                qip.boolarray[i][j]=1;
            }
        }
        qip.boolarray[6][3]=2;
        qip.boolarray[7][3]=2;
        qip.boolarray[8][3]=2;

       qip. boolarray[8][4]=2;
        qip.boolarray[8][5]=2;
        qip.boolarray[8][6]=2;
        qip.boolarray[8][7]=2;

        qip.boolarray[7][7]=2;
        qip.boolarray[6][7]=2;

        qip.boolarray[6][8]=2;
        qip.boolarray[6][9]=2;
        qip.boolarray[6][10]=2;
        qip.boolarray[6][11]=2;

        qip.boolarray[7][11]=2;
       qip. boolarray[8][11]=2;



        for(int j=3;j<=3+8;j++)
            qip.boolarray[10][j]=2;
       qip. boolarray[11][3]=2;
        for(int j=3;j<=3+8;j++)
           qip. boolarray[12][j]=2;
        qip.boolarray[11][3+8]=2;



       qip.boolarray[14][3]=2;
       qip. boolarray[15][3]=2;
       qip.boolarray[16][3]=2;

       qip. boolarray[16][4]=2;
       qip. boolarray[16][5]=2;
       qip. boolarray[16][6]=2;
       qip. boolarray[16][7]=2;

       qip. boolarray[15][7]=2;
       qip. boolarray[14][7]=2;

       qip. boolarray[14][8]=2;
       qip. boolarray[14][9]=2;
       qip. boolarray[14][10]=2;
       qip. boolarray[14][11]=2;

        qip.boolarray[15][11]=2;
      qip.  boolarray[16][11]=2;


        for(int j=3;j<=3+8;j++)
           qip. boolarray[18][j]=2;
        qip.boolarray[19][3]=2;
      for(int j=3;j<=3+8;j++)
            qip.boolarray[20][j]=2;
      qip.  boolarray[19][3+8]=2;

        for(int j=3;j<=3+8;j++)
         qip.   boolarray[22][j]=2;
      qip.  boolarray[22][3+8-1]=1;

        update();
                qip.show();
                this->hide();
            });
    connect(&qip,&GameWindow::signale,this,
            [=]()
            {
                qip.close();
                this->show();
           });
    connect(&a7,&QPushButton::clicked,this,
            [=]()
            {
                for(int i=0;i<28;i++)for(int j=0;j<26;j++)z.brick[i][j]=0;
                z.show();
                this->hide();
            });
    connect(&z,&zi::misignal,this,
            [=]()
            {
                qip.mos=8;
                qip.movex=200;//设置初始坐标
                qip.movey=600;
                qip.Vx=2;//设置初始速度
                qip.Vy=-2;//注意是负值
                for(int i=0;i<28;i++)for(int j=0;j<26;j++){
                    qip.boolarray[i][j]=z.brick[i][j];
                    qip.boolarray2[i][j]=qip.boolarray[i][j];
                }
                update();
                z.close();
                qip.show();
            });
}

void mo::paintEvent(QPaintEvent *)
{
     QPainter q(this);
     q.drawPixmap(rect(),QPixmap(":/new/prefix1/2.png"));
}
