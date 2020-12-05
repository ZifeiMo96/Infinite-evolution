#ifndef CLOSEMONSTER_H
#define CLOSEMONSTER_H
#include"monster.h"

class CloseMonster:public Monster  //近战形怪物
{
public:
    CloseMonster();//生成的构造函数

    virtual void init(double x,double y,int z);
    //初始化
    virtual void move(Player &p1,int map[12][16],Obj obj1[10],Obj obj2[10]);
    virtual void attackPlayer(Obj&p2);//攻击玩家，造成伤害。
    virtual void die();//死亡，隐藏函数
    int width_of_pix;
    int height_of_pix;
    int x_of_pix;
    int y_of_pix;
    QPixmap pix;
    QPixmap cmonster[10][8];



protected:
    double attackRange;//攻击范围
    int attackTime=0;//攻击间隔
    double directionX;
    double directionY;
    int x_of_gif;
    int y_of_gif;
    int number_of_move;
    int number_of_attack;
    bool ifAttack;
    bool ifInit = 0;

};

#endif // CLOSEMONSTER_H
