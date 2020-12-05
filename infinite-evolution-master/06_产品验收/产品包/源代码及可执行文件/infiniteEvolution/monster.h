#ifndef MONSTER_H
#define MONSTER_H


#include "player.h"
#include "bullet.h"
#include "obj.h"
#include"prop.h"



class Monster:public Obj
{
public:
    Monster();
    virtual void init(){}
    virtual void attackPlayer(Obj &obj){}
    bool ifdie();//把怪物的数据修改成死亡，并判断是否要掉落道具（血药）
    virtual void propLost();
    Prop pLost;
    bool ifprop;
protected:
    int level;//怪物的等级
    int cdOfAttack;//攻击间隔
    int kind;

};

#endif // MONSTER_H
