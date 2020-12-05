#include "darkload.h"
#include<QTime>

DarkLoad::DarkLoad()
{

}
void DarkLoad::init(double x, double y, int attack, int hp, int hpMax, int cdOfAttack, int width, int height, int speed, double attackRange)
{
        this->x=x;
        this->y=y;
        this->attack=attack;
        this->hp=hp;
        this->hpMax=hpMax;
        this->level=level;
        this->cdOfAttack=cdOfAttack;
        this->width=width;
        this->height=height;
        this->speed=speed;
        this->attackRange=attackRange;
        ifMove=1;
}


 void DarkLoad::summonDemons()
 {

            if(!ifStuporous&&summonTime>=summonCD)
            {
                    QTime time;
                    time= QTime::currentTime();
                    qsrand(time.msec()+time.second()*1000);
                    int tmp1=qrand()%560+40-width;
                    int tmp2=qrand()%320+40-height;
                    closemonster[monsterNumber].init(tmp1,tmp2,1);
                    closemonster[monsterNumber+1].init(tmp1,tmp2,1);
                    closemonster[monsterNumber+2].init(tmp1,tmp2,1);
                    int tmp3=qrand()%560+40-width;
                    int tmp4=qrand()%320+40-height;
                    remotemonster[monsterNumber].init(tmp3,tmp4,1);
                    summonTime=0;
                    monsterNumber+=3;
             }
            else  summonTime++;
            if(monsterNumber>80) monsterNumber=0;
 }


void DarkLoad::hellFire(Player &player)
{
    if(!ifStuporous)
        {
        int xx = player.getX()/40;
        int yy = player.getY()/40;
        if(fireTime>fireCD)
        {
            fireTime=0;
            ifInited=1;
        }
     else
        {
            if(fireTime>=fireDelaytime&&ifInited)
            {
                if(player.getX()/40<xx+1&&player.getX()/40>xx-1&&player.getY()/40>yy-1&&player.getY()/40<yy+1)
                    {
                        player.setHp(player.getHp()-(player.getHpMax()*0.2));
                    }
                    ifInited=0;
            }
            fireTime++;
         }
    }
}

 void DarkLoad::die()
 {
        if(hp<=0)
        {
            //gameover
        }
  }
