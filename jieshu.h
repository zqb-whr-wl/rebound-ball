#ifndef JIESHU_H
#define JIESHU_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>

class jieshu : public QWidget
{
    Q_OBJECT
public:
    explicit jieshu(QWidget *parent = nullptr);
    QPushButton ok;
    QLabel okk;

signals:
    void mesignal();
private:

public slots:
};

#endif // JIESHU_H
