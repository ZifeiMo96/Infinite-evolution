#include "skill.h"

Skill::Skill()
{

}

void Skill::init(double x, double y, int skillKind, int width, int height)
{
    this->x=x;
    this->y=y;
    this->skillKind=skillKind;
    this->width=width;
    this->height=height;
}



void Skill::hide()
{
    if(ifUsable){
        //图片消失
        ifLive=0;
        init(0,0,0,0,0);
    }
}

