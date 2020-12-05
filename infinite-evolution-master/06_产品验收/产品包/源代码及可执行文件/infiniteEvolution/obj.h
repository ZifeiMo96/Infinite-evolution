#ifndef OBJECT_H
#define OBJECT_H
//#include "map.h"



class Obj
{
public:
    Obj();
    //virtual void drawMyself()= 0;  //对自己绘画的虚函数
    bool checkCrash(int x,int y,int map[12][16]); //检验物体是否和地图碰撞
    //virtual void move() =0;//物体的移动函数
    virtual double getSpeed(){return speed;}
    virtual void setSpeed(double speed){this->speed=speed;}
    virtual double getX(){return x;}
    virtual double getY(){return y;}
    virtual void setX(double x){this->x=x;}
    virtual void setY(double y){this->y=y;}
    virtual int getWidth(){return width;}
    virtual int getHeight(){return height;}
    virtual int getHp(){return hp;}
    virtual int getHpMax(){return hpMax;}
    virtual void setHp(int hp){
        if(hp>=0){
            this->hp=hp;
        }else{
            this->hp = 0;
        }

    }

    virtual void setHpMax(int hpMax){this->hpMax=hpMax;}
    bool ifLive;//是否存在
    bool ifMove;//是否移动
    virtual  void beToxic(int damage);
    virtual void beStuporous();
    bool ifStuporous=0;//是否昏睡
    bool ifToxic=0;
    void setSize(int x, int y){width = x;height = y;}
    void setAttack(int attack){this->attack=attack;}
    int getAttack(){return attack;}
    bool checkCrashWith(int x,int y,Obj &o);
    void checkDie(bool &b);

protected:
    int hpMax;
    int hp;   //血量，子弹为0
    int attack;
    double x;  //横坐标
    double y;   //纵坐标
    int width;//宽度
    int height;//高度
    double speed;//移动速度
    int beToxicTime;//中毒时间
    int beToxicTimed;//已过中毒时间
    int beStuporousTime;//昏睡时间
    int beStuporousTimed;//已过昏睡时间
    //上述四个不能用static 否则会变成所有的怪物

};




#endif // OBJECT_H
