#ifndef DARKLOAD_H
#define DARKLOAD_H

#include"player.h"
#include"closemonster.h"
#include"remotemonster.h"

class DarkLoad:public CloseMonster//地狱领主
{
public:
    DarkLoad();//构造函数
    void init(double x,double y,int attack,int hp,int hpMax,int cdOfAttack,int width,int height,int speed,double attackRange);
    //初始化
    void summonDemons();//召唤小怪的攻击方式
    void hellFire(Player&player);//地狱火攻击方式
    void die();//死亡函数
 private:
        int summonTime=0;
        int summonCD;
        int fireTime=0;
        int fireCD;
        CloseMonster closemonster[100];
        RemoteMonster remotemonster[100];
        int fireDelaytime;
        int monsterNumber=0;
        bool ifInited=0;
};

#endif // DARKLOAD_H
