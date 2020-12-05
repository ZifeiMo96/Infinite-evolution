#include "mypushbutton.h"
#include <QIcon>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    pix.load(normalImg);


    this->setFixedSize(pix.width(),pix.height());

    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}

void MyPushButton::changeImg(bool mode)
{
    QPixmap pix;
    if(mode){
        pix.load(pressImgPath);
    }else{
        pix.load(normalImgPath);
    }
    this->setFixedSize(pix.width(),pix.height());

    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void MyPushButton::zoom1()
{
//创建动画对象
 QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
 //动画时间间隔
 animation->setDuration(200);
 //起始位置
 animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
 //结束位置
 animation->setEndValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
 //弹跳曲线
 animation->setEasingCurve(QEasingCurve::OutBounce);
 //执行动画
 animation->start();
}
void MyPushButton::zoom2()
{
//创建动画对象
  QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
  //动画时间间隔
  animation->setDuration(200);
  //起始位置
  animation->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
  //结束位置
  animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
  //弹跳曲线
  animation->setEasingCurve(QEasingCurve::OutBounce);
  //执行动画
  animation->start();
}
