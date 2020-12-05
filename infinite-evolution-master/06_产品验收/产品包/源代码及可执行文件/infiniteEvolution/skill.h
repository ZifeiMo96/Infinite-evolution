#ifndef SKILL_H
#define SKILL_H


#include"prop.h"
class Skill:public Prop
{
public:
    Skill();
    void init(double x,double y,int skillKind,int width=40,int height=40);
    bool ifUsable=0;
    int skillKind; //0治疗 1抗拒光环 2腐蚀 3昏睡 4yuan形吐息 5无敌 6强化普攻
    void beGot(Obj&obj);
    int cdOfSkill;
    int skillTime;
    void hide();
    int SkillRange;
};


#endif // SKILL_H
