#include "monster.h"
#include<QTime>

Monster::Monster()
{

}

bool Monster::ifdie()
{

    if(!ifLive&&ifprop){
        ifprop = 0;
        return 1;
    }
}


void Monster::propLost()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int tmp=qrand()%100;
    if(tmp<30){
        int kind=qrand()%4;
        double degree=(qrand()%10+1)/10.0;
        pLost.init(x,y,0,kind,degree);
    }
}
