#ifndef MO_H
#define MO_H

#include <QWidget>
#include<QPushButton>
#include<QPaintEvent>
#include"gamewindow.h"
#include"zi.h"

class mo : public QWidget
{
    Q_OBJECT
public:
    explicit mo(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

signals:
    void mysignal();

public slots:

private:
    QPushButton a1;
    QPushButton a2;
    QPushButton a3;
    QPushButton a4;
    QPushButton a5;
    QPushButton a6;
    QPushButton a7;
    QPushButton a8;
    GameWindow qip;
    zi z;

};

#endif // MO_H
