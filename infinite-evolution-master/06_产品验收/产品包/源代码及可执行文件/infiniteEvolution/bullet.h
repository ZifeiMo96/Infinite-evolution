#ifndef BULLET_H
#define BULLET_H


#include <QPainter>
#include <QPixmap>
#include "obj.h"




class Bullet:public Obj
{
public:
    Bullet();//46
    void Init(double x,double y,int kind,int damage,int width,int height);//子弹初始化
    void move();  //移动函数，根据x，y向量移动
    void calDirection(int beginX,int beginY,int endX,int endY);//计算子弹的设计方向，输入两个坐标，对向量坐标赋值
    bool checkHit(Obj &obj);  //传一个对象，来检验一个对象是否被子弹打中    对怪物的传怪物数组，对玩家是传玩家
    void loseHp(Obj &obj,bool &b);  //子弹造成伤害，分为普通子弹，火焰弹和催眠弹
    void loseHp(Obj &obj);
    void hide();   //把子弹隐藏起来（等同于析构
    void setDirectionX(double directionX){this->directionX=directionX;}//设置子弹方向向量x向量
    void setDirectionY(double directionY){this->directionY=directionY;}//设置子弹方向向量y向量
    int direction;//用于表示子弹图片的方向
    QPixmap pix;//子弹的图片
    void setDamage(int x){damage = x;}
    int getDamage(){return damage;}

private:
    int kind;//子弹的种类
    int damage;//子弹的伤害
    double directionX;//子弹方向的x坐标
    double directionY;//子弹方向的y坐标
};

#endif // BULLET_H
