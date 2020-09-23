#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include"mo.h"
#include<QPaintEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *);

private:
    QPushButton b1;
    QPushButton b2;
    mo o;
};

#endif // WIDGET_H
