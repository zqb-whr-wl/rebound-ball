#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include"jieshu.h"

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void mouseMoveEvent(QMouseEvent *);
    bool boolGame();
    void startGame();
    void stopGame();
    int movex,movey;//球心坐标
    int Vx,Vy;//速度坐标
    int boolarray[28][26];
    int boolarray2[28][26];
    int mos;//第几关
signals:
    void signale();
private:

    int R;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton b3;
    int GameTimer;
    int length;//半长
    int Width;//板宽
    int Bx;
    jieshu x;
    int killflag=0;
    int createflag=1;
public slots:
};

#endif // GAMEWINDOW_H
