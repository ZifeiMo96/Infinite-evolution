#ifndef KNIGHT_H
#define KNIGHT_H

#include"closemonster.h"
#include"skill.h"

class Knight:public CloseMonster
{
public:
    Knight();
    void init(double x,double y,int attack,int hp,int hpMax,int cdOfAttack,int width,int height,double speed,double attackRange,int skillOfDamage);
    void charge(Obj&obj);
    void skill(Obj&obj);
    void die();
    bool checkHit(Obj&obj);
    void skillDamage(Obj&obj);
    bool ifHit=0;
private:
    int skillOfDamage;
    Skill skillOfFirst;
};

#endif // KNIGHT_H
