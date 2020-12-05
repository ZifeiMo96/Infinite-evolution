#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString normalImg,QString pressImg = "");//两个图片的地址

    QString normalImgPath;//普通图片的地址
    QString pressImgPath;//按下图片的地址
    void zoom1();
    void zoom2();

signals:

public slots:
    void changeImg(bool mode);
};

#endif // MYPUSHBUTTON_H
