#ifndef ZI_H
#define ZI_H

#include <QWidget>
#include<QPushButton>
#include<QMouseEvent>

class zi : public QWidget
{
    Q_OBJECT
public:
    explicit zi(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    QPushButton a1;
    int ex,ey,ex1,ey1;
    int b1x=50,b1y=800;
    int  l=1500,w=1000;
    int rb=1450,lb=50,bb=750,ob=50,bw=25,bl=50;
    int brick[28][26];

signals:
    void misignal();

public slots:
};

#endif // ZI_H
