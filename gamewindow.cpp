#include "gamewindow.h"
#include <QPainter>
#include <QPushButton>
#include <QMouseEvent>
//#include <QMessageBox>
#include <QDebug>
GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
    this->resize(1500,1000);
    setWindowTitle("反弹球");
    setMouseTracking(true);


    memset(boolarray,0,28*26*sizeof(int));



    R=15;//设置球的初始半径
    length=50;//设置板子的半长
    Width=25;//设置板子的宽度
    Bx=750;//设置板子的初始位置

    b1=new QPushButton(this);
    b1->setText("开始游戏");
    b1->setGeometry(200,850,120,50);
    connect(b1,&QPushButton::released,this,&GameWindow::startGame);

    b2=new QPushButton(this);
    b2->setText("暂停游戏");
    b2->setGeometry(700,850,120,50);
    connect(b2,&QPushButton::released,this,&GameWindow::stopGame);

    connect(&b3,&QPushButton::clicked,this,
            [=]()
            {
                this->stopGame();
                emit signale();
            });
    b3.setParent(this);
    b3.setText("返回菜单");
    b3.setGeometry(1200,850,120,50);



    b1->setStyleSheet("color:blue;font: bold 20px;background-color: yellow;");
    b2->setStyleSheet("color:blue;font: bold 20px;background-color: yellow;");
    b3.setStyleSheet("color:blue;font: bold 20px;background-color: yellow;");



    connect(&x,&jieshu::mesignal,this,
            [=]()
            {
                x.close();
                movex=200;//设置初始坐标
                movey=600;
                Vx=2;//设置初始速度
                Vy=-2;//注意是负值
                for(int i=0;i<28;i++)for(int j=0;j<26;j++)boolarray[i][j]=0;
                if(mos==1){
                    boolarray[10][6]=1;
                    boolarray[26][6]=1;
                    update();
                }
                else if(mos==2){
                    for(int i=0;i<15;i++)for(int j=0;j<i;j++){boolarray[i][14-j]=1;boolarray[28-i][14-j]=1;}
                    for(int i=8;i<15;i++){boolarray[7][i]=-1;boolarray[21][i]=-1;}
                    update();
                }
                else if(mos==3){
                    boolarray[11][5]=2;
                    boolarray[16][5]=2;
                    boolarray[1][5]=1;
                    boolarray[6][5]=1;
                    boolarray[21][5]=1;
                    boolarray[26][5]=1;
                    for(int i=10;i<=12;i++){
                        boolarray[i][6]=2;
                        boolarray[i+5][6]=2;
                        boolarray[i-10][6]=1;
                        boolarray[i-5][6]=1;
                        boolarray[i+10][6]=1;
                        boolarray[i+15][6]=1;update();
                    }
                    for(int i=7;i<=15;i++)for(int j=6+i/2;j<=21-i/2;j++)boolarray[j][i]=2;
                    for(int i=7;i<=15;i++)for(int j=((0>i/2-4)?0:i/2-4);j<=11-i/2;j++)boolarray[j][i]=1;
                    for(int i=7;i<=15;i++)for(int j=16+i/2;j<((28<31-i/2)?28:31-i/2);j++)boolarray[j][i]=1;
                }
                else if(mos==4){
                    for(int i=0;i<28;i++)for(int j=0;j<26;j++)boolarray[i][j]=0;
                    for(int i=0;i<15;i++)for(int j=0;j<i;j++){boolarray[i][14-j]=i%3+1;boolarray[28-i][14-j]=i%3+1;}
                    update();
                }
                else if(mos==5){
                    for(int i=0;i<28;i++)for(int j=0;j<26;j++)boolarray[i][j]=0;
                    for(int i=0;i<28;i++)for(int j=3;j<12;j++)boolarray[i][j]=1;
                    for(int i=3;i<12;i++){
                        boolarray[1][i]=3;
                        boolarray[6][i]=3;
                        boolarray[9][i]=3;
                        boolarray[12][i]=3;
                        boolarray[15][i]=3;
                        boolarray[24][i]=3;
                    }
                    for(int i=8;i<=10;i++){
                        boolarray[i][3]=3;
                        boolarray[i+15][3]=3;
                    }
                    for(int i=13;i<=14;i++)boolarray[i][11]=3;
                    for(int i=18;i<=21;i++){
                        boolarray[i][3]=3;
                        boolarray[i][11]=3;
                        boolarray[i][7]=3;
                    }
                    for(int i=4;i<8;i++){
                        boolarray[i-2][2*i-5]=3;
                        boolarray[i-2][2*i-4]=3;
                        boolarray[i-2][2*i-3]=3;
                    }
                    for(int i=4;i<7;i++){
                        boolarray[18][i]=3;
                        boolarray[21][i+4]=3;
                    }
                    boolarray[8][11]=3;update();
                }
                else if(mos==6){
                    for(int i=0;i<28;i++)for(int j=0;j<26;j++)boolarray[i][j]=0;
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
                    boolarray[22][3+8-1]=1;update();
                }
                else if(mos==7)emit signale();
                else {

                    for(int i=0;i<28;i++)for(int j=0;j<26;j++) boolarray[i][j]=boolarray2[i][j];
                }

           });
}


void  GameWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/new/prefix1/2.png"));
    painter.setRenderHint(QPainter::Antialiasing, true); //抗锯齿

    painter.drawLine(QPoint(50,50),QPoint(1450,50));
    painter.drawLine(QPoint(50,50),QPoint(50,750));
    painter.drawLine(QPoint(1450,50),QPoint(1450,750));
    painter.drawLine(QPoint(50,750),QPoint(1450,750));

    for(int i=0;i<28;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(boolarray[i][j]!=0)
            {
                if(boolarray[i][j]==1)
                    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
                else if(boolarray[i][j]==2)
                    painter.setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
                else if(boolarray[i][j]==3)
                    painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
                else if(boolarray[i][j]<=-1)
                    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
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


void GameWindow::timerEvent(QTimerEvent *)
{
    int flag=0;
    int WinFlag=0;

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
        this->stopGame();
        x.okk.setText("您失败了，请再次尝试");
        x.ok.setText("重试");
        x.show();

    }


    if((movey+R-50)/25<26)//碰撞砖块
    {
        if(Vy<0 && boolarray[(movex-50)/50][(movey-R-50)/25]!=0)//下边界
        {

           boolarray[(movex-50)/50][(movey-R-50)/25]--;
           Vy=-Vy;
           flag=1;
           WinFlag=1;
        }

        if(Vy>0 && boolarray[(movex-50)/50][(movey+R-50)/25]!=0)//上边界
        {
            boolarray[(movex-50)/50][(movey+R-50)/25]--;
            Vy=-Vy;
            flag=1;
            WinFlag=1;
        }

        if(Vx>0 && boolarray[(movex-50+R)/50][(movey-50)/25]!=0)//左边界
        {
            boolarray[(movex-50+R)/50][(movey-50)/25]--;
            Vx=-Vx;
            flag=1;
            WinFlag=1;
        }

        if(Vx<0 && boolarray[(movex-50-R)/50][(movey-50)/25]!=0)//右边界
        {
            boolarray[(movex-50-R)/50][(movey-50)/25]--;
            Vx=-Vx;
            flag=1;
            WinFlag=1;
        }
    }


    if(flag==0)
    {
        movex+=Vx;
        movey+=Vy;
    }
    if(WinFlag==1)
        if(boolGame()){
            this->stopGame();
            x.okk.setText("恭喜你完成此关！");
            if(mos<6){
            x.ok.setText("下一关");
            }
            else{
            x.ok.setText("返回");
            }
            mos++;
            x.show();
        }
    update();
}


void GameWindow::startGame()
{
    if(createflag)
    {
        this->GameTimer = this->startTimer(1);  //每隔1毫秒调动一次定时器
        killflag=1;
        createflag=0;
    }
}

void GameWindow::stopGame()
{
    if(killflag)
    {
         this->killTimer(this->GameTimer);
         killflag=0;
         createflag=1;
    }

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

bool GameWindow::boolGame(){
    int f2=1;
    for(int i=0;i<28;i++)
        for(int j=0;j<26;j++){
            if(boolarray[i][j]>0){
                f2=0;break;
            }
        }
    if(f2==1)return true;
    else return false;
}

