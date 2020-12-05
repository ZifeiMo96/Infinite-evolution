#include "bullet.h"
#include<QtMath>
#include <QDebug>

Bullet::Bullet()
{
    x = 320;
    y = 280;
    ifLive  =0;
    width = 12;
    height = 12;

}
void Bullet::Init(double x, double y, int kind, int damage,int width,int height)
{
    this->x=x;
    this->y=y;
    this->kind=kind;
    this->damage =damage;
    this->width=width;
    this->height=height;
    ifLive=1;
    speed = 7;


}



void Bullet::move()
{
    x+=speed*directionX;
    y+=speed*directionY;
}

void Bullet::calDirection(int beginX, int beginY, int endX, int endY)
{
    double s=pow(beginX-endX,2)+pow(beginY-endY,2);
    directionX=(endX-beginX)/pow(s,0.5);
    directionY=(endY-beginY)/pow(s,0.5);
}

bool Bullet::checkHit(Obj &obj)
{
    if(obj.ifLive){
    if(x<=obj.getX()){
        if(y<=obj.getY()){
            if((int)(obj.getX()-x)<=width&&(int)(obj.getY()-y)<=height) return true;
            else  return false;
        }
        if(y>obj.getY()){
            if((int)(obj.getX()-x)<=width&&(int)(y-obj.getY())<=obj.getHeight()) return true;
            else  return false;
        }
    }
    else{
        if(y<=obj.getY()){
            if((int)(x-obj.getX())<=obj.getWidth()&&(int)(obj.getY()-y)<=height) return true;
            else  return false;
        }
        if(y>obj.getY()){
            if((int)(x-obj.getX())<=obj.getWidth()&&(int)(y-obj.getY())<=obj.getHeight()) return true;
            else  return false;
        }
    }
    }
    else  return false;
}

void Bullet::loseHp(Obj &obj,bool &b)
{


        if(kind==0){

            obj.setHp(obj.getHp()-damage);

            obj.checkDie(b);




        }
        else if(kind==1){
            obj.setHp(obj.getHp()-damage);
            obj.ifToxic=1;
            obj.beToxic(damage);
        }
        else  {
             obj.setHp(obj.getHp()-damage);
             obj.ifStuporous=1;
             obj.beStuporous();
        }

}

void Bullet::loseHp(Obj &obj)
{
    obj.setHp(obj.getHp()-damage);
    hide();
}

void Bullet::hide()
{
    //hide the picture
    Init(320,280,0,0,0,0);
    ifLive=0;//在判断是否撞墙等很多时候要同时判断iflive和ifbulletlive
}
