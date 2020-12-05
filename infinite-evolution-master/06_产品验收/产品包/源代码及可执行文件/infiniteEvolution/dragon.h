#ifndef DRAGON_H
#define DRAGON_H


#include"remotemonster.h"
#include"skill.h"


class dragon:public RemoteMonster
{
public:
    dragon();
    //普攻可以直接继承
    void skill(Obj&obj);
    void die();
private:
    int skillWidth;
    int skillHeight;
    int skillDamage;
    bool ifFired=0;
    Bullet fire;
    Skill skillOfThird;
};

#endif // DRAGON_H
