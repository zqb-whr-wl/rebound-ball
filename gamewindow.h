#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void startGame();
    void stopGame();
    void Egg();

private:
    Ui::GameWindow *ui;
    int movex,movey;//球心坐标
    int Vx,Vy;//速度坐标
    int R;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    int GameTimer;
    int length;//半长
    int Width;//板宽
    int Bx;
    int boolarray[28][26];



};

#endif // GAMEWINDOW_H
