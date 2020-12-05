#include "pupa.h"
#include<QTime>
Pupa::Pupa()
{

}

void Pupa::attackPlayer(Obj &obj)
{
    if(!ifStuporous){
        if(shootTime>=cdOfAttack||ifFirst){
            for(int i=0;i<10;i++){
                QTime time;
                time= QTime::currentTime();
                qsrand(time.msec()+time.second()*1000);
                int tmp1=qrand()%560+40-width;
                int tmp2=qrand()%320+40-height;
                boxOfBullet[i].Init(tmp1,tmp2,0,attack,pupaWidth,pupaHeight);
                ifInited=1;
            }
            ifFirst=0;
            shootTime=0;
          }
            else  {
                if(shootTime>cdOfBomb&&ifInited){
                    for(int i=0;i<10;i++){
                       // boxOfBullet[i].loseHp(obj);
                        //写出动画效果
                        boxOfBullet[i].hide();
                    }
                    ifInited=0;
                }
            shootTime++;
        }
    }
}

void Pupa::die()
{
    if(hp<=0){
    //hide the remoteMonster
    ifLive=0;
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int skillKind=qrand()%2;
    skillOfSec.init(x,y,skillKind);
    init(0,0,1);
    //跳转到下一关地图
    }

}
