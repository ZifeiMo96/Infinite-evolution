#include "dragon.h"
#include<QTime>
dragon::dragon()
{

}

void dragon::skill(Obj &obj)
{
    if(hp<=(int)(0.3*hpMax)&&!ifStuporous&&!ifFired){
            fire.Init(40,40,0,skillDamage,skillWidth,skillHeight);
            fire.setDirectionX(0);
            fire.setDirectionY(1);
            ifFired=1;
    }
}

void dragon::die()
{
    if(hp<=0){
        //hide the remoteMonster
        ifLive=0;
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int skillKind=qrand()%2;
        skillOfThird.init(x,y,skillKind);
        init(0,0,1);
        //跳转到下一关地图
        }

}
